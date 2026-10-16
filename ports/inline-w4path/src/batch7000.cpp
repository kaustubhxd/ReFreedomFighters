// batch7000.cpp - W4 wiring (docs/41 "Vehicle path speed"): 0x524180 CMoveAlongPath::UpdateDistToDest as plain C++ (the strict lift
// inline-gap-401000 batch831 is x86 assembly, which does not compile to wasm). Same function, same hooks; checked with the same spec.
// Thiscall, no arguments. d = (f[0x42] - f[4]) * f[0x53] * f[0x20] is stored at +0x30. d <= K (0x679540 = 2^-13, ordered):
// byte +0x34 = 1, and a next path in +0x4f is entered through ChangePath 0x523040(this, path, f[0x3d]) first; else byte +0x34 = 0.
// Then: d >= K2 (0x679544) and dword +0x39 == 2 and |f[0x24]| <= 0.0078125 (0x685278): the log line at 0x6a0828 (through the debug
// object's slot 0x20 then its slot 0x2c, called as the exe does: obj and format popped by the callee, the two doubles by the caller)
// and slot 8 of this with (f[0x57], f[0x5b]), +0x39 = 1, byte +0x46 = 0.
#include "ff.h"

extern "C" void THISCALL ext_523040(u8 *self, u32 path, float f);

typedef void (*logf_t)(u8 *, u32, ...);   // cdecl: the caller removes all four arguments (the exe's add esp,0x10 leaves obj and format as slot 8's outgoing words)

static void THISCALL fn524180(u8 *self) {
  float k = G(float, 0x679540);
  float d = *(float *)(self + 0x42);
  d = d - *(float *)(self + 4);
  d = d * *(float *)(self + 0x53);
  d = d * *(float *)(self + 0x20);
  *(float *)(self + 0x30) = d;
  if (k < d) {
    self[0x34] = 0;
  } else {
    u32 nxt = *(u32 *)(self + 0x4f);
    if (nxt) ext_523040(self, nxt, *(float *)(self + 0x3d));
    self[0x34] = 1;
  }
  if (*(float *)(self + 0x30) < G(float, 0x679544)) return;
  if (*(u32 *)(self + 0x39) != 2) return;
  double sp = (double)*(float *)(self + 0x24);
  sp = __builtin_bit_cast(double, __builtin_bit_cast(u64, sp) & 0x7fffffffffffffffull);
  if (G(double, 0x685278) < sp) return;
  u8 *o = vcall<u8 *>(G(u8 *, 0x700390), 0x20, 0x6a0778u, 0x1f0u);
  double d1 = (double)*(float *)(self + 0x30), d2 = (double)*(float *)(self + 0x24);
  (*(logf_t *)(*(u8 **)o + 0x2c))(o, 0x6a0828u, d1, d2);
  vcall<void>(self, 8, *(float *)(self + 0x57), *(float *)(self + 0x5b));
  *(u32 *)(self + 0x39) = 1;
  self[0x46] = 0;
}
PCREG(524180, fn524180);
