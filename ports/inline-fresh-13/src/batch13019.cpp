// batch13019.cpp - fresh slice 13, batch 19 (docs/20-fresh-13.md), 2026-10-12.
// 0x448c50 ZUSERLIGHT::CopyDataBlock(DBLK*) (name map high): thiscall, ret 4.
//  - ZLIGHT::CopyDataBlock 0x448a30, then DBLK::Get(u32*, 1) 0x4e12e0 for +0x1c (type), +0x20, +0x24 and
//    DBLK::Get(float*, 1) 0x4e12f0 for +0x28 .. +0x3c, then DBLK::NextBlock 0x4e1b30.
//  - By type: 0 / 1 / 2 set the geom prim (ZBaseGeom::SetPrim 0x4dcdf0 on +8 with the light manager's
//    (sys+0x1aa3)->+0x18 vtbl[+0x7c](1) id) and pass a light record to the manager's slot 0x98 / 0xa0 / 0xa8 with the
//    geom's +0x6c handle. Record fields (others are left as stack garbage, as in the exe): +0x10 = +0x20 (colour),
//    +0x14..+0x1c = +0x28..+0x30; types 1 / 2 add +0x24 = +0x38 * deg2rad, +0x28 = +0x34 * deg2rad (0.0174533f at
//    0x67da04); type 2 adds +0x38 = +0x3c. Type 3 calls the assert hook 0x7003b0 (int3 when unset); others do nothing.
//  - When the engine db (sys+0x9b) has +0x5d35 set: this->vtbl[0]() and +0x18 |= 8.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))
#define VT(o, off) (*(u32 *)(*(u32 *)(o) + (off)))

extern "C" char ext_448a30[], ext_4e12e0[], ext_4e12f0[], ext_4e1b30[], ext_4dcdf0[];
typedef void(THISCALL *P0)(void *self);
typedef void(THISCALL *P1)(void *self, u32 a);
typedef u32(THISCALL *R1)(void *self, u32 a);
typedef void(THISCALL *Get)(void *blk, void *p, u32 n);
typedef void(THISCALL *Rec)(void *self, u32 h, u32 *rec);
typedef void (*Hook)();

static void THISCALL fn448c50(u8 *self, u8 *blk) {
  ((P1)(void *)ext_448a30)(self, (u32)blk);
  ((Get)(void *)ext_4e12e0)(blk, self + 0x1c, 1);
  ((Get)(void *)ext_4e12e0)(blk, self + 0x20, 1);
  ((Get)(void *)ext_4e12e0)(blk, self + 0x24, 1);
  for (u32 off = 0x28; off <= 0x3c; off += 4)
    ((Get)(void *)ext_4e12f0)(blk, self + off, 1);
  ((P0)(void *)ext_4e1b30)(blk);
  u32 type = AT(u32, self, 0x1c);
  if (type <= 2) {
    u8 *mgr = AT(u8 *, AT(u8 *, G(u8 *, 0x70039c), 0x1aa3), 0x18);
    u32 prim = ((R1)VT(mgr, 0x7c))(mgr, 1);
    ((P1)(void *)ext_4dcdf0)(AT(u8 *, self, 8), prim);
    u32 rec[16];
    rec[4] = AT(u32, self, 0x20);
    rec[5] = AT(u32, self, 0x28);
    rec[6] = AT(u32, self, 0x2c);
    rec[7] = AT(u32, self, 0x30);
    if (type >= 1) {
      AT(float, rec, 0x28) = AT(float, self, 0x34) * G(float, 0x67da04);
      AT(float, rec, 0x24) = AT(float, self, 0x38) * G(float, 0x67da04);
    }
    if (type == 2)
      rec[14] = AT(u32, self, 0x3c);
    mgr = AT(u8 *, AT(u8 *, G(u8 *, 0x70039c), 0x1aa3), 0x18);
    u32 slot = type == 0 ? 0x98 : type == 1 ? 0xa0 : 0xa8;
    ((Rec)VT(mgr, slot))(mgr, AT(u32, AT(u8 *, self, 8), 0x6c), rec);
  } else if (type == 3) {
    Hook f = G(Hook, 0x7003b0);
    if (!f)
      __builtin_debugtrap();
    else
      f();
  }
  if (AT(u32, AT(u8 *, G(u8 *, 0x70039c), 0x9b), 0x5d35)) {
    ((P0)VT(self, 0))(self);
    AT(u32, self, 0x18) |= 8;
  }
}
PCREG(448c50, fn448c50);
