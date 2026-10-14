// batch36016.cpp - cascade s4 batch 36016: 0x50f060, 0x535ac0, 0x564a40, 0x579bd0, 0x57aaf0 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef void(THISCALL *v3_t)(void *, u32, u32, u32);
typedef u32(THISCALL *v1u_t)(void *, u32);
typedef u32(THISCALL *v0u_t)(void *);
typedef u8 *(THISCALL *v0o_t)(void *);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);
typedef u32 (*hook_t)();

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" u8 *THISCALL ext_5003d0(void *self, u32 a);   // ret 4
extern "C" u32 THISCALL ext_4db2f0(void *self, u32 a);   // ret 4
extern "C" void THISCALL ext_5002f0(void *self, u32 a);  // ret 4

static inline u8 *logOpen(u32 file, u32 line) {
  u8 *db = G(u8 *, 0x700390);
  return (*(v2o_t **)db)[0x20 / 4](db, file, line);
}
static inline void log2(u8 *o, u32 a, u32 b) {  // o->slot 0x2c(o, a, b) cdecl with ecx = vtable, caller pops 12
  void **vt2 = *(void ***)o;
  void *fn = *(void **)((u8 *)vt2 + 0x2c);
  __asm__ volatile("pushl %[b]\n\tpushl %[a]\n\tpushl %[o]\n\tcall *%[f]\n\taddl $12, %%esp"
                   : "+c"(vt2) : [a] "r"(a), [b] "r"(b), [o] "r"(o), [f] "r"(fn) : "eax", "edx", "memory", "cc");
}

// 0x50f060, stdcall(a) ret 4: rec = 0x5003d0(a[4], 0); obj = [[0x70039c]+0x9b]->slot 0x58(rec[0]); null: 0x5002f0(0x5003d0(a[8], 0), 0).
// Else x = 0x4db2f0(obj[8], 1); y = tab->slot 0x4c(x); r2 = 0x5003d0(a[8], 0): r2 byte [4] <= 1 -> r2[0] = y, r2[4] = 1; else log (0x69c8e0, 0xc4, 0x69c6b0, 0x69c938) and the assert hook (int3 when null).
static void STDCALL fn50f060(u8 *a) {
  u8 *rec = ext_5003d0(*(u8 **)(a + 4), 0);
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *obj = (*(v1o_t **)tab)[0x58 / 4](tab, rd(rec));
  if (!obj) {
    u8 *r3 = ext_5003d0(*(u8 **)(a + 8), 0);
    ext_5002f0(r3, 0);
    return;
  }
  u32 x = ext_4db2f0(*(u8 **)(obj + 8), 1);
  tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 y = (*(v1u_t **)tab)[0x4c / 4](tab, x);
  u8 *r2 = ext_5003d0(*(u8 **)(a + 8), 0);
  if (r2[4] <= 1) {
    wr(r2, y);
    r2[4] = 1;
    return;
  }
  log2(logOpen(0x69c8e0, 0xc4), 0x69c6b0, 0x69c938);
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
}
PCREG(50f060, fn50f060);

extern "C" void THISCALL ext_44b610(void *self);  // plain ret
extern "C" void ext_44b740(void *p);              // cdecl

// 0x535ac0, thiscall(a) ret 4 (this = E): logs (0x6a1e2c, 0xbc1, 0x6a24c0, a); p = E + 0x53b2; p->slot 0x4c(&loc); r = p->slot 0x5c(&loc); while loc != 0:
// s = [[0x70039c]+0x9b]->slot 0x60(r); s && (s[0x2c] == a || a == -1): 0x44b610(s), 0x44b740(s); r = p->slot 0x5c(&loc).
static void THISCALL fn535ac0(u8 *E, u32 a) {
  u32 loc[3];
  log2(logOpen(0x6a1e2c, 0xbc1), 0x6a24c0, a);
  u8 *p = E + 0x53b2;
  if (!p) return;
  (*(v1_t **)p)[0x4c / 4](p, (u32)loc);
  u32 r = (*(v1u_t **)p)[0x5c / 4](p, (u32)loc);
  if (loc[0] == 0) return;
  do {
    u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u8 *s = (*(v1o_t **)tab)[0x60 / 4](tab, r);
    if (s && (rd(s + 0x2c) == a || a == 0xffffffffu)) {
      ext_44b610(s);
      ext_44b740(s);
    }
    r = (*(v1u_t **)p)[0x5c / 4](p, (u32)loc);
  } while (loc[0] != 0);
}
PCREG(535ac0, fn535ac0);

extern "C" void THISCALL ext_610100(void *self, u32 a);  // ret 4

// 0x564a40, thiscall(flag) ret 4 (this = E): b = (byte)flag == 0; slot 0xbc(b) on the objects at E[0xc62], [0xc76], [0xc7a], [0xc6a], [0xc6e], [0xc72]; E[0x18a] = (byte)flag; E[0xc66]->slot 0xbc(flag);
// E[0x5c] non-null: slot 0xbc(flag); 0x610100(E, b); p = E[0xc7e] non-null: q = p->slot 0x25c(0x6a6acc, 0); q: tail call q->slot 0xbc(1).
static void THISCALL fn564a40(u8 *E, u32 flag) {
  u32 b = ((u8)flag == 0);
  static const u16 offs[6] = {0xc62, 0xc76, 0xc7a, 0xc6a, 0xc6e, 0xc72};
  for (int i = 0; i < 6; i++) {
    u8 *o = *(u8 **)(E + offs[i]);
    (*(v1_t **)o)[0xbc / 4](o, b);
  }
  E[0x18a] = (u8)flag;
  u8 *o = *(u8 **)(E + 0xc66);
  (*(v1_t **)o)[0xbc / 4](o, flag);
  u8 *c = *(u8 **)(E + 0x5c);
  if (c) (*(v1_t **)c)[0xbc / 4](c, flag);
  ext_610100(E, b);
  u8 *p = *(u8 **)(E + 0xc7e);
  if (!p) return;
  u8 *q = (*(v2o_t **)p)[0x25c / 4](p, 0x6a6acc, 0);
  if (!q) return;
  (*(v1_t **)q)[0xbc / 4](q, 1);
}
PCREG(564a40, fn564a40);

typedef void(THISCALL *v2b_t)(void *, u32, u32);
typedef void (*cdecl4_t)(void *, char *, u32, u32);

// 0x579bd0, thiscall(a) ret 4 (this = E): y = [0x70039c]->slot 0x190(); y->slot 0x198 cdecl (y, buf[0x40], 0x6a9ac8, E[0x194]); z = [[0x70039c]+0x9b]->slot 0x134(); z->slot 0x68(buf, a, 0);
// w = [0x70039c]->slot 0xbc(); w->slot 0xbc(a); loc = (u8)a; v = *(u32 *)([0x7003b8] + E[0x194]*4 + 0x2c3d) (unaligned); v: E[0x44]->slot 0x130(v, (u16)E[0x198], &loc).
static void THISCALL fn579bd0(u8 *E, u32 a) {
  char buf[0x40];
  u8 *eng = G(u8 *, 0x70039c);
  u8 *y = (*(v0o_t **)eng)[0x190 / 4](eng);
  void *fn = *(void **)((u8 *)*(void ***)y + 0x198);
  ((cdecl4_t)fn)(y, buf, 0x6a9ac8u, rd(E + 0x194));
  eng = G(u8 *, 0x70039c);
  u8 *tab = *(u8 **)(eng + 0x9b);
  u8 *z = (*(v0o_t **)tab)[0x134 / 4](tab);
  (*(v3_t **)z)[0x68 / 4](z, (u32)buf, a, 0);
  eng = G(u8 *, 0x70039c);
  u8 *w = (*(v0o_t **)eng)[0xbc / 4](eng);
  (*(v1_t **)w)[0xbc / 4](w, a);
  u32 loc = (u8)a;
  u32 i = rd(E + 0x194);
  u32 v = *(u32 *)(G(u8 *, 0x7003b8) + i * 4 + 0x2c3d);
  if (!v) return;
  u8 *c = *(u8 **)(E + 0x44);
  (*(v3_t **)c)[0x130 / 4](c, v, *(u16 *)(E + 0x198), (u32)&loc);
}
PCREG(579bd0, fn579bd0);

// 0x57aaf0, thiscall(no args) (this = E): B = "" then for each of E[0x194..0x197] non-zero byte append the two bytes at 0x677bc8 and a NUL; E[0x180]->slot 0x284(B); E[0x198] = 0.
static void THISCALL fn57aaf0(u8 *E) {
  char B[0x800];
  B[0] = 0;
  for (u32 i = 0; i < 4; i++) {
    if (E[0x194 + i] != 0) {
      u32 n = 0;
      while (B[n]) n++;
      B[n] = (char)*(u8 *)0x677bc8;
      B[n + 1] = (char)*(u8 *)0x677bc9;
      B[n + 2] = (char)*(u8 *)0x677bca;
    }
  }
  u8 *c = *(u8 **)(E + 0x180);
  (*(v1_t **)c)[0x284 / 4](c, (u32)B);
  E[0x198] = 0;
}
PCREG(57aaf0, fn57aaf0);
