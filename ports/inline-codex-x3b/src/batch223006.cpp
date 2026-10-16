#include "ff.h"

extern "C" float FASTCALL ext_4e0830(u8 *a, u8 *b);
extern "C" void THISCALL ext_662cf0(u8 *self);

// 0x662e20: thiscall(this, target_vec), ret 4.  When a new target direction
// differs by more than the scalar tolerance, replace it and rebuild the
// position/easing pull state.
void THISCALL fn_662e20(u8 *self, const u8 *target_vec) {
  float distance = ext_4e0830((u8 *)target_vec, self + 0x10);
  if (!(distance > G(float, 0x67a284))) return; // m0
  *(u32 *)(self + 0x10) = *(const u32 *)(target_vec + 0); // m1
  *(u32 *)(self + 0x14) = *(const u32 *)(target_vec + 4);
  *(u32 *)(self + 0x18) = *(const u32 *)(target_vec + 8); // m2
  ext_662cf0(self); // m3
}
PCREG(662e20, fn_662e20);
