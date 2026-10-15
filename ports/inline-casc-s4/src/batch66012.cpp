// batch66012.cpp - cascade s4 batch 66012: 0x4d2030 (tier F row).
#include "ff.h"

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" u8 *THISCALL ext_4d1cf0(void *self, s32 i);   // ret 4
extern "C" void ext_634273(void *p, u32 flag);           // cdecl

// Unlink a node (owner n[0], prev n[4], next n[8], data n[0xc]) and free its data (flag 1) and the node (size 0x14).
static void drop(u8 *n) {
  u8 *prev = *(u8 **)(n + 4);
  u8 *next = *(u8 **)(n + 8);
  if (prev) wr(prev + 8, (u32)next);
  else wr(*(u8 **)n + 0x18, (u32)next);
  next = *(u8 **)(n + 8);
  prev = *(u8 **)(n + 4);
  if (next) wr(next + 4, (u32)prev);
  else wr(*(u8 **)n + 0x1c, (u32)prev);
  void *data = *(void **)(n + 0xc);
  wr(n + 8, 0);
  wr(n + 4, 0);
  ext_634273(data, 1);
  ext_634273(n, 0x14);
}

// 0x4d2030, thiscall(i) ret 4 (this = t): i < 0 -> drop every node from the head t[0x18] until the list is empty.
// Otherwise n = 0x4d1cf0(t, i): n != 0 -> drop(n). Then t[0x14] != 0 -> 0x634273(t[0x14], 4), t[0x14] = 0; t[0x10] = 0.
static void THISCALL fn4d2030(u8 *t, s32 i) {
  if (i < 0) {
    while (rd(t + 0x18)) {
      u8 *n = *(u8 **)(t + 0x18);
      if (n) drop(n);
    }
  } else {
    u8 *n = ext_4d1cf0(t, i);
    if (n) drop(n);
  }
  u32 p = rd(t + 0x14);
  if (p) {
    ext_634273((void *)p, 4);
    wr(t + 0x14, 0);
  }
  wr(t + 0x10, 1);
}
PCREG(4d2030, fn4d2030);
