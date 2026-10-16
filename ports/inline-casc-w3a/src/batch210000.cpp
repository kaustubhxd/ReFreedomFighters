// batch210000.cpp - Sonnet-w3a: pure jmp thunks to a thiscall(this) callee
#include "ff.h"

extern "C" u32 THISCALL ext_45c180(u8 *self);
static u32 THISCALL fn45b900(u8 *self) {
  return ext_45c180(self);  // @45b900
}
PCREG(45b900, fn45b900);

extern "C" u32 THISCALL ext_466040(u8 *self);
static u32 THISCALL fn472ff0(u8 *self) {
  return ext_466040(self);  // @472ff0
}
PCREG(472ff0, fn472ff0);

extern "C" u32 THISCALL ext_4805a0(u8 *self);
static u32 THISCALL fn480010(u8 *self) {
  return ext_4805a0(self);  // @480010
}
PCREG(480010, fn480010);

extern "C" u32 THISCALL ext_4ba310(u8 *self);
static u32 THISCALL fn4ba1f0(u8 *self) {
  return ext_4ba310(self);  // @4ba1f0
}
PCREG(4ba1f0, fn4ba1f0);

extern "C" u32 THISCALL ext_5124d0(u8 *self);
static u32 THISCALL fn513500(u8 *self) {
  return ext_5124d0(self);  // @513500
}
PCREG(513500, fn513500);

extern "C" u32 THISCALL ext_5124c0(u8 *self);
static u32 THISCALL fn515620(u8 *self) {
  return ext_5124c0(self);  // @515620
}
PCREG(515620, fn515620);

extern "C" u32 THISCALL ext_562750(u8 *self);
static u32 THISCALL fn5626c0(u8 *self) {
  return ext_562750(self);  // @5626c0
}
PCREG(5626c0, fn5626c0);

extern "C" u32 THISCALL ext_573dd0(u8 *self);
static u32 THISCALL fn573da0(u8 *self) {
  return ext_573dd0(self);  // @573da0
}
PCREG(573da0, fn573da0);

extern "C" u32 THISCALL ext_5b6d00(u8 *self);
static u32 THISCALL fn5b6cf0(u8 *self) {
  return ext_5b6d00(self);  // @5b6cf0
}
PCREG(5b6cf0, fn5b6cf0);

extern "C" u32 THISCALL ext_5b8020(u8 *self);
static u32 THISCALL fn5b8330(u8 *self) {
  return ext_5b8020(self);  // @5b8330
}
PCREG(5b8330, fn5b8330);

extern "C" u32 THISCALL ext_5bd8e0(u8 *self);
static u32 THISCALL fn5bd960(u8 *self) {
  return ext_5bd8e0(self);  // @5bd960
}
PCREG(5bd960, fn5bd960);

extern "C" u32 THISCALL ext_5bf940(u8 *self);
static u32 THISCALL fn5bf930(u8 *self) {
  return ext_5bf940(self);  // @5bf930
}
PCREG(5bf930, fn5bf930);

extern "C" u32 THISCALL ext_5fd170(u8 *self);
static u32 THISCALL fn5fb5a0(u8 *self) {
  return ext_5fd170(self);  // @5fb5a0
}
PCREG(5fb5a0, fn5fb5a0);
