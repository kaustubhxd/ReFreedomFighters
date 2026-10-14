// batch987.cpp - residue-11 (core todo), batch 987: ZActor::ActivateAnimSegment(AnimHeader*, int, float, float, float), 0x477670,
// thiscall, five stack args, ret 0x14; returns the EAX of the tail call 0x461250 (stood in). h = 0: return 0. When [this+0x726] is set and
// [h+0x7c] has 0x40: [this+0x64c] == 10 returns 0; otherwise, when flags has bit 4 or the squared length of h's (+0x70,+0x74,+0x78) is
// above 2^-13 (constant at 0x679540): vslot 0x628(2, 1, 0), [this+0x726] = 0, r = vslot 0x588(), vslot 0x62c(r != 0). Then the tail
// 0x461250(h, flags, a, b, c).
#include "ff.h"

extern "C" u32 THISCALL ext_461250(void *self, u8 *h, u32 flags, float a, float b, float c);   // stood in

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define F(p, o) (*(float *)((u8 *)(p) + (o)))

// 0x477670 ZActor::ActivateAnimSegment(AnimHeader*, int, float, float, float).
static u32 THISCALL activateAnimSegment(u8 *t, u8 *h, u32 flags, float a, float b, float c) {
  if (!h)
    return 0;
  if (t[0x726] && (h[0x7c] & 0x40)) {
    if (D(t, 0x64c) == 0xa)
      return 0;
    bool go = (flags & 4) != 0;
    if (!go) {
      float s = F(h, 0x70) * F(h, 0x70);
      float s1 = F(h, 0x74) * F(h, 0x74);
      float s2 = F(h, 0x78) * F(h, 0x78);
      float sum = (s + s1) + s2;
      go = sum > *(float *)0x679540;
    }
    if (go) {
      vcall<void>(t, 0x628, 2u, 1u, 0u);
      t[0x726] = 0;
      u32 r = vcall<u32>(t, 0x588);
      vcall<void>(t, 0x62c, r != 0 ? 1u : 0u);
    }
  }
  return ext_461250(t, h, flags, a, b, c);
}
PCREG(477670, activateAnimSegment);
