// batch5802.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 102: 0x5d5400 (GUESS name unnamed_5d5400), thiscall, no stack args, plain ret.
// Branch 2 (this+0x54 == 2): if (s32)(engine+0x40) > this+0x4c: obj->vt[+0x250](0xfe); this+0x54 = 3; return. Else the division path.
// Branch 1 (this+0x54 == 1): if (s32)(engine+0x40) > this+0x4c: obj->vt[+0x250](0); obj->vt[+0xbc](1); this+0x54 = 0; return. Else the
// division path with 0x400 - q. Other values: return. Division path: q = ((long long)(s32)(engine+0x40 - this+0x50) << 10) / (long long)(s32)(this+0x4c -
// this+0x50) (the CRT _alldiv at 0x634290, signed); the value is ((0x3f800 * (s32)q_low) >> 10) (32-bit arithmetic shift of the shrd result);
// obj->vt[+0x250](value). The CRT helper is exact signed division, which the port does in C. The spec keeps this+0x50 != this+0x4c.
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef void(THISCALL *SlotI)(u8 *self, u32 a);

extern "C" unsigned long long STDCALL ext_634290(u32 alo, u32 ahi, u32 blo, u32 bhi);  // CRT signed 64-bit divide (_alldiv), original code

// 0x5d5400, thiscall, no stack args (GUESS name)
static void THISCALL unnamed5d5400(u8 *self) {
  u32 st = *(u32 *)(self + 0x54);
  if (st != 1 && st != 2) return;
  s32 eng40 = (s32)*(u32 *)(G(u8 *, 0x70039c) + 0x40);
  s32 x = (s32)*(u32 *)(self + 0x4c);
  u8 *obj = *(u8 **)(self + 0x44);
  if (eng40 > x) {
    if (st == 2) {
      ((SlotI)VT(obj)[0x250 / 4])(obj, 0xfe);
      *(u32 *)(self + 0x54) = 3;
    } else {
      ((SlotI)VT(obj)[0x250 / 4])(obj, 0);
      ((SlotI)VT(obj)[0xbc / 4])(obj, 1);
      *(u32 *)(self + 0x54) = 0;
    }
    return;
  }
  s32 n = (s32)*(u32 *)(self + 0x50);
  long long a = (long long)(s32)((u32)eng40 - (u32)n);
  long long b = (long long)(s32)((u32)x - (u32)n);
  unsigned long long a1 = (unsigned long long)a << 10;
  unsigned long long q = ext_634290((u32)a1, (u32)(a1 >> 32), (u32)b, (u32)((unsigned long long)b >> 32));
  s32 qlo = (s32)(u32)q;
  s32 mult = (st == 2) ? qlo : (s32)(0x400u - (u32)qlo);
  unsigned long long p = (unsigned long long)((long long)0x3f800 * (long long)mult);
  s32 value = (s32)((u32)(p >> 10)) >> 10;
  ((SlotI)VT(obj)[0x250 / 4])(obj, (u32)value);
}
PCREG(5d5400, unnamed5d5400);
