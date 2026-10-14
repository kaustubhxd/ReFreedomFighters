#include "ff.h"

// 0x46ac30: 6 insns, thiscall(param) ret 4: add param to [ecx+0x8e]
void THISCALL fn_46ac30(u8 *self, u32 param) {
  *(u32 *)(self + 0x8e) += param;
}
PCREG(46ac30, fn_46ac30);

// 0x4711d0: 6 insns, thiscall(param) ret 4: set [ecx+0x8e] to param
void THISCALL fn_4711d0(u8 *self, u32 param) {
  *(u32 *)(self + 0x8e) = param;
}
PCREG(4711d0, fn_4711d0);

// 0x471840: 6 insns, thiscall(param) ret 4: subtract param from [ecx+0x8e]
void THISCALL fn_471840(u8 *self, u32 param) {
  *(u32 *)(self + 0x8e) -= param;
}
PCREG(471840, fn_471840);

// 0x47be00: 6 insns, thiscall(param) ret 4: set [ecx+0x74f] to param
void THISCALL fn_47be00(u8 *self, u32 param) {
  *(u32 *)(self + 0x74f) = param;
}
PCREG(47be00, fn_47be00);
