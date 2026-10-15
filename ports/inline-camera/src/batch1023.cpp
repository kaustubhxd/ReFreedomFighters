// batch1023.cpp - ZShakeCamera: the level event that shakes the main cameras (explosions etc.).
// Camera thread, 2026-10-11.
#include "cam.h"

extern "C" THISCALL long double ext_4e5e80(void *db);  // DBREAD::operator float (result in ST0)
extern "C" THISCALL u32 ext_4e5e40(void *db);          // DBREAD::operator unsigned short
extern "C" THISCALL u32 ext_4e5e60(void *db);          // DBREAD::operator unsigned int

// Fields: +0x44 own geometry, +0x48 message id to send, +0x4a strength, +0x4e radius, +0x52 trigger message id,
// +0x54 shake on start, +0x55/+0x59/+0x5d/+0x61 the level cameras "MainCamera", "MainCamera2..4".

// 0x5d3780 ZShakeCamera::Shake(): send {strength, own world position, radius} as message +0x48 from the own
// geometry (slot 0x130(receiver, id, data)) to each camera that has a receiver (camera slot 0x230). The camera
// side is ZFFCamera1::Command -> ShakeCamera(pos, strength, radius) (batch1002/1004).
static THISCALL void ZShakeCamera_Shake(void *self) {
  float v[3] = {0.0f, 0.0f, 0.0f};
  vcall<void>(ptr(self, 0x44), 0x84, v);
  float msg[5] = {at<float>(self, 0x4a), v[0], v[1], v[2], at<float>(self, 0x4e)};
  static const u16 cams[4] = {0x55, 0x59, 0x5d, 0x61};
  for (int i = 0; i < 4; i++) {
    void *cam = ptr(self, cams[i]);
    if (!cam) continue;
    u32 rcv = vcall<u32>(cam, 0x230);
    if (rcv) vcall<void>(ptr(self, 0x44), 0x130, rcv, (u32)at<u16>(self, 0x48), msg);
  }
}
PCREG(5d3780, ZShakeCamera_Shake);

// 0x5d3520 ZShakeCamera::FindCameras(): look the four main cameras up by name.
static THISCALL void ZShakeCamera_FindCameras(void *self) {
  static const u32 names[4] = {0x685a0c, 0x6ac8a8, 0x6ac8b4, 0x6ac8c0};  // "MainCamera", "MainCamera2".."4"
  static const u16 offs[4] = {0x55, 0x59, 0x5d, 0x61};
  for (int i = 0; i < 4; i++) {
    void *n = vcall<void *>(SYS9B, 0x138);
    u32 id = 0;
    vcall<void>(n, 0x88, (const char *)names[i], &id);
    at<u32>(self, offs[i]) = vcall<u32>(SYS9B, 0x58, id);
  }
}
PCREG(5d3520, ZShakeCamera_FindCameras);

// 0x5d3480 ZShakeCamera::Command(unsigned short, void*): the trigger message shakes.
static THISCALL u32 ZShakeCamera_Command(void *self, u32 cmd, void *) {
  if ((u16)cmd == at<u16>(self, 0x52)) ZShakeCamera_Shake(self);
  return 0;
}
PCREG(5d3480, ZShakeCamera_Command);

// 0x5d34a0 ZShakeCamera::CopyData(ZEventBase*)
static THISCALL void ZShakeCamera_CopyData(void *self, u8 *src) {
  at<u32>(self, 0x4a) = at<u32>(src, 0x4a);
  at<u16>(self, 0x52) = at<u16>(src, 0x52);
  at<u8>(self, 0x54) = at<u8>(src, 0x54);
  at<u32>(self, 0x4e) = at<u32>(src, 0x4e);
  ZShakeCamera_FindCameras(self);
  if (at<u8>(self, 0x54)) ZShakeCamera_Shake(self);
}
PCREG(5d34a0, ZShakeCamera_CopyData);

// 0x5d34e0 ZShakeCamera::CopyEventDataBlock(DBREAD&): strength (float), trigger message (u16), shake on start
// (u32 != 0), radius (float).
static THISCALL void ZShakeCamera_CopyEventDataBlock(void *self, void *db) {
  at<float>(self, 0x4a) = (float)ext_4e5e80(db);
  at<u16>(self, 0x52) = (u16)ext_4e5e40(db);
  at<u8>(self, 0x54) = ext_4e5e60(db) != 0;
  at<float>(self, 0x4e) = (float)ext_4e5e80(db);
}
PCREG(5d34e0, ZShakeCamera_CopyEventDataBlock);

// 0x5d3640 ZShakeCamera::Init(): find the cameras; shake at once when set to.
static THISCALL void ZShakeCamera_Init(void *self) {
  ZShakeCamera_FindCameras(self);
  if (at<u8>(self, 0x54)) ZShakeCamera_Shake(self);
}
PCREG(5d3640, ZShakeCamera_Init);
