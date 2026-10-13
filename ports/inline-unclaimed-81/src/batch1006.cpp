// batch1006.cpp - area 81 (residue 0), batch 1006: ZFFHeroMovementCloseCombat::WantControl(a1, a2, a3), 0x5e7cc0, thiscall, three stack arguments
// (not read), ret 0xc. No SEH frame. The hero (this+0x36d) vtable calls: 0x100, 0x50c, 0x504, 0x560; the chosen object's 0x350, 0x35c, 0x328 and
// 0x2e8. The name compare is strcmp against "MonkeyWrench" at 0x6ad8b4 (default name at 0x67c8e8 when the object's name pointer is null).
// Float constants of the exe: 0.1f at 0x67a284, 1024.0f at 0x678620.
#include "ff.h"

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

// strcmp() == 0 for the two NUL-terminated strings (the exe compares them two bytes at a time).
static bool sameName(const char *a, const char *b) {
  while (*a && *a == *b) {
    ++a;
    ++b;
  }
  return *a == *b;
}

// 0x5e7cc0 ZFFHeroMovementCloseCombat::WantControl(a1, a2, a3).
static u32 THISCALL wantControl(u8 *self, u32 a1, u32 a2, u32 a3) {
  u8 *hero = (u8 *)D(self, 0x36d);
  if (*(u8 *)(hero + 0x831)) {
    *(u8 *)(hero + 0x831) = 0;
    return 0;
  }
  if (*(u8 *)(self + 0x5ac))
    return 1;
  if (!D(hero, 0x85a))
    D(hero, 0x85a) = vcall<u32>(hero, 0x100, 0x6a6e88u);
  if (*(u8 *)(D(hero, 0x85a) + 0xb45))
    return 0;
  u8 a = *(u8 *)(hero + 0x66a);
  u8 d = *(u8 *)(hero + 0x66d);
  if (!a && !d)
    return 0;
  u8 bl = 0;
  bool handled = false;
  u8 *p = (u8 *)vcall<u32>(hero, 0x50c);
  if (p) {
    u8 *q = (u8 *)vcall<u32>(p, 0x350);
    if ((u8)vcall<u32>(q, 0x328)) {
      handled = true;
      if (!vcall<u32>(p, 0x35c) && !vcall<u32>(hero, 0x560, (u32)p))
        bl = 1;
    }
  }
  if (!handled) {
    u8 *r = (u8 *)vcall<u32>(hero, 0x504);
    if (!r) {
      bl = 1;
    } else {
      u8 *s = (u8 *)vcall<u32>(r, 0x2e8);
      const char *nm = D(s, 4) ? (const char *)D(s, 4) : (const char *)0x67c8e8;
      if (sameName(nm, (const char *)0x6ad8b4))
        bl = 1;
    }
  }
  if (!(d || (a && bl)))
    return 0;
  if (D(hero, 0x417) & 0xe000000)
    return 0;
  if (*(u8 *)(hero + 0x7f0))
    return 0;
  float v = *(float *)(hero + 0x813) + 0.1f;
  v *= 1024.0f;
  int n = (int)v;
  u8 *sys = *(u8 **)0x70039c;
  return (u32)(n <= (int)D(sys, 0x40));
}
PCREG(5e7cc0, wantControl);
