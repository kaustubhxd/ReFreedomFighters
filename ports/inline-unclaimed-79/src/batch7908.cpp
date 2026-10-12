#include "ff.h"
// batch7908.cpp - unclaimed-79 batch 8 (docs/20-unclaimed-79.md). Name from the GC name map (naming only).
// PlayAnimation 0x5dd470 runs as original code here (stubbed by the harness).

extern "C" void THISCALL ext_5dd470(u8 *self, u8 *obj, u8 *sym);

// 0x5dd2a0, ZFFMortar::FrameUpdate() (high). Plain ret, thiscall.
static void THISCALL mortarFrameUpdate(u8 *self) {
  if (self[0x75] == 0 || self[0x76] == 0 || self[0x77] == 0 || self[0x78] == 0 || self[0x79] == 0)
    return;
  if (vcall<u8, u32, u32>(*(u8 **)(self + 0x65), 0x23c, 0x6b6db4u, 0u) != 0)
    return;
  if (vcall<u8, u32, u32>(*(u8 **)(self + 0x69), 0x23c, 0x6b6dc0u, 0u) != 0)
    return;
  if (vcall<u8, u32, u32>(*(u8 **)(self + 0x6d), 0x23c, 0x6b6dd8u, 0u) != 0)
    return;
  if (vcall<u8, u32, u32>(*(u8 **)(self + 0x71), 0x23c, 0x6b6df0u, 0u) != 0)
    return;
  u8 *t = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *o = vcall<u8 *, u32>(t, 0x58, *(u32 *)(self + 0x5d));
  vcall<void, u32>(o, 0xbc, 0u);
  ext_5dd470(self, *(u8 **)(self + 0x65), (u8 *)0x6b6db4u);
  ext_5dd470(self, *(u8 **)(self + 0x69), (u8 *)0x6b6dc0u);
  ext_5dd470(self, *(u8 **)(self + 0x6d), (u8 *)0x6b6dd8u);
  ext_5dd470(self, *(u8 **)(self + 0x71), (u8 *)0x6b6df0u);
  u8 *o44 = *(u8 **)(self + 0x44);
  u32 id = (u32)(u16)vcall<u32, u32, u32, u32, u32>(t, 0x114, 0x682e18u, 0u, 0x6b6d70u, 0x8eu);
  vcall<void, u32, u32, u32>(o44, 0x138, id, 0u, 0u);
}
PCREG(5dd2a0, mortarFrameUpdate);
