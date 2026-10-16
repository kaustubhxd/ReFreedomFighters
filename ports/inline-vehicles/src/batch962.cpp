// batch962.cpp - residue-04/05 (core todo), batch 962: 0x55edc0 and 0x55fb90 (thiscall, two stack args X, Y, ret 8).
// Each calls a helper with (X, Y) and ECX = this (0x55fb90 for 0x55edc0, 0x506220 for 0x55fb90; stood in by the checker);
// then Z = [X+0x15], and the render manager's vslot 0x4c answers the value of [this+0x1c] (0x55edc0) or [this+0x18]
// (0x55fb90), and Z's vslot 0x3c takes that answer.
#include "ff.h"

extern "C" void THISCALL ext_55fb90(void *self, u32 a, u32 b);   // helper (stood in)
extern "C" void THISCALL ext_506220(void *self, u32 a, u32 b);   // helper (stood in)

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

static void rmSave(u32 x, u32 field) {
  u8 *z = *(u8 **)(x + 0x15);
  void *rm = *(void **)(*(u8 **)0x70039c + 0x9b);
  u32 v = vcall<u32>(rm, 0x4c, field);
  vcall<void>(z, 0x3c, v);
}

// 0x55edc0.
static void THISCALL edc0(u8 *t, u32 x, u32 y) {
  ext_55fb90(t, x, y);
  rmSave(x, D(t, 0x1c));
}
PCREG(55edc0, edc0);

// 0x55fb90.
static void THISCALL fb90(u8 *t, u32 x, u32 y) {
  ext_506220(t, x, y);
  rmSave(x, D(t, 0x18));
}
PCREG(55fb90, fb90);
