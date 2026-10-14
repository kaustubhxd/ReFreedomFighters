#include "ff.h"

// 0x4e5000: 9 insns, thiscall: set vtable pointer at [ecx] to 0x6973a4
void THISCALL fn_4e5000(u8 *self) {
  *(u32 *)self = 0x6973a4;
}
PCREG(4e5000, fn_4e5000);

// 0x534d60: 9 insns, thiscall(unused_param) ret 4: check [ecx+0x52fa], if zero return, else tail-jump to 0x53a910
extern "C" void THISCALL ext_53a910(u8 *self);
void THISCALL fn_534d60(u8 *self, u32 unused) {
  u8 *ptr = *(u8 **)(self + 0x52fa);
  if (ptr == 0) return;
  ext_53a910(self);
}
PCREG(534d60, fn_534d60);

// 0x5eeb10: 9 insns, thiscall(param) ret 4: conditional store and flag setter
void THISCALL fn_5eeb10(u8 *self, u32 param) {
  if (*(u32 *)(self + 0x49) != param) {
    *(u32 *)(self + 0x49) = param;
    self[0x77] = 1;
  }
}
PCREG(5eeb10, fn_5eeb10);

// 0x645c10: 9 insns, thiscall(ptr_param) ret 4: conditional byte copy
void THISCALL fn_645c10(u8 *self, u8 *param) {
  if (self[0x266] != 0) {
    *param = self[0x267];
  }
}
PCREG(645c10, fn_645c10);

// 0x63eab0: 8 insns, thiscall(param) ret 4: indexed dword read with mask
u32 THISCALL fn_63eab0(u8 *self, u32 param) {
  u32 masked = param & 0xfff;
  u8 *table = *(u8 **)(self + 0x68);
  return *(u32 *)(table + masked * 4);
}
PCREG(63eab0, fn_63eab0);
