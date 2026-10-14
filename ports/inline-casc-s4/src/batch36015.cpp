// batch36015.cpp - cascade s4 batch 36015: 0x4d3900, 0x4d41b0, 0x4d5000, 0x4dc1e0, 0x4f3d40 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef void(THISCALL *v3_t)(void *, u32, u32, u32);
typedef u32(THISCALL *v1u_t)(void *, u32);
typedef u32(THISCALL *v2u_t)(void *, u32, u32);
typedef u8(THISCALL *v2b_t)(void *, u32, u32);
typedef u8 *(THISCALL *v0o_t)(void *);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

// log call through [0x700390]: o = db->slot 0x20(file, line); o->slot 0x2c cdecl with ecx = o->vtbl; `argc` stack args after o (0..2), caller pops.
static inline u8 *logOpen(u32 file, u32 line) {
  u8 *db = G(u8 *, 0x700390);
  return (*(v2o_t **)db)[0x20 / 4](db, file, line);
}
static inline void log1(u8 *o, u32 fmt) {
  void **vt2 = *(void ***)o;
  void *fn = *(void **)((u8 *)vt2 + 0x2c);
  __asm__ volatile("pushl %[f2]\n\tpushl %[o]\n\tcall *%[f]\n\taddl $8, %%esp"
                   : "+c"(vt2) : [f2] "r"(fmt), [o] "r"(o), [f] "r"(fn) : "eax", "edx", "memory", "cc");
}
static inline void log2(u8 *o, u32 fmt, u32 a) {
  void **vt2 = *(void ***)o;
  void *fn = *(void **)((u8 *)vt2 + 0x2c);
  __asm__ volatile("pushl %[a]\n\tpushl %[f2]\n\tpushl %[o]\n\tcall *%[f]\n\taddl $12, %%esp"
                   : "+c"(vt2) : [a] "r"(a), [f2] "r"(fmt), [o] "r"(o), [f] "r"(fn) : "eax", "edx", "memory", "cc");
}

// 0x4d3900, thiscall(s) ret 4 (this = E): off = 0; while off < E[0xc] (unsigned; skipped when E[0xc] == 0): rec = E[8] + off; off += rec[0];
// rec byte [4] set: n = *(u32 *)(rec+5) + *(u32 *)(rec+0xd) + 0xc; s->slot 0x10(&n, 4); s->slot 0x10(rec+5, n); s->slot 0x3c(((s32)(*(u32 *)(rec+9) - 0x6e7a30)) / 20).
// Finally s->slot 0x10(&(-1), 4).
static void THISCALL fn4d3900(u8 *E, u8 *s) {
  u32 neg = 0xffffffffu;
  u32 off = 0;
  if (rd(E + 0xc) > 0) {
    do {
      u8 *rec = *(u8 **)(E + 8) + off;
      off += rd(rec);
      if (rec[4] != 0) {
        u32 n = rd(rec + 5) + (rd(rec + 0xd) + 0xc);
        (*(v2_t **)s)[0x10 / 4](s, (u32)&n, 4);
        (*(v2_t **)s)[0x10 / 4](s, (u32)(rec + 5), n);
        s32 d = (s32)(rd(rec + 9) - 0x6e7a30u);
        (*(v1_t **)s)[0x3c / 4](s, (u32)(d / 20));
      }
    } while (off < rd(E + 0xc));
  }
  (*(v2_t **)s)[0x10 / 4](s, (u32)&neg, 4);
}
PCREG(4d3900, fn4d3900);

typedef char *(*strtok_t)(char *, const char *);

// 0x4d41b0, thiscall(no args) (this = E): b = E+0x1008; b[0] set -> E->slot 0x34(b); E[0xfb3] = 0; t1 = strtok(b, 0x679e6c); null or empty returns.
// t2 = strtok(0, 0x6965c8); ok = (E+0x10db)->slot 8(t1, t2); ok: E->slot 4 cdecl (E, 0x6965cc, t1, t2); E[0x10cf] = 1; b[0] = 0. Else E->slot 4 cdecl (E, 0x6965d4, t1); b[0] = 0; E[0x10cf] = 1.
static void THISCALL fn4d41b0(u8 *E) {
  u8 *b = E + 0x1008;
  if (b[0]) (*(v1_t **)E)[0x34 / 4](E, (u32)b);
  wr(E + 0xfb3, 0);
  char *t1 = G(strtok_t, 0x676420)((char *)b, (const char *)0x679e6c);
  if (!t1 || !*t1) return;
  char *t2 = G(strtok_t, 0x676420)(0, (const char *)0x6965c8);
  u8 *sub = E + 0x10db;
  void **svt = *(void ***)sub;
  u8 ok = ((v2b_t)svt[8 / 4])(sub, (u32)t1, (u32)t2);
  void **vt = *(void ***)E;
  void *fn = vt[4 / 4];
  if (ok) {
    __asm__ volatile("pushl %[t2]\n\tpushl %[t1]\n\tpushl $0x6965cc\n\tpushl %[e]\n\tcall *%[f]\n\taddl $16, %%esp"
                     : : [t2] "r"(t2), [t1] "r"(t1), [e] "r"(E), [f] "r"(fn) : "eax", "ecx", "edx", "memory", "cc");
    wr(E + 0x10cf, 1);
    b[0] = 0;
    return;
  }
  __asm__ volatile("pushl %[t1]\n\tpushl $0x6965d4\n\tpushl %[e]\n\tcall *%[f]\n\taddl $12, %%esp"
                   : : [t1] "r"(t1), [e] "r"(E), [f] "r"(fn) : "eax", "ecx", "edx", "memory", "cc");
  b[0] = 0;
  wr(E + 0x10cf, 1);
}
PCREG(4d41b0, fn4d41b0);

// 0x4d5000, thiscall(no args) (this = E): logs (0x6966c4, 0x182, fmt 0x696728); h = *(u8 **)(E+0x11); h[4] >= 0 (signed) returns; n = h[0xc]; zero returns;
// rec = (h[4] & 0x40000000) ? h + 0x14 + h[0x10]*4 : h + 0x10; repeat n times: kind = rec[4] & 0xc0000000; sz = (kind is 0x40000000, 0x80000000 or 0xc0000000) ? rec[8] : 8;
// logs (0x6966c4, 0x18a, fmt 0x696740, rec + sz); rec += rec[4] & 0x3fffffff.
static void THISCALL fn4d5000(u8 *E) {
  log1(logOpen(0x6966c4, 0x182), 0x696728);
  u8 *h = *(u8 **)(E + 0x11);
  u32 f = rd(h + 4);
  if ((s32)f >= 0) return;
  u32 n = rd(h + 0xc);
  if (!n) return;
  u8 *rec;
  if (f & 0x40000000u) rec = h + 0x10 + rd(h + 0x10) * 4 + 4;
  else rec = h + 0x10;
  do {
    u32 kind = rd(rec + 4) & 0xc0000000u;
    u32 sz = 8;
    if (kind == 0x40000000u || kind == 0x80000000u) sz = rd(rec + 8);
    if (kind == 0xc0000000u) sz = rd(rec + 8);
    log2(logOpen(0x6966c4, 0x18a), 0x696740, sz + (u32)rec);
    rec += rd(rec + 4) & 0x3fffffffu;
    n--;
  } while (n != 0);
}
PCREG(4d5000, fn4d5000);

extern "C" void THISCALL ext_4dc140(void *self, u32 a);  // ret 4
extern "C" void THISCALL ext_4da770(void *self, u32 a);  // ret 4

// 0x4dc1e0, thiscall(a) ret 4 (this = E): id = u16 E[0x5c]; id != 0: o = ([[0x70039c]+0x9b][8])->slot 0x5c(id) non-null: x = lookup again (null when id == 0);
// x byte [0x1c] = n; some i < n with x[i*4] == a: lookup a third time and 0x4dc140(that, a). Then a->slot 0x36c(E); 0x4da770(E, a).
static inline u8 *lookup5c(u16 id) {
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *o8 = *(u8 **)(tab + 8);
  return (*(v1o_t **)o8)[0x5c / 4](o8, id);
}
static void THISCALL fn4dc1e0(u8 *E, u8 *a) {
  u16 id = *(u16 *)(E + 0x5c);
  if (id != 0) {
    u8 *o = lookup5c(id);
    if (o) {
      u16 id2 = *(u16 *)(E + 0x5c);
      u8 *x = id2 ? lookup5c(id2) : 0;
      u32 n = x[0x1c];
      if (n != 0) {
        u32 i = 0;
        bool found = false;
        do {
          if (((u8 **)x)[i] == a) { found = true; break; }
          i++;
        } while (i != n);
        if (found) {
          u16 id3 = *(u16 *)(E + 0x5c);
          u8 *y = id3 ? lookup5c(id3) : 0;
          ext_4dc140(y, (u32)a);
        }
      }
    }
  }
  (*(v1_t **)a)[0x36c / 4](a, (u32)E);
  ext_4da770(E, (u32)a);
}
PCREG(4dc1e0, fn4dc1e0);

extern "C" void THISCALL ext_45d3a0(void *self);  // plain ret

// 0x4f3d40, thiscall(no args) (this = E): 0x45d3a0(E); x = E->slot 0x2c4(); null: logs (0x699384, 0x30, 0x6993ac, name = E[4] ? E[4] : 0x67c8e8), E->slot 0x210(1), return.
// Else y = E->slot 0x20(); y[0xc][0x23] != 0x10002e -> E->slot 0x2c4()->slot 0x288(E, 0, 1). E[8][0x3c] & 0x800 returns; z = E->slot 0x2e0(); z: E->slot 0x2c4()->slot 0x2ec(z).
static void THISCALL fn4f3d40(u8 *E) {
  ext_45d3a0(E);
  u8 *x = (*(v0o_t **)E)[0x2c4 / 4](E);
  if (!x) {
    u8 *o = logOpen(0x699384, 0x30);
    u32 name = rd(E + 4) ? rd(E + 4) : 0x67c8e8u;
    log2(o, 0x6993ac, name);
    (*(v1_t **)E)[0x210 / 4](E, 1);
    return;
  }
  u8 *y = (*(v0o_t **)E)[0x20 / 4](E);
  if (rd(*(u8 **)(y + 0xc) + 0x23) != 0x10002eu) {
    u8 *x2 = (*(v0o_t **)E)[0x2c4 / 4](E);
    (*(v3_t **)x2)[0x288 / 4](x2, (u32)E, 0, 1);
  }
  u8 *w = *(u8 **)(E + 8);
  if (rd(w + 0x3c) & 0x800) return;
  u8 *z = (*(v0o_t **)E)[0x2e0 / 4](E);
  if (z) {
    u8 *x3 = (*(v0o_t **)E)[0x2c4 / 4](E);
    (*(v1_t **)x3)[0x2ec / 4](x3, (u32)z);
  }
}
PCREG(4f3d40, fn4f3d40);
