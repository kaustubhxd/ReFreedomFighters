// batch66024.cpp - cascade s4 batch 66024: 0x471540 (tier F row).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef void(THISCALL *v3_t)(void *, u32, u32, u32);
typedef u8 *(THISCALL *v1o_t)(void *, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }

extern "C" void THISCALL ext_4dc630(void *self, u32 a, u32 b);   // ret 8

// 0x471540, thiscall(a) ret 4 (this = t): a->slot 0x22 (0x88)(0x68884c, &key); l = t[0x70]; l == 0 -> return. l->slot 0x4c(&it); for e = l->slot 0x19 (0x64)(&it) while e (re-reading t[0x70] each time):
// e[0] == key: o = sys[0x9b]->slot 0x58(e[4]); o == 0 -> t[0x70]->slot 0x11 (0x44)(&it) (remove the entry). Otherwise n = o->slot 0x40 (0x100)(0x688854); ctx = o[8]; f = ctx[0x3c] & 0x800000;
// 0x4dc630(ctx, 0x800000, 0); n set -> n->slot 0x17 (0x5c)(0x20, a, (u16)t[0x76]); 0x4dc630(o[8], f, 0x800000).
static void THISCALL fn471540(u8 *t, u8 *a) {
  u32 key;
  u32 it[4];
  (*(v2_t **)a)[0x88 / 4](a, 0x68884cu, (u32)&key);
  u8 *l = *(u8 **)(t + 0x70);
  if (!l) return;
  (*(v1_t **)l)[0x4c / 4](l, (u32)it);
  l = *(u8 **)(t + 0x70);
  u8 *e = (*(v1o_t **)l)[0x64 / 4](l, (u32)it);
  if (!e) return;
  do {
    if (key == rd(e)) {
      u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
      u8 *o = (*(v1o_t **)tab)[0x58 / 4](tab, rd(e + 4));
      if (!o) {
        l = *(u8 **)(t + 0x70);
        (*(v1_t **)l)[0x44 / 4](l, (u32)it);
      } else {
        u8 *n = (*(v1o_t **)o)[0x100 / 4](o, 0x688854u);
        u8 *ctx = *(u8 **)(o + 8);
        u32 f = rd(ctx + 0x3c) & 0x800000;
        ext_4dc630(ctx, 0x800000, 0);
        if (n) (*(v3_t **)n)[0x5c / 4](n, 0x20, (u32)a, *(u16 *)(t + 0x76));
        ctx = *(u8 **)(o + 8);
        ext_4dc630(ctx, f, 0x800000);
      }
    }
    l = *(u8 **)(t + 0x70);
    e = (*(v1o_t **)l)[0x64 / 4](l, (u32)it);
  } while (e);
}
PCREG(471540, fn471540);
