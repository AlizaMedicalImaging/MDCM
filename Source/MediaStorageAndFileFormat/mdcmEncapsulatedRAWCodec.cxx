/*********************************************************
 *
 * MDCM
 *
 * github.com/issakomi
 *
 *********************************************************/

#include "mdcmEncapsulatedRAWCodec.h"
#include "mdcmTransferSyntax.h"
#include "mdcmByteSwap.h"
#include "mdcmDataElement.h"
#include "mdcmSequenceOfFragments.h"
#include <limits>
#include <sstream>
#include <cstring>

namespace mdcm
{

EncapsulatedRAWCodec::EncapsulatedRAWCodec() {}

EncapsulatedRAWCodec::~EncapsulatedRAWCodec() {}

bool
EncapsulatedRAWCodec::CanCode(TransferSyntax const & ts) const
{
  return (ts == TransferSyntax::EncapsulatedUncompressedExplicitVRLittleEndian);
}

bool
EncapsulatedRAWCodec::CanDecode(TransferSyntax const & ts) const
{
  return (ts == TransferSyntax::EncapsulatedUncompressedExplicitVRLittleEndian);
}

bool
EncapsulatedRAWCodec::Code(DataElement const & in, DataElement & out)
{
  return false;
}

bool
EncapsulatedRAWCodec::Decode(DataElement const & in, DataElement & out)
{
  return false;
}

bool
EncapsulatedRAWCodec::GetHeaderInfo(std::istream &, TransferSyntax & ts)
{
  ts = TransferSyntax::EncapsulatedUncompressedExplicitVRLittleEndian;
  return true;
}

bool
EncapsulatedRAWCodec::DecodeBytes(const char * inBytes, size_t inBufferLength, char * outBytes, size_t inOutBufferLength)
{
  return false;
}

bool
EncapsulatedRAWCodec::DecodeByStreams(std::istream & is, std::ostream & os)
{
  return ImageCodec::DecodeByStreams(is, os);
}

} // end namespace mdcm
