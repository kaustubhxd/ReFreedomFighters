// batch982.cpp - area 56 band, claim A48 (0x5368a0): chained virtual calls with a zero test on call + field.
#include "ff.h"

typedef u32(THISCALL *Slot1)(u8 *, u32);

static u32 callSlot5368a0(u8 *self, u32 a, u32 slot) {
  u8 *vt = *(u8 **)self;
  return ((Slot1)(*(u32 *)(vt + slot)))(self, a);
}

// A48 0x5368a0: f = this->5302; if f == 0 return 0; s = call(0x6c) + f, call(0x68) + f, call(0x64) + f, call(0x5c) + f, return the
// first nonzero; v = call(0x1d0); if v return v; return call(0x1cc).
static u32 THISCALL f5368a0(u8 *self, u32 a) {
  if (*(u32 *)(self + 0x5302) == 0) return 0;
  u32 s;
  s = callSlot5368a0(self, a, 0x6c) + *(u32 *)(self + 0x5302);
  if (s) return s;
  s = callSlot5368a0(self, a, 0x68) + *(u32 *)(self + 0x5302);
  if (s) return s;
  s = callSlot5368a0(self, a, 0x64) + *(u32 *)(self + 0x5302);
  if (s) return s;
  s = callSlot5368a0(self, a, 0x5c) + *(u32 *)(self + 0x5302);
  if (s) return s;
  u32 v = callSlot5368a0(self, a, 0x1d0);
  if (v) return v;
  return callSlot5368a0(self, a, 0x1cc);
}
PCREG(5368a0, f5368a0);
