// batch66014.cpp - cascade s4 batch 66014: 0x499e60 (tier F row).
#include "ff.h"

typedef u8 *(THISCALL *alloc2_t)(void *, u32, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" u8 *THISCALL ext_4cd9b0(void *self, u32 size, u32 flag);   // ret 8
extern "C" u8 *ext_41e290(u32 n);                                     // cdecl
extern "C" void *ext_634d22(void *d, const void *s, u32 n);          // cdecl memcpy thunk

// Make sure chunk c has a successor: ctx = c[4]; ctx[4] set -> p = 0x4cd9b0(ctx[4], 0x1394, 1), *p = 0x1394, p += 4; else p = 0x41e290(0x1390).
// c[0] = p; p != 0 -> p[0] = 0, p[4] = ctx.
static void ensure_next(u8 *c) {
  u8 *ctx = *(u8 **)(c + 4);
  u8 *ctx4 = *(u8 **)(ctx + 4);
  u8 *p;
  if (ctx4) {
    p = ext_4cd9b0(ctx4, 0x1394, 1);
    wr(p, 0x1394);
    p += 4;
  } else {
    p = ext_41e290(0x1390);
  }
  ctx = *(u8 **)(c + 4);
  wr(c, (u32)p);
  if (p) {
    wr(p, 0);
    wr(p + 4, (u32)ctx);
  }
}

// 0x499e60, thiscall(off, src, len) ret 0xc (this = c): a write of len bytes at offset off into a chain of 0x1388-byte chunks (c[0] next, c[4] context, data at c + 8).
// While off >= 0x1388: next chunk (allocated when missing), off -= 0x1388. Then rem = 0x1388 - off: len > rem -> memcpy(c + 8 + off, src, rem), src += rem, len -= rem,
// off = 0, next chunk (allocated when missing); otherwise memcpy(c + 8 + off, src, len), done.
static void THISCALL fn499e60(u8 *c, u32 off, u8 *src, u32 len) {
  for (;;) {
    if (off >= 0x1388) {
      if (!rd(c)) ensure_next(c);
      c = *(u8 **)c;
      off -= 0x1388;
      continue;
    }
    u32 rem = 0x1388 - off;
    if (len <= rem) {
      ext_634d22(c + 8 + off, src, len);
      return;
    }
    ext_634d22(c + 8 + off, src, rem);
    src += rem;
    off = 0;
    len -= rem;
    if (!rd(c)) ensure_next(c);
    c = *(u8 **)c;
  }
}
PCREG(499e60, fn499e60);
