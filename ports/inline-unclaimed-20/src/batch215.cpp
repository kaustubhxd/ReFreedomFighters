// batch215.cpp - gameplay-CORE function from decomp-pilot/core-todo/residue-19.txt (area 20, slice 19).
#include "ff.h"

typedef float(THISCALL *VtFloat)(u8 *, u32, u32);   // render manager slot 0x1c0: two stack words, float in st0

// 0x5dcc70, thiscall(): t = rm->vtable[0x1c0](rm, 0x6b6c28, 0x85) (rm = [0x70039c]); [this+0x4c] = [this+0x5c] + t * [this+0x60].
// The asm multiplies in x87 at 53-bit precision and stores the product as a float before the add, which matches
// single-precision multiply then add.
static void THISCALL initFlakFloat_5dcc70(u8 *self) {
  u8 *rm = *(u8 **)0x70039cu;
  VtFloat f = (VtFloat)(*(u32 *)(*(u32 *)rm + 0x1c0));
  float t = f(rm, 0x6b6c28u, 0x85u);
  float prod = t * *(float *)(self + 0x60);
  *(float *)(self + 0x4c) = *(float *)(self + 0x5c) + prod;
}
PCREG(5dcc70, initFlakFloat_5dcc70);
