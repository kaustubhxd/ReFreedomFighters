// batch1910.cpp - unclaimed-66 batch 10: three slice-5 leaves (names GUESS; bodies from the bytes). Thiscall.
#include "ff.h"

// 0x435d50, GUESS FUN_00435d50: if the count at this+0xc is below 2 (unsigned), store the argument at this+4 + 4*count and
// count up by one. ret 4.
static void THISCALL leaf435d50(u8 *self, u32 arg) {
  u32 count = *(u32 *)(self + 0xc);
  if (count < 2) {
    *(u32 *)(self + 4 + count * 4) = arg;
    *(u32 *)(self + 0xc) = count + 1;
  }
}
PCREG(435d50, leaf435d50);

// 0x435e90, GUESS FUN_00435e90: index = argument; if index < [this+0x60] (unsigned) return [this+0x20 + 4*index], else 0.
// ret 4.
static u32 THISCALL leaf435e90(u8 *self, u32 index) {
  if (index < *(u32 *)(self + 0x60)) return *(u32 *)(self + 0x20 + index * 4);
  return 0;
}
PCREG(435e90, leaf435e90);

// 0x4a8210, GUESS FUN_004a8210: if the low word of the first argument equals the word at this+0x52, store the second argument
// at this+0x4e. Returns 0 in EAX. ret 8.
static u32 THISCALL leaf4a8210(u8 *self, u32 word, u32 dword) {
  if ((u16)word == *(u16 *)(self + 0x52)) *(u32 *)(self + 0x4e) = dword;
  return 0;
}
PCREG(4a8210, leaf4a8210);
