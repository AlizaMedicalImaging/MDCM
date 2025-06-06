/*********************************************************
 *
 * MDCM
 *
 * Modifications github.com/issakomi
 *
 *********************************************************/

/*=========================================================================

  Program: GDCM (Grassroots DICOM). A DICOM library

  Copyright (c) 2006-2011 Mathieu Malaterre
  All rights reserved.
  See Copyright.txt or http://gdcm.sourceforge.net/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/

#include "mdcmUIDs.h"
#include <cstring>

namespace mdcm
{

const char * const UIDsStrings[][2] = {
  { nullptr, nullptr },
  { "1.2.840.10008.1.1", "Verification SOP Class" },
  { "1.2.840.10008.1.2", "Implicit VR Little Endian: Default Transfer Syntax for DICOM" },
  { "1.2.840.10008.1.2.1", "Explicit VR Little Endian" },
  { "1.2.840.10008.1.2.1.99", "Deflated Explicit VR Little Endian" },
  { "1.2.840.10008.1.2.2", "Explicit VR Big Endian" },
  { "1.2.840.10008.1.2.4.50",
    "JPEG Baseline (Process 1): Default Transfer Syntax for Lossy JPEG 8 Bit Image Compression" },
  { "1.2.840.10008.1.2.4.51",
    "JPEG Extended (Process 2 & 4): Default Transfer Syntax for Lossy JPEG 12 Bit Image Compression (Process 4 only)" },
  { "1.2.840.10008.1.2.4.52", "JPEG Extended (Process 3 & 5)" },
  { "1.2.840.10008.1.2.4.53", "JPEG Spectral Selection, Non-Hierarchical (Process 6 & 8)" },
  { "1.2.840.10008.1.2.4.54", "JPEG Spectral Selection, Non-Hierarchical (Process 7 & 9)" },
  { "1.2.840.10008.1.2.4.55", "JPEG Full Progression, Non-Hierarchical (Process 10 & 12)" },
  { "1.2.840.10008.1.2.4.56", "JPEG Full Progression, Non-Hierarchical (Process 11 & 13)" },
  { "1.2.840.10008.1.2.4.57", "JPEG Lossless, Non-Hierarchical (Process 14)" },
  { "1.2.840.10008.1.2.4.58", "JPEG Lossless, Non-Hierarchical (Process 15)" },
  { "1.2.840.10008.1.2.4.59", "JPEG Extended, Hierarchical (Process 16 & 18)" },
  { "1.2.840.10008.1.2.4.60", "JPEG Extended, Hierarchical (Process 17 & 19)" },
  { "1.2.840.10008.1.2.4.61", "JPEG Spectral Selection, Hierarchical (Process 20 & 22)" },
  { "1.2.840.10008.1.2.4.62", "JPEG Spectral Selection, Hierarchical (Process 21 & 23)" },
  { "1.2.840.10008.1.2.4.63", "JPEG Full Progression, Hierarchical (Process 24 & 26)" },
  { "1.2.840.10008.1.2.4.64", "JPEG Full Progression, Hierarchical (Process 25 & 27)" },
  { "1.2.840.10008.1.2.4.65", "JPEG Lossless, Hierarchical (Process 28)" },
  { "1.2.840.10008.1.2.4.66", "JPEG Lossless, Hierarchical (Process 29)" },
  { "1.2.840.10008.1.2.4.70",
    "JPEG Lossless, Non-Hierarchical, First-Order Prediction (Process 14 [Selection Value 1]): Default Transfer Syntax "
    "for Lossless JPEG Image Compression" },
  { "1.2.840.10008.1.2.4.80", "JPEG-LS Lossless Image Compression" },
  { "1.2.840.10008.1.2.4.81", "JPEG-LS Lossy (Near-Lossless) Image Compression" },
  { "1.2.840.10008.1.2.4.90", "JPEG 2000 Image Compression (Lossless Only)" },
  { "1.2.840.10008.1.2.4.91", "JPEG 2000 Image Compression" },
  { "1.2.840.10008.1.2.4.92", "JPEG 2000 Part 2 Multi-component Image Compression (Lossless Only)" },
  { "1.2.840.10008.1.2.4.93", "JPEG 2000 Part 2 Multi-component Image Compression" },
  { "1.2.840.10008.1.2.4.94", "JPIP Referenced" },
  { "1.2.840.10008.1.2.4.95", "JPIP Referenced Deflate" },
  { "1.2.840.10008.1.2.4.100", "MPEG2 Main Profile @ Main Level" },
  { "1.2.840.10008.1.2.5", "RLE Lossless" },
  { "1.2.840.10008.1.2.6.1", "RFC 2557 MIME encapsulation" },
  { "1.2.840.10008.1.2.6.2", "XML Encoding" },
  { "1.2.840.10008.1.3.10", "Media Storage Directory Storage" },
  { "1.2.840.10008.1.4.1.1", "Talairach Brain Atlas Frame of Reference" },
  { "1.2.840.10008.1.4.1.2", "SPM2 T1 Frame of Reference" },
  { "1.2.840.10008.1.4.1.3", "SPM2 T2 Frame of Reference" },
  { "1.2.840.10008.1.4.1.4", "SPM2 PD Frame of Reference" },
  { "1.2.840.10008.1.4.1.5", "SPM2 EPI Frame of Reference" },
  { "1.2.840.10008.1.4.1.6", "SPM2 FIL T1 Frame of Reference" },
  { "1.2.840.10008.1.4.1.7", "SPM2 PET Frame of Reference" },
  { "1.2.840.10008.1.4.1.8", "SPM2 TRANSM Frame of Reference" },
  { "1.2.840.10008.1.4.1.9", "SPM2 SPECT Frame of Reference" },
  { "1.2.840.10008.1.4.1.10", "SPM2 GRAY Frame of Reference" },
  { "1.2.840.10008.1.4.1.11", "SPM2 WHITE Frame of Reference" },
  { "1.2.840.10008.1.4.1.12", "SPM2 CSF Frame of Reference" },
  { "1.2.840.10008.1.4.1.13", "SPM2 BRAINMASK Frame of Reference" },
  { "1.2.840.10008.1.4.1.14", "SPM2 AVG305T1 Frame of Reference" },
  { "1.2.840.10008.1.4.1.15", "SPM2 AVG152T1 Frame of Reference" },
  { "1.2.840.10008.1.4.1.16", "SPM2 AVG152T2 Frame of Reference" },
  { "1.2.840.10008.1.4.1.17", "SPM2 AVG152PD Frame of Reference" },
  { "1.2.840.10008.1.4.1.18", "SPM2 SINGLESUBJT1 Frame of Reference" },
  { "1.2.840.10008.1.4.2.1", "ICBM 452 T1 Frame of Reference" },
  { "1.2.840.10008.1.4.2.2", "ICBM Single Subject MRI Frame of Reference" },
  { "1.2.840.10008.1.9", "Basic Study Content Notification SOP Class" },
  { "1.2.840.10008.1.20.1", "Storage Commitment Push Model SOP Class" },
  { "1.2.840.10008.1.20.1.1", "Storage Commitment Push Model SOP Instance" },
  { "1.2.840.10008.1.20.2", "Storage Commitment Pull Model SOP Class" },
  { "1.2.840.10008.1.20.2.1", "Storage Commitment Pull Model SOP Instance" },
  { "1.2.840.10008.1.40", "Procedural Event Logging SOP Class" },
  { "1.2.840.10008.1.40.1", "Procedural Event Logging SOP Instance" },
  { "1.2.840.10008.1.42", "Substance Administration Logging SOP Class" },
  { "1.2.840.10008.1.42.1", "Substance Administration Logging SOP Instance" },
  { "1.2.840.10008.2.6.1", "DICOM UID Registry" },
  { "1.2.840.10008.2.16.4", "DICOM Controlled Terminology" },
  { "1.2.840.10008.3.1.1.1", "DICOM Application Context Name" },
  { "1.2.840.10008.3.1.2.1.1", "Detached Patient Management SOP Class" },
  { "1.2.840.10008.3.1.2.1.4", "Detached Patient Management Meta SOP Class" },
  { "1.2.840.10008.3.1.2.2.1", "Detached Visit Management SOP Class" },
  { "1.2.840.10008.3.1.2.3.1", "Detached Study Management SOP Class" },
  { "1.2.840.10008.3.1.2.3.2", "Study Component Management SOP Class" },
  { "1.2.840.10008.3.1.2.3.3", "Modality Performed Procedure Step SOP Class" },
  { "1.2.840.10008.3.1.2.3.4", "Modality Performed Procedure Step Retrieve SOP Class" },
  { "1.2.840.10008.3.1.2.3.5", "Modality Performed Procedure Step Notification SOP Class" },
  { "1.2.840.10008.3.1.2.5.1", "Detached Results Management SOP Class" },
  { "1.2.840.10008.3.1.2.5.4", "Detached Results Management Meta SOP Class" },
  { "1.2.840.10008.3.1.2.5.5", "Detached Study Management Meta SOP Class" },
  { "1.2.840.10008.3.1.2.6.1", "Detached Interpretation Management SOP Class" },
  { "1.2.840.10008.4.2", "Storage Service Class" },
  { "1.2.840.10008.5.1.1.1", "Basic Film Session SOP Class" },
  { "1.2.840.10008.5.1.1.2", "Basic Film Box SOP Class" },
  { "1.2.840.10008.5.1.1.4", "Basic Grayscale Image Box SOP Class" },
  { "1.2.840.10008.5.1.1.4.1", "Basic Color Image Box SOP Class" },
  { "1.2.840.10008.5.1.1.4.2", "Referenced Image Box SOP Class" },
  { "1.2.840.10008.5.1.1.9", "Basic Grayscale Print Management Meta SOP Class" },
  { "1.2.840.10008.5.1.1.9.1", "Referenced Grayscale Print Management Meta SOP Class" },
  { "1.2.840.10008.5.1.1.14", "Print Job SOP Class" },
  { "1.2.840.10008.5.1.1.15", "Basic Annotation Box SOP Class" },
  { "1.2.840.10008.5.1.1.16", "Printer SOP Class" },
  { "1.2.840.10008.5.1.1.16.376", "Printer Configuration Retrieval SOP Class" },
  { "1.2.840.10008.5.1.1.17", "Printer SOP Instance" },
  { "1.2.840.10008.5.1.1.17.376", "Printer Configuration Retrieval SOP Instance" },
  { "1.2.840.10008.5.1.1.18", "Basic Color Print Management Meta SOP Class" },
  { "1.2.840.10008.5.1.1.18.1", "Referenced Color Print Management Meta SOP Class" },
  { "1.2.840.10008.5.1.1.22", "VOI LUT Box SOP Class" },
  { "1.2.840.10008.5.1.1.23", "Presentation LUT SOP Class" },
  { "1.2.840.10008.5.1.1.24", "Image Overlay Box SOP Class" },
  { "1.2.840.10008.5.1.1.24.1", "Basic Print Image Overlay Box SOP Class" },
  { "1.2.840.10008.5.1.1.25", "Print Queue SOP Instance" },
  { "1.2.840.10008.5.1.1.26", "Print Queue Management SOP Class" },
  { "1.2.840.10008.5.1.1.27", "Stored Print Storage SOP Class" },
  { "1.2.840.10008.5.1.1.29", "Hardcopy Grayscale Image Storage SOP Class" },
  { "1.2.840.10008.5.1.1.30", "Hardcopy Color Image Storage SOP Class" },
  { "1.2.840.10008.5.1.1.31", "Pull Print Request SOP Class" },
  { "1.2.840.10008.5.1.1.32", "Pull Stored Print Management Meta SOP Class" },
  { "1.2.840.10008.5.1.1.33", "Media Creation Management SOP Class UID" },
  { "1.2.840.10008.5.1.4.1.1.1", "Computed Radiography Image Storage" },
  { "1.2.840.10008.5.1.4.1.1.1.1", "Digital X-Ray Image Storage - For Presentation" },
  { "1.2.840.10008.5.1.4.1.1.1.1.1", "Digital X-Ray Image Storage - For Processing" },
  { "1.2.840.10008.5.1.4.1.1.1.2", "Digital Mammography X-Ray Image Storage - For Presentation" },
  { "1.2.840.10008.5.1.4.1.1.1.2.1", "Digital Mammography X-Ray Image Storage - For Processing" },
  { "1.2.840.10008.5.1.4.1.1.1.3", "Digital Intra-oral X-Ray Image Storage - For Presentation" },
  { "1.2.840.10008.5.1.4.1.1.1.3.1", "Digital Intra-oral X-Ray Image Storage - For Processing" },
  { "1.2.840.10008.5.1.4.1.1.2", "CT Image Storage" },
  { "1.2.840.10008.5.1.4.1.1.2.1", "Enhanced CT Image Storage" },
  { "1.2.840.10008.5.1.4.1.1.3", "Ultrasound Multi-frame Image Storage" },
  { "1.2.840.10008.5.1.4.1.1.3.1", "Ultrasound Multi-frame Image Storage" },
  { "1.2.840.10008.5.1.4.1.1.4", "MR Image Storage" },
  { "1.2.840.10008.5.1.4.1.1.4.1", "Enhanced MR Image Storage" },
  { "1.2.840.10008.5.1.4.1.1.4.2", "MR Spectroscopy Storage" },
  { "1.2.840.10008.5.1.4.1.1.5", "Nuclear Medicine Image Storage" },
  { "1.2.840.10008.5.1.4.1.1.6", "Ultrasound Image Storage" },
  { "1.2.840.10008.5.1.4.1.1.6.1", "Ultrasound Image Storage" },
  { "1.2.840.10008.5.1.4.1.1.7", "Secondary Capture Image Storage" },
  { "1.2.840.10008.5.1.4.1.1.7.1", "Multi-frame Single Bit Secondary Capture Image Storage" },
  { "1.2.840.10008.5.1.4.1.1.7.2", "Multi-frame Grayscale Byte Secondary Capture Image Storage" },
  { "1.2.840.10008.5.1.4.1.1.7.3", "Multi-frame Grayscale Word Secondary Capture Image Storage" },
  { "1.2.840.10008.5.1.4.1.1.7.4", "Multi-frame True Color Secondary Capture Image Storage" },
  { "1.2.840.10008.5.1.4.1.1.8", "Standalone Overlay Storage" },
  { "1.2.840.10008.5.1.4.1.1.9", "Standalone Curve Storage" },
  { "1.2.840.10008.5.1.4.1.1.9.1", "Waveform Storage - Trial" },
  { "1.2.840.10008.5.1.4.1.1.9.1.1", "12-lead ECG Waveform Storage" },
  { "1.2.840.10008.5.1.4.1.1.9.1.2", "General ECG Waveform Storage" },
  { "1.2.840.10008.5.1.4.1.1.9.1.3", "Ambulatory ECG Waveform Storage" },
  { "1.2.840.10008.5.1.4.1.1.9.2.1", "Hemodynamic Waveform Storage" },
  { "1.2.840.10008.5.1.4.1.1.9.3.1", "Cardiac Electrophysiology Waveform Storage" },
  { "1.2.840.10008.5.1.4.1.1.9.4.1", "Basic Voice Audio Waveform Storage" },
  { "1.2.840.10008.5.1.4.1.1.10", "Standalone Modality LUT Storage" },
  { "1.2.840.10008.5.1.4.1.1.11", "Standalone VOI LUT Storage" },
  { "1.2.840.10008.5.1.4.1.1.11.1", "Grayscale Softcopy Presentation State Storage SOP Class" },
  { "1.2.840.10008.5.1.4.1.1.11.2", "Color Softcopy Presentation State Storage SOP Class" },
  { "1.2.840.10008.5.1.4.1.1.11.3", "Pseudo-Color Softcopy Presentation State Storage SOP Class" },
  { "1.2.840.10008.5.1.4.1.1.11.4", "Blending Softcopy Presentation State Storage SOP Class" },
  { "1.2.840.10008.5.1.4.1.1.12.1", "X-Ray Angiographic Image Storage" },
  { "1.2.840.10008.5.1.4.1.1.12.1.1", "Enhanced XA Image Storage" },
  { "1.2.840.10008.5.1.4.1.1.12.2", "X-Ray Radiofluoroscopic Image Storage" },
  { "1.2.840.10008.5.1.4.1.1.12.2.1", "Enhanced XRF Image Storage" },
  { "1.2.840.10008.5.1.4.1.1.13.1.1", "X-Ray 3D Angiographic Image Storage" },
  { "1.2.840.10008.5.1.4.1.1.13.1.2", "X-Ray 3D Craniofacial Image Storage" },
  { "1.2.840.10008.5.1.4.1.1.12.3", "X-Ray Angiographic Bi-Plane Image Storage" },
  { "1.2.840.10008.5.1.4.1.1.20", "Nuclear Medicine Image Storage" },
  { "1.2.840.10008.5.1.4.1.1.66", "Raw Data Storage" },
  { "1.2.840.10008.5.1.4.1.1.66.1", "Spatial Registration Storage" },
  { "1.2.840.10008.5.1.4.1.1.66.2", "Spatial Fiducials Storage" },
  { "1.2.840.10008.5.1.4.1.1.66.3", "Deformable Spatial Registration Storage" },
  { "1.2.840.10008.5.1.4.1.1.66.4", "Segmentation Storage" },
  { "1.2.840.10008.5.1.4.1.1.67", "Real World Value Mapping Storage" },
  { "1.2.840.10008.5.1.4.1.1.77.1", "VL Image Storage - Trial" },
  { "1.2.840.10008.5.1.4.1.1.77.2", "VL Multi-frame Image Storage - Trial" },
  { "1.2.840.10008.5.1.4.1.1.77.1.1", "VL Endoscopic Image Storage" },
  { "1.2.840.10008.5.1.4.1.1.77.1.1.1", "Video Endoscopic Image Storage" },
  { "1.2.840.10008.5.1.4.1.1.77.1.2", "VL Microscopic Image Storage" },
  { "1.2.840.10008.5.1.4.1.1.77.1.2.1", "Video Microscopic Image Storage" },
  { "1.2.840.10008.5.1.4.1.1.77.1.3", "VL Slide-Coordinates Microscopic Image Storage" },
  { "1.2.840.10008.5.1.4.1.1.77.1.4", "VL Photographic Image Storage" },
  { "1.2.840.10008.5.1.4.1.1.77.1.4.1", "Video Photographic Image Storage" },
  { "1.2.840.10008.5.1.4.1.1.77.1.5.1", "Ophthalmic Photography 8 Bit Image Storage" },
  { "1.2.840.10008.5.1.4.1.1.77.1.5.2", "Ophthalmic Photography 16 Bit Image Storage" },
  { "1.2.840.10008.5.1.4.1.1.77.1.5.3", "Stereometric Relationship Storage" },
  { "1.2.840.10008.5.1.4.1.1.77.1.5.4", "Ophthalmic Tomography Image Storage" },
  { "1.2.840.10008.5.1.4.1.1.88.1", "Text SR Storage - Trial" },
  { "1.2.840.10008.5.1.4.1.1.88.2", "Audio SR Storage - Trial" },
  { "1.2.840.10008.5.1.4.1.1.88.3", "Detail SR Storage - Trial" },
  { "1.2.840.10008.5.1.4.1.1.88.4", "Comprehensive SR Storage - Trial" },
  { "1.2.840.10008.5.1.4.1.1.88.11", "Basic Text SR Storage" },
  { "1.2.840.10008.5.1.4.1.1.88.22", "Enhanced SR Storage" },
  { "1.2.840.10008.5.1.4.1.1.88.33", "Comprehensive SR Storage" },
  { "1.2.840.10008.5.1.4.1.1.88.40", "Procedure Log Storage" },
  { "1.2.840.10008.5.1.4.1.1.88.50", "Mammography CAD SR Storage" },
  { "1.2.840.10008.5.1.4.1.1.88.59", "Key Object Selection Document Storage" },
  { "1.2.840.10008.5.1.4.1.1.88.65", "Chest CAD SR Storage" },
  { "1.2.840.10008.5.1.4.1.1.88.67", "X-Ray Radiation Dose SR Storage" },
  { "1.2.840.10008.5.1.4.1.1.104.1", "Encapsulated PDF Storage" },
  { "1.2.840.10008.5.1.4.1.1.104.2", "Encapsulated CDA Storage" },
  { "1.2.840.10008.5.1.4.1.1.128", "Positron Emission Tomography Image Storage" },
  { "1.2.840.10008.5.1.4.1.1.129", "Standalone PET Curve Storage" },
  { "1.2.840.10008.5.1.4.1.1.481.1", "RT Image Storage" },
  { "1.2.840.10008.5.1.4.1.1.481.2", "RT Dose Storage" },
  { "1.2.840.10008.5.1.4.1.1.481.3", "RT Structure Set Storage" },
  { "1.2.840.10008.5.1.4.1.1.481.4", "RT Beams Treatment Record Storage" },
  { "1.2.840.10008.5.1.4.1.1.481.5", "RT Plan Storage" },
  { "1.2.840.10008.5.1.4.1.1.481.6", "RT Brachy Treatment Record Storage" },
  { "1.2.840.10008.5.1.4.1.1.481.7", "RT Treatment Summary Record Storage" },
  { "1.2.840.10008.5.1.4.1.1.481.8", "RT Ion Plan Storage" },
  { "1.2.840.10008.5.1.4.1.1.481.9", "RT Ion Beams Treatment Record Storage" },
  { "1.2.840.10008.5.1.4.1.2.1.1", "Patient Root Query/Retrieve Information Model - FIND" },
  { "1.2.840.10008.5.1.4.1.2.1.2", "Patient Root Query/Retrieve Information Model - MOVE" },
  { "1.2.840.10008.5.1.4.1.2.1.3", "Patient Root Query/Retrieve Information Model - GET" },
  { "1.2.840.10008.5.1.4.1.2.2.1", "Study Root Query/Retrieve Information Model - FIND" },
  { "1.2.840.10008.5.1.4.1.2.2.2", "Study Root Query/Retrieve Information Model - MOVE" },
  { "1.2.840.10008.5.1.4.1.2.2.3", "Study Root Query/Retrieve Information Model - GET" },
  { "1.2.840.10008.5.1.4.1.2.3.1", "Patient/Study Only Query/Retrieve Information Model - FIND" },
  { "1.2.840.10008.5.1.4.1.2.3.2", "Patient/Study Only Query/Retrieve Information Model - MOVE" },
  { "1.2.840.10008.5.1.4.1.2.3.3", "Patient/Study Only Query/Retrieve Information Model - GET" },
  { "1.2.840.10008.5.1.4.31", "Modality Worklist Information Model - FIND" },
  { "1.2.840.10008.5.1.4.32.1", "General Purpose Worklist Information Model - FIND" },
  { "1.2.840.10008.5.1.4.32.2", "General Purpose Scheduled Procedure Step SOP Class" },
  { "1.2.840.10008.5.1.4.32.3", "General Purpose Performed Procedure Step SOP Class" },
  { "1.2.840.10008.5.1.4.32", "General Purpose Worklist Management Meta SOP Class" },
  { "1.2.840.10008.5.1.4.33", "Instance Availability Notification SOP Class" },
  { "1.2.840.10008.5.1.4.34.1", "RT Beams Delivery Instruction Storage (Supplement 74 Frozen Draft)" },
  { "1.2.840.10008.5.1.4.34.2", "RT Conventional Machine Verification (Supplement 74 Frozen Draft)" },
  { "1.2.840.10008.5.1.4.34.3", "RT Ion Machine Verification (Supplement 74 Frozen Draft)" },
  { "1.2.840.10008.5.1.4.34.4", "Unified Worklist and Procedure Step Service Class" },
  { "1.2.840.10008.5.1.4.34.4.1", "Unified Procedure Step - Push SOP Class" },
  { "1.2.840.10008.5.1.4.34.4.2", "Unified Procedure Step - Watch SOP Class" },
  { "1.2.840.10008.5.1.4.34.4.3", "Unified Procedure Step - Pull SOP Class" },
  { "1.2.840.10008.5.1.4.34.4.4", "Unified Procedure Step - Event SOP Class" },
  { "1.2.840.10008.5.1.4.34.5", "Unified Worklist and Procedure Step SOP Instance" },
  { "1.2.840.10008.5.1.4.37.1", "General Relevant Patient Information Query" },
  { "1.2.840.10008.5.1.4.37.2", "Breast Imaging Relevant Patient Information Query" },
  { "1.2.840.10008.5.1.4.37.3", "Cardiac Relevant Patient Information Query" },
  { "1.2.840.10008.5.1.4.38.1", "Hanging Protocol Storage" },
  { "1.2.840.10008.5.1.4.38.2", "Hanging Protocol Information Model - FIND" },
  { "1.2.840.10008.5.1.4.38.3", "Hanging Protocol Information Model - MOVE" },
  { "1.2.840.10008.5.1.4.41", "Product Characteristics Query SOP Class" },
  { "1.2.840.10008.5.1.4.42", "Substance Approval Query SOP Class" },
  { "1.2.840.10008.15.0.3.1", "dicomDeviceName" },
  { "1.2.840.10008.15.0.3.2", "dicomDescription" },
  { "1.2.840.10008.15.0.3.3", "dicomManufacturer" },
  { "1.2.840.10008.15.0.3.4", "dicomManufacturerModelName" },
  { "1.2.840.10008.15.0.3.5", "dicomSoftwareVersion" },
  { "1.2.840.10008.15.0.3.6", "dicomVendorData" },
  { "1.2.840.10008.15.0.3.7", "dicomAETitle" },
  { "1.2.840.10008.15.0.3.8", "dicomNetworkConnectionReference" },
  { "1.2.840.10008.15.0.3.9", "dicomApplicationCluster" },
  { "1.2.840.10008.15.0.3.10", "dicomAssociationInitiator" },
  { "1.2.840.10008.15.0.3.11", "dicomAssociationAcceptor" },
  { "1.2.840.10008.15.0.3.12", "dicomHostname" },
  { "1.2.840.10008.15.0.3.13", "dicomPort" },
  { "1.2.840.10008.15.0.3.14", "dicomSOPClass" },
  { "1.2.840.10008.15.0.3.15", "dicomTransferRole" },
  { "1.2.840.10008.15.0.3.16", "dicomTransferSyntax" },
  { "1.2.840.10008.15.0.3.17", "dicomPrimaryDeviceType" },
  { "1.2.840.10008.15.0.3.18", "dicomRelatedDeviceReference" },
  { "1.2.840.10008.15.0.3.19", "dicomPreferredCalledAETitle" },
  { "1.2.840.10008.15.0.3.20", "dicomTLSCyphersuite" },
  { "1.2.840.10008.15.0.3.21", "dicomAuthorizedNodeCertificateReference" },
  { "1.2.840.10008.15.0.3.22", "dicomThisNodeCertificateReference" },
  { "1.2.840.10008.15.0.3.23", "dicomInstalled" },
  { "1.2.840.10008.15.0.3.24", "dicomStationName" },
  { "1.2.840.10008.15.0.3.25", "dicomDeviceSerialNumber" },
  { "1.2.840.10008.15.0.3.26", "dicomInstitutionName" },
  { "1.2.840.10008.15.0.3.27", "dicomInstitutionAddress" },
  { "1.2.840.10008.15.0.3.28", "dicomInstitutionDepartmentName" },
  { "1.2.840.10008.15.0.3.29", "dicomIssuerOfPatientID" },
  { "1.2.840.10008.15.0.3.30", "dicomPreferredCallingAETitle" },
  { "1.2.840.10008.15.0.3.31", "dicomSupportedCharacterSet" },
  { "1.2.840.10008.15.0.4.1", "dicomConfigurationRoot" },
  { "1.2.840.10008.15.0.4.2", "dicomDevicesRoot" },
  { "1.2.840.10008.15.0.4.3", "dicomUniqueAETitlesRegistryRoot" },
  { "1.2.840.10008.15.0.4.4", "dicomDevice" },
  { "1.2.840.10008.15.0.4.5", "dicomNetworkAE" },
  { "1.2.840.10008.15.0.4.6", "dicomNetworkConnection" },
  { "1.2.840.10008.15.0.4.7", "dicomUniqueAETitle" },
  { "1.2.840.10008.15.0.4.8", "dicomTransferCapability" },
  //
  { "1.2.840.10008.5.1.4.1.1.77.1.6", "VL Whole Slide Microscopy Image Storage" },
  { "1.2.840.10008.5.1.4.1.1.6.2", "Enhanced US Volume Storage" },
  { "1.2.840.10008.5.1.4.1.1.66.5", "Surface Segmentation Storage" },
  { "1.2.840.10008.5.1.4.1.1.13.1.3", "Breast Tomosynthesis Image Storage" },
  { "1.2.840.10008.5.1.4.1.1.2.2", "Legacy Converted Enhanced CT Image Storage" },
  { "1.2.840.10008.5.1.4.1.1.4.4", "Legacy Converted Enhanced MR Image Storage" },
  { "1.2.840.10008.5.1.4.1.1.128.1", "Legacy Converted Enhanced PET Image Storage" },
  { "1.2.840.10008.1.2.4.101", "MPEG2 Main Profile @ High Level" },
  { "1.2.840.10008.1.2.4.102", "MPEG-4 AVC/H.264 High Profile / Level 4.1" },
  { "1.2.840.10008.1.2.4.103", "MPEG-4 AVC/H.264 BD-compatible High Profile / Level 4.1" },

  //////////////////////////////////////////////
  //
  // 2019b
  //
  { "1.2.840.10008.1.5.2", "PET Color Palette SOP Instance" },
  { "1.2.840.10008.1.5.3", "Hot Metal Blue Color Palette SOP Instance" },
  { "1.2.840.10008.1.5.4", "PET 20 Step Color Palette SOP Instance" },
  { "1.2.840.10008.1.5.5", "Spring Color Palette SOP Instance" },
  { "1.2.840.10008.1.5.6", "Summer Color Palette SOP Instance" },
  { "1.2.840.10008.1.5.7", "Fall Color Palette SOP Instance" },
  { "1.2.840.10008.1.5.8", "Winter Color Palette SOP Instance" },
  { "1.2.840.10008.1.20", "Papyrus 3 Implicit VR Little Endian" },
  { "1.2.840.10008.2.16.5", "Adult Mouse Anatomy Ontology" },
  { "1.2.840.10008.2.16.6", "Uberon Ontology" },
  { "1.2.840.10008.2.16.7", "Integrated Taxonomic Information System (ITIS) Taxonomic Serial Number (TSN)" },
  { "1.2.840.10008.2.16.8", "Mouse Genome Initiative (MGI)" },
  { "1.2.840.10008.2.16.9", "PubChem Compound CID" },
  { "1.2.840.10008.2.16.10", "ICD-11" },
  { "1.2.840.10008.2.16.11", "New York University Melanoma Clinical Cooperative Group" },
  { "1.2.840.10008.2.16.12",
    "Mayo Clinic Non-radiological Images Specific Body Structure Anatomical Surface Region Guide" },
  { "1.2.840.10008.2.16.13", "Image Biomarker Standardisation Initiative" },
  { "1.2.840.10008.2.16.14", "Radiomics Ontology" },
  { "1.2.840.10008.5.1.1.40", "Display System SOP Class" },
  { "1.2.840.10008.5.1.1.40.1", "Display System SOP Instance" },
  { "1.2.840.10008.5.1.4.1.1.9.4.2", "General Audio Waveform Storage" },
  { "1.2.840.10008.5.1.4.1.1.9.5.1", "Arterial Pulse Waveform Storage" },
  { "1.2.840.10008.5.1.4.1.1.9.6.1", "Respiratory Waveform Storage" },
  { "1.2.840.10008.5.1.4.1.1.11.5", "XA/XRF Grayscale Softcopy Presentation State Storage" },
  { "1.2.840.10008.5.1.4.1.1.11.6", "Grayscale Planar MPR Volumetric Presentation State Storage" },
  { "1.2.840.10008.1.2.4.104", "MPEG-4 AVC/H.264 High Profile / Level 4.2 For 2D Video" },
  { "1.2.840.10008.1.2.4.105", "MPEG-4 AVC/H.264 High Profile / Level 4.2 For 3D Video" },
  { "1.2.840.10008.1.2.4.106", "MPEG-4 AVC/H.264 Stereo High Profile / Level 4.2" },
  { "1.2.840.10008.1.2.4.107", "HEVC/H.265 Main Profile / Level 5.1" },
  { "1.2.840.10008.1.2.4.108", "HEVC/H.265 Main 10 Profile / Level 5.1" },
  { "1.2.840.10008.1.5.1", "Hot Iron Color Palette SOP Instance" },
  { "1.2.840.10008.5.1.4.1.1.11.7", "Compositing Planar MPR Volumetric Presentation State Storage" },
  { "1.2.840.10008.5.1.4.1.1.11.8", "Advanced Blending Presentation State Storage" },
  { "1.2.840.10008.5.1.4.1.1.11.9", "Volume Rendering Volumetric Presentation State Storage" },
  { "1.2.840.10008.5.1.4.1.1.11.10", "Segmented Volume Rendering Volumetric Presentation State Storage" },
  { "1.2.840.10008.5.1.4.1.1.11.11", "Multiple Volume Rendering Volumetric Presentation State Storage" },
  { "1.2.840.10008.5.1.4.1.1.12.77", "null" },
  { "1.2.840.10008.5.1.4.1.1.13.1.4", "Breast Projection X-Ray Image Storage - For Presentation" },
  { "1.2.840.10008.5.1.4.1.1.13.1.5", "Breast Projection X-Ray Image Storage - For Processing" },
  { "1.2.840.10008.5.1.4.1.1.14.1", "Intravascular Optical Coherence Tomography Image Storage - For Presentation" },
  { "1.2.840.10008.5.1.4.1.1.14.2", "Intravascular Optical Coherence Tomography Image Storage - For Processing" },
  { "1.2.840.10008.5.1.4.1.1.30", "Parametric Map Storage" },
  { "1.2.840.10008.5.1.4.1.1.40", "null" },
  { "1.2.840.10008.5.1.4.1.1.66.6", "Tractography Results Storage" },
  { "1.2.840.10008.5.1.4.1.1.68.1", "Surface Scan Mesh Storage" },
  { "1.2.840.10008.5.1.4.1.1.68.2", "Surface Scan Point Cloud Storage" },
  { "1.2.840.10008.5.1.4.1.1.77.1.5.5", "Wide Field Ophthalmic Photography Stereographic Projection Image Storage" },
  { "1.2.840.10008.5.1.4.1.1.77.1.5.6", "Wide Field Ophthalmic Photography 3D Coordinates Image Storage" },
  { "1.2.840.10008.5.1.4.1.1.77.1.5.7", "Ophthalmic Optical Coherence Tomography En Face Image Storage" },
  { "1.2.840.10008.5.1.4.1.1.77.1.5.8", "Ophthalmic Optical Coherence Tomography B-scan Volume Analysis Storage" },
  { "1.2.840.10008.5.1.4.1.1.78.1", "Lensometry Measurements Storage" },
  { "1.2.840.10008.5.1.4.1.1.78.2", "Autorefraction Measurements Storage" },
  { "1.2.840.10008.5.1.4.1.1.78.3", "Keratometry Measurements Storage" },
  { "1.2.840.10008.5.1.4.1.1.78.4", "Subjective Refraction Measurements Storage" },
  { "1.2.840.10008.5.1.4.1.1.78.5", "Visual Acuity Measurements Storage" },
  { "1.2.840.10008.5.1.4.1.1.78.6", "Spectacle Prescription Report Storage" },
  { "1.2.840.10008.5.1.4.1.1.78.7", "Ophthalmic Axial Measurements Storage" },
  { "1.2.840.10008.5.1.4.1.1.78.8", "Intraocular Lens Calculations Storage" },
  { "1.2.840.10008.5.1.4.1.1.79.1", "Macular Grid Thickness and Volume Report Storage" },
  { "1.2.840.10008.5.1.4.1.1.80.1", "Ophthalmic Visual Field Static Perimetry Measurements Storage" },
  { "1.2.840.10008.5.1.4.1.1.81.1", "Ophthalmic Thickness Map Storage" },
  { "1.2.840.10008.5.1.4.1.1.82.1", "Corneal Topography Map Storage" },
  { "1.2.840.10008.5.1.4.1.1.88.34", "Comprehensive 3D SR Storage" },
  { "1.2.840.10008.5.1.4.1.1.88.35", "Extensible SR Storage" },
  { "1.2.840.10008.5.1.4.1.1.88.68", "Radiopharmaceutical Radiation Dose SR Storage" },
  { "1.2.840.10008.5.1.4.1.1.88.69", "Colon CAD SR Storage" },
  { "1.2.840.10008.5.1.4.1.1.88.70", "Implantation Plan SR Storage" },
  { "1.2.840.10008.5.1.4.1.1.88.71", "Acquisition Context SR Storage" },
  { "1.2.840.10008.5.1.4.1.1.88.72", "Simplified Adult Echo SR Storage" },
  { "1.2.840.10008.5.1.4.1.1.88.73", "Patient Radiation Dose SR Storage" },
  { "1.2.840.10008.5.1.4.1.1.88.74", "Planned Imaging Agent Administration SR Storage" },
  { "1.2.840.10008.5.1.4.1.1.88.75", "Performed Imaging Agent Administration SR Storage" },
  { "1.2.840.10008.5.1.4.1.1.90.1", "Content Assessment Results Storage" },
  { "1.2.840.10008.5.1.4.1.1.104.3", "Encapsulated STL Storage" },
  { "1.2.840.10008.5.1.4.1.1.130", "Enhanced PET Image Storage" },
  { "1.2.840.10008.5.1.4.1.1.131", "Basic Structured Display Storage" },
  { "1.2.840.10008.5.1.4.1.1.200.1", "CT Defined Procedure Protocol Storage" },
  { "1.2.840.10008.5.1.4.1.1.200.2", "CT Performed Procedure Protocol Storage" },
  { "1.2.840.10008.5.1.4.1.1.200.3", "Protocol Approval Storage" },
  { "1.2.840.10008.5.1.4.1.1.200.4", "Protocol Approval Information Model - FIND" },
  { "1.2.840.10008.5.1.4.1.1.200.5", "Protocol Approval Information Model - MOVE" },
  { "1.2.840.10008.5.1.4.1.1.200.6", "Protocol Approval Information Model - GET" },
  { "1.2.840.10008.5.1.4.1.1.481.10", "RT Physician Intent Storage" },
  { "1.2.840.10008.5.1.4.1.1.481.11", "RT Segment Annotation Storage" },
  { "1.2.840.10008.5.1.4.1.1.501.1", "DICOS CT Image Storage" },
  { "1.2.840.10008.5.1.4.1.1.501.2.1", "DICOS Digital X-Ray Image Storage - For Presentation" },
  { "1.2.840.10008.5.1.4.1.1.501.2.2", "DICOS Digital X-Ray Image Storage - For Processing" },
  { "1.2.840.10008.5.1.4.1.1.501.3", "DICOS Threat Detection Report Storage" },
  { "1.2.840.10008.5.1.4.1.1.501.4", "DICOS 2D AIT Storage" },
  { "1.2.840.10008.5.1.4.1.1.501.5", "DICOS 3D AIT Storage" },
  { "1.2.840.10008.5.1.4.1.1.501.6", "DICOS Quadrupole Resonance (QR) Storage" },
  { "1.2.840.10008.5.1.4.1.1.601.1", "Eddy Current Image Storage" },
  { "1.2.840.10008.5.1.4.1.1.601.2", "Eddy Current Multi-frame Image Storage" },
  { "1.2.840.10008.5.1.4.1.2.4.2", "Composite Instance Root Retrieve - MOVE" },
  { "1.2.840.10008.5.1.4.1.2.4.3", "Composite Instance Root Retrieve - GET" },
  { "1.2.840.10008.5.1.4.1.2.5.3", "Composite Instance Retrieve Without Bulk Data - GET" },
  { "1.2.840.10008.5.1.4.20.1", "Defined Procedure Protocol Information Model - FIND" },
  { "1.2.840.10008.5.1.4.20.2", "Defined Procedure Protocol Information Model - MOVE" },
  { "1.2.840.10008.5.1.4.20.3", "Defined Procedure Protocol Information Model - GET" },
  { "1.2.840.10008.5.1.4.34.5.1", "UPS Filtered Global Subscription SOP Instance" },
  { "1.2.840.10008.5.1.4.34.6", "Unified Worklist and Procedure Step Service Class (1)" },
  { "1.2.840.10008.5.1.4.34.6.1", "Unified Procedure Step - Push SOP Class (1)" },
  { "1.2.840.10008.5.1.4.34.6.2", "Unified Procedure Step - Watch SOP Class (1)" },
  { "1.2.840.10008.5.1.4.34.6.3", "Unified Procedure Step - Pull SOP Class (1)" },
  { "1.2.840.10008.5.1.4.34.6.4", "Unified Procedure Step - Event SOP Class (1)" },
  { "1.2.840.10008.5.1.4.34.7", "RT Beams Delivery Instruction Storage" },
  { "1.2.840.10008.5.1.4.34.8", "RT Conventional Machine Verification" },
  { "1.2.840.10008.5.1.4.34.9", "RT Ion Machine Verification" },
  { "1.2.840.10008.5.1.4.34.10", "RT Brachy Application Setup Delivery Instruction Storage" },
  { "1.2.840.10008.5.1.4.38.4", "Hanging Protocol Information Model - GET" },
  { "1.2.840.10008.5.1.4.39.1", "Color Palette Storage" },
  { "1.2.840.10008.5.1.4.39.2", "Color Palette Query/Retrieve Information Model - FIND" },
  { "1.2.840.10008.5.1.4.39.3", "Color Palette Query/Retrieve Information Model - MOVE" },
  { "1.2.840.10008.5.1.4.39.4", "Color Palette Query/Retrieve Information Model - GET" },
  { "1.2.840.10008.5.1.4.43.1", "Generic Implant Template Storage" },
  { "1.2.840.10008.5.1.4.43.2", "Generic Implant Template Information Model - FIND" },
  { "1.2.840.10008.5.1.4.43.3", "Generic Implant Template Information Model - MOVE" },
  { "1.2.840.10008.5.1.4.43.4", "Generic Implant Template Information Model - GET" },
  { "1.2.840.10008.5.1.4.44.1", "Implant Assembly Template Storage" },
  { "1.2.840.10008.5.1.4.44.2", "Implant Assembly Template Information Model - FIND" },
  { "1.2.840.10008.5.1.4.44.3", "Implant Assembly Template Information Model - MOVE" },
  { "1.2.840.10008.5.1.4.44.4", "Implant Assembly Template Information Model - GET" },
  { "1.2.840.10008.5.1.4.45.1", "Implant Template Group Storage" },
  { "1.2.840.10008.5.1.4.45.2", "Implant Template Group Information Model - FIND" },
  { "1.2.840.10008.5.1.4.45.3", "Implant Template Group Information Model - MOVE" },
  { "1.2.840.10008.5.1.4.45.4", "Implant Template Group Information Model - GET" },
  { "1.2.840.10008.7.1.1", "Native DICOM Model" },
  { "1.2.840.10008.7.1.2", "Abstract Multi-Dimensional Image Model" },
  { "1.2.840.10008.8.1.1", "DICOM Content Mapping Resource" },
  { "1.2.840.10008.5.1.4.1.1.4.3", "Enhanced MR Color Image Storage" },
  { "1.2.840.10008.15.1.1", "Universal Coordinated Time" },
  //
  //
  //
  //////////////////////////////////////////////

  /////////////////////////////////////////////////////////////////////////
  //
  // Private UIDs
  //
  { "1.2.840.113619.4.2", "GE Magnetic Resonance Image Storage" },
  { "1.2.840.113619.4.3", "GE Computed Tomography Image Storage" },
  { "1.3.12.2.1107.5.9.1", "CSA Non-Image Storage" },
  // iis_fp_10282r2.pdf
  { "1.2.840.113619.4.26", "GE Private 3D Model Storage" },
  { "1.2.840.113619.4.30", "GE Advance Raw Data Storage" },
  { "2.16.840.1.113709.1.5.1", "GEPACS_PRIVATE_IMS_INFO Storage" },
  { "2.16.840.1.113709.1.2.2", "COMPRESS_EXPRESS TRANSFER SYNTAX" },
  { "1.2.840.113543.6.6.1.3.10002", "Philips 3D" },
  { "1.2.392.200036.9116.7.8.1.1.1", "Toshiba Private Data Storage" },
  // business.fujifilm.co.uk/medical/downloads/DICOM_xg1.pdf
  { "1.2.392.200036.9125.1.1.2", "Fuji Private CR Image Storage" },
  // CREF4.09-80_iSite4.1DICOMConformance.pdf
  // Correction: 1.2.840113619.4.27 -> 1.2.840.113619.4.27 ... sigh
  // DICOM_Conformance_Statement_MR_R2.6.pdf
  { "1.2.840.113619.4.27", "GE Nuclear Medicine private SOP Class" },
  { "1.3.46.670589.11.0.0.12.1", "Philips Private MR Spectrum Storage" },
  { "1.3.46.670589.11.0.0.12.2", "Philips Private MR Series Data Storage" },
  { "1.3.46.670589.11.0.0.12.4", "Philips Private MR Examcard Storage" },
  { "1.3.46.670589.2.3.1.1", "Philips Private Specialized XA Image" },
  { "1.3.46.670589.2.4.1.1", "Philips Private CX Image Storage" },
  { "1.3.46.670589.2.5.1.1", "Philips iE33 private 3D Object Storage" },
  { "1.3.46.670589.5.0.1", "Philips Private Volume Storage" },
  { "1.3.46.670589.5.0.1.1", "Philips Private Volume Image Reference" },
  { "1.3.46.670589.5.0.10", "Philips Private MR Synthetic Image Storage" },
  { "1.3.46.670589.5.0.11", "Philips Private MR Cardio Analysis Storage" },
  { "1.3.46.670589.5.0.11.1", "Philips Private MR Cardio Analysis Data" },
  { "1.3.46.670589.5.0.12", "Philips Private CX Synthetic Image Storage" },
  { "1.3.46.670589.5.0.13", "Philips Private Perfusion Image Reference" },
  { "1.3.46.670589.5.0.14", "Philips Private Perfusion Analysis Data" },
  { "1.3.46.670589.5.0.2", "Philips Private 3D Object Storage" },
  { "1.3.46.670589.5.0.2.1", "Philips Private 3D Object 2 Storage" },
  { "1.3.46.670589.5.0.3", "Philips Private Surface Storage" },
  { "1.3.46.670589.5.0.3.1", "Philips Private Surface 2 Storage" },
  { "1.3.46.670589.5.0.4", "Philips Private Composite Object Storage" },
  { "1.3.46.670589.5.0.7", "Philips Private MR Cardio Profile" },
  { "1.3.46.670589.5.0.8", "Philips Private MR Cardio" },
  { "1.3.46.670589.5.0.9", "Philips Private CT Synthetic Image Storage" },
  // PACS_conformance_statement_10.2P2.pdf
  { "1.2.752.24.3.7.6", "Sectra Compression" },
  { "1.2.752.24.3.7.7", "Sectra Compression LS" },
  { "1.2.840.113619.5.2", "GE Implicit VR Big Endian DLX" },
  // DICOM_Conformance_Statement_GEMINI_R3.5_R3.6.pdf
  { "1.3.46.670589.33.1.4.1", "CT-private-ELE" },
  { "1.2.276.0.7230010.3.1.0.1", "DCMTK Unknown" },
  //
  //
  //
  /////////////////////////////////////////////////////////////////////////

  //////////////////////////////////////////////
  //
  // 2021d
  //
  { "1.2.840.10008.1.2.1.98", "Encapsulated Uncompressed Explicit VR Little Endian" },
  { "1.2.840.10008.1.2.7.1", "SMPTE ST 2110-20 Uncompressed Progressive Active Video" },
  { "1.2.840.10008.1.2.7.2", "SMPTE ST 2110-20 Uncompressed Interlaced Active Video" },
  { "1.2.840.10008.1.2.7.3", "SMPTE ST 2110-30 PCM Digital Audio" },
  { "1.2.840.10008.5.1.4.1.1.9.7.1", "Routine Scalp Electroencephalogram Waveform Storage" },
  { "1.2.840.10008.5.1.4.1.1.9.7.2", "Electromyogram Waveform Storage" },
  { "1.2.840.10008.5.1.4.1.1.9.7.3", "Electrooculogram Waveform Storage" },
  { "1.2.840.10008.5.1.4.1.1.9.7.4", "Sleep Electroencephalogram Waveform Storage" },
  { "1.2.840.10008.5.1.4.1.1.9.8.1", "Body Position Waveform Storage" },
  { "1.2.840.10008.5.1.4.1.1.77.1.7", "Dermoscopic Photography Image Storage" },
  { "1.2.840.10008.5.1.4.1.1.88.76", "Enhanced X-Ray Radiation Dose SR Storage" },
  { "1.2.840.10008.5.1.4.1.1.104.4", "Encapsulated OBJ Storage" },
  { "1.2.840.10008.5.1.4.1.1.104.5", "Encapsulated MTL Storage" },
  { "1.2.840.10008.5.1.4.1.1.200.7", "XA Defined Procedure Protocol Storage" },
  { "1.2.840.10008.5.1.4.1.1.200.8", "XA Performed Procedure Protocol Storage" },
  { "1.2.840.10008.5.1.4.1.1.481.12", "RT Radiation Set Storage" },
  { "1.2.840.10008.5.1.4.1.1.481.13", "C-Arm Photon-Electron Radiation Storage" },
  { "1.2.840.10008.5.1.4.1.1.481.14", "Tomotherapeutic Radiation Storage" },
  { "1.2.840.10008.5.1.4.1.1.481.15", "Robotic-Arm Radiation Storage" },
  { "1.2.840.10008.5.1.4.1.1.481.16", "RT Radiation Record Set Storage" },
  { "1.2.840.10008.5.1.4.1.1.481.17", "RT Radiation Salvage Record Storage" },
  { "1.2.840.10008.5.1.4.1.1.481.18", "Tomotherapeutic Radiation Record Storage" },
  { "1.2.840.10008.5.1.4.1.1.481.19", "C-Arm Photon-Electron Radiation Record Storage" },
  { "1.2.840.10008.5.1.4.1.1.481.20", "Robotic Radiation Record Storage" },
  { "1.2.840.10008.5.1.4.1.1.481.21", "RT Radiation Set Delivery Instruction Storage" },
  { "1.2.840.10008.5.1.4.1.1.481.22", "RT Treatment Preparation Storage" },
  { "1.2.840.10008.5.1.4.34.6.5", "Unified Procedure Step - Query SOP Class" },
  { "1.2.840.10008.10.1", "Video Endoscopic Image Real-Time Communication" },
  { "1.2.840.10008.10.2", "Video Photographic Image Real-Time Communication" },
  { "1.2.840.10008.10.3", "Audio Waveform Real-Time Communication" },
  { "1.2.840.10008.10.4", "Rendition Selection Document Real-Time Communication" },
  //
  //
  //
  //////////////////////////////////////////////

  //////////////////////////////////////////////
  //
  // 2023c
  //
  { "1.2.840.10008.1.2.4.100.1", "Fragmentable MPEG2 Main Profile / Main Level" },
  { "1.2.840.10008.1.2.4.101.1", "Fragmentable MPEG2 Main Profile / High Level" },
  { "1.2.840.10008.1.2.4.102.1", "Fragmentable MPEG-4 AVC/H.264 High Profile / Level 4.1" },
  { "1.2.840.10008.1.2.4.103.1", "Fragmentable MPEG-4 AVC/H.264 BD-compatible High Profile / Level 4.1" },
  { "1.2.840.10008.1.2.4.104.1", "Fragmentable MPEG-4 AVC/H.264 High Profile / Level 4.2 For 2D Video" },
  { "1.2.840.10008.1.2.4.105.1", "Fragmentable MPEG-4 AVC/H.264 High Profile / Level 4.2 For 3D Video" },
  { "1.2.840.10008.1.2.4.106.1", "Fragmentable MPEG-4 AVC/H.264 Stereo High Profile / Level 4.2" },
  { "1.2.840.10008.2.16.17", "Unified numbering system (UNS) for metals and alloys" },
  { "1.2.840.10008.2.16.18", "Research Resource Identification" },
  { "1.2.840.10008.5.1.4.1.1.6.3", "Photoacoustic Image Storage" },
  { "1.2.840.10008.5.1.4.1.1.9.1.4", "General 32-bit ECG Waveform Storage" },
  { "1.2.840.10008.5.1.4.1.1.11.12", "Variable Modality LUT Softcopy Presentation State Storage" },
  { "1.2.840.10008.5.1.4.1.1.201.1", "Inventory Storage" },
  { "1.2.840.10008.5.1.4.1.1.201.2", "Inventory - FIND" },
  { "1.2.840.10008.5.1.4.1.1.201.3", "Inventory - MOVE" },
  { "1.2.840.10008.5.1.4.1.1.201.4", "Inventory - GET" },
  { "1.2.840.10008.5.1.4.1.1.201.5", "Inventory Creation" },
  { "1.2.840.10008.5.1.4.1.1.201.6", "Repository Query" },
  { "1.2.840.10008.5.1.4.1.1.201.1.1", "Storage Management SOP Instance" },
  { "1.2.840.10008.5.1.4.1.1.481.23", "Enhanced RT Image Storage" },
  { "1.2.840.10008.5.1.4.1.1.481.24", "Enhanced Continuous RT Image Storage" },
  { "1.2.840.10008.5.1.4.1.1.481.25", "RT Patient Position Acquisition Instruction Storage" },
  //
  //
  //
  //////////////////////////////////////////////

  //////////////////////////////////////////////
  //
  // 2023e
  //
  { "1.2.840.10008.1.2.4.201", "High-Throughput JPEG 2000 Image Compression (Lossless Only)"},
  { "1.2.840.10008.1.2.4.202", "High-Throughput JPEG 2000 with RPCL Options Image Compression (Lossless Only)"},
  { "1.2.840.10008.1.2.4.203", "High-Throughput JPEG 2000 Image Compression"},
  { "1.2.840.10008.1.2.4.204", "JPIP HTJ2K Referenced"},
  { "1.2.840.10008.1.2.4.205", "JPIP HTJ2K Referenced Deflate"},
  { "1.2.840.10008.5.1.4.1.1.77.1.8", "Confocal Microscopy Image Storage"},
  { "1.2.840.10008.5.1.4.1.1.77.1.9", "Confocal Microscopy Tiled Pyramidal Image Storage"},
  //
  //
  //
  //////////////////////////////////////////////

  //////////////////////////////////////////////
  //
  // 2025a
  //
  { "1.2.840.10008.1.2.4.110", "JPEG XL Lossless" },
  { "1.2.840.10008.1.2.4.111", "JPEG XL JPEG Recompression" },
  { "1.2.840.10008.1.2.4.112", "JPEG XL" },
  { "1.2.840.10008.1.2.8.1", "Deflated Image Frame Compression" },
  { "1.2.840.10008.5.1.4.1.1.9.100.1", "Waveform Presentation State Storage" },
  { "1.2.840.10008.5.1.4.1.1.9.100.2", "Waveform Acquisition Presentation State Storage" },
  { "1.2.840.10008.5.1.4.1.1.66.7", "Label Map Segmentation Storage" },
  { "1.2.840.10008.5.1.4.1.1.66.8", "Height Map Segmentation Storage" },
  { "1.2.840.10008.5.1.4.1.1.88.77", "Waveform Annotation SR Storage" },
  { "1.2.840.10008.5.1.4.1.1.601.3", "Thermography Image Storage" },
  { "1.2.840.10008.5.1.4.1.1.601.4", "Thermography Multi-frame Image Storage" },
  //
  //
  //
  //////////////////////////////////////////////

  { nullptr, nullptr }
};

UIDs::UIDs()
{
  UIDField = uid_0;
}

unsigned int
UIDs::GetNumberOfUIDsStrings()
{
  return static_cast<unsigned int>(sizeof(UIDsStrings) / sizeof(*UIDsStrings) - 2);
}

const char * const *
UIDs::GetUIDsString(unsigned int x)
{
  if (x > 0 && x <= UIDs::GetNumberOfUIDsStrings())
    return UIDsStrings[x];
  return UIDsStrings[UIDs::GetNumberOfUIDsStrings() + 1];
}

const char *
UIDs::GetUIDString(unsigned int x)
{
  return UIDs::GetUIDsString(x)[0];
}

const char *
UIDs::GetUIDName(unsigned int x)
{
  return UIDs::GetUIDsString(x)[1];
}

UIDs::UIDsStringsType
UIDs::GetUIDsStrings()
{
  return UIDsStrings;
}

bool
UIDs::SetFromUID(const char * str)
{
  if (!str)
    return false;
  UIDField = uid_0;
  UIDsStringsType uids = GetUIDsStrings();
  int             i = 1;
  const char *    p = uids[i][0];
  while (p != nullptr)
  {
    if (strcmp(p, str) == 0)
    {
      break;
    }
    ++i;
    p = uids[i][0];
  }
  if (p)
  {
    UIDField = UIDType(i);
    return true;
  }
  return false;
}

const char *
UIDs::GetString() const
{
  return GetUIDString(UIDField);
}
const char *
UIDs::GetName() const
{
  return GetUIDName(UIDField);
}

} // end namespace mdcm
