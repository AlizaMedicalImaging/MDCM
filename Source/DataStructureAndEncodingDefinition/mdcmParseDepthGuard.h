#ifndef MDCMPARSEDEPTHGUARD_H
#define MDCMPARSEDEPTHGUARD_H

#include "mdcmTypes.h"
#include "mdcmParseException.h"

namespace mdcm
{

class MDCM_EXPORT ParseDepthException : public ParseException
{
public:
  using ParseException::ParseException;
};

class MDCM_EXPORT ParseDepthGuard
{
public:
  ParseDepthGuard();
  ~ParseDepthGuard();
private:
  ParseDepthGuard(const ParseDepthGuard &) = delete;
  ParseDepthGuard &operator=(const ParseDepthGuard &) = delete;
};

}

#endif
