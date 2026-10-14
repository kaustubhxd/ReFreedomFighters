// batch34035.cpp - cascade tier E, batch 34035: 0x478700, pick the first pending entry of a table, remember its value and result, and clear it.
#include "ff.h"

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static inline void wr32u(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x478700, thiscall, no args: v = [this+0x695] (unaligned); [this+0x6c6] = 0; when v and its array [v+0x10] exist: for i in 0 .. [v+8] (signed) the first i with a non-zero
// array[i]: [this+0x6ca] = table[i*4 dwords] ([v+0xc]); [this+0x6c6] = [this+0x5b2]->slot0x228(array[i]); array[i] = 0 (array re-read through [this+0x695]).
static void THISCALL fn478700(u8 *self) {
  u8 *v = (u8 *)rd32u(self + 0x695);
  wr32u(self + 0x6c6, 0);
  if (!v) return;
  u32 *arr = *(u32 **)(v + 0x10);
  if (!arr) return;
  s32 n = *(s32 *)(v + 8);
  s32 i = 0;
  if (n <= 0) return;
  for (;;) {
    if (*arr != 0) break;
    i++;
    arr += 1;
    if (!(i < n)) return;
  }
  u8 *tab = *(u8 **)(v + 0xc);
  u32 val = *(u32 *)(tab + (u32)(i * 2) * 8);
  u8 *o = (u8 *)rd32u(self + 0x5b2);
  wr32u(self + 0x6ca, val);
  u32 *a2 = *(u32 **)(v + 0x10);
  u32 r = vcall<u32>(o, 0x228, a2[i]);
  wr32u(self + 0x6c6, r);
  u8 *v2 = (u8 *)rd32u(self + 0x695);
  (*(u32 **)(v2 + 0x10))[i] = 0;
}
PCREG(478700, fn478700);
