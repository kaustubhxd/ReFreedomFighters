// batch1014.cpp - unclaimed-07 batch 14 (docs/20-unclaimed-07.md, slice 6): CSteeringWheel::Init.
// Name from the GC name map (high). Body from the PC bytes.
#include "ff.h"

// 0x529960, CSteeringWheel::Init(ZGROUP*, ZGROUP*, bool) (high), thiscall, ret 12.
//   blk = this+4 (zeroed, +0x18 = g). g slot +0x84(blk); p slot +0x8c(blk); this+0x1c..0x24 = blk[0..2]; this+0x20 = 0.
//   r = g slot +0x25c(0x6a0bfc, 0). When r is non-null: member object at this+0x30 slot +0(g, r, flag); returns true.
//   Otherwise the engine log (global 0x700390): stream = slot +0x20(0x6a0c04, 0x14e); the names are g+4 and p+4
//   (or 0x67c8e8 when null); stream cdecl slot +0x2c(stream, 0x6a0c30, name2(p), name1(g)); returns false.
static bool THISCALL steeringWheelInit(u8 *self, u8 *p, u8 *g, u32 flag) {
  u8 *blk = self + 4;
  *(u32 *)(self + 4) = 0;
  *(u32 *)(self + 8) = 0;
  *(u32 *)(self + 0xc) = 0;
  *(u32 *)(self + 0x18) = (u32)g;
  vcall<void>(g, 0x84, (u32)blk);
  vcall<void>(p, 0x8c, (u32)blk);
  *(u32 *)(self + 0x1c) = *(u32 *)(self + 4);
  *(u32 *)(self + 0x20) = *(u32 *)(self + 8);
  *(u32 *)(self + 0x24) = *(u32 *)(self + 0xc);
  *(u32 *)(self + 0x20) = 0;
  u32 r = vcall<u32>(g, 0x25c, 0x6a0bfcu, 0u);
  if (r) {
    vcall<void>(self + 0x30, 0, (u32)g, r, flag);
    return true;
  }
  void *logger = *(void **)0x700390;
  void *stream = vcall<void *>(logger, 0x20, 0x6a0c04u, 0x14eu);
  u32 name1 = *(u32 *)(g + 4) ? *(u32 *)(g + 4) : 0x67c8e8u;
  u32 name2 = *(u32 *)(p + 4) ? *(u32 *)(p + 4) : 0x67c8e8u;
  typedef void(__attribute__((cdecl)) * printf_t)(void *, u32, u32, u32);
  (*(printf_t *)(*(u8 **)stream + 0x2c))(stream, 0x6a0c30u, name2, name1);
  return false;
}
PCREG(529960, steeringWheelInit);
