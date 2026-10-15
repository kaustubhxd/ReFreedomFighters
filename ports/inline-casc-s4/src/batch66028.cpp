// batch66028.cpp - cascade s4 batch 66028: 0x50c360 (tier F row).
#include "ff.h"

typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef u8 *(THISCALL *v0o_t)(void *);
typedef u32(THISCALL *v0r_t)(void *);
typedef void(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v1r_t)(void *, u32);
typedef u8(THISCALL *v1b_t)(void *, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" u8 *THISCALL ext_5003d0(void *self, u32 i);   // ret 4

static u8 *logobj(u32 line) {
  u8 *db = G(u8 *, 0x700390);
  return (*(v2o_t **)db)[0x20 / 4](db, 0x69d420u, line);
}

// 0x50c360, stdcall(p) ret 4, returns the result of s->slot 10 (0x28): s = p[0xc]->slot 0 (0x67a14c, 0); id = *0x5003d0(p[4], 0); o = sys[0x9b]->slot 0x58(id).
// o: o->slot 0x78 (0x1e0)(0x1007d1) (al) set -> s->slot 0xc (0x30)(o->slot 0xba (0x2e8)()[4]); else log (0x69d420, 0x15b) 0x69d650 with o[4]. No o: log (0x69d420, 0x15e) 0x69d698.
// r = 0x5003d0(p[8], 0): tag r[4]: 0 -> skip; 4 -> (*r)->slot 10 (0x28)(); other -> skip the assignment. Assignment: r[0] = s->slot 9 (0x24)(), r[4] = 4. Finally s->slot 10 (0x28)().
static u32 STDCALL fn50c360(u8 *p) {
  u8 *m = *(u8 **)(p + 0xc);
  u8 *s = (*(v2o_t **)m)[0](m, 0x67a14cu, 0);
  u8 *rec = ext_5003d0(*(u8 **)(p + 4), 0);
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *o = (*(v1o_t **)tab)[0x58 / 4](tab, rd(rec));
  if (o) {
    if ((u8)(*(v1b_t **)o)[0x1e0 / 4](o, 0x1007d1u)) {
      u8 *q = (*(v0o_t **)o)[0x2e8 / 4](o);
      (*(v1_t **)s)[0x30 / 4](s, rd(q + 4));
    } else {
      u8 *lo = logobj(0x15b);
      void *fn = *(void **)((u8 *)*(void ***)lo + 0x2c);
      ((void (*)(u8 *, u32, u32))fn)(lo, 0x69d650u, rd(o + 4));
    }
  } else {
    u8 *lo = logobj(0x15e);
    void *fn = *(void **)((u8 *)*(void ***)lo + 0x2c);
    ((void (*)(u8 *, u32))fn)(lo, 0x69d698u);
  }
  u8 *r2 = ext_5003d0(*(u8 **)(p + 8), 0);
  u8 tag = r2[4];
  bool assign = true;
  if (tag) {
    if (tag != 4) {
      assign = false;
    } else {
      u8 *old = *(u8 **)r2;
      (*(void (THISCALL ***)(void *))old)[0x28 / 4](old);
    }
  }
  if (assign) {
    wr(r2, (*(v0r_t **)s)[0x24 / 4](s));
    r2[4] = 4;
  }
  return (*(v0r_t **)s)[0x28 / 4](s);
}
PCREG(50c360, fn50c360);
