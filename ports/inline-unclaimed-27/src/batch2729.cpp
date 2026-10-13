#include "ff.h"
// batch2729.cpp - unclaimed-27 batch 31 (docs/20-unclaimed-27.md). FUN_59c4a0, name unknown (GUESS). No arguments, void.
typedef u32(THISCALL * slot94_fn)(u8 *);

static void funcResetAndStamp() {
  u8 *g = (u8 *)(unsigned long)G(u32, 0x70039c);
  *(float *)(g + 0x1b40) = 1.0f;
  u8 *eng = *(u8 **)(g + 0x9b);
  eng[0xbac] = 0;
  G(u32, 0x700324) = 0;
  u8 *o = *(u8 **)(g + 0x1aa3);
  u8 *r1 = (u8 *)(unsigned long)((slot94_fn)(*(u32 *)(*(u32 *)o + 0x94)))(o);
  *(u32 *)(r1 + 0xc) = 0;
  g = (u8 *)(unsigned long)G(u32, 0x70039c);
  o = *(u8 **)(g + 0x1aa3);
  u8 *r2 = (u8 *)(unsigned long)((slot94_fn)(*(u32 *)(*(u32 *)o + 0x94)))(o);
  *(float *)(r2 + 4) = 1.0f;
  G(u32, 0x6ffa60) = 0;
}
PCREG(59c4a0, funcResetAndStamp);
