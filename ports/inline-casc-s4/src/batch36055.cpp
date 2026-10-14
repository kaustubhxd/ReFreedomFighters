// batch36055.cpp - cascade s4 batch 36055: 0x4c7bb0 (tier F row).
#include "ff.h"

typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef void(THISCALL *v4_t)(void *, u32, u32, u32, u32);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef u32(THISCALL *v1r_t)(void *, u32);
typedef u32(THISCALL *v5r_t)(void *, u32, u32, u32, u32, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }

// 0x4c7bb0, cdecl() plain ret: id = sys[0x190f]->slot 0xb4(0); o = sys[0x9b]->slot 0x58(id); id and o: o->slot 0x28c(&B, 1, 7, 0) (B: 5 dwords, B[3] read back); B[3] == 0 -> return.
// x = tab->slot 0x58(B[3]); x and (u8)x->slot 0x1e0(0x2007d0): w = 0x69212c; ax = (u16)tab->slot 0x114(0x694c6c, 0, 0x694ad8, 0x2d9, &w); x->slot 0x130(x, ax).
static void fn4c7bb0() {
  u32 B[5];
  u8 *sys = G(u8 *, 0x70039c);
  u8 *mgr = *(u8 **)(sys + 0x190f);
  u32 id = (*(v1r_t **)mgr)[0xb4 / 4](mgr, 0);
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *o = (*(v1o_t **)tab)[0x58 / 4](tab, id);
  if (id == 0 || !o) return;
  (*(v4_t **)o)[0x28c / 4](o, (u32)B, 1, 7, 0);
  if (B[3] == 0) return;
  tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *x = (*(v1o_t **)tab)[0x58 / 4](tab, B[3]);
  if (!x) return;
  if (!(u8)(*(v1r_t **)x)[0x1e0 / 4](x, 0x2007d0u)) return;
  u32 w = 0x69212c;
  void **vt = *(void ***)x;
  tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 ax = (u16)(*(v5r_t **)tab)[0x114 / 4](tab, 0x694c6cu, 0, 0x694ad8u, 0x2d9u, (u32)&w);
  ((v2_t)vt[0x130 / 4])(x, (u32)x, ax);
}
PCREG(4c7bb0, fn4c7bb0);
