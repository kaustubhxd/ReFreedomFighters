// batch315.cpp - mounted gun tree, batch 315: vehicle gun aiming. AimControl (moveonspline.cpp), the aim helper a
// gun-carrying vehicle keeps at +0x16e5 (ZPmv), and ZPmv's Fire/SetTarget.
// AimControl fields (inference from these bodies): +4 the owner geom (slot 0x84 turns a point into the gun's frame or
// adds its position; same slot as the nest code), +8 the target object (slots 0x3a8/0x3b4/0x3b8 pick a body point
// index, 0x398(index, out) gives that point), +0xc / +0x10 the end times (seconds) of the "aim around" and "aim at
// last position" phases, +0x14 the next refresh time, +0x18 the point returned in the last-position phase, +0x24 the
// last known point.
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vcallU0)(void *self);
typedef u8(THISCALL *vcallBU)(void *self, u32 a);
typedef void(THISCALL *vcallVP)(void *self, void *a);
typedef void(THISCALL *vcallVUP)(void *self, u32 a, void *b);
typedef long double(THISCALL *randFn)(void *self, const char *file, u32 line);

extern "C" void THISCALL ext_512be0(void *self, float *out);   // GetAimAroundPoint (this batch)
extern "C" void THISCALL ext_512ca0(void *self, float *out);   // GetAimAtLastPosPoint (this batch)
extern "C" void THISCALL ext_512db0(void *self, float *out);   // GetAimAtTargetPoint (this batch)
extern "C" void THISCALL ext_514480(void *aim, u32 ref);       // AimControl::SetTarget (vehicles batch 905)

static inline u8 *eng() { return G(u8 *, 0x70039c); }
static inline s32 clockTicks() { return *(s32 *)(eng() + 0x40); }
#define MOS_FILE ((const char *)0x69e4bc)   // "..\\..\\code\\engine\\shared\\vehicles\\moveonspline.cpp"

// 0x512db0 AimControl::GetAimAtTargetPoint(float *out) (GameCube reference by order of the GetAimPoint branches; inferred);
// thiscall, ret 4. With a target: out = the target's point number slot3a8() (slot 0x398(index, out)); else (0,0,0).
// Then the owner's slot 0x84(out).
static void THISCALL getAimAtTargetPoint(u8 *self, float *out) {
  u8 *t = *(u8 **)(self + 8);
  if (t) {
    void **vt = *(void ***)t;
    u32 idx = ((vcallU0)vt[0x3a8 / 4])(t);
    ((vcallVUP)vt[0x398 / 4])(*(u8 **)(self + 8), idx, out);
  } else {
    ((u32 *)out)[0] = 0;
    ((u32 *)out)[1] = 0;
    ((u32 *)out)[2] = 0;
  }
  u8 *o = *(u8 **)(self + 4);
  ((vcallVP)VT(o, 0x84))(o, out);
}
PCREG(512db0, getAimAtTargetPoint);

// 0x512be0 AimControl::GetAimAroundPoint(float *out) (GameCube reference; inferred); thiscall, ret 4. out = owner slot
// 0x84 of (0,0,0), then x and z each move by random * 100 (engine slot 0x1c4, a signed random in ST0; lines 0x545,
// 0x546). The point is kept as the last point (+0x24) and +0x14 = now (seconds).
static void THISCALL getAimAroundPoint(u8 *self, float *out) {
  ((u32 *)out)[0] = 0;
  ((u32 *)out)[1] = 0;
  ((u32 *)out)[2] = 0;
  u8 *o = *(u8 **)(self + 4);
  ((vcallVP)VT(o, 0x84))(o, out);
  float dx = (float)(((randFn)VT(eng(), 0x1c4))(eng(), MOS_FILE, 0x545) * (long double)100.0f);   // 0x67cd40
  out[0] = out[0] + dx;
  float dz = (float)(((randFn)VT(eng(), 0x1c4))(eng(), MOS_FILE, 0x546) * (long double)100.0f);
  out[2] = out[2] + dz;
  *(u32 *)(self + 0x24) = ((u32 *)out)[0];
  *(u32 *)(self + 0x28) = ((u32 *)out)[1];
  *(u32 *)(self + 0x2c) = ((u32 *)out)[2];
  *(float *)(self + 0x14) = (float)clockTicks() * 0.0009765625f;
}
PCREG(512be0, getAimAroundPoint);

// 0x512ca0 AimControl::GetAimAtLastPosPoint(float *out) (GameCube reference; inferred); thiscall, ret 4. When the refresh
// time (+0x14) has passed: the returned point (+0x18) becomes the last point (+0x24); the last point is refreshed
// from a random body point of the target (slot 0x3b4 when random < 0.5, else 0x3b8; random from slot 0x1c0, line
// 0x556), or (0,0,0) with no target, pushed through the owner's slot 0x84; the next refresh is now + the global
// interval at 0x6e8e80 (0.1 s at start). Always returns +0x18.
static void THISCALL getAimAtLastPosPoint(u8 *self, float *out) {
  if (clockTicks() > (s32)(*(float *)(self + 0x14) * 1024.0f)) {   // 0x678620
    float *last = (float *)(self + 0x24);
    *(u32 *)(self + 0x18) = *(u32 *)(self + 0x24);
    *(u32 *)(self + 0x1c) = *(u32 *)(self + 0x28);
    *(u32 *)(self + 0x20) = *(u32 *)(self + 0x2c);
    if (*(u8 **)(self + 8)) {
      float r = (float)((randFn)VT(eng(), 0x1c0))(eng(), MOS_FILE, 0x556);
      u8 *t = *(u8 **)(self + 8);
      u32 idx = 0.5f > r ? ((vcallU0)VT(t, 0x3b4))(t) : ((vcallU0)VT(t, 0x3b8))(t);   // 0x67a6ac
      u8 *t2 = *(u8 **)(self + 8);
      ((vcallVUP)VT(t2, 0x398))(t2, idx, last);
    } else {
      ((u32 *)last)[0] = 0;
      ((u32 *)last)[1] = 0;
      ((u32 *)last)[2] = 0;
    }
    u8 *o = *(u8 **)(self + 4);
    ((vcallVP)VT(o, 0x84))(o, last);
    float iv = G(float, 0x6e8e80) * -1024.0f;   // 0x67862c
    u32 ticks = (u32)clockTicks() - (u32)(s32)iv;
    *(float *)(self + 0x14) = (float)(s32)ticks * 0.0009765625f;   // 0x6785e4
  }
  ((u32 *)out)[0] = *(u32 *)(self + 0x18);
  ((u32 *)out)[1] = *(u32 *)(self + 0x1c);
  ((u32 *)out)[2] = *(u32 *)(self + 0x20);
}
PCREG(512ca0, getAimAtLastPosPoint);

// 0x512e10 AimControl::GetAimPoint(float *out) (GameCube reference by size and shape; the namemap's ZPmv::UpdateAimPos
// [medium] is the GC caller's name); thiscall, ret 4. Nothing without an owner (+4). Before +0xc seconds: aim around;
// before +0x10: aim at the last position; after: aim at the target. (Tail calls in the original.)
static void THISCALL getAimPoint(u8 *self, float *out) {
  if (!*(u32 *)(self + 4))
    return;
  s32 now = clockTicks();
  if (now < (s32)(*(float *)(self + 0xc) * 1024.0f)) {
    ext_512be0(self, out);
    return;
  }
  if (now < (s32)(*(float *)(self + 0x10) * 1024.0f)) {
    ext_512ca0(self, out);
    return;
  }
  ext_512db0(self, out);
}
PCREG(512e10, getAimPoint);

// 0x51f780 ZPmv::Fire(bool) (GC map [high]), vtable slot 230; thiscall, ret 4. The fire flag +0x16d5 (a dword) = the
// bool; it is cleared again when the current target (+0x1654) is not valid (slot 0x310, TargetValid).
static void THISCALL pmvFire(u8 *self, u32 b) {
  u32 tgt = *(u32 *)(self + 0x1654);
  *(u32 *)(self + 0x16d5) = (u8)b;
  if (!((vcallBU)VT(self, 0x310))(self, tgt))
    *(u32 *)(self + 0x16d5) = 0;
}
PCREG(51f780, pmvFire);

// 0x51fa10 ZPmv::SetTarget(unsigned int) (GC map [high]), vtable slot 229; thiscall, ret 4. +0x1654 = ref when
// TargetValid(ref) (slot 0x310), else 0; the aim control (+0x16e5) gets the new target (AimControl::SetTarget).
static void THISCALL pmvSetTarget(u8 *self, u32 ref) {
  if (((vcallBU)VT(self, 0x310))(self, ref))
    *(u32 *)(self + 0x1654) = ref;
  else
    *(u32 *)(self + 0x1654) = 0;
  ext_514480(self + 0x16e5, *(u32 *)(self + 0x1654));
}
PCREG(51fa10, pmvSetTarget);
