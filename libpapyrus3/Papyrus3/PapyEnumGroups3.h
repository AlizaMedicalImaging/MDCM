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
/*	File     : PapyEnumGroups3.h                                                */
/*  Function : contains the declarations of the groups names and of the         */
/*		       elements names                                                   */
/*	Authors  : Christian Girard                                                 */
/*                                                                              */
/*	History  : 04.1994	version 3.0                                             */
/*             06.1995	version 3.1                                             */
/*             02.1996	version 3.3                                             */
/*             02.1999	version 3.6                                             */
/*             04.2001	version 3.7                                             */
/*             09.2001  version 3.7   on CVS                                    */
/*             10.2001  version 3.71  MAJ Dicom par CHG                         */
/*                                                                              */
/********************************************************************************/


#ifndef PapyEnumGroups3H 
#define PapyEnumGroups3H

#ifndef FILENAME83		/* this is for the normal machines ... */

#ifndef   PapyEnumImageGroups3H
#include "PapyEnumImageGroups3.h"
#endif

#else				/* FILENAME83 defined for the DOS machines */

#ifndef   PapyEnumImageGroups3H
#include "PAPEIG3.h"
#endif

#endif 				/* FILENAME83 defined */

/* 	enumeration of the groups	*/

enum groups {
Group2,
Group4,
Group8,
Group10,
Group18,
Group20,
Group28,
Group32,
Group38,
Group3A,
Group40,
Group41,
Group50,
Group54,
Group60,
Group70,
Group88,
Group100,
Group2000,
Group2010,
Group2020,
Group2030,
Group2040,
Group2050,
Group2100,
Group2110,
Group2120,
Group2130,
Group3002,
Group3004,
Group3006,
Group3008,
Group300A,
Group300C,
Group300E,
Group4000,
Group4008,
Group5000,
Group5400,
Group6000,
UINOVERLAY,
Group7FE0,
END_GROUP
};


#endif
