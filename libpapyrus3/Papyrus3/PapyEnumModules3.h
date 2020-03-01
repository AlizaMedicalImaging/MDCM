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
/*	File     : PapyEnumModules3.h                                               */
/*	Function : contains the declarations of the modules names                   */
/*	Authors  : Christian Girard                                                 */
/*                                                                              */
/*	History  : 04.1994	version 3.0                                             */
/*             06.1995	version 3.1                                             */
/*             02.1996	version 3.3                                             */
/*             02.1999	version 3.6                                             */
/*             04.2001	version 3.7                                             */
/*             09.2001  version 3.7  on CVS                                     */
/*             10.2001  version 3.71 MAJ Dicom par CHG                          */
/*                                                                              */
/********************************************************************************/


#ifndef PapyEnumModulesH 
#define PapyEnumModulesH

#ifndef FILENAME83		/* this is for the normal machines ... */

#include "PapyEnumImagesModules3.h"

#else				/* FILENAME83 defined for the DOS machines */

#include "PAPEIM3.h"

#endif 				/* FILENAME83 defined */


/* 	enumeration of the modules	*/

enum modules {
AcquisitionContext,       
Approval,
Audio,                                           
BasicAnnotationPresentation,
BasicFilmBoxPresentation,
BasicFilmBoxRelationship,
BasicFilmSessionPresentation,
BasicFilmSessionRelationship,
BiPlaneImage,
BiPlaneOverlay,
BiPlaneSequence,
Cine,
ContrastBolus,
CRImage,
CRSeries,
CTImage,
Curve,
CurveIdentification,
Device,
DirectoryInformation,
DisplayShutter,
DXAnatomyImaged,
DXImage,
DXDetector,
DXPositioning,
DXSeries,
ExternalPapyrus_FileReferenceSequence,
ExternalPatientFileReferenceSequence,
ExternalStudyFileReferenceSequence,
ExternalVisitReferenceSequence,
FileReference,
FileSetIdentification,
FrameOfReference,
FramePointers,
GeneralEquipment,
GeneralImage,
GeneralPatientSummary,
GeneralSeries,
GeneralSeriesSummary,
GeneralStudy,
GeneralStudySummary,
GeneralVisitSummary,
IconImage,
IdentifyingImageSequence,
ImageBoxRelationship,
ImageBoxPixelPresentation,
ImageHistogram,
ImageIdentification,
ImageOverlayBoxRelationship,
ImageOverlayBoxPresentation,
ImagePixel,
ImagePlane,
ImagePointer,
ImageSequencePap,
InternalImagePointerSequence,
InterpretationApproval,
InterpretationIdentification,
InterpretationRecording,
InterpretationRelationship,
InterpretationState,
InterpretationTranscription,
IntraOralImage,
IntraOralSeries,
LUTIdentification,
MammographyImage,
MammographySeries,
Mask,
ModalityLUT,
MRImage,
Multi_frameOverlay,
Multi_Frame,
NMDetector,
NMImage,
NMImagePixel,
NMIsotope,
NMMulti_gatedAcquisitionImage,
NMMultiFrame,
NMPhase,
NMReconstruction,
NMSeries,
NMTomoAcquisition,
OverlayIdentification,
OverlayPlane,
PaletteColorLookup,
PatientDemographic,
PatientIdentification,
PatientMedical,
Patient,
PatientRelationship,
PatientStudy,
PatientSummary,
PETCurve,
PETImage,
PETIsotope,
PETMultiGatedAcquisition,
PETSeries,
PixelOffset,
Printer,
PrintJob,
ResultIdentification,
ResultsImpression,
ResultRelationship,
RFTomographyAcquisition,
ROIContour,
RTBeams,
RTBrachyApplicationSetups,
RTDose,
RTDoseROI,
RTDVH,
RTFractionScheme,
RTGeneralPlan,
RTImage,
RTPatientSetup,
RTPrescription,
RTROIObservations,
RTSeries,
RTToleranceTables,
SCImage,
SCImageEquipment,
SCMultiFrameImage,
SCMultiFrameVector,
SlideCoordinates,
SOPCommon,
SpecimenIdentification,
StructureSet,
StudyAcquisition,
StudyClassification,
StudyComponentAcquisition,
StudyComponent,
StudyComponentRelationship,
StudyContent,
StudyIdentification,
StudyRead,
StudyRelationship,
StudyScheduling,
Therapy,
UINOverlaySequence,
USImage,
USFrameofReference,
USRegionCalibration,
VisitAdmission,
VisitDischarge,
VisitIdentification,
VisitRelationship,
VisitScheduling,
VisitStatus,
VLImage,
VOILUT,
XRayAcquisition,
XRayAcquisitionDose,
XRayCollimator,
XRayFiltration,
XRayGeneration,
XRayGrid,
XRayImage,
XRayTable,
XRayTomographyAcquisition,
XRFPositioner,
END_MODULE
};

/* 	enumeration of the records	*/

enum records {
PatientR,
StudyR,
SeriesR,
ImageR,
OverlayR,
ModalityLUTR,
VOILUTR,
CurveR,
Topic,
Visit,
Result,
Interpretation,
StudyComponentR,
PrintQueue,
FilmSession,
BasicFilmBox,
BasicImageBox,
END_RECORD
};

#endif	    /* PapyEnumModulesH */
