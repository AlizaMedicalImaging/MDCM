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
/*	Project  : P A P Y R U S  Toolkit  (Dicomdir library)                       */
/*	File     : DicomDirDataSetWrite3.c                                          */
/*	Function : contains the functions managing the records (writing).           */
/*	Authors  : Christian Girard                                                 */
/*             Marianne Logean                                                  */
/*                                                                              */
/*	History  : 05.1997	version 3.51                                            */
/*	           02.1999	version 3.6                                             */
/*                                                                              */
/********************************************************************************/

#ifdef Mac
#pragma segment papy3
#endif

/* ------------------------- includes -----------------------------------------*/

#ifndef DicomdirH 
#include "DicomDir.h"
#endif


/********************************************************************************/
/*                                                                              */
/*	Papy3CreateDicomDirDataSet : Create a new data set item and add it to       */
/*	the list of Data Set of the given file.                                     */
/*	return : a pointer to the created Data Set                                  */
/*           NULL otherwise                                                     */
/*                                                                              */
/********************************************************************************/

Item * CALLINGCONV
Papy3CreateDicomDirDataSet (PapyShort inFileNb)
{
  Object	*theObjectP;
  Item		*theItemP;

  
  /* creates an empty object that will point to the list of records */
  theObjectP = (Object *) emalloc3 ((PapyULong) sizeof (Object));
  theObjectP->whoAmI 	    = papItem;
  theObjectP->item   	    = NULL;
  theObjectP->module 	    = NULL;
  theObjectP->record 	    = NULL;
  theObjectP->group  	    = NULL;
  theObjectP->tmpFileLength = 0L;
  
  theItemP = InsertLastInList (&(gArrMemFile [inFileNb]), theObjectP);

  return theItemP;
  
} /* endof Papy3CreateDicomDirDataSet */


/********************************************************************************/
/*                                                                              */
/*	Papy3CreateDirRecItem : Create a new data set item in the Directory         */
/*                          Record sequence.                                    */
/*	return : a pointer to the created item of the data set                      */
/*           NULL otherwise                                                     */
/*                                                                              */
/********************************************************************************/

Item * CALLINGCONV
Papy3CreateDirRecItem (Module *inModuleP)
{
  Object	*theObjectP;
  Item		*theItemP;
  Module	*theElementP;
  
  
  /* go to the Directory Record Sequence of the module */
  theElementP = inModuleP + papDirectoryRecordSequence;

  
  /* creates an empty object that will point to the list of records */
  theObjectP = (Object *) emalloc3 ((PapyULong) sizeof (Object));
  theObjectP->whoAmI 	    = papItem;
  theObjectP->objID  	    = DirectoryInformation;
  theObjectP->item   	    = NULL;
  theObjectP->module 	    = NULL;
  theObjectP->record 	    = NULL;
  theObjectP->group  	    = NULL;
  theObjectP->tmpFileLength = 0L;
  
  /* test if it is the first item */
  if (theElementP->nb_val == 0L)
  {
    theElementP->nb_val = 1L;
    /* allocate room for the value to be inserted */
    theElementP->value = (UValue_T *) emalloc3 ((PapyULong) sizeof (UValue_T));
    /* and initializes it to NULL */
    theElementP->value->sq = NULL;

  } /* if ...first time */
  
  theItemP = InsertLastInList (&(theElementP->value->sq), theObjectP);

  return theItemP;
  
} /* endof Papy3CreateDirRecItem */



/********************************************************************************/
/*                                                                              */
/*	Papy3LinkRecordToDS : Link the given record to the Data Set.                */
/*                                                                              */
/********************************************************************************/

void CALLINGCONV
Papy3LinkRecordToDS (Item *inDataSetP, SElement *inRecordP, int inRecordName)
{
  Item		*theItemP;
  Object	*theObjectP;
  

  /* ------- link the created record to the list of modules/groups/records of the data set ---- */
  
  /* creation of the Object pointing to the record */
  theObjectP = (Object *) emalloc3 ((PapyULong) sizeof (Object));
  
  theObjectP->whoAmI 	    = papRecord;
  theObjectP->objID  	    = inRecordName;
  theObjectP->group  	    = NULL;
  theObjectP->item   	    = NULL;
  theObjectP->module 	    = NULL;
  theObjectP->record 	    = inRecordP;	/* link the record to the object */
  theObjectP->file   	    = NULL;
  theObjectP->tmpFileLength = 0L;

  /* insert the item at the end of the list of modules/groups/records of the data set */
  theItemP = InsertLastInList ((Item **) &(inDataSetP->object->item), theObjectP);

} /* endof Papy3LinkRecordToDS */



/********************************************************************************/
/*                                                                              */
/*	Papy3FillRecord : Fill the referenced element of the record                 */
/*                                                                              */
/********************************************************************************/

void CALLINGCONV
Papy3FillRecord (SElement **ioRecordP)
{
  SElement 	*theElemP;
  PapyShort	i;
  PapyULong	theLongValue;
  PapyUShort	theShortValue;
  
  
  /* initialisations */
  theLongValue  = 0L;
  theShortValue = 0;

  /* fill the 2 first elements of the record (common to all records)*/
  i = 0;
  theElemP = *ioRecordP;
  /* 0004:1400 */
  Papy3PutElement (*ioRecordP, i, &theLongValue);
  i++; theElemP++;
  /* 0004:1410 */
  Papy3PutElement (*ioRecordP, i, &theShortValue);
  i++; theElemP++;
  /* 0004:1420 */
  Papy3PutElement (*ioRecordP, i, &theLongValue);

} /* endof Papy3FillRecord */
  


/********************************************************************************/
/*                                                                              */
/*	Papy3CreateRecord : Create a new record.                                    */
/*	return : a pointer to the created record                                    */
/*           NULL otherwise                                                     */
/*                                                                              */
/********************************************************************************/

Record * CALLINGCONV 
Papy3CreateRecord (int inRecordName)
{
  Record	*theRecordP;
  
  
  /* create the record a la Papy3GroupCreate */
  theRecordP = CreateRecord3 (inRecordName);
  
  Papy3FillRecord (&theRecordP);

  return theRecordP;

} /* endof Papy3CreateRecord */



/********************************************************************************/
/*                                                                              */
/*	LookForGroupsInRecord3 : Scan a record for its list of groups. Compares     */
/* 	the found groups with the list of existing groups (if any) and build        */
/*	the list of groups to create or read (list that is returned).               */
/*                                                                              */
/********************************************************************************/

void
LookForGroupsInRecord3 (Record *inRecordP, int inRecordID, int *inGrToCreateP)
{
  int		*theTmpCrP, i;
  int		theEnumGrNb;
  Record	*theElemP;
  
  
  theElemP  = inRecordP;
  theTmpCrP = inGrToCreateP;
  
  /* initialize the array of groups to create to empty */
  for (i = 0; i < END_GROUP; i++) theTmpCrP [i] = 0;
  
  /* no list just add the groups found to the list */
  for (i = 0; i < gArrRecord [inRecordID]; i++)
  {
    theEnumGrNb = Papy3ToEnumGroup (theElemP->group);
    
    /* put the group in the to read list */
    if (theTmpCrP [theEnumGrNb] == 0)
      theTmpCrP [theEnumGrNb] = 1;
    
    /* next element of the record */
    theElemP++;
  } /* for ...loop on the elements of the record */
  
} /* endof LookForGroupsInRecord3 */


