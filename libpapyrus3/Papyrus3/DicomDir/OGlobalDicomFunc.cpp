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

// *************************************************************************** 
// *************************************************************************** 
//
//                      OGlobalDicomFunc
//
// ****************************************************************************
// ****************************************************************************
//
//  FILENAME	:	OGlobalDicomFunc.cpp
//
//  CLASSES	    :	none
//  
//  DESCRIPTION	:	Utility routines for DICOM type conversion.
//
//  HISTORY     :   24-02-99	CHG creation
//
// ****************************************************************************
// ****************************************************************************

// *****************************************************************************
// ***          INCLUDES
// *****************************************************************************
   
#include <string.h>


// *****************************************************************************
// ***          DicomDateToDate
// *****************************************************************************

void DicomDateToDate (char *inChar, char *outChar)
// converts the date introduced in DICOM files in something more displayable
{
  strcpy (outChar, inChar);
  if (outChar [4] != '.') 	// new style
  {
    outChar [4] = '.';
    outChar [5] = inChar [4];
    outChar [6] = inChar [5];
    outChar [7] = '.';
    outChar [8] = inChar [6];
    outChar [9] = inChar [7];
    outChar [10] = '\0';
  } // if ...new style
  
} // endofmethod DicomDateToDate


// *****************************************************************************
// ***          DicomTimeToTime
// *****************************************************************************

void DicomTimeToTime (char *inChar, char *outChar)
// converts the date introduced in DICOM files in something more displayable
{
  strcpy (outChar, inChar);
  if (outChar [2] != ':')	// new style time
  {
    outChar [2] = ':';
    outChar [3] = inChar [2];
    outChar [4] = inChar [3];
    outChar [5] = ':';
    outChar [6] = inChar [4];
    outChar [7] = inChar [5];
    outChar [8] = '\0';
  } // if ...new style time
  
} // endofmethod DicomTimeToTime


// *****************************************************************************
// ***          DicomNameToName
// *****************************************************************************

void DicomNameToName (char *inChar, char *outChar)
// converts the date introduced in DICOM files in something more displayable
{
  long	lengthOfString, i;
  
  lengthOfString = (long) strlen (inChar);
  for (i = 0; i < lengthOfString; i++)
    if (inChar [i] == '^') outChar [i] = ' ';
    else outChar [i] = inChar [i];
  outChar [lengthOfString] = '\0';
  
} // endofmethod DicomNameToName
