// batch387.cpp - area 76, residue 17 (out/functions.jsonl).
// 0x663d90 (thiscall, two stack arguments, ret 8; GUESS): 2D affine map of a picked pair of floats. this: [0] index i, [4] index j,
//   floats m at +8..+0x38. Reads x = src[i], y = src[j]; u = (m08*x + m0c*y + m10) * m20; w = (m14*x + m18*y + m1c) * m20;
//   out[0] = m2c*u + m24 + m34*w; out[1] = m30*u + m28 + m38*w. Single precision (SSE), same add order as the original.
#include "ff.h"

#define MF(o) (*(float *)(self + (o)))

static void THISCALL f663d90(u8 *selfp, float *out, float *src) {
    u32 self = (u32)selfp;
    float y = src[*(u32 *)(self + 4u)];
    float x = src[*(u32 *)self];
    float u = (MF(0x8u) * x + MF(0xcu) * y + MF(0x10u)) * MF(0x20u);
    float w = (MF(0x14u) * x + MF(0x18u) * y + MF(0x1cu)) * MF(0x20u);
    out[0] = MF(0x2cu) * u + MF(0x24u) + MF(0x34u) * w;
    out[1] = MF(0x30u) * u + MF(0x28u) + MF(0x38u) * w;
}
PCREG(663d90, f663d90);

#undef MF
