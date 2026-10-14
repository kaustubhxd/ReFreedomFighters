// batch35105.cpp - cascade s5 batch 35105: 0x46d530 (GUESS create a child object through a factory and initialise it).
#include "ff.h"

extern "C" void THISCALL ext_4dc630(u32 self, u32 a, u32 b);   // thiscall, ret 8
typedef u32(THISCALL *g0_t)(void *);
typedef u8 *(THISCALL *e2_t)(void *, u32, u32);
typedef u8 *(THISCALL *f5_t)(void *, u32, u32, u32, u32, u32);
typedef u32(THISCALL *g1_t)(void *, u32);
typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v0_t)(void *);

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x46d530, thiscall(A, B) ret 8, returns the new object or 0. id = this slot 0x2c8(); r = [engine+0x9b] slot 0x154(id, 0); name = [this+4] or the default 0x67c8e8; o = A slot 0x298(name, B, unaligned dword [r+0x23], 0, 1) (ECX = A);
// null gives 0. Then o slot 0x2e4(table slot 0x4c(this)) (the vtable slot read first), o slot 0x154(), 0x4dc630([o+8], 0x800000, 0), o slot 0x158(); returns o.
static u8 *THISCALL fn46d530(u8 *self, u8 *A, u32 B) {
  u32 id = (*(g0_t **)self)[0x2c8 / 4](self);
  u8 *eng = G(u8 *, 0x70039c);
  u8 *tab = *(u8 **)(eng + 0x9b);
  u8 *r = (*(e2_t **)tab)[0x154 / 4](tab, id, 0);
  u32 name = *(u32 *)(self + 4) ? *(u32 *)(self + 4) : 0x67c8e8;
  u8 *o = (*(f5_t **)A)[0x298 / 4](A, name, B, rd32u(r + 0x23), 0, 1);
  if (!o) return 0;
  eng = G(u8 *, 0x70039c);
  tab = *(u8 **)(eng + 0x9b);
  u32 f = (*(u32 **)o)[0x2e4 / 4];
  u32 k = (*(g1_t **)tab)[0x4c / 4](tab, (u32)self);
  ((v1_t)f)(o, k);
  (*(v0_t **)o)[0x154 / 4](o);
  ext_4dc630(*(u32 *)(o + 8), 0x800000, 0);
  (*(v0_t **)o)[0x158 / 4](o);
  return o;
}
PCREG(46d530, fn46d530);
