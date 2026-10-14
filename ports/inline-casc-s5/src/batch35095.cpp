// batch35095.cpp - cascade s5 batch 35095: 0x4db3b0 (GUESS find the entry matching this node's kind, by chain or by table index).
#include "ff.h"

typedef u8 *(THISCALL *g0_t)(void *);
typedef u8 *(THISCALL *g1_t)(void *, u32);

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x4db3b0, thiscall, no arguments, returns EAX. f = [this+0x3c]. Neither bit 0x40040000: walk the chain this, [+0x50], ...: the first node whose record r = [node+0x54] (non-null) has an unaligned dword 0x100021 at [r+0xc]+0x23 returns r (0 at
// the end of the chain). Otherwise s = this, except bit 0x40000000: s = word [this+0x5c] == 0 ? null : array[w - 1] where array = L slot 0x4c(), L = [[engine+0x9b]+8], elements 0x70 bytes. Then w2 = word [s+0x5c]: non-zero and
// o = L slot 0x5c(w2) with byte [o+0x1c] != 0 returns the dword [o]; anything else returns the dword [[engine+0x9b]+0xadc].
static u32 THISCALL fn4db3b0(u8 *self) {
  u32 f = *(u32 *)(self + 0x3c);
  if (!(f & 0x40040000)) {
    u8 *node = self;
    while (node) {
      u8 *r = *(u8 **)(node + 0x54);
      if (r) {
        u8 *blk = *(u8 **)(r + 0xc);
        if (rd32u(blk + 0x23) == 0x100021) return (u32)r;
      }
      node = *(u8 **)(node + 0x50);
    }
    return 0;
  }
  u8 *s = self;
  if (f & 0x40000000) {
    u32 w = *(u16 *)(self + 0x5c);
    if (w == 0) {
      s = 0;
    } else {
      u8 *eng = G(u8 *, 0x70039c);
      u8 *L = *(u8 **)(*(u8 **)(eng + 0x9b) + 8);
      u8 *base = (*(g0_t **)L)[0x4c / 4](L);
      s = base + w * 0x70 - 0x70;
    }
  }
  u32 w2 = *(u16 *)(s + 0x5c);
  if (w2) {
    u8 *eng = G(u8 *, 0x70039c);
    u8 *L = *(u8 **)(*(u8 **)(eng + 0x9b) + 8);
    u8 *o = (*(g1_t **)L)[0x5c / 4](L, w2);
    if (o && o[0x1c]) return *(u32 *)o;
  }
  u8 *eng = G(u8 *, 0x70039c);
  return *(u32 *)(*(u8 **)(eng + 0x9b) + 0xadc);
}
PCREG(4db3b0, fn4db3b0);
