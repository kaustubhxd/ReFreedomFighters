// batch48002.cpp - cascade tier H, batch 48002: 0x4700a0 (spawn a record through the object table and re-time it).
#include "ff.h"

extern "C" u8 *THISCALL ext_43ec00(void *self, void *a, void *b, u32 c, u32 d, u32 e, u32 f);   // thiscall ret 0x18
extern "C" u32 FASTCALL ext_4db3b0(void *ecx);
extern "C" void FASTCALL ext_633654(u32 cookie);   // /GS check

// 0x4700a0, thiscall(a) ret 4, returns a pointer; /GS check. a == 0 -> 0. Otherwise: p = this->slot0x2f4(); b = p ? p->slot0x20() : this; this->slot0x2c8(&v34, &v10); b->slot0x94(&v34, &v10);
// q = mgr->slot0x4c(this->slot0x2f4()) (mgr = [sys+0x9b]); res = ext_43ec00(b, &v34, &v10, a, 0, q, 0); o = mgr->slot0x60(res); when o: n = this->slot0x350()->slot0x33c(), r = engine random slot 0x1c0(0x6887c4, 0xa74)
// t = (int)(float)(r * (float)(2n) - (float)n) (x87); [o+0x60] = t - [o+0x64]; [o+0x64] = t; then k = mgr->slot0x58([o+0x3c]); when k and (c = ext_4db3b0([k+8])) != 0 and c == [mgr+0xadc]: [o+0x40] &= ~4.
static u8 *THISCALL fn4700a0(u8 *self, u32 a) {
  u8 *res = 0;
  if (a) {
    float v34[9], v10[3];
    u8 *sys = G(u8 *, 0x70039c);
    u8 *b = self;
    if (vcall<u8 *>(self, 0x2f4)) b = vcall<u8 *>(vcall<u8 *>(self, 0x2f4), 0x20);
    vcall<void>(self, 0x2c8, (u32)v34, (u32)v10);
    vcall<void>(b, 0x94, (u32)v34, (u32)v10);
    u8 *mgr = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u32 q = vcall<u32>(mgr, 0x4c, vcall<u32>(self, 0x2f4));
    res = ext_43ec00(b, v34, v10, a, 0u, q, 0u);
    u8 *o = vcall<u8 *>(*(u8 **)(G(u8 *, 0x70039c) + 0x9b), 0x60, (u32)res);
    if (o) {
      s32 n = vcall<s32>(vcall<u8 *>(self, 0x350), 0x33c);
      float r = vcall<float>(G(u8 *, 0x70039c), 0x1c0, 0x6887c4u, 0xa74u);
      float f1 = _mm_cvtss_f32(_mm_cvtepi32_ps(_mm_cvtsi32_si128(n * 2)));
      float f2 = _mm_cvtss_f32(_mm_cvtepi32_ps(_mm_cvtsi32_si128(n)));
      float tf = (float)((long double)r * (long double)f1 - (long double)f2);
      s32 t = _mm_cvttss_si32(_mm_set_ss(tf));
      u32 key = *(u32 *)(o + 0x3c);
      *(s32 *)(o + 0x60) = t - *(s32 *)(o + 0x64);
      *(s32 *)(o + 0x64) = t;
      u8 *k = vcall<u8 *>(*(u8 **)(G(u8 *, 0x70039c) + 0x9b), 0x58, key);
      if (k) {
        u32 c = ext_4db3b0(*(u8 **)(k + 8));
        if (c) {
          if (c == *(u32 *)(*(u8 **)(G(u8 *, 0x70039c) + 0x9b) + 0xadc)) *(u32 *)(o + 0x40) &= 0xfffffffb;
        }
      }
    }
    (void)sys;
  }
  ext_633654(0);
  return res;
}
PCREG(4700a0, fn4700a0);
