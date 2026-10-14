// batch36023.cpp - cascade s4 batch 36023: 0x57ad40, 0x57e400, 0x5b9560, 0x6006e0, 0x620cb0 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v0_t)(void *);
typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef void(THISCALL *v3_t)(void *, u32, u32, u32);
typedef u32(THISCALL *v0u_t)(void *);
typedef u32(THISCALL *v1u_t)(void *, u32);
typedef u8(THISCALL *v1b_t)(void *, u32);
typedef u8(THISCALL *v2b_t)(void *, u32, u32);
typedef u8 *(THISCALL *v0o_t)(void *);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);
typedef void(THISCALL *v5_t)(void *, u32, u32, u32, u32, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" void THISCALL ext_562440(void *self);            // plain ret
extern "C" void THISCALL ext_563510(void *self, u32 a);     // ret 4
typedef int(*atoi_t)(const char *);

// 0x57ad40, thiscall(no args) (this = E): 0x562440(E); 0x563510(E, 0x6a6850); ok = [0x70039c]->slot 0x5c(0x6a7584, &s); limit = ok ? atoi(s) : 0;
// list = E[0x54]->slot 0x25c(0x6a7590, 0)[0x50]; for each node n (via +0x60): t = n[0x54]; stops unless flags(t) has 0x100000 (flags = t ? t[0xc][0x23] : 0x200002);
// t->slot 0x1e0(0x100033): r = t->slot 0x310() signed < limit: t->slot 0x2dc().
static void THISCALL fn57ad40(u8 *E) {
  u32 loc;
  ext_562440(E);
  ext_563510(E, 0x6a6850);
  u8 *eng = G(u8 *, 0x70039c);
  s32 limit = 0;
  if ((*(v2b_t **)eng)[0x5c / 4](eng, 0x6a7584, (u32)&loc)) limit = G(atoi_t, 0x6762d8)((const char *)loc);
  u8 *c = *(u8 **)(E + 0x54);
  u8 *lst = (*(v2o_t **)c)[0x25c / 4](c, 0x6a7590, 0);
  u8 *n = *(u8 **)(lst + 0x50);
  while (n) {
    u8 *t = *(u8 **)(n + 0x54);
    u32 fl = t ? rd(*(u8 **)(t + 0xc) + 0x23) : 0x200002u;
    if (!(fl & 0x100000u)) break;
    if ((*(v1b_t **)t)[0x1e0 / 4](t, 0x100033u)) {
      u8 *o = *(u8 **)(n + 0x54);
      s32 r = (s32)(*(v0u_t **)o)[0x310 / 4](o);
      if (r < limit) (*(v0_t **)o)[0x2dc / 4](o);
    }
    n = *(u8 **)(n + 0x60);
  }
}
PCREG(57ad40, fn57ad40);

extern "C" void THISCALL ext_563110(void *self, u32 a, u32 b);  // ret 8
extern "C" void THISCALL ext_57f130(void *self, u32 a);         // ret 4

// 0x57e400, thiscall(a, b) ret 8, returns 0 (this = E): 0x563110(E, a, b); o = [[0x70039c]+0x1907 (unaligned)]: o->slot 0xc(0x6ece54, 0x6aad90, 0) when non-null;
// x = [eng+0x1907]->slot 0x60(0x6aad90) -> E[0x320]; E[0x324] = x->slot 0x14(0x6aab3c); E[0x328] = E[0x320]->slot 0x14(0x6aab50); E[0x314], E[0x310]->slot 0xbc(0); E[0x18c]->slot 0xbc(1);
// E[0x349] = 0; w = E->slot 0x84(); w->slot 0x34c(0x100000, 0, E[0x44], 10.0f, 0); 0x57f130(E, 1).
static u32 THISCALL fn57e400(u8 *E, u32 a, u32 b) {
  ext_563110(E, a, b);
  u8 *eng = G(u8 *, 0x70039c);
  u8 *o = *(u8 **)(eng + 0x1907);
  if (o) (*(v3_t **)o)[0xc / 4](o, 0x6ece54, 0x6aad90, 0);
  eng = G(u8 *, 0x70039c);
  o = *(u8 **)(eng + 0x1907);
  u8 *x = (*(v1o_t **)o)[0x60 / 4](o, 0x6aad90);
  wr(E + 0x320, (u32)x);
  wr(E + 0x324, (*(v1u_t **)x)[0x14 / 4](x, 0x6aab3c));
  x = *(u8 **)(E + 0x320);
  wr(E + 0x328, (*(v1u_t **)x)[0x14 / 4](x, 0x6aab50));
  u8 *p = *(u8 **)(E + 0x314);
  (*(v1_t **)p)[0xbc / 4](p, 0);
  p = *(u8 **)(E + 0x310);
  (*(v1_t **)p)[0xbc / 4](p, 0);
  p = *(u8 **)(E + 0x18c);
  (*(v1_t **)p)[0xbc / 4](p, 1);
  E[0x349] = 0;
  u8 *w = (*(v0o_t **)E)[0x84 / 4](E);
  (*(v5_t **)w)[0x34c / 4](w, 0x100000, 0, rd(E + 0x44), 0x41200000, 0);
  ext_57f130(E, 1);
  return 0;
}
PCREG(57e400, fn57e400);

// 0x5b9560, stdcall(list, key) ret 8, returns the element after `key` in the list (slots 0x4c/0x5c iteration): key == 0 returns the first element; a key that was the last element wraps to the first;
// a missing key or a missing list returns 0.
static u32 STDCALL fn5b9560(u8 *a, u32 key) {
  u32 loc[3];
  u32 esi = key;
  u32 r = 0;
  bool walked = false;
  if (a) {
    (*(v1_t **)a)[0x4c / 4](a, (u32)loc);
    r = (*(v1u_t **)a)[0x5c / 4](a, (u32)loc);
    if (loc[0] != 0) {
      walked = true;
      for (;;) {
        if (!esi) return r;
        esi = (r != esi) ? esi : 0;
        r = (*(v1u_t **)a)[0x5c / 4](a, (u32)loc);
        if (loc[0] == 0) break;
      }
    }
  }
  if (!walked) esi = key;
  if (esi != 0) return 0;
  if (!a) return 0;
  u32 loc2[3];
  (*(v1_t **)a)[0x4c / 4](a, (u32)loc2);
  r = (*(v1u_t **)a)[0x5c / 4](a, (u32)loc2);
  return loc2[0] != 0 ? r : 0;
}
PCREG(5b9560, fn5b9560);

extern "C" u32 *THISCALL ext_5fe300(void *self, u32 **slot, u32 esi, u32 parent, u32 *key);  // ret 0x10
extern "C" void THISCALL ext_42ffc0(void *self_slot);                                         // plain ret (ecx = iterator slot)

// 0x6006e0, thiscall(out, key) ret 8 (this = T, T[0] = head): unique-key insert into a binary tree: head[1] = root, node[5] = left, node[9] = right, node[0xd] = key (all unaligned).
// Finds parent and side (go_left = *key < node.key); go_left and parent == head[5] (leftmost): insert; go_left otherwise: it = predecessor via 0x42ffc0; it.key < *key inserts, else duplicate.
// Right side: parent.key < *key inserts, else duplicate. Insert: out[0] = *0x5fe300(T, &cur (the iterator slot), 0, parent, key), out[4] = 1; duplicate: out[0] = node, out[4] = 0.
static void THISCALL fn6006e0(u8 *T, u8 *out, u32 *key) {
  u8 *head = *(u8 **)T;
  u8 *parent = head;
  u8 *n = *(u8 **)(head + 1);
  bool left = true;
  if (n) {
    do {
      left = *key < rd(n + 0xd);
      parent = n;
      n = left ? *(u8 **)(n + 5) : *(u8 **)(n + 9);
    } while (n);
  }
  u8 *cur = parent;
  bool insert;
  if (left) {
    if (parent == *(u8 **)(head + 5)) {
      insert = true;
    } else {
      ext_42ffc0(&cur);
      insert = rd(cur + 0xd) < *key;
    }
  } else {
    insert = rd(cur + 0xd) < *key;
  }
  if (insert) {
    u32 *r = ext_5fe300(T, (u32 **)&cur, 0, (u32)parent, key);
    wr(out, *r);
    out[4] = 1;
    return;
  }
  wr(out, (u32)cur);
  out[4] = 0;
}
PCREG(6006e0, fn6006e0);

typedef void (*cb3_t)(u32, u32, u32);
typedef void (*cb5_t)(u32, u32, u32, u32, u32);

// 0x620cb0, cdecl(A, obj, B, C): obj[0x48] set: A[0x50](A[4], B, C - B). Else repeat: tgt = (obj == A[0x8c]) ? A+0x118 (slot A+0x11c) : A[0x124] (slot +4); local = A[0x2c];
// obj[0x3c](obj, &B, C, &local, A[0x30]); *slot = B; A[0x50](A[4], A[0x2c], local - A[0x2c]); *tgt = B; until B == C.
static void fn620cb0(u8 *A, u8 *obj, u32 B, u32 C) {
  if (obj[0x48] != 0) {
    (*(cb3_t *)(A + 0x50))(rd(A + 4), B, C - B);
    return;
  }
  u8 *tgt;
  u8 *slot;
  if (obj == *(u8 **)(A + 0x8c)) {
    tgt = A + 0x118;
    slot = A + 0x11c;
  } else {
    tgt = *(u8 **)(A + 0x124);
    slot = tgt + 4;
  }
  u32 local;
  do {
    local = rd(A + 0x2c);
    (*(cb5_t *)(obj + 0x3c))((u32)obj, (u32)&B, C, (u32)&local, rd(A + 0x30));
    wr(slot, B);
    (*(cb3_t *)(A + 0x50))(rd(A + 4), rd(A + 0x2c), local - rd(A + 0x2c));
    wr(tgt, B);
  } while (B != C);
}
PCREG(620cb0, fn620cb0);
