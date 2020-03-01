/*=========================================================================

  Program: GDCM (Grassroots DICOM). A DICOM library

  Copyright (c) 2006-2011 Mathieu Malaterre
  All rights reserved.
  See Copyright.txt or http://gdcm.sourceforge.net/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#ifndef MDCM_CHARLS_H
#define MDCM_CHARLS_H

#include "mdcmTypes.h"
#ifdef MDCM_USE_SYSTEM_CHARLS
// version 2.0.0
# include <CharLS/charls.h>
# include <CharLS/publictypes.h>
# include <CharLS/util.h>
# include <CharLS/defaulttraits.h>
# include <CharLS/losslesstraits.h>
# include <CharLS/colortransform.h>
# include <CharLS/processline.h>
#else
#include "mdcmcharls/charls.h"
#include "mdcmcharls/publictypes.h"
#include "mdcmcharls/util.h"
#include "mdcmcharls/defaulttraits.h"
#include "mdcmcharls/losslesstraits.h"
#include "mdcmcharls/colortransform.h"
#include "mdcmcharls/processline.h"
#endif

#endif
