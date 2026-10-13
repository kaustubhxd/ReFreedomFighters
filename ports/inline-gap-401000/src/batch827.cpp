// batch827.cpp - core gameplay batch 827 (docs/20-unclaimed-65.md, batch 827): 0x49f210 (CMsgForwardToActors::Save), a thiscall with one stack
// argument (the save object s, ret 4) that returns true in al. It clears bit 6 of this+4, then calls slot 0x40 of s with the word at this+0x48,
// slot 0x40 of s with the word at this+0x4a, slot 0x4c of s with the float at this+0x4c, and slot 0x3c of s with the dword at this+0x50 (each
// with one argument; the callee pops it, since the exe has no add esp).
#include "ff.h"

typedef u32(THISCALL *F1)(u8 *self, u32 a);
typedef u32(THISCALL *FF)(u8 *self, float a);

static u32 vc1(u8 *o, u32 s, u32 a) { return ((F1)(*(const u32 *)(*(const u32 *)o + s)))(o, a); }
static u32 vcf(u8 *o, u32 s, float a) { return ((FF)(*(const u32 *)(*(const u32 *)o + s)))(o, a); }

static u8 THISCALL fn49f210(u8 *self, u8 *s) {
  *(u32 *)(self + 4) &= 0xffffffbf;
  vc1(s, 0x40, *(const u16 *)(self + 0x48));
  vc1(s, 0x40, *(const u16 *)(self + 0x4a));
  vcf(s, 0x4c, *(const float *)(self + 0x4c));
  vc1(s, 0x3c, *(const u32 *)(self + 0x50));
  return 1;
}

PCREG(49f210, fn49f210);
