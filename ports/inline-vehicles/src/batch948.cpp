// batch948.cpp - vehicles thread, batch 948: ZTank::Save(ZSaveGame*), 0x5213f0, callee pops 4, returns bool.
// ZVehicle::Save (0x515b70, exe) first; on failure return 0. Then the save-object slots in order:
// 0x68 (+0x2d8, +0x2e4), 0x4c (+0x2f0), 0x10 (+0x2f4, 4 bytes), 0x4c (+0x2f8), 0x60 byte (+0x2fc), the undercarriage save
// 0x528c80 (this+0x2fd, stood in), 0x4c (+0x25cd), 0x64 (+0x25d1), 0x3c (+0x25d5, +0x25d9), 0x64 (+0x25dd, +0x25e1),
// 0x68 (+0x25e5, +0x25f1, +0x25fd), 0x60 bytes (+0x2609, +0x260a, +0x260b), 0x3c (+0x260c, +0x2610), 0x44 (+0x2614),
// 0x4c (+0x2618), 0x44 (+0x2620), 0x68 (+0x2624, +0x2630), turret save 0x5274f0 (this+0x263c, stood in), 0x4c (+0x268d,
// +0x2691), 0x3c (+0x26e6), 0x60 byte (+0x2706), 0x3c (+0x26ea), second turret save 0x5274f0 (this+0x2695, stood in).
#include "ff.h"

extern "C" u8 THISCALL ext_515b70(void *self, void *sg);     // ZVehicle::Save (exe)
extern "C" void THISCALL ext_528c80(void *uc, void *sg);     // undercarriage save (stood in)
extern "C" void THISCALL ext_5274f0(void *tt, void *sg);     // turret save (stood in)

#define F(p, o) (*(float *)((u8 *)(p) + (o)))
#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x5213f0 ZTank::Save(ZSaveGame*).
static u8 THISCALL tankSave(u8 *s, void *sg) {
  if (!ext_515b70(s, sg))
    return 0;
  vcall<void>(sg, 0x68, (u32)(s + 0x2d8));
  vcall<void>(sg, 0x68, (u32)(s + 0x2e4));
  vcall<void>(sg, 0x4c, F(s, 0x2f0));
  vcall<void>(sg, 0x10, (u32)(s + 0x2f4), 4u);
  vcall<void>(sg, 0x4c, F(s, 0x2f8));
  vcall<void>(sg, 0x60, (u32)s[0x2fc]);
  ext_528c80(s + 0x2fd, sg);
  vcall<void>(sg, 0x4c, F(s, 0x25cd));
  vcall<void>(sg, 0x64, D(s, 0x25d1));
  vcall<void>(sg, 0x3c, D(s, 0x25d5));
  vcall<void>(sg, 0x3c, D(s, 0x25d9));
  vcall<void>(sg, 0x64, D(s, 0x25dd));
  vcall<void>(sg, 0x64, D(s, 0x25e1));
  vcall<void>(sg, 0x68, (u32)(s + 0x25e5));
  vcall<void>(sg, 0x68, (u32)(s + 0x25f1));
  vcall<void>(sg, 0x68, (u32)(s + 0x25fd));
  vcall<void>(sg, 0x60, (u32)s[0x2609]);
  vcall<void>(sg, 0x60, (u32)s[0x260a]);
  vcall<void>(sg, 0x60, (u32)s[0x260b]);
  vcall<void>(sg, 0x3c, D(s, 0x260c));
  vcall<void>(sg, 0x3c, D(s, 0x2610));
  vcall<void>(sg, 0x44, D(s, 0x2614));
  vcall<void>(sg, 0x4c, F(s, 0x2618));
  vcall<void>(sg, 0x44, D(s, 0x2620));
  vcall<void>(sg, 0x68, (u32)(s + 0x2624));
  vcall<void>(sg, 0x68, (u32)(s + 0x2630));
  ext_5274f0(s + 0x263c, sg);
  vcall<void>(sg, 0x4c, F(s, 0x268d));
  vcall<void>(sg, 0x4c, F(s, 0x2691));
  vcall<void>(sg, 0x3c, D(s, 0x26e6));
  vcall<void>(sg, 0x60, (u32)s[0x2706]);
  vcall<void>(sg, 0x3c, D(s, 0x26ea));
  ext_5274f0(s + 0x2695, sg);
  return 1;
}
PCREG(5213f0, tankSave);
