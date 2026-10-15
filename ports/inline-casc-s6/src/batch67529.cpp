// batch67529.cpp - cascade s6 batch 67529: 0x5fa640.
#include "ff.h"

extern "C" u32 FASTCALL ext_4cc4b0(u32 a, u32 b);   // case-insensitive ASCII byte equality (low bytes), plain ret

// 0x5fa640, fastcall(first, last, pat, patEnd, +3 unused stack dwords) ret 0x14: case-insensitive search of the pattern [pat, patEnd) in [first, last) (comparison 0x4cc4b0, which the
// original calls again on the same byte when it enters its second loop); returns the start of the LAST occurrence, or `last` when there is none (also when the pattern is empty).
static u8 *FASTCALL fn5fa640(u8 *first, u8 *last, u8 *pat, u8 *patEnd, u32 u1, u32 u2, u32 u3) {
  u8 *esi = first, *ebx = last, *edi = pat, *res, *next, *p4, *q;
  if (edi == patEnd) return ebx;
  res = ebx;
  for (;;) {
    if (esi == ebx) return res;
    if (edi + 1 == patEnd) {
      for (;;) {
        if ((u8)ext_4cc4b0(*esi, *edi)) break;
        esi++;
        if (esi == ebx) break;
      }
      goto t720;
    }
  l690:
    for (;;) {
      if ((u8)ext_4cc4b0(*esi, *edi)) break;
      esi++;
      if (esi == ebx) return res;
    }
    for (;;) {
      if ((u8)ext_4cc4b0(*esi, *edi)) break;
      esi++;
      if (esi == ebx) return res;
    }
    p4 = pat + 1;
    next = esi + 1;
    q = next;
    if (q == ebx) return res;
    if (!(u8)ext_4cc4b0(*q, *p4)) goto t70e;
    for (;;) {
      p4++;
      if (p4 == patEnd) { edi = pat; goto t720; }
      q++;
      if (q == ebx) return res;
      if (!(u8)ext_4cc4b0(*q, *p4)) goto t70e;
    }
  t70e:
    esi = next;
    edi = pat;
    if (esi == ebx) goto t720;
    goto l690;
  t720:
    if (esi == ebx) return res;
    res = esi;
    esi++;
  }
}
PCREG(5fa640, fn5fa640);
