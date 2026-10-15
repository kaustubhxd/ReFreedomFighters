// batch66067.cpp - cascade s4 batch 66067: 0x456d10 (tier F row).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef u32(THISCALL *v1r_t)(void *, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" void THISCALL ext_45f3c0(void *self, void *s);   // ret 4

// 0x456d10, thiscall(s) ret 4, returns al = 1 (this = t): 0x45f3c0(t, s); s->slot 0x10 (0x40)(&n); for i < n (unsigned): s->slot 0x10(t + 0x1d + 8 * i); t[0x21 + 8 * i] = 0.
// Then for up to 0x100 table entries at t + 0x1d (id, idx): id == 0 -> done. idx != 0: p = t[0x81d] + (idx - 1) * 0x94c; p != 0: o = sys[0x9b]->slot 0x58(id); while p: p[0x944] = o[0xdd]; p[0x948] = o + 0x5d; next idx = p[0], p = t[0x81d] + (idx - 1) * 0x94c, stop when idx or p is 0.
// Finally sys[0x9b][0x18] = sys[0x9b]->slot 0x13 (0x4c)(t).
static u8 THISCALL fn456d10(u8 *t, u8 *s) {
  ext_45f3c0(t, s);
  u32 n;
  (*(v1_t **)s)[0x40 / 4](s, (u32)&n);
  for (u32 i = 0; i < n; i++) {
    (*(v1_t **)s)[0x40 / 4](s, (u32)(t + 0x1d + 8 * i));
    wr(t + 0x21 + 8 * i, 0);
  }
  u8 *cur = t + 0x1d;
  for (u32 i = 0; i < 0x100; i++, cur += 8) {
    u32 id = rd(cur);
    if (!id) break;
    u32 idx = rd(cur + 4);
    if (!idx) continue;
    u8 *p = *(u8 **)(t + 0x81d) + idx * 0x94c - 0x94c;
    if (!p) continue;
    u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u8 *o = (*(v1o_t **)tab)[0x58 / 4](tab, id);
    for (;;) {
      wr(p + 0x944, rd(o + 0xdd));
      wr(p + 0x948, (u32)(o + 0x5d));
      u32 nx = rd(p);
      if (!nx) break;
      p = *(u8 **)(t + 0x81d) + nx * 0x94c - 0x94c;
      if (!p) break;
    }
  }
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 h = (*(v1r_t **)tab)[0x4c / 4](tab, (u32)t);
  wr(*(u8 **)(G(u8 *, 0x70039c) + 0x9b) + 0x18, h);
  return 1;
}
PCREG(456d10, fn456d10);
