// batch953.cpp - five residue-16 functions from the coordinator's slice (2026-10-12), each read in full (no SEH frame, no tail jump except 0x54a0c0).
//  0x54a0c0 [thiscall, no args, returns eax]: c = [this+0x8061]; if c is set, slot +0x18 of c (no args). Then tail-jump to 0x54d910 with ECX = this
//           (stood in; no args; its eax is this function's).
//  0x5f9700 [thiscall, two stack words (a, one unused), ret 8, returns this]: [this] = 0x69c968; slot +0x5c of a with one arg (this + 4).
//  0x656f40 [thiscall, one arg a, ret 4, void]: o = slot +0xc of this with one arg a (its eax is the object); slot +0xc of this with one arg
//           [o+0x94].
//  0x656900 [thiscall, two args (a, b), ret 8, void]: o = slot +0xc of this with one arg a; slot +0x144 of this with two args (o, b).
//  0x657940 [thiscall, one arg a, ret 4, returns al]: o = slot +0xc of this with one arg a; if the word at o+2 is non-zero return 0; else return
//           ([o+0x50] != 1).
#include "ff.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" u32 THISCALL ext_54d910(void *self);   // stood in (no args; the tail target)

// 0x54a0c0 (no name in the map).
static u32 THISCALL Tail54a0c0(u8 *self) {
  void *c = FP(self, 0x8061);
  if (c) vcall<void>(c, 0x18);
  return ext_54d910(self);
}
PCREG(54a0c0, Tail54a0c0);

// 0x5f9700 (no name in the map).
static u8 *THISCALL Init5f9700(u8 *self, u8 *a, u32 unused) {
  (void)unused;   // ret 8: the second stack word is never read
  U32(self, 0) = 0x69c968;
  vcall<void>(a, 0x5c, self + 4);
  return self;
}
PCREG(5f9700, Init5f9700);

// 0x656f40 (no name in the map).
static void THISCALL Chain656f40(u8 *self, u32 a) {
  u8 *o = (u8 *)vcall<void *>(self, 0xc, a);
  vcall<void>(self, 0xc, U32(o, 0x94));
}
PCREG(656f40, Chain656f40);

// 0x656900 (no name in the map).
static void THISCALL Chain656900(u8 *self, u32 a, u32 b) {
  u8 *o = (u8 *)vcall<void *>(self, 0xc, a);
  vcall<void>(self, 0x144, (u32)o, b);
}
PCREG(656900, Chain656900);

// 0x657940 (no name in the map).
static u8 THISCALL Test657940(u8 *self, u32 a) {
  u8 *o = (u8 *)vcall<void *>(self, 0xc, a);
  if (*(u16 *)(o + 2) != 0) return 0;
  return U32(o, 0x50) != 1;
}
PCREG(657940, Test657940);
