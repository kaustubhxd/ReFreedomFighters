// batch66071.cpp - cascade s4 batch 66071: 0x56f440 (tier F row).
#include "ff.h"

typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);
typedef u8 *(THISCALL *v0o_t)(void *);
typedef u32(THISCALL *v1r_t)(void *, u32);
typedef void(THISCALL *v0_t)(void *);
typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }
static inline u8 *pp(u8 *t, u32 off) { return *(u8 **)(t + off); }

extern "C" void THISCALL ext_5613a0(void *self, u32 a, u32 b);   // ret 8

// 0x56f440, thiscall() plain ret (this = t): t[0x188] = t[0x18c] = 0. m = t[0x5d6] set: p = m->slot 0x97 (0x25c)(0x6a84ec, 0); p set: for each child c of p[0x50] (next +0x60) while the flags of c[0x54][0xc][0x23] (0x200002 without c[0x54]) have 0x100000:
// c[0x54]->slot 0x78 (0x1e0)(0x100033) (al) and t[0x188] < 0x40 -> t[0x4ca + 4 * t[0x188]++] = c[0x54]. Then id = 0; sys[0x9b]->slot 0x4e (0x138)()->slot 0x22 (0x88)(0x6a7a40, &id); t[0x1c1] = id; 0x5613a0(t, t[0x19d], t[0x1a5]); 0x5613a0(t, t[0x19d], t[0x1c5]);
// t[0x4be]->slot 0xc7 (0x31c)(t[0x5e2], 3); t[0x5ce]->slot 10 (0x28)(); t[0x5da]->slot 10(); t[0x5ca]->slot 10(); t[0x5e2]->slot 0xdc (0x370)(t[0x184] - 8).
static void THISCALL fn56f440(u8 *t) {
  wr(t + 0x188, 0);
  wr(t + 0x18c, 0);
  u8 *m = pp(t, 0x5d6);
  if (m) {
    u8 *p = (*(v2o_t **)m)[0x25c / 4](m, 0x6a84ecu, 0);
    if (p) {
      u8 *c = *(u8 **)(p + 0x50);
      while (c) {
        u8 *w = *(u8 **)(c + 0x54);
        u32 flags = w ? rd(*(u8 **)(w + 0xc) + 0x23) : 0x200002;
        if (!(flags & 0x100000)) break;
        if ((u8)(*(v1r_t **)w)[0x1e0 / 4](w, 0x100033u)) {
          s32 cnt = (s32)rd(t + 0x188);
          if (cnt < 0x40) {
            wr(t + 0x4ca + cnt * 4, rd(c + 0x54));
            wr(t + 0x188, rd(t + 0x188) + 1);
          }
        }
        c = *(u8 **)(c + 0x60);
      }
    }
  }
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *o = (*(v0o_t **)tab)[0x138 / 4](tab);
  u32 id = 0;
  (*(v2_t **)o)[0x88 / 4](o, 0x6a7a40u, (u32)&id);
  wr(t + 0x1c1, id);
  ext_5613a0(t, rd(t + 0x19d), rd(t + 0x1a5));
  ext_5613a0(t, rd(t + 0x19d), rd(t + 0x1c5));
  u8 *a = pp(t, 0x4be);
  (*(v2_t **)a)[0x31c / 4](a, rd(t + 0x5e2), 3);
  u8 *b = pp(t, 0x5ce);
  (*(v0_t **)b)[0x28 / 4](b);
  b = pp(t, 0x5da);
  (*(v0_t **)b)[0x28 / 4](b);
  b = pp(t, 0x5ca);
  (*(v0_t **)b)[0x28 / 4](b);
  u8 *z = pp(t, 0x5e2);
  (*(v1_t **)z)[0x370 / 4](z, rd(t + 0x184) - 8);
}
PCREG(56f440, fn56f440);
