// batch1109.cpp - collision thread, batch 1109: the quadtree segment walk (CQuadtree / CNodeQuad).
#include "ff.h"

static inline s32 sbits(float f) { return (s32)fbits(f); }
static inline float fneg(float f) { return bitsf(fbits(f) ^ 0x80000000u); }

// SRecurseInfoCompiled (from these bodies): +0 1.0f (ctor), +4 per-object callback (fastcall: object+8, info) returning
// al, +0x30 pointer to the segment start, +0x34 pointer to its end (both in quantised tree space), +0x38 direction
// (end - start), +0x44 1/dir.x, +0x4c 1/dir.z (only written when the lane is non-zero).

// 0x4e4aa0 Line2D_VS_AABB(float x0, float z0, float x1, float z1, const SRecurseInfoCompiled *info, float *t)
// [medium], fastcall (info ECX, t EDX, the four floats on the stack), ret 0x10, al. XZ slab test of the segment
// against the square [x0, x1] x [z0, z1]. Every range test compares float bits as signed integers (so a negative
// value, including -0.0, is "below"). A start inside gives t = 0 and true. Otherwise the entry parameter on each
// axis is taken (-1 when that direction lane's bits are 0), the later one wins, the other coordinate at that t must be
// inside, and the result is t <= 1 by unsigned bits (so t in [+0, 1]).
static u32 FASTCALL line2D(const u8 *info, float *t, float x0, float z0, float x1, float z1) {
  const float *s = *(const float *const *)(info + 0x30);
  float w = x1 - x0;
  float sx = s[0] - x0;
  float sz = s[2] - z0;
  float h = z1 - z0;
  if (sbits(sx) >= 0 && sbits(sx) <= sbits(w) && sbits(sz) >= 0 && sbits(sz) <= sbits(h)) {
    *(u32 *)t = 0;
    return 1;
  }
  float tx = -1.0f, tz = -1.0f;
  u32 dx = *(const u32 *)(info + 0x38);
  if (dx)
    tx = ((s32)dx < 0) ? (w - sx) * *(const float *)(info + 0x44) : fneg(*(const float *)(info + 0x44) * sx);
  u32 dz = *(const u32 *)(info + 0x40);
  if (dz)
    tz = ((s32)dz < 0) ? (h - sz) * *(const float *)(info + 0x4c) : fneg(*(const float *)(info + 0x4c) * sz);
  float r;
  if (tx >= tz) {
    float z = (*(const float *)(info + 0x40) * tx) + sz;
    if (sbits(z) < 0 || sbits(z) > sbits(h))
      return 0;
    r = tx;
  } else {
    float x = (*(const float *)(info + 0x38) * tz) + sx;
    if (sbits(x) < 0 || sbits(x) > sbits(w))
      return 0;
    r = tz;
  }
  *t = r;
  return fbits(r) <= 0x3f800000u;
}
PCREG(4e4aa0, line2D);

typedef u8(FASTCALL *LineCb)(u8 *obj, u8 *info);
extern "C" u8 FASTCALL ext_4e2800(float *t, float, float, float, float, float, float, float, float, float, float,
                                  float, float);   // LineVS_AABB(box min xyz, max xyz, start xyz, dir xyz, t)
extern "C" u32 FASTCALL ext_4e4aa0(const u8 *info, float *t, float x0, float z0, float x1, float z1);
extern "C" u8 THISCALL ext_4e4660(u8 *node, u8 *info, u8 *pool, s32 size, s32 x, s32 z);

// 0x4e4660 CNodeQuad::CheckLinesegmentB(SRecurseInfoCompiled *info, CMemPool *pool, int size, int x, int z) [high],
// thiscall, ret 0x14, al = any callback returned true.
// CNodeQuad: +0 four u16 child indices (0 = none; child address = pool[0] + index * pool[+0xc]), +0xc first object.
// Object: +0 next, +8 what the callback gets, +0xc six u16 (box min xyz, max xyz).
// Each object whose box the 3D segment hits (LineVS_AABB) is passed to the callback. Then each child quadrant
// (centre x +- size/4, z +- size/4; bit 0 of the index picks +x, bit 1 +z; half size size/2) that the segment
// crosses in XZ is walked recursively.
static u8 THISCALL checkLinesegmentB(u8 *self, u8 *info, u8 *pool, s32 size, s32 x, s32 z) {
  u8 flag = 0;
  for (u8 *o = *(u8 **)(self + 0xc); o; o = *(u8 **)o) {
    float t = -1.0f;
    const float *s = *(const float *const *)(info + 0x30);
    const float *d = (const float *)(info + 0x38);
    const u16 *b = (const u16 *)(o + 0xc);
    if (ext_4e2800(&t, (float)b[0], (float)b[1], (float)b[2], (float)b[3], (float)b[4], (float)b[5], s[0], s[1], s[2],
                   d[0], d[1], d[2]))
      flag |= (*(LineCb *)(info + 4))(o + 8, info);
  }
  s32 q = size >> 2;
  for (u32 k = 0; k < 4; k++) {
    u16 child = ((const u16 *)self)[k];
    if (!child)
      continue;
    s32 half = size >> 1;
    s32 cx = ((k & 1) ? q : -q) + x;
    s32 cz = ((k & 2) ? q : -q) + z;
    float t;
    if (ext_4e4aa0(info, &t, (float)(cx - half), (float)(cz - half), (float)(cx + half), (float)(cz + half)) & 0xff)
      flag |= ext_4e4660(*(u8 **)pool + child * *(u32 *)(pool + 0xc), info, pool, half, cx, cz);
  }
  return flag;
}
PCREG(4e4660, checkLinesegmentB);

extern "C" void FASTCALL ext_43e920(float *dst, const float *a, const float *b);   // PSVECSubtract

// 0x4e4520 CQuadtree::CheckLinesegment(SRecurseInfoCompiled *info, float *from, float *to) [high], thiscall,
// ret 0xc, al. CQuadtree: +0 root CNodeQuad, +4 node pool (base at +4, stride at +0x10), +0x1d scale, +0x21 origin.
// Quantises both ends ((p - origin) * scale + 32768), points info+0x30 / +0x34 at them (they live in this
// function's frame), sets the direction and the reciprocals of its non-zero x and z lanes, and walks the tree from
// the root with size 0x10000 centred on (0x8000, 0x8000).
static u8 THISCALL checkLinesegment(u8 *self, u8 *info, const float *from, const float *to) {
  float sc = *(const float *)(self + 0x1d);
  const float *org = (const float *)(self + 0x21);
  float a[3], b[3];
  a[0] = ((from[0] - org[0]) * sc) + 32768.0f;
  a[1] = ((from[1] - org[1]) * sc) + 32768.0f;
  a[2] = ((from[2] - org[2]) * sc) + 32768.0f;
  b[0] = ((to[0] - org[0]) * sc) + 32768.0f;
  b[1] = ((to[1] - org[1]) * sc) + 32768.0f;
  b[2] = ((to[2] - org[2]) * sc) + 32768.0f;
  *(float **)(info + 0x30) = a;
  *(float **)(info + 0x34) = b;
  ext_43e920((float *)(info + 0x38), b, a);
  float dx = *(const float *)(info + 0x38);
  if (dx != 0.0f)
    *(float *)(info + 0x44) = 1.0f / dx;
  float dz = *(const float *)(info + 0x40);
  if (dz != 0.0f)
    *(float *)(info + 0x4c) = 1.0f / dz;
  return ext_4e4660(*(u8 **)self, info, self + 4, 0x10000, 0x8000, 0x8000);
}
PCREG(4e4520, checkLinesegment);
