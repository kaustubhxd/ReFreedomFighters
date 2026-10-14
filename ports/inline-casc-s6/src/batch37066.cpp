// batch37066.cpp - cascade s6 batch 37066: 0x407d80.
#include "ff.h"

extern "C" void __attribute__((cdecl)) ext_410bf0(u8 *w, u32 value, u32 nbytes);   // writer: (stream, value, byte count)
#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x407ed0 (verified): floor(log2(x)) for x > 1, else 0.
static u32 ilog2(u32 x) {
  u32 n = 0;
  if (x > 1) {
    do {
      x >>= 1;
      n++;
    } while (x > 1);
  }
  return n;
}

// 0x407d80, cdecl(a0, a1, w): serialises a record through the writer 0x410bf0. a1: +0 count N, +4 N-1 dwords, +0x4cc count M, +0x4d0 / +0x8d0 two M-entry arrays, +0x404 / +0x444 / +0x484
// three N-entry arrays. a0: +4 a length n whose log2 gives the bit width of the M-entry values and whose value is the repeat count of the +4 list.
static void fn407d80(u8 *a0, u8 *a1, u8 *w) {
  if ((s32)D32(a1, 0) > 1) {
    ext_410bf0(w, 1, 1);
    ext_410bf0(w, D32(a1, 0) - 1, 4);
  } else {
    ext_410bf0(w, 0, 1);
  }
  if ((s32)D32(a1, 0x4cc) > 0) {
    ext_410bf0(w, 1, 1);
    ext_410bf0(w, D32(a1, 0x4cc) - 1, 8);
    for (s32 i = 0; i < (s32)D32(a1, 0x4cc); i++) {
      ext_410bf0(w, D32(a1, 0x4d0 + 4 * i), ilog2(D32(a0, 4)));
      ext_410bf0(w, D32(a1, 0x8d0 + 4 * i), ilog2(D32(a0, 4)));
    }
  } else {
    ext_410bf0(w, 0, 1);
  }
  ext_410bf0(w, 0, 2);
  if ((s32)D32(a1, 0) > 1 && (s32)D32(a0, 4) > 0) {
    for (s32 i = 0; i < (s32)D32(a0, 4); i++) ext_410bf0(w, D32(a1, 4 + 4 * i), 4);
  }
  for (s32 i = 0; i < (s32)D32(a1, 0); i++) {
    ext_410bf0(w, D32(a1, 0x404 + 4 * i), 8);
    ext_410bf0(w, D32(a1, 0x444 + 4 * i), 8);
    ext_410bf0(w, D32(a1, 0x484 + 4 * i), 8);
  }
}
PCREG(407d80, fn407d80);
