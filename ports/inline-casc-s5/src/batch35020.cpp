// batch35020.cpp - cascade s5 batch 35020: 0x51e700 (GUESS switch an object's mode on or off).
#include "ff.h"

typedef u32(THISCALL *g0_t)(void *);
typedef u8(THISCALL *b0_t)(void *);
typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);

// 0x51e700, stdcall(o, on, c) ret 0xc; only the low byte of `on` is tested. Off: o slot 0x2d0(0, 0). On: slot 0x33c(3); when slot 0x35c() is zero slot 0x360(0x64); when slot 0x354()
// (bool) is false slot 0x2d0(6, 0) and slot 0x2d0(0, 0); then slot 0x2d0(0, 0), slot 0x2d0(3, 0) and slot 0x32c(c).
static void STDCALL fn51e700(u8 *o, u32 on, u32 c) {
  if (!(u8)on) {
    (*(v2_t **)o)[0x2d0 / 4](o, 0, 0);
    return;
  }
  (*(v1_t **)o)[0x33c / 4](o, 3);
  if (!(*(g0_t **)o)[0x35c / 4](o)) (*(v1_t **)o)[0x360 / 4](o, 0x64);
  if (!(*(b0_t **)o)[0x354 / 4](o)) {
    (*(v2_t **)o)[0x2d0 / 4](o, 6, 0);
    (*(v2_t **)o)[0x2d0 / 4](o, 0, 0);
  }
  (*(v2_t **)o)[0x2d0 / 4](o, 0, 0);
  (*(v2_t **)o)[0x2d0 / 4](o, 3, 0);
  (*(v1_t **)o)[0x32c / 4](o, c);
}
PCREG(51e700, fn51e700);
