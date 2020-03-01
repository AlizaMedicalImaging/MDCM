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
/*	Project  : P A P Y R U S  Toolkit (Dicomdir library)                        */
/*	File     : DicomdirInit.c                                                   */
/*	Function : contains all the initialisation functions                        */
/*	Authors  : Marianne Logean                                                  */
/*                                                                              */
/*	History  : 05.1997	version 3.51                                            */
/*             02.1999	version 3.6                                             */
/*                                                                              */
/********************************************************************************/

/* ------------------------- includes -----------------------------------------*/

#include <stdio.h>

#ifndef DicomdirH 
#include "DicomDir.h"
#endif

#ifndef FILENAME83              /* this is for the normal machines ... */

#ifndef DicomdirInitRecordsH	
#include "DicomDirInitRecords.h"
#endif

#else				/* FILENAME83 defined for the DOS machines */

#ifndef DicomdirInitRecordsH
#include "DICINIR3.h"
#endif

#endif 				/* FILENAME83 defined */



/********************************************************************************/
/*                                                                              */
/*	InitRecordSize3 : initializes the number of element for each defined        */
/*                    record.                                                   */
/*                                                                              */
/********************************************************************************/

void
InitRecordSize3 ()
{
  /* initialization of the records length */
  gArrRecord [(int) PatientR]   = papEndPatientR;
  gArrRecord [(int) StudyR]     = papEndStudyR;
  gArrRecord [(int) SeriesR]    = papEndSeriesR;
  gArrRecord [(int) ImageR]		= papEndImageR;
  gArrRecord [(int) OverlayR]   = papEndOverlayR;
  gArrRecord [(int) ModalityLUTR]	= papEndModalityLUTR;
  gArrRecord [(int) VOILUTR]		= papEndVOILUTR;
  gArrRecord [(int) CurveR]		= papEndCurveR;
  gArrRecord [(int) Topic]		= papEndTopic;
  gArrRecord [(int) Visit]		= papEndVisit;
  gArrRecord [(int) Result]		= papEndResult;
  gArrRecord [(int) Interpretation]	= papEndInterpretation;
  gArrRecord [(int) StudyComponentR]	= papEndStudyComponentR;
  gArrRecord [(int) PrintQueue]		= papEndPrintQueue;
  gArrRecord [(int) FilmSession]	= papEndFilmSession;
  gArrRecord [(int) BasicFilmBox]	= papEndBasicFilmBox;
  gArrRecord [(int) BasicImageBox]	= papEndBasicImageBox;

} /* endof InitRecordSize3 */


/********************************************************************************/
/*                                                                              */
/*	DicD3Init : initializes the DicomDir library                                */
/*	return : always return 0                                                    */
/*                                                                              */
/********************************************************************************/

PapyShort CALLINGCONV
DicD3Init ()
{
  int i;

  /* initialize some pointer to NULL */
  /* rootDirRecordItem = NULL; */
  /* initialize some pointers to NULL */
  for (i = 0; i < kMax_file_open; i++) 
  {
    gPosFirstPatientOffset 	 [i] = 0L;
    gRefFirstPatientOffset 	 [i] = 0L;
    gPosLastPatientOffset  	 [i] = 0L;
    gRefLastPatientOffset  	 [i] = 0L;
    gPosNextDirRecordOffset	 [i] = NULL;
    gRefNextDirRecordOffset	 [i] = NULL;
    gPosLowerLevelDirRecordOffset[i] = NULL;
    gRefLowerLevelDirRecordOffset[i] = NULL;
  } /* for */

  /* test to see wether the toolkit has been initialised or not */
  if  (gIsDicd3Inited == 21) return 0;
  else gIsDicd3Inited = 21;
  
   /* initialize the number of elements in the records */
  InitRecordSize3 ();

  return 0;
  
} /* endof DicD3Init */



/********************************************************************************/
/*                                                                              */
/*	InitRecord3 : initializes the selected record                               */
/*                                                                              */
/********************************************************************************/
 
void
InitRecord3 (int inRecordEnum, SElement *ioElemP)
{
   switch (inRecordEnum)
   {
     case PatientR :
       init_PatientR (ioElemP);
       break;
     case StudyR :
       init_StudyR (ioElemP);
       break;
     case SeriesR :
       init_SeriesR (ioElemP);
       break;
     case ImageR :
       init_ImageR (ioElemP);
       break;
     case OverlayR :
       init_OverlayR (ioElemP);
       break;
     case ModalityLUTR :
       init_ModalityLUTR (ioElemP);
       break;
     case CurveR :
       init_CurveR (ioElemP);
       break;
     case Topic :
       init_Topic (ioElemP);
       break;
     case Visit :
       init_Visit (ioElemP);
       break;
     case Result :
       init_Result (ioElemP);
       break;
     case Interpretation :
       init_Interpretation (ioElemP);
       break;
     case StudyComponentR :
       init_StudyComponentR (ioElemP);
       break;
     case PrintQueue :
       init_PrintQueue (ioElemP);
       break;
     case FilmSession :
       init_FilmSession (ioElemP);
       break;
     case BasicFilmBox :
       init_BasicFilmBox (ioElemP);
       break;
     case BasicImageBox :
       init_BasicImageBox (ioElemP);
       break;
     default :
       break;
   } /* end switch */

} /* endof InitRecord3 */



/********************************************************************************/
/*                                                                              */
/*	CreateRecord3 : allocates memory for the elements of the record and fill    */
/*	                in the description of the elements of the record.           */
/* 	return : a pointer to the created record                                    */
/*                                                                              */
/********************************************************************************/
 
Record*
CreateRecord3 (int inRecordID)
{
  Record *theRecordP;
   
  theRecordP = (Record *) ecalloc3 ((PapyULong) gArrRecord [inRecordID], 
   			     	     (PapyULong) sizeof (Record));
   
  (void) InitRecord3 (inRecordID, theRecordP);
   
  return theRecordP;
   
} /* endof CreateRecord3 */
  
 
/********************************************************************************/
/*                                                                              */
/*	Papy3RecordFree : Frees a previously allocated record.                      */
/*	return : standard error message if a problem occur zero otherwise           */
/*                                                                              */
/********************************************************************************/
  
PapyShort CALLINGCONV
Papy3RecordFree (SElement **ioRecordP, int inRecordID, int inDelSeq)
{
  SElement 	*theElemP;
  PapyShort  	theRecordSize, i, theErr;
    
    
  if (*ioRecordP == NULL) RETURN (papNoError);
    
  if (inRecordID < 0) RETURN (papEnumGroup);
  
  theRecordSize = gArrRecord [inRecordID];
  if (theRecordSize < 0) RETURN (papGroupErr);
    
  /* free the elements of the record */
  for (i = 0, theElemP = *ioRecordP; i < theRecordSize; i++, theElemP++)
    if ((theErr = Papy3ClearElement (*ioRecordP, i, inDelSeq)) < 0) RETURN (theErr);
    
  efree3 ((void **) ioRecordP);

  RETURN (papNoError)
    
} /* endof Papy3RecordFree */
  



