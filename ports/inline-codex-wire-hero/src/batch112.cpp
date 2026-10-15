// batch112.cpp - going down into a sewer: walking to the lid and the lid-opening animation (climb thread, batch 112).
#include "ff.h"

extern "C" void FASTCALL ext_4de420(float *dst, const float *src);                          // mcpy
extern "C" void FASTCALL ext_4de520(float *out, const float *a, const float *b, float t);    // mpul (matrix blend)
extern "C" void THISCALL ext_594590(void *hero);                                             // ZFFHERO::RestoreItem
extern "C" void THISCALL ext_595010(void *hero, u32 item);                                   // ZFFHERO::SetTempItem
extern "C" void THISCALL ext_59a6b0(void *osd, float v);                                     // ZGameOSD::ProgressValue
extern "C" void THISCALL ext_5c3860(void *openSewer, u32 ref);                               // COpenSewer::ActivateMenu
extern "C" void THISCALL ext_59a6a0(void *osd, bool on);                                     // OSD flag (batch 109)
extern "C" void THISCALL ext_596940(void *osd, u32 a, const float *pos, u32 b, s32 c);       // ZGameOSD::CharismaAddExperience

static inline u8 *sys() { return G(u8 *, 0x70039c); }
static inline u8 *engineDb() { return *(u8 **)(sys() + 0x9b); }
static inline float since(float t) { return (float)(s32)(*(u32 *)(sys() + 0x40) - (u32)(s32)(t * 1024.0f)) * 0.0009765625f; }

// 0x5e6eb0, ZFFHeroMovementOpenSewer::Move(mat, pos, newMat, newPos, speed) (GC map high). thiscall, ret 0x14.
// speed = 0. u = seconds since the start (+0x54f) / 0.24. After 0.24 s (u > 1): newPos = pos and newMat = mat (the hero
// is in place). Before: newPos = start (+0x55b) + (target (+0x567) - start) * u per axis, newMat = mpul(start matrix
// +0x573, target matrix +0x597, u), then the collision check (own slot 0x48); when it reports a hit, the engine logger
// ([0x700390] slot 0x20(file, line 0xb18), then its varargs slot 0x2c) prints "ERROR: Unable to move hero towards sewer".
static void THISCALL openSewerMove(u8 *self, const float *mat, const float *pos, float *newMat, float *newPos,
                                   float *speed) {
  speed[2] = 0.0f;
  speed[1] = 0.0f;
  speed[0] = 0.0f;
  float u = since(*(float *)(self + 0x54f)) / 0.239999994635581970f;
  if (u > 1.0f) {
    *(u32 *)&newPos[0] = *(const u32 *)&pos[0];
    *(u32 *)&newPos[1] = *(const u32 *)&pos[1];
    *(u32 *)&newPos[2] = *(const u32 *)&pos[2];
    ext_4de420(newMat, mat);
    return;
  }
  float *s = (float *)(self + 0x55b), *t = (float *)(self + 0x567);
  newPos[0] = (t[0] - s[0]) * u + s[0];
  newPos[1] = (t[1] - s[1]) * u + s[1];
  newPos[2] = (t[2] - s[2]) * u + s[2];
  ext_4de520(newMat, (float *)(self + 0x573), (float *)(self + 0x597), u);
  if (vcall<bool>(self, 0x48, mat, pos, newMat, newPos, speed)) {
    u8 *lg = vcall<u8 *>(G(void *, 0x700390), 0x20, (const char *)0x6b7a5c, 0xb18u);
    typedef void (*logfn)(void *, const char *, ...);
    (*(logfn *)(*(u8 **)lg + 0x2c))(lg, (const char *)0x6b7ef8);
  }
}
PCREG(5e6eb0, openSewerMove);

// 0x5e3220, ZFFHeroMovementOpenSewer::GetActiveAnim(AnimHeader** out, a, b, c, d) (GC map high). thiscall, ret 0x14, ST0.
//  - Hero slot 0x438() true (guess: interrupted), or no Open_Sewer animation (+0x553, also written to *out): "opening"
//    +0x54c clears and the phase is 0.
//  - f = seconds since start (+0x54f) * fps (int at anim+0x6c); frames = (anim+0x64) - (anim+0x60) + 1.
//  - f not 0 (NaN counts) and below 139 with hero+0x9e3 equal to 0: "opening" clears (the use button was let go,
//    inferred: hero+0x9e3 holds the time the button went down).
//  - f above 104: RestoreItem and SetTempItem(0) (the tool is put away). Progress bar = f / 139.
//  - f past the last frame: COpenSewer::ActivateMenu(sewer +0, sewer +4) and "opening" clears (the sewer menu opens).
//  - Else f above 139 and +0x54d clear, once: display flag off, the lid is marked open (sewer+8), the lid geom gets the
//    messages "ReloadRelativePos" and "Activate" (RegisterZMsg(name, 0, file, line 0xaf4 / 0xaf5, 0, 0), then slot 0x128(id), one argument);
//    +0x54d set; and on the level whose controller byte +0x4a is '1' (game data +0x2c15; a level-name digit, guess) the
//    hero gets the charisma bonus: hero slot 0x390(hero slot 0x3a0(mat, pos)), position through hero->slot 0x20()'s
//    slot 0x84, then ZGameOSD::CharismaAddExperience(2, pos, 1, -1).
//  - Returns f / frames, divided on the x87 stack.
static long double THISCALL openSewerGetActiveAnim(u8 *self, u8 **out, const float *a, const float *b, const float *c,
                                                   const float *d) {
  (void)a;
  (void)b;
  (void)c;
  (void)d;
  if (vcall<bool>(*(void **)(self + 0x36d), 0x438)) {
    self[0x54c] = 0;
    return 0.0L;
  }
  u8 *an = *(u8 **)(self + 0x553);
  *out = an;
  if (!an) {
    self[0x54c] = 0;
    return 0.0L;
  }
  s32 nframes = *(s32 *)(an + 0x64) - *(s32 *)(an + 0x60) + 1;
  float frames = (float)nframes;
  float f = since(*(float *)(self + 0x54f)) * (float)*(s32 *)(an + 0x6c);
  if (f != 0.0f && 139.0f > f && *(float *)(*(u8 **)(self + 0x36d) + 0x9e3) == 0.0f)
    self[0x54c] = 0;
  if (f > 104.0f) {
    ext_594590(*(void **)(self + 0x36d));
    ext_595010(*(void **)(self + 0x36d), 0);
  }
  ext_59a6b0(*(void **)(*(u8 **)(self + 0x36d) + 0x852), f / 139.0f);
  if (f > (float)nframes) {
    u8 *s = *(u8 **)(self + 0x557);
    ext_5c3860(*(void **)s, *(u32 *)(s + 4));
    self[0x54c] = 0;
  } else if (f > 139.0f && !self[0x54d]) {
    ext_59a6a0(*(void **)(*(u8 **)(self + 0x36d) + 0x852), false);
    (*(u8 **)(self + 0x557))[8] = 1;
    void *g = vcall<void *>(engineDb(), 0x58, *(u32 *)(*(u8 **)(self + 0x557) + 4));
    if (g) {
      // RegisterZMsg takes four arguments (ret 0x10); the two extra pushes of the exe stay on the stack and reach slot 0x128 as
      // its second and third arguments (ret 0xc on the geom classes), so they are passed on as zeros here.
      u16 id = vcall<u16>(engineDb(), 0x114, (const char *)0x68ff4c, 0u, (const char *)0x6b7a5c, 0xaf4u);
      vcall<void>(g, 0x128, (u32)id, 0u, 0u);
      u16 id2 = vcall<u16>(engineDb(), 0x114, (const char *)0x682e18, 0u, (const char *)0x6b7a5c, 0xaf5u);
      vcall<void>(g, 0x128, (u32)id2, 0u, 0u);
    }
    self[0x54d] = 1;
    if ((*(u8 **)(G(u8 *, 0x7003b8) + 0x2c15))[0x4a] == 0x31) {
      void *hero = *(void **)(self + 0x36d);
      u8 *vt = *(u8 **)hero;
      float m[9], p[3];
      typedef u32(THISCALL * f3a0)(void *, float *, float *);
      typedef void(THISCALL * f390)(void *, u32);
      u32 x = (*(f3a0 *)(vt + 0x3a0))(hero, m, p);
      (*(f390 *)(vt + 0x390))(hero, x);
      vcall<void>(vcall<void *>(*(void **)(self + 0x36d), 0x20), 0x84, p);
      ext_596940(*(void **)(*(u8 **)(self + 0x36d) + 0x852), 2, p, 1, -1);
    }
  }
  return (long double)f / frames;
}
PCREG(5e3220, openSewerGetActiveAnim);
