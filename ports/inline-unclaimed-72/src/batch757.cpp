// batch757.cpp - area 72, gap rows, vtable calls (2026-10-12). See docs/20-unclaimed-72.md.
#include "ff.h"

static void THISCALL f_4bbc20(u8 *self) {
  u8 *o = *(u8 **)(self + 0x44);
  if (o) vcall<void>(o, 0x210, 1u);
}
PCREG(4bbc20, f_4bbc20);

static void THISCALL f_4aff30(u8 *self, u32 a, u32 b) { (void)a; vcall<void>(self, 0x84, b); }
PCREG(4aff30, f_4aff30);

static void THISCALL f_551080(u8 *self, u32 a, u32 b, u32 c) { (void)self; vcall<void>((void *)a, 0x18, b); (void)c; }
PCREG(551080, f_551080);

static void THISCALL f_4dc420(u8 *self, u32 a) {
  u8 *o = *(u8 **)(self + 0x54);
  if (o) vcall<void>(o, 0xc, a);
}
PCREG(4dc420, f_4dc420);

static void THISCALL f_54c300(u8 *self, u32 a) {
  u8 *o = *(u8 **)(self + 0x50);
  if (o) vcall<void>(o, 0x18, a);
}
PCREG(54c300, f_54c300);

static double THISCALL f_4d1db0(u8 *self, u32 a) {
  u8 *p = (u8 *)vcall<u32>(self, 0x3c, a);
  return *(double *)p;
}
PCREG(4d1db0, f_4d1db0);

static u32 THISCALL f_4d1e10(u8 *self, u32 a) {
  u8 *p = (u8 *)vcall<u32>(self, 0x3c, a);
  return *(u32 *)p;
}
PCREG(4d1e10, f_4d1e10);
