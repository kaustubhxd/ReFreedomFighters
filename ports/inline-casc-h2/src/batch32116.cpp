// batch32116.cpp - cascade h2 (Sonnet): one tier H (float / SSE) function.
#include "ff.h"

typedef u32 (STDCALL *s3_t)(u32, u32, u32);

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }

// 0x6101b0, thiscall(float a, float b, u32 c) ret 0xc: globals [0x724960] = a, [0x724954] = c | 0xff000000, [0x724964] = b; with o = unaligned [this+0x1377] (re-read before every call),
// slot 0xc8 of o (ECX = the vtable, so a stdcall with the object as first argument) is called with (o, 0x22, c | 0xff000000), (o, 0x8c, 3), (o, 0x23, 0), (o, 0x24, a bits), (o, 0x25, b bits).
static void THISCALL fn6101b0(u8 *self, float a, float b, u32 c) {
  G(float, 0x724960) = a;
  u32 col = c | 0xff000000u;
  G(u32, 0x724954) = col;
  G(float, 0x724964) = b;
  u32 o = rd32(self + 0x1377);
  (*(s3_t *)(*(u8 **)o + 0xc8))(o, 0x22, col);
  o = rd32(self + 0x1377);
  (*(s3_t *)(*(u8 **)o + 0xc8))(o, 0x8c, 3);
  o = rd32(self + 0x1377);
  (*(s3_t *)(*(u8 **)o + 0xc8))(o, 0x23, 0);
  o = rd32(self + 0x1377);
  (*(s3_t *)(*(u8 **)o + 0xc8))(o, 0x24, G(u32, 0x724960));
  o = rd32(self + 0x1377);
  (*(s3_t *)(*(u8 **)o + 0xc8))(o, 0x25, G(u32, 0x724964));
}
PCREG(6101b0, fn6101b0);
