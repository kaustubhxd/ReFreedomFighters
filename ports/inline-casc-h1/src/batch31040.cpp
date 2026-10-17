#include "ff.h"

// 0x591d30: 13 insns, thiscall(index_param) ret 4: bounds check with computed index
u32 THISCALL fn_591d30(u8 *self, u32 index) {
  u32 limit = *(u32 *)(self + 0xa16);
  if (index >= limit) {
    return 0;
  }
  u32 computed = index + index*2;  // index * 3
  computed = computed * 2;  // index * 6
  return *(u32 *)(self + computed*8 + 0xa1a);
}
PCREG(591d30, fn_591d30);

// 0x517510: 13 insns, thiscall(word_param) ret 4: word comparison with conditional
u32 THISCALL fn_517510(u8 *self, u16 param) {
  u16 field = *(u16 *)(self + 0x164e);
  if (param != field) {
    return 0;
  }
  u32 val = *(u32 *)(self + 0x1639);
  if (val <= 0) {
    return 0;
  }
  return val - 1;
}
PCREG(517510, fn_517510);
