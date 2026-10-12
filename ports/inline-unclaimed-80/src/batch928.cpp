#include "ff.h"
// batch928.cpp - unclaimed-80 claim 8 (docs/20-unclaimed-80.md). CAction::Run(unsigned int) (0x4a18b0, GC map name). All calls
// are virtual. The argument is the value passed in (a1).
//   b = sub-object (global 0x70039c, +0x9b) slot +0x58 with a1 (one argument)
//   if not this slot +0x84 with b (returns al, one argument): return
//   if this+0x48 == 7: ax = sub slot +0x114 with (0x68f908, 0, 0x68f6b4, 0x685, this) (five arguments); obj(+0x44) slot +0x130
//        with (b, ax) (two arguments); then the common tail below
//   common tail when this+0x48 is 6 or 7: ptr = this+0x4e (dword), w = this+0x4c (word): if both nonzero, obj(+0x44) slot
//        +0x12c with (ptr, w, a1) (three arguments)
//   otherwise: if b slot +0x1e0 with 0x200074 (one argument) returns nonzero, b slot +0x42c with this (one argument; the exe
//        keeps this in edi on this path, not a1)

static void THISCALL actionRun(u8 *self, u32 a1) {
  u8 *sub = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  typedef u32(THISCALL * r1_fn)(u8 *, u32);
  u8 *b = (u8 *)((r1_fn)(*(u32 *)(*(u32 *)sub + 0x58)))(sub, a1);
  typedef u8(THISCALL * al1_fn)(u8 *, u32);
  if (((al1_fn)(*(u32 *)(*(u32 *)self + 0x84)))(self, (u32)b) == 0)
    return;
  typedef void(THISCALL * v2_fn)(u8 *, u32, u32);
  typedef void(THISCALL * v3_fn)(u8 *, u32, u32, u32);
  typedef u32(THISCALL * r5_fn)(u8 *, u32, u32, u32, u32, u32);
  u32 t48 = *(u32 *)(self + 0x48);
  typedef void(THISCALL * v1_fn)(u8 *, u32);
  if (t48 == 7) {
    u16 ax = (u16)((r5_fn)(*(u32 *)(*(u32 *)sub + 0x114)))(sub, 0x68f908u, 0u, 0x68f6b4u, 0x685u, (u32)self);
    u8 *obj = *(u8 **)(self + 0x44);
    ((v2_fn)(*(u32 *)(*(u32 *)obj + 0x130)))(obj, (u32)b, (u32)ax);
    u32 ptr = *(u32 *)(self + 0x4e);
    u32 w = *(u16 *)(self + 0x4c);
    if (ptr == 0 || w == 0)
      return;
    ((v3_fn)(*(u32 *)(*(u32 *)obj + 0x12c)))(obj, ptr, w, a1);
    return;
  }
  if (t48 == 6) {
    u32 ptr = *(u32 *)(self + 0x4e);
    u32 w = *(u16 *)(self + 0x4c);
    if (ptr != 0 && w != 0) {
      u8 *obj = *(u8 **)(self + 0x44);
      ((v3_fn)(*(u32 *)(*(u32 *)obj + 0x12c)))(obj, ptr, w, a1);
      return;
    }
  }
  // fallback: the exe keeps this (not a1) in edi here
  if (((al1_fn)(*(u32 *)(*(u32 *)b + 0x1e0)))(b, 0x200074u) != 0)
    ((v1_fn)(*(u32 *)(*(u32 *)b + 0x42c)))(b, (u32)self);
}
PCREG(4a18b0, actionRun);
