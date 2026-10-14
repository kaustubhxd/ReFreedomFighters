// batch1203.cpp - pathfinding tree: nearest-element visitor, A* array init, path point append.
#include "pf.h"

// 0x52d3f0 ZPFOctreeElementFuncGetNearest_packed::Apply(ZPFOctree_packed*, int&, int, int*, int*, int, unsigned short)
// [map medium; , vtable slot 0]. thiscall, ret 0x1c, returns 1 when the element became the best so far.
// Functor: +4/+8/+0xc target cell (ints, local x z y), +0x10..+0x18 best cell, +0x1c best distance, +0x20 weight of
// the third (world y) axis. Distance = sqrt(dx*dx (float) + dz*dz (int, wraps)) + |dy| * weight; only walkable
// (non-zero) elements count. A strictly smaller distance wins.
static int THISCALL elemGetNearest(u8 *self, void *, int *elem, int, int *c, int *, int, u32) {
  if (*elem == 0) return 0;
  int *t = (int *)(self + 4);
  int dz = (int)((u32)c[1] - (u32)t[1]);   // wrapping, as the exe
  int dx = (int)((u32)c[0] - (u32)t[0]);
  int dy = (int)((u32)c[2] - (u32)t[2]);
  float fx = (float)dx;
  float s = (float)(int)((u32)dz * (u32)dz) + fx * fx;
  double r = crt::sqrt((double)s);
  int ady = (int)(((u32)dy ^ (u32)(dy >> 31)) - (u32)(dy >> 31));   // cdq/xor/sub: INT_MIN stays INT_MIN
  r = r + (double)((float)ady * *(float *)(self + 0x20));
  float d = (float)r;
  if (!(*(float *)(self + 0x1c) > d)) return 0;
  *(float *)(self + 0x1c) = d;
  t[3] = c[0];
  t[4] = c[1];
  t[5] = c[2];
  return 1;
}
PCREG(52d3f0, elemGetNearest);

// 0x530fd0 ZPFOctree_packed::Init(int) [map medium; ; source engine\pathfinder\zpfoctreepacked.cpp line
// 0x12b]. thiscall, ret 4. Allocates the A* array (0x15-byte SPFAStarData_packed records, count kept as u16 at +0x50,
// array at +0x98) and resets every record: f = 100000.0, words +0 / +0xe and links +0x10 / +0x12 = 0, byte +0x14 = 0.
// More than 65535 entries is reported and clamped.
static void THISCALL octreeInit(u8 *self, int n) {
  if (n > 0xffff) {
    pfReport((const char *)0x6a1438, 0x12b, (const char *)0x6a146c);
    n = 0xffff;
  }
  *(u16 *)(self + 0x50) = (u16)n;
  u64 bytes = (u64)(u16)n * 0x15;
  u8 *a = (u8 *)ext_41e290(bytes >> 32 ? 0xffffffffu : (u32)bytes);
  u32 cnt = *(u16 *)(self + 0x50);
  *(u8 **)(self + 0x98) = a;
  for (; cnt; cnt--) {
    *(u32 *)(a + 0xa) = 0x47c35000;   // 100000.0f
    *(u16 *)a = 0;
    a += 0x15;
    a[-1] = 0;
    *(u32 *)(a - 5) = 0;
    *(u16 *)(a - 7) = 0;
  }
}
PCREG(530fd0, octreeInit);

// 0x52d1c0 ZPFOctree_packed::AddPoint(CChkPntLst*, int&, float&, float*, float*, int, CHelpers*,
// SExtraLinkParentInfo_packed*) [map medium; ]. thiscall (this unused), ret 0x20.
// CChkPntLst: +0xc points (16 bytes: running length, x, y, z), +0x10 ints (zeroed), +0x14 link info pointers.
// After the first point the running length grows by |prev - p| (x87 fadd of the float distance), prev becomes p.
static void THISCALL addPoint(void *, u8 *list, int *n, float *len, float *prev, float *p, int, void *, void *extra) {
  if (*n) *len = (float)((long double)ext_4e0870(prev, p) + (long double)*len);
  prev[0] = p[0];
  prev[1] = p[1];
  prev[2] = p[2];
  float *pt = (float *)(*(u8 **)(list + 0xc) + *n * 16);
  pt[0] = *len;
  (*(int **)(list + 0x10))[*n] = 0;
  (*(void ***)(list + 0x14))[*n] = extra;
  pt = (float *)(*(u8 **)(list + 0xc) + *n * 16);
  pt[1] = p[0];
  pt[2] = p[1];
  pt[3] = p[2];
  (*n)++;
}
PCREG(52d1c0, addPoint);
