// batch4144.cpp - unclaimed-41 batch 44 (core-todo residue-19): 0x4c5530 ZPathfinderControl::CopyData(ZEventBase*) (thiscall, one stack
// argument src, ret 4). SEH frame not reproduced (fs:[0] writes are not compared). The /GS cookie check is not reproduced.
#include "ff.h"

extern "C" u8 *__attribute__((cdecl)) ext_41e290(u32 size);      // allocator, one stack argument, caller pops (stub, GUESS)
extern "C" u32 THISCALL ext_4ccbe0(u8 *self, u32 a1, u32 a2);    // two stack arguments, callee pops; returns eax (stub, GUESS)

typedef u32(THISCALL * f1_t)(u8 *, u32);

static u32 vslot(u8 *o, u32 off) {
  return *(u32 *)(*(u8 **)o + off);
}

static void THISCALL fn4c5530(u8 *self, u8 *src) {
  *(u16 *)(self + 0x4c) = *(u16 *)(src + 0x4c);
  *(u16 *)(self + 0x4e) = *(u16 *)(src + 0x4e);
  *(u16 *)(self + 0x50) = *(u16 *)(src + 0x50);
  self[0x52] = src[0x52];

  u8 *R0 = *(u8 **)(self + 0x48);
  if (R0 != 0)
    ((f1_t)vslot(R0, 0))(R0, 1u);

  u8 *A = ext_41e290(0x1cu);
  u32 nr = 0;
  if (A != 0)
    nr = ext_4ccbe0(A, 2u, 0u);
  *(u32 *)(self + 0x48) = nr;

  u8 *R1 = *(u8 **)(src + 0x48);
  if (R1 != 0) {
    u32 l18 = 0;
    ((f1_t)vslot(R1, 0x4c))(R1, (u32)&l18);
    u32 x = ((f1_t)vslot(R1, 0x5c))(R1, (u32)&l18);
    while (l18 != 0) {
      u8 *R = *(u8 **)(self + 0x48);
      ((f1_t)vslot(R, 4))(R, x);
      x = ((f1_t)vslot(R1, 0x5c))(R1, (u32)&l18);
    }
  }
}
PCREG(4c5530, fn4c5530);
