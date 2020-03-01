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
/*	File     : PapyInitModules3.h                                               */
/*	Function : declaration of the init fct.declaration of the init fct.         */
/*	Authors  : Christian Girard                                                 */
/*             Marianne Logean                                                  */
/*                                                                              */
/*	History  : 06.1994	version 3.0                                             */
/*             06.1995	version 3.1                                             */
/*             02.1996	version 3.3                                             */
/*             02.1999	version 3.6                                             */
/*             04.2001	version 3.7                                             */
/*             09.2001  version 3.7  on CVS                                     */
/*             10.2001  version 3.71 MAJ Dicom par CHG                          */
/*                                                                              */
/********************************************************************************/

#ifndef PapyInitModules3H 
#define PapyInitModules3H
#endif

/* ------------------------- includes ------------------------------------------*/


#ifndef Papyrus3H
#include "Papyrus3.h"
#endif

/* ------------------------- functions definition ------------------------------*/

#ifdef _NO_PROTO
extern void init_group2();
extern void init_group4();
extern void init_group8();
extern void init_group10();
extern void init_group18();
extern void init_group20();
extern void init_group28();
extern void init_group32();
extern void init_group38();
extern void init_group3A();
extern void init_group40();
extern void init_group41();
extern void init_group50();
extern void init_group54();
extern void init_group60();
extern void init_group70();
extern void init_group88();
extern void init_group100();
extern void init_group2000();
extern void init_group2010();
extern void init_group2020();
extern void init_group2030();
extern void init_group2040();
extern void init_group2050();
extern void init_group2100();
extern void init_group2110();
extern void init_group2120();
extern void init_group2130();
extern void init_group3002();
extern void init_group3004();
extern void init_group3006();
extern void init_group3008();
extern void init_group300A();
extern void init_group300C();
extern void init_group300E();
extern void init_group4000();
extern void init_group4008();
extern void init_group5000();
extern void init_group5400();
extern void init_group6000();
extern void init_group7FE0();
extern void init_uinoverlay ();
extern void init_AcquisitionContext ();
extern void init_Approval ();
extern void init_Audio ();
extern void init_BasicAnnotationPresentation ();
extern void init_BasicFilmBoxPresentation ();
extern void init_BasicFilmBoxRelationship ();
extern void init_BasicFilmSessionPresentation ();
extern void init_BasicFilmSessionRelationship ();
extern void init_BiPlaneImage ();
extern void init_BiPlaneOverlay ();
extern void init_BiPlaneSequence ();
extern void init_Cine ();
extern void init_ContrastBolus ();
extern void init_CRImage ();
extern void init_CRSeries ();
extern void init_CTImage ();
extern void init_Curve ();
extern void init_CurveIdentification ();
extern void init_Device ();
extern void init_DirectoryInformation ();
extern void init_DisplayShutter ();
extern void init_DXAnatomyImaged ();
extern void init_DXImage ();
extern void init_DXDetector ();
extern void init_DXPositioning ();
extern void init_DXSeries ();
extern void init_ExternalPapyrus_FileReferenceSequence ();
extern void init_ExternalPatientFileReferenceSequence ();
extern void init_ExternalStudyFileReferenceSequence ();
extern void init_ExternalVisitReferenceSequence ();
extern void init_FileReference ();
extern void init_FileSetIdentification ();
extern void init_FrameOfReference ();
extern void init_FramePointers ();
extern void init_GeneralEquipment ();
extern void init_GeneralPatientSummary ();
extern void init_GeneralSeriesSummary ();
extern void init_GeneralVisitSummary ();
extern void init_GeneralImage ();
extern void init_GeneralSeries ();
extern void init_GeneralStudy ();
extern void init_GeneralStudySummary ();
extern void init_IconImage ();
extern void init_IdentifyingImageSequence ();
extern void init_ImageBoxPixelPresentation ();
extern void init_ImageBoxRelationship ();
extern void init_ImageHistogram ();
extern void init_ImageIdentification ();
extern void init_ImageOverlayBoxPresentation ();
extern void init_ImageOverlayBoxRelationship ();
extern void init_ImagePlane ();
extern void init_ImagePointer ();
extern void init_ImageSequence ();
extern void init_ImagePixel ();
extern void init_InternalImagePointerSequence ();
extern void init_InterpretationApproval ();
extern void init_InterpretationIdentification ();
extern void init_InterpretationRecording ();
extern void init_InterpretationRelationship ();
extern void init_InterpretationState ();
extern void init_InterpretationTranscription ();
extern void init_IntraOralImage ();
extern void init_IntraOralSeries ();
extern void init_LUTIdentification ();
extern void init_MammographyImage ();
extern void init_MammographySeries ();
extern void init_Mask ();
extern void init_ModalityLUT ();
extern void init_MRImage ();
extern void init_Multi_frameOverlay ();
extern void init_Multi_Frame ();
extern void init_NMDetector ();
extern void init_NMImage ();
extern void init_NMImagePixel ();
extern void init_NMIsotope ();
extern void init_NMMultiFrame ();
extern void init_NMMulti_gatedAcquisitionImage ();
extern void init_NMPhase ();
extern void init_NMReconstruction ();
extern void init_NMSeries ();
extern void init_NMTomoAcquisition ();
extern void init_OverlayIdentification ();
extern void init_OverlayPlane ();
extern void init_PaletteColorLookup ();
extern void init_PatientDemographic ();
extern void init_PatientIdentification ();
extern void init_PatientMedical ();
extern void init_Patient () ;
extern void init_PatientRelationship ();
extern void init_PatientStudy ();
extern void init_PatientSummary ();
extern void init_PETCurve ();
extern void init_PETImage ();
extern void init_PETIsotope ();
extern void init_PETMultiGatedAcquisition ();
extern void init_PETSeries ();
extern void init_PixelOffset ();
extern void init_Printer ();
extern void init_PrintJob ();
extern void init_ResultIdentification ();
extern void init_ResultsImpression ();
extern void init_ResultRelationship ();
extern void init_RFTomographyAcquisition ();
extern void init_ROIContour ();
extern void init_RTBeams ();
extern void init_RTBrachyApplicationSetups ();
extern void init_RTDose ();
extern void init_RTDoseROI ();
extern void init_RTDVH ();
extern void init_RTFractionScheme ();
extern void init_RTGeneralPlan ();
extern void init_RTImage ();
extern void init_RTPatientSetup ();
extern void init_RTPrescription ();
extern void init_RTROIObservations ();
extern void init_RTSeries ();
extern void init_RTToleranceTables ();
extern void init_StructureSet ();
extern void init_SCImageEquipment ();
extern void init_SCImage ();
extern void init_SCMultiFrameImage ();
extern void init_SCMultiFrameVector ();
extern void init_SlideCoordinates ();
extern void init_SOPCommon ();
extern void init_SpecimenIdentification ();
extern void init_StudyAcquisition ();
extern void init_StudyClassification ();
extern void init_StudyComponentAcquisition ();
extern void init_StudyComponent ();
extern void init_StudyComponentRelationship ();
extern void init_StudyContent ();
extern void init_StudyIdentification ();
extern void init_StudyRead ();
extern void init_StudyRelationship ();
extern void init_StudyScheduling ();
extern void init_Therapy ();
extern void init_UINOverlaySequence ();
extern void init_USImage ();
extern void init_USFrameofReference ();
extern void init_USRegionCalibration ();
extern void init_VisitAdmission ();
extern void init_VisitDischarge ();
extern void init_VisitIdentification ();
extern void init_VisitRelationship ();
extern void init_VisitScheduling ();
extern void init_VisitStatus ();
extern void init_VLImage ();
extern void init_VOILUT ();
extern void init_XRayAcquisition ();
extern void init_XRayAcquisitionDose ();
extern void init_XRayCollimator ();
extern void init_XRayFiltration ();
extern void init_XRayGeneration ();
extern void init_XRayGrid ();
extern void init_XRayImage ();
extern void init_XRayTable ();
extern void init_XRayTomographyAcquisition ();
extern void init_XRFPositioner ();
#else
extern void init_group2(SElement[]);
extern void init_group4(SElement[]);
extern void init_group8(SElement[]);
extern void init_group10(SElement[]);
extern void init_group18(SElement[]);
extern void init_group20(SElement[]);
extern void init_group28(SElement[]);
extern void init_group32(SElement[]);
extern void init_group38(SElement[]);
extern void init_group3A(SElement[]);
extern void init_group40(SElement[]);
extern void init_group41(SElement[]);
extern void init_group50(SElement[]);
extern void init_group54(SElement[]);
extern void init_group60(SElement[]);
extern void init_group70(SElement[]);
extern void init_group88(SElement[]);
extern void init_group100(SElement[]);
extern void init_group2000(SElement[]);
extern void init_group2010(SElement[]);
extern void init_group2020(SElement[]);
extern void init_group2030(SElement[]);
extern void init_group2040(SElement[]);
extern void init_group2050(SElement[]);
extern void init_group2100(SElement[]);
extern void init_group2110(SElement[]);
extern void init_group2120(SElement[]);
extern void init_group2130(SElement[]);
extern void init_group3002(SElement[]);
extern void init_group3004(SElement[]);
extern void init_group3006(SElement[]);
extern void init_group3008(SElement[]);
extern void init_group300A(SElement[]);
extern void init_group300C(SElement[]);
extern void init_group300E(SElement[]);
extern void init_group4000(SElement[]);
extern void init_group4008(SElement[]);
extern void init_group5000(SElement[]);
extern void init_group5400(SElement[]);
extern void init_group6000(SElement[]);
extern void init_group7FE0(SElement[]);
extern void init_uinoverlay (SElement[]);
extern void init_AcquisitionContext (SElement[]);
extern void init_Approval (SElement[]);
extern void init_Audio (SElement[]);
extern void init_BasicAnnotationPresentation (SElement[]);
extern void init_BasicFilmBoxPresentation (SElement[]);
extern void init_BasicFilmBoxRelationship (SElement[]);
extern void init_BasicFilmSessionPresentation (SElement[]);
extern void init_BasicFilmSessionRelationship (SElement[]);
extern void init_BiPlaneImage (SElement[]);
extern void init_BiPlaneOverlay (SElement[]);
extern void init_BiPlaneSequence (SElement[]);
extern void init_Cine (SElement[]);
extern void init_ContrastBolus (SElement[]);
extern void init_CRImage (SElement[]);
extern void init_CRSeries (SElement[]);
extern void init_CTImage (SElement[]);
extern void init_Curve (SElement[]);
extern void init_CurveIdentification (SElement[]);
extern void init_Device (SElement[]);
extern void init_DirectoryInformation (SElement[]);
extern void init_DisplayShutter (SElement[]);
extern void init_DXAnatomyImaged (SElement[]);
extern void init_DXImage (SElement[]);
extern void init_DXDetector (SElement[]);
extern void init_DXPositioning (SElement[]);
extern void init_DXSeries (SElement[]);
extern void init_ExternalVisitReferenceSequence (SElement[]);
extern void init_ExternalStudyFileReferenceSequence (SElement[]);
extern void init_ExternalPatientFileReferenceSequence (SElement[]);
extern void init_ExternalPapyrus_FileReferenceSequence (SElement[]);
extern void init_FileReference (SElement[]);
extern void init_FileSetIdentification (SElement[]);
extern void init_FrameOfReference (SElement[]);
extern void init_FramePointers (SElement[]);
extern void init_GeneralEquipment (SElement[]);
extern void init_GeneralPatientSummary (SElement[]);
extern void init_GeneralSeries (SElement[]);
extern void init_GeneralSeriesSummary (SElement[]);
extern void init_GeneralVisitSummary (SElement[]);
extern void init_GeneralImage (SElement[]);
extern void init_GeneralStudy (SElement[]);
extern void init_GeneralStudySummary (SElement[]);
extern void init_IconImage (SElement[]);
extern void init_IdentifyingImageSequence (SElement[]);
extern void init_ImageBoxPixelPresentation (SElement[]);
extern void init_ImageBoxRelationship (SElement[]);
extern void init_ImageHistogram (SElement[]);
extern void init_ImageIdentification (SElement[]);
extern void init_ImageOverlayBoxPresentation (SElement[]);
extern void init_ImageOverlayBoxRelationship (SElement[]);
extern void init_ImagePixel (SElement[]);
extern void init_ImagePlane (SElement[]);
extern void init_ImagePointer (SElement[]);
extern void init_ImageSequence (SElement[]);
extern void init_InterpretationApproval (SElement[]);
extern void init_InterpretationIdentification (SElement[]);
extern void init_InterpretationRecording (SElement[]);
extern void init_InterpretationRelationship (SElement[]);
extern void init_InterpretationState (SElement[]);
extern void init_InterpretationTranscription (SElement[]);
extern void init_InternalImagePointerSequence (SElement[]);
extern void init_IntraOralImage (SElement[]);
extern void init_IntraOralSeries (SElement[]);
extern void init_LUTIdentification (SElement[]);
extern void init_MammographyImage (SElement[]);
extern void init_MammographySeries (SElement[]);
extern void init_Mask (SElement[]);
extern void init_ModalityLUT (SElement[]);
extern void init_MRImage (SElement[]);
extern void init_Multi_frameOverlay (SElement[]);
extern void init_Multi_Frame (SElement[]);
extern void init_NMDetector (SElement[]);
extern void init_NMImage (SElement[]);
extern void init_NMImagePixel (SElement[]);
extern void init_NMIsotope (SElement[]);
extern void init_NMMultiFrame (SElement[]);
extern void init_NMMulti_gatedAcquisitionImage (SElement[]);
extern void init_NMPhase (SElement[]);
extern void init_NMReconstruction (SElement[]);
extern void init_NMSeries (SElement[]);
extern void init_NMTomoAcquisition (SElement[]);
extern void init_OverlayIdentification (SElement[]);
extern void init_OverlayPlane (SElement[]);
extern void init_PaletteColorLookup (SElement[]);
extern void init_PatientDemographic (SElement[]);
extern void init_PatientIdentification (SElement[]);
extern void init_PatientMedical (SElement[]);
extern void init_Patient (SElement[]) ;
extern void init_PatientRelationship (SElement[]);
extern void init_PatientStudy (SElement[]);
extern void init_PatientSummary (SElement[]);
extern void init_PETCurve (SElement[]);
extern void init_PETImage (SElement[]);
extern void init_PETIsotope (SElement[]);
extern void init_PETMultiGatedAcquisition (SElement[]);
extern void init_PETSeries (SElement[]);
extern void init_PixelOffset (SElement[]);
extern void init_Printer (SElement[]);
extern void init_PrintJob (SElement[]);
extern void init_ResultIdentification (SElement[]);
extern void init_ResultsImpression (SElement[]);
extern void init_ResultRelationship (SElement[]);
extern void init_RFTomographyAcquisition (SElement[]);
extern void init_ROIContour (SElement[]);
extern void init_RTBeams (SElement[]);
extern void init_RTBrachyApplicationSetups (SElement[]);
extern void init_RTDose (SElement[]);
extern void init_RTDoseROI (SElement[]);
extern void init_RTDVH (SElement[]);
extern void init_RTFractionScheme (SElement[]);
extern void init_RTGeneralPlan (SElement[]);
extern void init_RTImage (SElement[]);
extern void init_RTPatientSetup (SElement[]);
extern void init_RTPrescription (SElement[]);
extern void init_RTROIObservations (SElement[]);
extern void init_RTSeries (SElement[]);
extern void init_RTToleranceTables (SElement[]);
extern void init_StructureSet (SElement[]);
extern void init_SCImageEquipment (SElement[]);
extern void init_SCImage (SElement[]);
extern void init_SCMultiFrameImage (SElement[]);
extern void init_SCMultiFrameVector (SElement[]);
extern void init_SlideCoordinates (SElement[]);
extern void init_SOPCommon (SElement[]);
extern void init_SpecimenIdentification (SElement[]);
extern void init_StudyAcquisition (SElement[]);
extern void init_StudyClassification (SElement[]);
extern void init_StudyComponentAcquisition (SElement[]);
extern void init_StudyComponent (SElement[]);
extern void init_StudyComponentRelationship (SElement[]);
extern void init_StudyContent (SElement[]);
extern void init_StudyIdentification (SElement[]);
extern void init_StudyRead (SElement[]);
extern void init_StudyRelationship (SElement[]);
extern void init_StudyScheduling (SElement[]);
extern void init_Therapy (SElement[]);
extern void init_UINOverlaySequence (SElement[]);
extern void init_USImage (SElement[]);
extern void init_USFrameofReference (SElement[]);
extern void init_USRegionCalibration (SElement[]);
extern void init_VisitAdmission (SElement[]);
extern void init_VisitDischarge (SElement[]);
extern void init_VisitIdentification (SElement[]);
extern void init_VisitRelationship (SElement[]);
extern void init_VisitScheduling (SElement[]);
extern void init_VisitStatus (SElement[]);
extern void init_VLImage (SElement[]);
extern void init_VOILUT (SElement[]);
extern void init_XRayAcquisition (SElement[]);
extern void init_XRayAcquisitionDose (SElement[]);
extern void init_XRayCollimator (SElement[]);
extern void init_XRayFiltration (SElement[]);
extern void init_XRayGeneration (SElement[]);
extern void init_XRayGrid (SElement[]);
extern void init_XRayImage (SElement[]);
extern void init_XRayTable (SElement[]);
extern void init_XRayTomographyAcquisition (SElement[]);
extern void init_XRFPositioner (SElement[]);
#endif


