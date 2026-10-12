// batch2442.cpp - decomp area 24, batch 2442 (gap band).
#include "ff.h"

extern "C" void THISCALL ext_610100(void *self, void *dblk);  // ZRenderGC::Init(DBLK*), bare ret 4
extern "C" u32 THISCALL ext_4e1b30(void *dblk);               // DBLK::NextBlock()
extern "C" void THISCALL ext_44a1f0(void *self);              // ZLNKWHANDS::ResetTargets()
extern "C" void THISCALL ext_4dcbb0(void *self, u32 owner);  // ZBaseGeom::SetOwnerDraw(bool)

// 0x44d000 ZMotionBlur::ClassInit(), thiscall, plain ret: SetOwnerDraw(1) on the object at +8.
static void THISCALL motionBlurClassInit(u8 *self) {
  ext_4dcbb0(*(void **)(self + 8), 1u);
}
PCREG(44d000, motionBlurClassInit);

// 0x444fa0 ZROOM::NotInRoomTree(), thiscall, AL: bit 2 of slot 0x37c's result.
static u8 THISCALL roomNotInRoomTree(u8 *self) {
  u32 v = vcall<u32>(self, 0x37c);
  return (u8)((v >> 2) & 1u);
}
PCREG(444fa0, roomNotInRoomTree);

// 0x44a700 ZLIST::Script_GetRefNr(int), thiscall, ret 4: tail jump to slot 0x30 of the object at +0x18.
static u32 THISCALL listScriptGetRefNr(u8 *self, u32 idx) {
  return vcall<u32>(*(void **)(self + 0x18), 0x30, idx);
}
PCREG(44a700, listScriptGetRefNr);

// 0x455af0 ZParticleController::CopyDataBlock(DBLK*), thiscall, ret 4.
static u32 THISCALL particleControllerCopyDataBlock(u8 *self, void *dblk) {
  ext_610100(self, dblk);
  return ext_4e1b30(dblk);
}
PCREG(455af0, particleControllerCopyDataBlock);

// 0x454850 ZTemplate::ClassInit(), thiscall, plain ret: ResetTargets, then the global function pointer (tail jump).
static void THISCALL templateClassInit(u8 *self) {
  (void)self;
  ext_44a1f0(self);
  typedef void (*fn0)(void);
  fn0 fn = *(fn0 *)0x7003b0;
  if (!fn)
    __builtin_trap();
  fn();
}
PCREG(454850, templateClassInit);
