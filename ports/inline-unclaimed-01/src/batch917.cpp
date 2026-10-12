#include "ff.h"
// batch917.cpp - unclaimed-01 claim 16 (docs/20-unclaimed-01.md). CHitpointControl::Init() (0x584580, high).
// Name from the GC name map. The full-list branch calls original code (0x4301c0) and is not reached by the spec's inputs.

static void THISCALL hitpointControlInit(u8 *self) {
  if (*(u8 *)(self + 0x63) != 0) {
    u8 *list = G(u8 *, 0x7003b8);
    u32 count = *(u32 *)(list + 0xb61);
    *(u32 *)(list + count * 4 + 0xb65) = (u32)self;
    *(u32 *)(list + 0xb61) = count + 1;
  }
  u8 *sub = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  typedef u32(THISCALL * slot4c_fn)(u8 *, u32);
  u32 value = ((slot4c_fn)(*(u32 *)(*(u32 *)sub + 0x4c)))(sub, *(u32 *)(self + 0x44));
  u8 *ring = G(u8 *, 0x7003b8) + 0x4a0;
  u32 wp = *(u32 *)(ring + 4);
  // (the full case, wp == end at +8, is not taken here)
  if (wp != 0)
    *(u32 *)wp = value;
  *(u32 *)(ring + 4) = wp + 4;
  *(u32 *)(self + 0x64) = *(u32 *)(self + 0x48);
  if (*(u8 *)(self + 0x56) != 0) {
    u8 *obj = *(u8 **)(self + 0x44);
    typedef void(THISCALL * slot_bc_fn)(u8 *, u32);
    ((slot_bc_fn)(*(u32 *)(*(u32 *)obj + 0xbc)))(obj, 1u);
  }
}
PCREG(584580, hitpointControlInit);
