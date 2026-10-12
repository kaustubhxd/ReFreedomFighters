// batch320.cpp - gap band 0x601000-0x621000 (docs/20-unclaimed-76.md): two fixed-point fractional getters (thiscall, plain ret, float on st0,
// GUESS). x = [this+ox]. If x == 0.0 (ordered), return [this+ov]. Otherwise: t = (s32)(x * K1); g = (s64)t * (s32)[engine+0x40]
// (engine = [0x70039c]); c = (s32)([this+ov] * K2); q = low dword of (u64)g >> 10; d = (s32)(q - c); v = (float)d * K3;
// if v >= 0 (or unordered) return v - (float)(s32)v; else return v - (float)((s32)v - 1). K1 = [0x678620], K2 = [0x67862c], K3 = [0x6785e4].
// 0x60d840: ox = 0x18, ov = 0x10. 0x60d8e0: ox = 0x1c, ov = 0x14.
#include "ff.h"

static float fracPart_s(u8 *self, u32 ox, u32 ov) {
    float x = *(float *)(self + ox);
    if (x == 0.0f) return *(float *)(self + ov);
    s32 t = (s32)(x * G(float, 0x678620u));
    u32 eng = G(u32, 0x70039cu);
    long long g = (long long)t * (long long)*(s32 *)(eng + 0x40u);
    s32 c = (s32)(*(float *)(self + ov) * G(float, 0x67862cu));
    u32 q = (u32)((u64)g >> 10);
    s32 d = (s32)(q - (u32)c);
    float v = (float)d * G(float, 0x6785e4u);
    s32 tr = (s32)v;
    if (!(v < 0.0f)) return v - (float)tr;
    return v - (float)(tr - 1);
}

static float THISCALL frac_60d840(u8 *self) { return fracPart_s(self, 0x18u, 0x10u); }
PCREG(60d840, frac_60d840);

static float THISCALL frac_60d8e0(u8 *self) { return fracPart_s(self, 0x1cu, 0x14u); }
PCREG(60d8e0, frac_60d8e0);
