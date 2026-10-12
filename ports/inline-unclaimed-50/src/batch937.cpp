// batch937.cpp - 0x477740 ZActor::ActivateBaseMove(unsigned int, bool) [thiscall (ECX = this), two stack args (a, flag byte), ret 8, returns al = 1].
// Body read in full (2026-10-12). If this+0x650 == a and flag == 0: return 1. Otherwise this+0x654 = old this+0x650; this+0x650 = a; r = this
// slot +0x5a8 (a) (stood in); if r == 0: this+0x658 = a, return 0. Else ecx = [r], edx = [r+4]; edi = (mgr+0x44) + ecx when ecx != 0 (mgr = g+0x9b),
// else 0. this+0x759 = ((float)[edi+0x64] + 1.0f - (float)[edi+0x60]) / (float)[edi+0x6c]; this+0x769 = (float)[edi+0x5c] / (float)[edi+0x6c].
// If bit 3 of edx is set: this+0x755 = fmod(the double of this+0x755, 1.0) (the exe's _CIfmod import, computed here as x - trunc(x)); else 0.
// Then this slot +0x268 (edi, [edi+0x7c]) (stood in). Returns 1. The exe reads [edi] unchecked: r's first word must be nonzero (the spec draws it so).
#include "ff.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define F32(p, o) (*(float *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

// 0x477740 (name in the map: ZActor::ActivateBaseMove(unsigned int, bool)).
static u8 THISCALL ActivateBaseMove477740(u8 *self, u32 a, u8 flag) {
  if (U32(self, 0x650) == a && flag == 0) return 1;
  U32(self, 0x654) = U32(self, 0x650);
  U32(self, 0x650) = a;
  u32 r = vcall<u32>(self, 0x5a8, a);
  if (r == 0) {
    U32(self, 0x658) = a;
    return 0;
  }
  u32 ecx = U32((u8 *)r, 0);
  u32 edx = U32((u8 *)r, 4);
  u8 *edi = 0;
  if (ecx != 0) {
    u8 *mgr = (u8 *)FP(G(u8 *, 0x70039c), 0x9b);
    edi = (u8 *)(U32(mgr, 0x44) + ecx);
  }
  float x1 = ((float)(s32)U32(edi, 0x64) + 1.0f - (float)(s32)U32(edi, 0x60)) / (float)(s32)U32(edi, 0x6c);
  F32(self, 0x759) = x1;
  float x2 = (float)(s32)U32(edi, 0x5c) / (float)(s32)U32(edi, 0x6c);
  F32(self, 0x769) = x2;
  if (edx & 8u) {
    double v = (double)F32(self, 0x755);
    double f = v - (double)(long long)v;     // fmod(v, 1.0): v minus its truncation (exact for |v| < 2^53)
    F32(self, 0x755) = (float)f;
  } else {
    F32(self, 0x755) = 0.0f;
  }
  vcall<void>(self, 0x268, (void *)edi, U32(edi, 0x7c));
  return 1;
}
PCREG(477740, ActivateBaseMove477740);
