// batch8806.cpp - hit-reaction thread, batch 8806: ZFFActorActionCloseCombat::Execute, which starts a soldier's punch and
// builds the SDamageInfo its Update (batch 8805) sends.
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])

extern "C" void FASTCALL ext_43e920(float *d, const float *a, const float *b);          // PSVECSubtract d = a - b
extern "C" void FASTCALL ext_4de040(float *m, const float *p, const float *q);          // createmat
extern "C" void FASTCALL ext_443ef0(float *d, const float *a, const float *v, float s); // vaddscalar4 d = a + v * s
extern "C" void THISCALL ext_461570(void *bone, float frames, u32 fn, u32 z);           // ZBoneAnim::AddCallBackAlways

typedef void(THISCALL *vRootTM)(void *self, float *m, float *p);
typedef void(THISCALL *vVP)(void *self, float *p);
typedef u8 *(THISCALL *vAnim)(void *self, u8 *hdr, u32 a, float b, float c, float d);
typedef void(THISCALL *vPlace)(void *self, float *m, float *p, float frame);
typedef void(THISCALL *vCmd)(void *self, u32 msg, u32 data, u32 z);
typedef u32(THISCALL *vHandle)(void *self, void *o);
typedef s16(THISCALL *vS0)(void *self);
typedef void(THISCALL *vVU)(void *self, u32 a);

// 0x5eb020 ZFFActorActionCloseCombat::Execute() (GC 80074f2c). Attacker +8, target +0xc, clips +0x10 / +0x14, type +0x18.
//  d = attacker root position (slot 0x80) - target root point (slot 0x84) with y = 0, normalised (x87) unless x and z are both
//  0; s = its length (0 when not normalised). The attacker is turned to face along -d? no: createmat(d) is its frame.
//  type 0: clip +0x14 (slot 0x228(clip, 1, 0, -1, 1)); no bone anim -> return false; callback 0x465710 at the clip's last
//  frame (+0x64 - +0x60); placed by slot 0x238(frame, attacker position, 7); hit time +0x1c = now + 7 / fps (s); the target
//  gets "CCAttack" (id [0x7143a4]) with data 0. type 1: clip +0x10, frame 10, data 1. Other types: none of this.
//  SDamageInfo at +0x21: attacker = render manager slot 0x4c(attacker), +4 (zone multiplier flag) = 0, type +0x29 = 1 (type 0)
//  or 3 (type 1), pos +0x31 = attacker position + d * s, dir +0x3d = d, damage +0x49 = (float)GetCloseCombatStrength (slot
//  0x6b0, s16). +0x20 = 1 (armed for Update); attacker slot 0x704(1). Returns true.
static u8 THISCALL ccExecute(u8 *self) {
  float ap[3], tp[3], d[3], m[9], am[9], pos2[3], dd[3];
  ap[0] = 0.0f; ap[1] = 0.0f; ap[2] = 0.0f;
  float s = 0.0f;
  tp[0] = 0.0f; tp[1] = 0.0f; tp[2] = 0.0f;
  void *at = *(void **)(self + 8);
  ((vRootTM)VT(at, 0x80))(at, am, ap);
  void *tg = *(void **)(self + 0xc);
  ((vVP)VT(tg, 0x84))(tg, tp);
  ext_43e920(d, ap, tp);
  d[1] = 0.0f;
  if (!(d[0] == 0.0f) || !(d[2] == 0.0f)) {
    long double x = d[0], y = d[1], z = d[2];
    long double len = fsqrt_x87(x * x + y * y + z * z);
    long double inv = 1.0L / len;
    d[0] = (float)((long double)d[0] * inv);
    d[1] = (float)((long double)d[1] * inv);
    d[2] = (float)((long double)d[2] * inv);
    s = (float)len;
  }
  pos2[0] = ap[0]; pos2[1] = ap[1]; pos2[2] = ap[2];
  dd[0] = d[0]; dd[1] = d[1]; dd[2] = d[2];
  ext_4de040(m, dd, 0);
  u32 type = *(u32 *)(self + 0x18);
  if (type == 0 || type == 1) {
    u8 *hdr = *(u8 **)(self + (type == 0 ? 0x14 : 0x10));
    at = *(void **)(self + 8);
    u8 *bone = ((vAnim)VT(at, 0x228))(at, hdr, 1, 0.0f, -1.0f, 1.0f);
    if (!bone) return 0;
    hdr = *(u8 **)(self + (type == 0 ? 0x14 : 0x10));
    ext_461570(bone, (float)(*(s32 *)(hdr + 0x64) - *(s32 *)(hdr + 0x60)), 0x465710, 0);
    at = *(void **)(self + 8);
    ((vPlace)VT(at, 0x238))(at, m, pos2, type == 0 ? 7.0f : 10.0f);
    hdr = *(u8 **)(self + (type == 0 ? 0x14 : 0x10));
    float k = type == 0 ? G(float, 0x681dc8) : G(float, 0x680a70);
    float fps = (float)*(s32 *)(hdr + 0x6c);
    s32 now = *(s32 *)(G(u8 *, 0x70039c) + 0x40);
    k = k / fps;
    k = k * G(float, 0x67862c);
    s32 i = _mm_cvttss_si32(_mm_set_ss(k));
    *(float *)(self + 0x1c) = (float)(now - i) * G(float, 0x6785e4);
    tg = *(void **)(self + 0xc);
    ((vCmd)VT(tg, 0x128))(tg, *(u16 *)0x7143a4, type == 0 ? 0 : 1, 0);
  }
  type = *(u32 *)(self + 0x18);
  if (type == 0) *(u32 *)(self + 0x29) = 1;
  else if (type == 1) *(u32 *)(self + 0x29) = 3;
  ext_443ef0((float *)(self + 0x31), ap, d, s);
  *(float *)(self + 0x3d) = d[0];
  *(float *)(self + 0x41) = d[1];
  *(float *)(self + 0x45) = d[2];
  u8 *rm = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  *(u32 *)(self + 0x21) = ((vHandle)VT(rm, 0x4c))(rm, *(void **)(self + 8));
  at = *(void **)(self + 8);
  s16 str = ((vS0)VT(at, 0x6b0))(at);
  *(u32 *)(self + 0x25) = 0;
  self[0x20] = 1;
  *(float *)(self + 0x49) = (float)str;
  at = *(void **)(self + 8);
  ((vVU)VT(at, 0x704))(at, 1);
  return 1;
}
PCREG(5eb020, ccExecute);
