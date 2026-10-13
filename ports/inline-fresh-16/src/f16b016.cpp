// f16b016.cpp - fresh slice 16, batch 16 (2026-10-12).
// 0x5045c0: p = __builtin_new(0x14); p -> {vtable 0x69c9c0, 1, 0, this, 0} and, when [0x700e70] == 0, 0x5044c0(p). Returns p.
//           SEH not reproduced.
// 0x552400 CFFTools_if::DrawSpline(params) (stdcall): e = 0x5003d0([params+4]; 0); o = db slot 0x58([e]); none -> return;
//           !o slot 0x1e0(0x4000022) -> error report (0x6a57fc, 0x3b4; 0x6a5b9c); else [0x70039c] slot 0x1c0(0x6a57fc, 0x3b8)
//           (float result dropped) and 0x51ad70(o; 0.001f bits 0x3a83126f, 0) (ret 8; the GameCube name CBaseEvent::Init does
//           not fit these arguments, so the name is a GUESS). Ret 4.
// 0x442240 (fastcall a, b; c, d): d -> 0x441ad0(fastcall d, c; a, b) (ret 8); else p = 0x45c4b0(0x83), p -> 0x441b90(p; c, a, b)
//           (ret 0xc); else 0. Ret 8. SEH not reproduced.
// 0x4f2000 ZWINDOWS::ClassInit: LoadInit 0x4f2610; ZWINGROUP::ClassInit 0x4ef0e0; ZGEOM::EnableClassCall slot 0x110(0x110, 0);
//           g = +0x6f: g slot 0x27c(db slot 0x4c(this)); g+0x48 |= 0x210000; +0x30 |= 0x400; in = [0x70039c] slot 0xbc();
//           SetMouseSpeed slot 0x314(in slot 0xa8() (float)); SetShowMouse slot 0x30c(in slot 0xb0() (bool)).
#include "ff.h"
#include "f16log.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_41e290[], ext_5044c0[], ext_5003d0[], ext_51ad70[], ext_441ad0[], ext_45c4b0[], ext_441b90[], ext_4f2610[],
    ext_4ef0e0[];

extern "C" u32 *THISCALL f16_5045c0(void *self) {
  u32 *p = ((u32 * (*)(u32))(void *)ext_41e290)(0x14);
  if (!p) return 0;
  p[1] = 1;
  p[2] = 0;
  p[0] = 0x69c9c0u;
  p[3] = (u32)self;
  p[4] = 0;
  if (G(u32, 0x700e70) == 0) ((void(THISCALL *)(void *))(void *)ext_5044c0)(p);
  return p;
}

extern "C" void STDCALL f16_552400(u8 *params) {
  u32 *e = ((u32 * (THISCALL *)(void *, u32))(void *)ext_5003d0)(AT(void *, params, 4), 0);
  void *o = vcall<void *>(AT(void *, G(u8 *, 0x70039c), 0x9b), 0x58, e[0]);
  if (!o) return;
  if (!vcall<bool>(o, 0x1e0, 0x4000022u)) {
    f16_report(0x6a57fcu, 0x3b4, 0x6a5b9cu);
    return;
  }
  (void)vcall<float>(G(void *, 0x70039c), 0x1c0, 0x6a57fcu, 0x3b8u);
  ((void(THISCALL *)(void *, u32, u32))(void *)ext_51ad70)(o, 0x3a83126fu, 0u);
}

extern "C" u32 FASTCALL f16_442240(u32 a, u32 b, u32 c, u32 d) {
  if (d) return ((u32(FASTCALL *)(u32, u32, u32, u32))(void *)ext_441ad0)(d, c, a, b);
  void *p = ((void *(*)(u32))(void *)ext_45c4b0)(0x83);
  if (!p) return 0;
  return ((u32(THISCALL *)(void *, u32, u32, u32))(void *)ext_441b90)(p, c, a, b);
}

extern "C" void THISCALL f16_4f2000(u8 *self) {
  ((void(THISCALL *)(void *))(void *)ext_4f2610)(self);
  ((void(THISCALL *)(void *))(void *)ext_4ef0e0)(self);
  vcall<void>(self, 0x110, 0x110u, 0u);
  void *g = AT(void *, self, 0x6f);
  void **gvt = *(void ***)g;
  u32 ref = vcall<u32>(AT(void *, G(u8 *, 0x70039c), 0x9b), 0x4c, (void *)self);
  ((void(THISCALL *)(void *, u32))gvt[0x27c / 4])(AT(void *, self, 0x6f), ref);
  AT(u32, AT(u8 *, self, 0x6f), 0x48) |= 0x210000u;
  AT(u32, self, 0x30) |= 0x400u;
  void *in = vcall<void *>(G(void *, 0x70039c), 0xbc);
  float sp = vcall<float>(in, 0xa8);
  vcall<void>(self, 0x314, sp);
  bool sh = vcall<bool>(in, 0xb0);
  vcall<void>(self, 0x30c, (u32)sh);
}

PCREG(5045c0, f16_5045c0);
PCREG(552400, f16_552400);
PCREG(442240, f16_442240);
PCREG(4f2000, f16_4f2000);
