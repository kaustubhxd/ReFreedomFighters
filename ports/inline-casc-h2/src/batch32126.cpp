// batch32126.cpp - cascade h2 (Sonnet): two tier H functions.
#include "ff.h"

typedef u32 (THISCALL *fn_p_t)(u32);

static inline u8 *engTable() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

// 0x512be0, thiscall(out) ret 4: out[0..2] = 0; slot 0x84 of [this+4] with out; engine slot 0x1c4 with (0x69e4bc, 0x545) gives r1 (x87 float): out[0] += (float)(r1 * K(0x67cd40));
// out[2] += (float)(r2 * K) with r2 from the same slot with (0x69e4bc, 0x546); [this+0x24] = out[0], [this+0x28] = out[1], [this+0x2c] = out[2]; [this+0x14] = (float)[[0x70039c]+0x40] * K2(0x6785e4).
static void THISCALL fn512be0(u8 *self, float *out) {
  out[0] = 0; out[1] = 0; out[2] = 0;
  vcall<void>(*(void **)(self + 4), 0x84, (u32)out);
  void *eng = G(void *, 0x70039c);
  float r1 = vcall<float>(eng, 0x1c4, 0x69e4bcu, 0x545u);
  float x = (float)((double)r1 * (double)G(float, 0x67cd40));
  out[0] = out[0] + x;
  eng = G(void *, 0x70039c);
  float r2 = vcall<float>(eng, 0x1c4, 0x69e4bcu, 0x546u);
  float y = (float)((double)r2 * (double)G(float, 0x67cd40));
  out[2] = out[2] + y;
  *(float *)(self + 0x24) = out[0];
  *(float *)(self + 0x28) = out[1];
  *(float *)(self + 0x2c) = out[2];
  *(float *)(self + 0x14) = (float)*(s32 *)(G(u8 *, 0x70039c) + 0x40) * G(float, 0x6785e4);
}
PCREG(512be0, fn512be0);

// 0x46ab30, thiscall(p, float f) ret 8: slot 0x110 of this with (0x10, 0); k = 0 when p == 0 or slot 0x20 of the object g = [0x70038c] with p is non-zero; otherwise,
// with fn = [g+8]: fn != 0 and [g+0xc] <= p < [g+0x10] -> k = fn(p) (thiscall); else k = [p-4] after slot 0xac of g with p when [p-4] == 0; slot 0x98 of [this+0x78] with (k, f, 0).
static void THISCALL fn46ab30(u8 *self, u32 p, float f) {
  vcall<void>(self, 0x110, 0x10u, 0u);
  u32 k;
  if (!p) {
    k = 0;
  } else {
    u8 *g = G(u8 *, 0x70038c);
    if (vcall<u32>(g, 0x20, p)) {
      k = 0;
    } else {
      g = G(u8 *, 0x70038c);
      u32 fn = *(u32 *)(g + 8);
      if (fn && !(*(u32 *)(g + 0xc) > p) && p < *(u32 *)(g + 0x10)) {
        k = (*(fn_p_t *)&fn)(p);
      } else {
        if (*(u32 *)(p - 4) == 0) vcall<void>(g, 0xac, p);
        k = *(u32 *)(p - 4);
      }
    }
  }
  vcall<void>(*(void **)(self + 0x78), 0x98, k, f, 0u);
}
PCREG(46ab30, fn46ab30);
