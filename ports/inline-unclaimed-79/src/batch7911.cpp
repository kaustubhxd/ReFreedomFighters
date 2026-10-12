#include "ff.h"
// batch7911.cpp - unclaimed-79 batch 11 (docs/20-unclaimed-79.md). Name from the GC name map (naming only).
// SEH frame not reproduced (fs:[0] writes not compared). The callees run as original code (stubbed by the harness).

extern "C" void *ext_41e290(u32 size);                     // cdecl allocator (caller pops)
extern "C" void THISCALL ext_4780f0(u8 *self, u8 *blk);
extern "C" void THISCALL ext_4e12e0(u8 *blk, u8 *p, u32 n);
extern "C" void THISCALL ext_4e11e0(u8 *blk, u8 *p, u32 n);
extern "C" u8 THISCALL ext_4e1600(u8 *blk);
extern "C" void THISCALL ext_4e1b30(u8 *blk);
extern "C" u32 THISCALL ext_59d330(u8 *obj, u8 *a, u32 b);

// 0x59ee60, ZFFActor::CopyDataBlock(DBLK*) (high). Thiscall, one stack argument (ret 4).
static void THISCALL ffActorCopyDataBlock(u8 *self, u8 *blk) {
  u8 *b = blk;
  u32 v18 = 0, v10 = 0, v14 = 0;
  ext_4780f0(self, b);
  ext_4e12e0(b, (u8 *)&v18, 1u);
  ext_4e11e0(b, (u8 *)&v10, 1u);
  u8 *obj = (u8 *)ext_41e290(0x18u);
  u32 res = 0;
  if (obj != 0)
    res = ext_59d330(obj, self, v10);
  *(u32 *)(self + 0x54) = res;
  ext_4e12e0(b, self + 0x792, 1u);
  ext_4e11e0(b, self + 0x79a, 1u);
  if (ext_4e1600(b) == 8)
    ext_4e12e0(b, self + 0x796, 1u);
  else
    *(u32 *)(self + 0x796) = 0;
  ext_4e12e0(b, (u8 *)&blk, 1u);   // the exe writes its argument slot here, then reads it back
  ext_4e12e0(b, (u8 *)&v14, 1u);
  if (blk != 0) {
    u8 *y = *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x1aa3) + 0x18);
    u32 r = vcall<u32, u32>(y, 0xc, (u32)(unsigned long)blk);
    vcall<void, u32>(self, 0x5a4, r);
    if (blk != 0) {
      u8 *y2 = *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x1aa3) + 0x18);
      u32 r2 = vcall<u32, u32>(y2, 0xc, v14);
      vcall<void, u32>(self, 0x5a4, r2);
    }
  }
  ext_4e1b30(b);
}
PCREG(59ee60, ffActorCopyDataBlock);
