// batch2490.cpp - decomp area 24, batch 2490.
#include "ff.h"

// Both functions end in a tail jump (jmp [vtable+0x3c]) that passes the caller's argument on, so the target's own `ret` pops it. The
// port calls the target and returns, which pops the same dword: this assumes the slot 0x3c target takes one dword and pops it (the
// spec stubs pop 4). Not settled for every class; a different arity would show up as a stack mismatch in the checker.

// 0x444fb0 (ZROOM::RemoveDynamicGeomFromRoom per the claim doc), thiscall, ret 4. Child at +0xa8: slot 0x28 with the argument; when
// nonzero, tail to slot 0x3c of the child with the argument; otherwise 0.
static u32 THISCALL roomRemoveDynamicGeomTail(u8 *self, u32 arg) {
  u8 *child = *(u8 **)(self + 0xa8);
  if (child && vcall<u32>(child, 0x28, arg)) {
    child = *(u8 **)(self + 0xa8);
    return vcall<u32>(child, 0x3c, arg);
  }
  return 0;
}
PCREG(444fb0, roomRemoveDynamicGeomTail);

// 0x44a5b0 (name not in the claim doc), thiscall, ret 4. When +0x18 is set: slot 0x230 of this with (argument, 0), then tail to slot 0x3c
// of the child at +0x18 with the argument.
static void THISCALL tailToChildWithPrecall(u8 *self, u32 arg) {
  if (*(u8 **)(self + 0x18)) {
    vcall<void>(self, 0x230, arg, 0u);
    vcall<void>(*(void **)(self + 0x18), 0x3c, arg);
  }
}
PCREG(44a5b0, tailToChildWithPrecall);
