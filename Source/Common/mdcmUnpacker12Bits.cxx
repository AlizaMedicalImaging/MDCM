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

#include "mdcmUnpacker12Bits.h"

namespace mdcm
{

// http://groups.google.com/group/comp.lang.c/msg/572bc9b085c717f3
bool Unpacker12Bits::Unpack(char * out, const char * in, size_t n)
{
  if (n % 3 != 0)
    return false; // 3 bytes are actually 2 words
  short * q = static_cast<short*>(static_cast<void*>(out));
  const unsigned char * p = reinterpret_cast<const unsigned char*>(in);
  const unsigned char * end = p + n;
  while (p != end)
  {
    const unsigned char b0 = *p++;
    const unsigned char b1 = *p++;
    const unsigned char b2 = *p++;
    *q++ = static_cast<short>(((b1 & 0xf) << 8) + b0);
    *q++ = static_cast<short>((b1 >> 4) + (b2 << 4));
  }
  return true;
}

#if 0
bool Unpacker12Bits::Pack(char * out, const char * in, size_t n)
{
  if (n % 4 != 0)
    return false; // need an even number of 'words' so that 2 words are split in 3 bytes
  unsigned char * q = reinterpret_cast<unsigned char*>(out);
  const unsigned short * p = static_cast<const unsigned short*>(static_cast<const void*>(in));
  const unsigned short * end = static_cast<const unsigned short*>(static_cast<const void*>(in + n));
  while (p != end)
  {
    const unsigned short b0 = *p++;
    const unsigned short b1 = *p++;
    *q++ = static_cast<unsigned char>(b0 & 0xff);
    *q++ = static_cast<unsigned char>((b0 >> 8) + ((b1 & 0xf) << 4));
    *q++ = static_cast<unsigned char>(b1 >> 4);
  }
  return true;
}
#endif

}
