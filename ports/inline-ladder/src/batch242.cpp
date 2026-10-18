// batch242.cpp - ZFFHERO::OnMoveNotifyLargeObj (inline-ladder thread, 2026-10-11). GUESS flagged where noted.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))
#define F32(p, off) (*(float *)((u8 *)(p) + (off)))

extern "C" float FASTCALL ext_4e0870(const float *a, const float *b);                 // vdist (batch 48), ST0
extern "C" void FASTCALL ext_43e920(float *dst, const float *src, const float *a);    // PSVECSubtract
extern "C" long double THISCALL ext_58b9c0(void *hero, float amount, u32 ref, u32 b); // ZFFHERO::AdjustHitPoints (ST0)

// 0x5935a0 ZFFHERO::OnMoveNotifyLargeObj(ZMoveNotify *m) [GC 8007eaf0, high], thiscall, ret 4.
// Only when m+5 (a speed) is above 50.0. d = vdist(m+0x69, m+0x39) / frame time; a speed below 300 counts as 0.
// The object's damage: amount = -(speed * m+5) / 0x689060, applied through AdjustHitPoints(amount, ref(m+1), db)
// (GUESS: the third argument is the ECX value left by the database call; the port passes the database pointer,
// which is what the harness's stub leaves in ECX). Then while hit points < 5.0: the hero's knockback slot 0x5bc(
// zero, dir, speed) (threshold 2^-13 at 0x679540) with dir = (m+0x69) - (m+0x39) and speed as above (0 when below 300).
static void THISCALL heroOnMoveNotifyLargeObj(u8 *self, u8 *m) {
  if (!(F32(m, 5) > 50.0f))
    return;
  float dist = ext_4e0870((const float *)(m + 0x69), (const float *)(m + 0x39));
  u8 *eng = (u8 *)G(u32, 0x70039c);
  float val = dist / F32(eng, 0x48);
  if (300.0f > val)
    val = 0.0f;
  u8 *db = (u8 *)U32(eng, 0x9b);
  float xs = val * F32(m, 5);
  float amount = -(xs / 250.0f);   // constant 250.0 at 0x689060
  u32 obj = vcall<u32>(db, 0x4c, U32(m, 1), 1u);
  (void)ext_58b9c0(self, amount, obj, (u32)(unsigned long)db);
  if (0.0001220703125f > F32(self, 0x7ff)) {   // 2^-13 (0x679540)
    float dir[3];
    ext_43e920(dir, (const float *)(m + 0x69), (const float *)(m + 0x39));
    float zero[3] = {0.0f, 0.0f, 0.0f};
    vcall<void>(self, 0x5bc, zero, dir, val);
  }
}
PCREG(5935a0, heroOnMoveNotifyLargeObj);
