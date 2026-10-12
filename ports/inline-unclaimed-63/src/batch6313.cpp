// batch6313.cpp - unclaimed-63 batch 13 (docs/20-unclaimed-63.md): ZMoveOnSpline::Resurrect(float) at 0x513ee0 (GC name, high).
// c = [this+0x134]; if c: c->vtbl[+0x28]() (thiscall, no arguments). Then [this+0x1c9] = -1.0f; v = (0 > t) ? 0.0f : minss(1.0f, t);
// this->vtbl[+0x2d0](v); this->vtbl[+0x2c](); this->vtbl[+0xbc](0); [this+0xc4] = 1. Callee pops 4 (ret 4).
#include "ff.h"

typedef u32(THISCALL * call0_fn)(void *);
typedef void(THISCALL * call1_fn)(void *, u32);
typedef void(THISCALL * call1f_fn)(void *, float);

// 0x513ee0 (high). The minss is kept as the SSE intrinsic: _mm_min_ss(1.0, t) returns t when 1.0 < t is false (NaN gives t).
static void THISCALL moveOnSplineResurrect(u8 *self, float t) {
  u32 c = *(u32 *)(self + 0x134);
  if (c != 0)
    ((call0_fn)(*(u32 *)(*(u32 *)c + 0x28)))((void *)c);
  *(u32 *)(self + 0x1c9) = 0xbf800000u;
  float v = (0.0f > t) ? 0.0f : _mm_cvtss_f32(_mm_min_ss(_mm_set_ss(1.0f), _mm_set_ss(t)));
  ((call1f_fn)(*(u32 *)(*(u32 *)self + 0x2d0)))((void *)self, v);
  ((call0_fn)(*(u32 *)(*(u32 *)self + 0x2c)))((void *)self);
  ((call1_fn)(*(u32 *)(*(u32 *)self + 0xbc)))((void *)self, 0);
  *(u32 *)(self + 0xc4) = 1;
}
PCREG(513ee0, moveOnSplineResurrect);
