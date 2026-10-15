// batch38093.cpp - cascade s8 batch 38093: 0x401c90 (Vorbis vorbis_info_clear: release everything the decoder info owns, then zero it).
#include "ff.h"

extern "C" void ext_634d52(void *p);   // free
extern "C" void ext_4063d0(void *p);
extern "C" void ext_406770(void *p);
extern "C" void ext_402480(void *p);
extern "C" void ext_4062e0(void *p);
extern "C" void ext_405690(void *p);
typedef void (*fn1_t)(void *);
#define P32(p, off) (*(u8 **)((u8 *)(p) + (off)))
#define U(p, off) (*(u32 *)((u8 *)(p) + (off)))

static void freeif(void *p) {
  if (p) ext_634d52(p);
}

// 0x401c90, cdecl(vi) void. vi+4 = codec setup (ci), +8 / +0xc = arrays, +0x68 = backend state.
static void fn401c90(u8 *vi) {
  if (!vi) return;
  u8 *ci = P32(vi, 4);
  u8 *priv = ci ? P32(ci, 0x1c) : 0;
  u8 *b = P32(vi, 0x68);
  if (b) {
    if (P32(b, 4)) {
      freeif(*(void **)P32(b, 4));
      ext_634d52(P32(b, 4));
      u8 *s = b + 0x14;
      for (int i = 0; i < 4; i++, s += 4) {
        freeif(*(void **)*(u8 **)s);
        ext_634d52(*(u8 **)s);
      }
    }
    if (P32(b, 0)) {
      ext_4063d0(P32(b, 0));
      ext_634d52(P32(b, 0));
    }
    if (P32(b, 0x24)) {
      ext_406770(*(void **)P32(b, 0x24));
      ext_634d52(*(void **)P32(b, 0x24));
      ext_634d52(P32(b, 0x24));
    }
    if (P32(b, 0x28)) {
      ext_406770(*(void **)P32(b, 0x28));
      ext_634d52(*(void **)P32(b, 0x28));
      ext_634d52(P32(b, 0x28));
    }
    if (P32(b, 0x30)) ext_402480(P32(b, 0x30));
    ext_4062e0(b + 0x48);
  }
  if (P32(vi, 8)) {
    for (int i = 0; (int)U(ci, 4) > 0 && i < (int)U(ci, 4); i++) freeif(((void **)P32(vi, 8))[i]);
    ext_634d52(P32(vi, 8));
    freeif(P32(vi, 0xc));
  }
  if (priv) {
    for (int i = 0; (int)U(priv, 8) > 0 && i < (int)U(priv, 8); i++) {
      if (b && P32(b, 0x38)) {
        u8 *m = P32(priv, 0x24 + 4 * i);
        u32 idx = U(m, 0xc);
        u32 x = U(priv, 0x124 + idx * 4);
        u8 **tab = (u8 **)(0x6f1dd8 + x * 4);
        ((fn1_t)(*(u8 **)(*tab + 0x14)))(((void **)P32(b, 0x38))[i]);
      }
    }
    for (int i = 0; (int)U(priv, 0x1c) > 0 && i < (int)U(priv, 0x1c); i++) {
      if (b && P32(b, 0x2c)) ext_405690(P32(b, 0x2c) + i * 0x1c);
    }
  }
  if (b) {
    freeif(P32(b, 0x38));
    freeif(P32(b, 0x2c));
    freeif(P32(b, 0x3c));
    freeif(P32(b, 0x40));
    freeif(P32(b, 0x44));
    ext_634d52(b);
  }
  for (int i = 0; i < 0x1c; i++) U(vi, 4 * i) = 0;
}
PCREG(401c90, fn401c90);
