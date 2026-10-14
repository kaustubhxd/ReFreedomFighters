// batch35038.cpp - cascade s5 batch 35038: 0x49c420 (GUESS relocate three tagged handles in every node of a chain).
#include "ff.h"

typedef u32(THISCALL *g1_t)(void *, u32);

// 0x49c420, stdcall(node, unused) ret 8. For every node of the chain (next at +0xc) and each of its three dwords v at +0, +4, +8: p = v & ~7; when p != 0: r = engine table
// ([engine+0x9b]) slot 0x54((p + 0x60) | 0x40000000), and the dword becomes r | (v & 7).
static void STDCALL fn49c420(u32 *node, u32 unused) {
  (void)unused;
  while (node) {
    for (int k = 0; k < 3; k++) {
      u32 v = node[k];
      u32 p = v & 0xfffffff8;
      if (p) {
        u8 *eng = G(u8 *, 0x70039c);
        u8 *tab = *(u8 **)(eng + 0x9b);
        u32 r = (*(g1_t **)tab)[0x54 / 4](tab, (p + 0x60) | 0x40000000);
        node[k] = r | (v & 7);
      }
    }
    node = (u32 *)node[3];
  }
}
PCREG(49c420, fn49c420);
