// This is core/vil/vil_flipud.cxx
#ifdef VCL_NEEDS_PRAGMA_INTERFACE
#pragma implementation
#endif
//:
// \file
// \author fsm

#include "vil_flipud.h"
#include <vil/vil_flipud_impl.h>

vil_image vil_flipud(vil_image const &I) {
  return new vil_flipud_impl(I);
}
