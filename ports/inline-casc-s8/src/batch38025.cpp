// batch38025.cpp - cascade s8 batch 38025: 0x4cf690 (rebuild a hash container through a temporary bucket table).
#include "ff.h"

extern "C" u8 *ext_41e290(u32 size);                    // allocator, cdecl
extern "C" void ext_634273(void *p, u32 n);              // free(p, size), cdecl
extern "C" void ext_634d10(void *p, u32 v, u32 n);       // memset, cdecl
extern "C" void ext_634d22(void *dst, const void *src, u32 n);   // memcpy, cdecl
typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(*log_t)(void *, u32);
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define LOGGER G(u8 *, 0x700390)

// 0x4cf690, thiscall, no args, plain ret. Buckets the container's entries (iterated with slot 0x54 / 0x74; key = last of this+0x18 dwords, bucket = key - this[0x1c], range up to this[0x20])
// into a temporary chain table (nodes of 8 bytes taken from the top of an entries*8 pool), builds a fresh container object (0x1c bytes, vtable 0x695734, capacity max(1, [+0xc] & 0x7fffffff),
// element size [+0x18]) and appends every chained entry to it through its slot 1 + memcpy of the key tail, checks the counts (logging 0x695c38 / 0x695c48 on mismatch), then swaps the
// new container's fields (+4, +8) and count into this (slot 0xc is called first), deletes the temporary object and frees the pool and bucket table.
static void THISCALL fn4cf690(u8 *self) {
  s32 nb = *(s32 *)(self + 0x20) - *(s32 *)(self + 0x1c) + 1;
  u32 cnt0 = *(u32 *)(self + 0x14);
  u8 *pool = ext_41e290(cnt0 << 3);
  u8 *edi = pool + (u32)(*(s32 *)(self + 0x14)) * 8;
  u32 bsz = (u32)nb << 2;
  u32 *bk = (u32 *)ext_41e290(bsz);
  ext_634d10(bk, 0, bsz);
  u32 it[9];
  SLOT(self, 0x54, v1_t)(self, (u32)it);
  u8 *x = (u8 *)SLOT(self, 0x74, v1_t)(self, (u32)it);
  while (x) {
    edi -= 8;
    s32 key = *(s32 *)(x + (*(u32 *)(self + 0x18)) * 4 - 4);
    s32 idx = key - *(s32 *)(self + 0x1c);
    *(u32 *)edi = bk[idx];
    *(u8 **)(edi + 4) = x;
    bk[idx] = (u32)edi;
    x = (u8 *)SLOT(self, 0x74, v1_t)(self, (u32)it);
  }
  if (edi != pool) {
    u8 *lg = LOGGER;
    ((log_t)(*(u8 ***)lg)[0x24 / 4])(lg, 0x695c38);
  }
  u8 *p = ext_41e290(0x1c);
  u8 *ob = 0;
  if (p) {
    u32 c = *(u32 *)(self + 0xc) & 0x7fffffff;
    u32 dim = *(u32 *)(self + 0x18);
    *(u32 *)p = 0x695734;
    *(u32 *)(p + 0x14) = 0;
    if (c < 1) c = 1;
    *(u32 *)(p + 0x18) = dim;
    *(u32 *)(p + 0xc) = c;
    *(u32 *)(p + 0x10) = dim * c;
    *(u32 *)(p + 4) = 0;
    *(u32 *)(p + 8) = 0;
    ob = p;
  }
  u32 tail = *(u32 *)(self + 0x18) * 4 - 4;
  u32 b = 0;
  if (nb != 0) {
    do {
      u8 *e = (u8 *)bk[b];
      if (e) {
        do {
          u8 *key = *(u8 **)(e + 4);
          u8 *dst = (u8 *)SLOT(ob, 4, v1_t)(ob, *(u32 *)key);
          ext_634d22(dst, *(u8 **)(e + 4) + 4, tail);
          e = *(u8 **)e;
        } while (e);
      }
      b++;
    } while (b != (u32)nb);
  }
  u32 r = SLOT(ob, 0x14, v0_t)(ob);
  if (*(u32 *)(self + 0x14) != r) {
    u8 *lg = LOGGER;
    ((log_t)(*(u8 ***)lg)[0x24 / 4])(lg, 0x695c48);
  }
  u32 saved = *(u32 *)(self + 0x14);
  SLOT(self, 0xc, v0_t)(self);
  *(u32 *)(self + 0x14) = saved;
  *(u32 *)(self + 4) = *(u32 *)(ob + 4);
  *(u32 *)(self + 8) = *(u32 *)(ob + 8);
  *(u32 *)(ob + 4) = 0;
  SLOT(ob, 0, v1_t)(ob, 1);
  ext_634273(pool, 8);
  ext_634273(bk, 4);
}
PCREG(4cf690, fn4cf690);
