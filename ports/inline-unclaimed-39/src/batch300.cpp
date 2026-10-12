// batch300.cpp - decomp area 39 (docs/20-unclaimed-39.md), slice floor(addr/16) mod 20 == 18.
#include "ff.h"

// |x| by clearing the sign bit, as the exe does with andps and the mask 0x7fffffff.
static inline float absBits(float f) {
    u32 b;
    __builtin_memcpy(&b, &f, 4);
    b &= 0x7fffffffu;
    __builtin_memcpy(&f, &b, 4);
    return f;
}

// 0x4e2c60: fastcall, ecx = 3x3 float matrix m (row-major by column offsets), edx = float v[3] (read, then overwritten).
// out.x = |m[6]*x| + |m[3]*y| + |m[0]*z|; out.y = |m[7]*x| + |m[4]*y| + |m[1]*z|; out.z = |m[8]*x| + |m[5]*y| + |m[2]*z|.
// Each term is a float multiply then fabs, summed left to right with float adds. GUESS: a 3x3 absolute-value transform.
static void FASTCALL absTransform_4e2c60(float *m, float *v) {
    float x = v[0], y = v[1], z = v[2];
    float o0 = absBits(m[6] * x);
    o0 = o0 + absBits(m[3] * y);
    o0 = o0 + absBits(m[0] * z);
    float o1 = absBits(m[7] * x);
    o1 = o1 + absBits(m[4] * y);
    o1 = o1 + absBits(m[1] * z);
    float o2 = absBits(m[8] * x);
    o2 = o2 + absBits(m[5] * y);
    o2 = o2 + absBits(m[2] * z);
    v[0] = o0;
    v[1] = o1;
    v[2] = o2;
}
PCREG(4e2c60, absTransform_4e2c60);

// 0x4e65e0: thiscall (ecx = out, two float stack args, ret 8), returns bool in al.
// Each of x and y maps to: v <= 1e-4 -> 10000.0; v >= 10000 -> 0; else 1/v. The compares use the unordered-aware
// jb of comiss (a NaN takes the same branch as the exe). Then s = out[1] + out[0]; if !(1e-4 > s) return 1; else
// both set to 1.0 and return 0. GUESS: a clamped reciprocal pair with a sum test.
static float clampedRecip_4e65e0(float v) {
    const float eps = 1e-4f;
    const float big = 10000.0f;
    if (!(eps >= v)) {
        if (!(v >= big)) return 1.0f / v;
        return 0.0f;
    }
    return big;
}

static u8 THISCALL recipPair_4e65e0(float *out, float x, float y) {
    const float eps = 1e-4f;
    out[0] = clampedRecip_4e65e0(x);
    out[1] = clampedRecip_4e65e0(y);
    float s = out[1] + out[0];
    if (!(eps > s)) return 1;
    out[1] = 1.0f;
    out[0] = 1.0f;
    return 0;
}
PCREG(4e65e0, recipPair_4e65e0);
