// batch36026.cpp - cascade s4 batch 36026: 0x474eb0, 0x5057e0, 0x50c290, 0x537160, 0x53e830 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v0_t)(void *);
typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef void(THISCALL *v3_t)(void *, u32, u32, u32);
typedef u32(THISCALL *v0u_t)(void *);
typedef u32(THISCALL *v1u_t)(void *, u32);
typedef u32(THISCALL *v3u_t)(void *, u32, u32, u32);
typedef u8 *(THISCALL *v0o_t)(void *);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);
typedef u32 (*hook_t)();

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }
static inline u8 *tabOf() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }
static inline void assertHook() {
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  else h();
}
static inline u8 *logOpen(u32 file, u32 line) {
  u8 *db = G(u8 *, 0x700390);
  return (*(v2o_t **)db)[0x20 / 4](db, file, line);
}

extern "C" void FASTCALL ext_441970(u32 *dst, u32 *src, u32 *mat);  // ecx = dst, edx = src, stack arg = matrix, ret 4
extern "C" void FASTCALL ext_441940(u32 *dst, u32 *src);            // ecx = dst, edx = src, plain ret

// 0x474eb0, thiscall(a, b) ret 8 (this = E): v = a->slot 0x2b4(E[0x56] (byte), buf34, buf10); a->slot 0x390(v); a->slot 0x98(buf34, buf10); t = b->slot 0x20(); t->slot 0x94(buf34, buf10);
// 0x441970(buf44, E + 0x5a, buf34) and 0x441940(buf10, buf44) (register-argument helpers); b->slot 0x2d4(buf34, buf10).
static void THISCALL fn474eb0(u8 *E, u8 *a, u8 *b) {
  u32 buf34[9];
  u32 buf10[3];
  u32 buf44[4];
  void **avt = *(void ***)a;
  u32 v = ((u32(THISCALL *)(void *, u32, u32, u32))avt[0x2b4 / 4])(a, E[0x56], (u32)buf34, (u32)buf10);
  ((void(THISCALL *)(void *, u32))avt[0x390 / 4])(a, v);
  (*(v2_t **)a)[0x98 / 4](a, (u32)buf34, (u32)buf10);
  u8 *t = (*(v0o_t **)b)[0x20 / 4](b);
  (*(v2_t **)t)[0x94 / 4](t, (u32)buf34, (u32)buf10);
  ext_441970(buf44, (u32 *)(E + 0x5a), buf34);
  ext_441940(buf10, buf44);
  (*(v2_t **)b)[0x2d4 / 4](b, (u32)buf34, (u32)buf10);
}
PCREG(474eb0, fn474eb0);

// 0x5057e0, thiscall(a, b) ret 8 (this = E): b == -1: log (0x69cd2c, 0xd1, 0x69cdc0, a, name); b == 0: log (0xd4, 0x69cdfc, a, name); name = E[0x14]->slot 0x20()[4] or 0x67c8e8; other b: assert hook.
static void THISCALL fn5057e0(u8 *E, u32 a, u32 b) {
  if (b == 0xffffffffu || b == 0) {
    u32 line = b ? 0xd1 : 0xd4;
    u32 fmt = b ? 0x69cdc0 : 0x69cdfc;
    u8 *o = logOpen(0x69cd2c, line);
    u8 *c = *(u8 **)(E + 0x14);
    u8 *x = (*(v0o_t **)c)[0x20 / 4](c);
    u32 nm = rd(x + 4);
    u32 name = nm ? nm : 0x67c8e8u;
    void **vt2 = *(void ***)o;
    void *fn = *(void **)((u8 *)vt2 + 0x2c);
    ((void (*)(u8 *, u32, u32, u32))fn)(o, fmt, a, name);  // cdecl varargs print (ecx = vtable in the exe is not read by it)
    (void)vt2;
    return;
  }
  assertHook();
}
PCREG(5057e0, fn5057e0);

extern "C" u8 *THISCALL ext_5003d0(void *self, u32 a);   // ret 4
extern "C" void THISCALL ext_5002f0(void *self, u32 a);  // ret 4

// 0x50c290, thiscall(a) ret 4 (this = E): id = 0x5003d0(a[4], 0)[0]; x = E->slot 0x4c(id); null: 0x5002f0(0x5003d0(a[8], 0), 0).
// Else y = x->slot 0x500(); id2 = tab->slot 0x4c(y); r = 0x5003d0(a[8], 0): r[4] <= 1: r[0] = id2, r[4] = 1; else log (0x69c8e0, 0xc4, 0x69c6b0, 0x69c938) and the assert hook.
static void THISCALL fn50c290(u8 *E, u8 *a) {
  u8 *rec = ext_5003d0(*(u8 **)(a + 4), 0);
  u8 *x = (*(v1o_t **)E)[0x4c / 4](E, rd(rec));
  if (!x) {
    u8 *r3 = ext_5003d0(*(u8 **)(a + 8), 0);
    ext_5002f0(r3, 0);
    return;
  }
  u8 *t = tabOf();
  void **tvt = *(void ***)t;
  u32 y = (*(v0u_t **)x)[0x500 / 4](x);
  u8 *t2 = tabOf();
  u32 id2 = ((v1u_t)tvt[0x4c / 4])(t2, y);
  u8 *r2 = ext_5003d0(*(u8 **)(a + 8), 0);
  if (r2[4] <= 1) {
    wr(r2, id2);
    r2[4] = 1;
    return;
  }
  u8 *o = logOpen(0x69c8e0, 0xc4);
  void **vt2 = *(void ***)o;
  void *fn = *(void **)((u8 *)vt2 + 0x2c);
  __asm__ volatile("pushl $0x69c938\n\tpushl $0x69c6b0\n\tpushl %[o]\n\tcall *%[f]\n\taddl $12, %%esp"
                   : "+c"(vt2) : [o] "r"(o), [f] "r"(fn) : "eax", "edx", "memory", "cc");
  assertHook();
}
PCREG(50c290, fn50c290);

extern "C" u32 FASTCALL ext_4cc850(u32 a, u32 b);  // wildcard match: 0 = match

// 0x537160, thiscall(tab, name, n) ret 0xc (this = E): n == 0, tab == 0, name == 0 or E[0x5302] == 0 -> 0; for i < u16 tab[8] (zero count -> 0): off = tab[0x10] (0 -> 0); item = (E[0x5302] + off)[i] (0 -> 0);
// s = E->slot 0x1e8(item + E[0x5302]) (0 -> 0); 0x4cc850(s, name) == 0 returns the item.
static u32 THISCALL fn537160(u8 *E, u8 *tab, u32 name, u32 n) {
  if (n < 1) return 0;
  if (!tab || !name) return 0;
  if (rd(E + 0x5302) == 0) return 0;
  s32 i = 0;
  if (0 >= *(u16 *)(tab + 8)) return 0;
  for (;;) {
    u32 off = rd(tab + 0x10);
    if (!off) return 0;
    u32 base = rd(E + 0x5302);
    u32 *arr = (u32 *)(off + base);
    u32 item = arr[i];
    if (!item) return 0;
    u32 s = (*(v1u_t **)E)[0x1e8 / 4](E, item + base);
    if (!s) return 0;
    if (ext_4cc850(s, name) == 0) return arr[i];
    i++;
    if (!(i < (s32) * (u16 *)(tab + 8))) return 0;
  }
}
PCREG(537160, fn537160);

extern "C" u32 THISCALL ext_4e5e60(void *self);  // plain ret

// 0x53e830, thiscall(s) ret 4, returns E[0x141] (this = E): cursor p = s[0], null skips the reads. Tag t = p[0] (not 0xff, low 6 bits): 3 -> E[0x149] = (0x4e5e60(s) != 0);
// re-read: 0xb -> E[0x145] = 0x4e5e60(s); re-read: 3 -> E[0x141] = 0x4e5e60(s). Then [0x70039c][0x1a9f] != 0 and E[0x145] == 0: log (0x6a2ca0, 0xfa, 0x6a2d28, E[0x44][4] or 0x67c8e8). E[0x13d] = E[0x141].
static u32 THISCALL fn53e830(u8 *E, u8 *s) {
  if (rd(s) != 0) {
    u8 *p = *(u8 **)s;
    u8 a = p[0];
    if (a != 0xff && (a & 0x3f) == 3) E[0x149] = (ext_4e5e60(s) != 0);
    p = *(u8 **)s;
    a = p[0];
    if (a != 0xff && (a & 0x3f) == 0xb) wr(E + 0x145, ext_4e5e60(s));
    p = *(u8 **)s;
    a = p[0];
    if (a != 0xff && (a & 0x3f) == 3) wr(E + 0x141, ext_4e5e60(s));
    if (rd(G(u8 *, 0x70039c) + 0x1a9f) != 0 && rd(E + 0x145) == 0) {
      u8 *o = logOpen(0x6a2ca0, 0xfa);
      u8 *c = *(u8 **)(E + 0x44);
      u32 nm = rd(c + 4);
      u32 name = nm ? nm : 0x67c8e8u;
      void **vt2 = *(void ***)o;
      void *fn = *(void **)((u8 *)vt2 + 0x2c);
      __asm__ volatile("pushl %[n]\n\tpushl $0x6a2d28\n\tpushl %[o]\n\tcall *%[f]\n\taddl $12, %%esp"
                       : "+c"(vt2) : [n] "r"(name), [o] "r"(o), [f] "r"(fn) : "eax", "edx", "memory", "cc");
    }
  }
  wr(E + 0x13d, rd(E + 0x141));
  return rd(E + 0x141);
}
PCREG(53e830, fn53e830);
