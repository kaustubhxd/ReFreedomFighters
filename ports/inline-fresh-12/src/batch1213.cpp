// batch1213.cpp - fresh slice 12, batch 13. Exe callees run as ext_<hex>; the harness hooks and logs them.
#include "ff.h"

extern "C" void THISCALL ext_469870(u8 *self);            // base constructor, ret 0
extern "C" void THISCALL ext_4ccba0(u8 *self);            // member constructor, ret 0
extern "C" void THISCALL ext_4cfc70(u8 *self, u8 *blk);   // ret 4
extern "C" void THISCALL ext_4d09b0(u8 *self, u8 *blk, u32 n);   // ret 8

// 0x65f600: aspect correction. a, b = engine(+0x190f) slots 0xd8 / 0xdc (ints), c, d = this slots 0 / 4 (ints);
// returns ((float)d / b) / (c / a) in single precision (SSE), as a float in ST0.
static float THISCALL aspect65f600(u8 *self) {
  u8 *v = *(u8 **)(G(u8 *, 0x70039c) + 0x190f);
  float a = (float)vcall<s32>(v, 0xd8);
  float b = (float)vcall<s32>(v, 0xdc);
  float c = (float)vcall<s32>(self, 0);
  float d = (float)vcall<s32>(self, 4);
  return d / b / (c / a);
}
PCREG(65f600, aspect65f600);

// 0x4a3b40: constructor (SEH frame, ESI restored). Base 0x469870, +4 |= 0x20, +0x44 = 0, vtable 0x68fbe8, member
// ctors 0x4ccba0 on +0x5c and +0x108, then +0x48..+0x54 = 0. Returns this.
static u8 *THISCALL ctor4a3b40(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x68fbe8;
  ext_4ccba0(self + 0x5c);
  ext_4ccba0(self + 0x108);
  *(u32 *)(self + 0x48) = 0;
  *(u32 *)(self + 0x4c) = 0;
  *(u32 *)(self + 0x50) = 0;
  *(u32 *)(self + 0x54) = 0;
  return self;
}
PCREG(4a3b40, ctor4a3b40);

// 0x4d08c0: heap block take. blk has its free size at +8 (stored negated once used) and data from +0x10. When more than
// 0x18 bytes would be left after n, the tail becomes a new free block at blk + 0x10 + n (size rem - 0x10, prev -n),
// linked by 0x4cfc70, with its trailing size word set; else the whole block is taken (n = size) and its trailer at
// +0x1c + size = -size. Then blk+8 = -n, self+0 += n + 0x10, byte +0x1e9 = 0, 0x4d09b0(blk, n), blk+4 = self+0x821c.
// Returns blk. ret 8.
static u8 *THISCALL take4d08c0(u8 *self, u8 *blk, u32 n) {
  u32 size = *(u32 *)(blk + 8);
  u32 rem = size - n;
  if (rem > 0x18) {
    u8 *t = blk + 0x10 + n;
    *(u32 *)(t + 8) = rem - 0x10;
    *(u32 *)(t + 0xc) = (u32)-n;
    ext_4cfc70(self, t);
    *(u32 *)(t + rem + 0xc) = rem - 0x10;
  } else {
    n = size;
    *(u32 *)(blk + n + 0x1c) = (u32)-n;
  }
  *(u32 *)(blk + 8) = (u32)-n;
  *(u32 *)self += n + 0x10;
  self[0x1e9] = 0;
  ext_4d09b0(self, blk, n);
  *(u32 *)(blk + 4) = *(u32 *)(self + 0x821c);
  return blk;
}
PCREG(4d08c0, take4d08c0);
