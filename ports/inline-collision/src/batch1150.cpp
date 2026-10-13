// batch1150.cpp - collision thread, batch 1150 (name GUESS: ZOctreeCompiled::Init): 0x4e3d60. Thiscall (ECX = this), one stack
// argument X, ret 4. Stores X at [this+0x14] and the dword at [X+0x10] at [this+0x10], copies the three floats at X+4, X+8,
// X+0xc into a local vector and calls 0x4e3360 (thiscall with this, the local as the stack argument; ret 4 - exe code, batch 501
// and batch 1401 ports exist). The security-cookie call at the exit is omitted (no effect when the cookie is intact).
#include "ff.h"

extern "C" void THISCALL ext_4e3360(void *self, float *v);   // exe: copies three floats from v into self+4..+0xc, ret 4

static void THISCALL init4e3d60(u8 *self, u8 *X) {
  *(u32 *)(self + 0x14) = (u32)X;
  *(u32 *)(self + 0x10) = *(u32 *)(X + 0x10);
  float v[3];
  v[0] = *(float *)(X + 4);
  v[1] = *(float *)(X + 8);
  v[2] = *(float *)(X + 0xc);
  ext_4e3360(self, v);
}
PCREG(4e3d60, init4e3d60);
