// batch409.cpp - callees of ZPlayer::DebugControl (0x482b80): ZBaseGeom::GetSize (0x4db7c0) and
// ZBaseGeom::GetOwnerRoom (0x4db3b0). Names: GC names through the name map (both [high]).
#include "ff.h"

// ---------------------------------------------------------------- 0x4db7c0 ZBaseGeom::GetSize(float* out) [high]
// thiscall, ret 4: copies the three floats at +0x40 (the half-extents) to out.
static void THISCALL baseGeomGetSize(u8 *self, float *out) {
  out[0] = *(float *)(self + 0x40);
  out[1] = *(float *)(self + 0x44);
  out[2] = *(float *)(self + 0x48);
}
PCREG(4db7c0, baseGeomGetSize);

// ---------------------------------------------------------------- 0x4db3b0 ZBaseGeom::GetOwnerRoom() [high]
// thiscall, returns the room pointer. With flags 0x40040000 in +0x3c: when 0x40000000 is set, +0x5c (a room index,
// 16-bit, 1-based) selects an entry of the room table (0x70 bytes each, table from the room manager's slot 0x4c) and
// the room pointer from the room manager's slot 0x5c (index) is used when its byte +0x1c is set; otherwise the
// default room (render manager +0xadc) is returned. With neither flag: the first geom up the +0x50 chain (starting at
// the object) whose room record (+0x54) has a type dword 0x100021 at +0xc+0x23, else null. Both reads of the index
// go through the same address (no null guard), like the exe.
static u8 *THISCALL baseGeomGetOwnerRoom(u8 *self) {
  u8 *sys = G(u8 *, 0x70039c);
  u32 f = *(u32 *)(self + 0x3c);
  if (f & 0x40040000u) {
    u8 *rm = *(u8 **)(sys + 0x9b);
    u8 *rmo = *(u8 **)(rm + 8);
    u8 *esi;
    if (f & 0x40000000u) {
      if (*(u16 *)(self + 0x5c) == 0) {
        esi = 0;
      } else {
        u8 *table = vcall<u8 *>(rmo, 0x4c);
        esi = table + (u32)*(u16 *)(self + 0x5c) * 0x70 - 0x70;
      }
    } else {
      esi = self;
    }
    // esi may be null: the exe then reads address 0x5c. Go through a volatile integer address, so the compiler
    // cannot treat the null read as undefined and drop the zero-index branch.
    u16 w = *(volatile u16 *)((u32)esi + 0x5c);
    if (w) {
      u8 *ent = vcall<u8 *>(rmo, 0x5c, (u32)w);
      if (ent && ent[0x1c])
        return *(u8 **)ent;
    }
    return *(u8 **)(rm + 0xadc);
  }
  u8 *cur = self;
  while (cur) {
    u8 *room = *(u8 **)(cur + 0x54);
    if (room && *(u32 *)(*(u8 **)(room + 0xc) + 0x23) == 0x100021u)
      return room;
    cur = *(u8 **)(cur + 0x50);
  }
  return 0;
}
PCREG(4db3b0, baseGeomGetOwnerRoom);
