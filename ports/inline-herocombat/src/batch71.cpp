// batch71.cpp - sewer entry, inline session batch 71: ZFFHeroMovementOpenSewer TerminateControl (0x5e7420),
// WantControl (0x5e88e0), GotControl (0x5e5600), Move (0x5e6eb0) and GetActiveAnim (0x5e3220), and
// ZFFActionClimbSewer::Execute (0x5e0100).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vcallU0)(void *self);
typedef u32(THISCALL *vcallUU)(void *self, u32 a);
typedef u8(THISCALL *vcallB0)(void *self);
typedef void(THISCALL *vcallVP)(void *self, void *a);
typedef void(THISCALL *vcallVU)(void *self, u32 a);
typedef void(THISCALL *vcallVPP)(void *self, void *a, void *b);
typedef u32(THISCALL *vcallUPP)(void *self, void *a, void *b);
typedef void(THISCALL *vcallVUUP)(void *self, u32 a, u32 b, void *c);
typedef u8(THISCALL *moveFn)(void *self, const float *a, const float *b, float *m, float *p, float *v);
typedef void(THISCALL *playFn)(void *self, u32 anim, u32 a, float b, float c, float d);
typedef u32(THISCALL *regFn)(void *self, u32 name, u32 a, u32 file, u32 line);
typedef void(THISCALL *sendCmdFn)(void *self, u32 cmd, void *data, void *sender);  // ZGEOM::SendCommand(cmd, data, sender)
typedef u32(THISCALL *findFn)(void *self, u32 name, u32 a);
typedef void *(*logFn)(void *log, u32 fmt);

extern "C" void THISCALL ext_594590(u8 *hero);                                   // ZFFHERO::RestoreItem (batch 70)
extern "C" void THISCALL ext_595010(u8 *hero, u32 type);                         // ZFFHERO::SetTempItem (batch 70)
extern "C" void THISCALL ext_59a6a0(u8 *osd, u32 on);                            // throw / progress meter on (batch 38)
extern "C" void THISCALL ext_59a6b0(u8 *osd, float v);                           // ZGameOSD::ProgressValue
extern "C" void THISCALL ext_5950c0(u8 *hero, u32 action, float dist, const char *s);   // SetUseAction (batch 59)
extern "C" void THISCALL ext_5c3860(u8 *sewer, u32 arg);                         // COpenSewer::ActivateMenu (batch 70)
extern "C" void THISCALL ext_596940(u8 *osd, u32 kind, float *pos, u32 a, s32 b);   // ZGameOSD::CharismaAddExperience
extern "C" u8 *THISCALL ext_59b3c0(u8 *lc);                                      // ZFFLevelController::GetStartingSewerLid
extern "C" void FASTCALL ext_43e920(float *dst, const float *a, const float *b);  // PSVECSubtract (batch 34)
extern "C" void FASTCALL ext_4e09b0(float *v);                                    // vneg in place
extern "C" void FASTCALL ext_4de040(float *out, const float *p, const float *q);  // createmat (batch 36)
extern "C" void FASTCALL ext_443ef0(float *dst, const float *a, const float *v, float s);   // (batch 65)
extern "C" void THISCALL ext_4e0d00(float *v, float s);                           // vscalar in place (batch 29)
extern "C" void FASTCALL ext_4de4b0(float *dst, const float *a, const float *m);  // mmtmul (batch 70)
extern "C" void FASTCALL ext_4de4f0(float *m, const float *n);                    // m *= n^T (batch 70)
extern "C" void FASTCALL ext_4de420(float *dst, const float *src);                // mcpy (batch 29)
extern "C" void FASTCALL ext_4de520(float *dst, const float *a, const float *b, float t);   // mpul (matrix blend)

static u8 *sys() { return G(u8 *, 0x70039c); }
static u8 *rmgr() { return *(u8 **)(sys() + 0x9b); }
static float secs(s32 ticks) { return (float)ticks * bitsf(0x3a800000u); }
static s32 ticksOf(float s) { return _mm_cvttss_si32(_mm_set_ss(s * 1024.0f)); }

// The movement object: hero at +0x36d, active byte +0x54c, done byte +0x54d, start time +0x54f, the chosen sewer
// record +0x557 (9 bytes in the level's list at [0x7003b8]+0xc6d: COpenSewer*, lid handle, opened byte), the hero's
// start position +0x55b, the walk-to position +0x567, the start frame +0x573, the walk-to frame +0x597 and the
// "Open_Sewer" animation +0x553.

// 0x5e7420 ZFFHeroMovementOpenSewer::TerminateControl(bool force), thiscall, ret 4, al. Forced, the movement stops.
// When it is not active any more the hero gets its item back (RestoreItem), the progress meter goes off and the hero's
// use time +0x9e3 is cleared. True when not active.
static u8 THISCALL terminateControl(u8 *self, u8 force) {
  if (force)
    self[0x54c] = 0;
  if (!self[0x54c]) {
    ext_594590(*(u8 **)(self + 0x36d));
    ext_59a6a0(*(u8 **)(*(u8 **)(self + 0x36d) + 0x852), 0);
    *(u32 *)(*(u8 **)(self + 0x36d) + 0x9e3) = 0;
  }
  return self[0x54c] == 0;
}
PCREG(5e7420, terminateControl);

// 0x5e88e0 ZFFHeroMovementOpenSewer::WantControl(const float *a, const float *pos, const float *c), thiscall, ret
// 0xc, al. While active: true. With the hero's sewer flag (+0x9f5) every lid of the level's sewer list is tested: its
// position (slot 0x80 of the lid object) raised by 60 against pos; the last lid within 200 units is chosen (+0x557).
// The use prompt (SetUseAction) is 12 for an opened lid (record byte +8) or 10 otherwise, with the distance of the
// LAST lid tested, not the chosen one (as the exe does). Use pressed (+0x66c) on action 12 opens the sewer menu
// (ActivateMenu, false); on action 10 it starts the movement (true).
static u8 THISCALL wantControl(u8 *self, const float *, const float *pos, const float *) {
  if (self[0x54c])
    return 1;
  u8 *hero = *(u8 **)(self + 0x36d);
  if (!hero[0x9f5])
    return 0;
  *(u32 *)(self + 0x557) = 0;
  u8 *L = G(u8 *, 0x7003b8);
  float l2 = 0.0f;
  for (u8 *rec = L + 0xc6d; rec != L + 0xc6d + 9 * *(u32 *)(L + 0xc69); rec += 9) {
    u8 *rm = rmgr();
    u8 *o = (u8 *)((vcallUU)VT(rm, 0x58))(rm, *(u32 *)(rec + 4));
    float m[9], p[3], d[3];
    ((vcallVPP)VT(o, 0x80))(o, m, p);
    p[1] = p[1] + 60.0f;
    ext_43e920(d, p, pos);
    l2 = ((d[1] * d[1]) + (d[0] * d[0])) + (d[2] * d[2]);
    if (!(l2 > 40000.0f)) {
      double s = crt::sqrt((double)l2);
      ext_4e0d00(d, (float)(1.0 / s));
      *(u32 *)(self + 0x557) = (u32)rec;
    }
  }
  u8 *rec = *(u8 **)(self + 0x557);
  if (!rec)
    return 0;
  float dist = (float)crt::sqrt((double)l2);
  ext_5950c0(hero, rec[8] ? 12 : 10, dist, 0);
  hero = *(u8 **)(self + 0x36d);
  if (*(u32 *)(hero + 0x9d3) == 12) {
    if (hero[0x66c]) {
      u8 *r = *(u8 **)(self + 0x557);
      ext_5c3860(*(u8 **)r, *(u32 *)(r + 4));
    }
    return 0;
  }
  if (*(u32 *)(hero + 0x9d3) == 10 && hero[0x66c])
    return 1;
  return 0;
}
PCREG(5e88e0, wantControl);

// The inline x87 normalise (53-bit, so double arithmetic); an all-zero vector is left alone.
static void normalize3(float *v) {
  if (v[0] == 0.0f && v[1] == 0.0f && v[2] == 0.0f)
    return;
  double x = v[0], y = v[1], z = v[2];
  double inv = 1.0 / crt::sqrt(((x * x) + (y * y)) + (z * z));
  v[0] = (float)((double)v[0] * inv);
  v[1] = (float)((double)v[1] * inv);
  v[2] = (float)((double)v[2] * inv);
}

// 0x5e5600 ZFFHeroMovementOpenSewer::GotControl(), thiscall. Starts the walk to the lid: active, not done, start time
// now; the hero's frame and position (hero slot 0x59c) are the start, raised by 1. The lid (render manager slot 0x58
// on the record's handle) gives the walk-to frame and position. The flat direction from the hero to the lid, negated,
// makes the walk-to frame (createmat); the walk-to point is 81.945 short of the lid along it, at the hero's height.
// The lid's parent and the lid itself are turned to face the hero: parent frame = createmat(-dir) times the transpose
// of the parent's old frame, then the lid's frame is multiplied by the transpose of that (0x4de4f0). The hero gets the
// crowbar as a temporary item (SetTempItem(1)), the progress meter goes on at 0 and the hero's use time +0x9e3 is now.
static void THISCALL gotControl(u8 *self) {
  float now = secs(*(s32 *)(sys() + 0x40));
  *(u16 *)(self + 0x54c) = 1;
  *(float *)(self + 0x54f) = now;
  u8 *hero = *(u8 **)(self + 0x36d);
  ((vcallVPP)VT(hero, 0x59c))(hero, self + 0x573, self + 0x55b);
  *(float *)(self + 0x55f) = *(float *)(self + 0x55f) + 1.0f;
  u8 *rm = rmgr();
  u8 *o = (u8 *)((vcallUU)VT(rm, 0x58))(rm, *(u32 *)(*(u8 **)(self + 0x557) + 4));
  ((vcallVPP)VT(o, 0x80))(o, self + 0x597, self + 0x567);
  float d[3];
  ext_43e920(d, (float *)(self + 0x567), (float *)(self + 0x55b));
  d[1] = 0.0f;
  ext_4e09b0(d);
  ext_4de040((float *)(self + 0x597), d, 0);
  ext_4e09b0(d);
  normalize3(d);
  *(u32 *)(self + 0x56b) = *(u32 *)(self + 0x55f);
  ext_443ef0((float *)(self + 0x567), (float *)(self + 0x567), d, bitsf(0xc2a3e3d7u));   // -81.945
  float m1[9], p1[3], m2[9], m3[9];
  u8 *g = (u8 *)((vcallU0)VT(o, 0x20))(o);
  ((vcallVPP)VT(g, 0x80))(g, m1, p1);
  ext_4e09b0(d);
  ext_4de040(m2, d, 0);
  ext_4de4b0(m3, m2, m1);
  g = (u8 *)((vcallU0)VT(o, 0x20))(o);
  ((vcallVPP)VT(g, 0x7c))(g, m2, p1);
  ((vcallVPP)VT(o, 0x80))(o, m2, p1);
  ext_4de4f0(m2, m3);
  ((vcallVPP)VT(o, 0x7c))(o, m2, p1);
  *(u32 *)(self + 0x56b) = *(u32 *)(self + 0x55f);
  ext_595010(*(u8 **)(self + 0x36d), 1);
  ext_59a6a0(*(u8 **)(*(u8 **)(self + 0x36d) + 0x852), 1);
  ext_59a6b0(*(u8 **)(*(u8 **)(self + 0x36d) + 0x852), 0.0f);
  *(float *)(*(u8 **)(self + 0x36d) + 0x9e3) = secs(*(s32 *)(sys() + 0x40));
}
PCREG(5e5600, gotControl);

// 0x5e6eb0 ZFFHeroMovementOpenSewer::Move(const float *m, const float *p, float *outM, float *outP, float *outV),
// thiscall, ret 0x14. No velocity. t = time since the start / 0.24 s. After t = 1 the hero stays where it is;
// before, the position goes linearly from the start to the walk-to point and the frame blends (mpul) from the start
// frame to the walk-to frame. The base move check (slot 0x48) failing logs "Unable to move hero towards sewer".
static void THISCALL move(u8 *self, const float *m, const float *p, float *outM, float *outP, float *outV) {
  outV[2] = 0.0f;
  outV[1] = 0.0f;
  outV[0] = 0.0f;
  s32 ti = ticksOf(*(float *)(self + 0x54f));
  float t = (float)(s32)((u32) * (s32 *)(sys() + 0x40) - (u32)ti) * bitsf(0x3a800000u) / bitsf(0x3e75c28fu);
  if (t > 1.0f) {
    outP[0] = p[0];
    outP[1] = p[1];
    outP[2] = p[2];
    ext_4de420(outM, m);
    return;
  }
  const float *a = (const float *)(self + 0x55b), *b = (const float *)(self + 0x567);
  outP[0] = (b[0] - a[0]) * t + a[0];
  outP[1] = (b[1] - a[1]) * t + a[1];
  outP[2] = (b[2] - a[2]) * t + a[2];
  ext_4de520(outM, (const float *)(self + 0x573), (const float *)(self + 0x597), t);
  if (((moveFn)VT(self, 0x48))(self, m, p, outM, outP, outV)) {
    u8 *lg = G(u8 *, 0x700390);
    u8 *l = (u8 *)((findFn)VT(lg, 0x20))(lg, 0x6b7a5cu, 0xb18);
    ((logFn)VT(l, 0x2c))(l, 0x6b7ef8u);
  }
}
PCREG(5e6eb0, move);

// 0x5e3220 ZFFHeroMovementOpenSewer::GetActiveAnim(AnimHeader **out, ...), thiscall, ret 0x14, ST0 = the animation
// time. A hero that cannot act (slot 0x438) or no "Open_Sewer" animation ends the movement (0). t = time since the
// start * the animation's rate (+0x6c), in frames; the animation has frames +0x60 to +0x64.
// - Before frame 139 with the hero's use time cleared, the movement ends (the use button was let go).
// - After frame 104 the hero puts the crowbar away (RestoreItem, SetTempItem(0)).
// - The meter shows t / 139. Past the animation's last frame the sewer menu opens (ActivateMenu) and the movement
//   ends. Past frame 139, once: the meter goes off, the record is marked opened, the lid gets "ReloadRelativePos" and
//   "Activate" (ZFFHeroMovement.cpp lines 0xaf4 and 0xaf5), and on a level whose name has '1' at +0x4a the hero gets
//   the open-sewer experience at its position (CharismaAddExperience(2, pos, 1, -1)).
// Returns t / frame count.
static long double THISCALL getActiveAnim(u8 *self, u32 *out, const float *, const float *, const float *, const float *) {
  u8 *hero = *(u8 **)(self + 0x36d);
  if (((vcallB0)VT(hero, 0x438))(hero)) {
    self[0x54c] = 0;
    return 0.0L;
  }
  u8 *anim = *(u8 **)(self + 0x553);
  *out = (u32)anim;
  if (!anim) {
    self[0x54c] = 0;
    return 0.0L;
  }
  s32 n = *(s32 *)(anim + 0x64) - *(s32 *)(anim + 0x60) + 1;
  float nf = (float)n;
  s32 ti = ticksOf(*(float *)(self + 0x54f));
  float t = (float)(s32)((u32) * (s32 *)(sys() + 0x40) - (u32)ti) * bitsf(0x3a800000u) * (float)*(s32 *)(anim + 0x6c);
  if (!(t == 0.0f) && 139.0f > t && *(float *)(*(u8 **)(self + 0x36d) + 0x9e3) == 0.0f)
    self[0x54c] = 0;
  if (t > 104.0f) {
    ext_594590(*(u8 **)(self + 0x36d));
    ext_595010(*(u8 **)(self + 0x36d), 0);
  }
  ext_59a6b0(*(u8 **)(*(u8 **)(self + 0x36d) + 0x852), t / 139.0f);
  if (t > (float)n) {
    u8 *r = *(u8 **)(self + 0x557);
    ext_5c3860(*(u8 **)r, *(u32 *)(r + 4));
    self[0x54c] = 0;
  } else if (t > 139.0f && !self[0x54d]) {
    ext_59a6a0(*(u8 **)(*(u8 **)(self + 0x36d) + 0x852), 0);
    (*(u8 **)(self + 0x557))[8] = 1;
    u8 *rm = rmgr();
    u8 *o = (u8 *)((vcallUU)VT(rm, 0x58))(rm, *(u32 *)(*(u8 **)(self + 0x557) + 4));
    if (o) {
      void **vt = *(void ***)o;
      rm = rmgr();
      u16 id = (u16)((regFn)VT(rm, 0x114))(rm, 0x68ff4cu, 0, 0x6b7a5cu, 0xaf4);
      ((sendCmdFn)vt[0x128 / 4])(o, id, 0, 0);
      vt = *(void ***)o;
      rm = rmgr();
      id = (u16)((regFn)VT(rm, 0x114))(rm, 0x682e18u, 0, 0x6b7a5cu, 0xaf5);
      ((sendCmdFn)vt[0x128 / 4])(o, id, 0, 0);
    }
    self[0x54d] = 1;
    if ((*(u8 **)(G(u8 *, 0x7003b8) + 0x2c15))[0x4a] == '1') {
      u8 *h = *(u8 **)(self + 0x36d);
      void **hv = *(void ***)h;
      float mm[9], pos[3];
      u32 x = ((vcallUPP)hv[0x3a0 / 4])(h, mm, pos);
      ((vcallVU)hv[0x390 / 4])(h, x);
      u8 *g = (u8 *)((vcallU0)VT(*(u8 **)(self + 0x36d), 0x20))(*(u8 **)(self + 0x36d));
      ((vcallVP)VT(g, 0x84))(g, pos);
      ext_596940(*(u8 **)(*(u8 **)(self + 0x36d) + 0x852), 2, pos, 1, -1);
    }
  }
  return (long double)((double)t / (double)nf);
}
PCREG(5e3220, getActiveAnim);

// 0x5e0100 ZFFActionClimbSewer::Execute(), thiscall, al. Without an animation (+0xc) true. Otherwise the level's
// starting sewer lid (GetStartingSewerLid) places the hero: at its "MO_Sewer_HeroPos_*" marker, else its
// "MO_Sewer_Manhole_*" marker, else the lid itself (the grandparent's slot 0x25c finds them), the hero plays the climb
// animation (slot 0x228(anim, 1, 0, -1, 1)) and its geometry is set to the marker's frame and position (slot 0x74).
// False.
static u8 THISCALL climbSewerExecute(u8 *self) {
  u32 anim = *(u32 *)(self + 0xc);
  if (!anim)
    return 1;
  u8 *lc = *(u8 **)(G(u8 *, 0x7003b8) + 0x2c15);
  if (!lc)
    return 0;
  u8 *lid = ext_59b3c0(lc);
  if (!lid)
    return 0;
  u8 *a = (u8 *)((vcallU0)VT(lid, 0x20))(lid);
  u8 *b = (u8 *)((vcallU0)VT(a, 0x20))(a);
  u8 *p = (u8 *)((findFn)VT(b, 0x25c))(b, 0x6b74e8u, 0);
  if (!p) {
    a = (u8 *)((vcallU0)VT(lid, 0x20))(lid);
    b = (u8 *)((vcallU0)VT(a, 0x20))(a);
    p = (u8 *)((findFn)VT(b, 0x25c))(b, 0x6b74fcu, 0);
    if (!p)
      p = lid;
  }
  float m[9], pos[3];
  ((vcallVPP)VT(p, 0x80))(p, m, pos);
  u8 *hero = *(u8 **)(self + 8);
  ((playFn)VT(hero, 0x228))(hero, anim, 1, 0.0f, -1.0f, 1.0f);
  u8 *g = (u8 *)((vcallU0)VT(*(u8 **)(self + 8), 0x20))(*(u8 **)(self + 8));
  ((vcallVPP)VT(g, 0x74))(g, m, pos);
  return 0;
}
PCREG(5e0100, climbSewerExecute);
