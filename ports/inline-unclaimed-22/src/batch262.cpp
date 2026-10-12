// batch262.cpp - area 22 gameplay-core batch (docs/20-unclaimed-22.md, "Gameplay core, batch262"): weapon template getters,
// spline vehicles (frame update, target, script interface) and the hint box load. Names from the GameCube name map.
#include "ff.h"

extern "C" void THISCALL ext_4690b0(u8 *self);   // empty method (ret), runs as exe code
extern "C" void THISCALL ext_523280(u8 *path);   // CMoveAlongPath::FrameUpdate (hooked, GUESS stub; disputed in docs/39)
extern "C" void THISCALL ext_5121e0(u8 *self);   // ZMoveOnSpline::AnimUpdate (hooked recorder; verified in inline-unclaimed-81)
extern "C" void THISCALL ext_50a410(u8 *self, u8 *buf);   // ZGeomIf::collectOpaqueInfo (hooked, GUESS stub)
extern "C" void THISCALL ext_504560(u8 *self, u8 *p);     // ZGeomIf::opaqueCall (hooked, GUESS stub)

#define DB (*(u8 **)(*(u8 **)0x70039cu + 0x9b))

// 0x46ed10 ZItemTemplateWeapon::GetPitchChange() const: the word at +0xd3.
static u32 THISCALL getPitchChange_46ed10(u8 *self) { return *(u32 *)(self + 0xd3); }
PCREG(46ed10, getPitchChange_46ed10);

// 0x46efd0 ZItemTemplateWeapon::GetWeaponType() const: the word at +0x9c.
static u32 THISCALL getWeaponType_46efd0(u8 *self) { return *(u32 *)(self + 0x9c); }
PCREG(46efd0, getWeaponType_46efd0);

// 0x46ecd0 ZItemTemplateWeapon::GetMuzzleVelocity() const: the float at +0xa8 (st0).
static float THISCALL getMuzzleVelocity_46ecd0(u8 *self) { return *(float *)(self + 0xa8); }
PCREG(46ecd0, getMuzzleVelocity_46ecd0);

// 0x514350 ZMoveOnSpline::SendTargetForVehicle(unsigned to, int target) ret 8: SendCommand slot 0x12c (handle, cmd, data)
// to `to` with the message id at +0x211 (word) and a stack pair {db->vt[0x4c](this) (own handle), target}.
static void THISCALL sendTargetForVehicle_514350(u8 *self, u32 to, u32 target) {
  u32 pair[2];
  pair[0] = vcall<u32>(DB, 0x4c, (u32)self);
  pair[1] = target;
  vcall<void>(self, 0x12c, to, (u32) * (u16 *)(self + 0x211), (u32)pair);
}
PCREG(514350, sendTargetForVehicle_514350);

// 0x5b7710 ZFFHintBox::Load(ZLoadGame *l) ret 4, returns al = 1: clears flag 0x40 at +4, reads +0x4c (slot 0x48) and the
// target id +0x48 (slot 0x40), and stores the geom (db vt[0x58]) of that id at +0x50.
static bool THISCALL hintBoxLoad_5b7710(u8 *self, u8 *l) {
  *(u32 *)(self + 4) &= ~0x40u;
  vcall<void>(l, 0x48, (u32)(self + 0x4c));
  vcall<void>(l, 0x40, (u32)(self + 0x48));
  *(u32 *)(self + 0x50) = vcall<u32>(DB, 0x58, *(u32 *)(self + 0x48));
  return true;
}
PCREG(5b7710, hintBoxLoad_5b7710);

// 0x512450 ZMoveOnSpline::ClassFrameUpdate() (no args): the base's empty method 0x4690b0; with a path running (the
// CMoveAlongPath at +0x5c has +0x4b set): its FrameUpdate 0x523280, vt[0x354](), vt[0x2f4](), vt[0x34c](), AnimUpdate
// 0x5121e0, vt[0x320]() (tail call). Without one, when byte +0x133 is set: vt[0x354](), vt[0x320]().
static void THISCALL classFrameUpdate_512450(u8 *self) {
  ext_4690b0(self);
  u8 *p = *(u8 **)(self + 0x5c);
  if (*(u32 *)(p + 0x4b)) {
    ext_523280(p);
    vcall<void>(self, 0x354);
    vcall<void>(self, 0x2f4);
    vcall<void>(self, 0x34c);
    ext_5121e0(self);
    vcall<void>(self, 0x320);
    return;
  }
  if (self[0x133]) {
    vcall<void>(self, 0x354);
    vcall<void>(self, 0x320);
  }
}
PCREG(512450, classFrameUpdate_512450);

// 0x51a790 ZMoveOnSplineIf::collectOpaqueInfo(OpaqueObjectSerialBuffer_t &buf) ret 4: the base's collectOpaqueInfo, then
// buf->vt[0](this->vt[0x38]()) (buf's vtable is read after the base call, before the this call).
static void THISCALL collectOpaqueInfo_51a790(u8 *self, u8 *buf) {
  ext_50a410(self, buf);
  u8 *bv = *(u8 **)buf;
  u32 x = vcall<u32>(self, 0x38);
  (*(void(THISCALL **)(u8 *, u32))bv)(buf, x);
}
PCREG(51a790, collectOpaqueInfo_51a790);

// 0x51a7d0 ZMoveOnSplineIf::opaqueCall(OpaqueCallParameters_t &p) ret 4: method index = word p+0x10; below the count at
// [0x701660] it calls this class's handler table [0x701668 + 4 * index] (thiscall, p); otherwise it subtracts the count
// from the word and tail-calls the base ZGeomIf::opaqueCall 0x504560.
static void THISCALL opaqueCall_51a7d0(u8 *self, u8 *p) {
  u32 i = *(u16 *)(p + 0x10);
  u32 n = *(u32 *)0x701660u;
  if (i < n) {
    (*(void(THISCALL **)(u8 *, u8 *))(0x701668u + 4 * i))(self, p);
    return;
  }
  *(u16 *)(p + 0x10) = (u16)(i - n);
  ext_504560(self, p);
}
PCREG(51a7d0, opaqueCall_51a7d0);
#undef DB
