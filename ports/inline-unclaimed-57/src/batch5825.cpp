// batch5825.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 125: 0x5c3140 (GUESS name unnamed5c3140), thiscall, no args, plain ret.
// k = G(0x678620); lim = engine+0x40; t1 = trunc((this+0x115 + this+0xfa) * k); if lim < t1: return.
// if this+0x125 != 0: t2 = trunc(this+0x11d * k); if lim < t2: v = engine+0x48 + this+0x121; this+0x121 = v; r = 0x4de000(0.05f, 0.25f) (hooked);
//   if this+0x121 <= r: return; f = (this+0x114 == 0); this+0x121 = 0; this+0x114 = f; 0x5c3560(this, f, 0) (hooked); return.
//   else (lim >= t2): this+0x114 = 0; 0x5c3560(this, 0, 1); this+0x125 = 0; this+0x119 = float(engine+0x40 - trunc(this+0x102 * G(0x67862c))) * G(0x6785e4); return.
// else (this+0x125 == 0): t3 = trunc(this+0x119 * k); if lim <= t3: return; f = (this+0x114 == 0); this+0x114 = f; 0x5c3560(this, f, 1) (hooked);
//   if this+0x114 == 0: this+0x125 = 1; this+0x11d = float(engine+0x40 - trunc(this+0x106 * G(0x67862c))) * G(0x6785e4);
//   else: this+0x119 = float(engine+0x40 - trunc(this+0xfe * G(0x67862c))) * G(0x6785e4).
#include "ff.h"

#define VT(o) (*(void ***)(o))

extern "C" float STDCALL ext_4de000(float a, float b);            // stdcall ret 8, float result in st0, original code (hooked in the spec)
extern "C" void THISCALL ext_5c3560(u8 *self, u32 a, u32 b);      // thiscall ret 8, original code (hooked in the spec)

static s32 cvtTrunc(float x) { return _mm_cvttss_si32(_mm_set_ss(x)); }

// 0x5c3140, thiscall, no args (GUESS name)
static void THISCALL unnamed5c3140(u8 *self) {
  float k = G(float, 0x678620);
  s32 lim = (s32)*(u32 *)(G(u8 *, 0x70039c) + 0x40);
  if (lim < cvtTrunc((*(float *)(self + 0x115) + *(float *)(self + 0xfa)) * k)) return;
  if (*(u8 *)(self + 0x125) != 0) {
    if (lim < cvtTrunc(*(float *)(self + 0x11d) * k)) {
      u8 *eng = G(u8 *, 0x70039c);
      float v = *(float *)(eng + 0x48) + *(float *)(self + 0x121);
      *(float *)(self + 0x121) = v;
      float r = ext_4de000(0.05f, 0.25f);
      if (*(float *)(self + 0x121) <= r) return;
      u8 f = (u8)(*(u8 *)(self + 0x114) == 0);
      *(u32 *)(self + 0x121) = 0;
      *(u8 *)(self + 0x114) = f;
      ext_5c3560(self, f, 0);
      return;
    }
    *(u8 *)(self + 0x114) = 0;
    ext_5c3560(self, 0, 1);
    s32 t = cvtTrunc(*(float *)(self + 0x102) * G(float, 0x67862c));
    *(u8 *)(self + 0x125) = 0;
    *(float *)(self + 0x119) = (float)((s32)*(u32 *)(G(u8 *, 0x70039c) + 0x40) - t) * G(float, 0x6785e4);
    return;
  }
  if (lim <= cvtTrunc(*(float *)(self + 0x119) * k)) return;
  u8 f = (u8)(*(u8 *)(self + 0x114) == 0);
  *(u8 *)(self + 0x114) = f;
  ext_5c3560(self, f, 1);
  if (*(u8 *)(self + 0x114) == 0) {
    s32 t = cvtTrunc(*(float *)(self + 0x106) * G(float, 0x67862c));
    *(u8 *)(self + 0x125) = 1;
    *(float *)(self + 0x11d) = (float)((s32)*(u32 *)(G(u8 *, 0x70039c) + 0x40) - t) * G(float, 0x6785e4);
  } else {
    s32 t = cvtTrunc(*(float *)(self + 0xfe) * G(float, 0x67862c));
    *(float *)(self + 0x119) = (float)((s32)*(u32 *)(G(u8 *, 0x70039c) + 0x40) - t) * G(float, 0x6785e4);
  }
}
PCREG(5c3140, unnamed5c3140);
