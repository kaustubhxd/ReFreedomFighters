// batch38050.cpp - cascade s8 batch 38050 (numbering note: batch 38049 is 0x620180): 0x4f08b0 (log a node's flags, name and children).
#include "ff.h"

extern "C" u8 *THISCALL ext_4db520(u8 *node);   // next node, plain ret
extern "C" const char *THISCALL ext_4cc5a0(u8 *o);   // text of an object, plain ret
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef u32(*log3_t)(void *, u32, const char *);
typedef u32(*log7_t)(void *, u32, const char *, u32, u32, u32, u32);
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define LOG G(u8 *, 0x700390)

static void *stream(u32 line) { return (void *)SLOT(LOG, 0x20, v2_t)(LOG, 0x697b1c, line); }
static void say(u8 *a, u32 line, u32 fmt) {
  void *st = stream(line);
  const char *t = ext_4cc5a0(a);
  (*(log3_t **)st)[0x2c / 4](st, fmt, t);
}

// 0x4f08b0, thiscall(a, b) ret 8, no result. Skips ahead along this[0x54] while the node's flag word ([[n+0x54]+0xc]+0x23, 0x200002 when absent) lacks bit 0x100000 (0x4db520 = next), then writes a
// block of log lines about the object `a` (text from 0x4cc5a0): a line for each of this[0x30] bits 0x800, 2 and 0x40000000 (two variants), one with this[0xc][0], the name, this[8]+0x24 and a mode
// string chosen by this[8][0x3c] & 0xc00, one closing line, then every child of this[0x50] (+0x60 chain) gets slot 0x20c(a + 4, 0) on its +0x54 object, and a last line.
static void THISCALL fn4f08b0(u8 *self, u8 *a, u32 b) {
  (void)b;
  u8 *n = *(u8 **)(self + 0x54);
  while (n) {
    u8 *t = *(u8 **)(n + 0x54);
    u32 fl = t ? *(u32 *)(*(u8 **)(t + 0xc) + 0x23) : 0x200002;
    if (fl & 0x100000) break;
    n = ext_4db520(n);
  }
  u32 f30 = *(u32 *)(self + 0x30);
  if (f30 & 0x800) say(a, 0x68e, 0x67cc20);
  if (f30 & 2) say(a, 0x68f, 0x67cc34);
  if (f30 & 0x40000000) say(a, 0x692, 0x69853c);
  else say(a, 0x694, 0x698544);
  u32 mstr = 0x677b5a;
  u32 mode = *(u32 *)(*(u8 **)(self + 8) + 0x3c) & 0xc00;
  if (mode == 0x400) mstr = 0x68dd0c;
  else if (mode == 0x800) mstr = 0x69850c;
  else if (mode == 0xc00) mstr = 0x698518;
  void *st = stream(0x6a3);
  u32 p8 = (u32)(*(u8 **)(self + 8) + 0x24);
  u32 name = *(u32 *)(self + 4) ? *(u32 *)(self + 4) : 0x67c8e8;
  u32 v0 = **(u32 **)(self + 0xc);
  const char *t = ext_4cc5a0(a);
  (*(log7_t **)st)[0x2c / 4](st, 0x69852c, t, v0, name, p8, mstr);
  say(a, 0x6a4, 0x67ccd8);
  for (u8 *c = *(u8 **)(self + 0x50); c; c = *(u8 **)(c + 0x60)) {
    u8 *o = *(u8 **)(c + 0x54);
    if (o) SLOT(o, 0x20c, v2_t)(o, (u32)(a + 4), 0);
  }
  say(a, 0x6aa, 0x67cce0);
}
PCREG(4f08b0, fn4f08b0);
