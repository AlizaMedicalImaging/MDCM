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
/*	Project  : P A P Y R U S  Toolkit					                        */
/*	File     : PapyEalloc3.c						                            */
/*	Function : contains all the allocating stuff		     		            */
/*	Authors  : Matthieu Funk						                            */
/*             Christian Girard                                                 */
/*             Jean-Francois Vurlod                                             */
/*             Marianne Logean                                                  */
/*                                                                              */
/*	History  : 12.1990	version 1.0                                             */
/*             07.1992	version 1.2                                             */
/*             05.1993	version 2.0                                             */
/*             06.1995	version 3.1                                             */
/*             02.1996	version 3.3                                             */
/*             02.1999	version 3.6                                             */
/*             04.2001	version 3.7                                             */
/*             09.2001  version 3.7  on CVS                                     */
/*                                                                              */
/********************************************************************************/


/* ------------------------- includes ---------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#ifndef PapyTypeDef3H
#include "PapyTypeDef3.h"
#endif
#include  "PapyWild3.h"



/********************************************************************************/
/*                                                                              */
/*	checkvp3 : check if the new allocated did not failed                        */
/*	return : the validated pointer if OK                                        */
/*           else exit the program                                              */
/*                                                                              */
/********************************************************************************/

static void *
checkvp3 (void *pointer)
{
	if (pointer == NULL)
		wildrexit ("allocating memory");
		
	return pointer;
	
} /* endof checkvp3 */


/********************************************************************************/
/*                                                                              */
/*	emalloc3 : checked version of malloc                                        */
/*	return : the validated pointer if OK                                        */
/*                                                                              */
/********************************************************************************/

void *
emalloc3 (PapyULong size)
{
	return checkvp3 (malloc ((size_t) size));
} /* endof emalloc3 */


/********************************************************************************/
/*                                                                              */
/*	ecalloc3 : checked version of calloc                                        */
/*	return : the validated pointer if OK                                        */
/*                                                                              */
/********************************************************************************/

void *
ecalloc3 (PapyULong nelem, PapyULong elsize)
{
	return checkvp3 (calloc ((size_t) nelem, (size_t) elsize));
} /* endof ecalloc3 */


/********************************************************************************/
/*                                                                              */
/*	erealloc3 : checked version of realloc                                      */
/*	return : the validated pointer if OK                                        */
/*                                                                              */
/********************************************************************************/

void *
erealloc3 (void *ptr, PapyULong size,PapyULong size2)
{
  return checkvp3 (realloc ((char *)ptr, (size_t) size));

} /* endof erealloc3 */


/********************************************************************************/
/*                                                                              */
/*	efree3 : free the allocated memory and put the pointer to NULL              */
/*                                                                              */
/********************************************************************************/

/* modify it to have the pointer on the pointer to really put it to NULL */

void
efree3 (void **p)
{
    if (*p) free((char *)*p);
    *p = NULL;
    
} /* endof efree3 */

