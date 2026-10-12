// batch2435.cpp - decomp area 24, batch 2435 (slice 11 leaves).
#include "ff.h"

extern "C" u32 THISCALL ext_563490(void *self, void *save);  // CBaseWindow::Save(ZSaveGame*)
extern "C" u32 THISCALL ext_5c34a0(void *self, void *db);    // CLightToggle::ReadInput(DBREAD&)

// 0x5ab0f0 ZOnScreenDisplay::StatsIncShotsFiredHero(), thiscall, plain ret.
static void THISCALL statsIncShotsFiredHero(u8 *self) {
  if (*(u32 *)(self + 0x300) != 0x10000000u)
    *(u32 *)(self + 0x8bf) += 1;
}
PCREG(5ab0f0, statsIncShotsFiredHero);

// 0x445170 ZROOM::SetEnvironment(ZBaseGeom*), thiscall, ret 4.
static void THISCALL roomSetEnvironment(u8 *self, u8 *env) {
  *(u8 **)(self + 0xb0) = env;
}
PCREG(445170, roomSetEnvironment);

// 0x65f5f0 ZDrawBuffer::PixelAspectXY() const, thiscall, plain ret, float on st0: slot 0xe8 of the object at +0x10.
static float THISCALL drawBufferPixelAspectXY(u8 *self) {
  void *t = *(void **)(self + 0x10);
  return vcall<float>(t, 0xe8);
}
PCREG(65f5f0, drawBufferPixelAspectXY);

// 0x5650f0 CFileWindow::Save(ZSaveGame*), thiscall, ret 4: tail jump to CBaseWindow::Save.
static u32 THISCALL fileWindowSave(u8 *self, void *save) {
  return ext_563490(self, save);
}
PCREG(5650f0, fileWindowSave);

// 0x5c30b0 CLightToggle::CopyEventDataBlock(DBREAD&), thiscall, ret 4: tail jump to CLightToggle::ReadInput.
static u32 THISCALL lightToggleCopyEventDataBlock(u8 *self, void *db) {
  return ext_5c34a0(self, db);
}
PCREG(5c30b0, lightToggleCopyEventDataBlock);
