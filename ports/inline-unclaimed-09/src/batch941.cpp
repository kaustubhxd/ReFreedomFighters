// batch941.cpp - unclaimed-09 batch 33: ZRunParamAnim::Run(TIMETYPE) (core list; docs/20-unclaimed-09.md, claim 35).
// thiscall, one stack argument, ret 4, returns a float in st0. The CRT 64-bit helper 0x634380 is original code; the list's
// vtable calls are unverified (GUESS recording stubs in the spec).
#include "ff.h"

// CRT 64-bit helper (stdcall, four dword arguments: lo and hi of the dividend, then of the divisor); original code.
extern "C" u64 STDCALL ext_634380(u32 loP, u32 hiP, u32 loQ, u32 hiQ);

typedef long long s64;

typedef u8 *(THISCALL *ListCall)(u8 *self, u32 *flag);  // vt+0x4c (begin) and vt+0x5c (next); both write the flag

static u32 slot(u8 *obj, u32 off) {
  return *(u32 *)(*(u32 *)obj + off);
}

// 0x4e6f80, ZRunParamAnim::Run(TIMETYPE) (list name; see claim 35). Returns the float at this+0xbd.
static float THISCALL runParamAnimRun(u8 *self, u32 time) {
  float f = *(float *)(self + 0xb8) * G(float, 0x678620);
  s32 t32 = (s32)f;                       // cvttss2si: truncation (the x86 result for out-of-range is the same instruction)
  s64 P = (s64)t32 * (s64)(s32)time;      // one-operand imul: 32 x 32 -> 64, signed
  u32 edi = *(u32 *)(self + 8);
  if (edi == 0) return G(float, 0x67af2c);
  if (*(u8 *)(self + 0xbc) == 0) {
    s64 a = P >> 20;                      // shrd by 20 then sar: arithmetic shift of the 64-bit value
    s64 b = (s64)(s32)edi;
    if (a > b) return G(float, 0x67af2c);
  }
  u32 sh = edi << 20;
  s64 Q = (s64)(s32)sh;
  u64 r = ext_634380((u32)P, (u32)((u64)P >> 32), (u32)Q, (u32)((u64)Q >> 32));
  s32 v = (s32)(u32)(r >> 10);            // shrd eax, edx, 10: low dword of the 64-bit value shifted right by 10
  *(float *)(self + 0xbd) = (float)v * G(float, 0x6785e4);

  u8 *list = self + 0xc;
  u32 flag = 0;
  ((ListCall)slot(list, 0x4c))(list, &flag);
  u8 *node = ((ListCall)slot(list, 0x5c))(list, &flag);
  while (flag != 0) {
    u8 *key = *(u8 **)(node + 8);
    *(u8 **)(node + 0x14) = key;
    float bd = *(float *)(self + 0xbd);
    float kf = (float)*(s32 *)key;
    if (bd > kf) {
      u32 step = *(u32 *)node;
      u32 end = *(u32 *)(node + 0xc);
      for (;;) {
        u32 cur = *(u32 *)(node + 0x14) + step;
        *(u32 *)(node + 0x14) = cur;
        if (cur == end) break;
        float cf = (float)*(s32 *)cur;
        if (!(bd > cf)) break;
      }
    }
    u32 n4 = *(u32 *)(node + 4) + 0xffefffffu;
    u32 cursor = *(u32 *)(node + 0x14);
    u32 prev = cursor - *(u32 *)node;
    *(u32 *)(node + 0x10) = prev;
    if (n4 <= 1) {
      float t0 = (float)*(s32 *)prev;
      float t1 = (float)*(s32 *)cursor;
      float bdv = *(float *)(self + 0xbd);
      float x2 = bdv - t0;
      float d = t1 - t0;
      float c4 = *(float *)(cursor + 4) - *(float *)(prev + 4);
      float res = (x2 / d) * c4 + *(float *)(prev + 4);
      *(float *)(node + 0x18) = res;
    }
    node = ((ListCall)slot(list, 0x5c))(list, &flag);
  }
  return *(float *)(self + 0xbd);
}
PCREG(4e6f80, runParamAnimRun);
