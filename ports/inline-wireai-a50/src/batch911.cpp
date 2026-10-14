// batch911.cpp - residue-9 slice, two bodies read in full.
//  0x626e10 [cdecl: value (signed dword), output pointer; no pop; returns the byte count]: UTF-8 encoding of a code point.
//           negative: 0; < 0x80: 1 byte; < 0x800: 2; < 0x10000: 3; < 0x110000: 4; else 0.
//  0x4bb350 [thiscall, no args, returns this]: calls the base constructor 0x469870 on this, sets bit 5 of this+4, clears the dword
//           at this+0x44, and writes the vtable 0x692ce0 at this. 0x469870 is stood in.
#include "ff.h"

#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))

extern "C" void THISCALL ext_469870(void *self);   // base constructor (stood in)

// 0x626e10 (no name in the map).
s32 Utf8626e10(s32 v, u8 *out) {
  if (v < 0) return 0;
  if (v < 0x80) {
    out[0] = (u8)v;
    return 1;
  }
  if (v < 0x800) {
    out[0] = (u8)((v >> 6) | 0xc0);
    out[1] = (u8)((v & 0x3f) | 0x80);
    return 2;
  }
  if (v < 0x10000) {
    out[0] = (u8)((v >> 12) | 0xe0);
    out[1] = (u8)(((v >> 6) & 0x3f) | 0x80);
    out[2] = (u8)((v & 0x3f) | 0x80);
    return 3;
  }
  if (v < 0x110000) {
    out[0] = (u8)((v >> 18) | 0xf0);
    out[1] = (u8)(((v >> 12) & 0x3f) | 0x80);
    out[2] = (u8)(((v >> 6) & 0x3f) | 0x80);
    out[3] = (u8)((v & 0x3f) | 0x80);
    return 4;
  }
  return 0;
}
PCREG(626e10, Utf8626e10);

// 0x4bb350 (no name in the map).
static u8 *THISCALL Init4bb350(u8 *self) {
  ext_469870(self);
  U32(self, 4) |= 0x20;
  U32(self, 0x44) = 0;
  U32(self, 0) = 0x692ce0u;
  return self;
}
PCREG(4bb350, Init4bb350);
