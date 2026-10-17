// batch754.cpp - area 72, gap rows round 4 (2026-10-12): simple stores, getters and vtable calls (docs/20-unclaimed-72.md).
#include "ff.h"

static void THISCALL f_4cbdc0(u8 *self) { vcall<void>(*(void **)(self + 0x44), 0x3c, 1u); }
PCREG(4cbdc0, f_4cbdc0);

static void THISCALL f_566e30(u8 *self) { vcall<void>(self, 0xd0, 0u); }
PCREG(566e30, f_566e30);

static u32 THISCALL f_4d4a30(u8 *self, u32 a) { (void)self; return *(u32 *)a; }
PCREG(4d4a30, f_4d4a30);

static void THISCALL f_4b00d0(u8 *self, u32 a) { *(u32 *)(self + 0x48) = a; }
PCREG(4b00d0, f_4b00d0);

static void THISCALL f_4bb2c0(u8 *self) {
  u8 *inner = *(u8 **)(self + 0x44);
  u8 *x = *(u8 **)(inner + 0x18);
  *(u32 *)(self + 0x4e) = *(u32 *)(x + 0x70);
}
PCREG(4bb2c0, f_4bb2c0);

static void THISCALL f_4d7530(u8 *self, u32 a) { *(u32 *)(self + 0xd) = a; }
PCREG(4d7530, f_4d7530);

static void THISCALL f_4be6d0(u8 *self, u32 a) { *(u8 *)(self + 0xd1) = (u8)a; }
PCREG(4be6d0, f_4be6d0);

static void THISCALL f_563500(u8 *self) {
  (void)self;
  u8 *g = *(u8 **)0x7003a0;
  *(u32 *)(g + 0x70) = *(u32 *)(g + 0x6c);
}
PCREG(563500, f_563500);

static bool THISCALL f_4c8340(u8 *self, u32 a) {
  (void)a;
  *(u32 *)(self + 4) &= 0xffffffbfu;
  vcall<void>(self, 0x8);
  return true;
}
PCREG(4c8340, f_4c8340);

static void THISCALL f_4afec0(u8 *self, u32 a, u32 b) { (void)a; (void)b; vcall<void>(self, 0x84); }
PCREG(4afec0, f_4afec0);
