// batch5830.cpp - residue 9, 0x5eaf50 (ZFFActorActionThrow::~ZFFActorActionThrow(), gc name map), thiscall, one stack argument (flags), ret 4, returns this.
// this->vtable = 0x685294; if (flags & 1): operator delete (0x634273, cdecl) with (this, 0x21). returns this.
#include "ff.h"

extern "C" void ext_634273(void *p, u32 size);  // operator delete (cdecl, two args), original code (hooked in the spec)

// 0x5eaf50, thiscall, one stack argument (ZFFActorActionThrow dtor)
static u8 *THISCALL unnamed5eaf50(u8 *self, u32 flags) {
  *(u32 *)self = 0x685294u;
  if (flags & 1) ext_634273(self, 0x21);
  return self;
}
PCREG(5eaf50, unnamed5eaf50);
