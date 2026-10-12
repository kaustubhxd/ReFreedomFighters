// batch612.cpp - unclaimed-06 claim 12 (docs/20-unclaimed-06.md): CMoveAlongPath::SetSplineVal(float). Thiscall, one float
// argument (passed as bits), ret 4. Names are from the GC name map (medium: the class is named, the function name is a guess
// from the vtable slot). The callee 0x460aa0 is stubbed (GUESS), and the virtual slot 0x84 of the object at this+0x4b is a stand-in.
#include "ff.h"

extern "C" void THISCALL ext_460aa0(u8 *obj, u8 *p, u32 f);   // stubbed in the harness (GUESS), ecx = object + 0x1c

// 0x523e10, CMoveAlongPath::SetSplineVal(float) (medium): m = 0.0 when 0 > a, else min(1.0, a); stores m at this+4. Then, with obj = [this+0x4b]: if obj is set, calls ext_460aa0(obj+0x1c, this+8,
// the stored float bits (0.0 when a < 0, the clamped value otherwise)) and the object's virtual slot 0x84 with this+8;
// if obj is null, clears the dwords at this+8, +0xc, +0x10.
static void THISCALL moveAlongPathSetSplineVal(u8 *self, u32 argBits) {
  float a;
  *(u32 *)&a = argBits;
  // xmm0 starts at 0.0; the minss runs only when !(0.0 > a). Both paths then store xmm0 at this+4 (the original's
  // movss [edi+4], xmm0 sits after the jump target), so the argument itself is never stored.
  float m = 0.0f;
  if (!(0.0f > a)) {
    float c = 1.0f;
    m = (c < a) ? c : a;   // minss: dst (1.0) vs src (a); returns a unless 1.0 < a
  }
  *(float *)(self + 4) = m;
  float pushed = m;
  u8 *obj = *(u8 **)(self + 0x4b);
  if (obj) {
    u32 pbits;
    *(float *)&pbits = pushed;
    ext_460aa0(obj + 0x1c, self + 8, pbits);
    ((void (THISCALL *)(void *, u32))(*(void **)(*(u8 **)obj + 0x84)))(obj, (u32)(self + 8));
  } else {
    *(u32 *)(self + 8) = 0;
    *(u32 *)(self + 0xc) = 0;
    *(u32 *)(self + 0x10) = 0;
  }
}
PCREG(523e10, moveAlongPathSetSplineVal);
