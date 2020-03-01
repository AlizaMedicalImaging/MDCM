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
/*	File     : DicomdirInitRecords.h                                            */
/*	Function : declaration of the init fct.                                     */
/*	Authors  : Marianne Logean                                                  */
/*                                                                              */
/*	History  : 06.1997	version 3.5                                             */
/*             02.1999	version 3.6                                             */
/*                                                                              */
/********************************************************************************/

#ifndef DicomdirInitRecordsH 
#define DicomdirInitRecordsH
#endif


/* ------------------------- functions definition ------------------------------*/

#ifdef _NO_PROTO

extern void init_PatientR();
extern void init_StudyR();
extern void init_SeriesR();
extern void init_ImageR();
extern void init_OverlayR();
extern void init_ModalityLUTR();
extern void init_VOILUTR();
extern void init_CurveR();
extern void init_Topic();
extern void init_Visit();
extern void init_Result();
extern void init_Interpretation();
extern void init_StudyComponentR();
extern void init_PrintQueue();
extern void init_FilmSession();
extern void init_BasicFilmBox();
extern void init_BasicImageBox();

#else

extern void init_PatientR(SElement[]);
extern void init_StudyR(SElement[]);
extern void init_SeriesR(SElement[]);
extern void init_ImageR(SElement[]);
extern void init_OverlayR(SElement[]);
extern void init_ModalityLUTR(SElement[]);
extern void init_VOILUTR(SElement[]);
extern void init_CurveR(SElement[]);
extern void init_Topic(SElement[]);
extern void init_Visit(SElement[]);
extern void init_Result(SElement[]);
extern void init_Interpretation(SElement[]);
extern void init_StudyComponentR(SElement[]);
extern void init_PrintQueue(SElement[]);
extern void init_FilmSession(SElement[]);
extern void init_BasicFilmBox(SElement[]);
extern void init_BasicImageBox(SElement[]);

#endif    /* DicomdirInitRecordsH */


