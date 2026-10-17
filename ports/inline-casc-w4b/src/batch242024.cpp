// batch242024.cpp - Sonnet-w4b, hand port of 0x40c5c0 (`and esp,-8` prologue, x87 weighting curve; the lifter does not take esp-based locals).
#include "ff.h"

#define R32(a) (*(u32 *)(u32)(a))
#define W32(a, v) (*(u32 *)(u32)(a) = (u32)(v))

extern "C" u32 ext_634df4_cdecl2(...) __asm__("ext_634df4");     // calloc
extern "C" u32 ext_634d58_cdecl1(...) __asm__("ext_634d58");     // malloc
extern "C" u32 ext_407980_cdecl3(...) __asm__("ext_407980");
extern "C" double ext_634dca_dbl(double) __asm__("ext_634dca");  // floor, double on the stack, result in st0

#define K(a) (*(const float *)(a))
#define KD(a) (*(const double *)(a))

// 0x40c5c0: cdecl(ctx, pidx, P) -> S (calloc'd 0x34 bytes): S[0] = T[*pidx] / 2 where T = ctx[4][0x1c]; S[4] = P[8]; S[8] = P[0]; S[0x10] = P;
// S[0xc] = int table (L+1 entries, last -1) of min(floor(w(i / L) * fv), S[4]); S[0x28] = float table 2*cos(pi / S[4] * j).
extern "C" u32 port_40c5c0(u32 ctx, u32 pidx, u32 P) {
  volatile s32 A, n, L, i, S4, j;
  volatile float fv;
  volatile double dbl;
  u32 T = R32(R32(ctx + 4) + 0x1c);
  u32 S = ext_634df4_cdecl2(1, 0x34);
  W32(S + 8, R32(P));
  s32 v = (s32)R32(T + R32(pidx) * 4);
  W32(S, v / 2);
  W32(S + 4, R32(P + 8));
  W32(S + 0x10, P);
  if (R32(ctx) != 0) ext_407980_cdecl3(S + 0x14, R32(S + 4), R32(S + 8));
  A = (s32)R32(P + 4);
  n = (s32)R32(S + 4);
  __asm__ volatile(
      "fildl %1; fmuls (0x6bdffc); .byte 0xd9, 0xc0; fildl %2; .byte 0xd9, 0xc1; .byte 0xd8, 0xca;"
      "fmuls (0x6bdff8); fld1; fpatan; fmull (0x6bdff0); .byte 0xd9, 0xc3; fmuls (0x6bdfe8); fld1; fpatan; fmull (0x6bdfe0);"
      ".byte 0xde, 0xc1; .byte 0xd9, 0xcb; fmuls (0x6bdfd8); .byte 0xde, 0xc3; .byte 0xd9, 0xca; .byte 0xde, 0xfa; .byte 0xd9, 0xc9;"
      "fstps %0; .byte 0xdd, 0xd8"
      : "=m"(fv) : "m"(A), "m"(n) : "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)", "memory");
  W32(S + 0xc, ext_634d58_cdecl1(R32(S) * 4 + 4));
  L = (s32)R32(S);
  i = 0;
  while (i < L) {
    __asm__ volatile(
        "fildl %1; fmuls (0x6bdffc); fidivl %2; fimull %3; .byte 0xd9, 0xc0; .byte 0xd9, 0xc0; .byte 0xd8, 0xc9;"
        "fmuls (0x6bdff8); fld1; fpatan; fmull (0x6bdff0); .byte 0xd9, 0xc2; fmuls (0x6bdfe8); fld1; fpatan; fmull (0x6bdfe0);"
        ".byte 0xde, 0xc1; .byte 0xd9, 0xca; fmuls (0x6bdfd8); .byte 0xde, 0xc2; flds %4; .byte 0xde, 0xca; .byte 0xd9, 0xc9;"
        "fstpl %0; .byte 0xdd, 0xd8"
        : "=m"(dbl) : "m"(A), "m"(L), "m"(i), "m"(fv) : "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)", "memory");
    s32 e = (s32)ext_634dca_dbl(dbl);
    s32 lim = (s32)R32(S + 4);
    if (!(e < lim)) e = lim;
    i = i + 1;
    W32(R32(S + 0xc) + i * 4 - 4, e);
    L = (s32)R32(S);
  }
  W32(R32(S + 0xc) + (u32)i * 4, 0xffffffff);
  W32(S + 0x28, ext_634d58_cdecl1(R32(S + 4) * 4));
  S4 = (s32)R32(S + 4);
  j = 0;
  while (j < S4) {
    float out;
    __asm__ volatile("fildl %1; fdivrs (0x6be0cc); fimull %2; fcos; .byte 0xd8, 0xc0; fstps %0" : "=m"(out) : "m"(S4), "m"(j) : "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    j = j + 1;
    W32(R32(S + 0x28) + j * 4 - 4, *(u32 *)&out);
    S4 = (s32)R32(S + 4);
  }
  return S;
}
PCREG(40c5c0, port_40c5c0);
