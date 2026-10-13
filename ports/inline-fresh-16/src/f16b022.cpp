// f16b022.cpp - fresh slice 16, batch 22 (2026-10-12).
// 0x4c3e80 (thiscall, no args): b+0x49 -> [+0x44] slot 0xbc(1); +0x8a = +0x8e = 0; !b+0x48 -> [+0x44] slot 0x3c(1);
//           b+0x78 -> f+0x92 = (float)(int)([[0x70039c]+0x40] - (int)(f+0x7a * -1024.0f)) * (1/1024.0f) and, if b+0x48,
//           this slot 0x64(0x10); +0x96..+0x9e = 0; [+0x44] slot 0x84(this+0x96).
// 0x4474c0 ctor(a, b, c): ZGEOM::ZGEOM(a, b, c); vtable 0x67dc30; +0x18 = 0; byte [db+0xbad] -> +0x14 |= 1; vtable
//           0x67f0c0; p = new(0x1c): +0x1c = p ? REFTAB::REFTAB(p; 4, 0) : 0. Returns this. SEH not reproduced.
// 0x4d8600 CConsoleCommandList::Add(cmd): t = [+4]; r = t slot 0x84(c_str(cmd slot 4())); found -> tab = [r+4]; else
//           r2 = t slot 0x88(c_str(cmd slot 4())) and [r2] = new(0x1c) ? REFTAB(8, 0) : 0, tab = [r2]. tab slot 4(cmd).
//           SEH not reproduced. A failed new leaves tab 0 and the exe crashes on it; inputs keep new non-null.
// 0x50c540 (thiscall params): e = 0x5003d0([params+4]; 0); o = this slot 0x4c([e]); none -> 0x5002f0(0x5003d0([params+8];
//           0); 0) (shared pushed 0); else r = db slot 0x4c(o slot 0x504()); x = 0x5003d0([params+8]; 0); byte [x+4] <= 1 ->
//           [x] = r, byte [x+4] = 1; else error report (0x69c8e0, 0xc4; 0x69c6b0, 0x69c938) and the assert handler.
#include "ff.h"
#include "f16log.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_45c3a0[], ext_41e290[], ext_4ccbe0[], ext_4cc1d0[], ext_5003d0[], ext_5002f0[];

extern "C" void THISCALL f16_4c3e80(u8 *self) {
  if (AT(u8, self, 0x49)) vcall<void>(AT(void *, self, 0x44), 0xbc, 1u);
  AT(u32, self, 0x8a) = 0;
  AT(u32, self, 0x8e) = 0;
  if (!AT(u8, self, 0x48)) vcall<void>(AT(void *, self, 0x44), 0x3c, 1u);
  if (AT(u8, self, 0x78)) {
    float m = AT(float, self, 0x7a) * -1024.0f;
    int t;
    __asm__("cvttss2si %1, %0" : "=r"(t) : "x"(m));
    int d = (int)(AT(u32, G(u8 *, 0x70039c), 0x40) - (u32)t);
    AT(float, self, 0x92) = (float)d * 0.0009765625f;
    if (AT(u8, self, 0x48)) vcall<void>(self, 0x64, 0x10u);
  }
  AT(u32, self, 0x96) = 0;
  AT(u32, self, 0x9a) = 0;
  AT(u32, self, 0x9e) = 0;
  vcall<void>(AT(void *, self, 0x44), 0x84, self + 0x96);
}

extern "C" void *THISCALL f16_4474c0(u8 *self, u32 a, u32 b, u32 c) {
  ((void(THISCALL *)(void *, u32, u32, u32))(void *)ext_45c3a0)(self, a, b, c);
  AT(u32, self, 0) = 0x67dc30u;
  AT(u32, self, 0x18) = 0;
  if (AT(u8, AT(u8 *, G(u8 *, 0x70039c), 0x9b), 0xbad)) AT(u32, self, 0x14) |= 1;
  AT(u32, self, 0) = 0x67f0c0u;
  void *p = ((void *(*)(u32))(void *)ext_41e290)(0x1c);
  AT(void *, self, 0x1c) = p ? ((void *(THISCALL *)(void *, u32, u32))(void *)ext_4ccbe0)(p, 4, 0) : 0;
  return self;
}

typedef u32(THISCALL *CStr)(void *);

extern "C" void THISCALL f16_4d8600(u8 *self, void *cmd) {
  void **tvt = *(void ***)AT(void *, self, 4);
  u32 n = ((CStr)(void *)ext_4cc1d0)(vcall<void *>(cmd, 4));
  u8 *r = ((u8 * (THISCALL *)(void *, u32)) tvt[0x84 / 4])(AT(void *, self, 4), n);
  if (!r) {
    void **tvt2 = *(void ***)AT(void *, self, 4);
    u32 n2 = ((CStr)(void *)ext_4cc1d0)(vcall<void *>(cmd, 4));
    u8 *r2 = ((u8 * (THISCALL *)(void *, u32)) tvt2[0x88 / 4])(AT(void *, self, 4), n2);
    r = r2 - 4;
    void *p = ((void *(*)(u32))(void *)ext_41e290)(0x1c);
    AT(void *, r, 4) = p ? ((void *(THISCALL *)(void *, u32, u32))(void *)ext_4ccbe0)(p, 8, 0) : 0;
  }
  vcall<void>(AT(void *, r, 4), 4, cmd);
}

typedef u8 *(THISCALL *Get)(void *, u32);
typedef void (*Hfn)();

extern "C" void THISCALL f16_50c540(void *self, u8 *params) {
  u32 *e = (u32 *)((Get)(void *)ext_5003d0)(AT(void *, params, 4), 0);
  void *o = vcall<void *>(self, 0x4c, e[0]);
  if (!o) {
    u8 *x = ((Get)(void *)ext_5003d0)(AT(void *, params, 8), 0);
    ((void(THISCALL *)(void *, u32))(void *)ext_5002f0)(x, 0);
    return;
  }
  void **dvt = *(void ***)AT(void *, G(u8 *, 0x70039c), 0x9b);
  u32 v = vcall<u32>(o, 0x504);
  u32 r = ((u32(THISCALL *)(void *, u32))dvt[0x4c / 4])(AT(void *, G(u8 *, 0x70039c), 0x9b), v);
  u8 *x = ((Get)(void *)ext_5003d0)(AT(void *, params, 8), 0);
  if (AT(u8, x, 4) <= 1) {
    AT(u32, x, 0) = r;
    AT(u8, x, 4) = 1;
    return;
  }
  f16_report2(0x69c8e0u, 0xc4, 0x69c6b0u, 0x69c938u);
  G(Hfn, 0x7003b0)();
}

PCREG(4c3e80, f16_4c3e80);
PCREG(4474c0, f16_4474c0);
PCREG(4d8600, f16_4d8600);
PCREG(50c540, f16_50c540);
