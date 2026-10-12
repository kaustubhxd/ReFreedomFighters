// batch304.cpp - decomp area 39 (docs/20-unclaimed-39.md), slice floor(addr/16) mod 20 == 18.
#include "ff.h"

// Exe helpers, run as original code. Both are fastcall (ecx, edx, then stack words; the callee pops them).
// 0x43e920: dst (ECX) = a (EDX) - b (stack): three float subtractions done in x87 double precision.
// 0x446ee0: dst (ECX) = cross-style product of a (stack) and b (EDX), x87 double precision.
extern "C" void FASTCALL ext_43e920(u8 *dst, u8 *a, u8 *b);
extern "C" void FASTCALL ext_446ee0(u8 *dst, u8 *b, u8 *a);

// Round-to-nearest double square root, the same result as the exe's fsqrt at 53-bit precision.
static inline double sqrtDouble(double x) {
    double r;
    __asm__("sqrtsd %1, %0" : "=x"(r) : "x"(x));
    return r;
}

// 0x53d160: fastcall (ECX = out vec3, EDX = e, two stack pointers s1 and s2; ret 8).
// loc1 = s1 - e; loc2 = s2 - e (exe 0x43e920). out = cross-style product of loc1 and loc2 (exe 0x446ee0).
// If all three out components are ordered zeros, out = (0, 1, 0) and return. Otherwise
// L = sqrt(x*x + y*y + z*z) in double; inv = 1.0 / L; out = (x*inv, y*inv, z*inv) rounded to float. The rounded
// float of L is compared: if 0.99999 > L_float, out = (0, 1, 0). Unordered compares keep the normalized value.
// GUESS: a normal of a difference-of-two-vectors frame, with a fallback to +Y for a degenerate result.
static void FASTCALL normFrame_53d160(float *out, float *e, float *s1, float *s2) {
    float loc1[3], loc2[3];
    ext_43e920((u8 *)loc1, (u8 *)s1, (u8 *)e);
    ext_43e920((u8 *)loc2, (u8 *)s2, (u8 *)e);
    ext_446ee0((u8 *)out, (u8 *)loc2, (u8 *)loc1);

    if (out[0] == 0.0f && out[1] == 0.0f && out[2] == 0.0f) {
        out[0] = 0.0f;
        out[1] = 1.0f;
        out[2] = 0.0f;
        return;
    }

    double x = out[0], y = out[1], z = out[2];
    double len = sqrtDouble((x * x + y * y) + z * z);
    float lenF = (float)len;
    double inv = 1.0 / len;
    out[0] = (float)(x * inv);
    out[1] = (float)(y * inv);
    out[2] = (float)(z * inv);

    float c = G(float, 0x6a2dec);
    if (c > lenF) {
        out[0] = 0.0f;
        out[1] = 1.0f;
        out[2] = 0.0f;
    }
}
PCREG(53d160, normFrame_53d160);
