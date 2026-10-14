// batch939.cpp - three derived-class constructors from the area-50 label-D claim (top 95 by address), all read in full (2026-10-12).
//  Each is thiscall (ECX = this), two stack args (a, b), ret 8, returns this. Each calls the base ctor 0x5e0e10 (thiscall: this, a, b, ret 8;
//  verified in area 10 batch 6; stood in here), then stores its vtable word and its fields.
//  0x5e11c0: vtable 0x6b7964 at +0; byte 0 at +0x54c; dword 0 at +0x55c.
//  0x5e1200: vtable 0x6b77b4 at +0; byte 0 at +0x550; dword 0 at +0x565.
//  0x5e10a0: vtable 0x6b760c at +0; dword 0 at +0x54c; byte 0 at +0x550; byte 1 at +0x559; dwords 0 at +0x593, +0x597, +0x59b, +0x59f.
#include "ff.h"

#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))

extern "C" void THISCALL ext_5e0e10(void *self, u32 a, u32 b);   // base ctor, stood in (ret 8)

// 0x5e11c0 (no name in the map).
static u8 *THISCALL Ctor5e11c0(u8 *self, u32 a, u32 b) {
  ext_5e0e10(self, a, b);
  U32(self, 0) = 0x6b7964;
  U8(self, 0x54c) = 0;
  U32(self, 0x55c) = 0;
  return self;
}
PCREG(5e11c0, Ctor5e11c0);

// 0x5e1200 (no name in the map).
static u8 *THISCALL Ctor5e1200(u8 *self, u32 a, u32 b) {
  ext_5e0e10(self, a, b);
  U32(self, 0) = 0x6b77b4;
  U8(self, 0x550) = 0;
  U32(self, 0x565) = 0;
  return self;
}
PCREG(5e1200, Ctor5e1200);

// 0x5e10a0 (no name in the map).
static u8 *THISCALL Ctor5e10a0(u8 *self, u32 a, u32 b) {
  ext_5e0e10(self, a, b);
  U32(self, 0) = 0x6b760c;
  U32(self, 0x54c) = 0;
  U8(self, 0x550) = 0;
  U8(self, 0x559) = 1;
  U32(self, 0x593) = 0;
  U32(self, 0x597) = 0;
  U32(self, 0x59b) = 0;
  U32(self, 0x59f) = 0;
  return self;
}
PCREG(5e10a0, Ctor5e10a0);
