// batch838.cpp - gap band small functions with hooked callees (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

extern "C" u32 *THISCALL ext_6397c0(u8 *self, u32 arg);                 // hooked (GUESS): returns a buffer, ret 4
extern "C" void __attribute__((cdecl)) ext_634d22(void *dst, void *src, u32 n);   // hooked (GUESS): memmove

typedef void (*cb_t)();
typedef u32 (THISCALL *vr_t)(u8 *self);
typedef void (THISCALL *vit_t)(u8 *self, u32 *it);

// 0x639b00: thiscall(arg) ret 4 - calls the assert hook [0x7003b0] (int3 when unset), p = 0x6397c0(arg); p[0] = this[0x32];
// copies this[0x32] words from this[0x2d] to p+4, then copies vt[0x1c]()*vt[0x20]() bytes from this[0x36] after them;
// returns the end address
static u32 THISCALL packArrays_639b00(u8 *self, u32 arg) {
  cb_t cb = G(cb_t, 0x7003b0);
  if (!cb) __builtin_trap();
  cb();
  u32 *p = ext_6397c0(self, arg);
  *p = *(u32 *)(self + 0x32);
  u32 *q = p + 1;
  ext_634d22(q, *(void **)(self + 0x2d), *(u32 *)(self + 0x32) << 2);
  u32 edi = (u32)(q + *(u32 *)(self + 0x32));
  u32 a = (*(vr_t *)(*(u8 **)self + 0x20))(self);
  u32 b = (*(vr_t *)(*(u8 **)self + 0x1c))(self);
  ext_634d22((void *)edi, *(void **)(self + 0x36), a * b);
  a = (*(vr_t *)(*(u8 **)self + 0x20))(self);
  b = (*(vr_t *)(*(u8 **)self + 0x1c))(self);
  return b * a + edi;
}
PCREG(639b00, packArrays_639b00);

// 0x640450: thiscall() - walks the container at this+0x1dc through an iterator {cur, idx, node} (begin = vt[0xc](&it),
// remove-current = vt[0x10](&it)): items whose object byte +5 bit 0 is clear are removed; the others advance, hopping to
// the next node (node[8]) when idx reaches node[0]
static void THISCALL pruneList_640450(u8 *self) {
  u8 *c = self + 0x1dc;
  u32 it[3];   // cur, idx, node
  (*(vit_t *)(*(u8 **)c + 0xc))(c, it);
  u32 cur = it[0];
  if (!cur) return;
  u32 node = it[2], idx = it[1];
  while (cur) {
    if (!(*(u8 *)(*(u32 *)cur + 5) & 1)) {
      (*(vit_t *)(*(u8 **)c + 0x10))(c, it);
      node = it[2];
      idx = it[1];
      cur = it[0];
      continue;
    }
    idx++;
    it[1] = idx;
    if (idx == *(u32 *)node) {
      node = *(u32 *)(node + 8);
      it[2] = node;
      if (!node) return;
      idx = 0;
      cur = node + 0x10;
      it[1] = 0;
    } else {
      cur += 4;
    }
    it[0] = cur;
  }
}
PCREG(640450, pruneList_640450);
