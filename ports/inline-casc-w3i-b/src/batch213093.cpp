#include "ff.h"

typedef u32(THISCALL *V3)(void *, u32, u32, u32);

extern "C" u32 THISCALL ext_4cd9b0(u32 ctx, u32 bytes, u32 flag);

static inline u32 rd32u(u32 p) { u32 v; __builtin_memcpy(&v, (const void *)p, 4); return v; }
static inline void wr32u(u32 p, u32 v) { __builtin_memcpy((void *)p, &v, 4); }
static inline u32 rd8(u32 p) { return *(const u8 *)p; }
static inline void wr8(u32 p, u32 v) { *(u8 *)p = (u8)v; }

// 0x495950: thiscall(a, b, c, d, e) ret 0x14 -> a node pointer: insert/update of a (b | d) -> (c | d) pair in a chain of small nodes (header bytes +0..7 hold per-tag counters,
// +8 the used count n (odd when a link to the next node leads the pair area at +0xc), +9 the capacity; pairs of dwords follow, d < 8 is the tag in the key's low bits).
// The chain a is searched: a pair whose tag is d and whose key's object [key & ~7 + 0x50] equals b[0x50] and whose key equals (c | d) + 0x70 gets its key replaced by b | d,
// and one whose value equals (b | d) - 0x70 gets the value c | d; the head a is returned. Otherwise a node with room for two more words is looked for along the chain,
// else a new node is allocated (size ((e + 7) & ~7) * 4 + 0x18 rounded down to 16 through 0x4cd9b0([this], bytes, 1), logged through the [0x70038c] object's slot 0x2c, linked in front
// of a when a exists) and the pair is appended, the tag counter incremented, returning the (possibly new) head.
extern "C" u32 THISCALL fn_495950(u8 *self, u32 a, u32 b, u32 c, u32 d, u32 e) {
  u32 size = (e + 7) & ~7u;
  u32 bk = rd32u(b + 0x50);
  u32 b2 = b | d, c2 = c | d;
  u32 edi = a, s18 = a;
  if (a && rd8(a + 8) > 1) {
    u32 esi = a;
    for (;;) {
      u32 n = rd8(esi + 8);
      u32 p = esi + 0xc;
      u32 end = esi + (n + 3) * 4;
      u32 next = 0;
      if (n & 1) {
        next = rd32u(p);
        p += 4;
      }
      while (p != end) {
        u32 key = rd32u(p), val = rd32u(p + 4);
        p += 8;
        if ((key & 7) == d) {
          if (rd32u((key & ~7u) + 0x50) == bk) {
            if (c2 + 0x70 == key) {
              wr32u(p - 8, b2);
              return a;
            }
            if (b2 - 0x70 == val) {
              wr32u(p - 4, c2);
              return a;
            }
          }
        }
      }
      if (!next) break;
      esi = next;
    }
    edi = a;
  }
  u32 esi = a;
  bool alloc = false;
  if (!a) {
    alloc = true;
  } else if ((s32)(rd8(a + 9) - rd8(a + 8)) < 2) {
    u32 edx = a;
    for (;;) {
      u32 bl = rd8(edx + 8);
      if ((s32)(rd8(edx + 9) - bl) >= 2) {
        edi = edx;
        s18 = edi;
        break;
      }
      if (!(bl & 1)) break;
      edx = rd32u(edx + 0xc);
      if (!edx) break;
    }
    if (!edi || (s32)(rd8(edi + 9) - rd8(edi + 8)) < 2) alloc = true;
  }
  if (alloc) {
    u32 bytes = (size * 4 + 0x18) & 0xfffffff0u;
    u32 p = ext_4cd9b0(rd32u((u32)self), bytes, 1);
    void *L = G(void *, 0x70038c);
    if (L) (*(V3 *)(*(u8 **)L + 0x2c))(L, 0x68e4c8, p, bytes);
    u32 node = rd32u((u32)self + 4) + p;
    wr8(node + 9, size);
    wr32u(node, 0);
    wr32u(node + 4, 0);
    if (s18) {
      wr8(node + 8, 1);
      wr32u(node + 0xc, a);
    } else {
      wr8(node + 8, 0);
    }
    esi = node;
    edi = node;
  }
  u32 cnt = rd8(edi + 8);
  wr32u(edi + cnt * 4 + 0xc, b2);
  u32 t = b2 & 7;
  wr32u(edi + cnt * 4 + 0x10, c2);
  wr8(edi + 8, cnt + 2);
  wr8(edi + t, rd8(edi + t) + 1);
  return esi;
}
PCREG(495950, fn_495950);
