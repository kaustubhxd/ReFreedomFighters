// batch342.cpp - gap band 0x601000-0x621000 (docs/20-unclaimed-76.md): 0x60ffe0 (thiscall, ten float arguments a0..a9, ret 0x28; GUESS).
// x3 = -(((a3 - a2) * a7) / a9); x6 = -(((a1 - a0) * a6) / a8). Then the exe helper 0x610250 (ECX = the incoming ECX, six floats; ret 0x18,
// pure: it writes an object at ECX and makes no calls) with (x6 + a0, x6 + a1, x3 + a3, x3 + a2, a4, a5).
#include "ff.h"

extern "C" void THISCALL ext_610250(u32 ecx, float p0, float p1, float p2, float p3, float p4, float p5);

static void THISCALL frame_60ffe0(u32 ecx, float a0, float a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8,
                                  float a9) {
    float x3 = (a3 - a2) * a7;
    x3 = x3 / a9;
    x3 = -x3;
    float x6 = (a1 - a0) * a6;
    x6 = x6 / a8;
    x6 = -x6;
    ext_610250(ecx, x6 + a0, x6 + a1, x3 + a3, x3 + a2, a4, a5);
}
PCREG(60ffe0, frame_60ffe0);
