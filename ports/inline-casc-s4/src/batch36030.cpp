// batch36030.cpp - cascade s4 batch 36030: 0x59e730, 0x6004a0, 0x606940, 0x63f6b0, 0x61fb10 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);
typedef u8 *(THISCALL *v1o_t)(void *, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" void THISCALL ext_5a3690(void *self, u32 a, u32 b);  // ret 8

// 0x59e730, thiscall(a, b) ret 8 (this = E): entries of 16 bytes at E+0x7d2 (count u32 at E+0x7ce). first = first entry with b <= v <= a (signed); from that position on, last = first entry with v > a (or the end).
// first found: 0x5a3690(E + 0x7ce, index(first), index(last)).
static void THISCALL fn59e730(u8 *E, s32 a, s32 b) {
  u8 *base = E + 0x7ce;
  u8 *end = base + 4 + rd(base) * 16;
  u8 *first = 0;
  u8 *p = E + 0x7d2;
  if (p != end) {
    for (;;) {
      s32 v = *(s32 *)p;
      if (v >= b && v <= a) {
        first = p;
        break;
      }
      p += 0x10;
      if (p == end) break;
    }
  }
  u8 *last = end;
  if (p != end) {
    for (;;) {
      if (*(s32 *)p > a) {
        last = p;
        break;
      }
      p += 0x10;
      if (p == end) break;
    }
  }
  if (first) ext_5a3690(base, (u32)(((s32)(first - base) - 4) >> 4), (u32)(((s32)(last - base) - 4) >> 4));
}
PCREG(59e730, fn59e730);

extern "C" u32 *THISCALL ext_5fe240(void *self, u32 **slot, u32 esi, u32 parent, u16 *key);  // ret 0x10
extern "C" void THISCALL ext_42ffc0(void *self_slot);                                         // plain ret (ecx = iterator slot)

// 0x6004a0, thiscall(out, key) ret 8 (this = T, T[0] = head): same unique insert as 0x6006e0 but with 16-bit keys (u16 at node+0xd, *key as u16, unsigned 16-bit compares) and the creator 0x5fe240.
static void THISCALL fn6004a0(u8 *T, u8 *out, u16 *key) {
  u8 *head = *(u8 **)T;
  u8 *parent = head;
  u8 *n = *(u8 **)(head + 1);
  bool left = true;
  if (n) {
    do {
      left = *key < *(u16 *)(n + 0xd);
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
      insert = *(u16 *)(cur + 0xd) < *key;
    }
  } else {
    insert = *(u16 *)(cur + 0xd) < *key;
  }
  if (insert) {
    u32 *r = ext_5fe240(T, (u32 **)&cur, 0, (u32)parent, key);
    wr(out, *r);
    out[4] = 1;
    return;
  }
  wr(out, (u32)cur);
  out[4] = 0;
}
PCREG(6004a0, fn6004a0);

extern "C" void *ext_634d22(void *dst, const void *src, u32 n);  // cdecl (memcpy thunk)
extern "C" void THISCALL ext_606230(void *self, void *block);    // ret 4

// 0x606940, thiscall(data, len) ret 8 (this = E): MD5-style update: bits = E[0x10]; idx = (bits >> 3) & 0x3f; E[0x10] += len * 8 (carry into E[0x14]); E[0x14] += len >> 29; room = 0x40 - idx.
// len >= room: memcpy(E + 0x18 + idx, data, room), 0x606230(E, E + 0x18), further whole 64-byte blocks straight from data through 0x606230, idx = 0; else room = 0 (skipped bytes).
// Finally memcpy(E + 0x18 + idx, data + done, len - done).
static void THISCALL fn606940(u8 *E, u8 *data, u32 len) {
  u32 bits = rd(E + 0x10);
  u32 idx = (bits >> 3) & 0x3f;
  u32 nb = bits + len * 8;
  wr(E + 0x10, nb);
  if (nb < len * 8) wr(E + 0x14, rd(E + 0x14) + 1);
  wr(E + 0x14, rd(E + 0x14) + (len >> 29));
  u32 done = 0x40 - idx;
  if (len >= done) {
    ext_634d22(E + 0x18 + idx, data, done);
    ext_606230(E, E + 0x18);
    u32 j = done + 0x3f;
    while (j < len) {
      ext_606230(E, data - 0x3f + j);
      j += 0x40;
      done += 0x40;
    }
    idx = 0;
  } else {
    done = 0;
  }
  ext_634d22(E + 0x18 + idx, data + done, len - done);
}
PCREG(606940, fn606940);

// 0x63f6b0, thiscall(p) ret 4 (this = E): E[0xc]--; b = E->slot 0x2c(p); p[0..1] = u16 b[2]; b[0]--; b[2..3] = (u16)(((s32)(p - b) - 0x10) / 0x30). b[0] == 0: when E[8] == b: E[8] = (b[8] == b ? 0 : b[8]);
// unlink b from its ring; E->slot 0x34(b). b[0] != 0 and b != E[8]: unlink and relink b as the new head (E[8]) of the ring.
static void THISCALL fn63f6b0(u8 *E, u8 *p) {
  wr(E + 0xc, rd(E + 0xc) - 1);
  u8 *b = (*(v1o_t **)E)[0x2c / 4](E, (u32)p);
  u16 cx = *(u16 *)(b + 2);
  b[0]--;
  *(u16 *)p = cx;
  s32 d = (s32)((u32)p - (u32)b) - 0x10;
  *(u16 *)(b + 2) = (u16)(d / 0x30);
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
PCREG(63f6b0, fn63f6b0);

extern "C" u32 ext_620180(u8 *s, u32 a, u32 b, u32 c);       // cdecl
extern "C" u32 ext_6206e0(u8 *s);                            // cdecl
extern "C" u8 *ext_61fd60(u8 *tab, u32 key, u32 size);       // cdecl
extern "C" u32 ext_6210c0(u8 *A, u8 *node);                  // cdecl

// 0x61fb10, cdecl(A, b, c, d), returns eax: s = A + 0x1a8; 0x620180(s, b, c, d) zero -> 0; s[0xc] == s[8]: 0x6206e0(s) zero -> 0; *s[0xc] = 0, s[0xc]++; k = s[0x10] zero -> 0;
// p = 0x61fd60(A + 0x16c, k, 0x18) zero -> 0; p[0] != k: A[0x1b4] = A[0x1b8], return p; else A[0x1b8] = A[0x1b4], 0x6210c0(A, p) zero -> 0, else p.
static u8 *fn61fb10(u8 *A, u32 b, u32 c, u32 d) {
  u8 *s = A + 0x1a8;
  if (!ext_620180(s, b, c, d)) return 0;
  if (rd(s + 0xc) == rd(s + 8)) {
    if (!ext_6206e0(s)) return 0;
  }
  **(u8 **)(s + 0xc) = 0;
  wr(s + 0xc, rd(s + 0xc) + 1);
  u32 k = rd(s + 0x10);
  if (!k) return 0;
  u8 *p = ext_61fd60(A + 0x16c, k, 0x18);
  if (!p) return 0;
  if (rd(p) != k) {
    wr(A + 0x1b4, rd(A + 0x1b8));
    return p;
  }
  wr(A + 0x1b8, rd(A + 0x1b4));
  if (!ext_6210c0(A, p)) return 0;
  return p;
}
PCREG(61fb10, fn61fb10);
