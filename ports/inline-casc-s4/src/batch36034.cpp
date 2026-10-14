// batch36034.cpp - cascade s4 batch 36034: 0x575800, 0x576260, 0x5f07a0, 0x5fe240, 0x5fe300 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v0_t)(void *);
typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef u8 *(THISCALL *v0o_t)(void *);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);
typedef u32(THISCALL *v0r_t)(void *);
typedef u32(THISCALL *v5r_t)(void *, u32, u32, u32, u32, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

// 0x575800, thiscall() returns al (this = s): w = s->slot 0x84(); v = w->slot 0x2f0(); find i < 5 with v == s[0x224 + i * 0x24]; none -> 0.
// name = v[4] or the exe string 0x67c8e8; e = s[0x44]; ax = tab->slot 0x114(0x6a77a0, 0, 0x6a9298, 0x144, name); e->slot 0x12c(s[0x212], ax);
// again with (0x6a9300, 0, 0x6a9298, 0x145, 0); then s->slot 0x84()->slot 0x2f8(s[0x212]); return 1.
static u8 THISCALL fn575800(u8 *s) {
  u8 *w = (*(v0o_t **)s)[0x84 / 4](s);
  u32 v = (*(v0r_t **)w)[0x2f0 / 4](w);
  u32 i = 0;
  u8 *ent = s + 0x224;
  for (;;) {
    if (v == rd(ent)) break;
    i++;
    ent += 0x24;
    if (i >= 5) return 0;
  }
  u32 name = rd((u8 *)v + 4);
  if (name == 0) name = 0x67c8e8;
  u8 *e = *(u8 **)(s + 0x44);
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 ax = (u16)(*(v5r_t **)tab)[0x114 / 4](tab, 0x6a77a0u, 0, 0x6a9298u, 0x144u, name);
  e = *(u8 **)(s + 0x44);
  (*(v2_t **)e)[0x12c / 4](e, rd(s + 0x212), ax);
  e = *(u8 **)(s + 0x44);
  tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  ax = (u16)(*(v5r_t **)tab)[0x114 / 4](tab, 0x6a9300u, 0, 0x6a9298u, 0x145u, 0);
  (*(v2_t **)e)[0x12c / 4](e, rd(s + 0x212), ax);
  w = (*(v0o_t **)s)[0x84 / 4](s);
  (*(v1_t **)w)[0x2f8 / 4](w, rd(s + 0x212));
  return 1;
}
PCREG(575800, fn575800);

extern "C" void THISCALL ext_562440(void *self);

static bool same_str(const u8 *x, const u8 *y) {
  for (;;) {
    if (*x != *y) return false;
    if (*x == 0) return true;
    x++;
    y++;
  }
}

// 0x576260, thiscall() (this = b): inverted twin of 0x575160 (does the calls when the name matches, returns otherwise): 0x562440(b); e = b[0x94]; name = e + 0x48.
// name == str 0x6a6e5c and e[0x1040] == 0, or name == str 0x6a8558: o = sys[0x9b]->slot 0x138(); x = sys[0x9b]->slot 0x4c(b[0x44], 0x10); o->slot 0x60(0x6a6db0, x). Otherwise return.
static void THISCALL fn576260(u8 *b) {
  ext_562440(b);
  u8 *e = *(u8 **)(b + 0x94);
  u8 *name = e + 0x48;
  bool go = same_str(name, (const u8 *)0x6a6e5c) && e[0x1040] == 0;
  if (!go && !same_str(name, (const u8 *)0x6a8558)) return;
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *o = (*(v0o_t **)tab)[0x138 / 4](tab);
  tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *x = (*(v2o_t **)tab)[0x4c / 4](tab, rd(b + 0x44), 0x10);
  (*(v2_t **)o)[0x60 / 4](o, 0x6a6db0u, (u32)x);
}
PCREG(576260, fn576260);

extern "C" void THISCALL ext_5ac940(void *self, u32 a);   // ret 4
extern "C" u32 THISCALL ext_5ab9d0(void *self);           // plain ret
extern "C" void THISCALL ext_5ac620(void *self, u32 a, u32 b);   // ret 8

// 0x5f07a0, thiscall(a, b) ret 8 (this = s): s[0x74] = 0; entries of 12 bytes at s[0x7c] + s[0x88] * 12 up to s[0x80], at most 0x1c: with k = s[0x74] (objects at s[4 + k * 4]):
// type 0: 0x5ac940(obj, e[1]), X = 0; type 1: 0x5ac940, X = -5 - (0x5ab9d0(obj) >> 1); type 2: 0x5ac940, X = (0x5ab9d0(obj) >> 1) + 5; other types: skipped.
// then 0x5ac620(obj, 3, X); obj->slot 4(a, b); s[0x74]++.
static void THISCALL fn5f07a0(u8 *s, u32 a, u32 b) {
  u32 n = 0;
  wr(s + 0x74, 0);
  u8 *e = *(u8 **)(s + 0x7c) + rd(s + 0x88) * 12;
  while (e != *(u8 **)(s + 0x80)) {
    u32 k = rd(s + 0x74);
    if (k != 0x1c) {
      u32 t = rd(e);
      u32 x;
      bool ok = true;
      if (t == 0) {
        ext_5ac940(*(u8 **)(s + k * 4 + 4), rd(e + 4));
        x = 0;
      } else if (t == 1) {
        ext_5ac940(*(u8 **)(s + k * 4 + 4), rd(e + 4));
        u32 w = ext_5ab9d0(*(u8 **)(s + rd(s + 0x74) * 4 + 4)) >> 1;
        x = 0xfffffffbu - w;
      } else if (t == 2) {
        ext_5ac940(*(u8 **)(s + k * 4 + 4), rd(e + 4));
        u32 w = ext_5ab9d0(*(u8 **)(s + rd(s + 0x74) * 4 + 4)) >> 1;
        x = w + 5;
      } else {
        ok = false;
        x = 0;
      }
      if (ok) {
        ext_5ac620(*(u8 **)(s + rd(s + 0x74) * 4 + 4), 3, x);
        u8 *o = *(u8 **)(s + rd(s + 0x74) * 4 + 4);
        (*(v2_t **)o)[4 / 4](o, a, b);
        wr(s + 0x74, rd(s + 0x74) + 1);
      }
    }
    n++;
    e += 0xc;
    if (n >= 0x1c) break;
  }
}
PCREG(5f07a0, fn5f07a0);

extern "C" u8 *STDCALL ext_6014a0(u32 n);                  // alloc, ret 4
extern "C" void FASTCALL ext_430480(u8 *node, u8 *root1);  // plain ret

// 0x5fe240, thiscall(out, flag, parent, key) ret 0x10 (this = T, T[0] = head, T[4] = count): tree node insert with a 6-byte key (u32 + u16 at node + 0xd), node size 0x13.
// parent != head and flag == 0 and (u16)*key >= (u16)parent[0xd]: node = alloc, parent[9] = node; head[9] == parent -> head[9] = node. Otherwise: parent[5] = node; parent == head: head[1] = node, head[9] = node; else head[5] == parent: head[5] = node.
// then node[1] = parent, node[5] = node[9] = 0, 0x430480(node, head + 1), T[4]++, *out = node.
static void THISCALL fn5fe240(u8 *T, u32 *out, u32 flag, u8 *parent, u16 *key) {
  u8 *node;
  if (parent != *(u8 **)T && flag == 0 && *key >= *(u16 *)(parent + 0xd)) {
    node = ext_6014a0(0x13);
    if (node + 0xd) {
      wr(node + 0xd, *(u32 *)key);
      *(u16 *)(node + 0x11) = key[2];
    }
    wr(parent + 9, (u32)node);
    u8 *head = *(u8 **)T;
    if (parent == *(u8 **)(head + 9)) wr(head + 9, (u32)node);
  } else {
    node = ext_6014a0(0x13);
    if (node + 0xd) {
      wr(node + 0xd, *(u32 *)key);
      *(u16 *)(node + 0x11) = key[2];
    }
    wr(parent + 5, (u32)node);
    u8 *head = *(u8 **)T;
    if (parent == head) {
      wr(head + 1, (u32)node);
      head = *(u8 **)T;
      wr(head + 9, (u32)node);
    } else if (parent == *(u8 **)(head + 5)) {
      wr(head + 5, (u32)node);
    }
  }
  wr(node + 1, (u32)parent);
  wr(node + 5, 0);
  wr(node + 9, 0);
  ext_430480(node, *(u8 **)T + 1);
  wr(T + 4, rd(T + 4) + 1);
  *out = (u32)node;
}
PCREG(5fe240, fn5fe240);

// 0x5fe300: same as 0x5fe240 with an 8-byte key (two u32, node size 0x15, unsigned dword compare of *key with parent[0xd]).
static void THISCALL fn5fe300(u8 *T, u32 *out, u32 flag, u8 *parent, u32 *key) {
  u8 *node;
  if (parent != *(u8 **)T && flag == 0 && key[0] >= rd(parent + 0xd)) {
    node = ext_6014a0(0x15);
    if (node + 0xd) {
      wr(node + 0xd, key[0]);
      wr(node + 0x11, key[1]);
    }
    wr(parent + 9, (u32)node);
    u8 *head = *(u8 **)T;
    if (parent == *(u8 **)(head + 9)) wr(head + 9, (u32)node);
  } else {
    node = ext_6014a0(0x15);
    if (node + 0xd) {
      wr(node + 0xd, key[0]);
      wr(node + 0x11, key[1]);
    }
    wr(parent + 5, (u32)node);
    u8 *head = *(u8 **)T;
    if (parent == head) {
      wr(head + 1, (u32)node);
      head = *(u8 **)T;
      wr(head + 9, (u32)node);
    } else if (parent == *(u8 **)(head + 5)) {
      wr(head + 5, (u32)node);
    }
  }
  wr(node + 1, (u32)parent);
  wr(node + 5, 0);
  wr(node + 9, 0);
  ext_430480(node, *(u8 **)T + 1);
  wr(T + 4, rd(T + 4) + 1);
  *out = (u32)node;
}
PCREG(5fe300, fn5fe300);
