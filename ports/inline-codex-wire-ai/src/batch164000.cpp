// batch601.cpp - damage thread, batch 601: the hit-reaction lockout.
#include "ff.h"

// Portable exact remainder for the function's float dividend and signed integer divisor.
// Binary subtraction avoids integer conversion overflow, handles negative time and all finite float magnitudes.
// The only dependency (_CIfmod) is replaced here and re-verified against the exe fprem thunk.
static double ci_fmod(double x, double y) {
  if (x != x || y == 0.0 || x > 3.4028234663852886e38 || x < -3.4028234663852886e38) return __builtin_nan("");
  bool neg = x < 0.0;
  double a = neg ? -x : x;
  double b = y < 0.0 ? -y : y;
  if (a >= b) {
    double step = b;
    while (step <= a * 0.5) step *= 2.0;
    while (step >= b) { if (a >= step) a -= step; step *= 0.5; }
  }
  return neg ? -a : a;
}

// 0x59dfd0 ZFFActor::CanBreakHitAnim() (GameCube reference): true when no hit anim is recorded (+0x90f == 0) or the
// current animation (this->+0x1c->+0x14, a ZBoneAnim) is not that hit anim (its id +0x48 differs). Otherwise false
// while fmod(time +0x4 - start +0x30, loop length +0xc) < 18. ZBoneAnim times are in frames at the clip's own rate
// (GC ZLNKOBJ::UpdateAnimationsAndGroundLink: t = (now - start) * speed * header fps), so 18 means 18 clip frames.
// Float 18.0 is read from 0x6aef80.
static u8 THISCALL canBreakHitAnim(u8 *self) {
  s32 id = *(s32 *)(self + 0x90f);
  if (id == 0) return 1;
  u8 *anim = *(u8 **)(*(u8 **)(self + 0x1c) + 0x14);
  if (id != *(s32 *)(anim + 0x48)) return 1;
  float dt = *(float *)(anim + 4) - *(float *)(anim + 0x30);
  float r = (float)ci_fmod((double)dt, (double)*(s32 *)(anim + 0xc));
  return (18.0f > r) ? 0 : 1;
}
PCREG(59dfd0, canBreakHitAnim);
