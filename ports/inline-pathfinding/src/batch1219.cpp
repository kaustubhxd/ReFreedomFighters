// batch1219.cpp - pathfinding tree: ZPathfinder3::ProcessAdditionalDoors (gate and door quads from level geoms).
#include "pf.h"

extern "C" void THISCALL ext_4db7c0(void *geom, float *size);     // ZBaseGeom::GetSize (half extents)
extern "C" void THISCALL ext_4daf90(void *geom, float *cen);      // ZBaseGeom::GetCen
extern "C" int FASTCALL ext_4cc850(const char *s, const char *pattern);   // striwcmp (wildcards), 0 = match

#define COLMGR (*(u8 **)(*(u8 **)((u8 *)g_pSysInterface + 0x9b) + 0xadc))

static inline u32 mulOverflow(u32 n, u32 size) {
  u64 b = (u64)n * size;
  return b >> 32 ? 0xffffffffu : (u32)b;
}

// 0x52b9d0 ZPathfinder3::ProcessAdditionalDoors() [map high; GameCube reference]. thiscall.
// Gates: every collision item (manager at sysi+0x9b +0xadc: first item +8, next = vtable +0x50) whose +0x54 object is
// a 0x200015-class object with "dynamics enabled" (+0x5b) adds one gate: the object's four corners (vtable +0x244, 12
// floats) transformed to world (vtable +0x84 on each). The gate count at +0x36 is only ever increased.
// Doors: one quad per geom in the door REFTAB (+0x2d; deleted afterwards): door +0x30 = its 1-based id, the
// door-blocker (8 bytes, vtable 0x6a0c68) +4 = the geom; the quad lies across the geom's thinnest axis through its
// centre (local), or for "*DDoorGarage_0*" geoms on the -z face; then transformed to world.
static void THISCALL processAdditionalDoors(u8 *self) {
  for (u8 *it = *(u8 **)(COLMGR + 8); it;) {
    u8 *obj = *(u8 **)(it + 0x54);
    if (obj && *(u32 *)(*(u8 **)(obj + 0xc) + 0x23) == 0x200015 && obj[0x5b]) (*(int *)(self + 0x36))++;
    vcall<void>(COLMGR, 0x50, &it);
  }
  *(u8 **)(self + 0x3a) = (u8 *)ext_41e290(mulOverflow(*(u32 *)(self + 0x36), 0x34));
  int off = 0;
  for (u8 *it = *(u8 **)(COLMGR + 8); it;) {
    u8 *obj = *(u8 **)(it + 0x54);
    if (obj && *(u32 *)(*(u8 **)(obj + 0xc) + 0x23) == 0x200015 && obj[0x5b]) {
      *(u32 *)(*(u8 **)(self + 0x3a) + off + 0x30) = 0;
      u32 *src = vcall<u32 *>(obj, 0x244);
      u32 *dst = (u32 *)(*(u8 **)(self + 0x3a) + off);
      for (int k = 0; k < 12; k++) dst[k] = src[k];
      for (int k = 0; k < 4; k++) vcall<void>(obj, 0x84, *(u8 **)(self + 0x3a) + off + 0xc * k);
      off += 0x34;
    }
    vcall<void>(COLMGR, 0x50, &it);
  }
  u32 n = vcall<u32>(*(void **)(self + 0x2d), 0x14);
  *(u32 *)(self + 0x3e) = n;
  *(u8 **)(self + 0x42) = (u8 *)ext_41e290(mulOverflow(n, 0x34));
  u32 *blk = (u32 *)ext_41e290(mulOverflow(n, 8));
  if (blk) {
    for (u32 k = 0, *b = blk; k < n; k++, b += 2) {
      b[0] = 0x6a0c68;
      b[1] = 0;
    }
  }
  *(u32 **)(self + 0x7d) = blk;
  for (int k = 0; k < *(int *)(self + 0x3e); k++) *(u32 *)(*(u8 **)(self + 0x42) + k * 0x34 + 0x30) = 0;
  if (*(void **)(self + 0x2d)) {
    u32 itr[3];
    vcall<void>(*(void **)(self + 0x2d), 0x4c, itr);
    u8 *geom = vcall<u8 *>(*(void **)(self + 0x2d), 0x5c, itr);
    int id = 1;
    int doff = 0;
    while (itr[0]) {
      float s[3], c[3];
      ext_4db7c0(*(void **)(geom + 8), s);
      float m = 1e7f;   // 0x6a13bc
      if (m > s[0]) m = s[0];
      int axis = 0;
      if (m > s[1]) {
        m = s[1];
        axis = 1;
      }
      if (m > s[2]) axis = 2;
      ext_4daf90(*(void **)(geom + 8), c);
      float *d = (float *)(*(u8 **)(self + 0x42) + doff);
      *(int *)(d + 12) = id;
      *(u8 **)(vcall<u8 *>(self, 0x228, id) + 4) = geom;
      const char *name = *(const char **)(geom + 4) ? *(const char **)(geom + 4) : (const char *)0x67c8e8;
      if (!ext_4cc850(name, (const char *)0x6a11ac)) {
        d[0] = s[0] + c[0]; d[1] = s[1] + c[1]; d[2] = c[2] - s[2];
        d[3] = c[0] - s[0]; d[4] = s[1] + c[1]; d[5] = c[2] - s[2];
        d[6] = c[0] - s[0]; d[7] = c[1] - s[1]; d[8] = c[2] - s[2];
        d[9] = s[0] + c[0]; d[10] = c[1] - s[1]; d[11] = c[2] - s[2];
      } else if (axis == 2) {
        d[0] = s[0] + c[0]; d[1] = s[1] + c[1]; d[2] = c[2];
        d[3] = c[0] - s[0]; d[4] = s[1] + c[1]; d[5] = c[2];
        d[6] = c[0] - s[0]; d[7] = c[1] - s[1]; d[8] = c[2];
        d[9] = s[0] + c[0]; d[10] = c[1] - s[1]; d[11] = c[2];
      } else if (axis == 1) {
        d[0] = s[0] + c[0]; d[1] = c[1]; d[2] = s[2] + c[2];
        d[3] = c[0] - s[0]; d[4] = c[1]; d[5] = s[2] + c[2];
        d[6] = c[0] - s[0]; d[7] = c[1]; d[8] = c[2] - s[2];
        d[9] = s[0] + c[0]; d[10] = c[1]; d[11] = c[2] - s[2];
      } else {
        d[0] = c[0]; d[1] = s[1] + c[1]; d[2] = s[2] + c[2];
        d[3] = c[0]; d[4] = c[1] - s[1]; d[5] = s[2] + c[2];
        d[6] = c[0]; d[7] = c[1] - s[1]; d[8] = c[2] - s[2];
        d[9] = c[0]; d[10] = s[1] + c[1]; d[11] = c[2] - s[2];
      }
      for (int k = 0; k < 4; k++) vcall<void>(geom, 0x84, d + 3 * k);
      doff += 0x34;
      id++;
      geom = vcall<u8 *>(*(void **)(self + 0x2d), 0x5c, itr);
    }
  }
  if (*(void **)(self + 0x2d)) vcall<void>(*(void **)(self + 0x2d), 0, 1);
  *(u32 *)(self + 0x2d) = 0;
}
PCREG(52b9d0, processAdditionalDoors);
