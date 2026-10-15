// batch36085.cpp - cascade s4 batch 36085: 0x4bd190, 0x4d21b0 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

// 0x4bd190, thiscall(s) ret 4, returns al = 1 (this = t): t[4] &= ~0x40; s->slot 0x48(&v); t[0x48] = v; s->slot 0x50(out) for t+0x4c, 0x54, 0x58, 0x5c, 0x60, 0x64, 0x68;
// s->slot 0x48(out) for t+0x6c, 0x70; s->slot 0x50(out) for t+0x78, 0x7c, 0x74.
static u8 THISCALL fn4bd190(u8 *t, u8 *s) {
  u32 v;
  wr(t + 4, rd(t + 4) & 0xffffffbf);
  (*(v1_t **)s)[0x48 / 4](s, (u32)&v);
  wr(t + 0x48, v);
  static const u16 offs[11] = {0x4c, 0x54, 0x58, 0x5c, 0x60, 0x64, 0x68, 0x6c, 0x70, 0x78, 0x7c};
  for (int i = 0; i < 11; i++) {
    u32 slot = (i == 7 || i == 8) ? 0x48 : 0x50;
    (*(v1_t **)s)[slot / 4](s, (u32)(t + offs[i]));
  }
  (*(v1_t **)s)[0x50 / 4](s, (u32)(t + 0x74));
  return 1;
}
PCREG(4bd190, fn4bd190);

// 0x4d21b0, thiscall(list, index) ret 8 (this = n): unlink n from its current owner n[0x2c] (list head [0x24], tail [0x28], node next [0x30], prev [0x34]),
// set n[0x2c] = list; list == 0 -> clear the links. Otherwise insert before the node at position index (walking next links; -1 or past the end -> append at the tail).
static void THISCALL fn4d21b0(u8 *n, u8 *list, u32 idx) {
  u8 *old = *(u8 **)(n + 0x2c);
  if (old) {
    u8 *prev = *(u8 **)(n + 0x34);
    u8 *next = *(u8 **)(n + 0x30);
    if (prev) wr(prev + 0x30, (u32)next);
    else wr(old + 0x24, (u32)next);
    next = *(u8 **)(n + 0x30);
    prev = *(u8 **)(n + 0x34);
    if (next) wr(next + 0x34, (u32)prev);
    else wr(*(u8 **)(n + 0x2c) + 0x28, (u32)prev);
    wr(n + 0x30, 0);
    wr(n + 0x34, 0);
  }
  wr(n + 0x2c, (u32)list);
  if (!list) {
    wr(n + 0x34, 0);
    wr(n + 0x30, 0);
    return;
  }
  if (idx != 0xffffffffu) {
    u8 *cur = *(u8 **)(list + 0x24);
    bool ok = true;
    if (idx != 0) {
      for (;;) {
        idx--;
        if (!cur) {
          ok = false;
          break;
        }
        cur = *(u8 **)(cur + 0x30);
        if (idx == 0) break;
      }
    }
    if (ok && cur) {
      u8 *prev = *(u8 **)(cur + 0x34);
      wr(n + 0x34, (u32)prev);
      wr(n + 0x30, (u32)cur);
      if (prev) {
        wr(prev + 0x30, (u32)n);
        wr(cur + 0x34, (u32)n);
      } else {
        wr(list + 0x24, (u32)n);
        wr(cur + 0x34, (u32)n);
      }
      return;
    }
  }
  u8 *tail = *(u8 **)(list + 0x28);
  wr(n + 0x34, (u32)tail);
  wr(n + 0x30, 0);
  tail = *(u8 **)(list + 0x28);
  if (tail) {
    wr(tail + 0x30, (u32)n);
    wr(list + 0x28, (u32)n);
  } else {
    wr(list + 0x24, (u32)n);
    wr(list + 0x28, (u32)n);
  }
}
PCREG(4d21b0, fn4d21b0);
