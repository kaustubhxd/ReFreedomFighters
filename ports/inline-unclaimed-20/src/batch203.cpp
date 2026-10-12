// batch203.cpp - unclaimed area 20 (docs/20-unclaimed-20.md), slice floor(addr/16) mod 20 == 19. Thin wrappers: each
// body is a few stores around one call into original exe code (bound through ext_<hex>, not ported here).
#include "ff.h"

extern "C" void THISCALL ext_45fa00(u8 *self, u32 a);          // original code, thiscall, callee pops 4
extern "C" void ext_634273(u8 *p, u32 n);                      // free-style release, original code (cdecl)
extern "C" void THISCALL ext_5e0e10(u8 *self, u32 a, u32 b);   // base constructor, original code, callee pops 8
extern "C" void THISCALL ext_4e3d60(u8 *self, u8 *arg);        // original code, thiscall, callee pops 4
extern "C" u8 *THISCALL ext_5003d0(u8 *self, u32 zero);        // original code, returns a pointer in eax

// 0x43e170, thiscall(a): call 0x45fa00(this, a); then if (byte [this+0x14] & 0xe) == 0, clear bit 0 of the dword at
// +0x14. Name GUESS.
static void THISCALL callThenClearBit0_43e170(u8 *self, u32 a) {
  ext_45fa00(self, a);
  u32 v = *(u32 *)(self + 0x14);
  if ((v & 0xe) == 0) *(u32 *)(self + 0x14) = v & 0xfffffffeu;
}
PCREG(43e170, callThenClearBit0_43e170);

// 0x4d24b0, thiscall(flags): set the vtable word at [this] to 0x696168; if flags bit 0 is set, release this with
// ext_634273(this, 4). Returns this in eax. Name GUESS (scalar deleting-destructor shape).
static u8 *THISCALL setVtableRelease_4d24b0(u8 *self, u32 flags) {
  *(u32 *)self = 0x696168u;
  if (flags & 1) ext_634273(self, 4);
  return self;
}
PCREG(4d24b0, setVtableRelease_4d24b0);

// 0x5e0ff0, thiscall(a, b): call the base constructor 0x5e0e10(this, a, b); then set vtable 0x6b76dc, clear the word
// at +0x554 and the dword at +0x557, and store the floats 0x43960000 at +0x54c and 0x3e800000 at +0x550. Returns this.
// Name GUESS.
static u8 *THISCALL ctorAfterBase_5e0ff0(u8 *self, u32 a, u32 b) {
  ext_5e0e10(self, a, b);
  *(u32 *)self = 0x6b76dcu;
  *(u16 *)(self + 0x554) = 0;
  *(u32 *)(self + 0x557) = 0;
  *(u32 *)(self + 0x54c) = 0x43960000u;
  *(u32 *)(self + 0x550) = 0x3e800000u;
  return self;
}
PCREG(5e0ff0, ctorAfterBase_5e0ff0);

// 0x4edcb0, stdcall(p): e = [p]; set the vtable word at p+4 to 0x67d138; call 0x4e3d60 (this = p+4, arg = p+0x20);
// return e + p. Name GUESS.
static u32 STDCALL readPlusBaseCall_4edcb0(u8 *p) {
  u32 e = *(u32 *)p;
  *(u32 *)(p + 4) = 0x67d138u;
  ext_4e3d60(p + 4, p + 0x20);
  return e + (u32)p;
}
PCREG(4edcb0, readPlusBaseCall_4edcb0);

// 0x51ab70, thiscall(p): r = call 0x5003d0(ecx = [p+4], 0) returning a pointer; then [[this+0x18] + 0x216] = [r] as a
// dword. Name GUESS.
static void THISCALL storeThroughPtr_51ab70(u8 *self, u8 *p) {
  u8 *r = ext_5003d0(*(u8 **)(p + 4), 0);
  u32 v = *(u32 *)r;
  u8 *dst = *(u8 **)(self + 0x18);
  *(u32 *)(dst + 0x216) = v;
}
PCREG(51ab70, storeThroughPtr_51ab70);
