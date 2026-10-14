#include "ff.h"

// 0x465850: 7 insns, thiscall(dword_param) ret 4: compare with constant, return bool
u8 THISCALL fn_465850(u8 *self, u32 param) {
  return (param == 0x465710) ? 1 : 0;
}
PCREG(465850, fn_465850);

// 0x64fc20: 9 insns, thiscall(out_param) ret 4: copy two dwords to output
void THISCALL fn_64fc20(u8 *self, u32 *out) {
  out[0] = *(u32 *)(self + 0x60);
  out[1] = *(u32 *)(self + 0x64);
}
PCREG(64fc20, fn_64fc20);

// 0x5ad2b0: 14 insns, thiscall(byte_array_param) ret 4: copy 4 bytes and clear flag
void THISCALL fn_5ad2b0(u8 *self, u8 *src) {
  self[0x48] = src[0];
  self[0x49] = src[1];
  self[0x4a] = src[2];
  self[0x4b] = src[3];
  self[0x4c] = 0;
}
PCREG(5ad2b0, fn_5ad2b0);
