#include "mdcmParseDepthGuard.h"
#include "mdcmTrace.h"

namespace
{
constexpr unsigned int parse_depth_limit = 99;
thread_local unsigned int parse_depth = 0;
}

namespace mdcm
{

ParseDepthGuard::ParseDepthGuard()
{
  // Check before incrementing: failed construction needs no counter cleanup,
  // and the counter cannot wrap past the limit.
#if 0
  std::cout << "ParseDepthGuard: parse_depth (before increment) = " << parse_depth << std::endl;
#endif
  if (parse_depth >= parse_depth_limit)
  {
    mdcmAlwaysWarnMacro("Nesting depth limit (" << parse_depth_limit << ") exceeded while parsing data set");
    throw ParseDepthException("");
  }
  ++parse_depth;
}

ParseDepthGuard::~ParseDepthGuard()
{
  assert(parse_depth > 0);
  --parse_depth;
}

}
