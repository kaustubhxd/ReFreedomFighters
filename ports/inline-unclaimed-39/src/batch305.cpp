// batch305.cpp - decomp area 39 (docs/20-unclaimed-39.md), slice floor(addr/16) mod 20 == 18.
#include "ff.h"

// Exe helper 0x451890: fastcall (ECX = dst vec3, EDX = src vec3, one float stack argument s, ret 4).
// dst[i] = dst[i] + src[i] * s, in x87 double precision, stored as float. Runs as original code.
extern "C" void FASTCALL ext_451890(u8 *dst, u8 *src, float s);

// Virtual call on the global system object at 0x70039c: slot 0x1c0, thiscall with two stack words (name, id).
// It returns a float in st0.
typedef float(__attribute__((thiscall)) * Slot1c0Fn)(u8 *, u32, u32);

// 0x55eae0: stdcall (three pointer arguments P, Q, R; ret 0xc).
// S = P->[+8]; A = S[+0x40]; B = S[+0x48]. u = Q[+0x18..+0x20], w = Q[+0..+8].
// r1 = sys->vtbl[0x1c0](sys, 0x6a5eb0, 0x411); V = (float)((r1 - 0.5) * A).
// r2 = sys->vtbl[0x1c0](sys, 0x6a5eb0, 0x412); W = (float)((r2 - 0.5) * B).
// ext 0x451890(R, u, 2V); ext 0x451890(R, w, 2W). GUESS: two weighted accumulations into R.
static void STDCALL blend_55eae0(u8 *P, u8 *Q, u8 *R) {
    u8 *S = *(u8 **)(P + 8);
    float A = *(float *)(S + 0x40);
    float B = *(float *)(S + 0x48);
    float u[3] = {*(float *)(Q + 0x18), *(float *)(Q + 0x1c), *(float *)(Q + 0x20)};
    float w[3] = {*(float *)(Q + 0), *(float *)(Q + 4), *(float *)(Q + 8)};
    float K = G(float, 0x67a6ac);

    u8 *sys = G(u8 *, 0x70039c);
    void **vt = *(void ***)sys;
    float r1 = ((Slot1c0Fn)vt[0x1c0 / 4])(sys, 0x6a5eb0u, 0x411u);
    float V = (float)(((double)r1 - (double)K) * (double)A);

    sys = G(u8 *, 0x70039c);
    vt = *(void ***)sys;
    float r2 = ((Slot1c0Fn)vt[0x1c0 / 4])(sys, 0x6a5eb0u, 0x412u);
    float W = (float)(((double)r2 - (double)K) * (double)B);

    ext_451890(R, (u8 *)u, V + V);
    ext_451890(R, (u8 *)w, W + W);
}
PCREG(55eae0, blend_55eae0);
