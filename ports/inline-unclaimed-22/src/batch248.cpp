// batch248.cpp - area 22 gameplay-core batch (docs/20-unclaimed-22.md, "Gameplay core, batch248"): ZPlayer::Load.
// Name from the GameCube name map (high); behaviour from the PC bytes.
#include "ff.h"

extern "C" u32 THISCALL ext_474770(u8 *self, u8 *l);   // original ZActor::Load (ret 4); al = success

// 0x483f20 ZPlayer::Load(ZLoadGame*) ret 4, returns al. ZActor::Load (0x474770) first; false: its eax is returned. Then 23
// field reads (slots 0x40, 0x48, 0x50, 0x68, 0x6c, 0x74), +0x439/+0x43d/+0x441 = 35.0, 100.0, 35.0, this->vt[0x628](), each
// non-null object in the 1-based table at +0x461 (count +0x459, unsigned, inclusive) loads with vt[0x38](l); +0x424 = 0,
// +0x412 = 1; true.
static u32 THISCALL playerLoad_483f20(u8 *self, u8 *l) {
  u32 ok = ext_474770(self, l);
  if (!(u8)ok) return ok;
  vcall<void>(l, 0x40, (u32)(self + 0x413));
  vcall<void>(l, 0x48, (u32)(self + 0x417));
  vcall<void>(l, 0x68, (u32)(self + 0x42c));
  vcall<void>(l, 0x6c, (u32)(self + 0x445));
  vcall<void>(l, 0x50, (u32)(self + 0x596));
  vcall<void>(l, 0x74, (u32)(self + 0x59a));
  vcall<void>(l, 0x6c, (u32)(self + 0x5be));
  vcall<void>(l, 0x74, (u32)(self + 0x4f5));
  vcall<void>(l, 0x6c, (u32)(self + 0x519));
  vcall<void>(l, 0x40, (u32)(self + 0x5ca));
  vcall<void>(l, 0x74, (u32)(self + 0x5ce));
  vcall<void>(l, 0x6c, (u32)(self + 0x5f2));
  vcall<void>(l, 0x68, (u32)(self + 0x5fe));
  vcall<void>(l, 0x68, (u32)(self + 0x5ff));
  vcall<void>(l, 0x68, (u32)(self + 0x601));
  vcall<void>(l, 0x68, (u32)(self + 0x600));
  vcall<void>(l, 0x48, (u32)(self + 0x602));
  vcall<void>(l, 0x48, (u32)(self + 0x606));
  vcall<void>(l, 0x48, (u32)(self + 0x60a));
  vcall<void>(l, 0x40, (u32)(self + 0x60e));
  vcall<void>(l, 0x50, (u32)(self + 0x4dd));
  *(u32 *)(self + 0x439) = 0x420c0000u;   // 35.0f
  *(u32 *)(self + 0x43d) = 0x42c80000u;   // 100.0f
  *(u32 *)(self + 0x441) = 0x420c0000u;   // 35.0f
  vcall<void>(self, 0x628);
  for (u32 i = 1; i <= *(u32 *)(self + 0x459); i++) {
    u8 *o = *(u8 **)(self + 0x461 + 4 * (i - 1));
    if (o) vcall<void>(o, 0x38, (u32)l);
  }
  *(u32 *)(self + 0x424) = 0;
  self[0x412] = 1;
  return 1;
}
PCREG(483f20, playerLoad_483f20);
