// batch400.cpp - per-frame update chain (inline-frameupdate thread, 2026-10-11): ZPlayer::ClassFrameUpdate and the
// small functions around it, bottom-up. Names: GameCube ELF via decoders/gc_pc_namemap.tsv (confidence in comments).
#include "ff.h"

// ---------------------------------------------------------------- 0x465fb0 ZIKLNKOBJ::ClassFrameUpdate [medium]
// thiscall, plain ret. Calls its own slot 0x410 (ZLNKWHANDS::UpdateTargets in the ZPlayer vtable [high]) and then
// tail-calls ZLNKOBJ::ClassFrameUpdate (0x461c40) [high] with the same this.
extern "C" void THISCALL ext_461c40(u8 *self);  // ZLNKOBJ::ClassFrameUpdate
static void THISCALL ziklnkobjClassFrameUpdate(u8 *self) {
  vcall<void>(self, 0x410);
  ext_461c40(self);
}
PCREG(465fb0, ziklnkobjClassFrameUpdate);

// ---------------------------------------------------------------- 0x482370 ZPlayer::ClassFrameUpdate [high]
// thiscall, plain ret. Slot names are from the ZPlayer vtable through the name map (ZFFHERO overrides some):
//   0x5ec UpdatePoolGeoms, 0x59c GetCenterMatPos, 0x61c MovementControl, 0x600 CalcBonesFromMotion,
//   0x5f0 SetGroupPos, 0x348 ZLNKOBJ::UpdateAnimationsAndGroundLink [low], 0x604 (empty in ZPlayer, 0x634d16).
extern "C" void THISCALL ext_465fb0(u8 *self);  // ZIKLNKOBJ::ClassFrameUpdate (above)
extern "C" void THISCALL ext_482b80(u8 *self);  // ZPlayer::DebugControl [high]
extern "C" void FASTCALL ext_441730(const char *tag);  // profiler begin (batch 48)
extern "C" void FASTCALL ext_440530(const char *tag);  // profiler end (batch 48)
static void THISCALL zplayerClassFrameUpdate(u8 *self) {
  if (self[0x5fe]) {  // byte +0x5fe: IK-driven (inference); run the IK link-object update instead
    ext_465fb0(self);
    return;
  }
  if (self[0x412]) {
    u8 *geom = *(u8 **)(vcall<u8 *>(self, 0x20) + 8);
    if (!(*(u32 *)(geom + 0x3c) & 0x800)) {
      ext_482b80(self);
      ext_441730((const char *)0x68c018u);  // "UpdatePool"
      vcall<void>(self, 0x5ec);
      ext_440530((const char *)0x68c018u);
      vcall<void>(self, 0x604);
      vcall<void>(self, 0x348);
      float centerMat[9], centerPos[3], newMat[9], newPos[3];
      vcall<void>(self, 0x59c, centerMat, centerPos);
      vcall<void>(self, 0x61c, centerMat, centerPos, newMat, newPos);
      vcall<void>(self, 0x600, centerMat, centerPos, newMat, newPos);
      vcall<void>(self, 0x5f0, newMat, newPos);
      return;
    }
  }
  vcall<void>(self, 0x5ec);
}
PCREG(482370, zplayerClassFrameUpdate);

// ---------------------------------------------------------------- 0x5cdb70 ZCamHelper::ControlBody [high]
// thiscall, plain ret. cam+0x44 is the hero.
extern "C" void THISCALL ext_5cf420(u8 *cam, float *out);  // aim origin (batch 50)
extern "C" void THISCALL ext_5ceb30(u8 *cam);  // ZCamHelper::ControlMouse [high]
extern "C" void THISCALL ext_5ceb70(u8 *cam);  // ZCamHelper::ControlOni [high]
extern "C" void THISCALL ext_5cdab0(u8 *cam);  // ZCamHelper::ControlA [high]
extern "C" void THISCALL ext_5cff20(u8 *cam);  // (no name)
extern "C" void THISCALL ext_5d0080(u8 *cam);  // (no name)
extern "C" void THISCALL ext_5cecd0(u8 *cam);  // ZCamHelper::DoMoveFocus [low]
static void THISCALL camControlBody(u8 *cam) {
  u8 *hero = *(u8 **)(cam + 0x44);
  vcall<void>(hero, 0x80, (float *)(cam + 0xcdd), (float *)(cam + 0xd01));
  ext_5cf420(cam, (float *)(cam + 0xd22));
  u8 *rm = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *o = vcall<u8 *>(rm, 0x58, *(u32 *)(cam + 0xc6d));
  vcall<void>(o, 0x80, (float *)(cam + 0xcb9), (float *)(cam + 0xcad));
  *(u32 *)(hero + 0x64b) = 4;
  vcall<void>(cam, 0x84);
  if (!cam[0xdd8] && !vcall<u8>(*(u8 **)(cam + 0x44), 0x438)) {
    switch (*(u32 *)(cam + 0xe1c)) {
      case 0: ext_5cdab0(cam); break;
      case 1: ext_5ceb70(cam); break;
      case 3: ext_5ceb30(cam); break;
    }
  }
  if (vcall<u8>(hero, 0x438)) {
    ext_5cff20(cam);
    return;
  }
  if (cam[0xdd8])
    ext_5d0080(cam);
  else
    ext_5cecd0(cam);
}
PCREG(5cdb70, camControlBody);
