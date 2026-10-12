// batch6440.cpp - unclaimed-68 batch 44 (claim 44, gap band). Name from the GC name map (low confidence).
#include "ff.h"

// 0x4c0a20, ZDllSound::GetPitchChange(int) (low): one stack argument, ret 4, the float result in ST0. arg 0 gives 1.0; a positive arg gives
// arg / 1200 + 1.0; a negative arg gives 1 / (1 - arg / 1200). (The first two constants are read from the exe: 1200.0 and 1.0.)
static float STDCALL dllSoundGetPitchChange(s32 arg) {
  const float one = G(float, 0x678858);
  const float k = G(float, 0x68af24);
  if (arg == 0) return one;
  if (arg > 0) {
    float x = (float)arg / k;
    return x + one;
  }
  float x = (float)arg / k;
  float d = one - x;
  return one / d;
}
PCREG(4c0a20, dllSoundGetPitchChange);
