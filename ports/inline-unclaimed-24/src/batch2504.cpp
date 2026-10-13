// batch2504.cpp - decomp area 24, batch 2504. 0x40f8b0 (GUESS: FFT factorisation + twiddle table builder), cdecl(n, twid, fac).
// Part 1 factors n by the table at 0x6f2400 (4, 2, 3, 5, then 7, 9, 11, ...), storing the factors in fac[2..], with a
// factor of 2 moved to fac[2]; fac[0] = n, fac[1] = factor count. Part 2 fills twid with cos/sin pairs using x87 fsin/fcos
// (inline asm: the compiler cannot reproduce them or the extended-precision step computation).
#include "ff.h"

extern "C" __attribute__((cdecl)) void f24_40f8b0(int n, float *twid, int *fac) {
  int cur = 0x6f2400, esi = 0, edi = 0, ecx = n, eax;
  for (;;) {
    if (cur < 0x6f2410) esi = *(int *)cur; else esi += 2;
    eax = ecx / esi;
    if (ecx - eax * esi != 0) { cur += 4; continue; }
    for (;;) {
      fac[edi + 2] = esi;
      edi++;
      ecx = eax;
      if (esi == 2 && edi != 1) {
        for (int j = edi + 1; j >= 3; j--) fac[j] = fac[j - 1];
        fac[2] = 2;
      }
      if (eax == 1) goto part2;
      eax = ecx / esi;
      if (ecx - eax * esi != 0) break;
    }
  }
part2:
  fac[0] = n;
  fac[1] = edi;
  edi--;
  int off = 0;
  float step;
  asm volatile("fildl %1\n\tfdivrs 0x6f2410\n\tfstps %0" : "=m"(step) : "m"(n));
  if (edi <= 0) return;
  int ld = 1;
  int *p = fac + 2;
  for (int cnt = edi; cnt != 0; cnt--, p++) {
    int ip = *p;
    int ido = n / (ip * ld);
    int j = 0;
    int k = ip - 1;
    if (k > 0) {
      float *tp = twid + off;
      off += k * ido;
      do {
        j += ld;
        float arg;
        asm volatile("fildl %1\n\tfmuls %2\n\tfstps %0" : "=m"(arg) : "m"(j), "m"(step));
        if (ido > 2) {
          u32 c2 = (u32)(ido - 1) >> 1;
          float *q = tp;
          asm volatile(
              "flds 0x6bdfd4\n"
              "1:\n\t"
              "fadds 0x6be05c\n\t"
              "fld %%st(0)\n\t"
              "fmuls %[a]\n\t"
              "fld %%st(0)\n\t"
              "fcos\n\t"
              "fstps (%[q])\n\t"
              "fsin\n\t"
              "fstps 4(%[q])\n\t"
              "addl $8, %[q]\n\t"
              "decl %[c]\n\t"
              "jne 1b\n\t"
              "fstp %%st(0)"
              : [q] "+r"(q), [c] "+r"(c2)
              : [a] "m"(arg)
              : "memory", "cc");
        }
        tp += ido;
        k--;
      } while (k != 0);
    }
    ld = ip * ld;
  }
}
PCREG(40f8b0, f24_40f8b0);
