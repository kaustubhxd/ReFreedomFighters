// batch35070.cpp - cascade s5 batch 35070: 0x570e80 (GUESS apply a mode change to a session object by mode number).
#include "ff.h"

extern "C" void THISCALL ext_562c20(u8 *self, u32 k);   // thiscall, ret 4
extern "C" void THISCALL ext_5718b0(u8 *self);          // plain ret
extern "C" void THISCALL ext_59b710(u32 self);          // plain ret
extern "C" void THISCALL ext_5707d0(u8 *self);          // plain ret
typedef u8(THISCALL *b0_t)(void *);
typedef void(THISCALL *v1_t)(void *, u32);

// 0x570e80, thiscall(k) ret 4, returns bool. 0x562c20(this, k); this slot 0xd8() true gives false. Otherwise (k != 3: 0x5718b0(this)), 0x59b710([this+0x94]); k == 1: 0x5707d0(this), true;
// k == 2: this slot 0xd0([this+0x190]), true; k == 3: this slot 0xd0([this+0x198]), true; any other k gives false.
static u8 THISCALL fn570e80(u8 *self, u32 k) {
  ext_562c20(self, k);
  if ((*(b0_t **)self)[0xd8 / 4](self)) return 0;
  if (k != 3) ext_5718b0(self);
  ext_59b710(*(u32 *)(self + 0x94));
  if (k == 1) {
    ext_5707d0(self);
    return 1;
  }
  if (k == 2) {
    (*(v1_t **)self)[0xd0 / 4](self, *(u32 *)(self + 0x190));
    return 1;
  }
  if (k == 3) {
    (*(v1_t **)self)[0xd0 / 4](self, *(u32 *)(self + 0x198));
    return 1;
  }
  return 0;
}
PCREG(570e80, fn570e80);
