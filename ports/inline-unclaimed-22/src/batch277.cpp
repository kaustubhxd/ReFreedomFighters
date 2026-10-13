// batch277.cpp - area 22 gameplay-core batch (docs/20-unclaimed-22.md, "Gameplay core, batch277"): ZParamAnim::FrameUpdate,
// the tick of a parameter-curve animation that drives an object's rotation and scale over time. Name from the GameCube
// name map; behaviour from the PC bytes.
#include "ff.h"

typedef float(THISCALL *curve_at_t)(u8 *, int);
typedef u8(THISCALL *curve_get_t)(u8 *, u32, float *);
typedef void(THISCALL *setf_t)(u8 *, float);

#define RM (*(u8 **)0x70039cu)

// 0x4a27d0 ZParamAnim::FrameUpdate() (thiscall, no args). The start time +0x4d is taken from the clock rm+0x40 the first
// time (when 0). Local time t = clock - (int)(delay +0x51 * -1024) - start. The curve object embedded at +0x59 gives a
// value at t (vt 0x0c, st0); a negative value, or t past (int)(length +0x55 * 1024) when the length is positive, ends the
// animation: target +0x44 vt 0x210(1) when the byte +0x48 is set (skipped for no target), else target vt 0x28(). Otherwise
// channel 0x100001 (vt 0x10) is sent to target vt 0x224 times 57.29578 (radians to degrees) and channel 0x100002 to
// target vt 0x230 as is.
void THISCALL paramAnimFrameUpdate_4a27d0(u8 *self) {
  u32 *start = (u32 *)(self + 0x4d);
  if (*start == 0 && (u8 *)start != RM + 0x40) *start = *(u32 *)(RM + 0x40);
  int t = *(int *)(RM + 0x40) - (int)(*(float *)(self + 0x51) * *(float *)0x67862cu) - (int)*start;
  u8 *curve = self + 0x59;
  float v = (*(curve_at_t *)(*(u8 **)curve + 0x0c))(curve, t);
  u8 *tgt = *(u8 **)(self + 0x44);
  float len = *(float *)(self + 0x55);
  if (0.0f > v || (len > 0.0f && t > (int)(len * *(float *)0x678620u))) {
    if (self[0x48]) {
      if (tgt) vcall<void>(tgt, 0x210, 1u);
      return;
    }
    vcall<void>(tgt, 0x28);
    return;
  }
  float f;
  if ((*(curve_get_t *)(*(u8 **)curve + 0x10))(curve, 0x100001u, &f))
    (*(setf_t *)(*(u8 **)tgt + 0x224))(tgt, f * *(float *)0x685274u);
  if ((*(curve_get_t *)(*(u8 **)curve + 0x10))(curve, 0x100002u, &f)) {
    tgt = *(u8 **)(self + 0x44);
    (*(setf_t *)(*(u8 **)tgt + 0x230))(tgt, f);
  }
}
PCREG(4a27d0, paramAnimFrameUpdate_4a27d0);
#undef RM
