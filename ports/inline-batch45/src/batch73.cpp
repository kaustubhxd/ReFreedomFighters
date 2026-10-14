// batch73.cpp - raising an enemy flag, inline session batch 73: CEnemyFlag::FlagPole (0x5c1650), the flag's
// "Activate" (0x5c1d10), its stop (0x5c1f70) and raised-by (0x5c21c0) helpers, CSaveMissions GetNumPrimaryObjectives
// (0x5b0bf0) and GetNumPrimaryObjectivesCompleted (0x5b0c50), ZFFHERO::SetRaisingFlag (0x594fb0) and
// ZFFHeroMovementRaiseFlag WantControl (0x5e8d40), GotControl (0x5e5950), TerminateControl (0x5e7480), Move
// (0x5e7000) and GetActiveAnim (0x5e3920).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vcallU0)(void *self);
typedef u32(THISCALL *vcallUU)(void *self, u32 a);
typedef u8(THISCALL *vcallB0)(void *self);
typedef void(THISCALL *vcallVP)(void *self, void *a);
typedef void(THISCALL *vcallVPP)(void *self, void *a, void *b);
typedef void(THISCALL *vcallVUP)(void *self, u32 a, void *b);
typedef long double(THISCALL *vcallF0)(void *self);
typedef u8(THISCALL *moveFn)(void *self, const float *a, const float *b, float *m, float *p, float *v);
typedef u32(THISCALL *regFn)(void *self, u32 name, u32 a, u32 file, u32 line);
typedef void(THISCALL *sendCmdFn)(void *self, u32 cmd, u32 data, u32 sender);  // ZGEOM::SendCommand(cmd, data, sender)
typedef void(THISCALL *sendHFn)(void *self, u32 handle, u32 cmd, u32 data);    // ZGEOM::SendCommand(handle, cmd, data)
typedef u32(THISCALL *findFn)(void *self, u32 name, u32 a);
typedef void *(*logFn)(void *log, u32 fmt);

extern "C" void THISCALL ext_59a6a0(u8 *osd, u32 on);                            // throw / progress meter on (batch 38)
extern "C" void THISCALL ext_59a6b0(u8 *osd, float v);                           // ZGameOSD::ProgressValue
extern "C" void THISCALL ext_5950c0(u8 *hero, u32 action, float dist, const char *s);   // SetUseAction (batch 59)
extern "C" void THISCALL ext_595440(u8 *hero, u32 stash, u32 reason);            // ZFFHERO::StashItem (batch 49)
extern "C" u8 *THISCALL ext_5c1650(u8 *flag);                                    // CEnemyFlag::FlagPole
extern "C" void THISCALL ext_5c1d10(u8 *flag);                                   // the flag's "Activate"
extern "C" void THISCALL ext_5c1f70(u8 *flag);                                   // the flag's stop
extern "C" void THISCALL ext_5c21c0(u8 *flag, u8 *hero);                         // raised by
extern "C" void THISCALL ext_5c21e0(u8 *flag, u32 team);                         // CEnemyFlag::SwitchFlags
extern "C" void THISCALL ext_4690b0(u8 *flag);                                   // empty (a shared 'ret')
extern "C" u32 THISCALL ext_5b0bf0(u8 *sm, const char *name);                    // GetNumPrimaryObjectives
extern "C" u32 THISCALL ext_5b0c50(u8 *sm, const char *name);                    // GetNumPrimaryObjectivesCompleted
extern "C" void THISCALL ext_594fb0(u8 *hero, u32 on, u8 *flag);                 // ZFFHERO::SetRaisingFlag
extern "C" void THISCALL ext_5d26c0(u8 *cam, u8 *flag);                          // ZCamHelper::StartRaisingFlag
extern "C" void THISCALL ext_5cd580(u8 *cam);                                    // ZCamHelper::AbortRaisingFlag
extern "C" void FASTCALL ext_43e920(float *dst, const float *a, const float *b);  // PSVECSubtract (batch 34)
extern "C" void FASTCALL ext_4e09b0(float *v);                                    // vneg in place
extern "C" void FASTCALL ext_4de040(float *out, const float *p, const float *q);  // createmat (batch 36)
extern "C" void FASTCALL ext_443ef0(float *dst, const float *a, const float *v, float s);   // (batch 65)
extern "C" void FASTCALL ext_451890(float *dst, const float *v, float s);         // dst += v * s
extern "C" void THISCALL ext_4e0d00(float *v, float s);                           // vscalar in place (batch 29)
extern "C" void FASTCALL ext_4de420(float *dst, const float *src);                // mcpy (batch 29)
extern "C" void FASTCALL ext_4de520(float *dst, const float *a, const float *b, float t);   // mpul (matrix blend)

static u8 *sys() { return G(u8 *, 0x70039c); }
static u8 *rmgr() { return *(u8 **)(sys() + 0x9b); }
static float secs(s32 ticks) { return (float)ticks * bitsf(0x3a800000u); }
static s32 ticksOf(float s) { return _mm_cvttss_si32(_mm_set_ss(s * 1024.0f)); }
static u8 *mapH(u32 h) {
  u8 *rm = rmgr();
  return (u8 *)((vcallUU)VT(rm, 0x58))(rm, h);
}
static u16 reg(u32 name, u32 file, u32 line) {
  u8 *rm = rmgr();
  return (u16)((regFn)VT(rm, 0x114))(rm, name, 0, file, line);
}
static void send(u8 *o, u32 cmd, u32 data) { ((sendCmdFn)VT(o, 0x128))(o, cmd, data, 0); }
// [0x70038c] slot 0xcc: the flag (CEnemyFlag) for a handle.
static u8 *flagOf(u32 h) {
  u8 *m = G(u8 *, 0x70038c);
  return (u8 *)((vcallUU)VT(m, 0xcc))(m, h);
}

// A CEnemyFlag: its geometry +0x44, team +0x48, previous team +0x4c, raised by +0x108, "raised" byte +0x106 (the
// flag already flies; a guess), a parent geometry +0x10d whose slot 0x25c finds the per-team flag object by name
// (names from +0xe4, indexed by team - +0xe8), and an optional pole handle +0x115 and flag object handle +0x111.

// 0x5c1650 CEnemyFlag::FlagPole() const, thiscall: the pole geometry (render manager slot 0x58 on +0x115), or the
// flag's own geometry when it has no pole handle.
static u8 *THISCALL flagPole(u8 *self) {
  u32 h = *(u32 *)(self + 0x115);
  if (h)
    return mapH(h);
  return *(u8 **)(self + 0x44);
}
PCREG(5c1650, flagPole);

static u8 *teamFlag(u8 *self, u32 team) {
  u8 *p = *(u8 **)(self + 0x10d);
  u32 name = (*(u32 **)(self + 0xe4))[team - *(u32 *)(self + 0xe8)];
  return (u8 *)((findFn)VT(p, 0x25c))(p, name, 0);
}

// 0x5c1d10, the flag's "Activate" (FlagRaised.cpp), thiscall. With a flag object handle (+0x111) the flag's geometry
// sends it "Activate" (line 0x1bf) by handle; otherwise the current team's flag object, if found, gets it (0x1c4).
static void THISCALL flagActivate(u8 *self) {
  u32 h = *(u32 *)(self + 0x111);
  if (h) {
    u8 *g = *(u8 **)(self + 0x44);
    void **vt = *(void ***)g;
    u16 id = reg(0x682e18u, 0x6b3a74u, 0x1bf);
    ((sendHFn)vt[0x12c / 4])(*(u8 **)(self + 0x44), *(u32 *)(self + 0x111), id, 0);
    return;
  }
  u8 *o = teamFlag(self, *(u32 *)(self + 0x48));
  if (o)
    send(o, reg(0x682e18u, 0x6b3a74u, 0x1c4), 0);
}
PCREG(5c1d10, flagActivate);

// 0x5c1f70, the flag's stop, thiscall. The flag object (by handle +0x111, else the current team's one) gets
// "StopAnim" (line 0x1b5) and "FrameCurrent" 10000 (line 0x1b6).
static void THISCALL flagStop(u8 *self) {
  u32 h = *(u32 *)(self + 0x111);
  u8 *o = h ? mapH(h) : teamFlag(self, *(u32 *)(self + 0x48));
  if (!o)
    return;
  send(o, reg(0x68ff10u, 0x6b3a74u, 0x1b5), 0);
  send(o, reg(0x68fee8u, 0x6b3a74u, 0x1b6), 10000);
}
PCREG(5c1f70, flagStop);

// 0x5c21c0, raised by (hero), thiscall, ret 4: remembers the hero (+0x108) and switches the flag to the hero's team
// (the dword at +4 of the hero's +0x54 object; SwitchFlags).
static void THISCALL raisedBy(u8 *self, u8 *hero) {
  *(u8 **)(self + 0x108) = hero;
  ext_5c21e0(self, *(u32 *)(*(u8 **)(hero + 0x54) + 4));
}
PCREG(5c21c0, raisedBy);

// The objective list: count +0x5b8, name pointers from +8, and per objective a "secondary" dword at +0x5c0 and a
// "completed" dword at +0x3c8 (both indexed like the names). Only the first 4 characters of the name are compared,
// with no test for the end of either string.
static bool same4(const char *a, const char *b) {
  for (int j = 0; j < 4; ++j)
    if (a[j] != b[j])
      return false;
  return true;
}

// 0x5b0bf0 CSaveMissions::GetNumPrimaryObjectives(const char *name) const, thiscall, ret 4.
static u32 THISCALL numPrimary(u8 *self, const char *name) {
  s32 n = *(s32 *)(self + 0x5b8);
  u32 k = 0;
  for (s32 i = 0; i < n; ++i)
    if (*(u32 *)(self + 0x5c0 + 4 * i) == 0 && same4(name, *(const char **)(self + 8 + 4 * i)))
      ++k;
  return k;
}
PCREG(5b0bf0, numPrimary);

// 0x5b0c50 CSaveMissions::GetNumPrimaryObjectivesCompleted(const char *name) const, thiscall, ret 4.
static u32 THISCALL numPrimaryDone(u8 *self, const char *name) {
  s32 n = *(s32 *)(self + 0x5b8);
  u32 k = 0;
  for (s32 i = 0; i < n; ++i)
    if (*(u32 *)(self + 0x5c0 + 4 * i) == 0 && same4(name, *(const char **)(self + 8 + 4 * i)) &&
        *(u32 *)(self + 0x3c8 + 4 * i) != 0)
      ++k;
  return k;
}
PCREG(5b0c50, numPrimaryDone);

// 0x594fb0 ZFFHERO::SetRaisingFlag(bool on, CEnemyFlag *flag), thiscall, ret 8. When exactly one primary objective
// of the level (its name at the level controller +0x48, the save missions at +0x50f) is still open, the hero's camera
// helper (+0x85a) starts the flag-raise camera. The bool is not used.
static void THISCALL setRaisingFlag(u8 *self, u32, u8 *flag) {
  u8 *lc = *(u8 **)(G(u8 *, 0x7003b8) + 0x2c15);
  u32 n = ext_5b0bf0(lc + 0x50f, (const char *)(lc + 0x48));
  lc = *(u8 **)(G(u8 *, 0x7003b8) + 0x2c15);
  if (n - ext_5b0c50(lc + 0x50f, (const char *)(lc + 0x48)) == 1)
    ext_5d26c0(*(u8 **)(self + 0x85a), flag);
}
PCREG(594fb0, setRaisingFlag);

// The movement object: hero +0x36d (and the owner, also a ZFFHERO, at +4), active +0x550, frame-0 / frame-45 /
// frame-60 bytes +0x551..+0x553, done +0x554, start time +0x555, the animations +0x559 (raise), +0x55d and +0x561
// (with a flag object; +0x561 when the flag is raised), the "FlagList" handle +0x565, the flag handle +0x569, the
// hero's start position +0x56d, walk-to position +0x579, start frame +0x585 and walk-to frame +0x5a9. The team of
// the flag goes to +0x54c.

// 0x5e8d40 ZFFHeroMovementRaiseFlag::WantControl(const float *a, const float *pos, const float *c), thiscall, ret
// 0xc, al. While active: true. A hero that may raise flags (slot 0x5a4) looks the database's "FlagList" up once
// (+0x565) and walks its handle list (+0x18 of the list object): the first flag whose pole top (hero height added,
// slot 0x5b4) is within 100 units in height and 100 units flat of pos and whose team differs from the hero's (+0x54
// object, +4) is chosen. Quirks kept from the exe: without a flag in the list the "distance" is the bit pattern of
// the pos pointer read as a float, and after a full walk the last flag looked at (whatever its team) and the list's
// end value in +0x569 are used. A flag that answers "FlagRaiseInProgress" (line 0x6ea) with non-zero logs "Denied!"
// (line 0x6ec). Otherwise the use prompt is 2 with the distance; pressing use on prompt 2 starts the movement.
static u8 THISCALL wantControl(u8 *self, const float *, const float *pos, const float *) {
  if (self[0x550])
    return 1;
  u8 *hero = *(u8 **)(self + 0x36d);
  if (!((vcallB0)VT(hero, 0x5a4))(hero))
    return 0;
  if (!*(u32 *)(self + 0x565)) {
    u8 *rm = rmgr();
    u8 *db = (u8 *)((vcallU0)VT(rm, 0x138))(rm);
    u32 out = 0;
    ((vcallVUP)VT(db, 0x88))(db, 0x6b3bc0u, &out);
    *(u32 *)(self + 0x565) = out;
  }
  u8 *lst = mapH(*(u32 *)(self + 0x565));
  if (!lst)
    return 0;
  u8 *flag = 0;
  float l2 = __builtin_bit_cast(float, (u32)pos);
  u8 *it = *(u8 **)(lst + 0x18);
  if (it) {
    u32 at;
    ((vcallVP)VT(it, 0x4c))(it, &at);
    *(u32 *)(self + 0x569) = ((vcallUU)VT(*(u8 **)(lst + 0x18), 0x5c))(*(u8 **)(lst + 0x18), (u32)&at);
    while (at) {
      flag = flagOf(*(u32 *)(self + 0x569));
      if (flag) {
        u8 *pole = ext_5c1650(flag);
        float m[9], p[3], d[3];
        ((vcallVPP)VT(pole, 0x80))(pole, m, p);
        hero = *(u8 **)(self + 0x36d);
        long double h = ((vcallF0)VT(hero, 0x5b4))(hero);
        p[1] = (float)(h + (long double)p[1]);
        ext_43e920(d, p, pos);
        double dy = (double)d[1];
        if (!(__builtin_fabs(dy) > 100.0)) {
          d[1] = 0.0f;
          l2 = ((d[0] * d[0]) + 0.0f) + (d[2] * d[2]);
          if (!(l2 > 10000.0f)) {
            double s = crt::sqrt((double)l2);
            ext_4e0d00(d, (float)(1.0 / s));
            if (*(u32 *)(flag + 0x48) != *(u32 *)(*(u8 **)(*(u8 **)(self + 0x36d) + 0x54) + 4))
              break;
          }
        }
      }
      *(u32 *)(self + 0x569) = ((vcallUU)VT(*(u8 **)(lst + 0x18), 0x5c))(*(u8 **)(lst + 0x18), (u32)&at);
    }
  }
  if (!*(u32 *)(self + 0x569))
    return 0;
  if (flag) {
    u32 resp = 0;
    u8 *g = *(u8 **)(flag + 0x44);
    void **vt = *(void ***)g;
    u16 id = reg(0x6b3becu, 0x6b7a5cu, 0x6ea);
    ((sendCmdFn)vt[0x128 / 4])(*(u8 **)(flag + 0x44), id, (u32)&resp, 0);
    if (resp) {
      u8 *lg = G(u8 *, 0x700390);
      u8 *l = (u8 *)((findFn)VT(lg, 0x20))(lg, 0x6b7a5cu, 0x6ec);
      ((logFn)VT(l, 0x2c))(l, 0x6b7e28u);
      return 0;
    }
  }
  ext_5950c0(*(u8 **)(self + 0x36d), 2, (float)crt::sqrt((double)l2), 0);
  hero = *(u8 **)(self + 0x36d);
  return *(u32 *)(hero + 0x9d3) == 2 && hero[0x66c];
}
PCREG(5e8d40, wantControl);

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

// 0x5e5950 ZFFHeroMovementRaiseFlag::GotControl(), thiscall. Active (the dword at +0x550 = 1 also clears the three
// frame bytes), not done, start time now. The flag gets "StartFlagRaise" (line 0x703); the owner (+4) is told it
// raises the flag (SetRaisingFlag) and puts its item away (StashItem(true, 4)); with the hero's meter flag (+0x9e7)
// the progress meter goes on at 0; the hero's use time +0x9e3 is now. The hero's frame and position are the start.
// The pole (or the flag's geometry) gives the walk-to frame and position. A flag not yet raised: the walk-to frame
// faces the pole along the flat direction and the walk-to point is 84.743 short of the pole at the hero's height. A
// raised flag: the walk-to point is 38 along the pole frame's first row. The flag's team goes to +0x54c.
static void THISCALL gotControl(u8 *self) {
  *(u32 *)(self + 0x550) = 1;
  self[0x554] = 0;
  *(float *)(self + 0x555) = secs(*(s32 *)(sys() + 0x40));
  u8 *flag = flagOf(*(u32 *)(self + 0x569));
  if (flag) {
    u8 *g = *(u8 **)(flag + 0x44);
    void **vt = *(void ***)g;
    u16 id = reg(0x6b3bccu, 0x6b7a5cu, 0x703);
    ((sendCmdFn)vt[0x128 / 4])(*(u8 **)(flag + 0x44), id, 0, 0);
  }
  ext_594fb0(*(u8 **)(self + 4), 1, flag);
  ext_595440(*(u8 **)(self + 4), 1, 4);
  u8 *hero = *(u8 **)(self + 0x36d);
  if (hero[0x9e7]) {
    ext_59a6b0(*(u8 **)(hero + 0x852), 0.0f);
    ext_59a6a0(*(u8 **)(*(u8 **)(self + 0x36d) + 0x852), 1);
  }
  *(float *)(*(u8 **)(self + 0x36d) + 0x9e3) = secs(*(s32 *)(sys() + 0x40));
  hero = *(u8 **)(self + 0x36d);
  ((vcallVPP)VT(hero, 0x59c))(hero, self + 0x585, self + 0x56d);
  u8 *pole = ext_5c1650(flag);
  if (!pole)
    pole = *(u8 **)(flag + 0x44);
  if (!flag[0x106]) {
    ((vcallVPP)VT(pole, 0x80))(pole, self + 0x5a9, self + 0x579);
    float d[3];
    ext_43e920(d, (float *)(self + 0x579), (float *)(self + 0x56d));
    d[1] = 0.0f;
    ext_4e09b0(d);
    ext_4de040((float *)(self + 0x5a9), d, 0);
    ext_4e09b0(d);
    normalize3(d);
    *(u32 *)(self + 0x57d) = *(u32 *)(self + 0x571);
    ext_443ef0((float *)(self + 0x579), (float *)(self + 0x579), d, bitsf(0xc2a97c6au));   // -84.743
  } else {
    ((vcallVPP)VT(pole, 0x80))(pole, self + 0x5a9, self + 0x579);
    ext_451890((float *)(self + 0x579), (float *)(self + 0x5a9), 38.0f);
  }
  *(u32 *)(self + 0x54c) = *(u32 *)(flag + 0x48);
}
PCREG(5e5950, gotControl);

// 0x5e7480 ZFFHeroMovementRaiseFlag::TerminateControl(bool force), thiscall, ret 4, al. Forced, the movement stops.
// While active it only ends when the hero's meter flag (+0x9e7) is set. Ending a raise that is not done: the hero's
// camera helper (found by name "ZCamHelper", slot 0x100, when not cached at +0x85a) aborts the flag camera, the flag
// gets "StopFlagRaise" (line 0x734) and its flag object stops. When not active any more: meter off, the owner takes
// its item back (StashItem(false, 4)) and the use time is cleared. True when not active.
static u8 THISCALL terminateControl(u8 *self, u8 force) {
  if (force)
    self[0x550] = 0;
  if (self[0x550] && !(*(u8 **)(self + 0x36d))[0x9e7])
    return 0;
  u8 *flag = flagOf(*(u32 *)(self + 0x569));
  if (flag && !self[0x554]) {
    u8 *h = *(u8 **)(self + 0x36d);
    if (!*(u32 *)(h + 0x85a))
      *(u32 *)(h + 0x85a) = ((vcallUU)VT(h, 0x100))(h, 0x6a6e88u);
    ext_5cd580(*(u8 **)(h + 0x85a));
    u8 *g = *(u8 **)(flag + 0x44);
    void **vt = *(void ***)g;
    u16 id = reg(0x6b3bdcu, 0x6b7a5cu, 0x734);
    ((sendCmdFn)vt[0x128 / 4])(*(u8 **)(flag + 0x44), id, 0, 0);
    ext_5c1f70(flag);
  }
  if (!self[0x550]) {
    ext_59a6a0(*(u8 **)(*(u8 **)(self + 0x36d) + 0x852), 0);
    ext_595440(*(u8 **)(self + 4), 0, 4);
    *(u32 *)(*(u8 **)(self + 0x36d) + 0x9e3) = 0;
  }
  return self[0x550] == 0;
}
PCREG(5e7480, terminateControl);

// 0x5e7000 ZFFHeroMovementRaiseFlag::Move(...), thiscall, ret 0x14. The sewer and gate walk with the flag's fields;
// a failed move check logs "Unable to move hero towards flag" (line 0x750).
static void THISCALL move(u8 *self, const float *m, const float *p, float *outM, float *outP, float *outV) {
  outV[2] = 0.0f;
  outV[1] = 0.0f;
  outV[0] = 0.0f;
  s32 ti = ticksOf(*(float *)(self + 0x555));
  float t = (float)(s32)((u32) * (s32 *)(sys() + 0x40) - (u32)ti) * bitsf(0x3a800000u) / bitsf(0x3e75c28fu);
  if (t > 1.0f) {
    outP[0] = p[0];
    outP[1] = p[1];
    outP[2] = p[2];
    ext_4de420(outM, m);
    return;
  }
  const float *a = (const float *)(self + 0x56d), *b = (const float *)(self + 0x579);
  outP[0] = (b[0] - a[0]) * t + a[0];
  outP[1] = (b[1] - a[1]) * t + a[1];
  outP[2] = (b[2] - a[2]) * t + a[2];
  ext_4de520(outM, (const float *)(self + 0x585), (const float *)(self + 0x5a9), t);
  if (((moveFn)VT(self, 0x48))(self, m, p, outM, outP, outV)) {
    u8 *lg = G(u8 *, 0x700390);
    u8 *l = (u8 *)((findFn)VT(lg, 0x20))(lg, 0x6b7a5cu, 0x750);
    ((logFn)VT(l, 0x2c))(l, 0x6b7e30u);
  }
}
PCREG(5e7000, move);

// 0x5e3920 ZFFHeroMovementRaiseFlag::GetActiveAnim(AnimHeader **out, ...), thiscall, ret 0x14, ST0. The animation
// is +0x559 for a flag without a flag object, else +0x561 (raised) or +0x55d; none, or a hero in state 0x40000
// (slot 0x5c8), ends the movement (0). t = time since the start * the RAISE animation's rate, in frames, over the
// raise animation's frame count. Once each: at frame 0 the flag is activated, at frame 45 it is raised by the hero
// (team switch), at frame 60 an empty flag function is called. Before frame 45, after the start, a cleared use time
// ends the movement. With the meter flag the meter shows t / frames. Past the last frame the flag is raised by the
// hero again, gets "FlagRaised" (line 0x790), and the movement is done and ends. Returns t / frame count.
static long double THISCALL getActiveAnim(u8 *self, u32 *out, const float *, const float *, const float *, const float *) {
  u8 *flag = flagOf(*(u32 *)(self + 0x569));
  if (!*(u32 *)(flag + 0x111))
    *out = *(u32 *)(self + 0x559);
  else
    *out = *(u32 *)(self + (flag[0x106] ? 0x561 : 0x55d));
  if (!*out) {
    self[0x550] = 0;
    return 0.0L;
  }
  u8 *hero = *(u8 **)(self + 0x36d);
  if (((vcallU0)VT(hero, 0x5c8))(hero) & 0x40000) {
    self[0x550] = 0;
    return 0.0L;
  }
  s32 ti = ticksOf(*(float *)(self + 0x555));
  float sec = (float)(s32)((u32) * (s32 *)(sys() + 0x40) - (u32)ti) * bitsf(0x3a800000u);
  u8 *anim = *(u8 **)(self + 0x559);
  s32 n = *(s32 *)(anim + 0x64) - *(s32 *)(anim + 0x60) + 1;
  float nf = (float)n;
  float t = (float)*(s32 *)(anim + 0x6c) * sec;
  if (!self[0x551] && t >= 0.0f) {
    self[0x551] = 1;
    ext_5c1d10(flag);
  }
  if (!self[0x552] && t >= 45.0f) {
    self[0x552] = 1;
    ext_5c21c0(flag, *(u8 **)(self + 0x36d));
  }
  if (!self[0x553] && t >= 60.0f) {
    self[0x553] = 1;
    ext_4690b0(flag);
  }
  if (!(t == 0.0f) && !self[0x552] && *(float *)(*(u8 **)(self + 0x36d) + 0x9e3) == 0.0f) {
    self[0x550] = 0;
    return (long double)((double)t / (double)nf);
  }
  hero = *(u8 **)(self + 0x36d);
  if (hero[0x9e7])
    ext_59a6b0(*(u8 **)(hero + 0x852), t / (float)n);
  if (t > (float)n) {
    ext_5c21c0(flag, *(u8 **)(self + 0x36d));
    u8 *g = *(u8 **)(flag + 0x44);
    void **vt = *(void ***)g;
    u16 id = reg(0x6b3aa8u, 0x6b7a5cu, 0x790);
    ((sendCmdFn)vt[0x128 / 4])(*(u8 **)(flag + 0x44), id, 0, 0);
    self[0x554] = 1;
    self[0x550] = 0;
  }
  return (long double)((double)t / (double)nf);
}
PCREG(5e3920, getActiveAnim);
