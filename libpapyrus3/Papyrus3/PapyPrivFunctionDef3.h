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
/*			                                                                    */
/*	Project  : P A P Y R U S  Toolkit                                           */
/*	File     : PapyPrivFunctionDef3.h                                           */
/*	Function : contains the declarations of the private functions               */
/*	Authors  : Christian Girard                                                 */
/*             Marianne Logean                                                  */
/*                                                                              */
/*	History  : 01.1999	version 3.6                                             */
/*             04.2001	version 3.7                                             */
/*             09.2001  version 3.7  on CVS                                     */
/*             10.2001  version 3.71 MAJ Dicom par CHG                          */
/*                                                                              */
/********************************************************************************/

#ifndef PapyPrivFunctionDef3H 
#define PapyPrivFunctionDef3H



/* --- functions definitions --- */



/* --- PapyDataSetRead3 --- */

PapyShort 
ExtractFileMetaInformation3 	(PapyShort);

PapyShort 
ExtractPapyDataSetInformation3  (PapyShort);

PapyShort 
ExtractDicomDataSetInformation3 (PapyShort);

PapyShort 
ExtractGroup28Information 	(PapyShort);


/* --- PapyDataSetWrite3 --- */

void 
LookForGroupsInModule3 		(Module *, int, int *, int *);

PapyShort
ItemModulesToGroups3 		(PapyShort, Item *, int);

PapyShort
ItemRecordsToGroups3            (PapyShort, Item *, int);

int 
Papy3GetRecordType 		(SElement *);

PapyShort 
CreateFileMetaInformation3 	(PapyShort, enum EPap_Compression, enum ETransf_Syntax, 
				 enum EModality);

void 
KeepReferences3                 (PapyShort, int, int, UValue_T *);

PapyShort 
SequencesToGroups3              (PapyShort, Item *, int);

PapyShort
CreateTmpFile3                  (PapyShort, PAPY_FILE *, void **);

PapyShort
WriteDicomHeader3               (PAPY_FILE, PapyShort, PapyULong *);


/* --- PapyFiles3 --- */

PapyULong 
ComputeUndefinedGroupLength3    (PapyShort, PapyLong);

PapyShort 
ComputeUndefinedSequenceLength3	(PapyShort, PapyULong *);

PapyShort 
ComputeUndefinedItemLength3	(PapyShort, PapyULong *);

PapyShort 
ReadGroup3 			(PapyShort, PapyUShort *, unsigned char **,
			      	 PapyULong *, PapyULong *);		  

PapyShort 
WriteGroup3 			(PAPY_FILE fp, unsigned char *, PapyULong);



/* --- PapyInit3 --- */

void 
InitGroup3 	 	(int, SElement *);

void 
InitModule3 	 	(int, SElement *);

void 
InitGroupNbAndSize3 	();

void 
InitModuleSize3 	();

void 
InitDataSetModules3 	();

void 
InitUIDs3 		();

void 
InitModulesLabels3  	();

Module*
CreateModule3	        (int);

PapyShort 
Papy3FreeSQElement 	(SElement **, Module *, int);


/* --- PapyRead3 --- */

PapyShort
PutBufferInGroup3 	(PapyShort, unsigned char *, SElement *, PapyUShort, PapyULong, 
		   	 PapyULong *, PapyLong);

PapyUShort
Extract2Bytes 	  	(unsigned char *, PapyULong *);

extern PapyULong  
Extract4Bytes     	(unsigned char *, PapyULong *);



/* --- PapyWrite3 --- */

PapyShort 
ComputeGroupLength3  	(PapyShort, SElement *, PapyULong *, enum ETransf_Syntax);

PapyULong 
ComputeSequenceLength3	(Item *, enum ETransf_Syntax);

void
Put4Bytes		(PapyULong, unsigned char *, PapyULong *);

PapyShort 
PutGroupInBuffer 	(PapyShort, PapyShort, int , SElement *, 
			 unsigned char *, PapyULong *, int);



#endif	    /* PapyPrivFunctionDef3H */

