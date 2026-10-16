// batch210002.cpp - Sonnet-w3a: small BLOCKED rows (tiny forwarders, constants, member-call chains)
#include "ff.h"

extern "C" u32 THISCALL ext_573db0(u8 *self);
extern "C" u32 THISCALL ext_575230(u8 *self);
extern "C" u32 THISCALL ext_5626c0(u8 *self);
extern "C" u32 THISCALL ext_573dd0(u8 *self);
extern "C" u32 THISCALL ext_4690b0(u8 *self);
extern "C" u32 THISCALL ext_563da0(u8 *self);
extern "C" u32 THISCALL ext_5ef040(u8 *self, u32 a);
extern "C" u32 THISCALL ext_5ef050(u8 *self, u32 a);
extern "C" u32 FASTCALL ext_603dd0(u32 a, u32 b);
extern "C" u32 THISCALL ext_43f900(u8 *self, u32 a);
extern "C" u32 THISCALL ext_445800(u8 *self, u32 a);
extern "C" u32 THISCALL ext_4e1b30(u8 *self);
extern "C" u32 THISCALL ext_45d380(u8 *self, u32 a, u32 b);

static u32 fn42acb5() { return 0x6ff950; }
PCREG(42acb5, fn42acb5);

static u8 STDCALL fn560360(u32 a) { (void)a; return 0; }
PCREG(560360, fn560360);

static u32 THISCALL fn575220(u8 *self) {
  ext_573db0(self);  // @575220_a
  return ext_575230(self);  // @575220_b
}
PCREG(575220, fn575220);

static u32 THISCALL fn573db0(u8 *self) {
  ext_5626c0(self);  // @573db0_a
  self[0x1f0] = 1;  // @573db0_s
  return ext_573dd0(self);  // @573db0_b
}
PCREG(573db0, fn573db0);

static u32 THISCALL fn511ab0(u8 *self) {
  ext_4690b0(self + 0xb6);  // @511ab0_a
  return ext_4690b0(self + 0x3d);  // @511ab0_b
}
PCREG(511ab0, fn511ab0);

static u32 THISCALL fn562260(u8 *self) {
  vcall<u32>(self, 0xf0);  // @562260_a
  return ext_563da0(self);  // @562260_b
}
PCREG(562260, fn562260);

static u32 THISCALL fn5a5c80(u8 *self, u32 a, u32 b, u32 c) {
  (void)a; (void)b;
  return ext_5ef040(*(u8 **)(self + 0x62c), c);  // @5a5c80
}
PCREG(5a5c80, fn5a5c80);

static u32 THISCALL fn5a5c60(u8 *self) {
  ext_5ef050(*(u8 **)(self + 0x62c), 1);  // @5a5c60_a
  u8 *m = *(u8 **)(self + 0x62c);
  return vcall<u32>(m, 8);  // @5a5c60_b
}
PCREG(5a5c60, fn5a5c60);

static u32 STDCALL fn601d60(u32 a, u32 b) {
  return ext_603dd0(a, b);  // @601d60
}
PCREG(601d60, fn601d60);

static u32 THISCALL fn44edd0(u8 *self, u8 *a) {
  ext_43f900(self, (u32)a);  // @44edd0_a
  return ext_4e1b30(a);  // @44edd0_b
}
PCREG(44edd0, fn44edd0);

static u32 THISCALL fn5b22e0(u8 *self, u8 *a) {
  ext_445800(self, (u32)a);  // @5b22e0_a
  return ext_4e1b30(a);  // @5b22e0_b
}
PCREG(5b22e0, fn5b22e0);

static u32 THISCALL fn52aae0(u8 *self, u32 a, u32 b) {
  ext_45d380(self, a, b);  // @52aae0
  return 0;
}
PCREG(52aae0, fn52aae0);

static u32 THISCALL fn5ebd80(u8 *self, u32 a) {
  u32 cur;
  __builtin_memcpy(&cur, self + 0x36, 4);
  if (cur != a) __builtin_memcpy(self + 0x36, &a, 4);  // @5ebd80
  return a;
}
PCREG(5ebd80, fn5ebd80);

static u32 fn44a1f0() { return ext_4690b0(0); }  // @44a1f0
PCREG(44a1f0, fn44a1f0);
