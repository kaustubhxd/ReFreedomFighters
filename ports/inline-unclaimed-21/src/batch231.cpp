// batch231.cpp - small leaves, slice 0/1. 0x5ef880 (name GUESS): thiscall(a1, a2, a3, a4) (ret 0x10). Stores words into
// this (+0xb7 word a3, +0xb9 word a4, +0xbb a1, +0xbf a2). If byte [this+0xb6]: 0x5ac600([this+0xa9], a1, a2, a3+3, a4+0x23)
// and ed = 0x10; else ed = 0x20. Then 0x5ac600([this+0xa1], a1, a2, a3+3, a4+ed+3) and 0x5ac600([this+0xa5], a1, a2, a3+3,
// a4+ed-0xd). If o = [this+0xb1]: 0x5edb70(o, a1, a2, a3-3, a4, -1) (ret 0x14) and o->vt[8](o). Both callees stubbed.
// The original's argument order (pushes) is reproduced: the first parameter is the last pushed.
#include "ff.h"

extern "C" void THISCALL ext_5ac600(u8 *self, u32 p1, u32 p2, u32 p3, u32 p4);       // stubbed, ret 0x10
extern "C" void THISCALL ext_5edb70(u8 *self, u32 p1, u32 p2, u32 p3, u32 p4, u32 p5); // stubbed, ret 0x14

typedef u32(THISCALL *SlotNone)(u8 *);
static u32 vslot13(u8 *obj, u32 off) { return *(u32 *)(*(u32 *)obj + off); }

static void THISCALL setRanges_5ef880(u8 *self, u32 a1, u32 a2, u32 a3, u32 a4) {
  u32 ed = 0x20;
  *(u16 *)(self + 0xb7) = (u16)a3;
  *(u16 *)(self + 0xb9) = (u16)a4;
  *(u32 *)(self + 0xbb) = a1;
  *(u32 *)(self + 0xbf) = a2;
  if (*(u8 *)(self + 0xb6)) {
    ext_5ac600(*(u8 **)(self + 0xa9), a1, a2, a3 + 3, a4 + 0x23);
    ed = 0x10;
  }
  ext_5ac600(*(u8 **)(self + 0xa1), a1, a2, a3 + 3, a4 + ed + 3);
  ext_5ac600(*(u8 **)(self + 0xa5), a1, a2, a3 + 3, a4 + ed - 0xd);
  u8 *o = *(u8 **)(self + 0xb1);
  if (o) {
    ext_5edb70(o, a1, a2, a3 - 3, a4, (u32)-1);
    u8 *q = *(u8 **)(self + 0xb1);
    ((SlotNone)vslot13(q, 8))(q);
  }
}
PCREG(5ef880, setRanges_5ef880);
