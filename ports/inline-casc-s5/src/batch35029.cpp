// batch35029.cpp - cascade s5 batch 35029: 0x5fe560 (GUESS apply two packed index tables to a target, children first).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x5fe560, thiscall(t) ret 4, recursive. When [this+0x9c] (child, same type) is set it is processed first with the same target. Then two tables are walked: T1 at [this+0x84] + [this+0x98], T2 at
// [this+0x98] + [this+0x80]; each starts with a dword count n, followed by n six-byte entries whose unaligned dword at +4 + 6i is an offset into the data block [t+0x9e] (unaligned pointer):
// t slot 0x34(*(u32 *)(data + offset)) for T1 entries, t slot 0x4(...) for T2 entries.
static void THISCALL fn5fe560(u8 *self, u8 *t) {
  u8 *child = *(u8 **)(self + 0x9c);
  if (child) fn5fe560(child, t);
  u8 *t1 = (u8 *)(*(u32 *)(self + 0x84) + *(u32 *)(self + 0x98));
  u32 n = *(u32 *)t1;
  if (n) {
    u32 i = 0;
    do {
      u32 off = rd32u(t1 + 4 + i * 6);
      u8 *data = (u8 *)rd32u(t + 0x9e);
      (*(v1_t **)t)[0x34 / 4](t, *(u32 *)(off + (u32)data));
      i++;
    } while (i != n);
  }
  u8 *t2 = (u8 *)(*(u32 *)(self + 0x98) + *(u32 *)(self + 0x80));
  n = *(u32 *)t2;
  if (n) {
    u32 i = 0;
    do {
      u32 off = rd32u(t2 + 4 + i * 6);
      u8 *data = (u8 *)rd32u(t + 0x9e);
      (*(v1_t **)t)[0x4 / 4](t, *(u32 *)(off + (u32)data));
      i++;
    } while (i != n);
  }
}
PCREG(5fe560, fn5fe560);
