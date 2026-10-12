#include "ff.h"
// batch8027.cpp - unclaimed core row, parked then resumed (docs/20-unclaimed-79.md). Name GUESS (no GC name).

// 0x481800 (GUESS): thiscall (ret 4), one argument.
static void THISCALL f_481800(u8 *self, u32 arg) {
  u32 flags = *(u32 *)(self + 0x417);
  if ((flags & 0x1800) != 0) {
    u32 old = *(u32 *)(self + 0x413);
    *(u32 *)(self + 0x417) = flags & 0xffffe7ffu;
    u8 *sub = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u8 *b = vcall<u8 *, u32>(sub, 0x58, old);
    if (b != 0) {
      u32 ax = (u16)vcall<u32, u32, u32, u32, u32, u32, u32>(sub, 0x114, 0x68bedcu, 0u, 0x68bcbcu, 0x299u, 0u, 0u);
      vcall<void, u32>(b, 0x128, ax);
    }
    *(u32 *)(self + 0x413) = 0;
    if (arg != 0) vcall<void, u32>(self, 0x598, arg);
    return;
  }
  *(u32 *)(self + 0x413) = 0;
  if (arg == 0) return;
  if (vcall<u32>(self, 0x514) != 0) return;
  *(u32 *)(self + 0x417) |= 0x1000u;
  u8 *sub = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 ax = (u16)vcall<u32, u32, u32, u32, u32, u32>(sub, 0x114, 0x68bee8u, 0u, 0x68bcbcu, 0x290u, 9u);
  vcall<void, u32, u32>(self, 0x130, arg, ax);
  *(u32 *)(self + 0x413) = vcall<u32, u32>(sub, 0x4c, arg);
}
PCREG(481800, f_481800);
