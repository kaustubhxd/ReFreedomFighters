// batch36025.cpp - cascade s4 batch 36025: 0x4c2360, 0x46d810, 0x4c23f0, 0x4ca620, 0x4fa510 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v3_t)(void *, u32, u32, u32);
typedef void(THISCALL *v5_t)(void *, u32, u32, u32, u32, u32);
typedef u32(THISCALL *v1u_t)(void *, u32);
typedef u8 *(THISCALL *v0o_t)(void *);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }
static inline u8 *tabOf() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }
static inline void rdSlot(u8 *s, u32 slot, u8 *dst) { (*(v1_t **)s)[slot / 4](s, (u32)dst); }

// 0x4c2360, thiscall(s) ret 4, returns 1 (this = E): E[4] &= ~0x40; s slots (value read into E+off): 0x44 -> 0x48, 0x4a; 0x68 -> 0x4c, 0x4d; 0x50 -> 0x4e, 0x52, 0x56, 0x5a; 0x48 -> 0x5e; 0x50 -> 0x62, 0x66.
static u8 THISCALL fn4c2360(u8 *E, u8 *s) {
  wr(E + 4, rd(E + 4) & 0xffffffbfu);
  rdSlot(s, 0x44, E + 0x48);
  rdSlot(s, 0x44, E + 0x4a);
  rdSlot(s, 0x68, E + 0x4c);
  rdSlot(s, 0x68, E + 0x4d);
  rdSlot(s, 0x50, E + 0x4e);
  rdSlot(s, 0x50, E + 0x52);
  rdSlot(s, 0x50, E + 0x56);
  rdSlot(s, 0x50, E + 0x5a);
  rdSlot(s, 0x48, E + 0x5e);
  rdSlot(s, 0x50, E + 0x62);
  rdSlot(s, 0x50, E + 0x66);
  return 1;
}
PCREG(4c2360, fn4c2360);

// 0x4c23f0, thiscall(s) ret 4, returns 1: same as 0x4c2360 but slot 0x50 for every dword field from +0x4e to +0x66 (7 fields).
static u8 THISCALL fn4c23f0(u8 *E, u8 *s) {
  wr(E + 4, rd(E + 4) & 0xffffffbfu);
  rdSlot(s, 0x44, E + 0x48);
  rdSlot(s, 0x44, E + 0x4a);
  rdSlot(s, 0x68, E + 0x4c);
  rdSlot(s, 0x68, E + 0x4d);
  static const u8 offs[7] = {0x4e, 0x52, 0x56, 0x5a, 0x5e, 0x62, 0x66};
  for (int i = 0; i < 7; i++) rdSlot(s, 0x50, E + offs[i]);
  return 1;
}
PCREG(4c23f0, fn4c23f0);

// 0x4ca620, thiscall(s) ret 4, returns 1: E[4] &= ~0x40; slot 0x6c -> +0x48, +0x54, +0x60, +0x6c, +0x78, +0x84, +0x90; slot 0x68 -> +0x9c; slot 0x40 -> +0x9d; slot 0x6c -> +0xa1, +0xad.
static u8 THISCALL fn4ca620(u8 *E, u8 *s) {
  wr(E + 4, rd(E + 4) & 0xffffffbfu);
  static const u16 offs[7] = {0x48, 0x54, 0x60, 0x6c, 0x78, 0x84, 0x90};
  for (int i = 0; i < 7; i++) rdSlot(s, 0x6c, E + offs[i]);
  rdSlot(s, 0x68, E + 0x9c);
  rdSlot(s, 0x40, E + 0x9d);
  rdSlot(s, 0x6c, E + 0xa1);
  rdSlot(s, 0x6c, E + 0xad);
  return 1;
}
PCREG(4ca620, fn4ca620);

extern "C" u32 FASTCALL ext_4cc850(u32 a, u32 b);  // wildcard match (ecx, edx); 0 = match

// 0x46d810, thiscall(sink, key, name) ret 0xc (this = E): c = E[0x70] null returns; c->slot 0x4c(&loc); r = c->slot 0x64(&loc); for each r (until null): r[0] == key:
// o = tab->slot 0x58(r[4]); null: E[0x70]->slot 0x44(&loc); else name == 0 or 0x4cc850(o[4] ? o[4] : 0x67c8e8, name) == 0: sink->slot 4(r[4]). Next r = E[0x70]->slot 0x64(&loc).
static void THISCALL fn46d810(u8 *E, u8 *sink, u32 key, u32 name) {
  u32 loc[3];
  u8 *c = *(u8 **)(E + 0x70);
  if (!c) return;
  (*(v1_t **)c)[0x4c / 4](c, (u32)loc);
  c = *(u8 **)(E + 0x70);
  u8 *r = (*(v1o_t **)c)[0x64 / 4](c, (u32)loc);
  if (!r) return;
  do {
    if (key == rd(r)) {
      u8 *tab = tabOf();
      u8 *o = (*(v1o_t **)tab)[0x58 / 4](tab, rd(r + 4));
      if (!o) {
        c = *(u8 **)(E + 0x70);
        (*(v1_t **)c)[0x44 / 4](c, (u32)loc);
      } else {
        bool hit;
        if (name == 0) {
          hit = true;
        } else {
          u32 nm = rd(o + 4);
          hit = ext_4cc850(nm ? nm : 0x67c8e8u, name) == 0;
        }
        if (hit) (*(v1_t **)sink)[4 / 4](sink, rd(r + 4));
      }
    }
    c = *(u8 **)(E + 0x70);
    r = (*(v1o_t **)c)[0x64 / 4](c, (u32)loc);
  } while (r);
}
PCREG(46d810, fn46d810);

// 0x4fa510, thiscall(a, b) ret 8, returns bool (this = E): a != E[0x9b] returns 0. Logs (0x69bdd0, 0x2d8, 0x69bdf8, b); x = E->slot 0x2c4(); x->slot 0x308(E+0x9f); E->slot 0x2c4()->slot 0x350(2, 0, E);
// b == 2: E[0xb3] = 1 and E->slot 0x2c4()->slot 0x34c(2, 0, E, 0, 1); else E[0xb3] = 0; returns 1.
static u8 THISCALL fn4fa510(u8 *E, u32 a, u32 b) {
  if (a != rd(E + 0x9b)) return 0;
  u8 *db = G(u8 *, 0x700390);
  u8 *o = (*(v2o_t **)db)[0x20 / 4](db, 0x69bdd0u, 0x2d8u);
  void **vt2 = *(void ***)o;
  void *fn = *(void **)((u8 *)vt2 + 0x2c);
  __asm__ volatile("pushl %[b]\n\tpushl $0x69bdf8\n\tpushl %[o]\n\tcall *%[f]\n\taddl $12, %%esp"
                   : "+c"(vt2) : [b] "r"(b), [o] "r"(o), [f] "r"(fn) : "eax", "edx", "memory", "cc");
  u8 *x = (*(v0o_t **)E)[0x2c4 / 4](E);
  (*(v1_t **)x)[0x308 / 4](x, (u32)(E + 0x9f));
  u8 *y = (*(v0o_t **)E)[0x2c4 / 4](E);
  (*(v3_t **)y)[0x350 / 4](y, 2, 0, (u32)E);
  if (b == 2) {
    E[0xb3] = 1;
    u8 *z = (*(v0o_t **)E)[0x2c4 / 4](E);
    (*(v5_t **)z)[0x34c / 4](z, 2, 0, (u32)E, 0, 1);
    return 1;
  }
  E[0xb3] = 0;
  return 1;
}
PCREG(4fa510, fn4fa510);
