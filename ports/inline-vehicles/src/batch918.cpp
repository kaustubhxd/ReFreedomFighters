// batch918.cpp - vehicles thread, batch 918: ZTank::UpdateSound.
#include "ff.h"

static inline u8 *sysp() { return *(u8 **)0x70039c; }
static inline void *sndMgr() { return *(void **)(sysp() + 0x1a9f); }
// Sound of the vehicle's sound set (+0x12f) matching a wildcard name, played through PlaySound (slot 0x2e8).
static inline u32 play(u8 *s, u32 pattern) {
  u32 id = vcall<u32>(sndMgr(), 0x60, *(u32 *)(s + 0x12f), pattern);
  return vcall<u32>(s, 0x2e8, id);
}
static inline u8 *node(u32 h) { return vcall<u8 *>(*(void **)(sysp() + 0x9b), 0x60, h); }
static inline float rnd(u32 line) {
  typedef long double(THISCALL * fn)(void *, const char *, u32);
  u8 *sy = sysp();
  return (float)(*(fn *)(*(u8 **)sy + 0x1c0))(sy, (const char *)0x6a04a8, line);
}

// Speed-up sound: pitch (int)(+0x1e1 * 0.5 * path speed) on its node; then with 50% chance an "*Air*" (air brake)
// sound with a random start delay of 0.5 to 1.5 s. The arming flag +0x2706 is cleared afterwards.
static inline void speedUp(u8 *s, u32 pattern, u32 l1, u32 l2) {
  u8 *n = node(play(s, pattern));
  if (n) {
    s32 v = _mm_cvttss_si32(_mm_mul_ss(_mm_mul_ss(_mm_load_ss((float *)(s + 0x1e1)), _mm_set_ss(0.5f)),
                                       _mm_load_ss((float *)(*(u8 **)(s + 0x5c) + 0x24))));
    *(s32 *)(n + 0x60) = v - *(s32 *)(n + 0x64);
    *(s32 *)(n + 0x64) = v;
  }
  volatile float r = rnd(l1);
  if (r > 0.5f) {
    u8 *a = node(play(s, 0x69f124));
    if (a) {
      volatile float r2 = rnd(l2);
      *(float *)(a + 0x78) = (r2 * 1000.0f + 500.0f) * 0.0010000000474974513f;
    }
  }
  s[0x2706] = 0;
}

// 0x522250 ZTank::UpdateSound() (needs the sound manager, engine +0x1a9f). The rolling-belts loop "*Rolling*"
// (+0x26ea) runs while the turn speed +0x371 is positive. When the path acceleration (path +0x28) is not positive
// the speed-up sound is armed (+0x2706); an armed tank that then accelerates by more than 50 plays
// "*Engine_SpeedUp*", by more than 25 "*Engine_SpeedUp_Low*" (each possibly followed by "*Air*").
static void THISCALL tankUpdateSound(u8 *s) {
  if (!sndMgr())
    return;
  if (*(float *)(s + 0x371) > 0.0f) {
    if (!*(u32 *)(s + 0x26ea))
      *(u32 *)(s + 0x26ea) = play(s, 0x69e5f8);
  } else if (*(u32 *)(s + 0x26ea)) {
    vcall<void>(s, 0x2ec, *(u32 *)(s + 0x26ea));
    *(u32 *)(s + 0x26ea) = 0;
  }
  float acc = *(float *)(*(u8 **)(s + 0x5c) + 0x28);
  if (!(0.0f < acc))
    s[0x2706] = 1;
  if (!s[0x2706])
    return;
  if (acc > 50.0f)
    speedUp(s, 0x69f110, 0x377, 0x37c);
  else if (acc > 25.0f)
    speedUp(s, 0x69f12c, 0x389, 0x38e);
}
PCREG(522250, tankUpdateSound);
