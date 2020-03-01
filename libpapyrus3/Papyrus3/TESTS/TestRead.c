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
/*	File     : TestRead.c                                                       */
/*	Function : Main for read testing the Papyrus toolkit 3.0.                   */
/*	Authors  : Christian Girard                                                 */
/*             Marianne Logean                                                  */
/*                                                                              */
/*	History  : 07.1994	version 3.0                                             */
/*             03.1999  version 3.6                                             */
/*             04.2001  version 3.7                                             */
/*                                                                              */
/********************************************************************************/
#define MAIN

#include <stdio.h>
#include <stdlib.h> /* exit */
#include "Papyrus3.h"


main (int argc, char *argv[])
{
  char          patName[256], firstPhysician [256], secondPhysician [256];
  int           itemType;
  PapyUShort	  *theImage;
  PapyShort	    fileNb, imageNb, err;
  PapyULong     nbVal, i;
  Module	      *module;    
  UValue_T      *val, *tmp;
  SElement      *group;

  /* initialisation of the Papyrus toolkit v3.6 */
  Papy3Init ();

  /* open the test file */
  fileNb = Papy3FileOpen (argv [1], (PAPY_FILE) 0, TRUE, 0);
  if (fileNb < 0)
  {
    PAPY3PRINTERRMSG ();
    exit(1);
  }
  
  imageNb = 1; /* first image */


  /* get the Patient module */
  module = Papy3GetModule (fileNb, (PapyShort)imageNb, Patient);
  
  /* get the patients name */
  val = Papy3GetElement (module, papPatientsNameP, &nbVal, &itemType);
  if (val != NULL)
    strcpy (patName, val->a);

  /* free the module and the associated sequences */
  Papy3ModuleFree (&module, Patient, TRUE);
  
  /* get the General Study module */
  module = Papy3GetModule (fileNb, (PapyShort)imageNb, GeneralStudy);
  
  /* IMPORTANT!!: this is an example of how to get multiple values!! */
  val = Papy3GetElement (module, papReferringPhysiciansNameGS, &nbVal, &itemType);
  if (val != NULL)
  {
    strcpy (firstPhysician, val->a);
    /* this allows to get the next value */
    tmp = val;
    /* get the second Physician Name */
    for (i = 1L; i < nbVal; i++) tmp ++;
    strcpy (secondPhysician, tmp->a);
  }

  /* free the module and the associated sequences */
  Papy3ModuleFree (&module, GeneralStudy, TRUE);
  
  /* position the file pointer to the begining of the data set */
  err = Papy3GotoNumber (fileNb, (PapyShort)imageNb, DataSetID);

  /* then goto group 0x7FE0 */
  if ((err = Papy3GotoGroupNb (fileNb, 0x7FE0)) == 0)
  {
    /* read group 0x7FE0 from the file */
    if ((err = Papy3GroupRead (fileNb, &group)) > 0) 
    {
      /* PIXEL DATA */
      theImage = (PapyUShort *)Papy3GetPixelData (fileNb, imageNb, group, ImagePixel);

      /* free group 7FE0 */
      err = Papy3GroupFree (&group, TRUE);

    } /* endif ...group 7FE0 read */

  } /* endif ...group 7FE0 found */

    
  /* close and free the file and the associated allocated memory */
  Papy3FileClose (fileNb, TRUE);
    
  /* free the allocated global value in the toolkit */
  Papy3FreeDataSetModules ();

} /* end of main */
