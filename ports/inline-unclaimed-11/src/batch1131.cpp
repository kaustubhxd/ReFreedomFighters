// batch1131.cpp - unclaimed-11 batch 32 (gap band): 0x5ab970, GUESS (no name). Returns an int.
#include "ff.h"

extern "C" void THISCALL ext_4db7c0(void *chain, float *out);   // stubbed in the harness; out is a vec3, the PC reads .y

// 0x5ab970, GUESS: d = [this+0x72] - [this+0x6e]; (d & ~0xf) == 0 gives 0; otherwise vec = 0x4db7c0 on R, result (int)(vec.y * K).
static s32 THISCALL guessScaledY(u8 *self) {
  u32 p = *(u32 *)(self + 0x6e);
  s32 d = (s32)(*(u32 *)(self + 0x72) - p);
  if ((d & (s32)0xfffffff0) == 0) return 0;
  u32 q = *(u32 *)(p + 8);
  u32 r = *(u32 *)(q + 8);
  float vec[3];
  ext_4db7c0((void *)r, vec);
  return (s32)(vec[1] * G(float, 0x680a60));
}
PCREG(5ab970, guessScaledY);
