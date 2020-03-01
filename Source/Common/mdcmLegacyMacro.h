/*=========================================================================

  Program: GDCM (Grassroots DICOM). A DICOM library

  Copyright (c) 2006-2011 Mathieu Malaterre
  All rights reserved.
  See Copyright.txt or http://gdcm.sourceforge.net/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#ifndef MDCMLEGACYMACRO_H
#define MDCMLEGACYMACRO_H

#if !defined(MDCMTYPES_H) && !defined(SWIG)
#error you need to include mdcmTypes.h instead
#endif

#include "mdcmException.h"

#if defined(MDCM_LEGACY_REMOVE)
# define MDCM_LEGACY(method)
#elif defined(MDCM_LEGACY_SILENT) || defined(SWIG)
# define MDCM_LEGACY(method) method;
#else
# if defined(__GNUC__) && !defined(__INTEL_COMPILER) && (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 1))
#  define MDCM_LEGACY(method) method __attribute__((deprecated));
# elif defined(_MSC_VER) && _MSC_VER >= 1300
#  define MDCM_LEGACY(method) __declspec(deprecated) method;
# else
#  define MDCM_LEGACY(method) method;
# endif
#endif

#if defined(MDCM_LEGACY_REMOVE) || defined(MDCM_LEGACY_SILENT)
# define MDCM_LEGACY_BODY(method, version)
# define MDCM_LEGACY_REPLACED_BODY(method, version, replace)
#else
# define MDCM_LEGACY_BODY(method, version) \
  mdcmWarningMacro(#method " was deprecated for " version " and will be removed in a future version.")
# define MDCM_LEGACY_REPLACED_BODY(method, version, replace) \
  mdcmWarningMacro(#method " was deprecated for " version " and will be removed in a future version.  Use " #replace " instead.")
#endif

#include "mdcmTrace.h"

#endif // MDCMLEGACYMACRO_H
