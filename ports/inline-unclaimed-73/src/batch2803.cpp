// batch2803.cpp - area 73 batch 3 (residue 12): ZPlayer::CopyDataBlock(DBLK*) (0x482800, docs/20-unclaimed-73.md).
#include "ff.h"

// Helpers (original code, hooked in the spec): thiscall.
extern "C" void THISCALL ext_473370(u8 *self, u8 *dblk);
extern "C" u32 THISCALL ext_4e1600(u8 *self);
extern "C" void THISCALL ext_4e12e0(u8 *self, u32 p0, u32 p1);
extern "C" void THISCALL ext_4e1b30(u8 *self);
extern "C" void THISCALL ext_4dc630(u8 *self, u32 p0, u32 p1);

// 0x482800, ZPlayer::CopyDataBlock(DBLK*) (high), thiscall, ret 4: ext_473370(this, dblk); this+0x60e = 0; when
// ext_4e1600(dblk) has low byte 0x0b: ext_4e12e0(dblk, this+0x60e, 1); ext_4e1b30(dblk); ext_4dc630(this+8 object, 0, 1);
// slot +0x40 on this; obj = slot +0x20 on this; ext_4dc630(obj+8, 0, 1).
static void THISCALL zPlayerCopyDataBlock(u8 *self, u8 *dblk) {
  ext_473370(self, dblk);
  u8 *ebx = self + 0x60e;
  *(u32 *)ebx = 0;
  u8 al = (u8)ext_4e1600(dblk);
  if (al == 0x0b)
    ext_4e12e0(dblk, (u32)ebx, 1u);
  ext_4e1b30(dblk);
  ext_4dc630(*(u8 **)(self + 8), 0u, 1u);
  vcall<void>(self, 0x40);
  u8 *obj = (u8 *)vcall<u32>(self, 0x20);
  ext_4dc630(*(u8 **)(obj + 8), 0u, 1u);
}
PCREG(482800, zPlayerCopyDataBlock);
