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
/*	File     : PapyEnumImagesModules3.h                                         */
/*	Function : contains the declarations of the modules needed for the          */
/*		       image objects .                                                  */
/*	Authors  : Christian Girard                                                 */
/*                                                                              */
/*	History  : 08.1994	version 3.0                                             */
/*             06.1995	version 3.1                                             */
/*             02.1996	version 3.3                                             */
/*             02.1999	version 3.6                                             */
/*             04.2001	version 3.7                                             */
/*             09.2001  version 3.7  on CVS                                     */
/*             10.2001  version 3.71 MAJ Dicom par CHG                          */
/*                                                                              */
/********************************************************************************/

#ifndef PapyEnumImagesModulesH 
#define PapyEnumImagesModulesH



/*	Module : Acquisition Context	        */

enum {
papAcquisitionContextSequenceAC,
papAcquisitionContextDescriptionAC,
papEndAcquisitionContext
};


/*	Module : Approval			*/

enum {
papApprovalStatus,
papReviewDate,
papReviewTime,
papReviewerName,
papEndApproval
};


/*	Module : Audio			        */

enum {
papAudioType,
papAudioSampleFormat,
papNumberofChannels,
papNumberofSamples,
papSampleRate,
papTotalTime,
papAudioSampleData,
papReferencedImageSequenceAudio,
papAudioComments,
papEndAudio
};


/*	Module : Basic Annotation Presentation	*/

enum {
papAnnotationPosition,
papTextString,
papEndBasicAnnotationPresentation
};


/*	Module : Basic Film Box Presentation	*/

enum {
papImageDisplayFormat,
papAnnotationDisplayFormatID,
papFilmOrientation,
papFilmSizeID,
papMagnificationTypeBFBP,
papSmoothingTypeBFBP,
papBorderDensity,
papEmptyImageDensity,
papMinDensity,
papMaxDensity,
papTrim,
papConfigurationInformation,
papEndBasicFilmBoxPresentation
};


/*	Module : Basic Film Box Relationship	*/

enum {
papReferencedFilmSessionSequence,
papReferencedImageBoxSequenceBFBR,
papReferencedBasicAnnotationBoxSequence,
papEndBasicFilmBoxRelationship
};


/*	Module : Basic Film Session Presentation */

enum {
papNumberofCopies,
papPrintPriorityBFSP,
papMediumType,
papFilmDestination,
papFilmSessionLabel,
papMemoryAllocation,
papMaximumMemoryAllocation,
papEndBasicFilmSessionPresentation
};


/*	Module : Basic Film Session Relationship */

enum {
papReferencedFilmBoxSequence,
papEndBasicFilmSessionRelationship
};


/*	Module : BiPlane Image			*/

enum {
papSmallestImagePixelValueinPlane,
papLargestImagePixelValueinPlane,
papEndBiPlaneImage
};


/*	Module : BiPlane Overlay		*/

enum {
papOverlayPlanes,
papOverlayPlaneOrigin,
papEndBiPlaneOverlay
};


/*	Module : BiPlane Sequence		*/

enum {
papPlanes,
papBiPlaneAcquisitionSequence,
papEndBiPlaneSequence
};


/*	Module : Cine				*/

enum {
papPreferredPlaybackSequencing,
papFrameTimeC,
papFrameTimeVector,
papStartTrim,
papStopTrim,
papRecommendedDisplayFrameRate,
papCineRate,
papFrameDelay,
papEffectiveDuration,
papActualFrameDurationC,
papEndCine
};


/*	Module : Contrast Bolus			*/

enum {
papContrastBolusAgent,
papContrastBolusAgentSequence,
papContrastBolusRoute,
papContrastBolusAdministrationRouteSequence,
papContrastBolusVolume,
papContrastBolusStartTime,
papContrastBolusStopTime,
papContrastBolusTotalDose,
papContrastFlowRates,
papContrastFlowDurations,
papContrastBolusIngredient,
papContrastBolusIngredientConcentration,
papEndContrastBolus
};


/*	Module : CR Image			*/

enum {
papKVPCRI,
papPlateID,
papDistanceSourcetoDetectorCRI,
papDistanceSourcetoPatientCRI,
papExposureTimeCRI,
papXrayTubeCurrentCRI,
papExposureCRI,
papImagerPixelSpacingCRI,
papGeneratorPowerCRI,
papAcquisitionDeviceProcessingDescription,
papAcquisitionDeviceProcessingCode,
papCassetteOrientation,
papCassetteSize,
papExposuresonPlate,
papRelativeXrayExposure,
papSensitivity,
papEndCRImage
};


/*	Module : CR Series			*/

enum {
papBodyPartExaminedCRS,
papViewPosition,
papFilterTypeCRS,
papCollimatorgridnameCRS,
papFocalSpotCRS,
papPlateType,
papPhosphorType,
papEndCRSeries
};


/*	Module : CT Image			*/

enum {
papImageTypeCTI,
papSamplesperPixelCTI,
papPhotometricInterpretationCTI,
papBitsAllocatedCTI,
papBitsStoredCTI,
papHighBitCTI,
papRescaleInterceptCTI,
papRescaleSlopeCTI,
papKVPCTI,
papAcquisitionNumberCTI,
papScanOptionsCTI,
papDataCollectionDiameter,
papReconstructionDiameterCTI,
papDistanceSourcetoDetectorCTI,
papDistanceSourcetoPatientCTI,
papGantryDetectorTiltCTI,
papTableHeightCTI,
papRotationDirectionCTI,
papExposureTimeCTI,
papXrayTubeCurrentCTI,
papExposureCTI,
papFilterTypeCTI,
papGeneratorPowerCTI,
papFocalSpotCTI,
papConvolutionKernelCTI,
papEndCTImage
};


/*	Module : Curve				*/

enum {
papCurveDimensions,
papNumberofPoints,
papTypeofData,
papDataValueRepresentation,
papCurveData,
papCurveDescription,
papAxisUnits,
papAxisLabels,
papMinimumCoordinateValue,
papMaximumCoordinateValue,
papCurveRange,
papCurveDataDescriptor,
papCoordinateStartValue,
papCoordinateStepValue,
papCurveLabel,
papReferencedOverlaySequence5000,
papEndCurve
};


/*	Module : Curve Identification		*/

enum {
papCurveNumber,
papCurveDate,
papCurveTime,
papReferencedImageSequenceCI,
papReferencedOverlaySequenceCI,
papReferencedCurveSequenceCI,
papEndCurveIdentification
};


/*	Module : Device				*/

enum {
papDeviceSequence,
papEndDevice
};


/*	Module : Directory Information	        */

enum {
papOffsetofTheFirstDirectoryRecord,
papOffsetofTheLastDirectoryRecord,
papFilesetConsistencyFlag,
papDirectoryRecordSequence,
papEndDirectoryInformation
};


/*	Module : Display Shutter		*/

enum {
papShutterShapeDS,
papShutterLeftVerticalEdgeDS,
papShutterRightVerticalEdgeDS,
papShutterUpperHorizontalEdgeDS,
papShutterLowerHorizontalEdgeDS,
papCenterofCircularShutterDS,
papRadiusofCircularShutterDS,
papVerticesofthePolygonalShutterDS,
papEndDisplayShutter
};


/*	Module : DX Anatomy Imaged	        */

enum {
papImageLateralityDXAI,
papAnatomicRegionSequenceDXAI,
papPrimaryAnatomicStructureSequenceDXAI,
papEndDXAnatomyImaged
};


/*	Module : DX Image			*/

enum {
papImageTypeDXI,
papSamplesperPixelDXI,
papPhotometricInterpretationDXI,
papBitsAllocatedDXI,
papBitsStoredDXI,
papHighBitDXI,
papPixelRepresentationDXI,
papPixelIntensityRelationshipDXI,
papPixelIntensityRelationshipSignDXI,
papRescaleInterceptDXI,
papRescaleSlopeDXI,
papRescaleTypeDXI,
papPresentationLUTShapeDXI,
papLossyImageCompressionDXI,
papLossyImageCompressionRatioDXI,
papDerivationDescriptionDXI,
papAcquisitionDeviceProcessingDescriptionDXI,
papAcquisitionDeviceProcessingCodeDXI,
papPatientOrientationDXI,
papCalibrationObjectDXI,
papBurnedInAnnotationDXI,
papEndDXImage
};


/*	Module : DX Detector			*/

enum {
papDetectorTypeDXD,
papDetectorConfigurationDXD,
papDetectorDescriptionDXD,
papDetectorModeDXD,
papDetectorIDDXD,
papDateofLastDetectorCalibrationDXD,
papTimeofLastDetectorCalibrationDXD,
papExposuresonDetectorSinceLastCalibrationDXD,
papExposuresonDetectorSinceManufacturedDXD,
papDetectorTimeSinceLastExposureDXD,
papDetectorActiveTimeDXD,
papDetectorActivationOffsetFromExposureDXD,
papDetectorBinningDXD,
papDetectorConditionsNominalFlagDXD,
papDetectorTemperatureDXD,
papSensitivityDXD,
papFieldofViewShapeDXD,
papFieldofViewDimensionsDXD,
papFieldofViewOriginDXD,
papFieldofViewRotationDXD,
papFieldofViewHorizontalFlipDXD,
papImagerPixelSpacingDXD,
papDetectorElementPhysicalSizeDXD,
papDetectorElementSpacingDXD,
papDetectorActiveShapeDXD,
papDetectorActiveDimensionsDXD,
papDetectorActiveOriginDXD,
papEndDXDetector
};


/*	Module : DX Positioning			*/

enum {
papProjectionEponymousNameCodeSequenceDXP,
papPatientPositionDXP,
papViewPositionDXP,
papViewCodeSequenceDXP,
papViewModifierCodeSequenceDXP,
papPatientOrientationCodeSequenceDXP,
papPatientOrientationModifierCodeSequenceDXP,
papPatientGantryRelationshipCodeSequenceDXP,
papDistanceSourcetoPatientDXP,
papDistanceSourcetoDetectorDXP,
papEstimatedRadiographicMagnificationFactorDXP,
papPositionerTypeDXP,
papPositionerPrimaryAngleDXP,
papPositionerSecondaryAngleDXP,
papDetectorPrimaryAngleDXP,
papDetectorSecondaryAngleDXP,
papColumnAngulationDXP,
papTableTypeDXP,
papTableAngleDXP,
papBodyPartThicknessDXP,
papCompressionForceDXP,
papEndDXPositioning
};


/*	Module : DX Series			*/

enum {
papModalityDX,
papReferencedStudyComponentSequence,
papPresentationIndentType,
papEndDXSeries
};


/*	Module : External Papyrus_File Reference Sequence */

enum {
papExternalPAPYRUSFileReferenceSequence,
papEndExternalPapyrus_FileReferenceSequence
};


/*	Module : External Patient File Reference Sequence */

enum {
papReferencedPatientSequenceEPFRS,
papEndExternalPatientFileReferenceSequence
};


/*	Module : External Study File Reference Sequence	*/

enum {
papReferencedStudySequenceESFRS,
papEndExternalStudyFileReferenceSequence
};


/*	Module : External Visit Reference Sequence	*/

enum {
papReferencedVisitSequenceEVRS,
papEndExternalVisitReferenceSequence
};


/*	Module : File Reference			*/

enum {
papReferencedSOPClassUID,
papReferencedSOPInstanceUID,
papReferencedFileName,
papReferencedFilePath,
papEndFileReference
};


/*	Module : File Set Identification	*/

enum {
papFilesetID,
papFileIDofFilesetDescriptorFile,
papFormatofFilesetDescriptorFile,
papEndFileSetIdentification
};


/*	Module : Frame Of Reference		*/

enum {
papFrameofReferenceUID,
papPositionReferenceIndicator,
papEndFrameOfReference
};


/*	Module : Frame Pointers			*/

enum {
papRepresentativeFrameNumber,
papFrameNumbersofInterest,
papFramesofInterestDescription,
papEndFramePointers
};


/*	Module : General Equipment		*/

enum {
papManufacturerGE,
papInstitutionNameGE,
papInstitutionAddressGE,
papStationName,
papInstitutionalDepartmentName,
papManufacturersModelName,
papDeviceSerialNumberGE,
papSoftwareVersionsGE,
papSpatialResolution,
papDateofLastCalibration,
papTimeofLastCalibration,
papPixelPaddingValue,
papEndGeneralEquipment
};


/*	Module : General Image			*/

enum {
papInstanceNumberGI,
papPatientOrientation,
papImageDate,
papImageTime,
papImageTypeGI,
papAcquisitionNumberGI,
papAcquisitionDate,
papAcquisitionTime,
papReferencedImageSequenceGI,
papDerivationDescription,
papSourceImageSequence,
papImagesinAcquisition,
papImageComments,
papLossyImageCompressionGI,
papEndGeneralImage
};


/*	Module : General Patient Summary	*/

enum {
papPatientsNameGPS,
papPatientsID,
papPatientsBirthDateGPS,
papPatientsSexGPS,
papPatientsHeight,
papPatientsWeightGPS,
papEndGeneralPatientSummary
};


/*	Module : General Series			*/

enum {
papModalityGS,
papSeriesInstanceUIDGS,
papSeriesNumberGS,
papLaterality,
papSeriesDate,
papSeriesTime,
papPerformingPhysiciansNameGS,
papProtocolName,
papSeriesDescription,
papOperatorsName,
papReferencedStudyComponentSequenceGS,
papBodyPartExaminedGS,
papPatientPosition,
papSmallestPixelValueinSeries,
papLargestPixelValueinSeries,
papEndGeneralSeries
};


/*	Module : General Series Summary		*/

enum {
papModalityGSS,
papSeriesInstanceUIDGSS,
papSeriesNumberGSS,
papNumberofimages,
papEndGeneralSeriesSummary
};


/*	Module : General Study			*/

enum {
papStudyInstanceUIDGS,
papStudyDateGS,
papStudyTimeGS,
papReferringPhysiciansNameGS,
papStudyIDGS,
papAccessionNumberGS,
papStudyDescriptionGS,
papPhysiciansOfRecordGS,
papNameofPhysiciansReadingStudyGS,
papReferencedStudySequenceGS,
papEndGeneralStudy
};


/*	Module : General Study Summary		*/

enum {
papStudyDateGSS,
papStudyTimeGSS,
papStudyUID,
papStudyIDGSS,
papAccessionnumberGSS,
papReferringPhysiciansNameGSS,
papEndGeneralStudySummary
};


/*	Module : General Visit Summary		*/

enum {
papCurrentPatientLocationGVS,
papPatientsInstitutionResidenceGVS,
papInstitutionNameVS,
papEndGeneralVisitSummary
};


/*	Module : Icon Image			*/

enum {
papSamplesperPixelII,
papPhotometricInterpretationII,
papRowsII,
papColumnsII,
papBitsAllocatedII,
papBitsStoredII,
papHighBitII,
papPixelRepresentationII,
papRedPaletteColorLookupTableDescriptors,
papBluePaletteColorLookupTableDescriptors,
papGreenPaletteColorLookupTableDescriptors,
papRedPaletteColorLookupTableDataII,
papBluePaletteColorLookupTableDataII,
papGreenPaletteColorLookupTableDataII,
papPixelDataII,
papEndIconImage
};


/*	Module : Identifying Image Sequence	*/

enum {
papImageIdentifierSequence,
papEndIdentifyingImageSequence
};


/*	Module : Image Box Pixel Presentation	*/

enum {
papImagePosition,
papPolarity,
papMagnificationTypeIBPP,
papSmoothingTypeIBPP,
papRequestedImageSize,
papPreformattedGrayscaleImageSequence,
papPreformattedColorImageSequence,
papReferencedImageOverlayBoxSequenceIBP,
papReferencedSOPClassUID8,
papReferencedSOPInstanceUID8,
papEndImageBoxPixelPresentation
};


/*	Module : Image Box Relationship		*/

enum {
papReferencedImageSequenceBR,
papReferencedImageOverlayBoxSequence,
papReferencedVOILUTSequence,
papEndImageBoxRelationship
};


/*	Module : Image Histogram		*/

enum {
papHistogramSequenceIH,
papEndImageHistogram
};


/*	Module : Image Identification		*/

enum {
papReferencedImageSOPClassUIDII,
papReferencedImageSOPInstanceUID,
papImageNumberII,
papEndImageIdentification
};


/*	Module : Image Overlay Box Presentation	*/

enum {
papReferencedOverlayPlaneSequence,
papOverlayMagnificationType,
papOverlaySmoothingType,
papOverlayForegroundDensity,
papOverlayMode,
papThresholdDensity,
papEndImageOverlayBoxPresentation
};


/*	Module : Image Overlay Box Relationship	*/

enum {
papReferencedImageBoxSequenceOBR,
papEndImageOverlayBoxRelationship
};


/*	Module : Image Pixel			*/

enum {
papSamplesperPixelIP,
papPhotometricInterpretationIP,
papRows,
papColumns,
papBitsAllocatedIP,
papBitsStoredIP,
papHighBitIP,
papPixelRepresentationIP,
papPixelData,
papPlanarConfiguration,
papPixelAspectRatio,
papSmallestImagePixelValue,
papLargestImagePixelValue,
papRedPaletteColorLookupTableDescriptor,
papGreenPaletteColorLookupTableDescriptor,
papBluePaletteColorLookupTableDescriptor,
papRedPaletteColorLookupTableData,
papGreenPaletteColorLookupTableData,
papBluePaletteColorLookupTableData,
papEndImagePixel
};


/*	Module : Image Plane			*/

enum {
papPixelSpacing,
papImageOrientationPatient,
papImagePositionPatient,
papSliceThickness,
papSliceLocation,
papEndImagePlane
};


/*	Module : Image Pointer			*/

enum {
papImagePointer,
papEndImagePointer
};


/*	Module : Image Sequence			*/

enum {
papImageSequence,
papEndImageSequence
};


/*	Module : Internal Image Pointer Sequence */

enum {
papPointerSequence,
papEndInternalImagePointerSequence
};


/*	Module : Interpretation Approval	*/

enum {
papInterpretationApproverSequence,
papInterpretationDiagnosisDescription,
papInterpretationDiagnosisCodesSequence,
papResultsDistributionListSequence,
papEndInterpretationApproval
};


/*	Module : Interpretation Identification	*/

enum {
papInterpretationID,
papInterpretationIDIssuer,
papEndInterpretationIdentification
};


/*	Module : Interpretation Recording	*/

enum {
papInterpretationRecordedDate,
papInterpretationRecordedTime,
papInterpretationRecorder,
papReferencetoRecordedSound,
papEndInterpretationRecording
};


/*	Module : Interpretation Relationship	*/

enum {
papReferencedResultsSequenceIR,
papEndInterpretationRelationship
};


/*	Module : Interpretation State		*/

enum {
papInterpretationTypeID,
papInterpretationStatusID,
papEndInterpretationState
};


/*	Module : Interpretation Transcription	*/

enum {
papInterpretationTranscriptionDate,
papInterpretationTranscriptionTime,
papInterpretationTranscriber,
papInterpretationText,
papInterpretationAuthor,
papEndInterpretationTranscription
};


/*	Module : Intra Oral Image		*/

enum {
papPositionerTypeIOI,
papImageLateralityIOI,
papAnatomicRegionSequenceIOI,
papAnatomicRegionModifierSequenceIOI,
papPrimaryAnatomicStructureSequenceIOI,
papEndIntraOralImage
};


/*	Module : Intra Oral Series		*/

enum {
papModalityIOS,
papEndIntraOralSeries
};


/*	Module : LUT Identification		*/

enum {
papLUTNumber,
papReferencedImageSequenceLI,
papEndLUTIdentification
};


/*	Module : Mammography Image		*/

enum {
papPositionerTypeMI,
papPositionerPrimaryAngleMI,
papPositionerSecondaryAngleMI,
papImageLateralityMI,
papOrganExposedMI,
papAnatomicRegionSequenceMI,
papViewCodeSequenceMI,
papViewModifierCodeSequenceMI,
papEndMammographyImage
};


/*	Module : Mammography Series		*/

enum {
papModalityMS,
papEndMammographySeries
};


/*	Module : Mask				*/

enum {
papMaskSubtractionSequence,
papRecommendedViewingMode,
papEndMask
};


/*	Module : Modality LUT		        */

enum {
papModalityLUTSequence,
papRescaleInterceptML,
papRescaleSlopeML,
papRescaleType,
papEndModalityLUT
};


/*	Module : MR Image			*/

enum {
papImageTypeMRI,
papSamplesperPixelMRI,
papPhotometricInterpretationMRI,
papBitsAllocatedMRI,
papScanningSequence,
papSequenceVariant,
papScanOptionsMRI,
papMRAcquisitionTypeMRI,
papRepetitionTime,
papEchoTime,
papEchoTrainLength,
papInversionTime,
papTriggerTimeMRI,
papSequenceName,
papAngioFlag,
papNumberofAverages,
papImagingFrequency,
papImagedNucleus,
papEchoNumber,
papMagneticFieldStrength,
papSpacingBetweenSlices,
papNumberofPhaseEncodingSteps,
papPercentSampling,
papPercentPhaseFieldofView,
papPixelBandwidth,
papNominalIntervalMRI,
papBeatRejectionFlagMRI,
papLowRRValueMRI,
papHighRRValueMRI,
papIntervalsAcquiredMRI,
papIntervalsRejectedMRI,
papPVCRejectionMRI,
papSkipBeatsMRI,
papHeartRateMRI,
papCardiacNumberofImagesMRI,
papTriggerWindow,
papReconstructionDiameterMRI,
papReceivingCoil,
papTransmittingCoil,
papAcquisitionMatrix,
papPhaseEncodingDirection,
papFlipAngle,
papSAR,
papVariableFlipAngleFlag,
papdBdt,
papTemporalPositionIdentifier,
papNumberofTemporalPositions,
papTemporalResolution,
papEndMRImage
};


/*	Module : Multi_Frame			*/

enum {
papNumberofFrames,
papFrameIncrementPointerMF,
papEndMulti_Frame
};


/*	Module : Multi_frame Overlay		*/

enum {
papNumberofFramesinOverlay,
papImageFrameOrigin,
papEndMulti_frameOverlay
};


/*	Module : NM Detector			*/

enum {
papDetectorInformationSequence,
papEndNMDetector
};


/*	Module : NM Image			*/

enum {
papImageType,
papImageID,
papLossyImageCompressionNMI,
papCountsAccumulated,
papAcquisitionTerminationCondition,
papTableHeightNMI,
papTableTraverseNMI,
papActualFrameDurationNMI,
papCountRate,
papPreprocessingFunctionNMI,
papCorrectedImage,
papWholeBodyTechnique,
papScanVelocity,
papScanLength,
papReferencedOverlaySequenceNMI,
papReferencedCurveSequenceNMI,
papTriggerSourceorType,
papAnatomicRegionSequence,
papPrimaryAnatomicStructureSequence,
papEndNMImage
};


/*	Module : NM Image Pixel			*/

enum {
papSamplesperPixel,
papPhotometricInterpretation,
papBitsAllocated,
papBitsStored,
papHighBit,
papPixelSpacingNM,
papEndNMImagePixel
};


/*	Module : NM Isotope	  	        */

enum {
papEnergyWindowInformationSequence,
papRadiopharmaceuticalInformationSequence,
papInterventionDrugInformationSequence,
papEndNMIsotope
};
  

/*	Module : NM Multi Frame			*/

enum {
papFrameIncrementPointer,
papEnergyWindowVector,
papNumberofEnergyWindows,
papDetectorVector,
papNumberofDetectors,
papPhaseVector,
papNumberofPhases,
papRotationVector,
papNumberofRotations,
papRRIntervalVector,
papNumberofRRIntervals,
papTimeSlotVector,
papNumberofTimeSlots,
papSliceVector,
papNumberofSlices,
papAngularViewVector,
papTimeSliceVector,
papEndNMMultiFrame
};


/*	Module : NM Multi_gated Acquisition Image */

enum {
papBeatRejectionFlagNMAI,
papPVCRejectionNMAI,
papSkipBeatsNMAI,
papHeartRateNMAI,
papGatedInformationSequenceNMAI,
papEndNMMulti_gatedAcquisitionImage
};


/*	Module : NM Phase	                */

enum {
papPhaseInformationSequence,
papEndNMPhase
};


/*	Module : NM Reconstruction	        */

enum {
papSpacingBetweenSlicesNM,
papReconstructionDiameter,
papConvolutionKernel,
papSliceThicknessNM,
papSliceLocationNM,
papEndNMReconstruction
};


/*	Module : NM Series			*/

enum {
papPatientOrientationCodeSequence,
papPatientGantryRelationshipCodeSequence,
papEndNMSeries
};


/*	Module : NM Tomo Acquisition		*/

enum {
papRotationInformationSequence,
papTypeofDetectorMotion,
papEndNMTomoAcquisition
};


/*	Module : Overlay Identification		*/

enum {
papOverlayNumber,
papOverlayDate,
papOverlayTime,
papReferencedImageSequenceOI,
papEndOverlayIdentification
};


/*	Module : Overlay Plane			*/

enum {
papRowsOP,
papColumnsOP,
papOverlayType,
papOrigin,
papBitsAllocatedOP,
papBitPosition,
papOverlayData,
papOverlayDescription,
papOverlaySubtypeOP,
papOverlayLabel,
papROIArea,
papROIMean,
papROIStandardDeviation,
papOverlayDescriptorGray,
papOverlayDescriptorRed,
papOverlayDescriptorGreen,
papOverlayDescriptorBlue,
papOverlaysGray,
papOverlaysRed,
papOverlaysGreen,
papOverlaysBlue,
papEndOverlayPlane
};


/*	Module : Palette Color Lookup	         */

enum {
papRedPaletteColorLookupTableDescriptorPCL,
papGreenPaletteColorLookupTableDescriptorPCL,
papBluePaletteColorLookupTableDescriptorPCL,
papPaletteColorLookupTableUID,
papRedPaletteCLUTData,
papGreenPaletteCLUTData,
papBluePaletteCLUTData,
papSegmentedRedPaletteColorLookupTableData,
papSegmentedGreenPaletteColorLookupTableData,
papSegmentedBluePaletteColorLookupTableData,
papEndPaletteColorLookup
};


/*	Module : Patient			*/

enum {
papPatientsNameP,
papPatientIDP,
papPatientsBirthDateP,
papPatientsSexP,
papReferencedPatientSequenceP,
papPatientsBirthTimeP,
papOtherPatientID,
papOtherPatientNamesP,
papEthnicGroupP,
papPatientCommentsP,
papEndPatient
};


/*	Module : Patient Demographic		*/

enum {
papPatientsAddress,
papRegionofResidence,
papCountryofResidence,
papPatientsTelephoneNumbers,
papPatientsBirthDatePD,
papPatientsBirthTimePD,
papEthnicGroupPD,
papPatientsSexPD,
papPatientsSizePD,
papPatientsWeightPD,
papMilitaryRank,
papBranchofService,
papPatientsInsurancePlanCodeSequence,
papPatientsReligiousPreference,
papPatientCommentsPD,
papEndPatientDemographic
};


/*	Module : Patient Identification		*/

enum {
papPatientsNamePI,
papPatientIDPI,
papIssuerofPatientID,
papOtherPatientIDs,
papOtherPatientNamesPI,
papPatientsBirthName,
papPatientsMothersBirthName,
papMedicalRecordLocator,
papEndPatientIdentification
};


/*	Module : Patient Medical		*/

enum {
papPatientState,
papPregnancyStatus,
papMedicalAlerts,
papContrastAllergies,
papSpecialNeeds,
papLastMenstrualDate,
papSmokingStatus,
papAdditionalPatientHistory,
papEndPatientMedical
};


/*	Module : Patient Relationship		*/

enum {
papReferencedVisitSequencePR,
papReferencedStudySequencePR,
papReferencedPatientAliasSequence,
papEndPatientRelationship
};


/*	Module : Patient Study			*/

enum {
papAdmittingDiagnosesDescription,
papPatientsAge,
papPatientsSizePS,
papPatientsWeightPS,
papOccupation,
papAdditionalPatientsHistory,
papEndPatientStudy
};


/*	Module : Patient Summary		*/

enum {
papPatientsNamePS,
papPatientIDPS,
papEndPatientSummary
};


/*	Module : PET Curve		*/

enum {
papCurveDimensionsPC,
papTypeofDataPC,
papCurveDataPC,
papAxisUnitsPC,
papDeadTimeCorrectionFlag,
papCountsIncluded,
papPreprocessingFunction,
papEndPETCurve
};


/*	Module : PET Image		*/

enum {
papImageTypePI,
papSamplesPerPixelPI,
papPhotometricInterpretationPI,
papBitsAllocatedPI,
papBitsStoredPI,
papHighBitPI,
papRescaleInterceptPI,
papRescaleSlopePI,
papFrameReferenceTime,
papTriggerTime,
papFrameTime,
papLowRRValue,
papHighRRValue,
papLossyImageCompression,
papImageIndex,
papAcquisitionDatePI,
papAcquisitionTimePI,
papActualFrameDuration,
papNominalInterval,
papIntervalsAcquired,
papIntervalsRejected,
papPrimaryCountsAccumulated,
papSecondaryCountsAccumulated,
papSliceSensitivityFactor,
papDecayFactor,
papDoseCalibrationFactor,
papScatterFractionFactor,
papDeadTimeFactor,
papReferencedOverlaySequence,
papReferencedCurveSequence,
papAnatomicRegionSequencePI,
papPrimaryAnatomicStructureSequencePI,
papEndPETImage
};


/*	Module : PET Isotope		*/

enum {
papRadiopharmaceuticalInformationSequencePI,
papInterventionDrugInformationSequencePI,
papEndPETIsotope
};


/*	Module : PET Multi-gated Acquisition	*/

enum {
papBeatRejectionFlag,
papTriggerSourceOrType,
papPVCRejection,
papSkipBeats,
papHeartRate,
papFramingType,
papEndPETMultiGatedAcquisition
};


/*	Module : PET Series			*/

enum {
papSeriesDatePET,
papSeriesTimePET,
papUnits,
papCountsSource,
papSeriesType,
papReprojectionMethod,
papNumberofRRIntervalsPET,
papNumberofTimeSlotsPET,
papNumberofSlicesPET,
papNumberofRotationsPET,
papRandomsCorrectionMethod,
papAttenuationCorrectionMethod,
papScatterCorrectionMethod,
papDecayCorrection,
papReconstructionDiameterPET,
papConvolutionKernelPET,
papReconstructionMethod,
papDetectorLinesOfResponseUsed,
papAcquisitionStartCondition,
papAcquisitionStartConditionData,
papAcquisitionTerminationConditionPET,
papAcquisitionTerminationConditionData,
papFieldofViewShape,
papFieldofViewDimensions,
papGantryDetectorTilt,
papGantryDetectorSlew,
papTypeofDetectorMotionPET,
papCollimatorType,
papCollimatorgridName,
papAxialAcceptance,
papAxialMash,
papTransverseMash,
papDetectorElementSize,
papCoincidenceWindowWidth,
papEnergyWindowRangeSequence,
papEnergyWindowLowerLimit,
papEnergyWindowUpperLimit,
papSecondaryCountsType,
papEndPETSeries
};


/*	Module : Pixel Offset			*/

enum {
papPixelOffset,
papEndPixelOffset
};


/*	Module : Printer			*/

enum {
papPrinterStatus,
papPrinterStatusInfo,
papPrinterNameP,
papManufacturerP,
papManufacturerModelName,
papDeviceSerialNumberP,
papSoftwareVersionsP,
papDateOfLastCalibration,
papTimeOfLastCalibration,
papEndPrinter
};


/*	Module : Print Job			*/

enum {
papExecutionStatus,
papExecutionStatusInfo,
papCreationDate,
papCreationTime,
papPrintPriorityPJ,
papPrinterNamePJ,
papOriginator,
papEndPrintJob
};


/*	Module : Result Identification		*/

enum {
papResultsID,
papResultsIDIssuer,
papEndResultIdentification
};


/*	Module : Results Impression		*/

enum {
papImpressions,
papResultsComments,
papEndResultsImpression
};


/*	Module : Result Relationship		*/

enum {
papReferencedStudySequenceRR,
papReferencedInterpretationSequence,
papEndResultRelationship
};


/*	Module : RF Tomography Acquisition	*/

enum {
papTornoLayerHeight,
papTornoAngle,
papTornoTime,
papEndRFTomographyAcquisition
};


/*	Module : ROI Contour			*/

enum {
papROIContourSequence,
papContourNumber,
papAttachedContours,
papEndROIContour
};


/*	Module : RT Beams			*/

enum {
papBeamSequence,
papHighDoseTechniqueType,
papCompensatorNumber,
papCompensatorType,
papEndRTBeams
};


/*	Module : RT Brachy Application Setups   */

enum {
papBrachyTreatmentTechnique,
papBrachyTreatmentType,
papTreatmentMachineSequence,
papSourceSequence,
papApplicationSetupSequence,
papEndRTBrachyApplicationSetups
};


/*	Module : RT Dose			*/

enum {
papSamplesperPixelRTD,
papPhotometricInterpretationRTD,
papBitsAllocatedRTD,
papBitsStoredRTD,
papHighBitRTD,
papPixelRepresentationRTD,
papDoseUnitsRTD,
papDoseTypeRTD,
papInstanceNumber,
papDoseCommentRTD,
papNormalizationPointRTD,
papDoseSummationTypeRTD,
papReferencedRTPlanSequenceRTD,
papGridFrameOffsetVectorRTD,
papDoseGridScalingRTD,
papEndRTDose
};


/*	Module : RT Dose ROI		        */

enum {
papRTDoseROISequence,
papEndRTDoseROI
};


/*	Module : RT DVH			        */

enum {
papReferencedStructureSetSequence,
papDVHNormalizationPoint,
papDVHNormalizationDoseValue,
papDVHSequence,
papEndRTDVH
};


/*	Module : RT Fraction Scheme		*/

enum {
papFractionGroupSequence,
papEndRTFractionScheme
};


/*	Module : RT General Plan		*/

enum {
papRTPlanLabel,
papRTPlanName,
papRTPlanDescription,
papRTPlanInstanceNumber,
papOperatorsNameRTGP,
papRTPlanDate,
papRTPlanTime,
papTreatmentProtocols,
papTreatmentIntent,
papTreatmentSites,
papRTPlanGeometry,
papReferencedStructureSetSequenceRTGP,
papReferencedDoseSequence,
papReferencedRTPlanSequence,
papEndRTGeneralPlan
};


/*	Module : RT Image			*/

enum {
papSamplesperPixelRTI,
papPhotometricInterpretationRTI,
papBitsAllocatedRTI,
papBitsStoredRTI,
papHighBitRTI,
papPixelRepresentationRTI,
papRTImageLabelRTI,
papRTImageNameRTI,
papRTImageDescriptionRTI,
papOperatorsNameRTI,
papImageTypeRTI,
papConversionTypeRTI,
papReportedValuesOriginRTI,
papRTImagePlaneRTI,
papXRayImageReceptortranslation,
papXRayImageReceptorAngleRTI,
papRTImageOrientationRTI,
papImagePlanePixelSpacingRTI,
papRTImagePositionRTI,
papRadiationMachineNameRTI,
papPrimaryDosimeterUnitRTI,
papRadiationMachineSADRTI,
papRadiationMachineSSDRTI,
papRTImageSIDRTI,
papSourcetoReferenceObjectDistanceRTI,
papReferencedRTPlanSequenceRTI,
papReferencedBeamNumberRTI,
papReferencedFractionGroupNumberRTI,
papFractionNumberRTI,
papStartCumulativeMetersetWeightRTI,
papEndCumulativeMetersetWeightRTI,
papExposureSequenceRTI,
papGantryAngleRTI,
papDiaphragmPosition,
papBeamLimitingDeviceAngleRTI,
papPatientSupportAngleRTI,
papTableTopEccentricAxisDistanceRTI,
papTableTopEccentricAngleRTI,
papTableTopVerticalPositionRTI,
papTableTopLongitudinalPositionRTI,
papTableTopLateralPositionRTI,
papEndRTImage
};


/*	Module : RT Patient Setup               */

enum {
papPatientSetupSequence,
papEndRTPatientSetup
};


/*	Module : RT Prescription		*/

enum {
papPrescriptionDescription,
papDoseReferenceSequence,
papEndRTPrescription
};


/*	Module : RT ROI Observations		*/

enum {
papRTROIObservationsSequence,
papEndRTROIObservations
};


/*	Module : RT Series			*/

enum {
papModalityRTS,
papSeriesInstanceUIDRTS,
papSeriesNumberRTS,
papSeriesDescriptionRTS,
papReferencedStudyComponentSequenceRTS,
papEndRTSeries
};


/*	Module : RT Tolerance Tables		*/

enum {
papToleranceTableSequence,
papEndRTToleranceTables
};


/*	Module : Structure Set			*/

enum {
papStructureSetLabel,
papStructureSetName,
papStructureSetDescription,
papStructureSetDate,
papStructureSetTime,
papReferencedFrameofReferenceSequence,
papStructureSetROISequence,
papEndStructureSet
};



/*	Module : SC Image				*/

enum {
papDateofSecondaryCapture,
papTimeofSecondaryCapture,
papEndSCImage
};


/*	Module : SC Image Equipment			*/

enum {
papConversionType,
papModalitySIE,
papSecondaryCaptureDeviceID,
papSecondaryCaptureDeviceManufacturer,
papSecondaryCaptureDeviceManufacturersModelName,
papSecondaryCaptureDeviceSoftwareVersion,
papVideoImageFormatAcquired,
papDigitalImageFormatAcquired,
papEndSCImageEquipment
};


/*	Module : SC Multi-Frame Image				*/

enum {
papZoomFactor,
papPresentationLUTShape,
papIllumination,
papReflectedAmbientLight,
papRescaleIntercept,
papRescaleSlope,
papRescaleTypeSCMF,
papFrameIncrementPointerSCMF,
papNominalScannedPixelSpacing,
papDigitizingDeviceTransportDirection,
papRotationOfScannedFilm,
papEndSCMultiFrameImage
};


/*	Module : SC Multi-Frame Vector				*/

enum {
papFrameTimeVectorSCMFV,
papPageNumberVector,
papFrameLabelVector,
papFramePrimaryAngleVector,
papFrameSecondaryAngleVector,
papSliceLocationVector,
papDisplayWindowLabelVector,
papEndSCMultiFrameVector
};


/*	Module : Slide Coordinates				*/

enum {
papImageCenterPointCoordinatesSequence,
papXOffsetInSlideCoordinateSystem,
papYOffsetInSlideCoordinateSystem,
papZOffsetInSlideCoordinateSystem,
papPixelSpacingSequence,
papEndSlideCoordinates
};


/*	Module : SOP Common				*/

enum {
papSOPClassUID,
papSOPInstanceUID,
papSpecificCharacterSet,
papInstanceCreationDate,
papInstanceCreationTime,
papInstanceCreatorUID,
papTimezoneOffsetFromUTC,
papEndSOPCommon
};


/*	Module : Specimen Identification				*/

enum {
papSpecimenAccessionNumber,
papSpecimenSequence,
papEndSpecimenIdentification
};


/*	Module : Study Acquisition			*/

enum {
papStudyArrivalDate,
papStudyArrivalTime,
papStudyDateSA,
papStudyTimeSA,
papModalitiesInStudy,
papStudyCompletionDate,
papStudyCompletionTime,
papStudyVerifiedDate,
papStudyVerifiedTime,
papSeriesinStudy,
papAcquisitionsinStudy,
papEndStudyAcquisition
};


/*	Module : Study Classification			*/

enum {
papStudyStatusID,
papStudyPriorityID,
papStudyComments,
papEndStudyClassification
};


/*	Module : Study Component			*/

enum {
papStudyIDSC,
papStudyInstanceUIDSC,
papReferencedSeriesSequenceSC,
papEndStudyComponent
};


/*	Module : Study Component Acquisition		*/

enum {
papModalitySCA,
papStudyDescriptionSCA,
papProcedureCodeSequence,
papPerformingPhysiciansNameSCA,
papStudyComponentStatusID,
papEndStudyComponentAcquisition
};


/*	Module : Study Component Relationship		*/

enum {
papReferencedStudySequenceSCR,
papEndStudyComponentRelationship
};


/*	Module : Study Content				*/

enum {
papStudyIDSCt,
papStudyInstanceUIDSCt,
papReferencedSeriesSequenceSCt,
papEndStudyContent
};


/*	Module : Study Identification			*/

enum {
papStudyIDSI,
papStudyIDIssuer,
papOtherStudyNumbers,
papEndStudyIdentification
};


/*	Module : Study Read				*/

enum {
papNameofPhysiciansReadingStudySR,
papStudyReadDate,
papStudyReadTime,
papEndStudyRead
};


/*	Module : Study Relationship			*/

enum {
papReferencedVisitSequenceSR,
papReferencedPatientSequenceSR,
papReferencedResultsSequenceSR,
papReferencedStudyComponentSequenceSR,
papStudyInstanceUIDSR,
papAccessionNumberSR,
papEndStudyRelationship
};


/*	Module : Study Scheduling			*/

enum {
papScheduledStudyStartDate,
papScheduledStudyStartTime,
papScheduledStudyStopDate,
papScheduledStudyStopTime,
papScheduledStudyLocation,
papScheduledStudyLocationAETitle,
papReasonforStudy,
papRequestingPhysician,
papRequestingService,
papRequestedProcedureDescription,
papRequestedProcedureCodeSequence,
papRequestedContrastAgent,
papEndStudyScheduling
};


/*	Module : Therapy			        */

enum {
papInterventionalTherapySequenceTH,
papEndTherapy
};


/*	Module : UIN Overlay Sequence			*/

enum {
papOwnerID,
papUINOverlaySequence,
papEndUINOverlaySequence
};


/*	Module : US Frame of Reference			*/

enum {
papRegionLocationMinx0,
papRegionLocationMiny0,
papRegionLocationMaxx1,
papRegionLocationMaxy1,
papPhysicalUnitsXDirection,
papPhysicalUnitsYDirection,
papPhysicalDeltaX,
papPhysicalDeltaY,
papReferencePixelx0,
papReferencePixely0,
papRefPixelPhysicalValueX,
papRefPixelPhysicalValueY,
papEndUSFrameofReference
};


/*	Module : US Image				*/

enum {
papSamplesperPixelUSI,
papPhotometricInterpretationUSI,
papBitsAllocatedUSI,
papBitsStoredUSI,
papHighBitUSI,
papPlanarConfigurationUSI,
papPixelRepresentationUSI,
papFrameIncrementPointerUSI,
papImageTypeUSI,
papLossyImageCompressionUSI,
papNumberofStages,
papNumberofViewsinStage,
papUltrasoundColorDataPresent,
papReferencedOverlaySequenceUSI,
papReferencedCurveSequenceUSI,
papStageName,
papStageCodeSequence,
papStageNumber,
papViewName,
papViewNumber,
papNumberofEventTimers,
papEventElapsedTimes,
papEventTimerNames,
papAnatomicRegionSequenceUSI,
papPrimaryAnatomicStructureSequenceUSI,
papTransducerPositionSequence,
papTransducerOrientationSequence,
papTriggerTimeUSI,
papNominalIntervalUSI,
papBeatRejectionFlagUSI,
papLowRRValueUSI,
papHighRRValueUSI,
papHeartRateUSI,
papOutputPower,
papTransducerData,
papTransducerType,
papFocusDepth,
papPreprocessingFunctionUSI,
papMechanicalIndex,
papBoneThermalIndex,
papCranialThermalIndex,
papSoftTissueThermalIndex,
papSoftTissuefocusThermalIndex,
papSoftTissuesurfaceThermalIndex,
papDepthofScanField,
papImageTransformationMatrix,
papImageTranslationVector,
papOverlaySubtype,
papEndUSImage
};


/*	Module : US Region Calibration			*/

enum {
papSequenceofUltrasoundRegions,
papEndUSRegionCalibration
};


/*	Module : Visit Admission			*/

enum {
papAdmittingDate,
papAdmittingTime,
papRouteofAdmissions,
papAdmittingDiagnosisDescription,
papAdmittingDiagnosisCodeSequence,
papReferringPhysiciansNameVA,
papAddress,
papReferringPhysiciansPhoneNumbers,
papEndVisitAdmission
};


/*	Module : Visit Discharge			*/

enum {
papDischargeDate,
papDischargeTime,
papDescription,
papDischargeDiagnosisCodeSequence,
papEndVisitDischarge
};


/*	Module : Visit Identification			*/

enum {
papInstitutionNameVI,
papInstitutionAddressVI,
papInstitutionCodeSequence,
papAdmissionID,
papIssuerofAdmissionID,
papEndVisitIdentification
};


/*	Module : Visit Relationship			*/

enum {
papReferencedStudySequenceVR,
papReferencedPatientSequenceVR,
papEndVisitRelationship
};


/*	Module : Visit Scheduling			*/

enum {
papScheduledAdmissionDate,
papScheduledAdmissionTime,
papScheduledDischargeDate,
papScheduledDischargeTime,
papScheduledPatientInstitutionResidence,
papEndVisitScheduling
};


/*	Module : Visit Status				*/

enum {
papVisitStatusID,
papCurrentPatientLocationVS,
papPatientsInstitutionResidenceVS,
papVisitComments,
papEndVisitStatus
};

/*	Module : VL Image				*/

enum {
papImageTypeVL,
papPhotometricInterpretationVL,
papBitsAllocatedVL,
papBitsStoredVL,
papHighBitVL,
papPixelRepresentationVL,
papSamplesperPixelVL,
papPlanarConfigurationVL,
papImageTimeVL,
papLossyImageCompressionVL,
papReferencedImageSequenceVL,
papEndVLImage
};


/*	Module : VOI LUT				*/

enum {
papVOILUTSequence,
papWindowCenter,
papWindowWidth,
papWindowCenterWidthExplanation,
papEndVOILUT
};


/*	Module : XRay Acquisition			*/

enum {
papKVP,
papRadiationSetting,
papXrayTubeCurrent,
papExposureTime,
papExposure,
papGrid,
papAveragePulseWidth,
papRadiationMode,
papTypeofFilters,
papIntensifierSize,
papFieldofViewShapeXRA,
papFieldofViewDimensionsXRA,
papImagerPixelSpacing,
papFocalSpots,
papImageAreaDoseProduct,
papEndXRayAcquisition
};


/*	Module : XRay Acquisition Dose			*/

enum {
papKVPXRAD,
papXrayTubeCurrentXRAD,
papExposureTimeXRAD,
papExposureXRAD,
papDistanceSourcetoDetectorXRAD,
papDistanceSourcetoPatientXRAD,
papImageAreaDoseProductXRAD,
papBodyPartThicknessXRAD,
papEntranceDoseXRAD,
papExposedAreaXRAD,
papDistanceSourcetoEntranceXRAD,
papCommentsonRadiationDoseXRAD,
papXRayOutputXRAD,
papHalfValueLayerXRAD,
papOrganDoseXRAD,
papOrganExposedXRAD,
papAnodeTargetMaterialXRAD,
papFilterMaterialXRAD,
papFilterThicknessMinimumXRAD,
papFilterThicknessMaximumXRAD,
papRectificationTypeXRAD,
papEndXRayAcquisitionDose
};


/*	Module : XRay Collimator			*/

enum {
papCollimatorShape,
papCollimatorLeftVerticalEdge,
papCollimatorRightVerticalEdge,
papCollimatorUpperHorizontalEdge,
papCollimatorLowerHorizontalEdge,
papCenterofCircularCollimator,
papRadiusofCircularCollimator,
papVerticesofthePolygonalCollimator,
papEndXRayCollimator
};


/*	Module : XRay Filtration				*/

enum {
papFilterTypeXRF,
papFilterMaterialXRF,
papFilterThicknessMinimumXRF,
papFilterThicknessMaximumXRF,
papEndXRayFiltration
};


/*	Module : XRay Generation				*/

enum {
papKVPXRG,
papXrayTubeCurrentXRG,
papExposureTimeXRG,
papExposureXRG,
papExposureinmAsXRG,
papExposureControlModeXRG,
papExposureControlModeDescriptionXRG,
papExposureStatusXRG,
papPhototimerSettingXRG,
papFocalSpotsXRG,
papAnodeTargetMaterialXRG,
papRectificationTypeXRG,
papEndXRayGeneration
};


/*	Module : XRay Grid				*/

enum {
papGridXRG,
papGridAbsorbingMaterialXRG,
papGridSpacingMaterialXRG,
papGridThicknessXRG,
papGridPitchXRG,
papGridAspectRatioXRG,
papGridPeriodXRG,
papGridFocalDistanceXRG,
papEndXRayGrid
};


/*	Module : XRay Image				*/

enum {
papFrameIncrementPointerXR,
papLossyImageCompressionXR,
papImageTypeXR,
papPixelIntensityRelationshipXR,
papSamplesperPixelXR,
papPhotometricInterpretationXR,
papBitsAllocatedXR,
papBitsStoredXR,
papHighBitXR,
papPixelRepresentationXR,
papScanOptionsXR,
papAnatomicRegionSequenceXR,
papPrimaryAnatomicStructureSequenceXR,
papRWavePointerXR,
papReferencedImageSequenceXR,
papDerivationDescriptionXR,
papAcquisitionDeviceProcessingDescriptionXR,
papCalibrationObjectXR,
papEndXRayImage
};


/*	Module : XRay Table			*/

enum {
papTableMotion,
papTableVerticalIncrement,
papTableLongitudinalIncrement,
papTableLateralIncrement,
papTableAngle,
papEndXRayTable
};


/*	Module : XRay Tomography Acquisition	*/

enum {
papTornoTypeXRTA,
papTornoClassXRTA,
papTornoLayerHeightXRTA,
papTornoAngleXRTA,
papTornoTimeXRTA,
papNumberofTornosynthesisSourceImagesXRTA,
papEndXRayTomographyAcquisition
};


/*	Module : XRF Positioner	*/

enum {
papDistanceSourceToDetector,
papDistanceSourcetoPatient,
papEstimatedRadiographicMagnificationFactor,
papColumnAngulation,
papEndXRFPositioner
};





#endif	    /* PapyEnumImagesModulesH */
