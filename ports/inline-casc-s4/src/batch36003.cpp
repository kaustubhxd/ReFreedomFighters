// batch36003.cpp - cascade s4 batch 36003: 0x4cfb30, 0x4d0c70 (tier F rows).
#include "ff.h"

typedef u8 *(THISCALL *p2o_t)(void *, u32, u32);
typedef u8 *(THISCALL *p1o_t)(void *, u32);
typedef void(THISCALL *p1_t)(void *, void *);

extern "C" void *memset_634d10(void *, int, u32) asm("ext_634d10");  // cdecl
extern "C" u8 *THISCALL ext_4d0630(void *self);                       // plain ret
extern "C" void THISCALL ext_4d0950(void *self, void *a);             // ret 4
typedef u32 (*hook_t)();

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

// 0x4cfb30, thiscall(blk, size) ret 8 (this = E): clears blk, header {0,0,size}, E[0x207]++; sub-header at blk+0x10 with size-0x30 at +0x18, 0 at +0x1c,
// 0 at blk+0x28+(size-0x30), (size-0x30) at blk+0x2c+(size-0x30); node = pool(E+0x1cc)->slot 8(that size, 0), or a fresh node from 0x4d0630(E)
// (node[0xc] = size, node[0x11] = 0, pool->slot 0(node)); then blk+0x20 = 0, blk+0x24 = node[0x11], node[0x11] = blk+0x10, and the old head's +0x10 = blk+0x10.
static u8 *THISCALL fn4cfb30(u8 *E, u8 *blk, u32 size) {
  memset_634d10(blk, 0, size);
  u8 *ebx = blk + 0x10;
  wr(blk + 8, size);
  wr(blk, 0);
  wr(blk + 4, 0);
  wr(E + 0x207, rd(E + 0x207) + 1);
  u32 edi = size - 0x30;
  wr(ebx + 8, edi);
  wr(ebx + 0xc, 0);
  wr(ebx + edi + 0x18, 0);
  wr(ebx + edi + 0x1c, edi);
  u8 *pool = E + 0x1cc;
  u32 ecx = rd(ebx + 8);
  u8 *node = (*(p2o_t **)pool)[8 / 4](pool, ecx, 0);
  if (!node) {
    node = ext_4d0630(E);
    wr(node + 0xc, ecx);
    wr(node + 0x11, 0);
    (*(p1_t **)pool)[0](pool, node);
  }
  wr(ebx + 0x10, 0);
  wr(ebx + 0x14, rd(node + 0x11));
  wr(node + 0x11, (u32)ebx);
  u8 *old = (u8 *)rd(ebx + 0x14);
  if (old) wr(old + 0x10, (u32)ebx);
  return node;
}
PCREG(4cfb30, fn4cfb30);

// 0x4d0c70, thiscall(a, b) ret 8 (this = E): assert hook when a[8] < 0 (signed); node = b, or pool(E+0x1cc)->slot 8(a[8], 0) when b == 0;
// unlink a from its list (prev a[0x10], next a[0x14]; no prev: node[0x11] = next); when node[0x11] == 0: x = pool->slot 4(node); if E[0x1c4] == 0x64:
// E[0x12130]--, E[0x11530 + 4*E[0x12130]] = x, 0x4d0950(E, x); else E[0x34 + 4*E[0x1c4]] = x, E[0x1c4]++.
static void THISCALL fn4d0c70(u8 *E, u8 *a, u8 *b) {
  if ((s32)rd(a + 8) < 0) {
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    else h();
  }
  u8 *node = b;
  u8 *pool = E + 0x1cc;
  if (!node) node = (*(p2o_t **)pool)[8 / 4](pool, rd(a + 8), 0);
  u8 *prev = (u8 *)rd(a + 0x10);
  if (prev) wr(prev + 0x14, rd(a + 0x14));
  else wr(node + 0x11, rd(a + 0x14));
  u8 *next = (u8 *)rd(a + 0x14);
  if (next) wr(next + 0x10, rd(a + 0x10));
  if (rd(node + 0x11) == 0) {
    u8 *x = (*(p1o_t **)pool)[4 / 4](pool, (u32)node);
    u32 cnt = rd(E + 0x1c4);
    if (cnt == 0x64) {
      wr(E + 0x12130, rd(E + 0x12130) - 1);
      wr(E + 0x11530 + 4 * rd(E + 0x12130), (u32)x);
      ext_4d0950(E, x);
      return;
    }
    wr(E + 0x34 + 4 * cnt, (u32)x);
    wr(E + 0x1c4, cnt + 1);
  }
}
PCREG(4d0c70, fn4d0c70);
