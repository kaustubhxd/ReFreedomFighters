#include "ff.h"

// 0x471640: 11 insns, thiscall(param) ret 4: copy three dwords to fields
void THISCALL fn_471640(u8 *self, u32 *src) {
  *(u32 *)(self + 0xaa) = src[0];
  *(u32 *)(self + 0xae) = src[1];
  *(u32 *)(self + 0xb2) = src[2];
}
PCREG(471640, fn_471640);

// 0x65ca30: 12 insns, thiscall(ptr_param, size_param) ret 4: multi-field init
void THISCALL fn_65ca30(u8 *self, u32 ptr_param, u32 size_param) {
  *(u32 *)(self + 0x400) = ptr_param;
  *(u32 *)(self + 0x410) = 0;
  *(u32 *)(self + 0x41c) = ptr_param + 4;
  *(u32 *)(self + 0x420) = size_param + ptr_param;
}
PCREG(65ca30, fn_65ca30);
