// batch601.cpp - damage thread, batch 601: the hit-reaction lockout.
#include "ff.h"

extern "C" void ext_634dc4(void);  // _CIfmod (CRT): fmod(ST1, ST0), pops one, result in ST0

// x87 fmod through the CRT helper, exactly as the original calls it (both operands as doubles).
static inline double ci_fmod(double x, double y) {
  double r;
  asm volatile("fldl %1\n\tfldl %2\n\tcall ext_634dc4\n\tfstpl %0" : "=m"(r) : "m"(x), "m"(y) : "eax", "ecx", "edx", "st", "st(1)", "memory");
  return r;
}

// 0x59dfd0 ZFFActor::CanBreakHitAnim() (GC 800713c0): true when no hit anim is recorded (+0x90f == 0) or the
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
