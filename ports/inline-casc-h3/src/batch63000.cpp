#include "ff.h"

// 0x43e8e0: ecx=out, edx=left, stack arg=right; out = left + right; ret 4.
extern "C" void FASTCALL ext_43e8e0(u8 *out, const u8 *left, const u8 *right);
static inline u32 R32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

// 0x51cf10: thiscall() void, /GS frame. Copies three floats from this+0x276,
// lets slot 0x88 update them, clamps y to [0, 0x67cd44], adds this+0x60,
// then sends this+0x6c and the resulting vector to slot 0x7c.
static void THISCALL fn51cf10(u8 *self) {
  vcall<u32>(self, 0x36c);

  float v[3] = {
      bitsf(R32(self + 0x276)),
      bitsf(R32(self + 0x27a)),
      bitsf(R32(self + 0x27e)),
  };
  vcall<u32>(self, 0x88, (u32)v);

  // COMISS 0,y; JA leaves xmm0=0, so negative y is clamped to zero. Otherwise
  // MINSS(limit,y) selects y for NaNs, matching the SSE behavior here.
  float y = v[1];
  if (y < 0.0f) {
    v[1] = 0.0f;
  } else {
    const float limit = G(float, 0x67cd44);
    v[1] = (limit < y) ? limit : y;
  }

  float result[3];
  ext_43e8e0((u8 *)result, self + 0x60, (const u8 *)v);
  vcall<u32>(self, 0x7c, (u32)(self + 0x6c), (u32)result);
}

PCREG(51cf10, fn51cf10);
