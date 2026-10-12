// batch6337.cpp - unclaimed-63 gap-band batch 37: 0x4cd300 (C-set; list teardown, SEH tagged), thiscall, one stack argument flags, ret 4.
//   SEH frame not reproduced: the original installs an fs:[0] frame and a /GS-style cookie (0x6f5630) that the epilogue does not check;
//   the port keeps only the body.
//   this[+0xc] |= 0x80000000; this[0] = 0x695734 (vptr); walk the list at this[+4]: for each node, read node->next, then call
//   vtbl[+0x7c](node) with ECX = this (thiscall, ret 4). Then this[+0x14] = 0, this[+4] = 0; if (flags & 1) 0x634273(this, 0x1c) (cdecl).
#include "ff.h"

extern "C" void ext_634273(u32 self, u32 size);   // cdecl, original code, stubbed by the spec (the deleter)

typedef void(THISCALL * virt7c_fn)(void *, u32);

// 0x4cd300 (C-set).
static void THISCALL unnamed4cd300(u8 *self, u32 flags) {
  *(u32 *)(self + 0xc) |= 0x80000000u;
  u32 node = *(u32 *)(self + 4);
  *(u32 *)self = 0x695734u;
  while (node != 0) {
    u32 next = *(u32 *)(node + 4);
    ((virt7c_fn)(*(u32 *)(*(u32 *)self + 0x7c)))((void *)self, node);
    node = next;
  }
  *(u32 *)(self + 0x14) = 0;
  *(u32 *)(self + 4) = 0;
  if (flags & 1)
    ext_634273((u32)self, 0x1cu);
}
PCREG(4cd300, unnamed4cd300);
