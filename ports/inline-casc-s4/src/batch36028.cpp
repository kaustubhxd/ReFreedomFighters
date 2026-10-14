// batch36028.cpp - cascade s4 batch 36028: 0x5307c0, 0x468320, 0x468a30, 0x46d760, 0x473000 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v0_t)(void *);
typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef u32(THISCALL *v0u_t)(void *);
typedef u32(THISCALL *v1u_t)(void *, u32);
typedef u8(THISCALL *v0b_t)(void *);
typedef u8(THISCALL *v1b_t)(void *, u32);
typedef u8 *(THISCALL *v0o_t)(void *);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }
static inline u8 *tabOf() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }
static inline u8 *logOpen(u32 file, u32 line) {
  u8 *db = G(u8 *, 0x700390);
  return (*(v2o_t **)db)[0x20 / 4](db, file, line);
}
// o->slot 0x2c cdecl varargs print with ecx = vtable in the exe; the ports call it as plain cdecl (the stubs do not read ecx)
static inline void logPrint2(u8 *o, u32 fmt, u32 a) {
  void *fn = *(void **)((u8 *)*(void ***)o + 0x2c);
  ((void (*)(u8 *, u32, u32))fn)(o, fmt, a);
}
static inline void logPrint1(u8 *o, u32 fmt) {
  void *fn = *(void **)((u8 *)*(void ***)o + 0x2c);
  ((void (*)(u8 *, u32))fn)(o, fmt);
}

extern "C" u32 THISCALL ext_52d750(void *self, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8, u32 a9);  // ret 0x24

// 0x5307c0, thiscall(a, p, b) ret 0xc (this = E): builds on the stack three triples {const, a, b} (consts 0x6a141c, 0x6a1424, 0x6a142c) and a 13-dword block s:
// s[0] = &s[6], s[1..3] = &triple0..2, s[4] byte = 1, s[5] = E, s[6] = 0x6a140c, s[7..9] = u16 p[0], p[1], p[2], s[10..12] = those + 1; returns
// 0x52d750(E, &s[0], 0x6e9034, E[0x38] - 1, 0, 0, 0, E[0x3c], E[0x40], E[0x44]).
static u32 THISCALL fn5307c0(u8 *E, u32 a, u16 *p, u32 b) {
  u32 L[22];
  u32 x = p[0], y = p[1], z = p[2];
  L[0] = 0x6a141c; L[1] = a; L[2] = b;
  L[3] = 0x6a1424; L[4] = a; L[5] = b;
  L[6] = 0x6a142c; L[7] = a; L[8] = b;
  u32 *s = &L[9];
  s[0] = (u32)&s[6];
  s[1] = (u32)&L[0];
  s[2] = (u32)&L[3];
  s[3] = (u32)&L[6];
  s[4] = 1;
  s[5] = (u32)E;
  s[6] = 0x6a140c;
  s[7] = x;
  s[8] = y;
  s[9] = z;
  s[10] = x + 1;
  s[11] = y + 1;
  s[12] = z + 1;
  return ext_52d750(E, (u32)s, 0x6e9034, rd(E + 0x38) - 1, 0, 0, 0, rd(E + 0x3c), rd(E + 0x40), rd(E + 0x44));
}
PCREG(5307c0, fn5307c0);

// 0x468320, thiscall(no args) (this = E): c = E[0x44]; bit 10 of c[8][0x3c] clear: log (0x6887c4, 0xf7d, 0x688ec0, name = c[4] or 0x67c8e8) and tail call E->slot 0x58().
// Else c->slot 0x20()->slot 0x1e0(0x1007d3) true: c(reloaded)->slot 0x20()->slot 0x2dc(E[0x44], E[0x4e]); otherwise log (0xf85, 0x688f08, name) and tail call E->slot 0x58().
static void THISCALL fn468320(u8 *E) {
  u8 *c = *(u8 **)(E + 0x44);
  u32 fl = rd(*(u8 **)(c + 8) + 0x3c);
  if (!((fl >> 10) & 1)) {
    u8 *o = logOpen(0x6887c4, 0xf7d);
    u32 nm = rd(c + 4);
    logPrint2(o, 0x688ec0, nm ? nm : 0x67c8e8u);
    (*(v0_t **)E)[0x58 / 4](E);
    return;
  }
  u8 *x = (*(v0o_t **)c)[0x20 / 4](c);
  if ((*(v1b_t **)x)[0x1e0 / 4](x, 0x1007d3u)) {
    c = *(u8 **)(E + 0x44);
    u8 *y = (*(v0o_t **)c)[0x20 / 4](c);
    (*(v2_t **)y)[0x2dc / 4](y, rd(E + 0x44), rd(E + 0x4e));
    return;
  }
  u8 *o = logOpen(0x6887c4, 0xf85);
  c = *(u8 **)(E + 0x44);
  u32 nm = rd(c + 4);
  logPrint2(o, 0x688f08, nm ? nm : 0x67c8e8u);
  (*(v0_t **)E)[0x58 / 4](E);
}
PCREG(468320, fn468320);

extern "C" u32 FASTCALL ext_4cc850(u32 a, u32 b);  // wildcard match: 0 = match
extern "C" u32 THISCALL ext_41e680(void *self, u32 a);  // plain ret

// 0x468a30, stdcall(a) ret 4: 0x4cc850(a[4] or 0x67c8e8, 0x688f74) == 0 returns. x = tab->slot 0x138(); local = 0; x->slot 0x88(0x688f80, &local); id = local:
// id: o = tab->slot 0x58(id); ax = tab->slot 0x114(0x688f94, 0, 0x6887c4, 0x1009); o->slot 0x128((u16)ax, 0x41e680(a, 0)). No id: [eng+0x190f]->slot 0xac(a, 100000.0f).
typedef u32(THISCALL *v4u_t)(void *, u32, u32, u32, u32);
static void STDCALL fn468a30(u8 *a) {
  u32 nm = rd(a + 4);
  if (ext_4cc850(nm ? nm : 0x67c8e8u, 0x688f74) == 0) return;
  u8 *t = tabOf();
  u8 *x = (*(v0o_t **)t)[0x138 / 4](t);
  u32 local = 0;
  (*(v2_t **)x)[0x88 / 4](x, 0x688f80, (u32)&local);
  if (local != 0) {
    t = tabOf();
    u8 *o = (*(v1o_t **)t)[0x58 / 4](t, local);
    t = tabOf();
    u32 ax = (*(v4u_t **)t)[0x114 / 4](t, 0x688f94, 0, 0x6887c4, 0x1009);
    void **ovt = *(void ***)o;
    u32 v = ext_41e680(a, 0);
    ((v2_t)ovt[0x128 / 4])(o, (u16)ax, v);
    return;
  }
  u8 *c = *(u8 **)(G(u8 *, 0x70039c) + 0x190f);
  (*(v2_t **)c)[0xac / 4](c, (u32)a, 0x47c35000u);
}
PCREG(468a30, fn468a30);

// 0x46d760, thiscall(sink) ret 4 (this = E): c = E[0x70] (null returns); c->slot 0x4c(&loc); for each r from c->slot 0x64(&loc): o = tab->slot 0x58(r[4]); null: c->slot 0x44(&loc);
// else p = o->slot 0x100(0x688854); p and p->slot 0x90() (al) true: sink->slot 4(r[4]).
static void THISCALL fn46d760(u8 *E, u8 *sink) {
  u32 loc[3];
  u8 *c = *(u8 **)(E + 0x70);
  if (!c) return;
  (*(v1_t **)c)[0x4c / 4](c, (u32)loc);
  c = *(u8 **)(E + 0x70);
  u8 *r = (*(v1o_t **)c)[0x64 / 4](c, (u32)loc);
  if (!r) return;
  do {
    u8 *tab = tabOf();
    u8 *o = (*(v1o_t **)tab)[0x58 / 4](tab, rd(r + 4));
    if (!o) {
      c = *(u8 **)(E + 0x70);
      (*(v1_t **)c)[0x44 / 4](c, (u32)loc);
    } else {
      u8 *p = (*(v1o_t **)o)[0x100 / 4](o, 0x688854);
      if (p && (*(v0b_t **)p)[0x90 / 4](p)) (*(v1_t **)sink)[4 / 4](sink, rd(r + 4));
    }
    c = *(u8 **)(E + 0x70);
    r = (*(v1o_t **)c)[0x64 / 4](c, (u32)loc);
  } while (r);
}
PCREG(46d760, fn46d760);

// 0x473000, thiscall(a) ret 4 (this = E): a != 0: tab->slot 0x4c(a); s = E->slot 0x500(); t = E->slot 0x504(); s == a: E->slot 0x3f0() != 9 -> E->slot 0x45c(9, 0), return;
// t != a: log (0x68961c, 0x65e, 0x689850), return. Else (a == 0 or t == a): E->slot 0x3f0() != 0xa -> E->slot 0x45c(0xa, 0).
static void THISCALL fn473000(u8 *E, u32 a) {
  if (a != 0) {
    u8 *t = tabOf();
    (*(v1u_t **)t)[0x4c / 4](t, a);
    u32 s = (*(v0u_t **)E)[0x500 / 4](E);
    u32 t2 = (*(v0u_t **)E)[0x504 / 4](E);
    if (s == a) {
      if ((*(v0u_t **)E)[0x3f0 / 4](E) != 9) (*(v2_t **)E)[0x45c / 4](E, 9, 0);
      return;
    }
    if (t2 != a) {
      logPrint1(logOpen(0x68961c, 0x65e), 0x689850);
      return;
    }
  }
  if ((*(v0u_t **)E)[0x3f0 / 4](E) != 0xa) (*(v2_t **)E)[0x45c / 4](E, 0xa, 0);
}
PCREG(473000, fn473000);
