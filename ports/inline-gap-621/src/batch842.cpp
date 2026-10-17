// batch842.cpp - gap band functions with hooked callbacks (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

typedef void (THISCALL *vm_t)(u8 *self);
typedef u32 (__attribute__((cdecl)) *conv_t)(u32 cookie, u32 arg);

// 0x63b940: thiscall() - vt[0x6c] on each of the this[0xec] objects at this[0xf0..]
static void THISCALL callAll6c_63b940(u8 *self) {
  u32 i = 0;
  if (*(u32 *)(self + 0xec) != 0) {
    u8 **p = (u8 **)(self + 0xf0);
    do {
      u8 *o = *p;
      (*(vm_t *)(*(u8 **)o + 0x6c))(o);
      i++;
      p++;
    } while (i != *(u32 *)(self + 0xec));
  }
}
PCREG(63b940, callAll6c_63b940);

// 0x62c6c0: cdecl(cvt, ch) - r = cvt[0x170](cvt[0x174], ch); returns 1 for a result above 16 bits, a surrogate high byte
// (0xd8..0xdf), 0xfffe / 0xffff, or a zero high byte whose entry in the table at 0x6bf2f4 is 0; else 0
static u32 __attribute__((cdecl)) isInvalid_62c6c0(u8 *cvt, u32 ch) {
  u32 r = (*(conv_t *)(cvt + 0x170))(*(u32 *)(cvt + 0x174), ch);
  if (r & 0xffff0000u) return 1;
  s32 c = (s32)r >> 8;
  if (c > 0xdf) {
    if (c == 0xff && (r == 0xfffe || r == 0xffff)) return 1;
  } else {
    if (c >= 0xd8) return 1;
    if (c == 0 && *(u8 *)(0x6bf2f4 + r) == 0) return 1;
  }
  return 0;
}
PCREG(62c6c0, isInvalid_62c6c0);

// 0x62c7f0: cdecl(cvt, u8 **src, u8 *srcEnd, u16 **dst, u16 *dstEnd) - converts until either end: a byte whose u16 entry in
// cvt[0x178 + 2b] is nonzero advances 1 and emits that entry; otherwise cvt[0x170](cvt[0x174], src) gives the code unit and
// the source advances cvt[0x4c + b] - 3
static void __attribute__((cdecl)) convert_62c7f0(u8 *cvt, u8 **src, u8 *srcEnd, u8 **dst, u8 *dstEnd) {
  if (*src == srcEnd) return;
  do {
    if (*dst == dstEnd) return;
    u8 *p = *src;
    u32 b = *p;
    u32 unit = *(u16 *)(cvt + 0x178 + b * 2);
    if (unit == 0) {
      u32 r = (*(conv_t *)(cvt + 0x170))(*(u32 *)(cvt + 0x174), (u32)p);
      p = *src;
      unit = (u16)r;
      *src = p + (u32)cvt[0x4c + *p] - 3;
    } else {
      *src = p + 1;
    }
    *(u16 *)*dst = (u16)unit;
    *dst += 2;
  } while (*src != srcEnd);
}
PCREG(62c7f0, convert_62c7f0);
