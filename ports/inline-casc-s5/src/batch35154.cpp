// batch35154.cpp - cascade s5 batch 35154: 0x64cd00 (GUESS reset per-frame state, find the first flagged child, assert the table is sorted).
#include "ff.h"

typedef void(THISCALL *v0_t)(void *);
typedef u32 (*hook_t)();

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static inline void wr32u(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x64cd00, thiscall, no args, no return value. byte +0x1825e |= 1; dword (unaligned) +0x18259 = 0xffffffff; +0x18261 = [+0x1005d] + 0xb944; +0x18279 = 0. n = [+0x10089] (unaligned); for the first n children
// c at +0x1008d + 4i (stops at the first with ([[[c+0xc]+0xc]+0x48] & 0x400000)): +0x18279 = c. Then this slot 0x3c(); then for the [+0x20] pairs at +0x28 + 8i: when the previous first dword (0 at the start) is above the
// current one the assert hook 0x7003b0 is called (int3 when null).
static void THISCALL fn64cd00(u8 *self) {
  self[0x1825e] |= 1;
  wr32u(self + 0x18259, 0xffffffffu);
  wr32u(self + 0x18261, rd32u(self + 0x1005d) + 0xb944);
  wr32u(self + 0x18279, 0);
  u32 n = rd32u(self + 0x10089);
  if (n) {
    u32 i = 0;
    do {
      u8 *ch = (u8 *)rd32u(self + 0x1008d + 4 * i);
      u8 *x = *(u8 **)(*(u8 **)(ch + 0xc) + 0xc);
      if (*(u32 *)(x + 0x48) & 0x400000) {
        wr32u(self + 0x18279, (u32)ch);
        break;
      }
      i++;
    } while (i != n);
  }
  (*(v0_t **)self)[0x3c / 4](self);
  u32 cnt = *(u32 *)(self + 0x20);
  u32 prev = 0;
  for (u32 i = 0; i != cnt; i++) {
    u32 cur = *(u32 *)(self + 0x28 + 8 * i);
    if (prev > cur) {
      hook_t h = G(hook_t, 0x7003b0);
      if (!h) __asm__ volatile("int3");
      h();
    }
    prev = cur;
  }
}
PCREG(64cd00, fn64cd00);
