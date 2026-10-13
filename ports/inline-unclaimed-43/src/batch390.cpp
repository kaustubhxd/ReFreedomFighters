// batch390.cpp - 0x410a00 (gap band). cdecl(a, b): returns 0x410a20(a, b, 1) (exe, cdecl, three arguments; tail forwarder).
#include "ff.h"

extern "C" u32 ext_410a20(void *p, void *out, u32 flag);   // stream entry pick (batch 389's function, exe code)

static u32 pickEntryForward(void *a, void *b) {
  return ext_410a20(a, b, 1u);
}
PCREG(410a00, pickEntryForward);
