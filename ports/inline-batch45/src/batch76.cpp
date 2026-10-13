// batch76.cpp - player mechanics, main thread batch 76 (2026-10-11, after the account switch): the fence-gate and
// flag-raise hero movements. ZFFHeroMovementOpenGate::Move (0x5e6d60), ZFFHeroMovementRaiseFlag::Move (0x5e7000),
// ZFFHeroMovementOpenGate::TerminateControl (0x5e73c0). Names from the GC map (high).
#include "ff.h"

extern "C" void FASTCALL ext_4de420(float *dst, const float *src);                          // mcpy
extern "C" void FASTCALL ext_4de520(float *out, const float *a, const float *b, float t);    // mpul (matrix blend)
extern "C" void THISCALL ext_594590(void *hero);                                             // ZFFHERO::RestoreItem
extern "C" void THISCALL ext_59a6a0(void *osd, bool on);                                     // OSD flag +0x22ce

static inline u8 *sys76() { return G(u8 *, 0x70039c); }
// seconds since a start time stored as float seconds: (tick - (int)(t * 1024)) * (1/1024), all single precision
static inline float since76(float t) {
  return (float)(s32)(*(u32 *)(sys76() + 0x40) - (u32)(s32)(t * 1024.0f)) * 0.0009765625f;
}

// Shared body of the two "walk into place over 0.24 s" moves. start time at +t0, start pos +sp, target pos +sp+12,
// start matrix +sm, target matrix +sm+0x24, logger line and message.
static inline void moveIntoPlace(u8 *self, const float *mat, const float *pos, float *newMat, float *newPos,
                                 float *speed, u32 t0, u32 sp, u32 sm, u32 line, u32 msg) {
  speed[2] = 0.0f;
  speed[1] = 0.0f;
  speed[0] = 0.0f;
  float u = since76(*(float *)(self + t0)) / 0.239999994635581970f;
  if (u > 1.0f) {
    *(u32 *)&newPos[0] = *(const u32 *)&pos[0];
    *(u32 *)&newPos[1] = *(const u32 *)&pos[1];
    *(u32 *)&newPos[2] = *(const u32 *)&pos[2];
    ext_4de420(newMat, mat);
    return;
  }
  float *s = (float *)(self + sp), *t = (float *)(self + sp + 12);
  newPos[0] = (t[0] - s[0]) * u + s[0];
  newPos[1] = (t[1] - s[1]) * u + s[1];
  newPos[2] = (t[2] - s[2]) * u + s[2];
  ext_4de520(newMat, (float *)(self + sm), (float *)(self + sm + 0x24), u);
  if (vcall<bool>(self, 0x48, mat, pos, newMat, newPos, speed)) {
    u8 *lg = vcall<u8 *>(G(void *, 0x700390), 0x20, (const char *)0x6b7a5c, line);
    typedef void (*logfn)(void *, const char *, ...);
    (*(logfn *)(*(u8 **)lg + 0x2c))(lg, (const char *)msg);
  }
}

// 0x5e6d60 ZFFHeroMovementOpenGate::Move(mat, pos, newMat, newPos, speed), thiscall, ret 0x14. speed = 0;
// u = seconds since +0x54f / 0.24. u > 1: hero in place (newPos = pos, newMat = mat). Otherwise newPos lerps from
// +0x55f to +0x56b, newMat = mpul(+0x577, +0x59b, u), then the own collision check (slot 0x48); on a hit the engine
// logger (line 0xa36) prints "ERROR: Unable to move hero towards fence (collides with something)".
static void THISCALL openGateMove(u8 *self, const float *mat, const float *pos, float *newMat, float *newPos,
                                  float *speed) {
  moveIntoPlace(self, mat, pos, newMat, newPos, speed, 0x54f, 0x55f, 0x577, 0xa36u, 0x6b7ea8u);
}
// PCREG(5e6d60, openGateMove);  // not registered: batch72 owns 0x5e6d60 (duplicate symbol at link time)

// 0x5e7000 ZFFHeroMovementRaiseFlag::Move, same shape: start time +0x555, positions +0x56d/+0x579, matrices
// +0x585/+0x5a9, logger line 0x750, message at 0x6b7e30.
static void THISCALL raiseFlagMove(u8 *self, const float *mat, const float *pos, float *newMat, float *newPos,
                                   float *speed) {
  moveIntoPlace(self, mat, pos, newMat, newPos, speed, 0x555, 0x56d, 0x585, 0x750u, 0x6b7e30u);
}
// PCREG(5e7000, raiseFlagMove);  // not registered: batch73 owns 0x5e7000 (duplicate symbol at link time)

// 0x5e73c0 ZFFHeroMovementOpenGate::TerminateControl(bool force), thiscall, ret 4, al. force clears the busy byte
// +0x54c. When it is clear: the hero's (+0x36d) OSD (+0x852) flag is switched off, RestoreItem gives the hero back the
// item put away for the gate, and the hero timer +0x9e3 is zeroed. Returns true when +0x54c is clear (may let go).
static u8 THISCALL openGateTerminateControl(u8 *self, u32 force) {
  if ((u8)force) self[0x54c] = 0;
  if (self[0x54c] != 0) return 0;
  u8 *hero = *(u8 **)(self + 0x36d);
  ext_59a6a0(*(void **)(hero + 0x852), false);
  ext_594590(*(void **)(self + 0x36d));
  *(u32 *)(*(u8 **)(self + 0x36d) + 0x9e3) = 0;
  return self[0x54c] == 0;
}
// PCREG(5e73c0, openGateTerminateControl);  // not registered: batch72 owns 0x5e73c0 (duplicate symbol at link time)
