// batch2403.cpp - decomp area 24, batch 2403: a DEFLATE-style bit writer over a symbol list (0x6304f0), cdecl, plain ret.
// Arguments: A (the writer: output buffer +8, output index +0x14, 16-bit accumulator +0x16b0, used bits +0x16b4, last
// extra length +0x16ac, symbol count +0x1698, distances at +0x169c (words), literal/length codes at +0x1690 (bytes)),
// T (literal table of {code, len} words, and length-code table at +0x404/+0x406 by length index), T2 (distance-code
// table of {code, len} words). The per-symbol tables are global data in the exe (0x6c0738 ... 0x6c1100).
// emit(v, L): if used <= 16 - L the value is OR-ed into the accumulator at bit 'used'; otherwise the accumulator's two
// bytes are written to the output (low, then high), and the value's top bits go to the accumulator.
#include "ff.h"

static void emitBits(u8 *A, u32 v, u32 L) {
  u32 used = *(u32 *)(A + 0x16b4);
  u16 acc = *(u16 *)(A + 0x16b0);
  if ((s32)used <= (s32)(16 - (s32)L)) {
    acc = (u16)(acc | (u16)(v << used));
    *(u16 *)(A + 0x16b0) = acc;
    *(u32 *)(A + 0x16b4) = used + L;
  } else {
    acc = (u16)(acc | (u16)(v << used));
    *(u16 *)(A + 0x16b0) = acc;
    u8 *buf = *(u8 **)(A + 8);
    u32 idx = *(u32 *)(A + 0x14);
    buf[idx] = (u8)(acc & 0xff);
    *(u32 *)(A + 0x14) = idx + 1;
    idx = idx + 1;
    buf[idx] = (u8)((acc >> 8) & 0xff);
    *(u32 *)(A + 0x14) = idx + 1;
    u32 sh = 16 - used;
    u16 top = (u16)((u16)v >> (sh & 0x1f));
    if (sh >= 16)
      top = 0;
    *(u16 *)(A + 0x16b0) = top;
    *(u32 *)(A + 0x16b4) = used + L - 16;
  }
}

static void cdeclDeflateBits(u8 *A, u8 *T, u8 *T2) {
  u32 N = *(u32 *)(A + 0x1698);
  u8 *W = *(u8 **)(A + 0x169c);
  u8 *B = *(u8 **)(A + 0x1690);
  for (u32 i = 0; i < N; ++i) {
    u32 w = *(u16 *)(W + 2 * i);
    u32 b = B[i];
    if (w == 0) {
      emitBits(A, *(u16 *)(T + 4 * b), *(u16 *)(T + 4 * b + 2));
      continue;
    }
    u32 k = ((u8 *)0x6c0738)[b];
    u32 L1 = *(u16 *)(T + 4 * k + 0x406);
    emitBits(A, *(u16 *)(T + 4 * k + 0x404), L1);
    u32 M = ((u32 *)0x6c0a38)[k];
    if (M != 0)
      emitBits(A, b - ((u32 *)0x6c1088)[k], M);
    u32 d = w - 1;
    u32 dc = (d < 0x100) ? ((u8 *)0x6c0838)[d] : ((u8 *)0x6c0938)[d >> 7];
    emitBits(A, *(u16 *)(T2 + 4 * dc), *(u16 *)(T2 + 4 * dc + 2));
    u32 E = ((u32 *)0x6c0ab0)[dc];
    if (E != 0)
      emitBits(A, d - ((u32 *)0x6c1100)[dc], E);
  }
  u32 X1 = *(u16 *)(T + 0x402);
  emitBits(A, *(u16 *)(T + 0x400), X1);
  *(u32 *)(A + 0x16ac) = X1;
}
PCREG(6304f0, cdeclDeflateBits);
