// batch824.cpp - core gameplay batch 824 (docs/20-unclaimed-65.md, batch 824): 0x53f5d0 (CRigidBody::Setup), a thiscall with no arguments
// and a stack frame with a cookie (the cookie check is not reproduced). It clears the byte at this+0x110, calls 0x4dc630 on the block
// [[this+0x44]+8] with arguments (0, 1), calls 0x4db7c0 on the same block with a pointer to a 16-byte local, calls slot 0x40 of
// [this+0x44] (no arguments), and calls 0x6352a0 with ecx = this and arguments (0x10, 0). The other callees are other claims, hooked by
// address in the spec (GUESS).
#include "ff.h"

typedef u32(THISCALL *F0)(u8 *self);

extern "C" void THISCALL ext_4dc630(u8 *self, u32 a, u32 b);   // thiscall, two arguments (hooked)
extern "C" void THISCALL ext_4db7c0(u8 *self, u32 *out);        // thiscall, one pointer argument (hooked)
extern "C" void THISCALL ext_6352a0(u8 *self, u32 a, u32 b);   // thiscall, two arguments (hooked)

static void THISCALL fn53f5d0(u8 *self) {
  self[0x110] = 0;
  u8 *blk = *(u8 **)(*(u8 **)(self + 0x44) + 8);
  ext_4dc630(blk, 0, 1);
  u32 local[4] = {0, 0, 0, 0};
  blk = *(u8 **)(*(u8 **)(self + 0x44) + 8);
  ext_4db7c0(blk, local);
  u8 *obj = *(u8 **)(self + 0x44);
  ((F0)(*(const u32 *)(*(const u32 *)obj + 0x40)))(obj);
  ext_6352a0(self, 0x10, 0);
}

PCREG(53f5d0, fn53f5d0);
