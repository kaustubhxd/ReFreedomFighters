#include "ff.h"

// 0x466600: 7 insns, thiscall(byte_param) ret 4: byte swap - returns [ecx], stores param
u8 THISCALL fn_466600(u8 *self, u8 param) {
  u8 old = *self;
  *self = param;
  return old;
}
PCREG(466600, fn_466600);

// 0x518730: 7 insns, thiscall(byte_param) ret 4: store byte at two locations
void THISCALL fn_518730(u8 *self, u8 param) {
  self[0x133] = param;
  self[0x394] = param;
}
PCREG(518730, fn_518730);

// 0x54db80: 7 insns, thiscall: compare [ecx+0x40ad] with 1, return 0 if equal, else increment
u32 THISCALL fn_54db80(u8 *self) {
  u32 val = *(u32 *)(self + 0x40ad);
  if (val == 1) return 0;
  return val + 1;
}
PCREG(54db80, fn_54db80);

// 0x49b340: 8 insns, thiscall(param1, param2) ret 8: store two dwords
void THISCALL fn_49b340(u8 *self, u32 param1, u32 param2) {
  *(u32 *)(self + 0x14) = param1;
  *(u32 *)(self + 0x18) = param2;
}
PCREG(49b340, fn_49b340);

// 0x5b07d0: 8 insns, thiscall(param1, param2) ret 8: store two dwords at 8 and 0x10
void THISCALL fn_5b07d0(u8 *self, u32 param1, u32 param2) {
  *(u32 *)(self + 8) = param1;
  *(u32 *)(self + 0x10) = param2;
}
PCREG(5b07d0, fn_5b07d0);
