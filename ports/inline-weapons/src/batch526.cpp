// batch526.cpp - weapons thread, batch 526: the seven ZLnkAction constructors used by ZLNKWHANDS::CreateLnkAction
// (0x4733d0). Each stores its arguments at +4.. and sets the vtable (data address from the exe). Layouts are from
// the stores below; the vtable addresses name the classes only through the exe's RTTI, which is not checked here.
#include "ff.h"

typedef u32 u32_t;

// 0x485d30: five arguments, +8 = 0, returns this.
static u32 THISCALL lnkA(u8 *self, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
  *(u32 *)(self + 4) = a0;
  *(u32 *)(self + 0xc) = a1;
  *(u32 *)(self + 0x10) = a2;
  *(u32 *)(self + 0x14) = a3;
  *(u32 *)(self + 0x18) = a4;
  *(u32 *)self = 0x68cbe4;
  *(u32 *)(self + 8) = 0;
  return (u32)self;
}
PCREG(485d30, lnkA);

// 0x485df0: five arguments, no zeroed field.
static u32 THISCALL lnkB(u8 *self, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
  *(u32 *)(self + 4) = a0;
  *(u32 *)(self + 8) = a1;
  *(u32 *)(self + 0xc) = a2;
  *(u32 *)(self + 0x10) = a3;
  *(u32 *)(self + 0x14) = a4;
  *(u32 *)self = 0x68cc1c;
  return (u32)self;
}
PCREG(485df0, lnkB);

// 0x485d00: four arguments at +4, +8, +0xc, +0x10; ret 0x10.
static u32 THISCALL lnkC(u8 *self, u32 a0, u32 a1, u32 a2, u32 a3) {
  *(u32 *)(self + 4) = a0;
  *(u32 *)(self + 8) = a1;
  *(u32 *)(self + 0xc) = a2;
  *(u32 *)(self + 0x10) = a3;
  *(u32 *)self = 0x68cc90;
  return (u32)self;
}
PCREG(485d00, lnkC);

// 0x485d70: four arguments at +4, +0xc, +0x10, +0x14; +8 = 0.
static u32 THISCALL lnkD(u8 *self, u32 a0, u32 a1, u32 a2, u32 a3) {
  *(u32 *)(self + 4) = a0;
  *(u32 *)(self + 0xc) = a1;
  *(u32 *)(self + 0x10) = a2;
  *(u32 *)(self + 0x14) = a3;
  *(u32 *)(self + 8) = 0;
  *(u32 *)self = 0x68cc54;
  return (u32)self;
}
PCREG(485d70, lnkD);

// 0x485e90: five arguments at +4, +8, +0xc, +0x10, +0x14.
static u32 THISCALL lnkE(u8 *self, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
  *(u32 *)(self + 4) = a0;
  *(u32 *)(self + 8) = a1;
  *(u32 *)(self + 0xc) = a2;
  *(u32 *)(self + 0x10) = a3;
  *(u32 *)(self + 0x14) = a4;
  *(u32 *)self = 0x68ccc8;
  return (u32)self;
}
PCREG(485e90, lnkE);

// 0x485db0: four arguments at +4, +0xc, +0x10, +0x14; +8 = 0.
static u32 THISCALL lnkF(u8 *self, u32 a0, u32 a1, u32 a2, u32 a3) {
  *(u32 *)(self + 4) = a0;
  *(u32 *)(self + 0xc) = a1;
  *(u32 *)(self + 0x10) = a2;
  *(u32 *)(self + 0x14) = a3;
  *(u32 *)(self + 8) = 0;
  *(u32 *)self = 0x68cd00;
  return (u32)self;
}
PCREG(485db0, lnkF);

// 0x485e30: ten arguments. The exe's stack reads are a0..a5, a6 (ebp+0x20) to +0x1c, a8 (ebp+0x28) to +0x20, a7 (ebp+0x24)
// to +0x24, a9 (ebp+0x2c) to +0x28; +0x2c = 0. Returns this.
static u32 THISCALL lnkG(u8 *self, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8, u32 a9) {
  *(u32 *)(self + 4) = a0;
  *(u32 *)(self + 8) = a1;
  *(u32 *)(self + 0xc) = a2;
  *(u32 *)(self + 0x10) = a3;
  *(u32 *)(self + 0x14) = a4;
  *(u32 *)(self + 0x18) = a5;
  *(u32 *)(self + 0x1c) = a6;
  *(u32 *)(self + 0x20) = a8;
  *(u32 *)(self + 0x24) = a7;
  *(u32 *)(self + 0x28) = a9;
  *(u32 *)self = 0x68cd3c;
  *(u32 *)(self + 0x2c) = 0;
  return (u32)self;
}
PCREG(485e30, lnkG);
