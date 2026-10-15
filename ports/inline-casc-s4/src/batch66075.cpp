// batch66075.cpp - cascade s4 batch 66075: 0x5db2e0 (tier F row).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef u32(THISCALL *v1r_t)(void *, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" void THISCALL ext_4daf90(void *self, void *out);   // ret 4
extern "C" u8 *ext_41e290(u32 n);                              // cdecl

// 0x5db2e0, thiscall() plain ret (this = t): l = t[0x48][0x18]; l == 0 -> done. l->slot 0x13 (0x4c)(&it); for e = t[0x48][0x18]->slot 0x17 (0x5c)(&it) while it[0] (re-reading t[0x48][0x18]): o = sys[0x9b]->slot 0x58(e); o[0x54] set ->
// 0x4daf90(o[8], &loc (12 bytes)); o->slot 0x21 (0x84)(&loc); n = alloc(13); n[9] = 0; n[0] = e; n[4] = sys[0x9b]->slot 0x58(e); n[8] = (o->slot 0x78 (0x1e0)(0x2003e8) (al) != 0); t[0x84]->slot 1 (4)(n).
static void THISCALL fn5db2e0(u8 *t) {
  u8 *l = *(u8 **)(*(u8 **)(t + 0x48) + 0x18);
  if (!l) return;
  u32 it[4];
  (*(v1_t **)l)[0x4c / 4](l, (u32)it);
  l = *(u8 **)(*(u8 **)(t + 0x48) + 0x18);
  u32 e = (*(v1r_t **)l)[0x5c / 4](l, (u32)it);
  if (it[0] == 0) return;
  do {
    u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u8 *o = (*(v1o_t **)tab)[0x58 / 4](tab, e);
    if (rd(o + 0x54)) {
      u32 loc[3];
      ext_4daf90(*(u8 **)(o + 8), loc);
      (*(v1_t **)o)[0x84 / 4](o, (u32)loc);
      u8 *n = ext_41e290(0xd);
      wr(n + 9, 0);
      wr(n, e);
      tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
      wr(n + 4, (u32)(*(v1o_t **)tab)[0x58 / 4](tab, e));
      u8 f = (u8)(*(v1r_t **)o)[0x1e0 / 4](o, 0x2003e8u) != 0;
      n[8] = f;
      u8 *w = *(u8 **)(t + 0x84);
      (*(v1_t **)w)[4 / 4](w, (u32)n);
    }
    l = *(u8 **)(*(u8 **)(t + 0x48) + 0x18);
    e = (*(v1r_t **)l)[0x5c / 4](l, (u32)it);
  } while (it[0] != 0);
}
PCREG(5db2e0, fn5db2e0);
