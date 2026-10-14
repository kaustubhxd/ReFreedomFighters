// batch35022.cpp - cascade s5 batch 35022: 0x4e8000 (GUESS red-black tree: unlink a node, rebalance when a black node left).
#include "ff.h"

extern "C" void THISCALL ext_4e8450(u8 *self, u8 *x);   // thiscall, ret 4 (rebalance)
typedef u8 *(THISCALL *g1_t)(void *, u8 *);
typedef void(THISCALL *v2_t)(void *, u8 *, u8 *);

// 0x4e8000, thiscall(n) ret 4. Node fields: +0 parent, +4 left, +8 right, +0xc payload, +0x10 colour byte (0 = black); nil = [this+8], root = [this+4]. y = n when a child of n is nil, else
// this slot 0x18(n) (successor). x = y.left, or y.right when that is nil; x.parent = y.parent; the parent's slot (root when the parent is nil) is replaced by x; when y != n: n.payload =
// y.payload and this slot 0x28(n, y); a black y runs 0x4e8450(this, x). Returns y, or 0 when y is nil.
static u8 *THISCALL fn4e8000(u8 *self, u8 *n) {
  u8 *nil = *(u8 **)(self + 8);
  u8 *y;
  if (*(u8 **)(n + 4) == nil || *(u8 **)(n + 8) == nil) y = n;
  else y = (*(g1_t **)self)[0x18 / 4](self, n);
  u8 *x = *(u8 **)(y + 4);
  if (x == *(u8 **)(self + 8)) x = *(u8 **)(y + 8);
  *(u8 **)x = *(u8 **)y;
  u8 *p = *(u8 **)y;
  if (p == *(u8 **)(self + 8)) {
    *(u8 **)(self + 4) = x;
  } else if (y == *(u8 **)(p + 4)) {
    *(u8 **)(p + 4) = x;
  } else {
    *(u8 **)(p + 8) = x;
  }
  if (y != n) {
    *(u32 *)(n + 0xc) = *(u32 *)(y + 0xc);
    (*(v2_t **)self)[0x28 / 4](self, n, y);
  }
  if (y[0x10] == 0) ext_4e8450(self, x);
  return y == *(u8 **)(self + 8) ? 0 : y;
}
PCREG(4e8000, fn4e8000);
