// batch35117.cpp - cascade s5 batch 35117: 0x4f5c90 (GUESS create a child through a table object and configure it).
#include "ff.h"

extern "C" void THISCALL ext_4de7a0(u8 *self);   // constructor of a 0x24-byte local, plain ret
typedef u8 *(THISCALL *e1_t)(void *, u32);
typedef u8 *(THISCALL *c7_t)(void *, u32, u8 *, u32 *, u32, u32, u32, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);

// 0x4f5c90, thiscall(a, b, c, d) ret 0x10, returns the child or 0. id = d == 0 ? [this+0x6c] : [this+0x70]; o = [engine+0x9b] slot 0x58(id); null gives 0. Otherwise l12 = {0, 0, 0}, l34 built by 0x4de7a0 and
// r = o slot 0x1bc(a, l34, l12, 0, 0, 0, 0); r slot 0x278(b, c); returns r.
static u8 *THISCALL fn4f5c90(u8 *self, u32 a, u32 b, u32 c, u32 d) {
  u8 l34[0x24];
  u32 l12[3];
  u32 id = d == 0 ? *(u32 *)(self + 0x6c) : *(u32 *)(self + 0x70);
  u8 *eng = G(u8 *, 0x70039c);
  u8 *tab = *(u8 **)(eng + 0x9b);
  u8 *o = (*(e1_t **)tab)[0x58 / 4](tab, id);
  if (!o) return 0;
  l12[0] = l12[1] = l12[2] = 0;
  ext_4de7a0(l34);
  u8 *r = (*(c7_t **)o)[0x1bc / 4](o, a, l34, l12, 0, 0, 0, 0);
  (*(v2_t **)r)[0x278 / 4](r, b, c);
  return r;
}
PCREG(4f5c90, fn4f5c90);
