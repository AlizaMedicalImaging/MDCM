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
/*	File     : PapyWild3.c                                                      */
/*	Function : handle all the messages for program breaks                       */
/*	Authors  : Matthieu Funk                                                    */
/*             Christian Girard                                                 */
/*             Jean-Francois Vurlod                                             */
/*             Marianne Logean                                                  */
/*                                                                              */
/*	History  : 12.1990	version 1.0                                             */
/*             04.1991	version 1.1                                             */
/*             12.1991	version 1.2                                             */
/*             06.1993	version 2.0                                             */
/*             06.1994	version 3.0                                             */
/*             06.1995	version 3.1                                             */
/*             02.1996	version 3.3                                             */
/*             02.1999	version 3.6                                             */
/*             04.2001	version 3.7                                             */
/*             09.2001  version 3.7  on CVS                                     */
/*             10.2001  version 3.71 MAJ Dicom par CHG                          */
/*                                                                              */
/********************************************************************************/

/* ------------------------- includes ----------------------------------------*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>



/********************************************************************************/
/*                                                                              */
/*	wildname : compares the name of the breaking program                        */
/*	return :                                                                    */
/*                                                                              */
/********************************************************************************/

char *
wildname (register char *inNameP)
{
  register int	i;
  static char	theSaved [15];
  
  
  if (inNameP != NULL && *inNameP != '\0')
  {
    for (i = 0; (theSaved [i] = *inNameP) != '\0'; ++inNameP)
    {
      if (isalnum (*inNameP) && isupper (*inNameP))
        theSaved [i] = tolower (*inNameP);
      
      if ((*inNameP == '/' || *inNameP == '\\') && *(inNameP + 1) != '/' &&
          *(inNameP + 1) != '\\' && *(inNameP + 1) != '\0') i = 0;
      else if (i < sizeof theSaved - 1) ++i;
    } /* for */
    
    if (i > 5 && (strcmp (&theSaved [i - 4], ".exe") == 0 ||
	strcmp (&theSaved [i - 4], ".com") == 0)) theSaved [i - 4] = '\0';
		    
  } /* if */
  
  return (theSaved [0] == '\0') ? "?" : theSaved;
	
} /* endof wildname */


/********************************************************************************/
/*                                                                              */
/*	wild3 : writes the error message 				                            */
/*                                                                              */
/********************************************************************************/

void
wild3 (char *inPart1P,char * inPart2P)
{
  inPart1P = inPart1P;
  inPart2P = inPart2P;
#if qDebug
  (void) fflush (stdout);
	/*
	** One space after the colon matches what perror does
	** (although your typing teacher may want a second space).
	*/
  (void) fprintf (stderr, "\n%s: wild", wildname ((char *) NULL));
  if (inPart1P != NULL && *inPart1P != '\0')
    (void) fprintf (stderr, " %s", inPart1P);
  if (inPart2P != NULL && *inPart2P != '\0')
    (void) fprintf (stderr, " %s", inPart2P);
  (void) fprintf (stderr, "\n");
#endif
	
} /* endof wild3 */
