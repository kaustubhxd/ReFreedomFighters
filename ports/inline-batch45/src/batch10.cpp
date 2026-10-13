// batch10.cpp - first-level functions, inline session batch 10 (Haiku, overnight).
#include "ff.h"

// 0x647f70, thiscall (no stack args, returns this, or 0 for a null this): zeroes a 0x24-byte record and writes the
// marker 0xffff1203 at +4 and a zero byte at +0x16. Name unknown.
static u32 THISCALL initRecord(u8 *self) {
  if (self == nullptr)
    return 0;
  *(u32 *)(self + 0) = 0;
  *(u32 *)(self + 4) = 0xffff1203u;
  *(u32 *)(self + 8) = 0;
  *(u32 *)(self + 0xc) = 0;
  *(u32 *)(self + 0x10) = 0;
  *(u16 *)(self + 0x14) = 0;
  self[0x16] = 0;
  *(u32 *)(self + 0x18) = 0;
  *(u32 *)(self + 0x1c) = 0;
  *(u32 *)(self + 0x20) = 0;
  return (u32)(u8 *)self;
}
PCREG(647f70, initRecord);

// 0x640cc0, thiscall (no stack args, returns this): sets the vtable word 0x6c281c and clears a block of fields,
// including a 16-round loop that clears three dwords at a time. Name unknown.
static u32 THISCALL initBlock(u8 *esi) {
  *(u32 *)esi = 0x6c281cu;
  *(u32 *)(esi + 0x2a) = 0;
  *(u16 *)(esi + 0x14) = 0;
  *(u32 *)(esi + 4) = 0;
  *(u32 *)(esi + 0x17f) = 0;
  *(u32 *)(esi + 0x36) = 0;
  *(u32 *)(esi + 0x3a) = 0;
  u8 *ecx = esi + 0x7f;
  u8 *eax = esi + 0xc7;
  for (u32 edx = 16; edx != 0; edx--) {
    *(u32 *)(ecx - 0x40) = 0;
    ecx += 4;
    *(u32 *)(ecx - 4) = 0;
    eax += 0xc;
    *(u32 *)(eax - 0x14) = 0;
    *(u32 *)(eax - 0x10) = 0;
    *(u32 *)(eax - 0xc) = 0;
  }
  return (u32)esi;
}
PCREG(640cc0, initBlock);

// 0x648690, thiscall (no stack args, returns a pointer): like advanceSlot (0x613ae0) but with 20-byte nodes and the
// marker 0xffff1204. Returns node+0x10 or 0 when the index at this+2 is 0xffff. Name unknown.
static u32 THISCALL advanceSlot20(u8 *self) {
  u16 w = *(u16 *)(self + 2);
  if (w == 0xffff)
    return 0;
  u8 *node = self + (u32)w * 20u;
  *(u16 *)(self + 2) = *(u16 *)(node + 0x10);
  *(u32 *)(node + 0x10) = 0;
  *(u32 *)(node + 0x14) = 0xffff1204u;
  *(u32 *)(node + 0x18) = 0;
  *(u32 *)(node + 0x1c) = 0;
  *(u32 *)(node + 0x20) = 0;
  self[0] += 1;
  return (u32)(node + 0x10);
}
PCREG(648690, advanceSlot20);

// 0x648750, same shape as advanceSlot20 with the marker 0xffff1205. Name unknown.
static u32 THISCALL advanceSlot20b(u8 *self) {
  u16 w = *(u16 *)(self + 2);
  if (w == 0xffff)
    return 0;
  u8 *node = self + (u32)w * 20u;
  *(u16 *)(self + 2) = *(u16 *)(node + 0x10);
  *(u32 *)(node + 0x10) = 0;
  *(u32 *)(node + 0x14) = 0xffff1205u;
  *(u32 *)(node + 0x18) = 0;
  *(u32 *)(node + 0x1c) = 0;
  *(u32 *)(node + 0x20) = 0;
  self[0] += 1;
  return (u32)(node + 0x10);
}
PCREG(648750, advanceSlot20b);
