// batch370.cpp - area 76 (docs/20-unclaimed-76.md, lower half of label D): 0x4dfa30 (fastcall: ECX = out vector, EDX = vector E,
// stack: A, Q, R (vectors); ret 0xc; returns bool; GUESS). d = A.R = (R.x A.x + R.y A.y) + A.z R.z. If |d| (as double) >= 1e-10
// (the constant at 0x6970c8; NaN takes this branch): t = ((Q.y R.y + Q.x R.x) + Q.z R.z - ((E.y R.y + E.x R.x) + E.z R.z)) / d;
// out = (A.x t, t A.y, A.z t); call 0x441940 (thiscall, no arguments; hooked in the fixture); return true. Else return false.
#include "ff.h"

extern "C" void THISCALL ext_441940(u8 *self);

static u8 __attribute__((fastcall)) f4dfa30(u32 out, u32 E, u32 A, u32 Q, u32 R) {
    const float *a = (const float *)A;
    const float *q = (const float *)Q;
    const float *r = (const float *)R;
    const float *e = (const float *)E;
    float d = (r[0] * a[0] + r[1] * a[1]) + a[2] * r[2];
    double ad = (double)d;
    if (ad < 0.0) ad = -ad;
    double c = G(double, 0x6970c8u);
    if (c > ad) return 0u;
    float num = ((q[1] * r[1] + q[0] * r[0]) + q[2] * r[2]) - ((e[1] * r[1] + e[0] * r[0]) + e[2] * r[2]);
    float t = num / d;
    float *o = (float *)out;
    o[0] = a[0] * t;
    o[1] = t * a[1];
    o[2] = a[2] * t;
    ext_441940((u8 *)out);
    return 1u;
}
PCREG(4dfa30, f4dfa30);
