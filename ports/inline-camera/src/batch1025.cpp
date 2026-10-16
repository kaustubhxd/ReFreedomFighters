// batch1025.cpp - hero aim helpers: HasSniperMode, GetFFCamPtr, OnlyVerticalAim, aim animations, aim-in callback.
// Camera thread, 2026-10-11.
#include "cam.h"

extern "C" THISCALL void ext_4dc630(void *geom, u32 set, u32 mask);  // ZBaseGeom::SetControl
extern "C" FASTCALL void ext_43e920(float *d, const float *a, const float *b);  // d = a - b
extern "C" THISCALL void ext_4816e0(void *self);                      // ZPlayer::CallBackAimInPosition
extern "C" THISCALL u32 ext_473e50(void *self);                       // ZLNKWHANDS::GetAimAnim

// 0x46efe0 ZItemTemplateWeapon::HasSniperMode() const: byte +0xc6 of the weapon template.
static THISCALL u32 ZItemTemplateWeapon_HasSniperMode(void *self) { return at<u8>(self, 0xc6); }
PCREG(46efe0, ZItemTemplateWeapon_HasSniperMode);

// 0x591ae0 ZFFHERO::GetFFCamPtr(): the "FFCamera1" object of the hero's camera geometry (+0x84e), cached at +0x85e.
static THISCALL u32 ZFFHERO_GetFFCamPtr(void *self) {
  if (at<u32>(self, 0x85e) == 0) {
    void *g = ptr(self, 0x84e);
    if (g) at<u32>(self, 0x85e) = vcall<u32>(g, 0x100, (const char *)0x6ad00c);  // "FFCamera1"
  }
  return at<u32>(self, 0x85e);
}
PCREG(591ae0, ZFFHERO_GetFFCamPtr);

// 0x593ae0 ZFFHERO::OnlyVerticalAim() const / 0x594fa0 ZFFHERO::SetOnlyVerticalAim(bool): byte +0x828.
static THISCALL u32 ZFFHERO_OnlyVerticalAim(void *self) { return at<u8>(self, 0x828); }
PCREG(593ae0, ZFFHERO_OnlyVerticalAim);
static THISCALL u32 ZFFHERO_SetOnlyVerticalAim(void *self, u32 on) {
  at<u8>(self, 0x828) = (u8)on;
  return on;
}
PCREG(594fa0, ZFFHERO_SetOnlyVerticalAim);

// Weapon type of a held item: item slot 0x350 (template) -> slot 0x330.
static inline u32 item_type(void *item) { return vcall<u32>(vcall<void *>(item, 0x350), 0x330); }

// 0x473e50 ZLNKWHANDS::GetAimAnim() const: aim animation by the right-hand (slot 0x50c) weapon type: none ->
// +0x266; types 0-1 -> +0x2d7 when the left hand (slot 0x508) holds the same type (dual), else +0x2db; 2-6 ->
// +0x2d3; 7 -> +0x2df; 8-10 and above 11 -> +0x2db; 11 -> 0.
static THISCALL u32 ZLNKWHANDS_GetAimAnim(void *self) {
  void *w = vcall<void *>(self, 0x50c);
  if (!w) return at<u32>(self, 0x266);
  u32 t = item_type(w);
  if (t <= 11) {
    static const u8 map[12] = {0, 0, 1, 1, 1, 1, 1, 2, 4, 4, 4, 3};
    switch (map[t]) {
      case 0: {
        void *l = vcall<void *>(self, 0x508);
        if (!l) break;
        void *lt = vcall<void *>(l, 0x350);
        u32 rt = item_type(w);
        if (vcall<u32>(lt, 0x330) == rt) return at<u32>(self, 0x2d7);
        break;
      }
      case 1: return at<u32>(self, 0x2d3);
      case 2: return at<u32>(self, 0x2df);
      case 3: return 0;
      default: break;
    }
  }
  return at<u32>(self, 0x2db);
}
PCREG(473e50, ZLNKWHANDS_GetAimAnim);

// 0x591880 ZFFHERO::GetAimAnim() const: hero flags first (0x40000: none, 0x2000000: +0x744), then, when the hero
// uses its own aim set (slot 0x49c), by weapon type: 0-1 -> +0x74c (two items) or +0x750, 2-6 -> +0x754,
// 7 -> +0x758; type 3 -> +0x740, 10-12 -> none, else the generic ZLNKWHANDS choice.
static THISCALL u32 ZFFHERO_GetAimAnim(void *self) {
  u32 f = at<u32>(self, 0x417);
  if (f & 0x40000) return 0;
  if (f & 0x2000000) return at<u32>(self, 0x744);
  void *w = vcall<void *>(self, 0x50c);
  if (!w) return at<u32>(self, 0x266);
  if (vcall<bool>(self, 0x49c)) {
    u32 t = item_type(w);
    if (t <= 7) {
      if (t <= 1) return vcall<void *>(self, 0x508) ? at<u32>(self, 0x74c) : at<u32>(self, 0x750);
      if (t <= 6) return at<u32>(self, 0x754);
      return at<u32>(self, 0x758);
    }
  }
  u32 t = item_type(w);
  if (t == 3) return at<u32>(self, 0x740);
  if (t - 10 <= 2) return 0;
  return ext_473e50(self);
}
PCREG(591880, ZFFHERO_GetAimAnim);

// 0x58c2b0 ZFFHERO::CallBackAimInPosition(): when the aim pose is reached: time stamp (+0x813, s), then the shot
// origin of the held weapon (weapon +0x109): the camera helper's eye point while aiming (+0xb45), else the
// weapon's own point (slot 0x34c); it is pulled back to the hero's body line if a line test (collision
// manager slot 0x30, hero flags 6 off) from the hero's origin at that height hits something.
static THISCALL void ZFFHERO_CallBackAimInPosition(void *self) {
  at<u8>(self, 0x7f0) = 0;
  at<float>(self, 0x813) = (float)at<s32>(G(u8 *, 0x70039c), 0x40) * G(float, 0x6785e4);
  u8 *w = vcall<u8 *>(self, 0x50c);
  if (!w) return;
  float pos[3];
  if (at<u8>(ptr(self, 0x85a), 0xb45)) {
    if (!ptr(self, 0x85a)) at<u32>(self, 0x85a) = vcall<u32>(self, 0x100, (const char *)0x6a6e88);  // "ZCamHelper"
    u8 *h = ptr(self, 0x85a);
    pos[0] = at<float>(h, 0xd22);
    pos[1] = at<float>(h, 0xd26);
    pos[2] = at<float>(h, 0xd2a);
  } else {
    vcall<void>(w, 0x34c, pos);
  }
  float q[3] = {0.0f, 0.0f, 0.0f};
  vcall<void>(self, 0x84, q);
  float p2[3] = {pos[0], pos[1], pos[2]};
  q[1] = pos[1];
  float d[3];
  ext_43e920(d, p2, q);
  u32 saved = at<u32>(ptr(self, 8), 0x3c) & 6;
  ext_4dc630(ptr(self, 8), 0, 6);
  alignas(4) u8 rec[0x48];
  *(u32 *)rec = 0x3f800000;
  void *coll = ptr(ptr(G(u8 *, 0x70039c), 0x1aa3), 0x1c);
  if (vcall<bool>(coll, 0x30, rec, 0u, q, d, 1u, 2u, 1u, 1u)) {
    pos[0] = q[0];
    pos[1] = q[1];
    pos[2] = q[2];
  }
  ext_4dc630(ptr(self, 8), saved, 0);
  at<float>(w, 0x109) = pos[0];
  at<float>(w, 0x10d) = pos[1];
  at<float>(w, 0x111) = pos[2];
  ext_4816e0(self);
}
PCREG(58c2b0, ZFFHERO_CallBackAimInPosition);
