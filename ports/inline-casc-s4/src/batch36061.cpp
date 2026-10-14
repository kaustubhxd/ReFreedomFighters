// batch36061.cpp - cascade s4 batch 36061: 0x4298b0, 0x493f20, 0x49ccc0 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v1r_t)(void *, u32);
typedef u32(THISCALL *v1ro_t)(void *, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" u8 *STDCALL ext_435eb0(u32 a);   // ret 4

// 0x4298b0, cdecl() plain ret: sys = [0x70039c]; sys[0x6d] == 0 -> return. r = 0x435eb0(0); r == 0 -> return. Three groups of flag bits in sys, selected by r[0xc], r[0xd], r[0xe]:
// r[0xc]: set (0xa10 |= 0xa0, 0x13fc |= 0xa0) with 0xad8 &= 0x7f, 0x13f7 &= 0x7f; else clear (0xa10 &= 0x5f, 0x13fc &= 0x5f, 0xad8 &= 0x7f, 0x13f7 &= 0x7f).
// r[0xd]: set (0xa15 |= 0xa0, 0x1401 |= 0xa0, 0xad8 &= 0x7f, 0x13f7 &= 0x7f); else clear (0xa15 &= 0x7f, 0x1401 &= 0x7f). r[0xe]: set (0xa1f |= 0xa0, 0x1406 |= 0xa0, 0xad8 &= 0x7f, 0x13f7 &= 0x7f); else clear (0xa1f &= 0x5f, 0x1406 &= 0x5f).
static void fn4298b0() {
  if (G(u8 *, 0x70039c)[0x6d] == 0) return;
  u8 *r = ext_435eb0(0);
  if (!r) return;
#define SYS G(u8 *, 0x70039c)
  if (r[0xc]) {
    SYS[0xa10] |= 0x80;
    SYS[0xad8] &= 0x7f;
    SYS[0xa10] |= 0x20;
    SYS[0x13fc] |= 0x80;
    SYS[0x13f7] &= 0x7f;
    SYS[0x13fc] |= 0x20;
  } else {
    SYS[0xa10] &= 0x7f;
    SYS[0xa10] &= 0xdf;
    SYS[0x13fc] &= 0x7f;
    SYS[0x13fc] &= 0xdf;
    SYS[0xad8] &= 0x7f;
    SYS[0x13f7] &= 0x7f;
  }
  if (r[0xd]) {
    SYS[0xa15] |= 0x80;
    SYS[0xad8] &= 0x7f;
    SYS[0xa15] |= 0x20;
    SYS[0x1401] |= 0x80;
    SYS[0x13f7] &= 0x7f;
    SYS[0x1401] |= 0x20;
  } else {
    SYS[0xa15] &= 0x7f;
    SYS[0x1401] &= 0x7f;
  }
  if (r[0xe]) {
    SYS[0xa1f] |= 0x80;
    SYS[0xa1f] |= 0x20;
    SYS[0xad8] &= 0x7f;
    SYS[0x1406] |= 0x80;
    SYS[0x1406] |= 0x20;
    SYS[0x13f7] &= 0x7f;
    return;
  }
  SYS[0xa1f] &= 0x7f;
  SYS[0xa1f] &= 0xdf;
  SYS[0x1406] &= 0x7f;
  SYS[0x1406] &= 0xdf;
#undef SYS
}
PCREG(4298b0, fn4298b0);

// 0x493f20, thiscall(a, flags) ret 8 (this = s): flags & 0x10: s[0xc8]->slot 1(a), flags &= ~0x10. id = 0 for a == 0; else registry g = [0x70038c]: g->slot 0x20(a) nonzero -> 0; h = g[8] and g[0xc] <= a < g[0x10] -> h(a); else a[-1] == 0 -> g->slot 0xac(a); id = a[-1].
// flags & 8: r = (s + 0xcc)->slot 1(id) (flags &= ~8); r -> *r = 0. flags &= 0x40; for each bit k of flags (loop shifting): bit set -> o = s[0x48 + 4k]; o->slot 0xf(id).
static void THISCALL fn493f20(u8 *s, u8 *a, u32 flags) {
  if (flags & 0x10) {
    u8 *o = *(u8 **)(s + 0xc8);
    (*(v1_t **)o)[4 / 4](o, (u32)a);
    flags &= 0xffffffef;
  }
  u32 id;
  if (!a) {
    id = 0;
  } else {
    u8 *g = G(u8 *, 0x70038c);
    if ((*(v1r_t **)g)[0x20 / 4](g, (u32)a)) {
      id = 0;
    } else {
      g = G(u8 *, 0x70038c);
      u8 *h = *(u8 **)(g + 8);
      if (h && !(rd(g + 0xc) > (u32)a) && (u32)a < rd(g + 0x10)) {
        id = ((u32(THISCALL *)(void *))h)(a);
      } else {
        if (rd(a - 4) == 0) (*(v1_t **)g)[0xac / 4](g, (u32)a);
        id = rd(a - 4);
      }
    }
  }
  if (flags & 8) {
    void **vt = *(void ***)(s + 0xcc);
    flags &= 0xfffffff7;
    u8 *r = ((u8 * (THISCALL *)(void *, u32))vt[1])(s + 0xcc, id);
    if (r) wr(r, 0);
  }
  flags &= 0x40;
  if (flags) {
    u8 *p = s + 0x48;
    do {
      if (flags & 1) {
        u8 *o = *(u8 **)p;
        (*(v1_t **)o)[0x3c / 4](o, id);
      }
      p += 4;
      flags >>= 1;
    } while (flags);
  }
}
PCREG(493f20, fn493f20);

extern "C" u32 THISCALL ext_49ca30(void *self, u32 i, u8 *p, u32 key, u32 slot);   // ret 0x10

// 0x49ccc0, thiscall(i, key, flag) ret 0xc returns eax (this = s): scan the packed table at s[0x1d] from word i + 1: each word w: v = w & ~7, bit1 = range flag, bit0 = end.
// no range: v == key -> found, else next word (p += 4); range: v <= key <= (p[1] & ~7) -> found, else p += 8 with end = p[1] & 1. Stop at the end flag or when found. Not found -> return 1. Found: flag == 0 -> 0; else 0x49ca30(s, i, p, key, (key & ~0xff) | last range bit) and return its result.
static u32 THISCALL fn49ccc0(u8 *s, u32 i, u32 key, u32 flag) {
  u8 *p = *(u8 **)(s + 0x1d) + i * 4 + 4;
  u8 found = 0;
  u32 keyslot = key;
  u8 endf;
  for (;;) {
    u32 w = rd(p);
    u32 v = w & 0xfffffff8u;
    endf = w & 1;
    u8 cl = (w >> 1) & 1;
    keyslot = (keyslot & 0xffffff00u) | cl;
    if (!cl) {
      if (v == key) found = 1;
      else p += 4;
    } else {
      if (!(v > key) && !(key > (rd(p + 4) & 0xfffffff8u))) {
        found = 1;
      } else {
        endf = *(p + 4) & 1;
        p += 8;
      }
    }
    if (endf) break;
    if (found) break;
  }
  if (found != 1) return 1;
  if ((u8)flag == 0) return 0;
  return ext_49ca30(s, i, p, key, keyslot);
}
PCREG(49ccc0, fn49ccc0);
