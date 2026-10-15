// batch66079.cpp - cascade s4 batch 66079: 0x4f2a30 (tier F row from the queue, redone by Sonnet).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v1r_t)(void *, u32);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef void(THISCALL *v4_t)(void *, u32, u32, u32, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }

// 0x4f2a30, thiscall(a) ret 4 (this = t, s = embedded list object at t + 0xcb): ebx = 0; s->slot 0x15 (0x54)(&it); ebx = s->slot 0x1b (0x6c)(&it); while it[0]: o = sys[0x9b]->slot 0x58(ebx): found -> h = sys[0x9b]->slot 0x4c(a); t->slot 0xb7 (0x2dc)(0x200, h, 0, o), stop;
// otherwise s->slot 0x11 (0x44)(&it) (remove) and ebx = s->slot 0x1b(&it).
// Then: h2 = sys[0x9b]->slot 0x4c(a); s->vtable slot 1 (4)(h2); t->slot 0xb7 (0x2dc)(0x100, ebx, 1, a); t[0x63b] = 1.
static void THISCALL fn4f2a30(u8 *t, u32 a) {
  u32 it[4];
  u8 *s = t + 0xcb;
  u32 ebx = 0;
  (*(v1_t **)s)[0x54 / 4](s, (u32)it);
  ebx = (*(v1r_t **)s)[0x6c / 4](s, (u32)it);
  if (it[0] != 0) {
    do {
      u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
      u8 *o = (*(v1o_t **)tab)[0x58 / 4](tab, ebx);
      if (o) {
        tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
        u32 h = (*(v1r_t **)tab)[0x4c / 4](tab, a);
        (*(v4_t **)t)[0x2dc / 4](t, 0x200, h, 0, (u32)o);
        break;
      }
      (*(v1_t **)s)[0x44 / 4](s, (u32)it);
      ebx = (*(v1r_t **)s)[0x6c / 4](s, (u32)it);
    } while (it[0] != 0);
  }
  void **vt = *(void ***)s;
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 h2 = (*(v1r_t **)tab)[0x4c / 4](tab, a);
  ((v1_t)vt[4 / 4])(s, h2);
  (*(v4_t **)t)[0x2dc / 4](t, 0x100, ebx, 1, a);
  t[0x63b] = 1;
}
PCREG(4f2a30, fn4f2a30);
