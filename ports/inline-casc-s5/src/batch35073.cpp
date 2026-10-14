// batch35073.cpp - cascade s5 batch 35073: 0x4f3ee0 (GUESS attach or detach this object through its parent link).
#include "ff.h"

extern "C" void THISCALL ext_45f070(u8 *self, u32 f);   // thiscall, ret 4
typedef u8 *(THISCALL *g0_t)(void *);
typedef void(THISCALL *v1_t)(void *, void *);
typedef void(THISCALL *v2_t)(void *, void *, u32);

// 0x4f3ee0, thiscall(f) ret 4 (only the low byte of f is tested). 0x45f070(this, f). f == 0: e = this slot 0x2e0(); when non-null this slot 0x2c4() slot 0x2ec(e). f != 0: e0 = (this slot 0x2c4()) slot 0x2f0();
// when non-null walk e = e0, e slot 0x20(), ...: reaching this gives this slot 0x2c4() slot 0x2f4(e0, 1); a null link ends the walk.
static void THISCALL fn4f3ee0(u8 *self, u32 f) {
  ext_45f070(self, f);
  if ((u8)f == 0) {
    u8 *e = (*(g0_t **)self)[0x2e0 / 4](self);
    if (!e) return;
    u8 *p = (*(g0_t **)self)[0x2c4 / 4](self);
    (*(v1_t **)p)[0x2ec / 4](p, e);
    return;
  }
  u8 *p = (*(g0_t **)self)[0x2c4 / 4](self);
  u8 *e0 = (*(g0_t **)p)[0x2f0 / 4](p);
  if (!e0) return;
  u8 *e = e0;
  while (e != self) {
    e = (*(g0_t **)e)[0x20 / 4](e);
    if (!e) return;
  }
  p = (*(g0_t **)self)[0x2c4 / 4](self);
  (*(v2_t **)p)[0x2f4 / 4](p, e0, 1);
}
PCREG(4f3ee0, fn4f3ee0);
