// batch32105.cpp - cascade h2 (Sonnet): three tier H (float / SSE) functions.
#include "ff.h"

extern "C" void THISCALL ext_4dd060(u8 *self, float *p);     // thiscall ret 4
extern "C" void THISCALL ext_4dce50(u8 *self, float a);      // thiscall ret 4
extern "C" void THISCALL ext_4dc600(u8 *self, u32 *p);       // thiscall ret 4
extern "C" void FASTCALL ext_633654(u32 cookie);             // /GS check

// 0x449ae0, thiscall(float a) ret 4: slot 0x238 of this; t = [[[0x70039c]+0x1aa3]+0x18]; id = [[this+8]+0x6c]; buf[9] filled by slot 0x80 of t with (id, buf); buf[5] = a; slot 0x98 of t with (id, buf);
// returns slot 0x220 of this with 1.
static u32 THISCALL fn449ae0(u8 *self, float a) {
  vcall<void>(self, 0x238);
  u8 *t = *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x1aa3) + 0x18);
  u32 id = *(u32 *)(*(u8 **)(self + 8) + 0x6c);
  u32 buf[9];
  vcall<void>(t, 0x80, id, (u32)buf);
  *(float *)&buf[5] = a;
  t = *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x1aa3) + 0x18);
  vcall<void>(t, 0x98, id, (u32)buf);
  return vcall<u32>(self, 0x220, 1u);
}
PCREG(449ae0, fn449ae0);

// 0x464400, thiscall(p, float b, float c, byte flag, e) ret 0x14, returns the last slot's eax (p != 0 only): x = flag ? b : (float)(int)([p+0x64] - [p+0x60]) * b;
// r = slot 0x288 of this with (p, p, x, c, e); m = [this+0x6c]; returns slot 0x18 of m (vtable read before the first call) with r.
static u32 THISCALL fn464400(u8 *self, u8 *p, float b, float c, u32 flag, u32 e) {
  if (!p) return 0;
  float x = ((u8)flag) ? b : (float)(s32)(*(u32 *)(p + 0x64) - *(u32 *)(p + 0x60)) * b;
  void *m = *(void **)(self + 0x6c);
  u32 slot18 = *(u32 *)(*(u8 **)m + 0x18);
  u32 r = vcall<u32>(self, 0x288, (u32)p, (u32)p, x, c, e);
  m = *(void **)(self + 0x6c);
  typedef u32 (THISCALL *fn_t)(void *, u32);
  return ((fn_t)slot18)(m, r);
}
PCREG(464400, fn464400);

// 0x47fea0, thiscall no args (/GS frame): f = [this+0x1c]; o = [this+8]; 0x4dd060(o, &{f, f, f}); 0x4dce50(o, f); 0x4dc600(o, &{0, 0, 0}); /GS check.
static void THISCALL fn47fea0(u8 *self) {
  u32 zero[3] = {0, 0, 0};
  float fv[3];
  float f = *(float *)(self + 0x1c);
  fv[0] = f; fv[1] = f; fv[2] = f;
  ext_4dd060(*(u8 **)(self + 8), fv);
  ext_4dce50(*(u8 **)(self + 8), *(float *)(self + 0x1c));
  ext_4dc600(*(u8 **)(self + 8), zero);
  ext_633654(0);
}
PCREG(47fea0, fn47fea0);
