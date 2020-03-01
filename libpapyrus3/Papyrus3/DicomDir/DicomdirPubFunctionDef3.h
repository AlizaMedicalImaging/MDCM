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
/*	File     : DicomdirPubFunctionDef3.h                                        */
/*	Function : contains the declarations of the public functions                */
/*	Authors  : Christian Girard                                                 */
/*             Marianne Logean                                                  */
/*                                                                              */
/*	History  : 02.1999	version 3.6                                             */
/*                                                                              */
/********************************************************************************/


#ifndef DicomdirPubFunctionDef3H 
#define DicomdirPubFunctionDef3H





/* --- functions definitions --- */



/* --- DicomDirDataSetRead3 --- */

extern EXPORT32 Record*	EXPORT 
Papy3GetRecord		(PapyShort, int);



/* --- DicomDirDataSetWrite3 --- */

extern EXPORT32 Item*     EXPORT
Papy3CreateDicomDirDataSet (PapyShort);

extern EXPORT32 Item*     EXPORT
Papy3CreateDirRecItem (Module*);

extern EXPORT32 void 	  EXPORT
Papy3LinkRecordToDS (Item *, SElement *, int);

extern EXPORT32 Record*	  EXPORT 
Papy3CreateRecord	(int);



/* --- DicomDirFiles --- */

extern EXPORT32 PapyShort EXPORT 
Papy3DicomDirCreate	(char *, int, PAPY_FILE, int, void*);

extern EXPORT32 PapyShort EXPORT 
Papy3WriteAndCloseDicomDir (PapyShort, int);



/* --- DicomDirInit --- */

extern EXPORT32 PapyShort EXPORT 
DicD3Init 		();

extern EXPORT32 PapyShort EXPORT 
Papy3RecordFree 	(SElement **, int, int);



#endif	    /* DicomdirPubFunctionDef3H */

