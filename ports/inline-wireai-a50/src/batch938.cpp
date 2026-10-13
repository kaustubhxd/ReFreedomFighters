// batch938.cpp - 0x5135c0 ZMoveOnSpline::Load(ZLoadGame*) [thiscall (ECX = this), one stack arg (stream st), ret 4, returns al = 1]. Body read in
// full (2026-10-12). Gate 0x440e10 (thiscall: this, st; verified in batch918; stood in here): if false, return 0. Then 0x523710 (thiscall: ECX =
// this+0x5c, st; stood in), a long run of stream reads into this (slots 0x6c, 0x74, 0x50, 0x18 (ptr, 4), 0x68, 0x40, 0x48, 0x70), 0x511bc0
// (fastcall: ECX = st, EDX = this+0xda; stood in), 0x4e78c0 (thiscall: ECX = this+0x144, st; stood in), and three stream reads into a local L
// each followed by the manager (g+0x9b) slot +0x58 (L) stored at this+0x159, +0x1c1 and +0x1c5. The final call
// is this slot +0x2e4 (no args). Returns 1.
#include "ff.h"

#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" bool THISCALL ext_440e10(void *self, void *st);            // stood in (verified in batch918)
extern "C" void THISCALL ext_523710(void *self, void *st);            // stood in
extern "C" void FASTCALL ext_511bc0(void *st, void *ptr);             // stood in (ECX = st, EDX = pointer)
extern "C" void THISCALL ext_4e78c0(void *self, void *st);            // stood in

// 0x5135c0 (name in the map: ZMoveOnSpline::Load(ZLoadGame*)).
static u8 THISCALL Load5135c0(u8 *self, u8 *st) {
  if (!ext_440e10(self, st)) return 0;
  ext_523710((void *)U32(self, 0x5c), st);
  vcall<void>(st, 0x6c, (void *)(self + 0x60));
  vcall<void>(st, 0x74, (void *)(self + 0x6c));
  vcall<void>(st, 0x6c, (void *)(self + 0x90));
  vcall<void>(st, 0x74, (void *)(self + 0x9c));
  vcall<void>(st, 0x50, (void *)(self + 0xc0));
  vcall<void>(st, 0x18, (void *)(self + 0xc4), 4u);
  vcall<void>(st, 0x50, (void *)(self + 0xc8));
  vcall<void>(st, 0x68, (void *)(self + 0xcc));
  vcall<void>(st, 0x68, (void *)(self + 0xcd));
  vcall<void>(st, 0x40, (void *)(self + 0xce));
  vcall<void>(st, 0x40, (void *)(self + 0xd2));
  vcall<void>(st, 0x40, (void *)(self + 0xd6));
  vcall<void>(st, 0x68, (void *)(self + 0x11e));
  vcall<void>(st, 0x48, (void *)(self + 0x11f));
  ext_511bc0(st, (void *)(self + 0xda));
  vcall<void>(st, 0x40, (void *)(self + 0x123));
  vcall<void>(st, 0x70, U32(self, 0x127));
  vcall<void>(st, 0x70, U32(self, 0x12b));
  vcall<void>(st, 0x40, (void *)(self + 0x12f));
  vcall<void>(st, 0x68, (void *)(self + 0x133));
  ext_4e78c0((void *)(self + 0x144), st);
  u32 L = 0;
  vcall<void>(st, 0x40, (void *)&L);
  U32(self, 0x159) = vcall<u32>(FP(G(u8 *, 0x70039c), 0x9b), 0x58, L);
  vcall<void>(st, 0x6c, (void *)(self + 0x15d));
  vcall<void>(st, 0x74, (void *)(self + 0x169));
  vcall<void>(st, 0x48, (void *)(self + 0x18d));
  vcall<void>(st, 0x48, (void *)(self + 0x191));
  vcall<void>(st, 0x50, (void *)(self + 0x195));
  vcall<void>(st, 0x50, (void *)(self + 0x199));
  vcall<void>(st, 0x74, (void *)(self + 0x19d));
  vcall<void>(st, 0x40, (void *)&L);
  U32(self, 0x1c1) = vcall<u32>(FP(G(u8 *, 0x70039c), 0x9b), 0x58, L);
  vcall<void>(st, 0x40, (void *)&L);
  U32(self, 0x1c5) = vcall<u32>(FP(G(u8 *, 0x70039c), 0x9b), 0x58, L);
  vcall<void>(st, 0x50, (void *)(self + 0x1c9));
  vcall<void>(st, 0x40, (void *)(self + 0x1d1));
  vcall<void>(st, 0x40, (void *)(self + 0x1d9));
  vcall<void>(st, 0x48, (void *)(self + 0x1dd));
  vcall<void>(st, 0x50, (void *)(self + 0x1e1));
  vcall<void>(st, 0x48, (void *)(self + 0x1e5));
  vcall<void>(st, 0x50, (void *)(self + 0x1e9));
  vcall<void>(st, 0x70, U32(self, 0x1ed));
  vcall<void>(st, 0x68, (void *)(self + 0x215));
  vcall<void>(self, 0x2e4);
  return 1;
}
PCREG(5135c0, Load5135c0);
