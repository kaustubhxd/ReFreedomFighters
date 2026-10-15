// batch66036.cpp - cascade s4 batch 66036: 0x470a00 (tier F row).
#include "ff.h"

typedef u8 *(THISCALL *v0o_t)(void *);
typedef u32(THISCALL *v0r_t)(void *);
typedef u32(THISCALL *v1r_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef u32(THISCALL *v5r_t)(void *, u32, u32, u32, u32, u32);

// 0x470a00, thiscall() returns al (this = t): a = t->slot 0xd4 (0x350)(); a->slot 0xcb (0x32c)() (al) == 0 -> 1. x = t->slot 0xbd (0x2f4)() == 0 -> 1.
// t->slot 0xbd()->slot 0x78 (0x1e0)(0x200074) (al) set and t->slot 0xbd()->slot 0x108 (0x420)() == 1 -> 1. t->slot 0xd5 (0x354)() (al) == 0 -> 0.
// Otherwise id = 0; sys[0x9b]->slot 0x4e (0x138)()->slot 0x22 (0x88)(0x688d74, &id); flag = 1; h = (u16) sys[0x9b]->slot 0x45 (0x114)(0x688d8c, 0, 0x6887c4, 0xcb6, &flag); t->slot 0x4b (0x12c)(id, h); return flag.
static u8 THISCALL fn470a00(u8 *t) {
  u8 *a = (*(v0o_t **)t)[0x350 / 4](t);
  if (!(u8)(*(v0r_t **)a)[0x32c / 4](a)) return 1;
  if (!(*(v0r_t **)t)[0x2f4 / 4](t)) return 1;
  u8 *x = (*(v0o_t **)t)[0x2f4 / 4](t);
  if ((u8)(*(v1r_t **)x)[0x1e0 / 4](x, 0x200074u)) {
    u8 *y = (*(v0o_t **)t)[0x2f4 / 4](t);
    if ((*(v0r_t **)y)[0x420 / 4](y) == 1) return 1;
  }
  void **vt = *(void ***)t;
  if (!(u8)((v0r_t)vt[0x354 / 4])(t)) return 0;
  u32 id = 0;
  u8 flag;
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *o = (*(v0o_t **)tab)[0x138 / 4](tab);
  (*(v2_t **)o)[0x88 / 4](o, 0x688d74u, (u32)&id);
  vt = *(void ***)t;
  flag = 1;
  tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 h = (u16)(*(v5r_t **)tab)[0x114 / 4](tab, 0x688d8cu, 0, 0x6887c4u, 0xcb6u, (u32)&flag);
  ((void (THISCALL *)(void *, u32, u32))vt[0x12c / 4])(t, id, h);
  return flag;
}
PCREG(470a00, fn470a00);
