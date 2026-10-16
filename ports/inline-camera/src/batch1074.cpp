// batch1074.cpp - the empty camera event readers. Camera thread, 2026-10-12.
#include "cam.h"

// 0x610100 (one stack arg, ret 4): the shared empty body. The class map names it ZCamHelper::CopyEventDataBlock,
// ZBaseCamera::CopyEventDataBlock, ZBaseCamera::CopyData and ZCAMERA::SetCamPrio (the body is the same for all).
static THISCALL void ZCAM_EmptyBody(u8 *self, u32 arg) {
  (void)self;
  (void)arg;
}
PCREG(610100, ZCAM_EmptyBody);

// 0x57f350 (one stack arg): a tail jump to 0x610100. The class map names it ZFFCam::CopyEventDataBlock(DBREAD&).
static THISCALL void ZFFCam_CopyEventDataBlock_Empty(u8 *self, u32 arg) {
  (void)self;
  (void)arg;
}
PCREG(57f350, ZFFCam_CopyEventDataBlock_Empty);

// 0x565a30 (one stack arg): a tail jump to 0x57f350, so also empty. The class map names it ZFFCamera1::CopyEventDataBlock(DBREAD&).
static THISCALL void ZFFCamera1_CopyEventDataBlock_Empty(u8 *self, u32 arg) {
  (void)self;
  (void)arg;
}
PCREG(565a30, ZFFCamera1_CopyEventDataBlock_Empty);
