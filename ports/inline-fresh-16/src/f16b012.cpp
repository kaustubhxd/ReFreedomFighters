// f16b012.cpp - fresh slice 16, batch 12 (2026-10-12).
// 0x56adc0: factory of the 0x485a40 shape (ctor 0x469870, +4 |= 0x20, +0x44 = 0) with vtable 0x6a7858, then +0x48 = 0 and
//           byte +0x50 = 1. Returns the object. SEH not reproduced.
// 0x455700 ZParticleController::ClassCommand(u16 cmd, data): cmd == u16 +0x821 -> [data] != 0x12345678 calls the handler at
//           0x7003b0 (int3 if null; not run); this slot 0x218([data+4], data+8, &zero[3], [0x70039c]+0x40). Returns 0. Ret 8.
//           Stack cookie not reproduced.
// 0x560280: [0x714198] == 0 -> local {0, 0, 0, byte 1}: 0x59a9b0(&loc; 0x32) (ret 4), this slot 0x1c(&loc), 0x4ff9d0(&loc)
//           (its destructor). SEH not reproduced.
// 0x5761c0 (name): walk list [+0x1c8] from [+0x1c8]+8 (advance with list slot 0x50(&it)); returns the first [it+0x54] whose
//           name ([e+4], or "<NONE>" 0x67c8e8 when null) equals name (strcmp); else 0. Ret 4.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_469870[], ext_59a9b0[], ext_4ff9d0[];

extern "C" void *THISCALL f16_56adc0(void *self) {
  void *a = AT(void *, AT(u8 *, G(u8 *, 0x70039c), 0x9b), 8);
  u8 *o = vcall<u8 *>(a, 0x44, self);
  if (o) {
    ((void(THISCALL *)(void *))(void *)ext_469870)(o);
    AT(u32, o, 4) |= 0x20;
    AT(u32, o, 0x44) = 0;
    AT(u32, o, 0) = 0x6a7858u;
    AT(u32, o, 0x48) = 0;
    AT(u8, o, 0x50) = 1;
  }
  return o;
}

extern "C" u32 THISCALL f16_455700(u8 *self, u32 cmd, u32 *data) {
  u32 z[3] = {0, 0, 0};
  if ((u16)cmd == AT(u16, self, 0x821)) {
    if (data[0] != 0x12345678u) {
      typedef void (*Hfn)();
      Hfn h = G(Hfn, 0x7003b0);
      if (!h) __asm__ volatile("int3");
      h();
    }
    vcall<void>(self, 0x218, data[1], (void *)(data + 2), (void *)z, AT(u32, G(u8 *, 0x70039c), 0x40));
  }
  return 0;
}

struct Loc560 {
  u32 a, b, c;
  u8 flag;
};

extern "C" void THISCALL f16_560280(void *self) {
  if (G(u32, 0x714198) != 0) return;
  volatile Loc560 loc;
  loc.a = 0;
  loc.b = 0;
  loc.c = 0;
  loc.flag = 1;
  ((void(THISCALL *)(volatile void *, u32))(void *)ext_59a9b0)(&loc, 0x32);
  vcall<void>(self, 0x1c, (volatile void *)&loc);
  ((void(THISCALL *)(volatile void *))(void *)ext_4ff9d0)(&loc);
}

extern "C" u8 *THISCALL f16_5761c0(u8 *self, const char *name) {
  u8 *it = AT(u8 *, AT(u8 *, self, 0x1c8), 8);
  while (it) {
    u8 *e = AT(u8 *, it, 0x54);
    const char *s = AT(const char *, e, 4);
    if (!s) s = (const char *)0x67c8e8;
    const char *p = name;
    while (*p == *s && *p) {
      ++p;
      ++s;
    }
    if (*p == *s) return e;
    vcall<void>(AT(void *, self, 0x1c8), 0x50, (void *)&it);
  }
  return 0;
}

PCREG(56adc0, f16_56adc0);
PCREG(455700, f16_455700);
PCREG(560280, f16_560280);
PCREG(5761c0, f16_5761c0);
