// batch306.cpp - decomp area 39 (docs/20-unclaimed-39.md), slice floor(addr/16) mod 20 == 18.
#include "ff.h"

// Exe helpers, run as original code.
// 0x478f90: thiscall (ecx = self, one float stack argument t, ret 4). Returns the segment index in eax. It walks the
//           16-byte keyed entries from the cursor stored at self[+0], writes the cursor back, and returns it.
// 0x43e920: fastcall (ECX = dst, EDX = a, one stack pointer b): dst = a - b, three floats in x87 double precision.
// 0x441940: fastcall (ECX += EDX): vector add.
// 0x4e0d00: thiscall (ecx = vec, one float stack argument alpha, ret 4): vec *= alpha.
extern "C" u32 THISCALL ext_478f90(u8 *self, float t);
extern "C" void FASTCALL ext_43e920(u8 *dst, u8 *a, u8 *b);
extern "C" void FASTCALL ext_441940(u8 *v, u8 *w);
extern "C" void THISCALL ext_4e0d00(u8 *v, float alpha);

static inline float absFloatBits(float f) {
    u32 b;
    __builtin_memcpy(&b, &f, 4);
    b &= 0x7fffffffu;
    __builtin_memcpy(&f, &b, 4);
    return f;
}

// 0x478ea0: thiscall (ecx = self, stack pointer o, one float stack argument t, ret 8).
// Keyed table: self[+0] cursor, self[+4] end key E (float), self[+8] count N, self[+0xc] entries (16 bytes each:
// key at +0, values at +4, +8, +0xc).
// t < 0 (ordered): o = entry[0] values.
// t >= E (ordered): o = entry[N-1] values.
// Otherwise i = search(t); o = values(i) - values(i-1). If |key_i - key_{i-1}| > 2^-13 (ordered), alpha =
// (t - key_{i-1}) / dk and o *= alpha. Then o += values(i-1). GUESS: a piecewise-linear keyed curve sample.
static void THISCALL keyedCurve_478ea0(u8 *self, float *o, float t) {
    u8 *arr = *(u8 **)(self + 0xc);
    if (0.0f > t) {
        o[0] = *(float *)(arr + 4);
        o[1] = *(float *)(arr + 8);
        o[2] = *(float *)(arr + 0xc);
        return;
    }
    float end = *(float *)(self + 4);
    if (!(t >= end)) {
        u32 off = ext_478f90(self, t) << 4;
        u8 *prev = arr + off - 0xc;                 // values of entry i-1
        ext_43e920((u8 *)o, arr + 4 + off, prev);   // o = values(i) - values(i-1)

        float keyI = *(float *)(arr + off);
        float keyPrev = *(float *)(arr + off - 0x10);
        float dk = keyI - keyPrev;
        if ((double)absFloatBits(dk) > G(double, 0x685278)) {
            float alpha = (t - keyPrev) / dk;
            ext_4e0d00((u8 *)o, alpha);
        }
        ext_441940((u8 *)o, prev);
        return;
    }
    s32 n = *(s32 *)(self + 8);
    u8 *last = arr + (u32)n * 16 - 16;
    o[0] = *(float *)(last + 4);
    o[1] = *(float *)(last + 8);
    o[2] = *(float *)(last + 0xc);
}
PCREG(478ea0, keyedCurve_478ea0);
