// batch78.cpp - unclaimed-68 batch 78 (slice 7). Names GUESS (FUN_addr).
#include "ff.h"
#include <stdint.h>

typedef u32(THISCALL *VSlot1bc)(u8 *self, u32 a, u32 b);
typedef void(THISCALL *VSlot58)(u8 *self, u32 v, u32 zero);

// 0x42cb30: r = this.slot+0x1bc(arg1, arg2) (args pushed arg2 then arg1); f = (float)(int32)r - K1; f = f * K2 (single precision); returns ST0. ret 8.
static float THISCALL g42cb30(u8 *self, u32 a1, u32 a2) {
  u32 r = ((VSlot1bc)*(u32 *)(*(u8 **)self + 0x1bc))(self, a1, a2);
  float f = (float)(int32_t)r;
  f = f - G(float, 0x678624);
  f = f * G(float, 0x6785e0);
  return f;
}
PCREG(42cb30, g42cb30);

// 0x63cfb0: obj = arg2; w = word [[obj+8]+0x5a]; if (w): idx = w & 0xfff; v = [[this+0x68]+4*idx]; this.slot+0x58(v, 0). ret 8.
static void THISCALL g63cfb0(u8 *self, u32 a1, u8 *obj) {
  (void)a1;
  u8 *rec = *(u8 **)(obj + 8);
  u16 w = *(u16 *)(rec + 0x5a);
  if (w != 0) {
    u32 idx = w & 0xfffu;
    u32 *tab = *(u32 **)(self + 0x68);
    ((VSlot58)*(u32 *)(*(u8 **)self + 0x58))(self, tab[idx], 0u);
  }
}
PCREG(63cfb0, g63cfb0);
