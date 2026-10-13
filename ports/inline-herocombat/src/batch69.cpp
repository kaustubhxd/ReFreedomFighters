// batch69.cpp - hero death, inline session batch 69: ZPlayer::IsDead (0x483ee0), ZFFActor::IsDead (0x5a0ad0),
// ZPlayer::DisableCollision (0x483100), ZPlayer::DisableControls (0x483110), ZPlayer::Die (0x4830e0), ZFFHERO::Die
// (0x5910d0), ZGROUP::AddSound2d (0x43eb80), ZIKLNKOBJ::PlaySound (0x466f60) and ZFFHERO::PerformDie (0x593cc0).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vcallU0)(void *self);
typedef u32(THISCALL *vcallUU)(void *self, u32 a);
typedef u32(THISCALL *vcallUUU)(void *self, u32 a, u32 b);
typedef void(THISCALL *vcallV0)(void *self);
typedef void(THISCALL *vcallVU)(void *self, u32 a);
typedef void(THISCALL *vcallVP)(void *self, void *a);
typedef void(THISCALL *vcallVUP)(void *self, u32 a, void *b);
typedef u8(THISCALL *vcallBU)(void *self, u32 a);
typedef u32(THISCALL *regFn)(void *self, u32 name, u32 a, u32 file, u32 line);
typedef void(THISCALL *sendHFn)(void *self, u32 target, u32 cmd, void *data);    // ZGEOM::SendCommand(handle, cmd, data)
typedef void(THISCALL *sendGFn)(void *self, void *target, u32 cmd, void *data);  // ZGEOM::SendCommand(geom, cmd, data)
typedef void *(*logFn)(void *log, u32 fmt);                                       // cdecl, variadic in the exe

extern "C" void THISCALL ext_4830e0(u8 *self, const float *a, const float *b, float f);   // ZPlayer::Die (this batch)
extern "C" u32 THISCALL ext_43ec00(u8 *grp, float *mat, float *pos, u32 snd, u32 a, u32 b, u32 c);   // AddSound3d
extern "C" u32 THISCALL ext_43eb80(u8 *grp, u32 snd);                             // AddSound2d (this batch)
extern "C" u32 THISCALL ext_466f60(u8 *self, u32 snd);                            // PlaySound (this batch)

static u8 *sys() { return G(u8 *, 0x70039c); }
static u8 *rmgr() { return *(u8 **)(sys() + 0x9b); }

// 0x483ee0 ZPlayer::IsDead() const, thiscall, al = bit 18 (0x40000) of +0x417.
static u8 THISCALL playerIsDead(u8 *self) { return (u8)((*(u32 *)(self + 0x417) >> 18) & 1); }
PCREG(483ee0, playerIsDead);

// 0x5a0ad0 ZFFActor::IsDead() const, thiscall, al. States 1, 2 and 3 of +8 are the dead ones.
static u8 THISCALL actorIsDead(u8 *self) {
  u32 s = *(u32 *)(self + 8);
  return s == 1 || s == 2 || s == 3;
}
PCREG(5a0ad0, actorIsDead);

// 0x483100 ZPlayer::DisableCollision(), thiscall. Counts +0x602 up and clears the collision byte +0x5ff.
static void THISCALL disableCollision(u8 *self) {
  ++*(u32 *)(self + 0x602);
  self[0x5ff] = 0;
}
PCREG(483100, disableCollision);

// 0x483110 ZPlayer::DisableControls(), thiscall. The first time (count +0x606 at 0) the controls object named in the
// database (render manager slot 0x138, then its slot 0x88 by name into a handle) gets the message registered by
// RegisterZMsg (slot 0x114, line 0x1a4) through the player's own SendCommand(handle, cmd, 0) (slot 0x12c, vtable read
// before the register call). Then the count goes up, flag 0x200 is set in +0x417 and byte +0x600 is cleared.
static void THISCALL disableControls(u8 *self) {
  if (*(u32 *)(self + 0x606) == 0) {
    u8 *rm = rmgr();
    u8 *db = (u8 *)((vcallU0)VT(rm, 0x138))(rm);
    u32 h = 0;
    ((vcallVUP)VT(db, 0x88))(db, 0x68be98u, &h);
    if (h) {
      void **vt = *(void ***)self;
      rm = rmgr();
      u16 id = (u16)((regFn)VT(rm, 0x114))(rm, 0x68be9cu, 0, 0x68bcbcu, 0x1a4);
      ((sendHFn)vt[0x12c / 4])(self, h, id, 0);
    }
  }
  ++*(u32 *)(self + 0x606);
  *(u32 *)(self + 0x417) |= 0x200;
  self[0x600] = 0;
}
PCREG(483110, disableControls);

// 0x4830e0 ZPlayer::Die(const float *dir, const float *pos, float force), thiscall, ret 0xc. Drops the current link
// action (slot 0x3dc) and calls slot 8 of the object at +0x455 with 1. The arguments are not used.
static void THISCALL playerDie(u8 *self, const float *, const float *, float) {
  ((vcallV0)VT(self, 0x3dc))(self);
  u8 *o = *(u8 **)(self + 0x455);
  ((vcallVU)VT(o, 8))(o, 1);
}
PCREG(4830e0, playerDie);

// 0x5910d0 ZFFHERO::Die(const float *a, const float *b, float force), thiscall, ret 0xc. Once only (flag 0x40000 of
// +0x417): ZPlayer::Die, then a goes to +0x9fa, b to +0xa06 and min(force, 250) * 0.02 to +0xa12, the dead flag is set,
// byte +0x827 = 1, and the hero drops its link action (slot 0x3dc), stops all animations (slot 0x220(0)) and disables
// its controls (slot 0x368).
static void THISCALL heroDie(u8 *self, const float *a, const float *b, float force) {
  if (*(u32 *)(self + 0x417) & 0x40000)
    return;
  ext_4830e0(self, a, b, force);
  float m = force < 250.0f ? force : 250.0f;   // minss
  *(u32 *)(self + 0x9fa) = *(const u32 *)a;
  *(u32 *)(self + 0x9fe) = *(const u32 *)(a + 1);
  *(u32 *)(self + 0xa02) = *(const u32 *)(a + 2);
  *(u32 *)(self + 0xa06) = *(const u32 *)b;
  *(u32 *)(self + 0xa0a) = *(const u32 *)(b + 1);
  *(u32 *)(self + 0xa0e) = *(const u32 *)(b + 2);
  *(u32 *)(self + 0x417) |= 0x40000;
  *(float *)(self + 0xa12) = m * bitsf(0x3ca3d70au);   // 0.02
  self[0x827] = 1;
  ((vcallV0)VT(self, 0x3dc))(self);
  ((vcallVU)VT(self, 0x220))(self, 0);
  ((vcallV0)VT(self, 0x368))(self);
}
PCREG(5910d0, heroDie);

// 0x43eb80 ZGROUP::AddSound2d(int snd), thiscall, ret 4, eax. Without a sound system ([0x70039c]+0x1a9f) 0, otherwise
// its slot 0x120(snd, 4).
static u32 THISCALL addSound2d(u8 *, u32 snd) {
  u8 *ss = *(u8 **)(sys() + 0x1a9f);
  if (!ss)
    return 0;
  return ((vcallUUU)VT(ss, 0x120))(ss, snd, 4);
}
PCREG(43eb80, addSound2d);

// 0x466f60 ZIKLNKOBJ::PlaySound(unsigned snd), thiscall, ret 4, eax = the sound handle. Without a sound system 0. A
// positional sound (sound system slot 0xf0) plays with AddSound3d at the object's matrix ([+8], position at +0x24),
// any other with AddSound2d, both in the object's group (slot 0x20). The playing sound (render manager slot 0x60) gets
// flag 0x80 set and 4 cleared in +0x40, mode 2 (+0x2c) and the object's byte +0x143 at +0xc.
static u32 THISCALL playSound(u8 *self, u32 snd) {
  u8 *ss = *(u8 **)(sys() + 0x1a9f);
  if (!ss)
    return 0;
  u32 r;
  if (((vcallBU)VT(ss, 0xf0))(ss, snd)) {
    u8 *m = *(u8 **)(self + 8);
    u8 *grp = (u8 *)((vcallU0)VT(self, 0x20))(self);
    r = ext_43ec00(grp, (float *)m, (float *)(m + 0x24), snd, 0, 0, 0);
  } else {
    u8 *grp = (u8 *)((vcallU0)VT(self, 0x20))(self);
    r = ext_43eb80(grp, snd);
  }
  u8 *rm = rmgr();
  u8 *h = (u8 *)((vcallUU)VT(rm, 0x60))(rm, r);
  if (h) {
    *(u32 *)(h + 0x40) |= 0x80;
    *(u32 *)(h + 0x2c) = 2;
    u32 c = self[0x143];
    *(u32 *)(h + 0x40) &= ~4u;
    *(u32 *)(h + 0xc) = c;
  }
  return r;
}
PCREG(466f60, playSound);

// 0x593cc0 ZFFHERO::PerformDie(), thiscall. Clears +0x9e3 and byte +0x827, writes the log line (the logger [0x700390]
// slot 0x20(file, line 0x1003), then its cdecl slot 0x2c), plays the death sound +0xef6, and sends the message of line
// 0x1005 to the handle +0x846 when there is one (SendCommand(handle, cmd, 0), slot 0x12c). Collision goes off (slot
// 0x584), +0x81b = 0 and +0x817 = now. An item in the right hand (slot 0x4f8, then its slot 0x10) is detached
// (slot 0x520(0)) and dropped (PerformDrop, slot 0x4f4).
// With byte +0x9e7 set, the item (or 0) is added once to the list at [0x7003b8] (count +0x8b4, entries from +0x8b8),
// the hero sends itself the message of line 0x1015 (SendCommand(geom, cmd, 0), slot 0x130) and +0x81b = 5. Otherwise
// the object named in the database (0x6a5c48) gets the message of line 0x101b and +0x81b = 3. Both hands' item states
// go to 0 (slots 0x518 and 0x51c).
static void THISCALL performDie(u8 *self) {
  *(u32 *)(self + 0x9e3) = 0;
  self[0x827] = 0;
  u8 *lg = G(u8 *, 0x700390);
  u8 *l = (u8 *)((vcallUUU)VT(lg, 0x20))(lg, 0x6ac6d0u, 0x1003);
  ((logFn)VT(l, 0x2c))(l, 0x6acf6cu);
  ext_466f60(self, *(u32 *)(self + 0xef6));
  if (*(u32 *)(self + 0x846)) {
    void **vt = *(void ***)self;
    u8 *rm = rmgr();
    u16 id = (u16)((regFn)VT(rm, 0x114))(rm, 0x6acf78u, 0, 0x6ac6d0u, 0x1005);
    ((sendHFn)vt[0x12c / 4])(self, *(u32 *)(self + 0x846), id, 0);
  }
  ((vcallV0)VT(self, 0x584))(self);
  *(u32 *)(self + 0x81b) = 0;
  *(float *)(self + 0x817) = (float)*(s32 *)(sys() + 0x40) * bitsf(0x3a800000u);
  u8 *rh = (u8 *)((vcallU0)VT(self, 0x4f8))(self);
  u32 it = ((vcallU0)VT(rh, 0x10))(rh);
  if (it) {
    ((vcallVU)VT(self, 0x520))(self, 0);
    ((vcallVU)VT(self, 0x4f4))(self, it);
  }
  if (self[0x9e7]) {
    u8 *L = G(u8 *, 0x7003b8);
    u32 *arr = (u32 *)(L + 0x8b8);
    u32 n = *(u32 *)(L + 0x8b4);
    u32 i = 0;
    while (i < n && arr[i] != it)
      ++i;
    if (i == n) {
      arr[n] = it;
      ++*(u32 *)(L + 0x8b4);
    }
    void **vt = *(void ***)self;
    u8 *rm = rmgr();
    u16 id = (u16)((regFn)VT(rm, 0x114))(rm, 0x690a14u, 0, 0x6ac6d0u, 0x1015);
    ((sendGFn)vt[0x130 / 4])(self, self, id, 0);
    *(u32 *)(self + 0x81b) = 0x40a00000u;   // 5.0f
  } else {
    u8 *rm = rmgr();
    u8 *db = (u8 *)((vcallU0)VT(rm, 0x138))(rm);
    u32 h = 0;
    ((vcallVUP)VT(db, 0x88))(db, 0x6a5c48u, &h);
    void **vt = *(void ***)self;
    rm = rmgr();
    u16 id = (u16)((regFn)VT(rm, 0x114))(rm, 0x6a4f9cu, 0, 0x6ac6d0u, 0x101b);
    ((sendHFn)vt[0x12c / 4])(self, h, id, 0);
    *(u32 *)(self + 0x81b) = 0x40400000u;   // 3.0f
  }
  ((vcallVU)VT(self, 0x518))(self, 0);
  ((vcallVU)VT(self, 0x51c))(self, 0);
}
PCREG(593cc0, performDie);
