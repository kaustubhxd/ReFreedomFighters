#include "ff.h"

// 0x4be6d0: 6 insns, thiscall(byte_param) ret 4: store byte param at [ecx+0xd1]
void THISCALL fn_4be6d0(u8 *self, u8 param) {
  self[0xd1] = param;
}
PCREG(4be6d0, fn_4be6d0);

// 0x4d4a30: 6 insns, thiscall(ptr_param) ret 4: dereference param, return [param+0]
u32 THISCALL fn_4d4a30(u8 *self, u8 *param) {
  return *(u32 *)param;
}
PCREG(4d4a30, fn_4d4a30);

// 0x4e5470: 6 insns, thiscall(ptr_param) ret 4: return word from [param+8]
u32 THISCALL fn_4e5470(u8 *self, u8 *param) {
  return (u32)(*(u16 *)(param + 8));
}
PCREG(4e5470, fn_4e5470);
