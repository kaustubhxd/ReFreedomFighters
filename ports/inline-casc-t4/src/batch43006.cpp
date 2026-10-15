// batch43006.cpp - t4 (Sonnet) batch 43006: tier H float/SSE functions
#include "ff.h"

extern "C" s32 THISCALL ext_549780(u8 *self, float f);          // thiscall ret 4
extern "C" s32 THISCALL ext_5496e0(u8 *self, s32 n);            // thiscall ret 4

// 0x58aaf0, fastcall(this, b) plain ret, returns this: this->slot 0x3c(b[0]); for each of b[0] records of 0x15 bytes at b+4 (count re-read each pass):
// this->slot 0x68(rec+4); this->slot 0x60(byte rec[0x10]); this->slot 0x4c(float at rec+0x11, unaligned)
static u8 *__attribute__((fastcall)) fn58aaf0(u8 *self, u8 *b) {
  vcall<void>(self, 0x3c, *(u32 *)b);
  for (u8 *rec = b + 4; rec != b + 4 + *(u32 *)b * 0x15; rec += 0x15) {
    vcall<void>(self, 0x68, (u32)(rec + 4));
    vcall<void>(self, 0x60, (u32)rec[0x10]);
    vcall<void>(self, 0x4c, *(float *)(rec + 0x11));
  }
  return self;
}
PCREG(58aaf0, fn58aaf0);

// 0x54c8f0, thiscall(a) ret 4: o = [this+0x63ec]; r = 0x549780(this, [this+0x63d7]); o->slot 0x3c(o, r) (stdcall, vtable read before the call);
// n = 0x5496e0(this, [a+0x28]); n > 100000 -> 100000, else max(n, 100) (signed); o' = [this+0x63ec]; vtable[0x44](o', n) (stdcall)
typedef void(STDCALL *sc2_t)(u8 *, s32);
static void THISCALL fn54c8f0(u8 *self, u8 *a) {
  u8 *o = *(u8 **)(self + 0x63ec);
  u8 *vt = *(u8 **)o;
  s32 r = ext_549780(self, *(float *)(self + 0x63d7));
  (*(sc2_t *)(vt + 0x3c))(*(u8 **)(self + 0x63ec), r);
  s32 n = ext_5496e0(self, *(s32 *)(a + 0x28));
  if (n > 100000) n = 100000;
  else if (n < 100) n = 100;
  u8 *o2 = *(u8 **)(self + 0x63ec);
  (*(sc2_t *)(*(u8 **)o2 + 0x44))(o2, n);
}
PCREG(54c8f0, fn54c8f0);

// 0x650f30, thiscall(i) ret 4: row = float[8] at 0x6c33b8 + i * 32; for d < (unsigned)[0x6f5a98]: key = (float)(d + 1) (unsigned via the table at 0x680aa0);
// k = first index < 8 with row[k] >= key (ordered); byte [[this+0x10] + d] = k, or 7 when none
static void THISCALL fn650f30(u8 *self, u32 i) {
  float *row = (float *)(0x6c33b8 + i * 32);
  for (u32 d = 0; d < G(u32, 0x6f5a98); d++) {
    u32 e = d + 1;
    float key = (float)((double)(s32)e + ((double *)0x680aa0)[e >> 31]);
    u32 k = 0;
    for (; k < 8; k++) {
      if (row[k] >= key) {
        (*(u8 **)(self + 0x10))[d] = (u8)k;
        break;
      }
    }
    if (k == 8) (*(u8 **)(self + 0x10))[d] = 7;
  }
}
PCREG(650f30, fn650f30);
