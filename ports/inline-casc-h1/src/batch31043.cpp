#include "ff.h"

// 0x4db580: 12 insns, thiscall(index) ret 4: bounds check with indexed read
u32 THISCALL fn_4db580(u8 *self, u32 index) {
  u8 limit = self[0x1c];
  if (index >= limit) return 0;
  return *(u32 *)(self + index*4);
}
PCREG(4db580, fn_4db580);

// 0x4cf1c0: 13 insns, thiscall(out_ptr) ret 4: copy fields and conditional store
void THISCALL fn_4cf1c0(u8 *self, u32 *out) {
  out[2] = 0xffffffff;
  out[0] = *(u32 *)(self + 8);
  u32 *ptr = *(u32 **)(self + 8);
  if (ptr != 0) {
    out[1] = *(u32 *)(ptr + 8);
  }
}
PCREG(4cf1c0, fn_4cf1c0);

// 0x624960: 13 insns, thiscall(ptr) ret: byte comparison with multiple checks
u8 THISCALL fn_624960(u8 *self, u8 *ptr) {
  if (ptr[0] != 0xf4) return 0;
  if ((ptr[1] & 0x30) == 0) return 0;
  return 1;
}
PCREG(624960, fn_624960);
