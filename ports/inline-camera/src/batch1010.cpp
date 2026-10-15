// batch1010.cpp - ZCamHelper small members (aim pointer helper of the hero). Camera thread, 2026-10-11.
#include "cam.h"

extern "C" THISCALL void ext_5cd7f0(void *self, float *a, float *b, float t, u32 n);  // ZCamHelper::ChangeFocus
extern "C" THISCALL void *ext_4e1b60(void *coli);                                       // COLI::COLI
extern "C" FASTCALL void ext_43e920(float *d, const float *a, const float *b);          // d = a - b
extern "C" THISCALL u32 ext_5cf110(void *self);                                         // (unnamed, x87) pick enemy under pointer
extern "C" THISCALL void ext_5d0df0(void *self);  // ZCamHelper::MovePointerMouse
extern "C" THISCALL void ext_5d2eb0(void *self);  // ZCamHelper::UpdatePointerMode
extern "C" THISCALL void ext_5d1530(void *self);  // ZCamHelper::RestrictPointerAngle
extern "C" THISCALL void ext_5d28c0(void *self);  // ZCamHelper::UpdateFocusAngleMouse
extern "C" THISCALL void ext_5ce0b0(void *self);  // ZCamHelper::ControlBodyOni
extern "C" THISCALL void ext_5d1ea0(void *self);  // ZCamHelper::SetFocusSystemMouse
extern "C" THISCALL void ext_5d0f10(void *self);  // ZCamHelper::MovePointerOni
extern "C" THISCALL void ext_5d2ab0(void *self);  // ZCamHelper::UpdateFocusAngleOni
extern "C" THISCALL void ext_5d2080(void *self);  // ZCamHelper::SetFocusSystemOni
extern "C" THISCALL void ext_5d2280(void *self);  // ZCamHelper::SetPointerOnScreenOni
extern "C" THISCALL void ext_5cd890(void *self);  // ZCamHelper::CheckResetPointerAndFocusOni
extern "C" THISCALL void ext_45bfd0(void *obj, float *p);  // (unnamed) +0xb5b object, fills/uses p
extern "C" THISCALL void ext_5cf420(void *self, float *out);  // (unnamed, x87) aim origin
extern "C" FASTCALL void ext_4e09b0(float *v);                 // vneg
extern "C" FASTCALL float ext_4e0030(const float *a, const float *b);  // vangle
extern "C" THISCALL u32 ext_5cfd90(void *self, float *p);
extern "C" THISCALL u32 ext_5cfb10(void *self, float *p);     // ZCamHelper::GetRecruitScoutPosColi
extern "C" FASTCALL void ext_4de420(float *d, const float *s);  // mcpy
extern "C" THISCALL void ext_5cc880(void *cam, u32 on);       // ZFFCamera1::SetCloseUp (batch1002)
extern "C" THISCALL void ext_5a7530(void *obj, u32 a);
extern "C" THISCALL void ext_5d0310(void *self);              // ZCamHelper::InitRecruitWayPoints
extern "C" FASTCALL void ext_4de7a0(float *m);                 // mreset
extern "C" THISCALL u32 ext_591ae0(void *hero);               // ZFFHERO::GetFFCamPtr

// ZCamHelper fields (packed): +0x44 hero, +0xb54 the hero's ZFFCamera1, +0xb15 camera distance (set by the
// camera each frame), +0xa4c control scheme (1, 2 = pad "Oni"), +0xdd8 raising-flag active.

// 0x5cd580 ZCamHelper::AbortRaisingFlag(): if a flag is being raised, stop and swing the focus back (0.1 s, mode 3).
static THISCALL void ZCamHelper_AbortRaisingFlag(void *self) {
  if (!at<u8>(self, 0xdd8)) return;
  at<u8>(self, 0xdd8) = 0;
  at<u8>(self, 0xd35) = 0;
  ext_5cd7f0(self, &at<float>(self, 0xddd), &at<float>(self, 0xde9), bitsf(0x3dcccccd), 3);
}
PCREG(5cd580, ZCamHelper_AbortRaisingFlag);

// 0x5cd750 (unnamed) ZCamHelper::IsClearLine(const float* p) (inferred): line test (flags 0x10/0x200000) from the
// eye point +0xd22 to p against the world; returns 1 when nothing is hit. AL only; the upper EAX bytes are the
// line test's.
static THISCALL u32 ZCamHelper_IsClearLine(void *self, const float *p) {
  alignas(4) u8 c[0x70];
  ext_4e1b60(c);
  float *eye = &at<float>(self, 0xd22);
  ((float *)c)[0] = eye[0];
  ((float *)c)[1] = eye[1];
  ((float *)c)[2] = eye[2];
  ext_43e920((float *)(c + 0xc), p, eye);
  c[0x6c] = 0;
  u32 r = vcall<u32>(ptr(SYS9B, 0xadc), 0x2e0, c, 0u, 0x10u, 0x200000u, 1u, 0u);
  return (r & ~0xffu) | ((u8)r == 0);
}
PCREG(5cd750, ZCamHelper_IsClearLine);

// 0x5cda40 ZCamHelper::CommandPointerAtEnemy(): squad "attack" order. Prepare the enemy pick: team of the hero
// (+0x44 -> +0x54 -> +0xc) to +0xb50, max distance 25000 (+0xdfd), its square (+0xe01), pick cone 2 degrees
// in close-up (+0xb45) else 24 degrees (+0xdf9); the pick (0x5cf110) leaves the enemy in +0xd2e. Returns and
// stores (+0xd11) the enemy or 0.
static THISCALL u32 ZCamHelper_CommandPointerAtEnemy(void *self) {
  u32 enemy = 0;
  u8 closeup = at<u8>(self, 0xb45);
  at<u32>(self, 0xb50) = at<u32>(ptr(ptr(self, 0x44), 0x54), 0xc);
  at<u32>(self, 0xdfd) = 0x46c35000;  // 25000
  at<u32>(self, 0xe01) = 0x4e1502f9;  // 625000000
  at<u32>(self, 0xdf9) = closeup ? 0x3d0efa35 : 0x3ed67750;  // 2 or 24 degrees
  if ((u8)ext_5cf110(self)) enemy = at<u32>(self, 0xd2e);
  at<u32>(self, 0xd11) = enemy;
  return enemy;
}
PCREG(5cda40, ZCamHelper_CommandPointerAtEnemy);

// 0x5ceb30 ZCamHelper::ControlMouse(): the PC mouse aim step.
static THISCALL void ZCamHelper_ControlMouse(void *self) {
  at<u8>(self, 0xb46) = 0;
  ext_5d0df0(self);
  ext_5d2eb0(self);
  ext_5d1530(self);
  ext_5d28c0(self);
  ext_5ce0b0(self);
  ext_5d1ea0(self);
}
PCREG(5ceb30, ZCamHelper_ControlMouse);

// 0x5ceb70 ZCamHelper::ControlOni(): the gamepad aim step (scheme 2).
static THISCALL void ZCamHelper_ControlOni(void *self) {
  at<u8>(self, 0xb46) = 0;
  at<u32>(self, 0xa4c) = 2;
  ext_5d0f10(self);
  ext_5d2eb0(self);
  ext_5d2ab0(self);
  ext_5d1530(self);
  ext_5d2080(self);
  ext_5d2280(self);
  ext_5cd890(self);
  ext_5ce0b0(self);
}
PCREG(5ceb70, ZCamHelper_ControlOni);

// 0x5cf3e0 (unnamed): object +0xb5b processes p, then the geometry of handle +0xb9f takes it (slot 0x88).
static THISCALL void ZCamHelper_5cf3e0(void *self, float *p) {
  ext_45bfd0((u8 *)self + 0xb5b, p);
  void *g = vcall<void *>(SYS9B, 0x58, at<u32>(self, 0xb9f));
  if (g) vcall<void>(g, 0x88, p);
}
PCREG(5cf3e0, ZCamHelper_5cf3e0);

// Aim direction: scheme 1 uses -(+0xcdd), others +0xa72.
static inline void aim_dir(void *self, float *d) {
  if (at<u32>(self, 0xa4c) == 1) {
    d[0] = at<float>(self, 0xcdd);
    d[1] = at<float>(self, 0xce1);
    d[2] = at<float>(self, 0xce5);
    ext_4e09b0(d);
  } else {
    d[0] = at<float>(self, 0xa72);
    d[1] = at<float>(self, 0xa76);
    d[2] = at<float>(self, 0xa7a);
  }
}

// 0x5cf520 (unnamed) ZCamHelper angle between the aim direction and the line from the aim origin to p.
static THISCALL float ZCamHelper_AngleToAim(void *self, const float *p) {
  float o[3], d[3], v[3];
  ext_5cf420(self, o);
  aim_dir(self, d);
  ext_43e920(v, p, o);
  return ext_4e0030(v, d);
}
PCREG(5cf520, ZCamHelper_AngleToAim);

// 0x5cf5d0 (unnamed) the same in the horizontal plane (y of both vectors zeroed).
static THISCALL float ZCamHelper_AngleToAimXZ(void *self, const float *p) {
  float o[3], d[3], v[3];
  ext_5cf420(self, o);
  aim_dir(self, d);
  ext_43e920(v, p, o);
  v[1] = 0.0f;
  d[1] = 0.0f;
  return ext_4e0030(v, d);
}
PCREG(5cf5d0, ZCamHelper_AngleToAimXZ);

// 0x5cf7f0 ZCamHelper::GetGlobalFocalPoint(float*): focus position +0xc71.
static THISCALL void ZCamHelper_GetGlobalFocalPoint(void *self, u32 *out) {
  out[0] = at<u32>(self, 0xc71);
  out[1] = at<u32>(self, 0xc75);
  out[2] = at<u32>(self, 0xc79);
}
PCREG(5cf7f0, ZCamHelper_GetGlobalFocalPoint);

// 0x5cfae0 ZCamHelper::GetRecruitScoutPos(float*): the cheap test first, then the collision-checked one.
static THISCALL u32 ZCamHelper_GetRecruitScoutPos(void *self, float *p) {
  u32 r = ext_5cfd90(self, p);
  if ((u8)r) return r;
  return ext_5cfb10(self, p);
}
PCREG(5cfae0, ZCamHelper_GetRecruitScoutPos);

// 0x5cfee0 ZCamHelper::GetFocusMatPos(float*, float*) == GetRootFocusMatPos: matrix +0xc89, position +0xc71.
static THISCALL void ZCamHelper_GetFocusMatPos(void *self, float *m, u32 *p) {
  p[0] = at<u32>(self, 0xc71);
  p[1] = at<u32>(self, 0xc75);
  p[2] = at<u32>(self, 0xc79);
  ext_4de420(m, &at<float>(self, 0xc89));
}
PCREG(5cfee0, ZCamHelper_GetFocusMatPos);

// 0x5d0080 (unnamed) ZCamHelper leave-aim reset (inferred): clears +0xb1f..+0xb2e, switches the camera's close-up
// off, clears +0xad5 and tells object +0xe18 (slot fn 0x5a7530, arg 0).
static THISCALL void ZCamHelper_5d0080(void *self) {
  void *cam = ptr(self, 0xb54);
  at<u32>(self, 0xb1f) = 0;
  at<u32>(self, 0xb23) = 0;
  at<u32>(self, 0xb27) = 0;
  at<u32>(self, 0xb2b) = 0;
  ext_5cc880(cam, 0);
  void *o = ptr(self, 0xe18);
  at<u32>(self, 0xad5) = 0;
  if (o) ext_5a7530(o, 0);
}
PCREG(5d0080, ZCamHelper_5d0080);

// 0x5d02d0 ZCamHelper::Init(): registers the script reference "GetRefObjectCamHelper" (manager slot 0x114),
// keeps its id (+0xb59, 16 bit), then InitRecruitWayPoints.
static THISCALL void ZCamHelper_Init(void *self) {
  u32 id = vcall<u32>(SYS9B, 0x114, (const char *)0x6acfa4, 0u, (const char *)0x6b4e78, 0x108u);
  at<u16>(self, 0xb59) = (u16)id;
  ext_5d0310(self);
}
PCREG(5d02d0, ZCamHelper_Init);

// 0x5d05b0 ZCamHelper::Load2(): distance 500 and the hero's camera pointer. (An identity matrix is built on the
// stack and not used.)
static THISCALL void ZCamHelper_Load2(void *self) {
  float m[9];
  ext_4de7a0(m);
  void *hero = ptr(self, 0x44);
  at<u32>(self, 0xb15) = 0x43fa0000;
  at<u32>(self, 0xb54) = ext_591ae0(hero);
}
PCREG(5d05b0, ZCamHelper_Load2);
