// batch48.cpp - hero frame-update tree, inline session batch 48: small callees of ZFFHERO::ClassFrameUpdate (0x58d000)
// and ZPlayer::ClassFrameUpdate (0x482370), bottom-up.
#include "ff.h"

// 0x6474d0 ZBoneModifyBase::SetOverrideLODIndex(bool, unsigned char), thiscall, ret 8.
static void THISCALL setOverrideLODIndex(u8 *self, u32 on, u32 index) {
  self[0x266] = (u8)on != 0;
  self[0x267] = (u8)index;
}
PCREG(6474d0, setOverrideLODIndex);

// 0x5ab070, thiscall, plain ret. Counts a frame at +0x8cb unless +0x300 holds 0x10000000.
static void THISCALL countFrame8cb(u8 *self) {
  if (*(u32 *)(self + 0x300) != 0x10000000u)
    ++*(u32 *)(self + 0x8cb);
}
PCREG(5ab070, countFrame8cb);

// 0x59ffc0, thiscall: returns the dword at +0x77f.
static u32 THISCALL getDword77f(u8 *self) { return *(u32 *)(self + 0x77f); }
PCREG(59ffc0, getDword77f);

// 0x596cf0 ZGameOSD::CharismaGetRecruitable(), thiscall: returns the dword at +0x1fba.
static u32 THISCALL charismaGetRecruitable(u8 *self) { return *(u32 *)(self + 0x1fba); }
PCREG(596cf0, charismaGetRecruitable);

// 0x4419f0 vmmul(float *v, const float *m), fastcall, plain ret. Row vector times 3x3 matrix, in place. x87 at 53-bit
// precision: each lane is (v0*m[6+j] + v1*m[3+j]) + v2*m[j] in double, stored as float.
static void FASTCALL vmmul(float *v, const float *m) {
  double v0 = v[0], v1 = v[1], v2 = v[2];
  double r0 = ((v0 * m[6]) + (v1 * m[3])) + (v2 * m[0]);
  double r1 = ((v0 * m[7]) + (v1 * m[4])) + (v2 * m[1]);
  double r2 = ((v0 * m[8]) + (v1 * m[5])) + (v2 * m[2]);
  v[0] = (float)r0;
  v[1] = (float)r1;
  v[2] = (float)r2;
}
PCREG(4419f0, vmmul);

extern "C" void FASTCALL ext_4419f0(float *v, const float *m);
// 0x4de480, fastcall (mat in ECX, m in EDX), plain ret. mat = mat * m, row by row from the last row.
static void FASTCALL mmulInPlace(float *mat, const float *m) {
  ext_4419f0(mat + 6, m);
  ext_4419f0(mat + 3, m);
  ext_4419f0(mat, m);
}
PCREG(4de480, mmulInPlace);

extern "C" void FASTCALL ext_43e920(float *dst, const float *src, const float *a);  // PSVECSubtract (batch 34)
// 0x4e0870, fastcall (a in ECX, b in EDX), plain ret, result in ST0: the distance |a - b|.
static float FASTCALL vdist(const float *a, const float *b) {
  float t[3];
  ext_43e920(t, a, b);
  float len2 = ((t[0] * t[0]) + (t[1] * t[1])) + (t[2] * t[2]);
  return (float)crt::sqrt((double)len2);
}
PCREG(4e0870, vdist);

typedef u64(THISCALL *vcallStampU64)(void *self, const char *file, u32 line);
typedef void(THISCALL *vcallProf)(void *self, u64 stamp, void *tag);

// 0x441730, fastcall (tag in ECX), plain ret. Profiler begin: when both [0x70039c]+0x9c7 and +0x9c3 are non-zero (or
// NaN), reads a 64-bit stamp through system slot 0x1c8 (file 0x67a7f8, line 0x259) and passes it with tag to slot 0x178.
static void FASTCALL profBegin(void *tag) {
  u8 *sys = G(u8 *, 0x70039c);
  if (*(float *)(sys + 0x9c7) == 0.0f || *(float *)(sys + 0x9c3) == 0.0f)
    return;
  u64 t = ((vcallStampU64)(*(void ***)sys)[0x1c8 / 4])(sys, (const char *)0x67a7f8u, 0x259u);
  sys = G(u8 *, 0x70039c);
  ((vcallProf)(*(void ***)sys)[0x178 / 4])(sys, t, tag);
}
PCREG(441730, profBegin);

// 0x440530, fastcall (tag in ECX), plain ret. Profiler end: same test, line 0x260, slot 0x17c.
static void FASTCALL profEnd(void *tag) {
  u8 *sys = G(u8 *, 0x70039c);
  if (*(float *)(sys + 0x9c7) == 0.0f || *(float *)(sys + 0x9c3) == 0.0f)
    return;
  u64 t = ((vcallStampU64)(*(void ***)sys)[0x1c8 / 4])(sys, (const char *)0x67a7f8u, 0x260u);
  sys = G(u8 *, 0x70039c);
  ((vcallProf)(*(void ***)sys)[0x17c / 4])(sys, t, tag);
}
PCREG(440530, profEnd);

typedef u8(THISCALL *vcallBool0)(void *self);
extern "C" u32 THISCALL ext_59a5e0(u8 *osd, u32 type);  // ZGameOSD::PlaySound(ESOUNDTYPE)
// 0x596680, thiscall, plain ret. When the object at +0xf56 is set and more than 1024 ticks have passed since the time
// at +0xf52 (seconds * 1024, truncated), plays OSD sound 0x11 unless the object's slot 0x438 returns true, then clears
// +0xf56.
static void THISCALL recruitTimeout(u8 *self) {
  u8 *o = *(u8 **)(self + 0xf56);
  if (!o)
    return;
  s32 then = (s32)(*(float *)(self + 0xf52) * 1024.0f);
  if ((s32)(*(u32 *)(G(u8 *, 0x70039c) + 0x40) - (u32)then) <= 0x400)
    return;
  if (!((vcallBool0)(*(void ***)o)[0x438 / 4])(o))
    ext_59a5e0(*(u8 **)(self + 0x852), 0x11);
  *(u32 *)(self + 0xf56) = 0;
}
PCREG(596680, recruitTimeout);

typedef void(THISCALL *vcall0)(void *self);
typedef void(THISCALL *vcall4x32)(void *self, u32 a, u32 b, u32 c, u32 d);
typedef void(THISCALL *vcallStr)(void *self, const char *s);
// 0x59c420 ZFFLevelController::PushEndScene(), thiscall, plain ret. With byte +0x1042 set, tail-calls render-manager
// slot 0xa8. Otherwise calls system slot 0xc with four zero dwords, then render-manager slots 0xa4 and 0xa0 (the
// string at 0x6ade2c).
static void THISCALL pushEndScene(u8 *self) {
  if (self[0x1042]) {
    u8 *rm = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    ((vcall0)(*(void ***)rm)[0xa8 / 4])(rm);
    return;
  }
  u8 *sys = G(u8 *, 0x70039c);
  ((vcall4x32)(*(void ***)sys)[0xc / 4])(sys, 0, 0, 0, 0);
  u8 *rm = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  ((vcall0)(*(void ***)rm)[0xa4 / 4])(rm);
  rm = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  ((vcallStr)(*(void ***)rm)[0xa0 / 4])(rm, (const char *)0x6ade2cu);
}
PCREG(59c420, pushEndScene);
