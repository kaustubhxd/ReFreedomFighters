// batch5706.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 6: ZPlayer::CreateMovements() (0x482ac0), thiscall, no arguments,
// ret. (1) For each of the n = this+0x459 entries of the pointer array at this+0x45d: if the entry p is non-null, p->vt[+4](1).
// (2) 0x634d10(this+0x45d, 0, 0x80) (cdecl, a memset-like fill). (3) this->vt[+0x63c]() gives r, this->vt[+0x624](r); then
// this->vt[+0x62c]() -> this->vt[+0x624]; this->vt[+0x630]() -> +0x624; this->vt[+0x634]() -> +0x624; this->vt[+0x638]() -> +0x624.
// (4) this->vt[+0x644](2). The virtual slots and 0x634d10 are unverified callees: the slots are stubbed, and the fill is hooked in the
// spec to write the same zeros in both runs.
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef u32(THISCALL *SlotNone)(u8 *self);          // this->vt[slot]() -> value
typedef void(THISCALL *SlotOne)(u8 *self, u32 a);   // this->vt[slot](a)

extern "C" void *ext_634d10(void *p, int v, u32 n);  // memset-like fill, cdecl, original code (hooked in the spec)

// 0x482ac0, ZPlayer::CreateMovements() (high)
static void THISCALL playerCreateMovements(u8 *self) {
  u32 count = *(u32 *)(self + 0x459);
  for (u32 i = 0; i < *(u32 *)(self + 0x459); i++) {
    u8 *p = *(u8 **)(self + 0x45d + 4 * i);
    if (p) ((SlotOne)VT(p)[0x4 / 4])(p, 1);
  }
  (void)count;
  ext_634d10(self + 0x45d, 0, 0x80);
  u32 r = ((SlotNone)VT(self)[0x63c / 4])(self);
  ((SlotOne)VT(self)[0x624 / 4])(self, r);
  r = ((SlotNone)VT(self)[0x62c / 4])(self);
  ((SlotOne)VT(self)[0x624 / 4])(self, r);
  r = ((SlotNone)VT(self)[0x630 / 4])(self);
  ((SlotOne)VT(self)[0x624 / 4])(self, r);
  r = ((SlotNone)VT(self)[0x634 / 4])(self);
  ((SlotOne)VT(self)[0x624 / 4])(self, r);
  r = ((SlotNone)VT(self)[0x638 / 4])(self);
  ((SlotOne)VT(self)[0x624 / 4])(self, r);
  ((SlotOne)VT(self)[0x644 / 4])(self, 2);
}
PCREG(482ac0, playerCreateMovements);
