// batch1621.cpp - ZDllSound group volume / pitch readers and the delay-time helper (soundtimers thread, 2026-10-11).
// Group table: the address is this + group*9 + 0x5159 for the volume float and this + group*9 + 0x515e for the
// pitch int (the original computes lea eax,[ecx+edx*8] and then indexes [edx+eax+off], which is group*9).
#include "st.h"

// 0x5370b0 ZDllSound::GetGroupVolume(int group) [high]: group volume as a percentage (the stored float x 100).
long double THISCALL ZDllSound_GetGroupVolume(u8 *self, u32 group) {
  float v = AT(float, self, group * 9 + 0x5159);
  return (long double)v * 100.0L;  // x87 fmul, full precision in ST0
}
PCREG(5370b0, ZDllSound_GetGroupVolume);

// 0x537090 ZDllSound::GetGroupPitch(int group) [high]: the group's stored pitch (int).
s32 THISCALL ZDllSound_GetGroupPitch(u8 *self, u32 group) {
  return AT(s32, self, group * 9 + 0x515e);
}
PCREG(537090, ZDllSound_GetGroupPitch);

// 0x535750 ZDllSound::CalcDelayTime(float t) [high]: 0 while t < 1000 (the limit is 1000.0 at 0x67d164; a NaN is not
// below it, so it scales), otherwise t x 0.00291545 (x87; the scale is used for delay in the reverb, not traced
// further).
long double THISCALL ZDllSound_CalcDelayTime(u8 *self, float t) {
  if (t < 1000.0f) return 0.0L;
  return (long double)t * (long double)0.0029154520016163588f;  // fmul in x87: the product is kept at full precision
}
PCREG(535750, ZDllSound_CalcDelayTime);
