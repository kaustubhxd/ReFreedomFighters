// batch222.cpp - unclaimed area 22 (docs/20-unclaimed-22.md), slice floor(addr/16) mod 20 == 1. Three wrappers: a
// float-argument forward to a fastcall, a flag-byte call to 0x4d2700 (five stack words, ret 0x14), and a stdcall of six
// words that calls a vtable slot and then a no-op.
#include "ff.h"

extern "C" u32 FASTCALL ext_4de520(u32 a, u32 b, u32 c, float d);            // original: ecx, edx, two stack words, ret 8
extern "C" void THISCALL ext_4d2700(u8 *self, u32 a, u32 one, u32 c, u32 *p, u32 zero);  // original, ret 0x14
extern "C" void STDCALL ext_65f530(u32, u32, u32, u32, u32, u32);           // original no-op, ret 0x18

// 0x45ee90, stdcall(a, b, c, d float): return ext_4de520(ecx = a, edx = b, c, d). Name GUESS (forward with a float).
static u32 STDCALL forwardFloat_45ee90(u32 a, u32 b, u32 c, float d) {
  return ext_4de520(a, b, c, d);
}
PCREG(45ee90, forwardFloat_45ee90);

// 0x4d3dd0, thiscall(a, b, c): v = (u8)b; ext_4d2700(this, a, 1, c, &v, 0). Name GUESS (byte flag passed by pointer).
static void THISCALL flagCall_4d3dd0(u8 *self, u32 a, u32 b, u32 c) {
  u32 v = (u8)b;
  ext_4d2700(self, a, 1, c, &v, 0);
}
PCREG(4d3dd0, flagCall_4d3dd0);

// 0x440e90, stdcall(a1..a6): r = rm->[+0x9b]->vtable[0x58](obj->[+0x14]) with rm = the global at 0x70039c. If r == 0,
// return r with its low byte cleared; else call 0x65f530 (six words, ecx = r) and return (r & ~0xff) | 1. Name GUESS.
static u32 STDCALL vtCheckNoop_440e90(u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6) {
  u8 *rm = *(u8 **)0x70039cu;
  u8 *obj = *(u8 **)(rm + 0x9b);
  u32 r = vcall<u32>(obj, 0x58, *(u32 *)(obj + 0x14));
  if (!r) return r & ~0xffu;
  ext_65f530(a1, a2, a3, a4, a5, a6);
  return (r & ~0xffu) | 1u;
}
PCREG(440e90, vtCheckNoop_440e90);
