#include "ff.h"

// 0x51c520: 6 insns, thiscall(byte_param) ret 4: zero-extend byte to dword, store at [ecx+0x469]
void THISCALL fn_51c520(u8 *self, u8 param) {
  *(u32 *)(self + 0x469) = (u32)param;
}
PCREG(51c520, fn_51c520);

// 0x5398c0: 6 insns, thiscall(dword_param) ret 4: store dword at [ecx+0x52f2]
void THISCALL fn_5398c0(u8 *self, u32 param) {
  *(u32 *)(self + 0x52f2) = param;
}
PCREG(5398c0, fn_5398c0);

// 0x54ba20: 6 insns, thiscall(byte_param) ret 4: store byte at [ecx+0xa273]
void THISCALL fn_54ba20(u8 *self, u8 param) {
  self[0xa273] = param;
}
PCREG(54ba20, fn_54ba20);

// 0x5eebc0: 6 insns, thiscall(dword_param) ret 4: store dword at [ecx+0x73]
void THISCALL fn_5eebc0(u8 *self, u32 param) {
  *(u32 *)(self + 0x73) = param;
}
PCREG(5eebc0, fn_5eebc0);

// 0x639c40: 6 insns, thiscall(dword_param) ret 4: store dword at [ecx+0x29]
void THISCALL fn_639c40(u8 *self, u32 param) {
  *(u32 *)(self + 0x29) = param;
}
PCREG(639c40, fn_639c40);
