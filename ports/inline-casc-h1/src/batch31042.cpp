#include "ff.h"

// 0x471a10: 13 insns, thiscall(param) ret 4: null check with conditional comparison
u8 THISCALL fn_471a10(u8 *self, u32 *param) {
  if (param == 0) return 0;
  u32 field = *(u32 *)(param + 0xc);
  return (*(u32 *)(field + 0x23) == 0x1007d3) ? 1 : 0;
}
PCREG(471a10, fn_471a10);

// 0x471a70: 13 insns, thiscall(ptr_param) ret 4: similar to 471a10
u32 THISCALL fn_471a70(u8 *self, u32 *param) {
  if (param == 0) return 0;
  u32 field = *(u32 *)(param + 0xc);
  return *(u32 *)(field + 0x10);
}
PCREG(471a70, fn_471a70);
