// batch8822.cpp - wire-hit-parts (2026-10-15): the line test of ZCollisionBox::CalcLineCollision (0x4e8c80, no name in the map), under
// ZIKLNKOBJ::CanPlayAnimSegment 0x465a80 -> CalcLineCollision 0x4e8c00.
#include "ff.h"

extern "C" u8 FASTCALL ext_4e2560(const float *start, const float *dir, const float *v0, const float *v1, const float *v2, float *t,
                                   u32 flag);                                                  // IntersectTriangleAndLine (batch8821)
extern "C" void FASTCALL ext_443ef0(float *out, const float *a, const float *b, float s);    // vaddscalar: out = a + b * s

// 0x4e8c80 (thiscall(out, start, dir, flag), ret 0x10, returns al). The box holds strips: +8 count, +0xc the first strip; a strip is
// {+0 vertex count n, +8, +0xc, +0x10 (surface words), +0x18 n vertices of 12 bytes}, the next strip right after the last vertex.
// *out = 1.0; best = float [0x678858]. Every triangle k of every strip (vertices k, k+1, k+2; odd k with the winding reversed:
// k+2, k+1, k) goes through IntersectTriangleAndLine(start, dir, ..., &t, flag); a hit with t >= 0 and best > t becomes the
// nearest (strip, vertex k, parity of k). None -> 0. Else out: +0x40 / +0x44 = strip +8 / +0xc, +4 = start + dir * best
// (0x443ef0), +0 = best, +0x10 = strip +0x10, +0x38 = -1, +0x20 = vertex k+1, and +0x14 / +0x2c = vertices k / k+2 (even k)
// or k+2 / k (odd k). Returns 1.
static u8 THISCALL lineStrips(u8 *self, u8 *out, const float *start, const float *dir, u32 flag) {
  float S[3] = {start[0], start[1], start[2]};
  float D[3] = {dir[0], dir[1], dir[2]};
  *(u32 *)out = 0x3f800000u;
  float best = G(float, 0x678858);
  u32 parity = 0;
  u8 *hitV = 0, *hitS = 0;
  u8 *p = *(u8 **)(self + 0xc);
  if (*(u32 *)(self + 8) == 0) return 0;
  for (u32 s = 0; s != *(u32 *)(self + 8); s++) {
    u8 *v = p + 0x18;
    u32 n = *(u32 *)p - 2;
    for (u32 k = 0; k != n; k++, v += 0xc) {
      float t;
      u8 hit;
      if (k & 1)
        hit = ext_4e2560(S, D, (float *)(v + 0x18), (float *)(v + 0xc), (float *)v, &t, flag);
      else
        hit = ext_4e2560(S, D, (float *)v, (float *)(v + 0xc), (float *)(v + 0x18), &t, flag);
      if (hit && t >= 0.0f && best > t) {
        hitS = p;
        best = t;
        hitV = v;
        parity = k;
      }
    }
    p = v + 0x18;
  }
  if (!hitV) return 0;
  *(u32 *)(out + 0x44) = *(u32 *)(hitS + 0xc);
  *(u32 *)(out + 0x40) = *(u32 *)(hitS + 8);
  ext_443ef0((float *)(out + 4), start, dir, best);
  *(float *)out = best;
  *(u32 *)(out + 0x10) = *(u32 *)(hitS + 0x10);
  *(u32 *)(out + 0x38) = 0xffffffffu;
  for (int i = 0; i < 3; i++) *(u32 *)(out + 0x20 + 4 * i) = *(u32 *)(hitV + 0xc + 4 * i);
  u8 *a = hitV, *b = hitV + 0x18;
  if (parity & 1) { u8 *x = a; a = b; b = x; }
  for (int i = 0; i < 3; i++) {
    *(u32 *)(out + 0x14 + 4 * i) = *(u32 *)(a + 4 * i);
    *(u32 *)(out + 0x2c + 4 * i) = *(u32 *)(b + 4 * i);
  }
  return 1;
}
PCREG(4e8c80, lineStrips);
