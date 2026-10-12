#include "ff.h"
// batch7909.cpp - unclaimed-79 batch 9 (docs/20-unclaimed-79.md). Name from the GC name map (naming only).
// Orchestration verified, helpers stubbed: the callees below run as original code, the harness stubs them with call recorders.

extern "C" void THISCALL ext_644660(u8 *self);
extern "C" void THISCALL ext_641340(u8 *self);
extern "C" void THISCALL ext_544e10(u8 *self);
extern "C" void THISCALL ext_545950(u8 *self);
extern "C" void THISCALL ext_641e20(u8 *self, u8 *a, u8 *b);
extern "C" void ext_634d22(u8 *dst, u8 *src, u32 n);
extern "C" void FASTCALL ext_547a70(u8 *ecx, u32 edx);
extern "C" void FASTCALL ext_4de480(u8 *ecx, u8 *edx);
extern "C" void FASTCALL ext_4419f0(u8 *ecx, u8 *edx);
extern "C" void FASTCALL ext_441940(u8 *ecx, u8 *edx);

// 0x6411b0, CRagdoll2::ComputeParticlePositions() (high). Thiscall, plain ret.
static void THISCALL ragdoll2ComputeParticlePositions(u8 *self) {
  u8 buf[0x1210];
  u32 cookie = 0;
  u32 a = vcall<u32, u32>(*(u8 **)(self + 0x36), 0x2b4, 0x15u);
  if (*(u32 *)(self + 0x1b3) != a || *(u32 *)(self + 0x1bf) != vcall<u32, u32>(*(u8 **)(self + 0x36), 0x2b4, 5u))
    ext_644660(self);
  u32 cnt = *(u32 *)(self + 0x26);
  u8 *edi = *(u8 **)(self + 0x2e);
  u32 n = (cnt * 3) << 4;
  ext_634d22(buf, edi, n);
  ext_634d22(edi, *(u8 **)(self + 0x32), n);
  u8 *z = *(u8 **)(*(u8 **)(self + 0x36) + 8);
  u32 edx = *(u32 *)(z + 0x6c);
  u8 *x = *(u8 **)(G(u8 *, 0x70039c) + 0x1aa3);
  u8 *y = *(u8 **)(x + 0x18);
  u32 r4 = vcall<u32, u32>(y, 0xc4, edx);
  u32 i = 1;
  u8 *ecxv = *(u8 **)(self + 0x2e);
  if (cnt != 1) {
    u8 *ebxp = ecxv + 0x24;
    u8 *eaxp = (u8 *)(unsigned long)r4 + 0xc;
    do {
      eaxp += 0x30;
      ecxv += 0x30;
      ebxp += 0x30;
      u32 idx = *(u32 *)eaxp;
      u8 *edip = *(u8 **)(self + 0x2e) + idx * 48;
      ext_4de480(ecxv, edip);
      ext_4419f0(ebxp, edip);
      ext_441940(ebxp, edip + 0x24);
      i++;
    } while (i != *(u32 *)(self + 0x26));
  }
  ext_641340(self);
  ext_544e10(*(u8 **)(self + 0x17f));
  n = *(u32 *)(self + 0x26) * 3 << 4;
  ext_634d22(*(u8 **)(self + 0x2e), buf, n);
  ext_641340(self);
  vcall<void>(*(u8 **)(self + 0x17f), 8);
  ext_545950(*(u8 **)(self + 0x17f));
  ext_547a70(*(u8 **)(self + 0x17f), 0xau);
  ext_641e20(self, (u8 *)&cookie, self + 8);
}
PCREG(6411b0, ragdoll2ComputeParticlePositions);
