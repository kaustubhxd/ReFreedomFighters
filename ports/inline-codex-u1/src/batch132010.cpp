// Port derived from inline-unclaimed-76 batch354; strict verification by codex-u1.
// batch354.cpp - area 76 (docs/20-unclaimed-76.md, parked row 0x616e00): colour lerp (fastcall: ECX = out pointer, EDX = pointer to
// colour c1, stack: pointer to colour c2, float t; ret 8; GUESS). If c1 == c2 the output is c1. Else each colour is split into four
// bytes, lanes (c >> 16), (c >> 8), (c & 0xff), (c >> 24); each lane is lerped as v1 + (v2 - v1) * t in single precision; each lane is
// then converted through the CRT float-to-int helper 0x633910 (exe code, called with the float in XMM0 and the result in EAX), and the
// output is ((((r3 << 8) + r0) << 8) + r1) << 8 + r2.
#include "ff.h"

static const u32 k633910 = 0x633910u;

// The helper takes its float in XMM0 and returns in EAX; it sets ECX itself (mode 1 at this entry).
static u32 cvt633910(float f) {
    register float x asm("xmm0") = f;
    u32 r;
    __asm__ volatile(
        "calll *%[t]\n\t"
        : "=&a"(r)
        : "x"(x), [t] "m"(k633910)
        : "ecx", "edx", "xmm1", "xmm2", "xmm3", "xmm4", "xmm5", "xmm6", "xmm7", "memory", "cc");
    return r;
}

static void __attribute__((fastcall)) lerp616e00(u32 out, u32 c1p, u32 c2p, float t) {
    u32 c1 = *(u32 *)c1p;
    u32 c2 = *(u32 *)c2p;
    if (c1 == c2) {
        *(u32 *)out = c1;
        return;
    }
    float v1[4] = {(float)((c1 >> 16) & 0xffu), (float)((c1 >> 8) & 0xffu), (float)(c1 & 0xffu), (float)(c1 >> 24)};
    float v2[4] = {(float)((c2 >> 16) & 0xffu), (float)((c2 >> 8) & 0xffu), (float)(c2 & 0xffu), (float)(c2 >> 24)};
    float w[4];
    for (int i = 0; i < 4; i++) w[i] = v1[i] + (v2[i] - v1[i]) * t;
    u32 r3 = cvt633910(w[3]);
    u32 r0 = cvt633910(w[0]);
    u32 r1 = cvt633910(w[1]);
    u32 r2 = cvt633910(w[2]);
    u32 e = r3;
    e = (e << 8) + r0;
    e = (e << 8) + r1;
    e = (e << 8) + r2;
    *(u32 *)out = e;
}
PCREG(616e00, lerp616e00);
