// batch36021.cpp - cascade s4 batch 36021: 0x487490, 0x497210, 0x4e1070, 0x50e7f0, 0x50f120 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v0_t)(void *);
typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef u32(THISCALL *v0u_t)(void *);
typedef u32(THISCALL *v1u_t)(void *, u32);
typedef u32(THISCALL *v5u_t)(void *, u32, u32, u32, u32, u32);
typedef u8 *(THISCALL *v0o_t)(void *);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);
typedef u32 (*hook_t)();

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }
static inline u8 *tabOf() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

// 0x487490, thiscall(s) ret 4 (this = E): o = s->slot 8(); s[0xa]: ax = tab->slot 0x114(0x68cf28, 0, 0x68cee8, 0x60, 0); o->slot 0x130(E[4], (u16)ax).
// then y = tab->slot 0x4c(o); s[0xb]: ax = tab->slot 0x114(0x68cf34, 0, 0x68cee8, 0x67, y) else (0x68cf40, 0, 0x68cee8, 0x69, y); o->slot 0x130(E[4], (u16)ax).
static void THISCALL fn487490(u8 *E, u8 *s) {
  u8 *o = (*(v0o_t **)s)[8 / 4](s);
  if (s[0xa]) {
    u8 *t = tabOf();
    u32 ax = (*(v5u_t **)t)[0x114 / 4](t, 0x68cf28u, 0, 0x68cee8u, 0x60, 0);
    (*(v2_t **)o)[0x130 / 4](o, rd(E + 4), (u16)ax);
  }
  u8 *t = tabOf();
  void **vo = *(void ***)o;
  u32 y = (*(v1u_t **)t)[0x4c / 4](t, (u32)o);
  u32 ax;
  if (s[0xb]) ax = (*(v5u_t **)t)[0x114 / 4](t, 0x68cf34u, 0, 0x68cee8u, 0x67, y);
  else ax = (*(v5u_t **)t)[0x114 / 4](t, 0x68cf40u, 0, 0x68cee8u, 0x69, y);
  ((v2_t)vo[0x130 / 4])(o, rd(E + 4), (u16)ax);
}
PCREG(487490, fn487490);

// 0x497210, thiscall(p) ret 4 (this = E): k = p[0x59], 0 returns; ent = E[0x40] + (k - 1) * 12; first = ent[4], cnt = ent[8]; key = [0x6ffa9c]; table entries of 8 bytes at E[0x44] + first * 8:
// first match of dword key within cnt entries: ent2[4]++, p[0x59] = 0, E->slot 0x18(p); no match: logs (0x68e36c, 0xb59, 0x68e5b0, key, E[0x40][k * 3] (dword)).
static void THISCALL fn497210(u8 *E, u8 *p) {
  u8 k = p[0x59];
  if (!k) return;
  u8 *ent = *(u8 **)(E + 0x40) + (u32)(k * 3 - 3) * 4;
  u32 first = rd(ent + 4);
  u32 cnt = rd(ent + 8);
  u32 key = G(u32, 0x6ffa9c);
  u8 *q = *(u8 **)(E + 0x44) + first * 8;
  u32 i = 0;
  if (cnt != 0) {
    do {
      if (rd(q) == key) {
        wr(q + 4, rd(q + 4) + 1);
        p[0x59] = 0;
        (*(v1_t **)E)[0x18 / 4](E, (u32)p);
        return;
      }
      i++;
      q += 8;
    } while (i != cnt);
  }
  u8 *db = G(u8 *, 0x700390);
  u8 *o = (*(v2o_t **)db)[0x20 / 4](db, 0x68e36cu, 0xb59u);
  void **vt2 = *(void ***)o;
  void *fn = *(void **)((u8 *)vt2 + 0x2c);
  u32 last = rd(*(u8 **)(E + 0x40) + (u32)(p[0x59] * 3) * 4);
  __asm__ volatile("pushl %[l]\n\tpushl %[k]\n\tpushl $0x68e5b0\n\tpushl %[o]\n\tcall *%[f]\n\taddl $16, %%esp"
                   : "+c"(vt2) : [l] "r"(last), [k] "r"(key), [o] "r"(o), [f] "r"(fn) : "eax", "edx", "memory", "cc");
}
PCREG(497210, fn497210);

extern "C" u32 THISCALL ext_4e1590(void *self);  // plain ret

// 0x4e1070, thiscall(buf) ret 4 (this = E): p = E[8]; unless (p[0] != 0xff and (p[0] & 0x3f) is 4 or 5): assert hook, then db->slot 0x24(db, 0x6970f8) cdecl.
// Copies the string at p + 1 (with its NUL) into buf, then E[8] += 0x4e1590(E) + 1.
static void THISCALL fn4e1070(u8 *E, u8 *buf) {
  u8 *p = *(u8 **)(E + 8);
  u8 a = p[0];
  bool ok = (a != 0xff && (a & 0x3f) == 4) || (a != 0xff && (a & 0x3f) == 5);
  if (!ok) {
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
    u8 *db = G(u8 *, 0x700390);
    void **vt = *(void ***)db;
    void *fn = vt[0x24 / 4];
    void *vtc = (void *)vt;
    __asm__ volatile("pushl $0x6970f8\n\tpushl %[o]\n\tcall *%[f]\n\taddl $8, %%esp"
                     : "+c"(vtc) : [o] "r"(db), [f] "r"(fn) : "eax", "edx", "memory", "cc");
  }
  p = *(u8 **)(E + 8);
  const u8 *src = p + 1;
  u8 *dst = buf;
  u8 c;
  do {
    c = *src++;
    *dst++ = c;
  } while (c != 0);
  u32 n = ext_4e1590(E);
  wr(E + 8, rd(E + 8) + n + 1);
}
PCREG(4e1070, fn4e1070);

extern "C" u8 *THISCALL ext_5003d0(void *self, u32 a);   // ret 4
extern "C" void THISCALL ext_5002f0(void *self, u32 a);  // ret 4

// 0x50e7f0, stdcall(a) ret 4: s = a[0xc]->slot 0(0x67a14c, 0); obj = tab->slot 0x58(0x5003d0(a[4], 0)[0]); name = obj and q = obj->slot 0x20() ? (obj->slot 0x20()[4] ? : 0x67c8e8) : 0x67c8e8;
// s->slot 0x30(name); r = 0x5003d0(a[8], 0): r[4] == 0 or 4: (4: r[0]->slot 0x28()), r[0] = s->slot 0x24(), r[4] = 4. Finally s->slot 0x28().
static void STDCALL fn50e7f0(u8 *a) {
  u8 *c = *(u8 **)(a + 0xc);
  u8 *s = (*(v2o_t **)c)[0](c, 0x67a14cu, 0);
  u8 *rec = ext_5003d0(*(u8 **)(a + 4), 0);
  u8 *t = tabOf();
  u8 *obj = (*(v1o_t **)t)[0x58 / 4](t, rd(rec));
  u32 name = 0x67c8e8;
  if (obj) {
    u8 *q = (*(v0o_t **)obj)[0x20 / 4](obj);
    if (q) {
      u8 *q2 = (*(v0o_t **)obj)[0x20 / 4](obj);
      u32 nm = rd(q2 + 4);
      name = nm ? nm : 0x67c8e8;
    }
  }
  (*(v1_t **)s)[0x30 / 4](s, name);
  u8 *r = ext_5003d0(*(u8 **)(a + 8), 0);
  u8 k = r[4];
  if (k == 0 || k == 4) {
    if (k == 4) {
      u8 *old = *(u8 **)r;
      (*(v0_t **)old)[0x28 / 4](old);
    }
    wr(r, (u32)(*(v0o_t **)s)[0x24 / 4](s));
    r[4] = 4;
  }
  (*(v0_t **)s)[0x28 / 4](s);
}
PCREG(50e7f0, fn50e7f0);

// 0x50f120, stdcall(a) ret 4: obj = tab->slot 0x58(0x5003d0(a[4], 0)[0]); null: 0x5002f0(0x5003d0(a[8], 0), 0). Else x = obj->slot 0x20(); y = tab->slot 0x4c(x); r = 0x5003d0(a[8], 0);
// r[4] <= 1: r[0] = y, r[4] = 1; else log (0x69c8e0, 0xc4, 0x69c6b0, 0x69c938) and the assert hook (int3 when null).
static void STDCALL fn50f120(u8 *a) {
  u8 *rec = ext_5003d0(*(u8 **)(a + 4), 0);
  u8 *t = tabOf();
  u8 *obj = (*(v1o_t **)t)[0x58 / 4](t, rd(rec));
  if (!obj) {
    u8 *r3 = ext_5003d0(*(u8 **)(a + 8), 0);
    ext_5002f0(r3, 0);
    return;
  }
  void **tvt = *(void ***)t;
  u8 *x = (*(v0o_t **)obj)[0x20 / 4](obj);
  u8 *t2 = tabOf();
  u32 y = ((v1u_t)tvt[0x4c / 4])(t2, (u32)x);
  u8 *r2 = ext_5003d0(*(u8 **)(a + 8), 0);
  if (r2[4] <= 1) {
    wr(r2, y);
    r2[4] = 1;
    return;
  }
  u8 *db = G(u8 *, 0x700390);
  u8 *o = (*(v2o_t **)db)[0x20 / 4](db, 0x69c8e0u, 0xc4u);
  void **vt2 = *(void ***)o;
  void *fn = *(void **)((u8 *)vt2 + 0x2c);
  __asm__ volatile("pushl $0x69c938\n\tpushl $0x69c6b0\n\tpushl %[o]\n\tcall *%[f]\n\taddl $12, %%esp"
                   : "+c"(vt2) : [o] "r"(o), [f] "r"(fn) : "eax", "edx", "memory", "cc");
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
}
PCREG(50f120, fn50f120);
