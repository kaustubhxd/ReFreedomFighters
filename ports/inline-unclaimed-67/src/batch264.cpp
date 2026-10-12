// batch264.cpp - unclaimed area 67, slice floor(addr/16) mod 20 == 6 (FUN_ names; bodies from the PC bytes).
#include "ff.h"

typedef u32 (THISCALL *F1)(u8 *self, u32 a);
static inline u32 rdw(u32 p, u32 off) { return *(u32 *)(unsigned long)(p + off); }

// 0x4cf5a0, stdcall (ret 4, one argument p): returns p[0] + p[1] * 4 + 0x10.
static u32 STDCALL nestedSize(u32 p) { return rdw(p, 0) + rdw(p, 4) * 4 + 0x10; }
PCREG(4cf5a0, nestedSize);

// 0x4e68e0, thiscall, ret 4: lo = low32(arg * 0x9e3779b9); result = high32(lo * [this+8]) (unsigned).
static u32 THISCALL hashMix(u8 *self, u32 a) {
  u64 p1 = (u64)a * 0x9e3779b9u;
  u32 lo = (u32)p1;
  u64 p2 = (u64)lo * rdw((u32)(unsigned long)self, 8);
  return (u32)(p2 >> 32);
}
PCREG(4e68e0, hashMix);

// 0x4f6560, thiscall, ret 4: r = slot 0x280 of this (ECX = this) called with the argument; returns the byte at r+0xc.
static u32 THISCALL byteFromSlot280(u8 *selfP, u32 a) {
  u32 self = (u32)(unsigned long)selfP;
  u32 r = ((F1)rdw(rdw(self, 0), 0x280))(selfP, a);
  return *(u8 *)(unsigned long)(r + 0xc);
}
PCREG(4f6560, byteFromSlot280);
