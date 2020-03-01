/*=========================================================================

  Program: GDCM (Grassroots DICOM). A DICOM library

  Copyright (c) 2006-2011 Mathieu Malaterre
  All rights reserved.
  See Copyright.txt or http://gdcm.sourceforge.net/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#ifndef MDCMUUIDGENERATOR_H
#define MDCMUUIDGENERATOR_H

#include "mdcmTypes.h"

namespace mdcm
{

/**
 * \brief Class for generating unique UUID
 */
class MDCM_EXPORT UUIDGenerator
{
public:
  // NOT THREAD SAFE
  const char * Generate();
  static bool IsValid(const char * uid);

private:
  std::string Unique;
};

} // end namespace mdcm

#endif //MDCMUUIDGENERATOR_H
