// batch34164.cpp - cascade tier H, batch 34164: 0x58aaf0 (apply 21-byte records), 0x54c8f0 (clamped count to a slot), 0x650f30 (bucket thresholds).
#include "ff.h"

extern "C" u32 THISCALL ext_549780(void *self, u32 f);   // ret 4
extern "C" u32 THISCALL ext_5496e0(void *self, u32 a);   // ret 4

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x58aaf0, ecx = this (vtable), edx = p: this->slot0x3c([p]); for each of [p] records of 0x15 bytes at p + 4 (count re-read each step): this->slot0x68(rec + 4), this->slot0x60(byte rec[0x10]), this->slot0x4c(float bits at rec + 0x11, unaligned). Returns this.
static u8 *FASTCALL fn58aaf0(u8 *self, u8 *p) {
  vcall<void>(self, 0x3c, *(u32 *)p);
  u8 *rec = p + 4;
  while (rec != p + 4 + *(s32 *)p * 0x15) {
    vcall<void>(self, 0x68, (u32)(rec + 4));
    vcall<void>(self, 0x60, (u32)rec[0x10]);
    vcall<void>(self, 0x4c, rd32(rec + 0x11));
    rec += 0x15;
  }
  return self;
}
PCREG(58aaf0, fn58aaf0);

// 0x54c8f0, thiscall(a) ret 4: o = [this+0x63ec]; r = ext_549780(this, unaligned float [this+0x63d7]); o's vtable slot 0x3c(o, r) (stdcall, ecx unspecified); v = ext_5496e0(this, [a+0x28]); v = min(v, 100000), max(v, 100) (signed); o's vtable slot 0x44(o, v).
static void THISCALL fn54c8f0(u8 *self, u8 *a) {
  u8 *o = *(u8 **)(self + 0x63ec);
  u8 *vt = *(u8 **)o;
  u32 r = ext_549780(self, rd32(self + 0x63d7));
  typedef void (STDCALL *sf)(u8 *, u32);
  (*(sf *)(vt + 0x3c))(*(u8 **)(self + 0x63ec), r);
  s32 v = (s32)ext_5496e0(self, *(u32 *)(a + 0x28));
  if (v > 100000) {
    o = *(u8 **)(self + 0x63ec);
    (*(sf *)(*(u8 **)o + 0x44))(o, 100000);
    return;
  }
  if (v < 100) v = 100;
  o = *(u8 **)(self + 0x63ec);
  (*(sf *)(*(u8 **)o + 0x44))(o, (u32)v);
}
PCREG(54c8f0, fn54c8f0);

// 0x650f30, thiscall(i) ret 4: table = 8 floats at 0x6c33b8 + 32 * i; for each index k below the count at [0x6f5a98] (unsigned, re-read): thr = (float)((double)(k + 1) + (k+1 < 0 ? 2^32 : 0)); the byte [[this+0x10] + k] = the first table slot j < 8 with table[j] >= thr (ordered), else 7.
static void THISCALL fn650f30(u8 *self, u32 i) {
  float *tbl = (float *)(0x6c33b8 + (i << 5));
  u32 edx = 0;
  while (edx < G(u32, 0x6f5a98)) {
    u32 ebx = edx + 1;
    double d = (double)(s32)ebx + ((ebx >> 31) ? 4294967296.0 : 0.0);
    float thr = (float)d;
    u32 j = 0;
    for (; j < 8; j++) {
      if (_mm_comige_ss(_mm_set_ss(tbl[j]), _mm_set_ss(thr))) {
        (*(u8 **)(self + 0x10))[edx] = (u8)j;
        break;
      }
    }
    if (j == 8) (*(u8 **)(self + 0x10))[edx] = 7;
    edx = ebx;
  }
}
PCREG(650f30, fn650f30);
