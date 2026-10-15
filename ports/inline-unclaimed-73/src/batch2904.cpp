// batch2904.cpp - area 73 batch 4 (residue 12): CEnemyFlag::Init2() (0x5c17c0, docs/20-unclaimed-73.md).
#include "ff.h"

// 0x5c21e0: thiscall, one argument (original code, hooked in the spec).
extern "C" void THISCALL ext_5c21e0(u8 *self, u32 arg);

// 0x5c17c0, CEnemyFlag::Init2() (high), thiscall, plain ret. r = (g_sys+0x9b)+0xadc slot +0x25c(0x685f44, 0); when r is
// null, return. w = r slot +0x100(0x6a5cf0); this+0xec = w. Zero this+0xf4..0xfc; this+0x44 slot +0x84(this+0xf4).
// b = (g_sys+0x9b) slot +0x138(); local = 0; b slot +0x88(0x6a6700, &local); this+0x50 = (g_sys+0x9b) slot +0x58(local).
// c = (g_sys+0x9b) slot +0x138(); local = 0; c slot +0x88(0x6a5c48, &local); b2 = (g_sys+0x9b) slot +0x58(local).
// When b2 is non-null: local_c (uninitialised) comes from (g_sys+0x9b) slot +0x114(0x6a5c68, 0, 0x6b3a74, 0xf9, &local_c, 0)
// and b2 slot +0x128(low word of that result); when local_c is non-zero, ext_5c21e0(this, 0).
static void THISCALL enemyFlagInit2(u8 *self) {
  u8 *sys = G(u8 *, 0x70039c);
  u8 *ctl = *(u8 **)(sys + 0x9b);
  u8 *r = (u8 *)vcall<u32>(*(void **)(ctl + 0xadc), 0x25c, 0x685f44u, 0u);
  if (!r)
    return;
  u32 w = vcall<u32>(r, 0x100, 0x6a5cf0u);
  *(u32 *)(self + 0xec) = w;
  *(u32 *)(self + 0xf4) = 0;
  *(u32 *)(self + 0xf8) = 0;
  *(u32 *)(self + 0xfc) = 0;
  vcall<void>(*(void **)(self + 0x44), 0x84, (u32)(self + 0xf4));
  u8 *b = (u8 *)vcall<u32>(ctl, 0x138);
  u32 local = 0;
  vcall<void>(b, 0x88, 0x6a6700u, (u32)&local);
  *(u32 *)(self + 0x50) = vcall<u32>(ctl, 0x58, local);
  u8 *c = (u8 *)vcall<u32>(ctl, 0x138);
  local = 0;
  vcall<void>(c, 0x88, 0x6a5c48u, (u32)&local);
  u8 *b2 = (u8 *)vcall<u32>(ctl, 0x58, local);
  if (!b2)
    return;
  u32 local_c;
  u32 r114 = vcall<u32>(ctl, 0x114, 0x6a5c68u, 0u, 0x6b3a74u, 0xf9u, (u32)&local_c, 0u);
  vcall<void>(b2, 0x128, (u32)(u16)r114);
  if (local_c != 0)
    ext_5c21e0(self, 0u);
}
PCREG(5c17c0, enemyFlagInit2);
