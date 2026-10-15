// batch46002.cpp - cascade t7 (Sonnet), tier G: 0x549840 (stream refill/decode step: fetch samples via slot 0x78, decode/zero-fill, report via slot 0x74).
#include "ff.h"

extern "C" u32 FASTCALL ext_54d470(void *self7f, void *out, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);  // ecx=this, edx=out, ret 0x18
extern "C" u32 THISCALL ext_54e1f0(void *self, u32 a, u32 b, u32 *c, u32 d);                                    // ret 0x10
extern "C" void *ext_634d10(void *p, u32 v, u32 n);                                                             // cdecl memset
extern "C" void *ext_634d22(void *d, const void *s, u32 n);                                                     // cdecl memcpy

static inline u8 *rec(u8 *self) { return *(u8 **)(self + 0x5d); }
static inline u32 &W(u8 *p, u32 off) { return *(u32 *)(p + off); }
static inline void report(u8 *self, u32 a, u32 b, u32 c, u32 d) { vcall<void>(self, 0x74, a, b, c, d); }

static u32 THISCALL fn549840(u8 *self) {
  u32 L18 = 0, L0c = 0, L10 = 0, L14 = 0, L08 = 0, L04 = 0, L1c = 0, ebx = 0, esi;
  u32 mode = W(self, 0x75);
  if (mode == 3) {
    if (self[0x7c]) {
      u8 r = vcall<u8>(self, 0, (u32)&L18);
      if (!r) return 0;
      esi = W(self, 0x10) >> 1;
    } else {
      esi = W(self, 0x10);
      L18 = 0;
    }
  } else {
    esi = W(rec(self), 0x14);
  }
  if (!esi) return 0;
  if (mode == 1) {
    u8 *o = *(u8 **)(self + 8);
    ebx = vcall<u32>(o, 0x98, W(rec(self), 0x20));
    esi = W(rec(self), 0x14);
    L1c = esi;
  } else if (mode == 3) {
    u8 *e = *(u8 **)(self + 0x29);
    ebx = W(e, 0x47) * W(self, 0x40ad) + W(e, 0x4f);
    L1c = W(self, 0x40a9);
  }
  u32 type = W(rec(self), 8) & 0x7fffffff;
  if (type == 0x11) {
    vcall<void>(self, 0x78, L18, esi, (u32)&L0c, (u32)&L10, (u32)&L14, (u32)&L08);
    if (W(self, 0x75) == 1) {
      u8 *r = rec(self);
      u32 edx = W(r, 0x28) * W(r, 0x1c);
      W(self, 0x93) = ebx;
      W(self, 0x409f) = W(r, 0x18);
      u32 a6 = (u32)((s32)W(self, 0x40a9) >> 1);
      ext_54d470(self + 0x7f, (void *)L0c, ebx, 0, W(r, 0xc), (edx >> 2) - 1, W(r, 0x24), a6);
    } else {
      u8 *r = rec(self);
      u32 a6 = (u32)((s32)L10 >> 1);
      u32 n = (W(r, 0x28) * W(r, 0x1c) >> 2) - 1;
      u32 pos = W(r, 0x24);
      L1c = pos;
      W(self, 0x40a3) = W(self, 0x29);
      u32 b7 = self[0x7b];
      L04 = 0;
      u32 e = ext_54d470(self + 0x7f, (void *)L0c, (u32)(self + 0x9f), b7, W(r, 0xc), n, pos, a6);
      ebx = e;
      if (ebx) {
        if (L08 == 0) ext_634d10((void *)(L0c + (a6 - ebx) * 2), 0, ebx * 2);
      }
      if (L08 != 0 && ebx == 0) {
        L04 = L10 + L08;
        ebx = ext_54d470(self + 0x7f, (void *)L14, (u32)(self + 0x9f), self[0x7b], W(rec(self), 0xc), n, L1c, (u32)((s32)L08 >> 1));
      }
      esi -= ebx * 2;
      L04 = esi;
      if (!self[0x7c]) W(self, 0x1c) = 0;
    }
    report(self, L0c, L10, L14, L08);
    return 1;
  }
  if (type == 0x1000) {
    W(self, 0x40b6) = W(self, 0x29);
    W(self, 0x63cf) = 0;
    W(self, 0x63d3) = W(rec(self), 0x14);
    u8 *sub = self + 0x40b1;
    u8 r = vcall<u8>(sub, 8);
    if (!r) return 0;
    vcall<void>(self, 0x78, L18, esi, (u32)&L0c, (u32)&L10, (u32)&L14, (u32)&L08);
    if (esi != 0) {
      W(self, 0x63cf) = L0c;
      L04 = 0;
      vcall<void>(sub, 0xc, L10, (u32)&L04);
      ebx = L04;
      if (ebx != L10) {
        ext_634d10((void *)(L0c + ebx), 0, L10 - ebx);
        ebx = L04;
      }
      if (L08 != 0 && ebx != 0) {
        W(self, 0x63cf) = L14;
        vcall<void>(sub, 0xc, L08, (u32)&L04);
        u32 ecx = L04;
        ebx += ecx;
        if (ecx != L08) ext_634d10((void *)(L14 + ecx), 0, L08 - ecx);
      }
      L04 = ebx;
      W(self, 0x1c) += ebx - esi;
    }
    report(self, L0c, L10, L14, L08);
    return 1;
  }
  if (type == 1) {
    vcall<void>(self, 0x78, L18, esi, (u32)&L0c, (u32)&L10, (u32)&L14, (u32)&L08);
    u32 eax;
    if (W(self, 0x75) == 1) {
      ext_634d22((void *)L0c, (void *)ebx, L1c);
      eax = L08;
    } else {
      L04 = 0;
      u32 rr = ext_54e1f0(*(u8 **)(self + 0x29), L0c, L10, &L04, 0);
      u32 ecx = L04;
      ebx = ecx;
      if (L10 != ecx && rr == 2) {
        ext_634d10((void *)(L0c + ecx), 0, L10 - ecx);
        ecx = L04;
      }
      eax = L08;
      if (eax != 0) {
        L04 = 0;
        u32 r2 = ext_54e1f0(*(u8 **)(self + 0x29), L14, L08, &L04, 0);
        ecx = L04;
        eax = L08;
        if (eax != ecx && r2 == 3) {
          ext_634d10((void *)(L14 + ecx), 0, eax - ecx);
          eax = L08;
          ecx = L04;
        }
        ecx += ebx;
        L04 = ecx;
      }
      W(self, 0x1c) += ecx - esi;
    }
    report(self, L0c, L10, L14, eax);
  }
  return 1;
}
PCREG(549840, fn549840);
