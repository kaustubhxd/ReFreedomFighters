// batch836.cpp - gap band small functions (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

typedef u32 (__attribute__((cdecl)) *test2_t)(u32 a, u32 b);

// 0x6385c0: thiscall(this = packed 4 chars) - writes the chars from the top byte down into the buffer at 0x725814 (letters
// and digits kept, anything else '.'), stops when the remaining value is 0, NUL-terminates; returns 0x725814
static u32 THISCALL fourccToStr_6385c0(u32 v) {
  u8 *d = (u8 *)0x725814;
  while (v) {
    s8 ch = (s8)(v >> 24);
    bool ok = (ch >= 0x61 && ch <= 0x7a) || (ch >= 0x41 && ch <= 0x5a) || (u8)(ch - 0x30) <= 9;
    *d++ = ok ? (u8)ch : (u8)0x2e;
    v <<= 8;
  }
  *d = 0;
  return 0x725814;
}
PCREG(6385c0, fourccToStr_6385c0);

// 0x636280: thiscall() - initialises a header object, returns this
static u8 *THISCALL ctor_636280(u8 *self) {
  *(u32 *)(self + 0x1c) = 0;
  *(u32 *)(self + 4) = 0x44585433;
  *(u32 *)(self + 8) = 0;
  *(u32 *)(self + 0xc) = 0;
  *(u32 *)(self + 0x10) = 0;
  *(u32 *)(self + 0x14) = 0;
  *(u32 *)(self + 0x18) = 0;
  self[0x28] = 0;
  *(u32 *)(self + 0x29) = 0;
  *(u32 *)self = 0x6c2214;
  return self;
}
PCREG(636280, ctor_636280);

typedef void (THISCALL *vm_t)(u8 *self);

// 0x640400: thiscall() - vt[0xb4], vt[0xbc], vt[0xc8] on this, then vt[0x40] on each of the this[0xec] objects at this[0xf0..]
static void THISCALL callAll_640400(u8 *self) {
  (*(vm_t *)(*(u8 **)self + 0xb4))(self);
  (*(vm_t *)(*(u8 **)self + 0xbc))(self);
  (*(vm_t *)(*(u8 **)self + 0xc8))(self);
  u32 i = 0;
  if (*(u32 *)(self + 0xec) != 0) {
    u8 **p = (u8 **)(self + 0xf0);
    do {
      u8 *o = *p;
      (*(vm_t *)(*(u8 **)o + 0x40))(o);
      i++;
      p++;
    } while (i != *(u32 *)(self + 0xec));
  }
}
PCREG(640400, callAll_640400);

// 0x635380: stdcall(key) ret 4 - scans the 78 five-byte entries at 0x6f5728 (dword at +1 is passed to the test import
// 0x676414(key, dword)); returns byte +0 of the first entry for which the test returns 0, else 0
static u8 STDCALL lookup_635380(u32 key) {
  u32 off = 0, i = 0;
  do {
    if (G(test2_t, 0x676414)(key, *(u32 *)(0x6f5729 + off)) == 0) return *(u8 *)(0x6f5728 + i * 5);
    off += 5;
    i++;
  } while (off != 0x186);
  return 0;
}
PCREG(635380, lookup_635380);
