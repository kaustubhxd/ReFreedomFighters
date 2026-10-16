#include "ff.h"
static u32 THISCALL fn4d5370(u8 *self, u32 target, s32 delta, u32 mode) {
  u8 *field = self + 4;
  if (target != (u32)field) {
    u32 assertion = G(u32, 0x7003b0);
    if (assertion) return ((u32 (FASTCALL *)(void))assertion)();
    __asm__ volatile("int3");
    return 0;
  }
  s32 value = G(s32, field + 4);
  if (mode == 0) value = delta;
  else if (mode == 1) value += delta;
  else if (mode == 2) value = (s32)G(u32, field + 8) + delta;
  s32 maximum = G(s32, field + 8);
  if (value > maximum) value = maximum;
  if (value < 0) value = 0;
  G(s32, field + 4) = value;
  return (u32)value;
}
PCREG(4d5370, fn4d5370);
