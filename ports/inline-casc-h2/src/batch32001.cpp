// batch32001.cpp - h2 batch 32001: eight more tiny getters
#include "ff.h"

// 0x46ed00, thiscall(self) ret eax: return dword at [self + 0x8e]
static u32 THISCALL fn46ed00(u8 *self) {
  return *(u32 *)(self + 0x8e);
}
PCREG(46ed00, fn46ed00);

// 0x46eec0, thiscall(self) ret eax: return dword at [self + 0xcf]
static u32 THISCALL fn46eec0(u8 *self) {
  return *(u32 *)(self + 0xcf);
}
PCREG(46eec0, fn46eec0);

// 0x46efb0, thiscall(self) ret eax: return dword at [self + 0xc7]
static u32 THISCALL fn46efb0(u8 *self) {
  return *(u32 *)(self + 0xc7);
}
PCREG(46efb0, fn46efb0);

// 0x471850, thiscall(self) ret eax: return address of [self + 0xaa]
static u32 THISCALL fn471850(u8 *self) {
  return (u32)(self + 0xaa);
}
PCREG(471850, fn471850);

// 0x474310, thiscall(self) ret al: return byte at [self + 0x3bb]
static u8 THISCALL fn474310(u8 *self) {
  return self[0x3bb];
}
PCREG(474310, fn474310);

// 0x4744b0, thiscall(self) ret eax: return dword at [self + 0x3b7]
static u32 THISCALL fn4744b0(u8 *self) {
  return *(u32 *)(self + 0x3b7);
}
PCREG(4744b0, fn4744b0);

// 0x4808c0, (self) ret eax: return dword at global 0x6e5ef8
static u32 fn4808c0(void) {
  return *(u32 *)0x6e5ef8;
}
PCREG(4808c0, fn4808c0);

