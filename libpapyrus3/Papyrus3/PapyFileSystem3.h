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
/*	Project  : P A P Y R U S  Toolkit                                           */
/*	File     : PapyFileSystem3.h                                                */
/*	Function : contains machine specific calls to the different file systems    */
/*	Authors  : Christian Girard                                                 */
/*             Marianne Logean                                                  */
/*                                                                              */
/*	History  : 06.1995	version 3.1                                             */
/*             02.1996	version 3.3                                             */
/*             02.1999	version 3.6                                             */
/*             04.2001	version 3.7                                             */
/*             09.2001  version 3.7  on CVS                                     */
/*             10.2001  version 3.71 MAJ Dicom par CHG                          */
/*                                                                              */
/********************************************************************************/

#ifndef PapyFileSystem3H
#define PapyFileSystem3H

/* ------------------------- includes ------------------------------------------*/

#ifndef FILENAME83		/* this is for the normal machines ... */

#ifndef PapyTypeDef3H
#include "PapyTypeDef3.h"
#endif
#ifndef PapyError3H
#include "PapyError3.h"
#endif

#else				/* FILENAME83 defined for the DOS machines */

#ifndef PapyTypeDef3H
#include "PAPYDEF3.h"
#endif
#ifndef PapyError3H
#include "PAPERR3.h"
#endif

#endif


/* ------------------------- functions definition ------------------------------*/

#ifdef _NO_PROTO
extern int		Papy3FCreate ();
extern PapyShort	Papy3FOpen   ();
extern int		Papy3FClose  ();
extern int		Papy3FDelete ();
extern PapyShort 	Papy3FRead   ();
extern PapyShort 	Papy3FWrite  ();
extern int		Papy3FTell   ();
extern int		Papy3FSeek   ();
extern void		Papy3FPrint  ();
#else
extern int		Papy3FCreate (char *, PAPY_FILE, PAPY_FILE *, void **);
extern PapyShort        Papy3FOpen   (char *, char, PAPY_FILE, PAPY_FILE *, void *);
extern int 		Papy3FClose  (PAPY_FILE *);
extern int		Papy3FDelete (char *, void *);
extern PapyShort 	Papy3FRead   (PAPY_FILE, PapyULong *, PapyULong, void *);
extern PapyShort 	Papy3FWrite  (PAPY_FILE, PapyULong *, PapyULong, void *);
extern int		Papy3FTell   (PAPY_FILE, PapyLong *);
extern int		Papy3FSeek   (PAPY_FILE, int, PapyLong);
extern void		Papy3FPrint  (char *, char *, int);
#endif

#endif /* PapyFileSystem3H */
