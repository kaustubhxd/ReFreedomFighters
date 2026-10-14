// batch37060.cpp - cascade s6 batch 37060: 0x444b90.
#include "ff.h"

typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v1_t)(void *, u32);
#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x444b90, thiscall(out, limit) ret 8, returns the final out pointer: walks the tree at this+0x48 (nodes: byte flags at +8 (bit 0 = has next sibling at +0xc), entries of two dwords
// after the header (start at +0xc, +0x10 when flag bit 0), end at node + (count + 3) * 4). An entry {lo | tag3, hi | ...}: tag 2 appends {lo, hi} to the out array (stops when
// out reaches limit), tag 0 counts the objects lo..hi step 0x70 whose slot 0x2a8 has bit 0x10000, whose owner's flags +0x3c miss 0x10002c00 and which do not answer slot 0x1e0(0x100021)
// (capped at 0x100); nodes with count < 2 are only passed through. After a pass the walk restarts from the root (count - 1) more times while the count is non-zero.
static u32 *THISCALL fn444b90(u8 *self, u32 *out, u32 *limit) {
  u32 edx = 0;
  u32 cnt;
  u8 *node;
  u8 *endp;
  u32 *ptr;
outer:
  node = *(u8 **)(self + 0x48);
  cnt = edx;
  if (!node) goto endcheck;
  for (;;) {
    u8 al = node[8];
    if (al >= 2) break;
    if (!(al & 1)) goto endcheck;
    node = *(u8 **)(node + 0xc);
    if (!node) goto endcheck;
  }
  {
    u8 al = node[8];
    ptr = (u32 *)(node + 0xc);
    if (al & 1) ptr++;
    endp = node + ((u32)al + 3) * 4;
    if (!ptr) goto endcheck;
  }
entry:
  {
    u32 w = ptr[1];
    u32 lo = ptr[0] & ~7u;
    u32 hi = w & ~7u;
    u32 tag = w & 7;
    ptr += 2;
    if (tag == 2) {
      if (limit <= out) return out;
      out[0] = lo;
      out[1] = hi;
      out += 2;
    } else if (tag == 0 && lo <= hi) {
      u32 c = cnt;
      u32 p = lo;
      do {
        u8 *o = *(u8 **)(p + 0x54);
        u32 f = (*(v0_t **)o)[0x2a8 / 4](o);
        if ((f & 0x10000) && !(D32(*(u8 **)(o + 8), 0x3c) & 0x10002c00) && !(u8)(*(v1_t **)o)[0x1e0 / 4](o, 0x100021)) {
          if (c < 0x100) c++;
        }
        p += 0x70;
      } while (p <= hi);
      cnt = c;
    }
  }
  if ((u8 *)ptr == endp) {
    for (;;) {
      if (!(node[8] & 1)) goto endloop;
      node = *(u8 **)(node + 0xc);
      if (!node) goto endloop;
      if (node[8] >= 2) break;
    }
    {
      u8 al = node[8];
      ptr = (u32 *)(node + 0xc);
      if (al & 1) ptr++;
      endp = node + ((u32)al + 3) * 4;
    }
  }
  if (ptr) goto entry;
endloop:
  edx = cnt;
endcheck:
  if (edx != 0) {
    edx--;
    goto outer;
  }
  return out;
}
PCREG(444b90, fn444b90);
