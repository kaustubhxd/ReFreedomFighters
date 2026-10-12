// batch6320.cpp - unclaimed-63 batch 20 (docs/20-unclaimed-63.md): two functions.
//   0x49b3a0 ZSaveGame::bool_pack(bool x8) (GC name, medium): mask = bits 0..7 from the low bytes of the eight stack arguments
//     (argument 1 -> 0x01, argument 2 -> 0x02, ..., argument 8 -> 0x80; a bit is set when the byte is nonzero). Then the mask is
//     stored in a local and this->vtbl[+0x10](&local, 1) is called (thiscall, two stack arguments: the pointer, then 1), and the
//     function returns with ret 0x20 (eight stack words).
//   0x4ccfe0 REFTAB::~REFTAB() (GC name, low): this+0xc |= 0x80000000; node = [this+4]; [this] = 0x695734 (the REFTAB vptr); while
//     node: next = [node+4]; this->vtbl[+0x7c](node) (thiscall, one stack argument; the vtable is read after the vptr store), node =
//     next; then [this+4] = 0 and [this+0x14] = 0. The SEH frame of the PC is not reproduced (it only matters if an exception is
//     thrown). The /GS cookie is not checked here.
#include "ff.h"

typedef void(THISCALL * call2_fn)(void *, u8 *, u32);
typedef void(THISCALL * call1_fn)(void *, u32);

// 0x49b3a0, ZSaveGame::bool_pack (GC name, medium).
static void THISCALL saveGameBoolPack(u8 *self, u32 b1, u32 b2, u32 b3, u32 b4, u32 b5, u32 b6, u32 b7, u32 b8) {
  u8 m = 0;
  if ((u8)b1 != 0) m |= 0x01;
  if ((u8)b2 != 0) m |= 0x02;
  if ((u8)b3 != 0) m |= 0x04;
  if ((u8)b4 != 0) m |= 0x08;
  if ((u8)b5 != 0) m |= 0x10;
  if ((u8)b6 != 0) m |= 0x20;
  if ((u8)b7 != 0) m |= 0x40;
  if ((u8)b8 != 0) m |= 0x80;
  u8 local = m;
  ((call2_fn)(*(u32 *)(*(u32 *)self + 0x10)))((void *)self, &local, 1u);
}
PCREG(49b3a0, saveGameBoolPack);

// 0x4ccfe0, REFTAB::~REFTAB (GC name, low). SEH frame not reproduced.
static void THISCALL refTabDtor(u8 *self) {
  *(u32 *)(self + 0xc) |= 0x80000000u;
  u32 node = *(u32 *)(self + 4);
  *(u32 *)self = 0x695734u;
  while (node != 0) {
    u32 next = *(u32 *)(node + 4);
    ((call1_fn)(*(u32 *)(*(u32 *)self + 0x7c)))((void *)self, node);
    node = next;
  }
  *(u32 *)(self + 4) = 0;
  *(u32 *)(self + 0x14) = 0;
}
PCREG(4ccfe0, refTabDtor);
