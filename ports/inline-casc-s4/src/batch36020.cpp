// batch36020.cpp - cascade s4 batch 36020: 0x553830, 0x597d30, 0x5d81b0, 0x476d30, 0x45e660 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v0_t)(void *);
typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef void(THISCALL *v3_t)(void *, u32, u32, u32);
typedef void(THISCALL *v4_t)(void *, u32, u32, u32, u32);
typedef u8(THISCALL *v1b_t)(void *, u32);
typedef u32(THISCALL *v0u_t)(void *);
typedef u32(THISCALL *v1u_t)(void *, u32);
typedef u8 *(THISCALL *v0o_t)(void *);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);
typedef u32 (*hook_t)();

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }
static inline void assertHook() {
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  else h();
}
static inline void log1(u32 file, u32 line, u32 fmt) {
  u8 *db = G(u8 *, 0x700390);
  u8 *o = (*(v2o_t **)db)[0x20 / 4](db, file, line);
  void **vt2 = *(void ***)o;
  void *fn = *(void **)((u8 *)vt2 + 0x2c);
  __asm__ volatile("pushl %[f2]\n\tpushl %[o]\n\tcall *%[f]\n\taddl $8, %%esp"
                   : "+c"(vt2) : [f2] "r"(fmt), [o] "r"(o), [f] "r"(fn) : "eax", "edx", "memory", "cc");
}

extern "C" u8 *THISCALL ext_5003d0(void *self, u32 a);   // ret 4
extern "C" void THISCALL ext_5002f0(void *self, u32 a);  // ret 4

// 0x553830, stdcall(a) ret 4: rec = 0x5003d0(a[4], 0); x = [[0x70039c]+0x9b]->slot 0x58(rec[0]); null: log (0x6a57fc, 0x315, 0x6a5af4), v = -1.
// Else x->slot 0x1e0(0x200006) and x[0x54] non-null: v = x[0x54][4]; else q = x->slot 0x20(): null -> -1; q2 = x->slot 0x20(); q2->slot 0x1e0(0x100bbd) ? 1 : -1.
// Finally 0x5002f0(0x5003d0(a[8], 0), v).
static void STDCALL fn553830(u8 *a) {
  u8 *rec = ext_5003d0(*(u8 **)(a + 4), 0);
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *x = (*(v1o_t **)tab)[0x58 / 4](tab, rd(rec));
  u32 v;
  if (!x) {
    log1(0x6a57fc, 0x315, 0x6a5af4);
    v = 0xffffffffu;
  } else {
    u8 *p;
    if ((*(v1b_t **)x)[0x1e0 / 4](x, 0x200006u) && (p = *(u8 **)(x + 0x54)) != 0) {
      v = rd(p + 4);
    } else if ((*(v0o_t **)x)[0x20 / 4](x) == 0) {
      v = 0xffffffffu;
    } else {
      u8 *q2 = (*(v0o_t **)x)[0x20 / 4](x);
      v = (*(v1b_t **)q2)[0x1e0 / 4](q2, 0x100bbdu) ? 1 : 0xffffffffu;
    }
  }
  u8 *r2 = ext_5003d0(*(u8 **)(a + 8), 0);
  ext_5002f0(r2, v);
}
PCREG(553830, fn553830);

extern "C" u32 THISCALL ext_594040(void *self, u32 a, u32 b);  // ret 8
extern "C" u8 *THISCALL ext_597720(void *self, u32 a);          // ret 4
extern "C" void THISCALL ext_597b50(void *self);                // plain ret
extern "C" void THISCALL ext_5967b0(void *self, u8 *p);         // ret 4
extern "C" void THISCALL ext_5a1ac0(void *self, u32 a, u32 b, u32 c);  // ret 0xc

// 0x597d30, thiscall(no args) (this = E): E[0xdd] = 0x594040(E[0x1d0b], 0x11, 0); p = 0x597720(E, 0), null returns; y = tab->slot 0x4c(E[0x1d0b]); 0x597b50(E); loc = {const, y};
// E[0x1d0b]->slot 0x12c(p, u16 E[0x1d2d], loc); signed E[0x1fae] < E[0x1fba]: const 0x6ad2f4, then 0x5967b0(E, p); else const 0x6ad304, then x = tab->slot 0x58(p), x: 0x5a1ac0(x, 0x1b, E[0xdd], 0).
static void THISCALL fn597d30(u8 *E) {
  u32 loc[2];
  u32 r = ext_594040(*(u8 **)(E + 0x1d0b), 0x11, 0);
  wr(E + 0xdd, r);
  u8 *p = ext_597720(E, 0);
  if (!p) return;
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  loc[1] = (*(v1u_t **)tab)[0x4c / 4](tab, rd(E + 0x1d0b));
  ext_597b50(E);
  bool lt = (s32)rd(E + 0x1fae) < (s32)rd(E + 0x1fba);
  u8 *cc = *(u8 **)(E + 0x1d0b);
  loc[0] = lt ? 0x6ad2f4u : 0x6ad304u;
  (*(v3_t **)cc)[0x12c / 4](cc, (u32)p, *(u16 *)(E + 0x1d2d), (u32)loc);
  if (lt) {
    ext_5967b0(E, p);
    return;
  }
  tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *x = (*(v1o_t **)tab)[0x58 / 4](tab, (u32)p);
  if (!x) return;
  ext_5a1ac0(x, 0x1b, rd(E + 0xdd), 0);
}
PCREG(597d30, fn597d30);

extern "C" void THISCALL ext_5d8470(void *self);  // plain ret

// 0x5d81b0, thiscall(id, unused) ret 8, returns 0 (this = E): (u16)id == E[0x4a]: eng->slot 0x1cc(0); eng[0x1b40] = 1.0f; eng->slot 0xc(0, 0, 0, 0); n = tab->slot 0xac() (signed); n times tab->slot 0xa4();
// [eng+0x190f]->slot 0xbc(); tab->slot 0xa0(E + 0x4e). (u16)id == E[0x4c]: 0x5d8470(E); E[0xbc] == 0: E[0x44]->slot 0x114(0x10).
static u32 THISCALL fn5d81b0(u8 *E, u32 id, u32 unused) {
  (void)unused;
  u16 w = (u16)id;
  if (w == *(u16 *)(E + 0x4a)) {
    u8 *eng = G(u8 *, 0x70039c);
    (*(v1_t **)eng)[0x1cc / 4](eng, 0);
    wr(G(u8 *, 0x70039c) + 0x1b40, 0x3f800000);
    eng = G(u8 *, 0x70039c);
    (*(v4_t **)eng)[0xc / 4](eng, 0, 0, 0, 0);
    u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    s32 n = (s32)(*(v0u_t **)tab)[0xac / 4](tab);
    if (n > 0) {
      do {
        tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
        (*(v0_t **)tab)[0xa4 / 4](tab);
        n--;
      } while (n > 0);
    }
    u8 *o = *(u8 **)(G(u8 *, 0x70039c) + 0x190f);
    (*(v0_t **)o)[0xbc / 4](o);
    tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    (*(v1_t **)tab)[0xa0 / 4](tab, (u32)(E + 0x4e));
    return 0;
  }
  if (w == *(u16 *)(E + 0x4c)) {
    ext_5d8470(E);
    if (rd(E + 0xbc) == 0) {
      u8 *c = *(u8 **)(E + 0x44);
      (*(v1_t **)c)[0x114 / 4](c, 0x10);
    }
  }
  return 0;
}
PCREG(5d81b0, fn5d81b0);

extern "C" u8 THISCALL ext_441790(void *self, void *s);  // ret 4

// 0x476d30, thiscall(s) ret 4, returns bool (this = E): 0x441790(E, s) false -> 0. s->slot 0x60(E[0x72]); s->slot 0x40(u16 E[0x70]); E[0x72] != 0: s->slot 0x64(E[0x6c]); return 1.
// Else s->slot 0x44(E[0x5c]); slot 0x44(E[0x60]); for i < E[0x5c] (signed): s->slot 0x64(E[0x64][i]); s->slot 0x10(E[0x68], E[0x5c] * 4); return 1.
static u8 THISCALL fn476d30(u8 *E, u8 *s) {
  if (!ext_441790(E, s)) return 0;
  (*(v1_t **)s)[0x60 / 4](s, E[0x72]);
  (*(v1_t **)s)[0x40 / 4](s, *(u16 *)(E + 0x70));
  if (E[0x72] != 0) {
    (*(v1_t **)s)[0x64 / 4](s, rd(E + 0x6c));
    return 1;
  }
  (*(v1_t **)s)[0x44 / 4](s, rd(E + 0x5c));
  (*(v1_t **)s)[0x44 / 4](s, rd(E + 0x60));
  if ((s32)rd(E + 0x5c) > 0) {
    s32 i = 0;
    do {
      (*(v1_t **)s)[0x64 / 4](s, ((u32 *)rd(E + 0x64))[i]);
      i++;
    } while (i < (s32)rd(E + 0x5c));
  }
  (*(v2_t **)s)[0x10 / 4](s, rd(E + 0x68), rd(E + 0x5c) << 2);
  return 1;
}
PCREG(476d30, fn476d30);

extern "C" u8 THISCALL ext_4da3a0(void *self);  // plain ret
extern "C" void ext_634273(void *p, u32 n);     // cdecl

// 0x45e660, thiscall(no args) (this = E): 0x4da3a0(E[8]) false returns. E[0x10][0x10] non-null: 0x634273(it, 8), cleared. E[0x10][8] == 0 returns. Loop while c = E[0x10][8] non-null and c->slot 0x14() non-zero:
// y = E[0x10][8]->slot 0x30(0); z = [0x70038c]->slot 0xcc(y); z ? z->slot 0x54(E) : assert hook; continue while E[0x10] non-null. Finally E[0x10][8] non-null: slot 0(1); E[0x10][8] = 0.
static void THISCALL fn45e660(u8 *E) {
  if (!ext_4da3a0(*(u8 **)(E + 8))) return;
  u8 *x = *(u8 **)(E + 0x10);
  if (x) {
    u8 *q = *(u8 **)(x + 0x10);
    if (q) {
      ext_634273(q, 8);
      wr(*(u8 **)(E + 0x10) + 0x10, 0);
    }
  }
  x = *(u8 **)(E + 0x10);
  if (rd(x + 8) == 0) return;
  while (x) {
    u8 *c = *(u8 **)(x + 8);
    if (!c) break;
    if (!(*(v0u_t **)c)[0x14 / 4](c)) break;
    u8 *cur = *(u8 **)(*(u8 **)(E + 0x10) + 8);
    u32 y = (*(v1u_t **)cur)[0x30 / 4](cur, 0);
    u8 *g = G(u8 *, 0x70038c);
    u8 *z = (*(v1o_t **)g)[0xcc / 4](g, y);
    if (z) (*(v1_t **)z)[0x54 / 4](z, (u32)E);
    else assertHook();
    x = *(u8 **)(E + 0x10);
  }
  x = *(u8 **)(E + 0x10);
  u8 *c = *(u8 **)(x + 8);
  if (c) (*(v1_t **)c)[0](c, 1);
  wr(*(u8 **)(E + 0x10) + 8, 0);
}
PCREG(45e660, fn45e660);
