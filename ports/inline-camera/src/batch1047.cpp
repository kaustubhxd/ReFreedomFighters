// batch1047.cpp - ZFFCameraClass::Load and ::Save wrappers around the engine camera's Load and Save. Camera thread,
// 2026-10-11. Each calls ZCAMERA::Load (0x446040) or ZCAMERA::Save (0x4464e0) first (ext: still the original code),
// then its own fields through the save or load object.
#include "cam.h"

extern "C" THISCALL u8 ext_446040(void *self, void *load);   // ZCAMERA::Load, returns al
extern "C" THISCALL u8 ext_4464e0(void *self, void *save);   // ZCAMERA::Save, returns al

// 0x5b2300 ZFFCameraClass::Load(ZLoadGame *load) (thiscall, one stack arg): the camera part, then byte +0x197,
// handle +0x198 (manager slot 0x58), matrix +0x19c, and 12 bytes at +0x1c0. Returns true.
static THISCALL u8 ZFFCameraClass_Load(u8 *self, u8 *load) {
  if (!ext_446040(self, load)) return 0;
  vcall<void>(load, 0x68, (void *)(self + 0x197));
  u32 tmp = 0;
  vcall<void>(load, 0x40, &tmp);
  at<u32>(self, 0x198) = vcall<u32>(SYS9B, 0x58, tmp);
  vcall<void>(load, 0x74, (void *)(self + 0x19c));
  vcall<void>(load, 0x6c, (void *)(self + 0x1c0));
  return 1;
}
PCREG(5b2300, ZFFCameraClass_Load);

// 0x5b2370 ZFFCameraClass::Save(ZSaveGame *save) (thiscall, one stack arg): the camera part, then byte +0x197,
// the dword +0x198 as it is, matrix +0x19c, and the 12 bytes at +0x1c0. Returns true.
static THISCALL u8 ZFFCameraClass_Save(u8 *self, u8 *save) {
  if (!ext_4464e0(self, save)) return 0;
  vcall<void>(save, 0x60, (u32)at<u8>(self, 0x197));
  vcall<void>(save, 0x64, at<u32>(self, 0x198));
  vcall<void>(save, 0x70, (void *)(self + 0x19c));
  vcall<void>(save, 0x68, (void *)(self + 0x1c0));
  return 1;
}
PCREG(5b2370, ZFFCameraClass_Save);
