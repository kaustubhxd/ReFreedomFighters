// batch1033.cpp - ZCamHelper::Init2(): the helper's per-level setup (multiplayer flag, hero camera, crosshair,
// focus point from the hero). Camera thread, 2026-10-11.
#include "cam.h"

extern "C" THISCALL u32 ext_591ae0(void *hero);          // ZFFHERO::GetFFCamPtr (batch1025)
extern "C" THISCALL void ext_5922c0(void *hero, float *out);  // hero helper (writes a point)
extern "C" FASTCALL void ext_4de7a0(float *m);           // mreset (identity matrix)

// Debug output: the logger at 0x700390 gives a stream (slot 0x20: file, line); the stream's slot off is a
// printf-like cdecl (stream, message). Same convention as batch1011.
static inline void init2_log(u32 line, u32 off, const char *msg) {
  void *s = vcall<void *>(G(void *, 0x700390), 0x20, (const char *)0x6b4e78, line);  // CamHelper.cpp
  typedef void (*logfn)(void *, const char *);
  (*(logfn *)(*(u8 **)s + off))(s, msg);
}

// 0x5d00e0 ZCamHelper::Init2(): multiplayer flag (+0xe17) from the options object, the hero's camera (+0xc6d,
// +0xb54), the eye point (+0xd22), distance 500, the crosshair object for the hero's stance (+0x684: 2, 3, 4 or
// other), the main camera geometry placed from the hero's focus point (+0xc71..+0xc79). Without a main camera
// (the handle lookup of +0xc6d fails) it logs a warning and stops.
static THISCALL void ZCamHelper_Init2(u8 *self) {
  u8 *opts = vcall<u8 *>(SYS9B, 0x134);
  u8 mp = 0;
  vcall<void>(opts, 0x90, (const char *)0x68a9d4, &mp);  // "Multiplayer"
  at<u8>(self, 0xe17) = mp != 0;
  u8 *hero = ptr(self, 0x44);
  at<u32>(self, 0xc6d) = at<u32>(hero, 0x676);
  at<u32>(self, 0xb54) = ext_591ae0(hero);
  ext_5922c0(hero, &at<float>(self, 0xd22));
  float m[9];
  ext_4de7a0(m);
  at<float>(self, 0xb15) = 500.0f;
  u32 v = at<u32>(hero, 0x684);
  const char *name = (const char *)0x690418;  // "CrossHair"
  if (v == 2) name = (const char *)0x6b4ed4;  // "CrossHair2"
  if (v == 3) name = (const char *)0x6b4ee0;  // "CrossHair3"
  if (v == 4) name = (const char *)0x6b4eec;  // "CrossHair4"
  u8 *props = vcall<u8 *>(SYS9B, 0x138);
  u32 h = 0;
  vcall<void>(props, 0x88, name, &h);
  at<u32>(self, 0xae1) = h;
  if (!at<u8>(G(u8 *, 0x70039c), 0x6c)) at<u32>(self, 0xe1c) = 3;
  u8 *res = vcall<u8 *>(SYS9B, 0x58, at<u32>(self, 0xc6d));
  if (!res) {
    init2_log(0x136, 0x2c, (const char *)0x6b4ef8);  // "WARNING: ZFFHERO::ClassInit2() ... No Main camera !!!"
    return;
  }
  vcall<void>(res, 0x80, self + 0xcb9, self + 0xcad);
  float p[3];
  vcall<void>(hero, 0x378, p);
  vcall<void>(hero, 0x84, p);
  at<float>(self, 0xc71) = p[0];
  at<float>(self, 0xc75) = p[1];
  at<float>(self, 0xc79) = p[2];
}
PCREG(5d00e0, ZCamHelper_Init2);
