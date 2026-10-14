// batch35129.cpp - cascade s5 batch 35129: 0x4f61b0 (GUESS create a named child through a factory, attach it with flags and configure it).
#include "ff.h"

extern "C" void THISCALL ext_4dc630(u32 self, u32 a, u32 b);   // thiscall, ret 8
typedef u8 *(THISCALL *f4_t)(void *, u32, u32, u32, u32);
typedef u8 *(THISCALL *a3_t)(void *, u8 *, u32, u32);
typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v0_t)(void *);

// 0x4f61b0, thiscall(A, b, c, d) ret 0x10, returns the object or 0. o = A slot 0x294(0x69a674, 0x699918, 0, 1); null gives 0. x = this slot 0x2d8(o, b, 0x20002d); x slot 0x270(0x2f); o slot 0x30c(c); o slot 0x154();
// 0x4dc630([o+8], 0x800000, 0); o slot 0x158(); o slot 0x2ec(1); x slot 0x260(d). Returns o.
static u8 *THISCALL fn4f61b0(u8 *self, u8 *A, u32 b, u32 c, u32 d) {
  u8 *o = (*(f4_t **)A)[0x294 / 4](A, 0x69a674, 0x699918, 0, 1);
  if (!o) return 0;
  u8 *x = (*(a3_t **)self)[0x2d8 / 4](self, o, b, 0x20002d);
  (*(v1_t **)x)[0x270 / 4](x, 0x2f);
  (*(v1_t **)o)[0x30c / 4](o, c);
  (*(v0_t **)o)[0x154 / 4](o);
  ext_4dc630(*(u32 *)(o + 8), 0x800000, 0);
  (*(v0_t **)o)[0x158 / 4](o);
  (*(v1_t **)o)[0x2ec / 4](o, 1);
  (*(v1_t **)x)[0x260 / 4](x, d);
  return o;
}
PCREG(4f61b0, fn4f61b0);
