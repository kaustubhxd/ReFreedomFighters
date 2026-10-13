// batch1410.cpp - unclaimed-14 batch 10 (slice 13): ZInputActions::CheckActionCheat(const char*, void*).
#include "ff.h"

// 0x4380d0, ZInputActions::CheckActionCheat(const char*, void*) (high): thiscall, two stack arguments (ret 8). If the byte
// at [0x70039c]+0x9b9 is zero it returns 0 (PC: xor al,al, so only al is defined). Otherwise it calls vtable slot +0x58 with
// the name, then vtable slot +0x2c with (that result, 0) and returns that call's eax. The second argument is not read.
static u32 THISCALL inputActionsCheckActionCheat(u8 *self, u32 name, u32 a2) {
  (void)a2;
  u8 *g = G(u8 *, 0x70039c);
  if (g[0x9b9] == 0)
    return 0;
  typedef u32(THISCALL * f58_t)(u8 *, u32);
  typedef u32(THISCALL * f2c_t)(u8 *, u32, u32);
  u32 v = (*(f58_t *)(*(u32 *)self + 0x58))(self, name);
  return (*(f2c_t *)(*(u32 *)self + 0x2c))(self, v, 0);
}
PCREG(4380d0, inputActionsCheckActionCheat);
