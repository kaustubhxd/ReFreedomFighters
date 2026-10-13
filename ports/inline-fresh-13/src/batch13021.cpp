// batch13021.cpp - fresh slice 13, batch 21 (docs/20-fresh-13.md), 2026-10-12.
// 0x44b310 ZSNDOBJ::ZSNDOBJ(ZGEOMCLASSINFO*, const char*, ZBaseGeom*) (name map medium): thiscall, ret 0xc, returns this.
//  - Base ctor 0x43de40 (3 args), vtable 0x67fc30, SetControl 0x4dc630(+8 geom; 0, 0x38003).
//  - RegisterZMsg (db slot 0x114) "DeleteSound" / "ActivateSound" / "DeactivateSound" (zsndobj.cpp lines 0x98..0x9a)
//    into the u16 globals 0x6ff96c / 0x6ff970 / 0x6ff974.
//  - +0x20 = 0, +0x1c = 0. Without a sound system (sys+0x1a9f) or when db[+0x2c]() is true: +0x18 = 0.
//  - Otherwise +0x18 = sound->vtbl[+0x44]() (a new sound record) and the record is initialised: owner id db[+0x4c](this),
//    flags, volume / pitch 1.0f, angles 360.0f, range: +0x88 == 0 ? (1.0f, 2.0f) : (10000.0f, +0x88 / 0.78125f *
//    10000.0f), and so on (see the body; every store is re-addressed through +0x18 as in the exe).
//  The exe's `+0x6c != &stack local` test before clearing +0x6c is always true and is kept as an unconditional store.
//  The SEH frame and /GS cookie are not reproduced.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))
#define VT(o, off) (*(u32 *)(*(u32 *)(o) + (off)))

extern "C" char ext_43de40[], ext_4dc630[];
typedef void(THISCALL *Base)(void *self, u32 a, u32 b, u32 c);
typedef void(THISCALL *P2)(void *self, u32 a, u32 b);
typedef u32(THISCALL *R0)(void *self);
typedef u32(THISCALL *R1)(void *self, u32 a);
typedef u16(THISCALL *Reg)(void *self, u32 name, u32 z, u32 file, u32 line);

static inline u8 *db() { return AT(u8 *, G(u8 *, 0x70039c), 0x9b); }
#define D AT(u8 *, self, 0x18)

static u8 *THISCALL fn44b310(u8 *self, u32 info, u32 name, u32 geom) {
  ((Base)(void *)ext_43de40)(self, info, name, geom);
  AT(u32, self, 0) = 0x67fc30;
  ((P2)(void *)ext_4dc630)(AT(u8 *, self, 8), 0, 0x38003);
  G(u16, 0x6ff96c) = ((Reg)VT(db(), 0x114))(db(), 0x67fe84, 0, 0x67fe5c, 0x98);
  G(u16, 0x6ff970) = ((Reg)VT(db(), 0x114))(db(), 0x67fe90, 0, 0x67fe5c, 0x99);
  G(u16, 0x6ff974) = ((Reg)VT(db(), 0x114))(db(), 0x67fea0, 0, 0x67fe5c, 0x9a);
  AT(u8, self, 0x20) = 0;
  AT(u32, self, 0x1c) = 0;
  u8 *snd = AT(u8 *, G(u8 *, 0x70039c), 0x1a9f);
  if (!snd || (u8)((R0)VT(db(), 0x2c))(db())) {
    AT(u32, self, 0x18) = 0;
    return self;
  }
  snd = AT(u8 *, G(u8 *, 0x70039c), 0x1a9f);
  AT(u32, self, 0x18) = ((R0)VT(snd, 0x44))(snd);
  u32 id = ((R1)VT(db(), 0x4c))(db(), (u32)self);
  AT(u32, D, 0) = id;
  AT(u32, D, 0x3c) = 0;
  AT(u32, D, 0x40) = 0;
  AT(u32, D, 0x40) &= ~8u;
  AT(u32, D, 0x6c) = 0;
  AT(u32, D, 0x70) = 0;
  AT(u32, D, 0x74) = 0;
  AT(u32, D, 8) = 1;
  AT(u32, D, 0xc) = 2;
  AT(u32, D, 0x68) = 0;
  AT(u32, D, 0x84) = 0x3f800000;
  AT(u32, D, 0x88) = 0x3f800000;
  u8 *d = D;
  AT(u32, d, 0x44) = 0x43b40000;
  AT(u32, d, 0x48) = 0x43b40000;
  AT(u32, D, 0x4c) = 0;
  AT(u32, D, 0x50) = 0;
  d = D;
  float r = AT(float, d, 0x88);
  if (r == 0.0f) {
    AT(u32, d, 0x54) = 0x3f800000;
    AT(u32, d, 0x5c) = 0x40000000;
  } else {
    AT(u32, d, 0x54) = 0x461c4000;
    AT(float, d, 0x5c) = r / G(float, 0x67cd3c) * G(float, 0x67ff1c);
  }
  d = D;
  AT(u32, d, 0x40) |= 0x80;
  AT(u32, d, 0x2c) = 0;
  AT(u32, D, 0x78) = 0;
  AT(u32, D, 0x8c) = 0;
  d = D;
  u32 t = AT(u32, d, 0x64);
  AT(u32, d, 0x64) = 0;
  AT(u32, d, 0x60) = 0u - t;
  AT(u32, D, 0x60) = 0;
  AT(u32, D, 0x40) |= 2;
  AT(u32, D, 0x40) |= 4;
  AT(u32, D, 0x40) &= ~0x20u;
  AT(u32, D, 4) = 3;
  AT(u32, D, 0x80) = 0;
  return self;
}
PCREG(44b310, fn44b310);
