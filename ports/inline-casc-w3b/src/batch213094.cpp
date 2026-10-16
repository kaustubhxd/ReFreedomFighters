#include "ff.h"

extern "C" void *ext_634d58(u32 size);

// 0x406590: cdecl(out, n) with no result: builds the twiddle and bit-reversal tables of a split-radix real FFT of size n (an x87 routine: the angle arithmetic keeps its extended
// intermediates, so each x87 block is done in asm exactly in the original's order). out = {n, r, A2, A1, scale}: r = ftol(floor(log(n) / log(2.0) + 0.5)) through the CRT wrappers
// 0x634dca / 0x634dfa, A1 = malloc((n / 4) * 4) bytes holds m = n / 8 index pairs ((~rev & mask) - 1, rev) with rev the bit reversal of the pair index b (bits tested against
// half = 1 << (r - 2)), A2 = malloc(((n / 4) + n) * 4) bytes holds (cos, -sin) of i * pi / n for n / 4 entries at A2[0..], (cos, sin) of (2j + 1) * pi / (2 n) at A2[n / 2..]
// and (0.5 cos, -0.5 sin) of (4k + 2) * pi / n for m entries at A2[n..]; out[4] = float(4.0 / float(n)).
extern "C" void fn_406590(u32 *out, s32 n) {
  s32 q = n / 4;
  u8 *A1 = (u8 *)ext_634d58((u32)q * 4);
  u8 *A2 = (u8 *)ext_634d58((u32)(q + n) * 4);
  s32 half_n = n >> 1;
  float nf;
  double dlog;
  asm volatile(
      "fildl %[n]\n\t"
      "fsts %[nf]\n\t"
      "fldln2\n\t"
      ".byte 0xd9, 0xc9\n\t"   // fxch st(1)
      "fyl2x\n\t"
      "fldln2\n\t"
      "fldl %[c1]\n\t"
      "fyl2x\n\t"
      ".byte 0xde, 0xf9\n\t"   // fdivp st(1), st
      "faddl %[c0]\n\t"
      "fstpl %[d]\n\t"
      : [nf] "=m"(nf), [d] "=m"(dlog)
      : [n] "m"(n), [c1] "m"(*(volatile double *)0x6be028), [c0] "m"(*(volatile double *)0x6be020)
      : "memory", "cc");
  s32 r;
  {
    u32 lo, hi;
    __builtin_memcpy(&lo, &dlog, 4);
    __builtin_memcpy(&hi, (u8 *)&dlog + 4, 4);
    u32 f1 = 0x634dca, f2 = 0x634dfa;
    asm volatile(
        "pushl %[hi]\n\t"
        "pushl %[lo]\n\t"
        "call *%[f1]\n\t"
        "addl $8, %%esp\n\t"
        "call *%[f2]\n\t"
        : "=&a"(r)
        : [hi] "r"(hi), [lo] "r"(lo), [f1] "r"(f1), [f2] "r"(f2)
        : "ecx", "edx", "memory", "cc");
  }
  out[1] = (u32)r;
  out[0] = (u32)n;
  out[2] = (u32)A2;
  out[3] = (u32)A1;
  if (q > 0) {
    s32 twoN = n + n;
    for (s32 k = 0; k < q; k++) {
      s32 i4 = 4 * k;
      s32 j2 = 2 * k + 1;
      u8 *p1 = A2 + 8 * k;
      u8 *p2 = A2 + (u32)half_n * 4 + 8 * k;
      asm volatile(
          "flds 0x6be0cc\n\t"
          "fdivs %[nf]\n\t"
          "fildl %[twoN]\n\t"
          "fdivrs 0x6be0cc\n\t"
          "fildl %[i4]\n\t"
          ".byte 0xd8, 0xca\n\t"   // fmul st, st(2)
          ".byte 0xd9, 0xc0\n\t"   // fld st(0)
          "fcos\n\t"
          "fstps (%[p1])\n\t"
          "fsin\n\t"
          "fchs\n\t"
          "fstps 4(%[p1])\n\t"
          "fildl %[j2]\n\t"
          ".byte 0xd8, 0xc9\n\t"   // fmul st, st(1)
          ".byte 0xd9, 0xc0\n\t"   // fld st(0)
          "fcos\n\t"
          "fstps (%[p2])\n\t"
          "fsin\n\t"
          "fstps 4(%[p2])\n\t"
          ".byte 0xdd, 0xd8\n\t"   // fstp st(0)
          ".byte 0xdd, 0xd8\n\t"
          :
          : [nf] "m"(nf), [twoN] "m"(twoN), [i4] "m"(i4), [j2] "m"(j2), [p1] "r"(p1), [p2] "r"(p2)
          : "memory", "cc");
    }
  }
  s32 m = n / 8;
  if (m > 0) {
    for (s32 k = 0; k < m; k++) {
      s32 j = 2 + 4 * k;
      u8 *p = A2 + (u32)n * 4 + 8 * k;
      asm volatile(
          "flds 0x6be0cc\n\t"
          "fdivs %[nf]\n\t"
          "fildl %[j]\n\t"
          ".byte 0xd8, 0xc9\n\t"   // fmul st, st(1)
          ".byte 0xd9, 0xc0\n\t"   // fld st(0)
          "fcos\n\t"
          "fmull 0x6be020\n\t"
          "fstps (%[p])\n\t"
          "fsin\n\t"
          "fmull 0x6be0d8\n\t"
          "fstps 4(%[p])\n\t"
          ".byte 0xdd, 0xd8\n\t"   // fstp st(0)
          :
          : [nf] "m"(nf), [j] "m"(j), [p] "r"(p)
          : "memory", "cc");
    }
  }
  s32 mask = (s32)((1u << ((r - 1) & 31)) - 1u);
  s32 half = (s32)(1u << ((r - 2) & 31));
  if (m > 0) {
    u8 *ap = A1;
    for (s32 b = 0; b < m; b++) {
      s32 rev = 0;
      if (half != 0) {
        s32 cl = 0;
        s32 edx = half;
        do {
          if (b & edx) rev |= (s32)(1u << (cl & 31));
          cl++;
          edx = half >> (cl & 31);
        } while (edx != 0);
      }
      s32 lo = ((~rev) & mask) - 1;
      __builtin_memcpy(ap, &lo, 4);
      __builtin_memcpy(ap + 4, &rev, 4);
      ap += 8;
    }
  }
  float sc;
  asm volatile(
      "flds 0x6be0d0\n\t"
      "fdivs %[nf]\n\t"
      "fstps %[sc]\n\t"
      : [sc] "=m"(sc)
      : [nf] "m"(nf)
      : "memory", "cc");
  __builtin_memcpy(&out[4], &sc, 4);
}
PCREG(406590, fn_406590);
