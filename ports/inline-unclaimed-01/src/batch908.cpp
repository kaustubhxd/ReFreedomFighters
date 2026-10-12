#include "ff.h"
// batch908.cpp - unclaimed-01 claim 7 (docs/20-unclaimed-01.md). ZActor::GetAnimOffset(const char*) (0x478b00, high).

// Calls vtable slot +0x21c with the name (thiscall, one argument). A zero result returns 0. Otherwise returns the result
// minus the dword at +0x44 of the object at +0x9b of the global object at 0x70039c.
static u32 THISCALL actorGetAnimOffset(u8 *self, const char *name) {
  typedef u32(THISCALL * slot_fn)(u8 *, const char *);
  slot_fn f = *(slot_fn *)(*(u32 *)self + 0x21c);
  u32 r = f(self, name);
  if (r == 0)
    return 0;
  u8 *g = G(u8 *, 0x70039c);
  u8 *m = *(u8 **)(g + 0x9b);
  return r - *(u32 *)(m + 0x44);
}
PCREG(478b00, actorGetAnimOffset);
