// batch210001.cpp - Sonnet-w3a: tail-jump thunks with a small prologue (vtable store / ecx adjust / vtable slot)
#include "ff.h"

extern "C" u32 THISCALL ext_45c3e0(u8 *self);
static u32 THISCALL fn43de70(u8 *self) {
  *(u32 *)self = 0x67c3a4;  // @43de70_vt
  return ext_45c3e0(self);  // @43de70
}
PCREG(43de70, fn43de70);

extern "C" u32 THISCALL ext_45c3e0(u8 *self);
static u32 THISCALL fn445330(u8 *self) {
  *(u32 *)self = 0x67d748;  // @445330_vt
  return ext_45c3e0(self);  // @445330
}
PCREG(445330, fn445330);

extern "C" u32 THISCALL ext_4cce40(u8 *self);
static u32 THISCALL fn4ccee0(u8 *self) {
  *(u32 *)self = 0x6959f8;  // @4ccee0_vt
  return ext_4cce40(self);  // @4ccee0
}
PCREG(4ccee0, fn4ccee0);

extern "C" u32 THISCALL ext_500a10(u8 *self);
static u32 THISCALL fn519430(u8 *self) {
  *(u32 *)self = 0x69f224;  // @519430_vt
  return ext_500a10(self);  // @519430
}
PCREG(519430, fn519430);

extern "C" u32 THISCALL ext_45c680(u8 *self, u32);
static u32 THISCALL fn4765d0(u8 *self, u32 a0) {
  return ext_45c680(self, a0);  // @4765d0
}
PCREG(4765d0, fn4765d0);

extern "C" u32 THISCALL ext_4e11e0(u8 *self, u32, u32);
static u32 THISCALL fn4e12e0(u8 *self, u32 a0, u32 a1) {
  return ext_4e11e0(self, a0, a1);  // @4e12e0
}
PCREG(4e12e0, fn4e12e0);

extern "C" u32 THISCALL ext_4db5a0(u8 *self, u32);
static u32 THISCALL fn45f020(u8 *self, u32 a0) {
  return ext_4db5a0(*(u8 **)(self + 8), a0);  // @45f020
}
PCREG(45f020, fn45f020);

extern "C" u32 THISCALL ext_4db860(u8 *self, u32);
static u32 THISCALL fn45f070(u8 *self, u32 a0) {
  return ext_4db860(*(u8 **)(self + 8), a0);  // @45f070
}
PCREG(45f070, fn45f070);

extern "C" u32 THISCALL ext_4dca60(u8 *self, u32);
static u32 THISCALL fn45fc70(u8 *self, u32 a0) {
  return ext_4dca60(*(u8 **)(self + 8), a0);  // @45fc70
}
PCREG(45fc70, fn45fc70);

extern "C" u32 THISCALL ext_4dd910(u8 *self, u32);
static u32 THISCALL fn45fde0(u8 *self, u32 a0) {
  return ext_4dd910(*(u8 **)(self + 8), a0);  // @45fde0
}
PCREG(45fde0, fn45fde0);

extern "C" u32 THISCALL ext_5ae930(u8 *self, u32, u32);
static u32 THISCALL fn59cb50(u8 *self, u32 a0, u32 a1) {
  return ext_5ae930(self + 0x57, a0, a1);  // @59cb50
}
PCREG(59cb50, fn59cb50);

static u32 THISCALL fn504880(u8 *self, u32 a0) {
  return vcall<u32, u32>(self, 0x4c, a0);  // @504880
}
PCREG(504880, fn504880);

static u32 THISCALL fn49c610(u8 *self, u32 a0) {
  return vcall<u32, u32>(self, 0x14, a0);  // @49c610
}
PCREG(49c610, fn49c610);

static u32 THISCALL fn4d1630(u8 *self, u32 a0) {
  return vcall<u32, u32>(self, 0x8, a0);  // @4d1630
}
PCREG(4d1630, fn4d1630);

static u32 THISCALL fn4d1e30(u8 *self, u32 a0) {
  return vcall<u32, u32>(self, 0x3c, a0);  // @4d1e30
}
PCREG(4d1e30, fn4d1e30);

extern "C" u32 THISCALL ext_49a300(u8 *self, u32);
static u32 THISCALL fn49b330(u8 *self, u32 a0) {
  return ext_49a300(self, a0 + 1);  // @49b330
}
PCREG(49b330, fn49b330);
