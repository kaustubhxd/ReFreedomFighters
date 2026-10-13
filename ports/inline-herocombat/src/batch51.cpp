// batch51.cpp - shoot tree, inline session batch 51: aim-assist target test and target pick (ZCamHelper).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u8(THISCALL *vcallB0)(void *self);
typedef void(THISCALL *vcallP)(void *self, float *p);
typedef u32(THISCALL *vcallUP)(void *self, float *p);
typedef void(THISCALL *vcallVU)(void *self, u32 a);
typedef u32(THISCALL *vcallUU)(void *self, u32 a);

extern "C" float FASTCALL ext_4e0830(const float *a, const float *b);   // vdist2, ST0
extern "C" float THISCALL ext_5cf520(u8 *cam, const float *p);          // aim angle to point (batch 50), ST0
extern "C" u8 THISCALL ext_5cd750(u8 *cam, const float *p);             // ray clear (batch 50)
extern "C" void FASTCALL ext_43e920(float *dst, const float *src, const float *a);  // PSVECSubtract (batch 34)
extern "C" float FASTCALL ext_4e0030(const float *a, const float *b);   // vangle, ST0
extern "C" u8 THISCALL ext_5d0490(u8 *cam, u8 *t);

// 0x5d0490, thiscall, ret 4, result in al: can actor t be an aim-assist target? Not when its slot 0x438 is true, its
// geom (+8) has bit 10 of +0x3c set, it is the hero (+0x44), or its team (+0x54, then +4, as a bit index) is not in
// the mask at +0xb50. Its position (slots 0x3a0, 0x398, then y + 10 and slot 0x84) must be within the squared range
// +0xe01 of +0xd22 and within the angle +0xdf9 of the aim direction. Then it is a target when byte +0xb45 is set,
// otherwise when the ray to it is clear.
static u8 THISCALL canTarget(u8 *cam, u8 *t) {
  u8 *hero = *(u8 **)(cam + 0x44);
  if (((vcallB0)VT(t, 0x438))(t))
    return 0;
  if ((*(u32 *)(*(u8 **)(t + 8) + 0x3c) >> 10) & 1u)
    return 0;
  if (hero == t)
    return 0;
  u8 *team = *(u8 **)(t + 0x54);
  if (team && (*(u32 *)(cam + 0xb50) & (1u << (*(u32 *)(team + 4) & 31))) == 0)
    return 0;
  float pos[3];
  void **tvt = *(void ***)t;
  u32 m = ((vcallUP)tvt[0x3a0 / 4])(t, pos);
  ((vcallVU)tvt[0x398 / 4])(t, m);
  pos[1] = pos[1] + 10.0f;
  ((vcallP)VT(t, 0x84))(t, pos);
  float d2 = ext_4e0830(pos, (const float *)(cam + 0xd22));
  if (d2 > *(float *)(cam + 0xe01))
    return 0;
  float ang = ext_5cf520(cam, pos);
  if (ang > *(float *)(cam + 0xdf9))
    return 0;
  if (cam[0xb45])
    return 1;
  return ext_5cd750(cam, pos);
}
PCREG(5d0490, canTarget);

// One candidate of the pick: chest-height point (0, 150, 0) through slot 0x84, angle from the aim direction.
static void consider(u8 *cam, u8 *t, float *best, u8 **bestT) {
  if (!ext_5d0490(cam, t))
    return;
  float pos[3] = {0.0f, 150.0f, 0.0f};
  ((vcallP)VT(t, 0x84))(t, pos);
  float d[3];
  ext_43e920(d, pos, (const float *)(cam + 0xcad));
  float ang = ext_4e0030(d, (const float *)(cam + 0xa72));
  if (*best > ang) {
    *best = ang;
    *bestT = t;
  }
}

// 0x5cf110, thiscall, result in al: picks the aim-assist target with the smallest angle from the aim direction among
// the actor list at [0x7003b8]+0x4b4 (entries point to records whose +4 is the actor) and the mover list at +0x40c.
// Clears +0xd0d, +0xd2e and byte +0xd33 first; on a pick, +0xd2e = render-manager slot 0x4c (actor), +0xd33 = 1.
static u8 THISCALL pickAimTarget(u8 *cam) {
  float best = 1e38f;
  u8 *bestT = 0;
  *(u32 *)(cam + 0xd0d) = 0;
  *(u32 *)(cam + 0xd2e) = 0;
  cam[0xd33] = 0;
  u8 *game = G(u8 *, 0x7003b8);
  for (u8 **it = (u8 **)(game + 0x4b4); it != (u8 **)(game + 0x4b4 + *(s32 *)(game + 0x4b0) * 4);
       game = G(u8 *, 0x7003b8), ++it)
    if (*it)
      consider(cam, *(u8 **)(*it + 4), &best, &bestT);
  game = G(u8 *, 0x7003b8);
  for (u8 **it = (u8 **)(game + 0x40c); it != (u8 **)(game + 0x40c + *(s32 *)(game + 0x408) * 4);
       game = G(u8 *, 0x7003b8), ++it)
    if (*it)
      consider(cam, *it, &best, &bestT);
  if (bestT) {
    u8 *rm = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    *(u32 *)(cam + 0xd2e) = ((vcallUU)VT(rm, 0x4c))(rm, (u32)bestT);
    cam[0xd33] = 1;
  }
  return cam[0xd33];
}
PCREG(5cf110, pickAimTarget);
