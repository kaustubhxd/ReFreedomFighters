// batch1225.cpp - pathfinding tree: ZPathfinder3::ClassFrameUpdate() [map high; ; source lines 0x259 / 0x260]
// and ZPFOctree_packed::ZPFOctree_packed() [map low; ].
#include "pf.h"

extern "C" void THISCALL ext_52c000(void *self, u32 flag);   // ZPathfinder3::ProcessQueue(bool)

#define ENGINE_FILE ((const char *)0x67a7f8)   // E:\p4\...\engine\system... (the profiler source file)
#define PROFILE_NAME ((const char *)0x6a0f48)  // "Pathfinder"

// 0x52ab00 ZPathfinder3::ClassFrameUpdate(). thiscall, ret 0. Profiling wrapper: when the two frame-time floats in the
// engine object (+0x9c3, +0x9c7) are both non-zero (NaN counts as non-zero: ucomiss + jnp), the frame's clock is reported (vtable +0x178 with the 64-bit time and
// the name "Pathfinder"), the queue is processed, and the clock is reported again (vtable +0x17c).
static void THISCALL classFrameUpdate(u8 *self) {
  u8 *eng = G(u8 *, 0x70039c);
  if (*(float *)(eng + 0x9c7) != 0.0f && *(float *)(eng + 0x9c3) != 0.0f) {
    u64 t = vcall<u64>(eng, 0x1c8, ENGINE_FILE, 0x259);
    vcall<void>(eng, 0x178, (u32)t, (u32)(t >> 32), PROFILE_NAME);
  }
  ext_52c000(self, 0);
  eng = G(u8 *, 0x70039c);
  if (*(float *)(eng + 0x9c7) != 0.0f && *(float *)(eng + 0x9c3) != 0.0f) {
    u64 t = vcall<u64>(eng, 0x1c8, ENGINE_FILE, 0x260);
    vcall<void>(eng, 0x17c, (u32)t, (u32)(t >> 32), PROFILE_NAME);
  }
}
PCREG(52ab00, classFrameUpdate);

// 0x52cfd0 ZPFOctree_packed::ZPFOctree_packed() [map low; ]. thiscall, no args, returns this in eax.
// Sets the vtable and the defaults of the packed octree: 1 in the eight u16 counters at +0x58..+0x86, 0x14e20 at +0x50,
// zero for the pointers and counts that Init and SerializeData fill later.
static u8 *THISCALL octreeCtor(u8 *self) {
  *(u32 *)self = 0x6a1414;
  *(u16 *)(self + 0x58) = 1;
  *(u16 *)(self + 0x5e) = 1;
  *(u16 *)(self + 0x64) = 1;
  *(u16 *)(self + 0x6a) = 1;
  *(u16 *)(self + 0x70) = 1;
  *(u16 *)(self + 0x76) = 1;
  *(u16 *)(self + 0x80) = 1;
  *(u16 *)(self + 0x86) = 1;
  *(u16 *)(self + 0x96) = 0;
  *(u32 *)(self + 0x98) = 0;
  *(u16 *)(self + 4) = 0;
  *(u32 *)(self + 0x50) = 0x14e20;
  *(u32 *)(self + 0x54) = 0;
  *(u32 *)(self + 0x5a) = 0;
  *(u32 *)(self + 0x60) = 0;
  *(u32 *)(self + 0x66) = 0;
  *(u32 *)(self + 0x6c) = 0;
  *(u32 *)(self + 0x72) = 0;
  *(u32 *)(self + 0x78) = 0;
  *(u32 *)(self + 0x82) = 0;
  *(u32 *)(self + 0x88) = 0;
  *(u32 *)(self + 0x8c) = 0;
  *(u32 *)(self + 0x90) = 0;
  *(u32 *)(self + 0x7c) = 0;
  return self;
}
PCREG(52cfd0, octreeCtor);
