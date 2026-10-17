// batch428.cpp - residue 2 row 0x4b5ca0 (thiscall, no arguments; nested vtable calls).
// Get engine = [0x70039c]; obj = [engine+0x9b]; call slot 0x138 with ECX = obj (no args),
// returns r1. Set local buffer [ebp-4] = 0. Call slot 0x88 with ECX = r1 (thiscall, two stack args:
// local buffer, 0x69206c). Get obj2 = [[0x70039c]+0x9b]. Call slot 0x58 with ECX = obj2
// (thiscall, one stack arg: [ebp-4] from previous call). Store result at [this+0x12a].
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" void THISCALL ext_unknown(void);  // placeholder for called functions

static void THISCALL nestedVtableCalls(u8 *self) {
  u32 engine = G(u32, 0x70039c);
  u32 obj = U32((u8 *)(unsigned long)engine, 0x9b);
  u32 r1 = vcall<u32>((void *)(unsigned long)obj, 0x138);

  u32 buf = 0;
  u32 val = 0x69206c;
  u32 result = vcall<u32>((void *)(unsigned long)r1, 0x88, val, (u32)&buf);

  u32 obj2 = U32((u8 *)(unsigned long)engine, 0x9b);
  u32 final = vcall<u32>((void *)(unsigned long)obj2, 0x58, buf);

  *(u32 *)((u8 *)self + 0x12a) = final;
}
PCREG(4b5ca0, nestedVtableCalls);
