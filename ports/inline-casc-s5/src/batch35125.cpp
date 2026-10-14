// batch35125.cpp - cascade s5 batch 35125: 0x5797e0 (GUESS handle mode k: mode 1 looks up and applies a resource word, others run helper 0x579880).
#include "ff.h"

extern "C" u32 THISCALL ext_562c20(u8 *self, u32 k);   // thiscall, ret 4
extern "C" void THISCALL ext_579880(u8 *self, u32 a);  // thiscall, ret 4
typedef u8(THISCALL *b0_t)(void *);
typedef u32(THISCALL *g5_t)(void *, u32, u32, u32, u32, u8 *);
typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef void(THISCALL *v1_t)(void *, u32);

// 0x5797e0, thiscall(k) ret 4, returns bool in AL (false from slot 0xd8; otherwise whatever 0x562c20 leaves). this slot 0xd8() true gives false. k == 1: w = low word of [engine+0x9b] slot 0x114(0x6a6ffc, 0, 0x6a9a24, 0x107, this + 0x194);
// [this+0x44] slot 0x12c([this+0x18c], w); this slot 0xd0([this+0x18c]); 0x562c20(this, k). Other k: 0x579880(this, 0x103); 0x562c20(this, k).
static u32 THISCALL fn5797e0(u8 *self, u32 k) {
  if ((*(b0_t **)self)[0xd8 / 4](self)) return 0;
  if (k == 1) {
    u8 *o = *(u8 **)(self + 0x44);
    u32 f = (*(u32 **)o)[0x12c / 4];
    u8 *eng = G(u8 *, 0x70039c);
    u8 *tab = *(u8 **)(eng + 0x9b);
    u32 w = (*(g5_t **)tab)[0x114 / 4](tab, 0x6a6ffc, 0, 0x6a9a24, 0x107, self + 0x194);
    ((v2_t)f)(*(u8 **)(self + 0x44), *(u32 *)(self + 0x18c), w & 0xffff);
    (*(v1_t **)self)[0xd0 / 4](self, *(u32 *)(self + 0x18c));
    return ext_562c20(self, k);
  }
  ext_579880(self, 0x103);
  return ext_562c20(self, k);
}
PCREG(5797e0, fn5797e0);
