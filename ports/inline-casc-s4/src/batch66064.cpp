// batch66064.cpp - cascade s4 batch 66064: 0x51f600 (tier F row).
#include "ff.h"

typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);
typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" void THISCALL ext_5175a0(void *self);              // plain ret
extern "C" u32 THISCALL ext_4dc110(void *self);               // plain ret
extern "C" u32 FASTCALL ext_4cc850(u32 name, u32 pattern);    // fastcall wildcard match, 0 = match
extern "C" void THISCALL ext_4db670(void *self, u32 a);       // ret 4
extern "C" void FASTCALL ext_4ddfa0(u32 dst, u32 src);        // fastcall plain ret

// 0x51f600, thiscall() plain ret (this = t): 0x5175a0(t); for each child c of t[0x50] (next +0x60) whose name 0x4dc110(c) matches the pattern 0x69f938 (0x4cc850 == 0): found = true; t[0x1660..0x1668] = 0; 0x4db670(c, t + 0x1660); t->slot 0x23 (0x8c)(t + 0x1660).
// Not found: log (0x71, 0x69fed8): 0x69ff20 with t[4] (or 0x67c8e8), and t[0x1660..0x1668] = 0. Then s = t + 0x166c = {t[0x6c], t[0x70], t[0x74]}; 0x4ddfa0(s, t + 0x78); t->slot 0x24 (0x90)(s); t[0x1678..] = s; t[0x1684]->slot 1 (4)(s, t + 0x1678).
static void THISCALL fn51f600(u8 *t) {
  ext_5175a0(t);
  u8 *c = *(u8 **)(t + 0x50);
  bool found = false;
  while (c) {
    u32 name = ext_4dc110(c);
    if (ext_4cc850(name, 0x69f938) == 0) {
      u8 *r = t + 0x1660;
      found = true;
      wr(r, 0);
      wr(r + 4, 0);
      wr(r + 8, 0);
      ext_4db670(c, (u32)r);
      (*(v1_t **)t)[0x8c / 4](t, (u32)r);
    }
    c = *(u8 **)(c + 0x60);
  }
  if (!found) {
    u8 *db = G(u8 *, 0x700390);
    u8 *lo = (*(v2o_t **)db)[0x20 / 4](db, 0x69fed8u, 0x71u);
    u32 nm = rd(t + 4) ? rd(t + 4) : 0x67c8e8u;
    void *fn = *(void **)((u8 *)*(void ***)lo + 0x2c);
    ((void (*)(u8 *, u32, u32))fn)(lo, 0x69ff20u, nm);
    wr(t + 0x1660, 0);
    wr(t + 0x1664, 0);
    wr(t + 0x1668, 0);
  }
  u8 *sp = t + 0x166c;
  wr(sp, rd(t + 0x6c));
  wr(sp + 4, rd(t + 0x70));
  wr(sp + 8, rd(t + 0x74));
  ext_4ddfa0((u32)sp, (u32)(t + 0x78));
  (*(v1_t **)t)[0x90 / 4](t, (u32)sp);
  u8 *q = t + 0x1678;
  wr(q, rd(sp));
  wr(q + 4, rd(sp + 4));
  wr(q + 8, rd(sp + 8));
  u8 *emb = t + 0x1684;
  (*(v2_t **)emb)[4 / 4](emb, (u32)sp, (u32)q);
}
PCREG(51f600, fn51f600);
