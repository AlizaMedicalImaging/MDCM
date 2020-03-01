/********************************************************************************/
/*                                                                              */
/* Papyrus 3 library.                                                           */
/* This library constitutes a DICOM file system which helps reading and writing */
/* DICOM files and DICOMDIR files.                                              */
/*                                                                              */
/* Copyright (C) 2004 - Service of  Medical Informatics -                       */
/* University Hospitals of Geneva (HUG), Geneva, Switzerland                    */
/*                                                                              */
/* This library is a free software; you can redistribute it and/or modify it    */
/* under the terms of the GNU Lesser General Public License as published by the */
/*  Free Software Foundation; either version 2.1 of the License, or             */
/* (at your option) any later version.                                          */
/*                                                                              */
/* This library is distributed in the hope that it will be useful,              */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of               */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                         */
/* See the GNU Lesser General Public License for more details.                  */
/*                                                                              */
/* You should have received a copy of the GNU Lesser General Public License     */
/* along with this library; if not, write to                                    */
/* the Free Software Foundation, Inc.,                                          */
/* 59 Temple Place, Suite 330,                                                  */
/* Boston, MA 02111-1307 USA                                                    */
/*                                                                              */
/* You can contact us for more information at osiris@sim.hcuge.ch               */
/* or by writing to Papyrus,                                                    */
/* Unite d'Imagerie Numerique / Service d'Informatique Medicale / HUG,          */
/* 24, Micheli-du-Crest street, 1211 Geneva 14, Switzerland.                    */
/*                                                                              */
/* The University Hopitals of Geneva, hereby disclaims all copyright interest   */
/* in the library `Papyrus' (a library for reading and writing DICOM files).    */
/*                                                                              */
/* Geneva, april 2004                                                           */
/* Antoine Geissbuhler, head of the Service of Medical Informatics,             */
/* University Hospitals of Geneva, Switzerland                                  */
/*                                                                              */
/********************************************************************************/

/********************************************************************************/
/*                                                                              */
/*	Project  : P A P Y R U S  Toolkit (DicomDir library)                        */
/*	File     : DicomDirDataSetRead3.c                                           */
/*	Function : contains the function that will manage the reading of            */
/*             the records.                                                     */
/*	Authors  : Marianne Logean                                                  */
/*                                                                              */
/*	History  : 05.1997	version 3.5                                             */
/*             02.1999	version 3.6                                             */
/*                                                                              */
/********************************************************************************/

/* ------------------------- includes -----------------------------------------*/

#include <stdio.h>
#include <string.h>

#ifndef DicomdirH 
#include "DicomDir.h"
#endif


/********************************************************************************/
/*                                                                              */
/*	Papy3GetRecord : Get the specified record from the specified data set.      */	
/*  	BEWARE: only useful when reading a DICOMDIR file                        */
/*	return : the read record or NULL.                                           */
/*                                                                              */
/********************************************************************************/

Record * CALLINGCONV
Papy3GetRecord (PapyShort inFileNb, int inRecordID)
{
  int		i, j, theElemType, theEnumTag, found, theOddGroup;
  int		*theListOfGroupsP, theElem = FALSE;
  PapyShort	theErr;
  PapyUShort	theElemTag, theElemCreator, theTmpTag;
  PapyULong	theNbVal, theLoopVal;
  UValue_T	*theValP, *theTmpValP;
  SElement	*theGrP, *theTmpGrP;
  Record	*theRecordP, *theElemP;

  
  /* Must be a DICOMDIR file */
  if (gIsPapyFile [inFileNb] != DICOMDIR) return NULL;

  /* creation of the record */
  theRecordP = CreateRecord3 (inRecordID);
  
  /* initialize the lists of groups contained in the record to empty */
  theListOfGroupsP  = (int *) ecalloc3 ((PapyULong) END_GROUP, (PapyULong) sizeof (int));
 
  /* scan the record to find its group composition */
  LookForGroupsInRecord3 (theRecordP, inRecordID, theListOfGroupsP);

  /* loop on the groups */
  for (i = 0; i < END_GROUP; i++)
  {
    /* read only the needed groups */
    if (theListOfGroupsP [i] == 1)
    {
      /* look for the group */
      if ((theErr = Papy3GotoGroupNb (inFileNb, (PapyShort) (gArrGroup [i].number))) == 0)
      {
        /* test wether it is an odd group number or not */
        if (gArrGroup [i].number % 2 != 0)
        {
          theOddGroup = TRUE;
          
          /* look for the owner range of the PAPYRUS 3.0 elements */
          theElemCreator = Papy3FindOwnerRange (inFileNb, gArrGroup [i].number, "PAPYRUS 3.0");
          
        } /* if ...odd group number */
        else theOddGroup = FALSE;
        
        /* read the group */
        if ((theErr = Papy3GroupRead (inFileNb, &theGrP)) < 0) 
        {
          Papy3RecordFree (&theRecordP, inRecordID, TRUE);
          efree3 ((void **) &theListOfGroupsP);
          return NULL;
        }
        
        theElemP = theRecordP;
        /* test each element of the record to see if it belongs to the group */
        for (j = 0; j < gArrRecord [inRecordID]; j++, theElemP++)
        {
          /* does the element belongs to the group ? */
          if (theElemP->group == theGrP->group)
          {
            /* locate the enum place of the element given its tag */
            theTmpGrP = theGrP;
            found = FALSE;
            theEnumTag = 0;
            theElemTag = theElemP->element;
            /* if it is an odd group number */
            if (theOddGroup && theElemTag >= 0x0100)
            {
              /* convert the element range to the one extracted from the file */
              /* 0xaabb -> 0x00bb */
              theTmpTag   = theElemTag << 8;
              theTmpTag   = theTmpTag  >> 8;
              /* put the elem creator in the 2 most significant bytes... */
              /* 0x00cc -> 0xcc00 */
              theElemTag  = theElemCreator << 8;
              /* ...and the element tag in the 2 less significant bytes */
              /* 0xccbb */
              theElemTag |= theTmpTag;
            } /* if ...odd group number */
              
            while (!found && (theEnumTag <= (int) gArrGroup [i].size))
            {
              if (theTmpGrP->element == theElemTag) found = TRUE;
              else
              {
                theEnumTag++;
                theTmpGrP++;
              } /* else */
            } /* while */
            
    
            if (found)
            {

              /* extract the element */
              theValP = Papy3GetElement (theGrP, theEnumTag, &theNbVal, &theElemType);
            
              /* put the element in the module */
              if (theValP != NULL)
              {
				/* test that it has found at least one element */
                if (!theElem) theElem = TRUE;

                /* loop on the values of the element */
                for (theLoopVal = 0L, theTmpValP = theValP; theLoopVal < theNbVal; theLoopVal++, theTmpValP++)
                {
                  /* depending on the VR of the element put it to the group */
                  switch (theElemType)		  /* No OB nor OW */
                  {
                    case SS :
                      Papy3PutElement (theRecordP, j, &(theTmpValP->ss)); 
                      break;
                    case USS :
                    case AT :
                      Papy3PutElement (theRecordP, j, &(theTmpValP->us)); 
                      break;
                    case SL :
                      Papy3PutElement (theRecordP, j, &(theTmpValP->sl)); 
                      break;
                    case UL :
                      Papy3PutElement (theRecordP, j, &(theTmpValP->ul)); 
                      break;
                    case FL :
                      Papy3PutElement (theRecordP, j, &(theTmpValP->fl)); 
                      break;
                    case FD :
                      Papy3PutElement (theRecordP, j, &(theTmpValP->fd)); 
                      break;
                    case AE :
                    case AS :
                    case CS :
                    case DA :
                    case DS :
                    case DT :
                    case IS :
                    case LO :
                    case LT :
                    case PN :
                    case SH :
                    case ST :
                    case TM :
                    case UI :
                      Papy3PutElement (theRecordP, j, &(theTmpValP->a)); 
                      break;
                    case SQ :            
                      Papy3PutElement (theRecordP, j, &(theTmpValP->sq)); 
                      break;
                  } /* switch */
                } /* for ...loop on the values of the element */
              } /* if ...the element exists */
            } /* if ...the element is not pixel data */
           
          } /* if ...the element belongs to this group */
        } /* for ...loop on the elements of the record */
        
        /* free the group */
        theErr = Papy3GroupFree (&theGrP, FALSE);
        
      } /* if ...the group exists */
    } /* if ...group has to be read */
    
  } /* for ...reading of the needed groups */
  
  /* delete the lists of groups number of the record */
  efree3 ((void **) &theListOfGroupsP);
  
  /* if no element found we have to assume the record is empty ... */
  if (!theElem)
  {
    Papy3RecordFree (&theRecordP, inRecordID, TRUE);
    return NULL;
  } /* if */
  else 
    return theRecordP; 
   
} /* endof Papy3GetRecord */
