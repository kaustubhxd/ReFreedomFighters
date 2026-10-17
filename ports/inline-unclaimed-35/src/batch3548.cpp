#include "ff.h"
// batch3548.cpp - slice 14, batch 48: 0x656160, 0x616a60, 0x6364a0 (GUESS names).
// Stubbed in the harness: 0x634273 (cdecl, two args, logged), 0x6363a0 (thiscall, no args, logged);
// mgr at 0x70039c; this vtable slots +0xc (no args) and +0x6c (two args, logged).

extern "C" void ext_634273(u32 a0, u32 a1);
extern "C" void THISCALL ext_6363a0(u8 *self);

struct Obj {
  u32 vt;
};

u32 THISCALL gap656160(u8 *self, u32 a0) {
  Obj *mgr = *(Obj **)0x70039c;
  u32 *r0 = (u32 *)*(u32 *)((u8 *)mgr + 0x1aa3);
  u32 *r1 = (u32 *)*(u32 *)((u8 *)r0 + 0x20);
  Obj *obj = (Obj *)self;
  typedef void (*fn_vc_t)(Obj *);
  ((fn_vc_t)(*(u32 *)obj + 0xc))(obj);
  typedef void (*fn_v2_t)(Obj *, u32, u32);
  ((fn_v2_t)(*(u32 *)obj + 0x6c))(obj, 0, r1[a0]);
  return 0;
}
PCREG(656160, gap656160);

u8 *THISCALL gap616a60(u8 *self, u32 a0) {
  *(u32 *)self = 0x6bdd68;
  if (*(u32 *)(self + 0xc) != 0)
    ext_634273(0x40, *(u32 *)(self + 0xc));
  *(u32 *)self = 0x6bdc40;
  if ((a0 & 1) != 0)
    ext_634273(0x10, (u32)self);
  return self;
}
PCREG(616a60, gap616a60);

u8 *THISCALL gap6364a0(u8 *self, u32 a0) {
  *(u32 *)self = 0x6c1fec;
  if (*(u8 *)(self + 0x31) != 0)
    ext_634273(4, *(u32 *)(self + 0x2d));
  ext_6363a0(self);
  if ((a0 & 1) != 0)
    ext_634273(0x36, (u32)self);
  return self;
}
PCREG(6364a0, gap6364a0);
