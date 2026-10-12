// batch6450.cpp - unclaimed-68 batch 45 (claim 45, gap band). Name from the GC name map. Helper 0x4db3b0 runs as exe code.
#include "ff.h"

extern "C" u32 THISCALL ext_4db3b0(u8 *self);
typedef u8 *(THISCALL *VSlot20)(u8 *self);

// 0x4a4220, ZSoundAmbient::GetListenerRoom(unsigned char): thiscall, ret 4. A non-null entry at this+0x1c8+4*idx gives r = slot +0x20;
// ext_4db3b0 on [r+8] gives v, returned when nonzero. Otherwise the engine's dword at [[0x70039c]+0x9b]+0xadc is returned.
static u32 THISCALL soundAmbientGetListenerRoom(u8 *self, u32 idx) {
  u8 *c = *(u8 **)(self + (u8)idx * 4 + 0x1c8);
  if (c) {
    u8 *r = ((VSlot20)*(u32 *)(*(u8 **)c + 0x20))(c);
    u32 v = ext_4db3b0(*(u8 **)(r + 8));
    if (v) return v;
  }
  u8 *eng = G(u8 *, 0x70039c);
  u8 *en = *(u8 **)(eng + 0x9b);
  return *(u32 *)(en + 0xadc);
}
PCREG(4a4220, soundAmbientGetListenerRoom);
