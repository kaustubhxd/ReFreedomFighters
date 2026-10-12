// batch6366.cpp - unclaimed-63 batch 66: 0x514600 ZMoveOnSpline::TargetValid(unsigned int) (core list name), stdcall-like, one stack
//   argument idx, ret 4, returns a bool (al).
//   db = [[0x70039c] + 0x9b]; r = db->vtbl[+0x58](idx) (thiscall, one argument, callee pops 4). If r == 0 return 0.
//   If r->vtbl[+0x1e0](0x200074) == 0 (thiscall, one argument) return 1.
//   If r->vtbl[+0x438]() != 0 (thiscall, no arguments) return 0.
//   Else return (~([[r+8] + 0x3c] >> 10)) & 1.
#include "ff.h"

typedef u8 (THISCALL * b1_fn)(void *, u32);
typedef u8 (THISCALL * b0_fn)(void *);
typedef u32 (THISCALL * q1_fn)(void *, u32);

// 0x514600.
static u8 STDCALL unnamed514600(u32 idx) {
  u32 db = *(u32 *)(G(u32, 0x70039c) + 0x9b);
  u32 r = ((q1_fn)(*(u32 *)(*(u32 *)db + 0x58)))((void *)db, idx);
  if (r == 0)
    return 0;
  if (((b1_fn)(*(u32 *)(*(u32 *)r + 0x1e0)))((void *)r, 0x200074u) == 0)
    return 1;
  if (((b0_fn)(*(u32 *)(*(u32 *)r + 0x438)))((void *)r) != 0)
    return 0;
  u32 flags = *(u32 *)(*(u32 *)(r + 8) + 0x3c);
  return (u8)((~(flags >> 10)) & 1u);
}
PCREG(514600, unnamed514600);
