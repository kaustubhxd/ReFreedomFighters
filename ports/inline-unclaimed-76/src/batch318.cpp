// batch318.cpp - gap band 0x601000-0x621000 (docs/20-unclaimed-76.md): two float leaves (GUESS).
// 0x601590 (cdecl, plain ret, float on st0): (float)(s32)[engine+0x40] * [0x6785e4] where engine = [0x70039c].
// 0x60ffb0 (thiscall, plain ret, float on st0): (float)(s32)[this+0x84] / (float)(s32)[this+0x88].
#include "ff.h"

static float __attribute__((cdecl)) tick_601590(void) {
    u32 eng = G(u32, 0x70039cu);
    s32 t = *(s32 *)(eng + 0x40u);
    float scale = G(float, 0x6785e4u);
    return (float)t * scale;
}
PCREG(601590, tick_601590);

static float THISCALL ratio_60ffb0(u8 *self) {
    s32 a = *(s32 *)(self + 0x84u);
    s32 b = *(s32 *)(self + 0x88u);
    return (float)a / (float)b;
}
PCREG(60ffb0, ratio_60ffb0);
