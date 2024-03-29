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
#ifndef MDCMDATASETHELPER_H
#define MDCMDATASETHELPER_H

#include "mdcmTypes.h"
#include "mdcmVR.h"

namespace mdcm
{

class DataSet;
class File;
class Tag;

/**
 * DataSetHelper (not intended at user level)
 */
class MDCM_EXPORT DataSetHelper
{
public:
  static VR
  ComputeVR(const File &, const DataSet &, const Tag &);
};

} // end namespace mdcm

#endif // MDCMDATASETHELPER_H
