// batch1201.cpp - pathfinding tree: world <-> local octree coordinates, CContext time slice.
#include "pf.h"

// ZPFOctree_packed fields used here (PC, /Zp1): +6 m_vMin (3 floats), +0x12 m_vMax (3 floats), +0x3c / +0x40 / +0x44
// the number of cells along x / z / y (ints). Local coordinates are (x, z, y) shorts: element 1 is the WORLD z axis
// scaled by +0x40 and element 2 the world y axis scaled by +0x44.

// 0x530b60 ZPFOctree_packed::GetLocalCoords(unsigned short*, float*) [map low; GameCube reference]. thiscall, ret 8.
// out = trunc((p - min) / (max - min) * cells), stored as 16 bits (cvttss2si: out of range gives 0x80000000 -> 0).
static void THISCALL getLocalCoords(u8 *self, u16 *out, float *p) {
  float *mn = (float *)(self + 6), *mx = (float *)(self + 0x12);
  float ex = mx[0] - mn[0], ey = mx[1] - mn[1], ez = mx[2] - mn[2];   // PSVECSubtract (0x43e920), x87 -> float
  float x = (p[0] - mn[0]) / ex * (float)*(int *)(self + 0x3c);
  float y = (p[1] - mn[1]) / ey * (float)*(int *)(self + 0x44);
  float z = (p[2] - mn[2]) / ez * (float)*(int *)(self + 0x40);
  out[0] = (u16)_mm_cvtt_ss2si(_mm_set_ss(x));
  out[1] = (u16)_mm_cvtt_ss2si(_mm_set_ss(z));
  out[2] = (u16)_mm_cvtt_ss2si(_mm_set_ss(y));
}
PCREG(530b60, getLocalCoords);

// 0x530db0 ZPFOctree_packed::GetLocalVector(short*, float*) [map medium; GameCube reference]. thiscall, ret 8.
// A world vector (a link offset) in cells: ceil(v / extent * cells) per axis, through the CRT ceil and _ftol2.
static void THISCALL getLocalVector(u8 *self, s16 *out, float *v) {
  float *mn = (float *)(self + 6), *mx = (float *)(self + 0x12);
  float ex = mx[0] - mn[0], ey = mx[1] - mn[1], ez = mx[2] - mn[2];
  out[0] = (s16)ftol2(ext_634da6((double)(v[0] / ex * (float)*(int *)(self + 0x3c))));
  out[2] = (s16)ftol2(ext_634da6((double)(v[1] / ey * (float)*(int *)(self + 0x44))));
  out[1] = (s16)ftol2(ext_634da6((double)(v[2] / ez * (float)*(int *)(self + 0x40))));
}
PCREG(530db0, getLocalVector);

// 0x52b080 CContext::isTimeUp() [map high; GameCube reference; source engine\pathfinder\timeslicing.h line 0x3d].
// thiscall, no args. +0x44 = time-slice record {u32 start, u32 budget, ..., u8 enabled at +0x10}. When enabled, it
// reads the engine clock (ZSysInterface vtable +0x1c8 (file, line)) and restarts the slice once more than `budget`
// has passed (unsigned). Always sets the flag at +0x48. The PC build returns nothing useful in EAX.
static void THISCALL contextIsTimeUp(u8 *self) {
  u32 *ts = *(u32 **)(self + 0x44);
  if (ts && ((u8 *)ts)[0x10]) {
    u32 now = vcall<u32>(g_pSysInterface, 0x1c8, (const char *)0x6a0ea8, 0x3d);
    ts = *(u32 **)(self + 0x44);
    if (now - ts[0] > ts[1]) ts[0] = now;
  }
  self[0x48] = 1;
}
PCREG(52b080, contextIsTimeUp);
