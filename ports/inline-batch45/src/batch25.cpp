// batch25.cpp - first-level functions, inline session batch 25 (Haiku, overnight).
#include "ff.h"

// 0x4ab280, thiscall (ret 4, returns 0): searches 200 records of 0x1b8 bytes starting at this+0x694 for a dword equal to
// the stack argument. The first match has its dword at +0x694 cleared. Name unknown.
static u32 THISCALL clearSlot(u8 *self, u32 value) {
  for (u32 i = 0; i < 200; i++) {
    u32 *slot = (u32 *)(self + 0x694 + 0x1b8 * i);
    if (*slot == value) {
      *slot = 0;
      return 0;
    }
  }
  return 0;
}
PCREG(4ab280, clearSlot);

// 0x4c09d0, thiscall, no args, plain ret: copies fields to the record: the byte at +0x58 (zero-extended dword) to +0x75,
// the dword at +0x48 to +0x65, the dword at +0x4c to +0x69, +0x50 to +0x6d, +0x54 to +0x71. The floats at +0x59, +0x5d
// and +0x61 are truncated to int (cvttss2si) into +0x79, +0x7d and +0x81. Name unknown.
static void THISCALL copyFields(u8 *self) {
  u32 b = self[0x58];
  *(u32 *)(self + 0x75) = b;
  *(u32 *)(self + 0x65) = *(u32 *)(self + 0x48);
  s32 c1 = (s32)*(float *)(self + 0x59);
  u32 dx = *(u32 *)(self + 0x54);
  *(u32 *)(self + 0x69) = *(u32 *)(self + 0x4c);
  *(u32 *)(self + 0x6d) = *(u32 *)(self + 0x50);
  *(u32 *)(self + 0x71) = dx;
  *(s32 *)(self + 0x79) = c1;
  *(s32 *)(self + 0x7d) = (s32)*(float *)(self + 0x5d);
  *(s32 *)(self + 0x81) = (s32)*(float *)(self + 0x61);
}
PCREG(4c09d0, copyFields);

// 0x49df30, thiscall, no args, returns a pointer: this holds a pointer s to a tagged string. When bit 1 of s[0] is clear
// it returns 0. When bit 0 is clear it returns s + 1. Otherwise it scans from s[1] to the next NUL and returns the
// position just past that NUL. Name unknown.
static u8 *THISCALL scanTag(u8 **self) {
  u8 *s = *self;
  u8 a = *s;
  if (!(a & 2))
    return 0;
  if (!(a & 1))
    return s + 1;
  u8 *p = s + 1;
  u8 c;
  do {
    c = *p;
    p++;
  } while (c != 0);
  return p;
}
PCREG(49df30, scanTag);
