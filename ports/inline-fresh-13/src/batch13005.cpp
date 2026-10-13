// batch13005.cpp - fresh slice 13, batch 5 (docs/20-fresh-13.md), 2026-10-12.
// 0x5faad0 GUESS constructor (no name map entry; vtable 0x6b92a4). Thiscall, no arguments, returns this. Clears fields,
// runs the member constructor 0x606220 (thiscall, no args) on +0x18 and +0x28, stores the secondary vtables 0x6b92a8
// (+0x50) and 0x6b89f0 (+0x5c), and builds two empty tree headers (std::map style: head node from 0x6014a0 =
// CHostInterface::alloc (name map high; thiscall on the member, one argument 0x13 / 0x15, ret 4), node byte 0 = 0,
// dword +1 = 0, +5 and +9 point at the node itself) at +0x118 and +0x121 (1-byte packed, 9 bytes each). The SEH frame and
// stack cookie are not reproduced.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_606220[], ext_6014a0[];
typedef void(THISCALL *Ctor0)(void *self);
typedef u8 *(THISCALL *Alloc1)(void *self, u32 n);

static void emptyTree(u8 *t, u32 n) {
  AT(u32, t, 0) = 0;
  u8 *node = ((Alloc1)(void *)ext_6014a0)(t, n);
  AT(u8 *, t, 0) = node;
  AT(u32, t, 4) = 0;
  node[0] = 0;
  AT(u32, AT(u8 *, t, 0), 1) = 0;
  AT(u32, AT(u8 *, t, 0), 5) = (u32)AT(u8 *, t, 0);
  AT(u32, AT(u8 *, t, 0), 9) = (u32)AT(u8 *, t, 0);
}

static u8 *THISCALL ctor5faad0(u8 *self) {
  AT(u32, self, 0) = 0x6b92a4;
  AT(u32, self, 4) = 0;
  AT(u32, self, 8) = 0;
  AT(u32, self, 0xc) = 0;
  ((Ctor0)(void *)ext_606220)(self + 0x18);
  ((Ctor0)(void *)ext_606220)(self + 0x28);
  AT(u32, self, 0x38) = 0;
  AT(u32, self, 0x3c) = 0;
  AT(u32, self, 0x40) = 0;
  AT(u32, self, 0x50) = 0x6b92a8;
  AT(u32, self, 0x54) = 0;
  AT(u32, self, 0x58) = 0;
  AT(u32, self, 0x5c) = 0x6b89f0;
  AT(u32, self, 0x60) = 0;
  AT(u32, self, 0x64) = 0;
  for (u32 off = 0x94; off <= 0xc8; off += 4)
    AT(u32, self, off) = 0;
  AT(u32, self, 0x10c) = 0;
  AT(u32, self, 0x110) = 0;
  AT(u32, self, 0x114) = 0;
  emptyTree(self + 0x118, 0x13);
  emptyTree(self + 0x121, 0x15);
  AT(u32, self, 0x12a) = 0;
  AT(u32, self, 0x12e) = 0;
  AT(u32, self, 0x132) = 0;
  return self;
}
PCREG(5faad0, ctor5faad0);
