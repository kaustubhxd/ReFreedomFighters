// batch1026.cpp - ZBaseCamera: Save, Load, RegisterMessages, Init (camera properties from the level).
// Camera thread, 2026-10-11.
#include "cam.h"

// 0x4fb2f0 ZBaseCamera::Save(ZSaveGame*): active, enabled (bytes, slot 0x60) and the camera control as a
// geometry handle (slot 0x3c; 0 when none). Clears flag 0x40 of +4. Returns 1 (AL).
static THISCALL u32 ZBaseCamera_Save(void *self, void *sg) {
  at<u32>(self, 4) &= 0xffffffbf;
  vcall<void>(sg, 0x60, (u32)at<u8>(self, 0x5a));
  vcall<void>(sg, 0x60, (u32)at<u8>(self, 0x5b));
  u8 *c = ptr(self, 0x5c);
  if (c) {
    u8 *vt = *(u8 **)sg;
    u32 h = vcall<u32>(SYS9B, 0x4c, at<u32>(c, 0x30));
    (*(void(THISCALL **)(void *, u32))(vt + 0x3c))(sg, h);
  } else {
    vcall<void>(sg, 0x3c, 0u);
  }
  return 1;
}
PCREG(4fb2f0, ZBaseCamera_Save);

// 0x4fb360 ZBaseCamera::Load(ZLoadGame*): messages registered again, active/enabled read back, the control found
// from its geometry handle by class "MainCameraControl".
static THISCALL u32 ZBaseCamera_Load(void *self, void *lg) {
  at<u32>(self, 4) &= 0xffffffbf;
  vcall<void>(self, 0x84);
  vcall<void>(lg, 0x68, &at<u8>(self, 0x5a));
  vcall<void>(lg, 0x68, &at<u8>(self, 0x5b));
  u32 h;
  vcall<void>(lg, 0x40, &h);
  if (h) {
    void *g = vcall<void *>(SYS9B, 0x58, h);
    at<u32>(self, 0x5c) = vcall<u32>(g, 0x100, (const char *)0x67d9e8);  // "MainCameraControl"
  } else {
    at<u32>(self, 0x5c) = 0;
  }
  return 1;
}
PCREG(4fb360, ZBaseCamera_Load);

// 0x4fb3e0 ZBaseCamera::RegisterMessages(): the camera message ids (basecamera.cpp lines 0x10f..0x117).
static THISCALL void ZBaseCamera_RegisterMessages(void *self) {
  static const u32 names[9] = {0x69c25c, 0x69c274, 0x69c288, 0x69c2ac, 0x69c2d0, 0x69c2e0, 0x688f94, 0x691ff0, 0x69c2f0};
  // Camera_RequestQuality, Camera_SendQuality, MainCameraControl_ActivateCamera, ..._DeactivateCamera,
  // EnableCamera, DisableCamera, Camera_Add, Camera_Remove, MSG_RESETCAMTOBESTPOS
  for (u32 i = 0; i < 9; i++)
    at<u16>(self, 0x48 + 2 * i) = (u16)vcall<u32>(SYS9B, 0x114, (const char *)names[i], 0u, (const char *)0x69c234, 0x10fu + i);
}
PCREG(4fb3e0, ZBaseCamera_RegisterMessages);

// A float level property through the property registry: pair = props slot 0x94(&tmp, name) -> {obj, index};
// value = obj slot 0x84(index, &f).
static inline float prop_float(void *props, const char *name) {
  u32 tmp[2];
  u32 *pair = vcall<u32 *>(props, 0x94, tmp, name);
  float f = 0.0f;
  void *obj = (void *)pair[0];
  vcall<void>(obj, 0x84, pair[1], &f);
  return f;
}

// 0x4fb040 ZBaseCamera::Init(): no control, active/enabled off, then the engine camera (+0x44) takes the level
// properties when present: CameraNear (slot 0x214), CameraFar (0x218), CameraTargetLen (0x220), CameraBackColor
// (three ints -> 0xRRGGBB, slot 0x21c) and CameraFOV (degrees, slot 0x224; default 67.4).
static THISCALL void ZBaseCamera_Init(void *self) {
  at<u32>(self, 0x5c) = 0;
  vcall<void>(self, 0x84);
  at<u32>(ptr(self, 0x44), 0x30) = 0;
  at<u16>(self, 0x5a) = 0;
  void *props = vcall<void *>(SYS9B, 0x138);
  static const u32 fprops[3] = {0x6922bc, 0x6922c8, 0x69c208};  // CameraNear, CameraFar, CameraTargetLen
  static const u32 fslots[3] = {0x214, 0x218, 0x220};
  for (int i = 0; i < 3; i++) {
    if (vcall<bool>(props, 0xa4, (const char *)fprops[i], 0u)) {
      float f = prop_float(props, (const char *)fprops[i]);
      vcall<void>(ptr(self, 0x44), fslots[i], f);
    }
  }
  if (vcall<bool>(props, 0xa4, (const char *)0x69c218, 0u)) {  // CameraBackColor
    u32 tmp[2];
    u32 *pair = vcall<u32 *>(props, 0x94, tmp, (const char *)0x69c218);
    s32 *c = vcall<s32 *>((void *)pair[0], 0x9c, pair[1], 4u);
    void *cam = ptr(self, 0x44);
    u32 rgb = (((u32)c[0] << 8) + (u32)c[1]) << 8;
    vcall<void>(cam, 0x21c, rgb + (u32)c[2]);
  }
  if (vcall<bool>(props, 0xa4, (const char *)0x69c228, 0u)) {  // CameraFOV
    float f = prop_float(props, (const char *)0x69c228);
    vcall<void>(ptr(self, 0x44), 0x224, f);
  } else {
    vcall<void>(ptr(self, 0x44), 0x224, bitsf(0x4286cccd));  // 67.4
  }
}
PCREG(4fb040, ZBaseCamera_Init);
