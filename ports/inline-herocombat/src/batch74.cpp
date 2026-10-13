// batch74.cpp - planting C4, inline session batch 74: ZFFHeroMovementPlaceC4 WantControl (0x5e8ae0; the name map
// splits it at 0x5e8b0e and calls the head TerminateControl), GotControl (0x5e5890) and GetActiveAnim (0x5e34c0),
// ZFFHERO::SendFollowersToSafepoints (0x594c30), ConvPtr (0x41e680), ZBaseGeom::GetOwner (0x4db2f0) and
// ZGameOSD::MessageAdd (0x59a580).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vcallU0)(void *self);
typedef u32(THISCALL *vcallUU)(void *self, u32 a);
typedef u8(THISCALL *vcallB0)(void *self);
typedef u8(THISCALL *vcallBPF)(void *self, void *a, float b);
typedef void(THISCALL *vcallV0)(void *self);
typedef void(THISCALL *vcallVU)(void *self, u32 a);
typedef void(THISCALL *vcallVP)(void *self, void *a);
typedef void(THISCALL *vcallVUU)(void *self, u32 a, u32 b);
typedef void(THISCALL *vcallVUUU)(void *self, u32 a, u32 b, u32 c);
typedef void(THISCALL *vcallVPP)(void *self, void *a, void *b);
typedef void(THISCALL *vcallVUP)(void *self, u32 a, void *b);
typedef u32(THISCALL *vcallUUU)(void *self, u32 a, u32 b);
typedef u32(THISCALL *regFn)(void *self, u32 name, u32 a, u32 file, u32 line);
typedef void(THISCALL *sendCmdFn)(void *self, u32 cmd, u32 data, u32 sender);  // ZGEOM::SendCommand(cmd, data, sender)
typedef void(THISCALL *sendHFn)(void *self, u32 handle, u32 cmd, u32 data);    // ZGEOM::SendCommand(handle, cmd, data)
typedef void(THISCALL *sendGFn)(void *self, void *geom, u32 cmd, void *data);  // ZGEOM::SendCommand(geom, cmd, data)
typedef u32(THISCALL *findFn)(void *self, u32 name, u32 a);
typedef void *(*logFn)(void *log, u32 fmt);
typedef u32(THISCALL *convFn)(void *p);

extern "C" void THISCALL ext_59a6a0(u8 *osd, u32 on);                            // throw / progress meter on (batch 38)
extern "C" void THISCALL ext_59a6b0(u8 *osd, float v);                           // ZGameOSD::ProgressValue
extern "C" void THISCALL ext_5950c0(u8 *hero, u32 action, float dist, const char *s);   // SetUseAction (batch 59)
extern "C" u8 *THISCALL ext_591e50(u8 *hero, u32 type);                          // ZFFHERO::GetItem (batch 49)
extern "C" void THISCALL ext_594590(u8 *hero);                                   // ZFFHERO::RestoreItem (batch 70)
extern "C" void THISCALL ext_595010(u8 *hero, u32 type);                         // ZFFHERO::SetTempItem (batch 70)
extern "C" u8 *THISCALL ext_589c20(u8 *gd, u32 c);                               // ZFFGameData::GetGameOSD(char)
extern "C" void THISCALL ext_59a580(u8 *osd, u32 text, u32 a, u32 snd);          // ZGameOSD::MessageAdd
extern "C" void THISCALL ext_59a5e0(u8 *osd, u32 snd);                           // ZGameOSD::PlaySound
extern "C" void THISCALL ext_5aaa30(u8 *o, u32 text, u32 a);                     // ZOnScreenDisplay::MessageAdd
extern "C" u8 *THISCALL ext_4db2f0(u8 *geom, u32 b);                             // ZBaseGeom::GetOwner
extern "C" u32 FASTCALL ext_41e680(u32 p);                                        // ConvPtr
extern "C" void THISCALL ext_594c30(u8 *hero, u8 *geom, float r, u8 *list);      // SendFollowersToSafepoints
extern "C" void FASTCALL ext_451890(float *dst, const float *v, float s);         // dst += v * s
extern "C" float FASTCALL ext_4e0870(const float *a, const float *b);             // vdist (batch 48)
extern "C" float FASTCALL ext_4e0830(const float *a, const float *b);             // vdist2

static u8 *sys() { return G(u8 *, 0x70039c); }
static u8 *rmgr() { return *(u8 **)(sys() + 0x9b); }
static float secs(s32 ticks) { return (float)ticks * bitsf(0x3a800000u); }
static s32 ticksOf(float s) { return _mm_cvttss_si32(_mm_set_ss(s * 1024.0f)); }
static u16 reg(u32 name, u32 file, u32 line) {
  u8 *rm = rmgr();
  return (u16)((regFn)VT(rm, 0x114))(rm, name, 0, file, line);
}

// 0x41e680 ConvPtr(void *p), fastcall (ecx), eax. Null stays null; a pointer the object manager ([0x70038c] slot
// 0x20) claims gives 0. Inside the manager's range [+0xc, +0x10) with a converter at +8, the converter's result;
// otherwise the id stored just before the object (p[-1]), which the manager's slot 0xac assigns when it is 0.
static u32 FASTCALL convPtr(u32 p) {
  if (!p)
    return 0;
  u8 *m = G(u8 *, 0x70038c);
  if (((vcallUU)VT(m, 0x20))(m, p))
    return 0;
  m = G(u8 *, 0x70038c);
  u32 fn = *(u32 *)(m + 8);
  if (fn && *(u32 *)(m + 0xc) <= p && p < *(u32 *)(m + 0x10))
    return ((convFn)fn)((void *)p);
  if (!*(u32 *)(p - 4))
    ((vcallUU)VT(m, 0xac))(m, p);
  return *(u32 *)(p - 4);
}
PCREG(41e680, convPtr);

// 0x4db2f0 ZBaseGeom::GetOwner(bool b) const, thiscall, ret 4. A dynamic object (flag 0x40000 of +0x3c) logs a
// warning (zbasegeom.cpp line 0xa08) and gets the render manager's +0xadc. Otherwise, without a parent (+0x50): the
// object itself when its own link (+0x54) has type flag 0x100000 (+0xc, +0x23), else 0. With a parent: walk the
// parent's links (+0x54) up through each link's owner (+8, +0x50): the first link of type 0x100021, or with b one
// flagged 0x4000000 at +0x30; 0 at the top.
static u8 *THISCALL getOwner(u8 *self, u8 b) {
  if (*(u32 *)(self + 0x3c) & 0x40000) {
    u8 *lg = G(u8 *, 0x700390);
    u8 *l = (u8 *)((findFn)VT(lg, 0x20))(lg, 0x696e24u, 0xa08);
    ((logFn)VT(l, 0x2c))(l, 0x696fc8u);
    return *(u8 **)(rmgr() + 0xadc);
  }
  u8 *p = *(u8 **)(self + 0x50);
  if (!p) {
    u8 *q = *(u8 **)(self + 0x54);
    if (!q)
      return 0;
    return (*(u32 *)(*(u8 **)(q + 0xc) + 0x23) & 0x100000) ? self : 0;
  }
  for (u8 *e = *(u8 **)(p + 0x54); e;) {
    if (*(u32 *)(*(u8 **)(e + 0xc) + 0x23) == 0x100021)
      return e;
    if (b && (*(u32 *)(e + 0x30) & 0x4000000))
      return e;
    u8 *pp = *(u8 **)(*(u8 **)(e + 8) + 0x50);
    if (!pp)
      return 0;
    e = *(u8 **)(pp + 0x54);
  }
  return 0;
}
PCREG(4db2f0, getOwner);

// 0x59a580 ZGameOSD::MessageAdd(const char *text, unsigned a, ESOUNDTYPE snd), thiscall, ret 0xc. With an
// on-screen display (+0x1d0f): the OSD sound, then the display's MessageAdd(text, a).
static void THISCALL messageAdd(u8 *self, u32 text, u32 a, u32 snd) {
  if (!*(u32 *)(self + 0x1d0f))
    return;
  ext_59a5e0(self, snd);
  ext_5aaa30(*(u8 **)(self + 0x1d0f), text, a);
}
PCREG(59a580, messageAdd);

// 0x594c30 ZFFHERO::SendFollowersToSafepoints(ZGEOM *bomb, float r, ZLIST *points), thiscall, ret 0xc. Each
// follower (records of 0x30 bytes at +0xa1a, count +0xa16) within r of the bomb (flat: the bomb's height is replaced
// by each follower's in turn, and that change carries over to the next follower) gets "RunToSafepoint" (ZFFHero.cpp
// line 0x5e8) with the handle of the nearest safe point not yet taken (the list's handles, positions by slot 0x84).
// The taken marks are 17 bytes on the stack.
static void THISCALL sendFollowersToSafepoints(u8 *self, u8 *bomb, float r, u8 *points) {
  u8 taken[17];
  for (int i = 0; i < 17; ++i)
    taken[i] = 0;
  float c[3] = {0.0f, 0.0f, 0.0f};
  ((vcallVP)VT(bomb, 0x84))(bomb, c);
  for (u8 *rec = self + 0xa1a; rec != self + 0xa1a + 0x30 * *(u32 *)(self + 0xa16); rec += 0x30) {
    u8 *f = *(u8 **)rec;
    float fp[3] = {0.0f, 0.0f, 0.0f};
    ((vcallVP)VT(f, 0x84))(f, fp);
    c[1] = fp[1];
    float d = ext_4e0870(c, fp);
    if (!(r > d))
      continue;
    u32 best = 0;
    u32 bi = 0;
    float bd = 1e38f;
    u8 *it = *(u8 **)(points + 0x18);
    if (!it)
      continue;
    u32 at;
    ((vcallVP)VT(it, 0x4c))(it, &at);
    u32 h = ((vcallUU)VT(*(u8 **)(points + 0x18), 0x5c))(*(u8 **)(points + 0x18), (u32)&at);
    for (u32 i = 0; at; ++i) {
      if (!taken[i]) {
        u8 *rm = rmgr();
        u8 *o = (u8 *)((vcallUU)VT(rm, 0x58))(rm, h);
        float op[3] = {0.0f, 0.0f, 0.0f};
        ((vcallVP)VT(o, 0x84))(o, op);
        float d2 = ext_4e0830(fp, op);
        if (bd > d2) {
          best = h;
          bi = i;
          bd = d2;
        }
      }
      h = ((vcallUU)VT(*(u8 **)(points + 0x18), 0x5c))(*(u8 **)(points + 0x18), (u32)&at);
    }
    if (best) {
      taken[bi] = 1;
      void **vt = *(void ***)*(u8 **)rec;
      u16 id = reg(0x6a56ccu, 0x6ac6d0u, 0x5e8);
      ((sendCmdFn)vt[0x128 / 4])(*(u8 **)rec, id, (u32)&best, 0);
    }
  }
}
PCREG(594c30, sendFollowersToSafepoints);

// The movement object: hero +0x36d, active +0x54c, "the C4 was already in the hand" +0x54d, placed-in-world +0x54e,
// done +0x54f, start time +0x550, the animation +0x554, the bomb geometry +0x558, its damage list +0x55c, the safe
// point list +0x560 and radius +0x564.

// 0x5e8ae0 ZFFHeroMovementPlaceC4::WantControl(const float *a, const float *pos, const float *c), thiscall, ret
// 0xc, al. While active: true. Each bomb spot of the level ([0x7003b8]+0xb61 count, pointers from +0xb65) with a
// positive +0x64 (or NaN) is tested: its geometry's position raised by 60 is not used; pos goes to the geometry's
// space (slot 0x8c) and its slot 0x180(pos, 0) says whether the hero is in the spot. With the HUD's +0x1d13 at most
// 1/8192 the use prompt is 13 (distance 100). Use pressed on prompt 13: without C4 (GetItem(14)) the help text
// "YouDontHaveAnyC4" is shown on the hero's player's OSD; with it the spot's geometry is kept (+0x558) and asked for
// its bomb damage list ("Msg_GetBombDmgList", line 0xb65, into +0x55c) and safe points ("Msg_GetSafePointInfo",
// line 0xb6b: list +0x560, radius +0x564), and the movement starts.
static u8 THISCALL wantControl(u8 *self, const float *, const float *pos, const float *) {
  if (self[0x54c])
    return 1;
  u8 *L = G(u8 *, 0x7003b8);
  u8 *g = 0;
  u8 **it = (u8 **)(L + 0xb65);
  for (; it != (u8 **)(L + 0xb65 + 4 * *(u32 *)(L + 0xb61)); it++) {
    u8 *e = *it;
    if (0.0f >= *(float *)(e + 0x64))
      continue;
    g = *(u8 **)(e + 0x44);
    float m[9], p[3], q[3];
    ((vcallVPP)VT(g, 0x80))(g, m, p);
    p[1] = p[1] + 60.0f;
    q[0] = pos[0];
    q[1] = pos[1];
    q[2] = pos[2];
    ((vcallVP)VT(g, 0x8c))(g, q);
    if (((vcallBPF)VT(g, 0x180))(g, q, 0.0f))
      break;
  }
  if (it == (u8 **)(L + 0xb65 + 4 * *(u32 *)(L + 0xb61)))
    return 0;
  u8 *hero = *(u8 **)(self + 0x36d);
  if (*(float *)(*(u8 **)(hero + 0x852) + 0x1d13) > bitsf(0x39000000u))
    return 0;
  ext_5950c0(hero, 13, 100.0f, 0);
  hero = *(u8 **)(self + 0x36d);
  if (*(u32 *)(hero + 0x9d3) != 13 || !hero[0x66c])
    return 0;
  if (!ext_591e50(hero, 14)) {
    u8 pl = (*(u8 **)(self + 0x36d))[0x684];
    u8 *tt = *(u8 **)(rmgr() + 0xae4);
    u32 text = ((vcallUUU)VT(tt, 0))(tt, 0x6a67e8u, 0x6b7f3cu);
    u8 c = (u8)(pl - 1);
    u8 *osd = ext_589c20(G(u8 *, 0x7003b8), c);
    ext_59a580(osd, text, 0xffffffffu, 0);
    return 0;
  }
  *(u8 **)(self + 0x558) = g;
  void **vt = *(void ***)g;
  u16 id = reg(0x6b6a78u, 0x6b7a5cu, 0xb65);
  ((sendGFn)vt[0x130 / 4])(g, g, id, self + 0x55c);
  vt = *(void ***)g;
  u32 sp[2];
  id = reg(0x6ab704u, 0x6b7a5cu, 0xb6b);
  ((sendGFn)vt[0x130 / 4])(g, g, id, sp);
  *(u32 *)(self + 0x560) = sp[0];
  *(u32 *)(self + 0x564) = sp[1];
  return 1;
}
PCREG(5e8ae0, wantControl);

// 0x5e5890 ZFFHeroMovementPlaceC4::GotControl(), thiscall. Active, start time now; remembers whether the C4 (item
// 14) was already in the hand (+0x54d), clears the placed and done bytes, takes the C4 as a temporary item, meter on
// at 0, use time now.
static void THISCALL gotControl(u8 *self) {
  float now = secs(*(s32 *)(sys() + 0x40));
  self[0x54c] = 1;
  *(float *)(self + 0x550) = now;
  u8 *c4 = ext_591e50(*(u8 **)(self + 0x36d), 14);
  u8 *hero = *(u8 **)(self + 0x36d);
  u8 *hand = (u8 *)((vcallU0)VT(hero, 0x504))(hero);
  *(u16 *)(self + 0x54e) = 0;
  self[0x54d] = hand == c4;
  ext_595010(*(u8 **)(self + 0x36d), 14);
  ext_59a6b0(*(u8 **)(*(u8 **)(self + 0x36d) + 0x852), 0.0f);
  ext_59a6a0(*(u8 **)(*(u8 **)(self + 0x36d) + 0x852), 1);
  *(float *)(*(u8 **)(self + 0x36d) + 0x9e3) = secs(*(s32 *)(sys() + 0x40));
}
PCREG(5e5890, gotControl);

// The bomb's place: 45 back along the hero frame's first row and 20 along its third, at the hero (slot 0x80).
static void bombPlace(u8 *hero, float *m, float *p) {
  ((vcallVPP)VT(hero, 0x80))(hero, m, p);
  ext_451890(p, m, -45.0f);
  ext_451890(p, m + 6, 20.0f);
}

// 0x5e34c0 ZFFHeroMovementPlaceC4::GetActiveAnim(AnimHeader **out, ...), thiscall, ret 0x14, ST0. Ends (0) for a
// hero that cannot act (slot 0x438) or no animation (+0x554). Every call sends "Msg_Music_BombPlaced" (line 0xba4) to
// the "LevelController". t = time since the start * the animation's rate, in frames.
// - Use let go (hero +0x9e3 clear) after the start, before it is done: the item comes back (and the C4 goes back to
//   the hand, or the C4 item's slot 0x2d0(1, 0)), the damage list is dropped, the movement ends.
// - Past frame 32, once: the C4 leaves the hand (RestoreItem, SetTempItem(0), slot 0x2d0(0, 0)) and is placed in
//   the world at the bomb place (slot 0x7c).
// - The meter shows t / 128 while that is at most 1.
// - Past frame 128, once (done): the hand item comes back (the C4's place taken by item 1 when the C4 was in the
//   hand), the C4 gets the hero's owner (GetOwner(false)) with slot 0x2f0(0, owner, 1) and the bomb place; the damage
//   list goes into the database as "rFF_C4_BombDmgList"; the C4 is armed (slot 0x2d0(3, 0)); followers near the bomb
//   are sent to safe points; the meter goes off.
// - Past the last frame the movement ends.
static long double THISCALL getActiveAnim(u8 *self, u32 *out, const float *, const float *, const float *, const float *) {
  u8 *hero = *(u8 **)(self + 0x36d);
  if (((vcallB0)VT(hero, 0x438))(hero)) {
    self[0x54c] = 0;
    return 0.0L;
  }
  u32 anim = *(u32 *)(self + 0x554);
  *out = anim;
  if (!anim) {
    self[0x54c] = 0;
    return 0.0L;
  }
  u8 *c4 = ext_591e50(*(u8 **)(self + 0x36d), 14);
  hero = *(u8 **)(self + 0x36d);
  u8 *rm = rmgr();
  u8 *db = (u8 *)((vcallU0)VT(rm, 0x138))(rm);
  u32 lc = 0;
  ((vcallVUP)VT(db, 0x88))(db, 0x6a5c48u, &lc);
  void **hv = *(void ***)hero;
  u16 id = reg(0x6a4f70u, 0x6b7a5cu, 0xba4);
  ((sendHFn)hv[0x12c / 4])(hero, lc, id, 0);
  s32 ti = ticksOf(*(float *)(self + 0x550));
  float sec = (float)(s32)((u32) * (s32 *)(sys() + 0x40) - (u32)ti) * bitsf(0x3a800000u);
  u8 *a = (u8 *)*out;
  s32 n = *(s32 *)(a + 0x64) - *(s32 *)(a + 0x60) + 1;
  float nf = (float)n;
  float t = (float)*(s32 *)(a + 0x6c) * sec;
  if (!(t == 0.0f) && *(float *)(*(u8 **)(self + 0x36d) + 0x9e3) == 0.0f) {
    if (!self[0x54f]) {
      ext_594590(*(u8 **)(self + 0x36d));
      if (self[0x54d]) {
        u8 *h = *(u8 **)(self + 0x36d);
        ((vcallV0)VT(h, 0x3dc))(h);
        h = *(u8 **)(self + 0x36d);
        void **v = *(void ***)h;
        u8 *r2 = rmgr();
        u32 hh = ((vcallUU)VT(r2, 0x4c))(r2, (u32)c4);
        ((vcallVU)v[0x480 / 4])(h, hh);
      } else {
        ((vcallVUU)VT(c4, 0x2d0))(c4, 1, 0);
      }
      *(u32 *)(self + 0x55c) = 0;
    }
    self[0x54c] = 0;
  }
  if (t > 32.0f && !self[0x54e]) {
    self[0x54e] = 1;
    ext_594590(*(u8 **)(self + 0x36d));
    ext_595010(*(u8 **)(self + 0x36d), 0);
    ((vcallVUU)VT(c4, 0x2d0))(c4, 0, 0);
    float m[9], p[3];
    bombPlace(*(u8 **)(self + 0x36d), m, p);
    ((vcallVPP)VT(c4, 0x7c))(c4, m, p);
  }
  float pv = t * 0.0078125f;
  if (1.0f >= pv)
    ext_59a6b0(*(u8 **)(*(u8 **)(self + 0x36d) + 0x852), pv);
  if (t > 128.0f && !self[0x54f]) {
    if (self[0x54d]) {
      ext_594590(*(u8 **)(self + 0x36d));
      u8 *h = *(u8 **)(self + 0x36d);
      ((vcallV0)VT(h, 0x3dc))(h);
      h = *(u8 **)(self + 0x36d);
      void **v = *(void ***)h;
      u8 *r2 = rmgr();
      void **rv = *(void ***)r2;
      u8 *it1 = ext_591e50(h, 1);
      u32 hh = ((vcallUU)rv[0x4c / 4])(rmgr(), (u32)it1);
      ((vcallVU)v[0x480 / 4])(h, hh);
    }
    self[0x54f] = 1;
    u8 *owner = ext_4db2f0(*(u8 **)(*(u8 **)(self + 0x36d) + 8), 0);
    float m[9], p[3];
    bombPlace(*(u8 **)(self + 0x36d), m, p);
    ((vcallVUUU)VT(c4, 0x2f0))(c4, 0, (u32)owner, 1);
    ((vcallVPP)VT(c4, 0x7c))(c4, m, p);
    ext_41e680(*(u32 *)(self + 0x55c));
    u8 *r3 = rmgr();
    u8 *db2 = (u8 *)((vcallU0)VT(r3, 0x138))(r3);
    void **dv = *(void ***)db2;
    u32 x = ext_41e680(*(u32 *)(self + 0x55c));
    ((vcallUUU)dv[0x4c / 4])(db2, 0x6b52ccu, x);
    ((vcallVUU)VT(c4, 0x2d0))(c4, 3, 0);
    *(u32 *)(self + 0x55c) = 0;
    if (*(u32 *)(self + 0x560)) {
      ext_594c30(*(u8 **)(self + 0x36d), *(u8 **)(self + 0x558), *(float *)(self + 0x564), *(u8 **)(self + 0x560));
      *(u32 *)(self + 0x558) = 0;
      *(u32 *)(self + 0x560) = 0;
    }
    ext_59a6a0(*(u8 **)(*(u8 **)(self + 0x36d) + 0x852), 0);
  }
  if (t > (float)n)
    self[0x54c] = 0;
  return (long double)((double)t / (double)nf);
}
PCREG(5e34c0, getActiveAnim);
