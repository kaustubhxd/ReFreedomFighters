#include "ff.h"
// batch7921.cpp - unclaimed-79 batch 21 (docs/20-unclaimed-79.md, gap band). Name from the GC name map (high).
// Orchestration verified, helpers stubbed: the helpers below run as original code (call-recording stubs in the harness).

extern "C" void FASTCALL ext_43e920(u8 *ecx, u8 *edx, u8 *a);
extern "C" void THISCALL ext_4e09b0(u8 *self);
extern "C" void FASTCALL ext_4de040(u8 *ecx, u8 *edx, u32 a);
extern "C" void THISCALL ext_4825c0(u8 *self, u8 *a, u8 *b, u8 *c, u8 *d);

// 0x4835c0, ZPlayer::ForceFacing(const float*) (high). Thiscall, one stack argument (ret 4). Zeroes a local vector, asks slot +0x84
// for it, subtracts it from the direction into a second local (0x43e920), normalises that (0x4e09b0), builds a matrix (0x4de040),
// asks slot +0x59c for a third vector, and calls 0x4825c0 (ContactMove) with the four vectors.
static void THISCALL playerForceFacing(u8 *self, u8 *dir) {
  u32 v10[3] = {0, 0, 0};
  vcall<void, u32 *>(self, 0x84, v10);
  u32 v1c[3] = {0, 0, 0};
  ext_43e920((u8 *)v1c, dir, (u8 *)v10);
  v1c[1] = 0;
  ext_4e09b0((u8 *)v1c);
  u32 m40[16] = {0};
  ext_4de040((u8 *)m40, (u8 *)v1c, 0u);
  u32 v64[3] = {0, 0, 0};
  vcall<void, u8 *, u8 *>(self, 0x59c, (u8 *)v64, (u8 *)v10);
  ext_4825c0(self, (u8 *)v64, (u8 *)v10, (u8 *)m40, (u8 *)v10);
}
PCREG(4835c0, playerForceFacing);
