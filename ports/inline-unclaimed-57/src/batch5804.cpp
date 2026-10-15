// batch5804.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 104: 0x5ddb00 (GUESS name unnamed_5ddb00), thiscall, no stack args, plain ret.
// The same shape as 0x5d5400 (batch 102) with the state at this+0x5c. State 1: if (s32)(engine+0x40) > this+0x4c: obj->vt[+0x250](0xfe),
// this+0x5c = 3, return. Else the division path with mult = q. State 2: if (s32)(engine+0x40) > this+0x4c: obj->vt[+0x250](0), obj->vt[+0xbc](1),
// this+0x5c = 0, return. Else the division path with mult = 0x400 - q. Other states return. Division path: n = this+0x50; a = (s64)(s32)(engine+0x40 - n);
// b = (s64)(s32)(this+0x4c - n); q = _alldiv(a << 10, b) (CRT helper 0x634290 at original code); v = ((0x3f800 * mult) >> 10) with a 32-bit arithmetic
// shift; obj->vt[+0x250](v).
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef void(THISCALL *SlotI)(u8 *self, u32 a);

extern "C" unsigned long long STDCALL ext_634290(u32 alo, u32 ahi, u32 blo, u32 bhi);  // CRT signed 64-bit divide (_alldiv), original code

// 0x5ddb00, thiscall, no stack args (GUESS name)
static void THISCALL unnamed5ddb00(u8 *self) {
  u32 st = *(u32 *)(self + 0x5c);
  if (st != 1 && st != 2) return;
  s32 eng40 = (s32)*(u32 *)(G(u8 *, 0x70039c) + 0x40);
  s32 x = (s32)*(u32 *)(self + 0x4c);
  u8 *obj = *(u8 **)(self + 0x44);
  if (eng40 > x) {
    if (st == 1) {
      ((SlotI)VT(obj)[0x250 / 4])(obj, 0xfe);
      *(u32 *)(self + 0x5c) = 3;
    } else {
      ((SlotI)VT(obj)[0x250 / 4])(obj, 0);
      ((SlotI)VT(obj)[0xbc / 4])(obj, 1);
      *(u32 *)(self + 0x5c) = 0;
    }
    return;
  }
  s32 n = (s32)*(u32 *)(self + 0x50);
  long long a = (long long)(s32)((u32)eng40 - (u32)n);
  long long b = (long long)(s32)((u32)x - (u32)n);
  unsigned long long a1 = (unsigned long long)a << 10;
  unsigned long long q = ext_634290((u32)a1, (u32)(a1 >> 32), (u32)b, (u32)((unsigned long long)b >> 32));
  s32 qlo = (s32)(u32)q;
  s32 mult = (st == 1) ? qlo : (s32)(0x400u - (u32)qlo);
  unsigned long long p = (unsigned long long)((long long)0x3f800 * (long long)mult);
  s32 value = (s32)((u32)(p >> 10)) >> 10;
  ((SlotI)VT(obj)[0x250 / 4])(obj, (u32)value);
}
PCREG(5ddb00, unnamed5ddb00);
