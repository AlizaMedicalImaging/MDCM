#include "mdcmParseDepthGuard.h"
#include "mdcmParseException.h"
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
  if (parse_depth >= parse_depth_limit)
  {
    mdcmAlwaysWarnMacro("Nesting depth limit (" << parse_depth_limit << ") exceeded while parsing data set");
    throw ParseDepthException("Nesting depth limit exceeded");
  }
  ++parse_depth;
}

ParseDepthGuard::~ParseDepthGuard()
{
  assert(parse_depth > 0);
  --parse_depth;
}

}
