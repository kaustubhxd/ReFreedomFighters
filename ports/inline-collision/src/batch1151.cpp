// batch1151.cpp - collision thread, batch 1151 (name GUESS: ZOctreeCompiled::CheckPoint): 0x4e3c20. Thiscall (ECX = this), two
// stack arguments (out, v), ret 8. The three coordinates (v - this+4/+8/+0xc) scaled by this+0x10 and offset by 32768.0f are
// truncated to integers at out+0x50, +0x54, +0x58. out+0xc = this+0x14 + 0x14; out+0x10 = [this+0x14] + this+0x14 (the
// dword at that block plus its address); out+0x2c = 0. Then 0x4e3ae0 (batch 239's cell traverse, thiscall(node) with stack
// (out, 0x8000, 0x8000, 0x8000), ret 0x10) runs as exe code with ECX = this+0x14 + 0x14.
#include "ff.h"

extern "C" void THISCALL ext_4e3ae0(void *node, u8 *S, s32 A, s32 B, s32 C);   // exe: cell traverse, ret 0x10

static void THISCALL checkPoint4e3c20(u8 *self, u8 *out, const float *v) {
  const float c = G(float, 0x6972d4);
  float sx = (v[0] - *(float *)(self + 4)) * *(float *)(self + 0x10) + c;
  *(s32 *)(out + 0x50) = (s32)sx;
  float sy = (v[1] - *(float *)(self + 8)) * *(float *)(self + 0x10) + c;
  *(s32 *)(out + 0x54) = (s32)sy;
  float sz = (v[2] - *(float *)(self + 0xc)) * *(float *)(self + 0x10) + c;
  *(s32 *)(out + 0x58) = (s32)sz;
  u32 p = *(u32 *)(self + 0x14);
  *(u32 *)(out + 0xc) = p + 0x14;
  *(u32 *)(out + 0x10) = *(u32 *)p + p;
  *(u32 *)(out + 0x2c) = 0;
  ext_4e3ae0((void *)(p + 0x14), out, 0x8000, 0x8000, 0x8000);
}
PCREG(4e3c20, checkPoint4e3c20);
