// batch6490.cpp - unclaimed-68 batch 49 (claim 49, gap band). Name from the GC name map (high).
#include "ff.h"

typedef u8 *(THISCALL *VEng138)(u8 *self);
typedef void(THISCALL *VR88)(u8 *self, u32 name, u32 *out);
typedef u32(THISCALL *VEng58)(u8 *self, u32 a);

// 0x4a8d20, ZSIGTE::GetpCUI() (high): thiscall, ret 0 (the result in EAX). With the cache at this+0xc9 zero, the engine's slot +0x138 gives r, r's
// slot +0x88 fills the cache through an out pointer (argument order: 0x68be98, then the pointer). The result is the engine's slot +0x58 applied to the
// cache when it is nonzero; zero otherwise.
static u32 THISCALL sigteGetpCUI(u8 *self) {
  u8 *eng = G(u8 *, 0x70039c);
  if (*(u32 *)(self + 0xc9) == 0) {
    u8 *en = *(u8 **)(eng + 0x9b);
    u8 *r = ((VEng138)*(u32 *)(*(u8 **)en + 0x138))(en);
    u32 local = 0;
    ((VR88)*(u32 *)(*(u8 **)r + 0x88))(r, 0x68be98u, &local);
    *(u32 *)(self + 0xc9) = local;
  }
  u32 cache = *(u32 *)(self + 0xc9);
  if (cache == 0) return 0;
  u8 *en = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  return ((VEng58)*(u32 *)(*(u8 **)en + 0x58))(en, cache);
}
PCREG(4a8d20, sigteGetpCUI);
