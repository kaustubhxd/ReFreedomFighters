#include "ff.h"
// batch7912.cpp - unclaimed-79 batch 12 (docs/20-unclaimed-79.md). Name from the GC name map (naming only).
// SEH frame not reproduced (fs:[0] writes not compared). The callees run as original code (stubbed by the harness):
// the allocator, the REFTAB constructor, and ZFFSearchLightGroup::LoadSpot (0x5c73f0, thiscall, two arguments).

extern "C" void *ext_41e290(u32 size);                       // cdecl allocator (caller pops)
extern "C" u32 THISCALL ext_4ccbe0(u8 *self, u32 a, u32 b);  // REFTAB::REFTAB(int, int): arguments (1, 0)
extern "C" void THISCALL ext_5c73f0(u8 *self, u8 *spot, u8 *ld);

// 0x5c7220, ZFFSearchLightGroup::Load(ZLoadGame*) (high). Thiscall, one stack argument (ret 4).
static void THISCALL searchLightGroupLoad(u8 *self, u8 *ld) {
  u32 t14 = 0, c10 = 0;
  *(u32 *)(self + 4) &= 0xffffffbfu;
  vcall<void, u32 *>(ld, 0x40, &t14);
  *(u32 *)(self + 0x48) = vcall<u32, u32>(*(u8 **)(G(u8 *, 0x70039c) + 0x9b), 0x58, t14);
  vcall<void, u32 *>(ld, 0x40, (u32 *)(self + 0x4c));
  vcall<void, u32>(ld, 0x70, *(u32 *)(self + 0x50));
  vcall<void, u32>(ld, 0x70, *(u32 *)(self + 0x54));
  vcall<void, u32>(ld, 0x70, *(u32 *)(self + 0x5c));
  vcall<void, u32 *>(ld, 0x40, (u32 *)(self + 0x64));
  vcall<void, u8 *>(ld, 0x68, self + 0x68);
  vcall<void, u8 *>(ld, 0x50, self + 0x69);
  vcall<void, u8 *>(ld, 0x50, self + 0x6d);
  vcall<void, u8 *>(ld, 0x50, self + 0x71);
  vcall<void, u32 *>(ld, 0x48, &c10);
  for (s32 i = 0; i < (s32)c10; ++i) {
    u8 *a = (u8 *)ext_41e290(0x2du);
    u8 *bm = (u8 *)ext_41e290(0x1cu);
    *(u32 *)(a + 4) = bm != 0 ? ext_4ccbe0(bm, 1u, 0u) : 0u;
    u8 *cm = (u8 *)ext_41e290(0x1cu);
    *(u32 *)(a + 0xc) = cm != 0 ? ext_4ccbe0(cm, 1u, 0u) : 0u;
    u8 *dm = (u8 *)ext_41e290(0x1cu);
    *(u32 *)(a + 8) = dm != 0 ? ext_4ccbe0(dm, 1u, 0u) : 0u;
    u8 *em = (u8 *)ext_41e290(0x1cu);
    *(u32 *)(a + 0x10) = em != 0 ? ext_4ccbe0(em, 1u, 0u) : 0u;
    ext_5c73f0(self, a, ld);
    vcall<void, u8 *>(*(u8 **)(self + 0x60), 0x4, a);
  }
}
PCREG(5c7220, searchLightGroupLoad);
