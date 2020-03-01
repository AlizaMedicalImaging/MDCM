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
/*	File     : PapyFileSystemUnix3.c                                            */
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

/* ------------------------- includes ------------------------------------------*/

#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <fcntl.h>		/* open */


#ifndef _WINDOWS
#ifndef Mac
#ifdef hpux
#include <sys/unistd.h>
#else
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/stat.h>
#include <unistd.h>
#endif
#endif
#endif



#ifndef PapyTypeDef3H
#include "PapyTypeDef3.h"
#endif

#ifndef __PapyError3__
#include "PapyError3.h"
#endif


/********************************************************************************/
/*										*/
/*	Papy3FCreate : overwrites the standard create file function		*/
/*	return : standard error message						*/
/*										*/
/********************************************************************************/

int
Papy3FCreate (char *inFilenameP, PAPY_FILE inVolume, PAPY_FILE *inFp, void **inFSSpecP)
{
  int         err;
  PAPY_FILE   file;
  
  if ((file = fopen (inFilenameP, "rb")) != NULL)
  {
    (void) fclose (file);
    RETURN (papFileAlreadyExist);
  }

  if ((file = fopen (inFilenameP, "wb")) == NULL)
    RETURN (papFileCreationFailed);

  (void) fclose (file);
    
  return 0;

} /* endof Papy3FCreate */


/********************************************************************************/
/*										*/
/*	Papy3FOpen : overwrites the standard open file function			*/
/*	return : standard error message						*/
/*										*/
/********************************************************************************/

PapyShort
Papy3FOpen (char *inFilenameP, char inPermission, PAPY_FILE inVolumeNb, PAPY_FILE *outFp,
            void *inFSSpecP)
/* inPermission r : read, w : write, a : read/write (all) */
{
  PAPY_FILE    file;

  switch (inPermission) {
    case 'r' : if ((*outFp = fopen (inFilenameP, "rb")) == NULL) 
                 RETURN (papOpenFile);              
               break;
    case 'w' : if ((*outFp = fopen (inFilenameP, "wb")) == NULL) 
                 RETURN (papOpenFile);               
               break;
    case 'a' : 
    default  : if ((*outFp = fopen (inFilenameP, "r+")) == NULL) 
                 RETURN (papOpenFile);
  }/* endsandwich */

  /*outFp = &file;*/

  return 0;

} /* endof Papy3FOpen */


/********************************************************************************/
/*										*/
/*	Papy3FClose : overwrites the standard close file function		*/
/*	return : standard error message						*/
/*										*/
/********************************************************************************/

int
Papy3FClose (PAPY_FILE *inFp)
{
  fclose (*inFp);
  
  return 0;
  
} /* endof Papy3FClose */


/********************************************************************************/
/*										*/
/*	Papy3FDelete : overwrites the standard delete file function		*/
/*	return : standard error message						*/
/*										*/
/********************************************************************************/

int
Papy3FDelete (char *inFilenameP, void *inIdentifierP)
{
  return (unlink ((char *) inFilenameP));

} /* endof Papy3FDelete */



/********************************************************************************/
/*										*/
/*	Papy3FRead : overwrites the standard read from file function		*/
/*	return : error (0 if OK, negative value otherwise)			*/
/*										*/
/********************************************************************************/

PapyShort
Papy3FRead (PAPY_FILE inFp, PapyULong *ioBytesToReadP, PapyULong inNb, void *ioBufferP)
{
  PapyShort  err = 0;
  
  err = (PapyShort)(fread ((char *) ioBufferP, (size_t) *ioBytesToReadP, inNb, inFp));
  if (err != inNb) return -1;
  else return 0;

} /* endof Papy3FRead */


/********************************************************************************/
/*									 	*/
/*	Papy3FWrite : overwrite the standard write to file function		*/
/*	return : error (0 if OK, negative value otherwise)			*/
/*										*/
/********************************************************************************/

PapyShort
Papy3FWrite (PAPY_FILE inFp, PapyULong *ioBytesToWriteP, PapyULong inNb, void *outBufferP)
{
  PapyShort  err = 0;
  
  err = (PapyShort)(fwrite ((char *) outBufferP, (int)*ioBytesToWriteP, inNb, inFp));

  return err;

} /* endof Papy3FWrite */


/********************************************************************************/
/*									 	*/
/*	Papy3FSeek : Papyrus own build file pointer positioning function.	*/
/*	return : standard error message						*/
/*										*/
/********************************************************************************/

int
Papy3FSeek (PAPY_FILE inFp, int inPosMode, PapyLong inOffset)
{
  PapyLong startPos, fileLimit;
  long     err;

  if (inOffset > 100000L) 
  {
    startPos = (PapyLong) ftell (inFp);
    /* get the end of file */
    err = fseek (inFp, 0L, (int) SEEK_END);
    fileLimit = (PapyLong) ftell (inFp);
    if (inOffset > fileLimit) return -1;  
    err = fseek (inFp, (long) startPos, (int) SEEK_SET);
  }

  err = fseek (inFp, (long) inOffset, inPosMode);
  
  return err;

} /* endof Papy3FSeek */


/********************************************************************************/
/*									 	*/
/*	Papy3FTell : Papyrus function to get the current position of the file	*/
/*	pointer.								*/
/*	return : standard error message						*/
/*										*/
/********************************************************************************/

int
Papy3FTell (PAPY_FILE inFp, PapyLong *outFilePosP)
{
  int err = 0;
  
  *outFilePosP = (PapyLong) ftell (inFp);
  
  return err;

} /* endof Papy3FTell */


/********************************************************************************/
/*									 	*/
/*	Papy3FPrint : Papyrus function to set a string.				*/
/*										*/
/********************************************************************************/

void
Papy3FPrint (char *inStringP, char *inFormatP, int inValue)
{
  
  sprintf (inStringP, inFormatP, inValue);
        
} /* endof Papy3FPrint */


