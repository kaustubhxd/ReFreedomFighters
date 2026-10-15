// batch67513.cpp - cascade s6 batch 67513: 0x5d5400.
#include "ff.h"

typedef long long s64;

extern "C" u64 STDCALL ext_634290(u32 numLo, u32 numHi, u32 denLo, u32 denHi);   // __alldiv: signed 64-bit divide, result in edx:eax, pops 16

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x5d5400, thiscall(), plain ret: advances a timed fade of the object at +0x44. State +0x54: 2 = fading in, 1 = fading out (sibling of 0x5ddb00 with the state at +0x54 and the codes swapped). With `now` (engine +0x40) past the end time (+0x4c) a
// fade-in tells the object slot 0x250 (0xfe) and becomes state 3, a fade-out sets 0, shows (slot 0xbc, 1) and becomes state 0. Otherwise the progress q = ((now - start) << 10) /
// (end - start) (start = +0x50, 64-bit arithmetic) drives slot 0x250 with ((0x3f800 * q) >> 10) >> 10 for a fade-in and with ((0x3f800 * (0x400 - q)) >> 10) >> 10 for a fade-out.
static void THISCALL fn5d5400(u8 *self) {
  u32 state = D32(self, 0x54);
  if (state != 1 && state != 2) return;
  s32 now = (s32)D32(*(u8 **)0x70039c, 0x40);
  s32 end = (s32)D32(self, 0x4c);
  if (now > end) {
    if (state == 2) {
      vcall<void>(*(void **)(self + 0x44), 0x250, 0xfeu);
      D32(self, 0x54) = 3;
    } else {
      vcall<void>(*(void **)(self + 0x44), 0x250, 0u);
      vcall<void>(*(void **)(self + 0x44), 0xbc, 1u);
      D32(self, 0x54) = 0;
    }
    return;
  }
  s32 start = (s32)D32(self, 0x50);
  s64 num = (s64)(now - start) << 10;
  s64 den = (s64)(end - start);
  u64 qq = ext_634290((u32)num, (u32)((u64)num >> 32), (u32)den, (u32)((u64)den >> 32));
  s32 q = (s32)(u32)qq;
  s32 ecx = state == 2 ? q : 0x400 - q;
  s64 prod = (s64)0x3f800 * (s64)ecx;
  s32 lo10 = (s32)(u32)((u64)(prod >> 10));   // shrd eax, edx, 10
  u32 lo = (u32)(lo10 >> 10);                 // sar eax, 10
  vcall<void>(*(void **)(self + 0x44), 0x250, lo);
}
PCREG(5d5400, fn5d5400);
