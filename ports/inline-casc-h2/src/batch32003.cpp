// batch32003.cpp - h2 batch 32003: simple field setters and getters
#include "ff.h"

// 0x54cd00, thiscall(self): set [self] = 0x6a3e14
static void THISCALL fn54cd00(u8 *self) {
  *(u32 *)self = 0x6a3e14;
}
PCREG(54cd00, fn54cd00);

// 0x59b330, thiscall(self) ret eax: return dword at [self + 0x121a8]
static u32 THISCALL fn59b330(u8 *self) {
  return *(u32 *)(self + 0x121a8);
}
PCREG(59b330, fn59b330);

// 0x59c610, thiscall(self) ret eax: return address of [self + 0x12108]
static u32 THISCALL fn59c610(u8 *self) {
  return (u32)(self + 0x12108);
}
PCREG(59c610, fn59c610);

// 0x5c7f00, thiscall(self): set [self] = 0x6b48f0
static void THISCALL fn5c7f00(u8 *self) {
  *(u32 *)self = 0x6b48f0;
}
PCREG(5c7f00, fn5c7f00);

// 0x60d810, thiscall(self) ret eax: return address of [self + 0x94]
static u32 THISCALL fn60d810(u8 *self) {
  return (u32)(self + 0x94);
}
PCREG(60d810, fn60d810);

// 0x616a50, thiscall(self): set [self] = 0x6bdc38
static void THISCALL fn616a50(u8 *self) {
  *(u32 *)self = 0x6bdc38;
}
PCREG(616a50, fn616a50);

// 0x63db10, (self) ret eax: return constant 0x18
static u32 fn63db10(void) {
  return 0x18;
}
PCREG(63db10, fn63db10);

// 0x63ec90, (self) ret eax: return constant 0x35
static u32 fn63ec90(void) {
  return 0x35;
}
PCREG(63ec90, fn63ec90);
