// batch1210.cpp - pathfinding tree: switching special links in a box, nearest walkable point.
#include "pf.h"

extern "C" int THISCALL ext_530e80(void *oct, u16 *out, const u16 *pos, u32 ry, u32 rxz, float weight);

// 0x52e4f0 ZPFOctree_packed::EnableSpecialLinks(unsigned short* at, short* half, bool on) [map low; GC 8019a804].
// thiscall, ret 0xc, returns the number of links switched. +0x86 u16 link count, +0x88 links (start / end cell),
// +0x8c actions (2 u16 per link). A link is switched when either end lies in the box at +- half (inclusive, cells):
// on clears bit 15 of both actions, off sets it (isActionAllowed then refuses the link).
static int THISCALL octEnableSpecialLinks(u8 *self, const u16 *at, const s16 *half, u32 on) {
  int lo0 = (int)at[0] - half[0], hi0 = half[0] + (int)at[0];
  int lo1 = (int)at[1] - half[1], hi1 = half[1] + (int)at[1];
  int lo2 = (int)at[2] - half[2], hi2 = half[2] + (int)at[2];
  int n = 0;
  if (!*(u16 *)(self + 0x86)) return 0;
  for (int i = 0; i < (int)*(u16 *)(self + 0x86); i++) {
    u16 *L = (u16 *)(*(u8 **)(self + 0x88) + i * 12);
    u16 *A = (u16 *)(*(u8 **)(self + 0x8c) + i * 4);
    if (!A) continue;
    bool outA = !(L[0] >= lo0 && L[1] >= lo1 && L[2] >= lo2 && L[0] <= hi0 && L[1] <= hi1 && L[2] <= hi2);
    bool outB = !(L[3] >= lo0 && L[4] >= lo1 && L[5] >= lo2 && L[3] <= hi0 && L[4] <= hi1 && L[5] <= hi2);
    if (outA && outB) continue;
    if ((u8)on) {
      A[0] &= 0x7fff;
      A[1] &= 0x7fff;
    } else {
      A[0] |= 0x8000;
      A[1] |= 0x8000;
    }
    n++;
  }
  return n;
}
PCREG(52e4f0, octEnableSpecialLinks);

// 0x52e670 ZPFOctree_packed::FindNearestPoint(float* p, float ry, float rxz, float weight) [map low; GC 80197670].
// thiscall, ret 0x10, bool. p to cells, nearest walkable cell below (see 0x530e80; the two radii are truncated to 16
// bits), then p becomes that cell's corner in world space, except that x (z) keeps p's value (as wx - (wx - px),
// float) when the cell is in p's own column.
static bool THISCALL octFindNearestPoint(u8 *self, float *p, float ry, float rxz, float weight) {
  float *mn = (float *)(self + 6), *mx = (float *)(self + 0x12);
  float ex = mx[0] - mn[0], ey = mx[1] - mn[1], ez = mx[2] - mn[2];
  float lx = (p[0] - mn[0]) / ex * (float)*(int *)(self + 0x3c);
  float ly = (p[1] - mn[1]) / ey * (float)*(int *)(self + 0x44);
  float lz = (p[2] - mn[2]) / ez * (float)*(int *)(self + 0x40);
  int tx = _mm_cvtt_ss2si(_mm_set_ss(lx));
  int tz = _mm_cvtt_ss2si(_mm_set_ss(lz));
  u16 c[3] = {(u16)tx, (u16)tz, (u16)_mm_cvtt_ss2si(_mm_set_ss(ly))};
  u16 out[4];
  u32 a = (u16)_mm_cvtt_ss2si(_mm_set_ss(ry)), b = (u16)_mm_cvtt_ss2si(_mm_set_ss(rxz));
  if (!ext_530e80(self, out, c, a, b, weight)) return false;
  ex = mx[0] - mn[0];
  ey = mx[1] - mn[1];
  ez = mx[2] - mn[2];
  float wx = ex * (float)(int)out[0] / (float)*(int *)(self + 0x3c) + mn[0];
  float wz = ez * (float)(int)out[1] / (float)*(int *)(self + 0x40) + mn[2];
  float wy = ey * (float)(int)out[2] / (float)*(int *)(self + 0x44) + mn[1];
  float dx = wx - p[0], dz = wz - p[2];   // PSVECSubtract (w - p), before p is written
  p[1] = wy;
  p[0] = wx;
  p[2] = wz;
  if (out[0] == (u16)tx) p[0] = wx - dx;
  if (out[1] == (u16)tz) p[2] = wz - dz;
  return true;
}
PCREG(52e670, octFindNearestPoint);
