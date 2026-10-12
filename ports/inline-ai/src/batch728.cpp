// batch728.cpp - soldier AI, batch 728 (2026-10-12): ZTargetObtained2 (target-perception event object). The object keeps a
// unique id (+0x48, from the level controller's unique-bit table at gl+0x2c15, gl = 0x7003b8), a command word (+0x4c), a dword
// (+0x4e, unaligned) and a word (+0x52) read from a DBREAD.
//   Command(cmd, data): if cmd == +0x4c, set the id's state bit (controller 0x59d250 (2, id, 1)); returns 0.
//   Init2(): if a controller exists, the id is taken from it (0x59d130 (2)); else the object's slot 0x68 (0x10, 0) is called.
//   FrameUpdate(): if the id's state bit is set (0x59d150 (2, id)), SendNotify (0x5b7ad0); then slot 0x68 (0x10, 0).
//   CopyEventDataBlock(DBREAD&): reads word -> +0x4c, dword -> +0x4e, word -> +0x52 in that order.
// The controller and SendNotify run as exe code in the port's ext_ calls; the spec hooks them.
#include "ff.h"

extern "C" u32 THISCALL ext_59d130(void *ctrl, u32 a);                   // ZFFLevelController::UniqueBitGetID
extern "C" u8 THISCALL ext_59d150(void *ctrl, u32 a, u32 b);            // ZFFLevelController::UniqueBitGetIDState (al)
extern "C" void THISCALL ext_59d250(void *ctrl, u32 a, u32 b, u32 c);   // ZFFLevelController::UniqueBitSetIDState
extern "C" void THISCALL ext_5b7ad0(void *self);                        // ZTargetObtained2::SendNotify
extern "C" u32 THISCALL ext_4e5e40(void *rd);                           // DBREAD::operator unsigned short
extern "C" u32 THISCALL ext_4e5e60(void *rd);                           // DBREAD::operator unsigned int

static inline void *controller() { return *(void **)(*(u8 **)0x7003b8 + 0x2c15); }

// 0x5b7a10 ZTargetObtained2::Command(unsigned short cmd, void* data) [high].
static u32 THISCALL target2_Command(u8 *self, u32 cmd, void *data) {
  (void)data;
  if ((u16)cmd == *(u16 *)(self + 0x4c))
    ext_59d250(controller(), 2u, *(u32 *)(self + 0x48), 1u);
  return 0;
}
PCREG(5b7a10, target2_Command);

// 0x5b7a40 ZTargetObtained2::CopyEventDataBlock(DBREAD&) [high].
static void THISCALL target2_CopyEventDataBlock(u8 *self, void *rd) {
  *(u16 *)(self + 0x4c) = (u16)ext_4e5e40(rd);
  *(u32 *)(self + 0x4e) = ext_4e5e60(rd);
  *(u16 *)(self + 0x52) = (u16)ext_4e5e40(rd);
}
PCREG(5b7a40, target2_CopyEventDataBlock);

// 0x5b7a70 ZTargetObtained2::FrameUpdate() [high].
static void THISCALL target2_FrameUpdate(u8 *self) {
  if (ext_59d150(controller(), 2u, *(u32 *)(self + 0x48)))
    ext_5b7ad0(self);
  vcall<void>(self, 0x68, 0x10u, 0u);
}
PCREG(5b7a70, target2_FrameUpdate);

// 0x5b7aa0 ZTargetObtained2::Init2() [high].
static void THISCALL target2_Init2(u8 *self) {
  void *ctrl = controller();
  if (ctrl) {
    *(u32 *)(self + 0x48) = ext_59d130(ctrl, 2u);
    return;
  }
  vcall<void>(self, 0x68, 0x10u, 0u);
}
PCREG(5b7aa0, target2_Init2);
