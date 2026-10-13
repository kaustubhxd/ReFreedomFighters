// batch8787.cpp - residue 6 batch 87 (GUESS names): FUN_004cd160, FUN_0042f820, FUN_0048cf20, FUN_004c91a0.
#include "ff.h"

extern "C" void __attribute__((cdecl)) ext_634273(void *p, u32 n);
extern "C" u8 THISCALL ext_4d3810(void *self, u32 a, u32 b);
extern "C" u8 THISCALL ext_496330(void *self, u32 a);
extern "C" u32 THISCALL ext_4e5e60(void *self);

// 0x4cd160 (GUESS FUN_004cd160): destructor body. Stores vtable 0x695b40 at this, then frees the pointer at this+4
// through the cdecl routine 0x634273 (pointer, 4). Plain ret.
static void THISCALL guess4cd160(u8 *self) {
  void *p = *(void **)(self + 4);
  *(u32 *)self = 0x695b40;
  ext_634273(p, 4);
}
PCREG(4cd160, guess4cd160);

// 0x42f820 (GUESS FUN_0042f820): stdcall, one argument. Returns 0x4d3810 on the global object 0x6ff938 with (a, 0).
static u8 STDCALL guess42f820(u32 a) {
  return ext_4d3810((void *)0x6ff938, a, 0);
}
PCREG(42f820, guess42f820);

// 0x48cf20 (GUESS FUN_0048cf20): q = the pointer at this+8; returns 0 when null, else tail-jumps to 0x496330 on q
// with the argument (ret 4 on both paths).
static u8 THISCALL guess48cf20(u8 *self, u32 a) {
  void *q = *(void **)(self + 8);
  if (!q)
    return 0;
  return ext_496330(q, a);
}
PCREG(48cf20, guess48cf20);

// 0x4c91a0 (GUESS FUN_004c91a0): thiscall, two arguments (the first unused, ret 8). Stores 0x4e5e60 on the second
// argument at this+0x48 and returns it.
static u32 THISCALL guess4c91a0(u8 *self, u32 a, u32 b) {
  (void)a;
  u32 v = ext_4e5e60((void *)b);
  *(u32 *)(self + 0x48) = v;
  return v;
}
PCREG(4c91a0, guess4c91a0);
