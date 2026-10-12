// batch1608.cpp - unclaimed-16 batch 8 (docs/20-unclaimed-16.md): 0x47bc70. The GC name map calls it
// ZActor::GetActorRootTM(float*, float*) const (low), but the body WRITES to the object, so the name is a GUESS
// (SetRootMatrixAndPos). If the byte at this+0x5d2 is nonzero: copies 36 bytes from arg1 to this+0x5e7 (exe helper
// 0x4de420, a plain 36-byte copy, done inline here) and the three dwords at arg2 to this+0x5db, 0x5df, 0x5e3.
#include "ff.h"

typedef u32(THISCALL *FnR0)(void *);
typedef void(THISCALL *FnV2)(void *, u32, u32);

// 0x47bc70, GUESS name (see above): ret 8. If the byte at this+0x5d2 is zero: r = slot 0x20 of this (no arguments),
// then the exe tail-jumps to slot 0x7c of r with the original two arguments.
static void THISCALL actorSetRootMatrixAndPos(u8 *self, u32 a1, u32 a2) {
  if (self[0x5d2] == 0) {
    u32 *vt = *(u32 **)self;
    u8 *r = (u8 *)(u32)((FnR0)vt[0x20 / 4])(self);
    u32 *rvt = *(u32 **)r;
    ((FnV2)rvt[0x7c / 4])(r, a1, a2);
    return;
  }
  u32 *src = (u32 *)a1;
  u32 *dst = (u32 *)(self + 0x5e7);
  for (int i = 0; i < 9; i++)
    dst[i] = src[i];
  u32 *pos = (u32 *)a2;
  *(u32 *)(self + 0x5db) = pos[0];
  *(u32 *)(self + 0x5df) = pos[1];
  *(u32 *)(self + 0x5e3) = pos[2];
}
PCREG(47bc70, actorSetRootMatrixAndPos);
