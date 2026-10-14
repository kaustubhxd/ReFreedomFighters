// batch36031.cpp - cascade s4 batch 36031: 0x64d880, 0x5cdb70, 0x4c85f0, 0x438a60 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v0_t)(void *);
typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);
typedef u32(THISCALL *v0r_t)(void *);
typedef u32(THISCALL *v1r_t)(void *, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

// 0x64d880, thiscall(p) ret 4 (this = E): same as 0x63f6b0 but the block record size is 0x34: E[0xc]--; b = E->slot 0x2c(p); p[0..1] = u16 b[2]; b[0]--; b[2..3] = (u16)(((s32)(p - b) - 0x10) / 0x34).
// b[0] == 0: when E[8] == b: E[8] = (b[8] == b ? 0 : b[8]); unlink b from its ring; E->slot 0x34(b). b[0] != 0 and b != E[8]: unlink b and relink it as the new head (E[8]) of the ring.
static void THISCALL fn64d880(u8 *E, u8 *p) {
  wr(E + 0xc, rd(E + 0xc) - 1);
  u8 *b = (*(v1o_t **)E)[0x2c / 4](E, (u32)p);
  u16 cx = *(u16 *)(b + 2);
  b[0]--;
  *(u16 *)p = cx;
  s32 d = (s32)((u32)p - (u32)b) - 0x10;
  *(u16 *)(b + 2) = (u16)(d / 0x34);
  if (b[0] == 0) {
    if (*(u8 **)(E + 8) == b) {
      u8 *n = *(u8 **)(b + 8);
      if (n == b) n = 0;
      *(u8 **)(E + 8) = n;
    }
    u8 *n1 = *(u8 **)(b + 8);
    wr(n1 + 0xc, rd(b + 0xc));
    u8 *n2 = *(u8 **)(b + 0xc);
    wr(n2 + 8, rd(b + 8));
    (*(v1_t **)E)[0x34 / 4](E, (u32)b);
    return;
  }
  if (b == *(u8 **)(E + 8)) return;
  u8 *n1 = *(u8 **)(b + 8);
  wr(n1 + 0xc, rd(b + 0xc));
  u8 *n2 = *(u8 **)(b + 0xc);
  wr(n2 + 8, rd(b + 8));
  u8 *head = *(u8 **)(E + 8);
  wr(b + 8, (u32)head);
  u8 *tail = *(u8 **)(head + 0xc);
  wr(b + 0xc, (u32)tail);
  wr(tail + 8, (u32)b);
  wr(head + 0xc, (u32)b);
  wr(E + 8, (u32)b);
}
PCREG(64d880, fn64d880);

extern "C" void THISCALL ext_5cf420(void *s, u32 a);   // ret 4
extern "C" void THISCALL ext_5cdab0(void *s);
extern "C" void THISCALL ext_5ceb30(void *s);
extern "C" void THISCALL ext_5ceb70(void *s);
extern "C" void THISCALL ext_5cff20(void *s);
extern "C" void THISCALL ext_5d0080(void *s);
extern "C" void THISCALL ext_5cecd0(void *s);

// 0x5cdb70, thiscall() (this = s): e = s[0x44]; e->slot 0x80(s + 0xcdd, s + 0xd01); 0x5cf420(s, s + 0xd22);
// o = sys[0x9b]->slot 0x58(s[0xc6d]); o->slot 0x80(s + 0xcb9, s + 0xcad); e[0x64b] = 4; s->slot 0x84();
// s[0xdd8] == 0 and !e->slot 0x438(): switch s[0xe1c]: 0 -> 0x5cdab0, 1 -> 0x5ceb70, 3 -> 0x5ceb30.
// then: e->slot 0x438() (low byte) != 0 -> tail 0x5cff20; else s[0xdd8] != 0 -> 0x5d0080 else 0x5cecd0.
static void THISCALL fn5cdb70(u8 *s) {
  u8 *e = *(u8 **)(s + 0x44);
  (*(v2_t **)e)[0x80 / 4](e, (u32)(s + 0xcdd), (u32)(s + 0xd01));
  ext_5cf420(s, (u32)(s + 0xd22));
  u8 *rm = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *o = (*(v1o_t **)rm)[0x58 / 4](rm, rd(s + 0xc6d));
  (*(v2_t **)o)[0x80 / 4](o, (u32)(s + 0xcb9), (u32)(s + 0xcad));
  wr(e + 0x64b, 4);
  (*(v0_t **)s)[0x84 / 4](s);
  if (s[0xdd8] == 0) {
    if (((u8)(*(v0r_t **)e)[0x438 / 4](e)) == 0) {
      u32 m = rd(s + 0xe1c);
      if (m == 0) ext_5cdab0(s);
      else if (m == 1) ext_5ceb70(s);
      else if (m == 3) ext_5ceb30(s);
    }
  }
  if ((u8)(*(v0r_t **)e)[0x438 / 4](e)) {
    ext_5cff20(s);
    return;
  }
  if (s[0xdd8]) ext_5d0080(s);
  else ext_5cecd0(s);
}
PCREG(5cdb70, fn5cdb70);

extern "C" void THISCALL ext_4daa20(void *node, u32 flag);   // ret 4

// 0x4c85f0, thiscall() (this = s): s[0x51] = (s[0x51] == 0); for each node of sys[0x9b][0xadc] (first = list[8], next via list->slot 0x50(&cur)):
// flags = node[0x54] ? node[0x54][0xc][0x23] : 0x200002; if flags & 0x800000: 0x4daa20(node, s[0x51]).
// sys[0x9b][0xbad] = s[0x51]; logger->slot 0x20(file 0x694ad8, line) prints (cdecl) 0x694c44 (line 0x2a4) when s[0x51] != 0, else 0x694c58 (line 0x2a6).
static void THISCALL fn4c85f0(u8 *s) {
  s[0x51] = (s[0x51] == 0);
  u8 *lst = *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x9b) + 0xadc);
  u32 cur = rd(lst + 8);
  while (cur) {
    u8 *x = *(u8 **)(cur + 0x54);
    u32 fl;
    if (x) fl = rd(*(u8 **)(x + 0xc) + 0x23);
    else fl = 0x200002;
    if (fl & 0x800000) ext_4daa20((void *)cur, s[0x51]);
    u8 *l2 = *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x9b) + 0xadc);
    (*(v1_t **)l2)[0x50 / 4](l2, (u32)&cur);
  }
  *(*(u8 **)(G(u8 *, 0x70039c) + 0x9b) + 0xbad) = s[0x51];
  u8 *db = G(u8 *, 0x700390);
  u8 *o;
  void *fn;
  if (s[0x51]) {
    o = (*(v2o_t **)db)[0x20 / 4](db, 0x694ad8u, 0x2a4u);
    fn = *(void **)((u8 *)*(void ***)o + 0x2c);
    ((void (*)(u8 *, u32))fn)(o, 0x694c44u);
  } else {
    o = (*(v2o_t **)db)[0x20 / 4](db, 0x694ad8u, 0x2a6u);
    fn = *(void **)((u8 *)*(void ***)o + 0x2c);
    ((void (*)(u8 *, u32))fn)(o, 0x694c58u);
  }
}
PCREG(4c85f0, fn4c85f0);

extern "C" u8 *THISCALL ext_438c30(void *s);

// 0x438a60, thiscall() (this = s): o = s[0xd]; if o: iterate o (slot 0x4c(&it) begin, slot 0x5c(&it) -> idx while it[0]); each idx: row = ext_438c30(s)[0x11][0x1344] + idx * 10;
// walk the list at row[4] (nodes: [0] record, [5] next): drop every node whose record == s with *record == 2 (unlink; prev stays). Finally: if s[0xd]: slot 0 (delete, 1); s[0xd] = 0.
static void THISCALL fn438a60(u8 *s) {
  u8 *o = *(u8 **)(s + 0xd);
  if (o) {
    u32 it[3];
    (*(v1_t **)o)[0x4c / 4](o, (u32)it);
    u8 *o2 = *(u8 **)(s + 0xd);
    u32 idx = (*(v1r_t **)o2)[0x5c / 4](o2, (u32)it);
    if (it[0] != 0) {
      do {
        u8 *w = ext_438c30(s);
        u8 *row = *(u8 **)(*(u8 **)(w + 0x11) + 0x1344) + idx * 10;
        u8 *prev = 0;
        u8 *n = *(u8 **)(row + 4);
        while (n) {
          u8 *rec = *(u8 **)n;
          if (rd(rec) == 2 && rec == s) {
            n = *(u8 **)(n + 5);
            if (prev) wr(prev + 5, (u32)n);
            else wr(row + 4, (u32)n);
          } else {
            prev = n;
            n = *(u8 **)(n + 5);
          }
        }
        u8 *o3 = *(u8 **)(s + 0xd);
        idx = (*(v1r_t **)o3)[0x5c / 4](o3, (u32)it);
      } while (it[0] != 0);
    }
  }
  u8 *o4 = *(u8 **)(s + 0xd);
  if (o4) {
    (*(v1_t **)o4)[0](o4, 1);
    wr(s + 0xd, 0);
  }
}
PCREG(438a60, fn438a60);
