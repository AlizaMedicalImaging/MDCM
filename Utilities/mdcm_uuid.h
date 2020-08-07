/*=========================================================================

  Program: GDCM (Grassroots DICOM). A DICOM library

  Copyright (c) 2006-2011 Mathieu Malaterre
  All rights reserved.
  See Copyright.txt or http://gdcm.sourceforge.net/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#ifndef MDCM_UUID_H
#define MDCM_UUID_H

/* Use the uuid library configured for mdcm.  */
#include "mdcmTypes.h"
#ifdef MDCM_USE_SYSTEM_UUID
# include <uuid/uuid.h>
#else
# include <mdcmuuid/uuid.h>
#endif

#endif