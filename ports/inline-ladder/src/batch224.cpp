// batch224.cpp - ZIKLNKOBJ members, part 3 (inline-ladder thread, 2026-10-11).
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" u32 THISCALL ext_461760(void *self, u32 a, u32 b, u32 c);                // ZLNKOBJ::CalcShadowProjectPlane
extern "C" void FASTCALL ext_43e920(float *dst, const float *src, const float *a);   // PSVECSubtract
extern "C" void THISCALL ext_4e09b0(float *v);                                      // vneg
extern "C" void FASTCALL ext_4de040(float *m, const float *dir, const float *up);   // createmat

// 0x465890 ZIKLNKOBJ::CalcShadowProjectPlane(float*, const float*, const float*) const [high], ret 0xc: the IK object
// (+0x6c) slot 0x54(owner, a, b, c) first; when it returns false (AL), the base ZLNKOBJ version. Returns AL of the
// last call (EAX of the IK call when it succeeded).
static u32 THISCALL ikCalcShadowProjectPlane(u8 *self, u32 a, u32 b, u32 c) {
  u32 r = vcall<u32>((void *)U32(self, 0x6c), 0x54, self, a, b, c);
  if ((u8)r)
    return r;
  return ext_461760(self, a, b, c);
}
PCREG(465890, ikCalcShadowProjectPlane);

// 0x466640 ZIKLNKOBJ::ForceFacing(const float *p) [high], ret 4: o = own origin in world (slot 0x84 of (0,0,0));
// d = p - o with d.y = 0, negated; mat = createmat(d, null); own slot 0x370(mat, o) sets the matrix and position (turns
// the actor to face p on the ground plane; the negation means the model's forward axis is -z, inference).
static void THISCALL ikForceFacing(u8 *self, const float *p) {
  float o[3] = {0.0f, 0.0f, 0.0f};
  vcall<void>(self, 0x84, o);
  float d[3];
  ext_43e920(d, p, o);
  d[1] = 0.0f;
  ext_4e09b0(d);
  float mat[9];
  ext_4de040(mat, d, 0);
  vcall<void>(self, 0x370, mat, o);
}
PCREG(466640, ikForceFacing);
