// batch2457.cpp - decomp area 24, batch 2457 (gap band).
#include "ff.h"

extern "C" void THISCALL ext_447640(void *self, u32 a0, u32 a1, u32 a2);   // base constructor, ret 12
extern "C" void THISCALL ext_610100(void *self, void *dblk);               // ZRenderGC::Init(DBLK*), bare ret 4
extern "C" u32 THISCALL ext_4e12e0(void *db, u32 *out, u32 count);         // DBLK::Get(unsigned int*, int)
extern "C" u32 THISCALL ext_4e1b30(void *db);                              // DBLK::NextBlock()

// 0x452990 (GUESS), thiscall, ret 12, eax = this.
static u8 *THISCALL unnamedCtor452990(u8 *self, u32 a0, u32 a1, u32 a2) {
  ext_447640(self, a0, a1, a2);
  *(u32 *)self = 0x681860u;
  *(u32 *)(self + 0x18) = 0x3000u;
  *(u32 *)(self + 0x1c) = (u32)self;
  *(u32 *)(self + 0x20) = (u32)self;
  return self;
}
PCREG(452990, unnamedCtor452990);

// 0x44d040 ZMotionBlur::CopyDataBlock(DBLK*), thiscall, ret 4.
static void THISCALL motionBlurCopyDataBlock(u8 *self, void *db) {
  ext_610100(self, db);
  ext_4e12e0(db, (u32 *)(self + 0x470), 0x10u);
  ext_4e1b30(db);
}
PCREG(44d040, motionBlurCopyDataBlock);
