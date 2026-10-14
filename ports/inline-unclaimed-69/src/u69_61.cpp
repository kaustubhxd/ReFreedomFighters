// u69_61.cpp - area 69, group 61 (slice 8). A float clamp stored into the object, then a call to 0x4314c0 (other area, GUESS stub: thiscall, two stack args, ret 8 assumed).
#include "ff.h"

extern "C" void THISCALL ext_4314c0(void *self, u32 s, float v);  // stack args: s (0x67a00c) first, then v

// 0x433440, thiscall one stack arg (x, float, ret 4). If x equals the float at self+0xe4 (ordered), returns at once. Otherwise
// v = (A > x) ? A : min(B, x) with A = the float at 0x67a284 and B = the float at 0x678858 (minss semantics: B < x ? B : x); stores v at self+0xe4,
// then calls 0x4314c0(self, 0x67a00c, v).
static void THISCALL clamp433440(u8 *self, float x) {
  if (x == *(float *)(self + 0xe4))
    return;
  float A = *(float *)0x67a284;
  float B = *(float *)0x678858;
  float v = (A > x) ? A : ((B < x) ? B : x);
  *(float *)(self + 0xe4) = v;
  ext_4314c0(self, 0x67a00c, v);
}
PCREG(433440, clamp433440);
