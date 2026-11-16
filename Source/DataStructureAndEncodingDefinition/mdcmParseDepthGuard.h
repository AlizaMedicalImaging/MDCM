#ifndef MDCMPARSEDEPTHGUARD_H
#define MDCMPARSEDEPTHGUARD_H

#include "mdcmTypes.h"

namespace mdcm
{

class MDCM_EXPORT ParseDepthGuard
{
public:
  ParseDepthGuard();
  ~ParseDepthGuard();
  ParseDepthGuard(const ParseDepthGuard &) = delete;
  ParseDepthGuard &operator=(const ParseDepthGuard &) = delete;
};

}

#endif
