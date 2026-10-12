// batch8801.cpp - hit-reaction thread, batch 8801: ZFFActor::DieByForce (ragdoll or death clip), the three kill
// counters it bumps, and ZIKLNKOBJ::ActivateRagdoll (the actor-side entry into the ragdoll classes).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])

extern "C" void THISCALL ext_5ab110(void *stats);   // kill counter +0x8b7 (no killer)
extern "C" void THISCALL ext_5ab050(void *stats);   // kill counter +0x8b3 (killer of class 0x2007f9, team 0)
extern "C" void THISCALL ext_5ab0b0(void *stats);   // kill counter +0x8af (killer of another class)
extern "C" void THISCALL ext_4783f0(void *self, const float *pos, const float *force, float strength, u32 killer);  // ZActor::DieByForce
extern "C" void THISCALL ext_466c10(void *self, const float *pos, const float *force, float strength);  // ZIKLNKOBJ::HitRagdoll
extern "C" const char *THISCALL ext_4cc1d0(void *mystr);  // MYSTR c_str (returns [this])
extern "C" void THISCALL ext_4cbec0(void *mystr);         // MYSTR::~MYSTR
extern "C" void THISCALL ext_466ce0(void *self);          // ZIKLNKOBJ::KillAllSounds

typedef s32(THISCALL *vI0)(void *self);
typedef void(THISCALL *vV0)(void *self);
typedef void(THISCALL *vVU)(void *self, u32 a);
typedef u8 *(THISCALL *vPU)(void *self, u32 a);
typedef u8(THISCALL *vBU)(void *self, u32 a);
typedef u8(THISCALL *vBUU)(void *self, u32 a, u32 b);
typedef void(THISCALL *vRootTM)(void *self, float *mat, float *pos);
typedef float(THISCALL *vRand)(void *self, const char *file, u32 line);
typedef u8(THISCALL *vCanPlay)(void *self, u8 *hdr, float first, float last, float *mat, float *pos, float a, float b);
typedef void(THISCALL *vPlay)(void *self, u8 *hdr, u32 loop);
typedef u8 *(THISCALL *vLogger)(void *self, const char *file, u32 line);
typedef u8 *(THISCALL *vName)(void *self, void *out, u32 full);
typedef void (*vPrintf)(void *self, const char *fmt, const char *s);
typedef u32(THISCALL *vAct)(void *self, void *obj, u32 a, u32 b, u32 c);

static const char *const FILE_ZFFACTOR = (const char *)0x6ae6a0;  // '..\\..\\freedomfighter\\FFBackground\\ZFFActor.cpp'

// 0x5ab110 / 0x5ab050 / 0x5ab0b0: kill counters on the stats object (OSD +0x1d0f); nothing when +0x300 == 0x10000000.
static void THISCALL killCountNone(u8 *s) {
  if (*(u32 *)(s + 0x300) != 0x10000000) (*(u32 *)(s + 0x8b7))++;
}
PCREG(5ab110, killCountNone);
static void THISCALL killCountTeam(u8 *s) {
  if (*(u32 *)(s + 0x300) != 0x10000000) (*(u32 *)(s + 0x8b3))++;
}
PCREG(5ab050, killCountTeam);
static void THISCALL killCountOther(u8 *s) {
  if (*(u32 *)(s + 0x300) != 0x10000000) (*(u32 *)(s + 0x8af))++;
}
PCREG(5ab0b0, killCountOther);

// 0x59f3e0 ZFFActor::DieByForce(const float* pos, const float* force, float strength, u32 killer) (GC 8006ee58).
//  1. GetActorState (slot 0x588) == 0 -> return.
//  2. With an owner player at +0x92e: its stats object (+0x852 -> +0x1d0f) counts the kill: no killer -> 0x5ab110; killer
//     (render manager slot 0x58) IsDerivedFrom(0x2007f9) (slot 0x1e0) -> 0x5ab050 when its team (+0x54 -> +4) is 0; not
//     derived -> 0x5ab0b0.
//  3. ZActor::DieByForce (-> slot 0x664 ZActor::Die), SetCheckSight(0) (slot 0x694), DropWeapons (slot 0x6e4).
//  4. ActivateRagdoll(1, 1) (slot 0x354): when it succeeds HitRagdoll(pos, force, strength + strength) and return (no clip).
//  5. Else death clip: d = force . root matrix row 0 (GetRootTM slot 0x80); r = engine random (slot 0x1c0 of
//     [0x70039c]); d > 0: r > 0.5 ? remap +0x7c2 : +0x7c6, else r > 0.5 ? +0x7ba : +0x7be; header = slot 0x5a0.
//     No header: "WARNING: Unable to play die anim for %s" and return. Can-play test slot 0x37c(hdr, frames +0x60 / +0x64
//     as floats, root matrix, root pos, 50, -130); false -> the +0x7ca header. ActivateAnim(hdr, 1) (slot 0x230).
static void THISCALL dieByForce(u8 *self, const float *pos, const float *force, float strength, u32 killer) {
  if (((vI0)VT(self, 0x588))(self) == 0) return;
  u8 *owner = *(u8 **)(self + 0x92e);
  if (owner) {
    u8 *osd = *(u8 **)(owner + 0x852);
    if (killer == 0) {
      ext_5ab110(*(void **)(osd + 0x1d0f));
    } else {
      void *rm = *(void **)(G(u8 *, 0x70039c) + 0x9b);
      u8 *ko = ((vPU)VT(rm, 0x58))(rm, killer);
      if (((vBU)VT(ko, 0x1e0))(ko, 0x2007f9)) {
        if (*(u32 *)(*(u8 **)(ko + 0x54) + 4) == 0) ext_5ab050(*(void **)(osd + 0x1d0f));
      } else {
        ext_5ab0b0(*(void **)(osd + 0x1d0f));
      }
    }
  }
  ext_4783f0(self, pos, force, strength, killer);
  ((vVU)VT(self, 0x694))(self, 0);
  ((vV0)VT(self, 0x6e4))(self);
  if (((vBUU)VT(self, 0x354))(self, 1, 1)) {
    ext_466c10(self, pos, force, strength + strength);
    return;
  }
  float mat[9], rpos[3];
  ((vRootTM)VT(self, 0x80))(self, mat, rpos);
  float a = force[0] * mat[0];
  float d = force[1] * mat[1];
  u8 *eng = G(u8 *, 0x70039c);
  vRand rnd = (vRand)VT(eng, 0x1c0);
  d = d + a;
  d = d + force[2] * mat[2];
  u32 idx;
  if (d > G(float, 0x6785d0)) {
    float r = rnd(eng, FILE_ZFFACTOR, 0x51a);
    idx = r > G(float, 0x67a6ac) ? *(u32 *)(self + 0x7c2) : *(u32 *)(self + 0x7c6);
  } else {
    float r = rnd(eng, FILE_ZFFACTOR, 0x51e);
    idx = r > G(float, 0x67a6ac) ? *(u32 *)(self + 0x7ba) : *(u32 *)(self + 0x7be);
  }
  u8 *hdr = ((vPU)VT(self, 0x5a0))(self, idx);
  if (!hdr) {
    void *lg = G(void *, 0x700390);
    u8 *out = ((vLogger)VT(lg, 0x20))(lg, FILE_ZFFACTOR, 0x522);
    u8 name[0x100];
    u8 *ms = ((vName)VT(self, 0x1d8))(self, name, 1);
    vPrintf pf = (vPrintf)VT(out, 0x2c);
    const char *s = ext_4cc1d0(ms);
    pf(out, (const char *)0x6aea70, s);   // 'WARNING: Unable to play die anim for %s'
    ext_4cbec0(name);
    return;
  }
  float mat2[9], rpos2[3];
  ((vRootTM)VT(self, 0x80))(self, mat2, rpos2);
  if (!((vCanPlay)VT(self, 0x37c))(self, hdr, (float)*(s32 *)(hdr + 0x60), (float)*(s32 *)(hdr + 0x64), mat2, rpos2,
                                    50.0f, -130.0f))
    hdr = ((vPU)VT(self, 0x5a0))(self, *(u32 *)(self + 0x7ca));
  ((vPlay)VT(self, 0x230))(self, hdr, 1);
}
PCREG(59f3e0, dieByForce);

// 0x465760 ZIKLNKOBJ::ActivateRagdoll(bool on, bool b) (GC 8017cb54): +0x13a = !on; KillAllSounds when on; then the bone
// modifier at +0x6c, slot 0x30 (ZBoneModifyBase::ActivateRagdoll) (this, on, b, 0) (the two bools passed as the full
// argument words); a non-zero result -> StopAllAnims(0) (slot 0x220). Returns that result as a bool.
static u8 THISCALL activateRagdoll(u8 *self, u32 on, u32 b) {
  u8 off = (u8)on == 0;
  self[0x13a] = off;
  if (!off) ext_466ce0(self);
  void *bm = *(void **)(self + 0x6c);
  u8 ok = ((vAct)VT(bm, 0x30))(bm, self, on, b, 0) != 0;
  if (ok) ((vVU)VT(self, 0x220))(self, 0);
  return ok;
}
PCREG(465760, activateRagdoll);
