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
/*	Project  : P A P Y R U S  Toolkit (DicomDir library)                        */
/*	File     : DicomdirTypeDef3.h                                               */
/*	Function : contains the declarations of the constants, the enumerated       */
/*             types, the structures and the type definition for the            */
/*             Dicomdir library.                                                */
/*	Authors  : Marianne Logean                                                  */
/*                                                                              */
/*	History  : 02.1999	created	version 3.6                                     */
/*                                                                              */
/********************************************************************************/

#ifndef DicomdirTypeDef3H
#define DicomdirTypeDef3H


#define VR_AE_LENGTH 16		/* Application Entity */
#define VR_AS_LENGTH 4		/* Age string */
#define VR_AT_LENGTH 4		/* Attribute tag */
#define VR_CS_LENGTH 256	/* Control string */
#define VR_DA_LENGTH 10		/* Date */
#define VR_DS_LENGTH 16		/* Decimal string */
#define VR_DT_LENGTH 26		/* Date/Time */
#define VR_FL_LENGTH 16		/* Float */
#define VR_FD_LENGTH 4		/* Floating double */
#define VR_IS_LENGTH 8		/* Integer string */
#define VR_LO_LENGTH 64		/* Long string */
#define VR_LT_LENGTH 10240	/* Long text */
#define VR_PN_LENGTH 64		/* Person Name */
#define VR_SH_LENGTH 16		/* Short string */
#define VR_SL_LENGTH 4		/* Signed long */
#define VR_SS_LENGTH 2		/* Signed short */
#define VR_ST_LENGTH 1024	/* Short text */
#define VR_TM_LENGTH 16		/* Time */
#define VR_UI_LENGTH 64		/* Unique identifier (UID) */
#define VR_UL_LENGTH 4		/* Unsigned long */
#define VR_US_LENGTH 2		/* Unsigned short */


typedef struct SPatientData_ 
{
    struct SPatientData_        *nextPatient;
    char fileID			[VR_CS_LENGTH + 1];
    char SOP_ClassUID		[VR_UI_LENGTH + 1];
    char SOP_InstanceUID	[VR_UI_LENGTH + 1];
    char patientName		[VR_UI_LENGTH + 1];
    char patientID		[VR_UI_LENGTH + 1];
    char			*entry;
    struct SStudyData_		*studyInfo;
} SPatientData; 

typedef struct SStudyData_ 
{
    struct SStudyData_		*nextStudy;
    char fileID			[VR_CS_LENGTH + 1];
    char SOP_ClassUID		[VR_UI_LENGTH + 1];
    char SOP_InstanceUID	[VR_UI_LENGTH + 1];
    char studyDate		[VR_DA_LENGTH + 1];
    char studyTime		[VR_TM_LENGTH + 1];
    char studyInstanceUID	[VR_UI_LENGTH + 1];
    char studyID		[VR_UI_LENGTH + 1];
    char studyDescription	[VR_LO_LENGTH + 1];
    char			*entry;
    struct SSeriesData_		*seriesInfo;
} SStudyData;

typedef struct SSeriesData_ 
{
    struct SSeriesData_		*nextSeries;
    char fileID			[VR_CS_LENGTH + 1];
    char SOP_ClassUID		[VR_UI_LENGTH + 1];
    char SOP_InstanceUID	[VR_UI_LENGTH + 1];
    char modality		[VR_CS_LENGTH + 1];
    char institutionName	[VR_LO_LENGTH + 1];
    char institutionAddress	[VR_ST_LENGTH + 1];
    char seriesInstanceUID	[VR_UI_LENGTH + 1];
    char seriesNumber		[VR_IS_LENGTH + 1];
    char performingMD		[VR_PN_LENGTH + 1];
    char			*entry;
    struct SImageData_		*imageInfo;
    int	 			nbImages;
    int                         multiFrame;
} SSeriesData;

typedef struct SImageData_ 
{
    struct SImageData_		*nextImage;
    char fileID			[VR_CS_LENGTH + 1];
    char SOP_ClassUID		[VR_UI_LENGTH + 1];
    char SOP_InstanceUID	[VR_UI_LENGTH + 1];
    char imageNumber		[VR_IS_LENGTH + 1];
    char calibrationObject	[VR_CS_LENGTH + 1];
} SImageData;


#endif /* DicomdirTypeDef3H */

