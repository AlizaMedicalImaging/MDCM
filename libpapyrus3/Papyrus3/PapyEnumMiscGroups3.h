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
/*	File     : PapyEnumMiscGroups3.h                                            */
/*	Function : contains the declarations of the groups names and of the         */
/*             elements names                                                   */
/*	Authors  : Christian Girard                                                 */
/*                                                                              */
/*	History  : 04.1994	version 3.0                                             */
/*             06.1995	version 3.1                                             */
/*             02.1996	version 3.3                                             */
/*             02.1999	version 3.6                                             */
/*             04.2001	version 3.7                                             */
/*             09.2001  version 3.7  on CVS                                     */
/*                                                                              */
/********************************************************************************/


#ifndef PapyEnumMiscGroups3H 
#define PapyEnumMiscGroups3H



/*	Group32		*/

enum {
papStudyStatusIDGr = 1,
papStudyPriorityIDGr,
papStudyIDIssuerGr,
papStudyVerifiedDateGr,
papStudyVerifiedTimeGr,
papStudyReadDateGr,
papStudyReadTimeGr,
papScheduledStudyStartDateGr,
papScheduledStudyStartTimeGr,
papScheduledStudyStopDateGr,
papScheduledStudyStopTimeGr,
papScheduledStudyLocationGr,
papScheduledStudyLocationAETitlesGr,
papReasonforStudyGr,
papRequestingPhysicianGr,
papRequestingServiceGr,
papStudyArrivalDateGr,
papStudyArrivalTimeGr,
papStudyCompletionDateGr,
papStudyCompletionTimeGr,
papStudyComponentStatusIDGr,
papRequestedProcedureDescriptionGr,
papRequestedProcedureCodeSequenceGr,
papRequestedContrastAgentGr,
papStudyCommentsGr,
papEndGroup32
};

/*	Group38		*/

enum {
papReferencedPatientAliasSequenceGr = 1,
papVisitStatusIDGr,
papAdmissionIDGr,
papIssuerofAdmissionIDGr,
papRouteofAdmissionsGr,
papScheduledAdmissionDateGr,
papScheduledAdmissionTimeGr,
papScheduledDischargeDateGr,
papScheduledDischargeTimeGr,
papScheduledPatientInstitutionResidenceGr,
papAdmittingDateGr,
papAdmittingTimeGr,
papDischargeDateGr,
papDischargeTimeGr,
papDischargeDiagnosisDescriptionGr,
papDischargeDiagnosisCodeSequenceGr,
papSpecialNeedsGr,
papCurrentPatientLocationGr,
papPatientsInstitutionResidenceGr,
papPatientStateGr,
papVisitCommentsGr,
papEndGroup38
};

/*	Group40 	*/

enum {
papScheduledStationAETitleGr = 1,
papScheduledProcedureStepStartDateGr,
papScheduledProcedureStepStartTimeGr,
papScheduledProcedureStepEndDateGr,
papScheduledProcedureStepEndTimeGr,
papScheduledPerformingPhysiciansNameGr,
papScheduledProcedureStepDescriptionGr,
papScheduledActionItemCodeSequenceGr,
papScheduledProcedureStepIDGr,
papScheduledStationNameGr,
papScheduledProcedureStepLocationGr,
papPreMedicationGr,
papScheduledProcedureStepSequenceGr,
papCommentsontheScheduledProcedureStepGr,
papRequestedProcedureIDGr,
papReasonfortheRequestedProcedureGr,
papRequestedProcedurePriorityGr,
papPatientTransportArrangementsGr,
papRequestedProcedureLocationGr,
papPlacerOrderNumberProcedureGr,
papFillerOrderNumberProcedureGr,
papConfidentialityCodeGr,
papReportingPriorityGr,
papNamesofIntendedRecipientsofResultsGr,
papRequestedProcedureCommentsGr,
papReasonfortheImagingServiceRequestGr,
papIssueDateofImagingServiceRequestGr,
papIssueTimeofImagingServiceRequestGr,
papPlacerOrderNumberImagingServiceRequestGr,
papFillerOrderNumberImagingServiceRequestGr,
papOrderEnteredByGr,
papOrderEnterersLocationGr,
papOrderCallbackPhoneNumberGr,
papImagingServiceRequestCommentsGr,
papConfidentialityConstraintonPatientDataDescriptionGr,
papEndGroup40
};

/*	Group50		*/

enum {
papCalibrationObjectGr = 1,
papDeviceSequenceGr,
papDeviceLengthGr,
papDeviceDiameterGr,
papDeviceDiameterUnitsGr,
papDeviceVolumeGr,
papIntermarkerDistanceGr,
papDeviceDescriptionGr,
papEndGroup50
};

/*	Group54		*/

enum {
papEnergyWindowVectorGr = 1,
papNumberofEnergyWindowsGr,
papEnergyWindowInformationSequenceGr,
papEnergyWindowRangeSequenceGr,
papEnergyWindowLowerLimitGr,
papEnergyWindowUpperLimitGr,
papRadiopharmaceuticalInformationSequenceGr,
papResidualSyringeCountsGr,
papEnergyWindowNameGr,
papDetectorVectorGr,
papNumberofDetectorsGr,
papDetectorInformationSequenceGr,
papPhaseVectorGr,
papNumberofPhasesGr,
papPhaseInformationSequenceGr,
papNumberofFramesinPhaseGr,
papPhaseDelayGr,
papPauseBetweenFramesGr,
papRotationVectorGr,
papNumberofRotationsGr,
papRotationInformationSequenceGr,
papNumberofFramesinRotationGr,
papRRIntervalVectorGr,
papNumberofRRIntervalsGr,
papGatedInformationSequenceGr,
papDataInformationSequenceGr,
papTimeSlotVectorGr,
papNumberofTimeSlotsGr,
papTimeSlotInformationSequenceGr,
papTimeSlotTimeGr,
papSliceVectorGr,
papNumberofSlicesGr,
papAngularViewVectorGr,
papTimeSliceVectorGr,
papStartAngleGr,
papTypeofDetectorMotionGr,
papTriggerVectorGr,
papNumberofTriggersinPhaseGr,
papViewCodeSequenceGr,
papViewAngulationModifierCodeSequenceGr,
papRadionuclideCodeSequenceGr,
papRadiopharmaceuticalRouteCodeSequenceGr,
papRadiopharmaceuticalCodeSequenceGr,
papCalibrationDataSequenceGr,
papEnergyWindowNumberGr,
papImageIDGr,
papPatientOrientationCodeSequenceGr,
papPatientOrientationModifierCodeSequenceGr,
papPatientGantryRelationshipCodeSequenceGr,
papEndGroup54
};

/*	Group88		*/

enum {
papStorageMediaFilesetIDGr = 1,
papStorageMediaFilesetUIDGr,
papIconImageSequenceGr,
papTopicTitleGr,
papTopicSubjectGr,
papTopicAuthorGr,
papTopicKeyWordsGr,
papEndGroup88
};

/*	Group2000		*/

enum {
papNumberOfCopiesGr = 1,
papPrintPriorityGr,
papMediumTypeGr,
papFilmDestinationGr,
papFilmSessionLabelGr,
papMemoryAllocationGr,
papReferencedFilmBoxSequenceGr,
papEndGroup2000
};

/*	Group2010		*/

enum {
papImageDisplayFormatGr = 1,
papAnnotationDisplayFormatIDGr,
papFilmOrientationGr,
papFilmSizeIDGr,
papMagnificationTypeGr,
papSmoothingTypeGr,
papBorderDensityGr,
papEmptyImageDensityGr,
papMinDensityGr,
papMaxDensityGr,
papTrimGr,
papConfigurationInformationGr,
papReferencedFilmSessionSequenceGr,
papReferencedImageBoxSequence2010Gr,
papReferencedBasicAnnotationBoxSequenceGr,
papEndGroup2010
};

/*	Group2020		*/

enum {
papImagePosition2020Gr = 1,
papPolarityGr,
papRequestedImageSizeGr,
papPreformattedGrayscaleImageSequenceGr,
papPreformattedColorImageSequenceGr,
papReferencedImageOverlayBoxSequenceGr,
papReferencedVOILUTBoxSequenceGr,
papEndGroup2020
};

/*	Group2030		*/

enum {
papAnnotationPositionGr = 1,
papTextStringGr,
papEndGroup2030
};

/*	Group2040		*/

enum {
papReferencedOverlayPlaneSequenceGr = 1,
papReferencedOverlayPlaneGroupsGr,
papOverlayMagnificationTypeGr,
papOverlaySmoothingTypeGr,
papOverlayForegroundDensityGr,
papOverlayModeGr,
papThresholdDensityGr,
papReferencedImageBoxSequence2040Gr,
papEndGroup2040
};

/*	Group2100		*/

enum {
papExecutionStatusGr = 1,
papExecutionStatusInfoGr,
papCreationDateGr,
papCreationTimeGr,
papOriginatorGr,
papReferencedPrintJobSequenceGr,
papEndGroup2100
};

/*	Group2110		*/

enum {
papPrinterStatusGr = 1,
papPrinterStatusInfoGr,
papPrinterNameGr,
papPrintQueueIDGr,
papEndGroup2110
};

/*	Group4000		*/

enum {
papArbitraryGr = 1,
papCommentsGr,
papEndGroup4000
};

/*	Group4008		*/

enum {
papResultsIDGr = 1,
papResultsIDIssuerGr,
papReferencedInterpretationSequenceGr,
papInterpretationRecordedDateGr,
papInterpretationRecordedTimeGr,
papInterpretationRecorderGr,
papReferencetoRecordedSoundGr,
papInterpretationTranscriptionDateGr,
papInterpretationTranscriptionTimeGr,
papInterpretationTranscriberGr,
papInterpretationTextGr,
papInterpretationAuthorGr,
papInterpretationApproverSequenceGr,
papInterpretationApprovalDateGr,
papInterpretationApprovalTimeGr,
papPhysicianApprovingInterpretationGr,
papInterpretationDiagnosisDescriptionGr,
papDiagnosisCodeSequenceGr,
papResultsDistributionListSequenceGr,
papDistributionNameGr,
papDistributionAddressGr,
papInterpretationIDGr,
papInterpretationIDIssuerGr,
papInterpretationTypeIDGr,
papInterpretationStatusIDGr,
papImpressionsGr,
papResultsCommentsGr,
papEndGroup4008
};

/*	Group5000		*/

enum {
papCurveDimensionsGr = 1,
papNumberofPointsGr,
papTypeofDataGr,
papCurveDescriptionGr,
papAxisUnitsGr,
papAxisLabelsGr,
papDataValueRepresentationGr,
papMinimumCoordinateValueGr,
papMaximumCoordinateValueGr,
papCurveRangeGr,
papCurveDataDescriptorGr,
papCoordinateStartValueGr,
papCoordinateStepValueGr,
papAudioTypeGr,
papAudioSampleFormatGr,
papNumberofChannelsGr,
papNumberofSamplesGr,
papSampleRateGr,
papTotalTimeGr,
papAudioSampleDataGr,
papAudioCommentsGr,
papCurveLabelGr,
papReferencedOverlaySequence5000Gr,
papReferencedOverlayGroupGr,
papCurveDataGr,
papEndGroup5000
};


#endif
