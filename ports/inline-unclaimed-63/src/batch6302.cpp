// batch6302.cpp - unclaimed-63 batch 2 (docs/20-unclaimed-63.md): LINKREFTAB::ClearThis (0x4cdc60) and LINKREFTAB::Clear (0x4cdb20).
// Names from the GC name map (high). ClearThis: if [this+0x24] is set, calls its slot 0 with 1 (a deleting destructor flag,
// thiscall, callee pops 4); then zeroes +0x24, +0x1c and +0x20. Clear: the same first part; then sets bit 31 of +0xc, walks the
// list at [this+4] (node, next = [node+4]) calling this->vtbl[+0x7c](node) for each node (thiscall, callee pops 4), then
// zeroes [this+4] and [this+0x14]. Both are thiscall with no arguments.
#include "ff.h"

typedef void(THISCALL * call1_fn)(void *, u32);

// 0x4cdc60, LINKREFTAB::ClearThis() (high).
static void THISCALL linkRefTabClearThis(u8 *self) {
  u32 obj = *(u32 *)(self + 0x24);
  if (obj)
    ((call1_fn)(*(u32 *)(*(u32 *)obj)))((void *)obj, 1);
  *(u32 *)(self + 0x24) = 0;
  *(u32 *)(self + 0x1c) = 0;
  *(u32 *)(self + 0x20) = 0;
}
PCREG(4cdc60, linkRefTabClearThis);

// 0x4cdb20, LINKREFTAB::Clear() (high).
static void THISCALL linkRefTabClear(u8 *self) {
  u32 obj = *(u32 *)(self + 0x24);
  if (obj)
    ((call1_fn)(*(u32 *)(*(u32 *)obj)))((void *)obj, 1);
  *(u32 *)(self + 0xc) |= 0x80000000u;
  u32 node = *(u32 *)(self + 4);
  *(u32 *)(self + 0x24) = 0;
  *(u32 *)(self + 0x1c) = 0;
  *(u32 *)(self + 0x20) = 0;
  while (node) {
    u32 next = *(u32 *)(node + 4);
    ((call1_fn)(*(u32 *)(*(u32 *)self + 0x7c)))((void *)self, node);
    node = next;
  }
  *(u32 *)(self + 4) = 0;
  *(u32 *)(self + 0x14) = 0;
}
PCREG(4cdb20, linkRefTabClear);
