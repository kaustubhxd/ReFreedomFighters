// batch703.cpp - soldier AI, batch 703 (2026-10-11): CCheckVisible per-seer settings (script/event handlers).
// Each handler gets an event block {seer ref, value...}. Unknown seer: logs "Warning: OnSetVisX() %s is not a registered
// seer" with the geom's name and returns 0; otherwise stores the value and returns 1.
// These are what the PPO natives SetVisRange / SetVisFov / SetVisOffset / SetVisLightMultiplier reach (ZActorIf
// wrappers 0x5084a0 etc., inferred from the names).
#include "ff.h"

struct MYSTR_buf { u8 b[0x80]; };
extern "C" const char *THISCALL ext_4cc1d0(void *);
extern "C" void THISCALL ext_4cbec0(void *);

static inline s32 cv_find_seer(u8 *self, u32 ref) {
  for (s32 i = 0; i < 200; i++)
    if (*(u32 *)(self + 0x694 + i * 0x1b8) == ref)
      return i;
  return -1;
}

static void cv_warn_seer(u32 ref, u32 line, u32 fmt) {
  void *db = *(void **)(*(u8 **)0x70039c + 0x9b);
  void *g = vcall<void *>(db, 0x58, ref);
  void *log = vcall<void *>(*(void **)0x700390, 0x20, (const char *)0x690610, line);
  MYSTR_buf name;
  void *ms = vcall<void *>(g, 0x1d8, &name, 1);
  const char *s = ext_4cc1d0(ms);
  typedef void(__attribute__((cdecl)) * printf_t)(void *, const char *, const char *);
  (*(printf_t *)(*(u8 **)log + 0x2c))(log, (const char *)fmt, s);
  ext_4cbec0(&name);
}

// 0x4ab760 CCheckVisible::OnSetVisRange(void*) [high]: range clamped to [10, 10000] (NaN passes through) at seer +4.
static u32 THISCALL cv_OnSetVisRange(u8 *self, u32 *ev) {
  s32 i = cv_find_seer(self, ev[0]);
  if (i < 0) {
    cv_warn_seer(ev[0], 0xf4, 0x690774);
    return 0;
  }
  float v = *(float *)(ev + 1);
  float r;
  if (10.0f > v)               // 0x680a70
    r = 10.0f;
  else
    r = (10000.0f < v) ? 10000.0f : v;   // 0x67ff1c, minss
  *(float *)(self + 0x698 + i * 0x1b8) = r;
  return 1;
}
PCREG(4ab760, cv_OnSetVisRange);

// 0x4ab430 CCheckVisible::OnSetVisFov(void*) [high]: full field of view in degrees, clamped to [0, 360]; stores
// cos(fov/2) (as float, via the CRT cos at 0x634d70) at seer +8.
extern "C" double VECTORCALL ext_634d70(double);
static u32 THISCALL cv_OnSetVisFov(u8 *self, u32 *ev) {
  s32 i = cv_find_seer(self, ev[0]);
  if (i < 0) {
    cv_warn_seer(ev[0], 0x107, 0x6907ac);
    return 0;
  }
  float v = *(float *)(ev + 1);
  float x;
  if (0.0f > v)
    x = 0.0f;
  else
    x = (360.0f < v) ? 360.0f : v;     // 0x690990
  x = x * 0.5f;                        // 0x67a6ac
  x = x * 3.14159274f;                 // 0x67da18
  x = x / 180.0f;                      // 0x67da28
  *(float *)(self + 0x69c + i * 0x1b8) = (float)ext_634d70((double)x);
  return 1;
}
PCREG(4ab430, cv_OnSetVisFov);

// 0x4ab650 CCheckVisible::OnSetVisOffset(void*) [high]: eye offset (3 floats) at seer +0x10..+0x18.
static u32 THISCALL cv_OnSetVisOffset(u8 *self, u32 *ev) {
  s32 i = cv_find_seer(self, ev[0]);
  if (i < 0) {
    cv_warn_seer(ev[0], 0x114, 0x6907e0);
    return 0;
  }
  u8 *s = self + 0x694 + i * 0x1b8;
  *(u32 *)(s + 0x10) = ev[1];
  *(u32 *)(s + 0x14) = ev[2];
  *(u32 *)(s + 0x18) = ev[3];
  return 1;
}
PCREG(4ab650, cv_OnSetVisOffset);

// 0x4ab560 CCheckVisible::OnSetVisLightMultiplier(void*) [high]: stored unclamped at seer +0xc.
static u32 THISCALL cv_OnSetVisLightMultiplier(u8 *self, u32 *ev) {
  s32 i = cv_find_seer(self, ev[0]);
  if (i < 0) {
    cv_warn_seer(ev[0], 0x121, 0x690818);
    return 0;
  }
  *(u32 *)(self + 0x6a0 + i * 0x1b8) = ev[1];
  return 1;
}
PCREG(4ab560, cv_OnSetVisLightMultiplier);
