#include "ff.h"
// batch7903.cpp - unclaimed-79 batch 3 (docs/20-unclaimed-79.md). Name from the residue list (no GC conflict).
// Helpers 0x563610 and 0x573b20 (not lifted here) run as original code; the harness stubs them with loggers.

extern "C" void THISCALL ext_563610(u8 *self, u32 a);
extern "C" u32 THISCALL ext_573b20(u8 *self, u32 a1, u32 a2);

// 0x577d60, ZObjectives::LoadInit2() (residue list, no GC name). Thiscall, plain ret.
static void THISCALL objectivesLoadInit2(u8 *self) {
  u8 *sys = G(u8 *, 0x70039c);
  u8 *t = *(u8 **)(sys + 0x9b);
  u8 *esi = (u8 *)vcall<u32>(t, 0x138);
  u32 v1 = vcall<u32, u32>(t, 0x4c, *(u32 *)(self + 0x44));
  vcall<void, u32, u32, u32>(esi, 0x60, 0x6a8fe8u, v1, 0x10u);
  u8 *esi2 = *(u8 **)(self + 0x94);
  if (esi2 != 0)
    *(u32 *)(esi2 + 0x132a7) = vcall<u32, u32>(t, 0x4c, *(u32 *)(self + 0x44));
  ext_563610(self, 0x6a98f4u);
  *(u32 *)(self + 0x20b) = ext_573b20(self, *(u32 *)(self + 0x1d4), 0x6a9900u);
  *(u32 *)(self + 0x5c) = vcall<u32, u32, u32>(*(u8 **)(self + 0x1dc), 0x25c, 0x6a92f8u, 0u);
  vcall<void, u32>(*(u8 **)(self + 0x1d8), 0xbc, 1u);
  vcall<void, u32>(*(u8 **)(self + 0x1d0), 0xbc, 1u);
}
PCREG(577d60, objectivesLoadInit2);
