// batch210003.cpp - Sonnet-w3a: small BLOCKED rows (engine-table slot calls, ctor-style init, flag getters)
#include "ff.h"

extern "C" u32 ext_5d7b10();
extern "C" u32 FASTCALL ext_498700(u8 *self, u32 edx);
extern "C" u32 ext_634273(u32 p, u32 flags);
extern "C" u32 THISCALL ext_562260(u8 *self);
extern "C" u32 THISCALL ext_589c20(u8 *self, u32 a);
extern "C" u32 THISCALL ext_59a570(u8 *self);
extern "C" u32 THISCALL ext_562d90(u8 *self, u32 a);

static u32 fn5d8420() {
  u8 *eng = G(u8 *, 0x70039c);
  vcall<u32, u32>(eng, 0x1cc, 1);  // @5d8420_a
  return ext_5d7b10();  // @5d8420_b
}
PCREG(5d8420, fn5d8420);

static u32 THISCALL fn475aa0(u8 *self) {
  return vcall<u32, u8 *>(self + 0x2e7, 0xc, self);  // @475aa0
}
PCREG(475aa0, fn475aa0);

static void FASTCALL fn493110(u8 *self, u32 edx) {
  if (self[0xbc2] == 0) {
    self[0xbc2] = 1;  // @493110_s
    u8 *p = *(u8 **)(self + 8);
    if (p) ext_498700(p, edx);  // @493110_c
  }
}
PCREG(493110, fn493110);

static u8 *THISCALL fn4d5510(u8 *self) {
  self[0] = 0;
  *(u32 *)(self + 1) = 0;
  *(u32 *)(self + 5) = 0;
  *(u32 *)(self + 9) = 0;
  *(u32 *)(self + 0xd) = 6;  // @4d5510_six
  *(u32 *)(self + 0x11) = 0;
  return self;
}
PCREG(4d5510, fn4d5510);

static u32 THISCALL fn463300(u8 *self) {
  u32 v = *(u32 *)(*(u8 **)(self + 8) + 0x6c);
  u8 *eng = G(u8 *, 0x70039c);
  u8 *o = *(u8 **)(eng + 0x1aa3);
  u8 *q = *(u8 **)(o + 0x18);
  return vcall<u32, u32>(q, 0xb4, v);  // @463300
}
PCREG(463300, fn463300);

static u32 THISCALL fn49df00(u8 *self) {
  u32 p = *(u32 *)(self + 4);
  *(u32 *)self = 0x68f008;  // @49df00_vt
  if (p) return ext_634273(p, 1);  // @49df00_c
  return 0;
}
PCREG(49df00, fn49df00);

static u32 THISCALL fn56dda0(u8 *self) {
  ext_562260(self);  // @56dda0_a
  u8 *r = (u8 *)ext_589c20(G(u8 *, 0x7003b8), 0);  // @56dda0_b
  if (r) return ext_59a570(r);  // @56dda0_c
  return 0;
}
PCREG(56dda0, fn56dda0);

static u8 THISCALL fn57e210(u8 *self, u32 a) {
  if (*(u32 *)(self + 0x33c) != 0) return 0;  // @57e210_z
  return (u8)ext_562d90(self, a);  // @57e210_c
}
PCREG(57e210, fn57e210);

static u8 THISCALL fn4e1600(u8 *self) {
  if (*(u32 *)(self + 4) == 0) return 0xff;
  u8 b = **(u8 **)(self + 8);
  if (b == 0xff) return 0xff;
  return b & 0x3f;  // @4e1600
}
PCREG(4e1600, fn4e1600);
