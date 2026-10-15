// batch66021.cpp - cascade s4 batch 66021: 0x5cbe30 (tier F row).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

static u8 *lookup(u32 id) {
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  return (*(v1o_t **)tab)[0x58 / 4](tab, id);
}

static void add_obj(u8 *t, u8 *p) {
  if (p) {
    wr(t + 0x5b0 + rd(t + 0x5ac) * 4, (u32)p);
    wr(t + 0x5ac, rd(t + 0x5ac) + 1);
  }
}

// 0x5cbe30, thiscall() plain ret (this = t): g = [0x7003b8]; t[0x5ac] = g[0x41c]; copy g[0x41c] dwords (signed count, none when <= 0) from g + 0x420 to t + 0x5b0.
// s = sys[0x9b][0xadc]->slot 0x97 (0x25c)(0x6b4d1c, 0); s and s[0x18] set: iterate s[0x18] (slot 0x4c(&it), e = slot 0x5c(&it) while it[0]): lookup(e) non-null -> appended to the t[0x5b0] array (count t[0x5ac]).
// Then lookup(t[0x368]) appended when non-null. t[0x7b1] = t + 0x5b0; t[0x7b5] = t[0x5b0].
static void THISCALL fn5cbe30(u8 *t) {
  u8 *g = G(u8 *, 0x7003b8);
  wr(t + 0x5ac, rd(g + 0x41c));
  s32 n = (s32)rd(g + 0x41c);
  u8 *d = t + 0x5b0;
  if (n > 0) {
    u8 *src = g + 0x420;
    do {
      wr(d, rd(src));
      src += 4;
      d += 4;
      n--;
    } while (n > 0);
  }
  u8 *m = *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x9b) + 0xadc);
  u8 *s = (*(v2o_t **)m)[0x25c / 4](m, 0x6b4d1cu, 0);
  if (s && rd(s + 0x18)) {
    u32 it[3];
    u8 *l = *(u8 **)(s + 0x18);
    (*(v1_t **)l)[0x4c / 4](l, (u32)it);
    l = *(u8 **)(s + 0x18);
    u8 *e = (*(v1o_t **)l)[0x5c / 4](l, (u32)it);
    if (it[0]) {
      do {
        add_obj(t, lookup((u32)e));
        l = *(u8 **)(s + 0x18);
        e = (*(v1o_t **)l)[0x5c / 4](l, (u32)it);
      } while (it[0]);
    }
  }
  add_obj(t, lookup(rd(t + 0x368)));
  wr(t + 0x7b1, (u32)(t + 0x5b0));
  wr(t + 0x7b5, rd(t + 0x5b0));
}
PCREG(5cbe30, fn5cbe30);
