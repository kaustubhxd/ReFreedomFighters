#include "ff.h"
// batch8029.cpp - unclaimed medium core row (docs/20-unclaimed-79.md). Name GUESS (no GC name). Callees and helpers stubbed.

extern "C" void FASTCALL ext_4de420(u8 *c, u8 *d);            // stubbed in spec
extern "C" void THISCALL ext_484b10(u8 *self, u32 a, u32 b, u32 c, u32 d, u32 e);   // five stack arguments, stubbed in spec
extern "C" void THISCALL ext_4ea300(u8 *self, u32 a);         // stubbed in spec

// 0x4840e0 (GUESS): thiscall (ret 8), arguments a (the edx value) and p (pointer to three floats).
static void THISCALL f_4840e0(u8 *self, u32 a, u32 p) {
  u8 L[0x10060];
  u8 *E = L + 0x10058;
  float *pf = (float *)(unsigned long)p;
  *(float *)(E - 0x10010) = pf[0];
  *(float *)(E - 0x1000c) = pf[1];
  *(float *)(E - 0x10008) = pf[2];
  ext_4de420(E - 0x10058, (u8 *)(unsigned long)a);
  u8 al = (u8)vcall<u32>(self, 0x2fc);
  if (al == 0) {
    u8 *S = G(u8 *, 0x70039c);
    u8 *T = *(u8 **)(S + 0x1aa3);
    u8 *U = *(u8 **)(T + 0x1c);
    u32 bv = vcall<u32, u32, u32>(U, 0x48, (u32)(unsigned long)(E - 0x10004), 0x10000u);
    u8 *esi = (u8 *)(unsigned long)vcall<u32, u32>(self, 0x640, 2u);
    *(u32 *)(esi + 0x8) = bv;
    float x = *(float *)(E - 0x1000c);
    float g1 = G(float, 0x680a84);
    float g2 = G(float, 0x680a70);
    *(float *)(E - 0x10028) = *(float *)(E - 0x10010);
    *(float *)(E - 0x1001c) = *(float *)(E - 0x10010);
    *(float *)(E - 0x10020) = *(float *)(E - 0x10008);
    *(float *)(E - 0x10014) = *(float *)(E - 0x10008);
    *(float *)(E - 0x10024) = x + g1;
    *(float *)(E - 0x10018) = x - g2;
    ext_484b10(self, bv, 0u, (u32)(unsigned long)(E - 0x10028), (u32)(unsigned long)(E - 0x1001c), 0u);
    ext_4ea300((u8 *)(unsigned long)bv, 0x20u);
    *(u32 *)(E - 0x10034) = 0;
    *(u32 *)(E - 0x10030) = 0;
    *(u32 *)(E - 0x1002c) = 0;
    vcall<void, u32>(self, 0x424, 0u);
    u8 r = (u8)vcall<u32, u32, u32, u32, u32, u32, u32>(esi, 0x4c, (u32)(unsigned long)(self + 0x41b), (u32)(unsigned long)(E - 0x10058), (u32)(unsigned long)(E - 0x10028), (u32)(unsigned long)(E - 0x10058), (u32)(unsigned long)(E - 0x1001c), (u32)(unsigned long)(E - 0x10034));
    if (r != 0) {
      u64 q = *(u64 *)(E - 0x1001c);
      u32 t = *(u32 *)(E - 0x10014);
      *(u64 *)(E - 0x10010) = q;
      *(u32 *)(E - 0x10008) = t;
      vcall<void, u32>(self, 0x5a8, 1u);
    } else {
      vcall<void, u32>(self, 0x5a8, 0u);
    }
    *(u32 *)(self + 0x445) = 0;
    *(u32 *)(self + 0x449) = 0;
    *(u32 *)(self + 0x44d) = 0;
    vcall<u32, u32>(U, 0x4c, bv);
  }
  vcall<void, u32, u32, u32, u32>(self, 0x600, (u32)(unsigned long)(E - 0x10058), (u32)(unsigned long)(E - 0x10010), (u32)(unsigned long)(E - 0x10058), (u32)(unsigned long)(E - 0x10010));
  vcall<void, u32, u32>(self, 0x5f0, (u32)(unsigned long)(E - 0x10058), (u32)(unsigned long)(E - 0x10010));
  vcall<void>(self, 0x410);
}
PCREG(4840e0, f_4840e0);
