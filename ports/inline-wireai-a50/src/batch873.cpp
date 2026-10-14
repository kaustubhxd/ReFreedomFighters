// batch873.cpp - area 50 (residue-09 candidate): 0x4e5f10 [35 instr, thiscall (the this is a pointer to a pointer), no args,
// returns an int in eax; GUESS "read a typed value from a variant record"]. The record's type byte (low 6 bits) minus one indexes a
// jump table (byte table at 0x4e5f7c, targets at 0x4e5f6c): case 0 truncates the double at +1, case 1 the float at +1, case 2 is the
// dword at +1, case 3 and out-of-range types return 0.
#include "ff.h"

// 0x4e5f10 (name GUESS).
static s32 THISCALL Value4e5f10(u8 **pp) {
  u8 *p = *pp;
  u32 idx = (u32)(p[0] & 0x3f) - 1;
  if (idx > 10) return 0;
  u8 kind = ((const u8 *)0x4e5f7c)[idx];   // the byte table in the image
  switch (kind) {
    case 0: {
      double d = *(double *)(p + 1);
      return (s32)d;
    }
    case 1: {
      float f = *(float *)(p + 1);
      return (s32)f;
    }
    case 2:
      return *(s32 *)(p + 1);
    default:
      return 0;
  }
}
PCREG(4e5f10, Value4e5f10);
