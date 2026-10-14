// batch32000.cpp - h2 batch 32000: eight tiny getter/setter functions
#include "ff.h"

extern "C" void THISCALL ext_4478d0(u8 *self);

// 0x443ac0, thiscall(self) ret eax: return this as eax
static u32 THISCALL fn443ac0(u8 *self) {
  return (u32)self;
}
PCREG(443ac0, fn443ac0);

// 0x4529d0, thiscall(self): set [self] = 0x681860, then tail to 0x4478d0
static void THISCALL fn4529d0(u8 *self) {
  *(u32 *)self = 0x681860;
  ext_4478d0(self);
}
PCREG(4529d0, fn4529d0);

// 0x466610, thiscall(self): clear byte at [self + 0x158]
static void THISCALL fn466610(u8 *self) {
  self[0x158] = 0;
}
PCREG(466610, fn466610);

// 0x466cd0, thiscall(self) ret al: return byte at [self]
static u8 THISCALL fn466cd0(u8 *self) {
  return self[0];
}
PCREG(466cd0, fn466cd0);

// 0x469120, (self) ret eax: return dword at global 0x6e59d8
static u32 fn469120(void) {
  return *(u32 *)0x6e59d8;
}
PCREG(469120, fn469120);

// 0x46e680, thiscall(self) ret eax: return dword at [self + 0x94]
static u32 THISCALL fn46e680(u8 *self) {
  return *(u32 *)(self + 0x94);
}
PCREG(46e680, fn46e680);

// 0x46e6a0, thiscall(self) ret eax: return dword at [self + 0xa4]
static u32 THISCALL fn46e6a0(u8 *self) {
  return *(u32 *)(self + 0xa4);
}
PCREG(46e6a0, fn46e6a0);

// 0x46e700, (self) ret eax: return constant 0x6866a8
static u32 fn46e700(void) {
  return 0x6866a8;
}
PCREG(46e700, fn46e700);
