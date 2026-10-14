// batch35010.cpp - cascade s5 batch 35010: 0x434fb0 (GUESS release the owned container at +4 and the items it hands out).
#include "ff.h"

typedef void(THISCALL *v0_t)(void *);
typedef void(THISCALL *v1_t)(void *, void *);
typedef void(THISCALL *v1u_t)(void *, u32);
typedef u32 *(THISCALL *g1_t)(void *, void *);
typedef u32(THISCALL *g0_t)(void *);

// 0x434fb0, thiscall, no arguments. C = [this+4] (reloaded before every use). When C is set: C slot 0x4c(&it), then for every p returned by C slot 0x64(&it):
// s = *p; s slot 0x38(), s slot 0x30(1), C slot 0x44(&it). Afterwards, when C is set and slot 0x14() is zero: delete C (slot 0 with 1, when still set) and clear [this+4].
static void THISCALL fn434fb0(u8 *self) {
  u32 it[3];
  void *c = *(void **)(self + 4);
  if (c) {
    (*(v1_t **)c)[0x4c / 4](c, it);
    c = *(void **)(self + 4);
    u32 *p = (*(g1_t **)c)[0x64 / 4](c, it);
    while (p) {
      void *s = (void *)*p;
      (*(v0_t **)s)[0x38 / 4](s);
      (*(v1u_t **)s)[0x30 / 4](s, 1);
      c = *(void **)(self + 4);
      (*(v1_t **)c)[0x44 / 4](c, it);
      c = *(void **)(self + 4);
      p = (*(g1_t **)c)[0x64 / 4](c, it);
    }
  }
  c = *(void **)(self + 4);
  if (c && !(*(g0_t **)c)[0x14 / 4](c)) {
    c = *(void **)(self + 4);
    if (c) (*(v1u_t **)c)[0](c, 1);
    *(u32 *)(self + 4) = 0;
  }
}
PCREG(434fb0, fn434fb0);
