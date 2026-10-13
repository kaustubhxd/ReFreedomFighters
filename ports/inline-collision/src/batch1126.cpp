// batch1126.cpp - collision thread, batch 1126: ZCollisionBase::GetStripsInsideBox (0x4ed5b0).
#include "ff.h"

extern "C" float *THISCALL ext_4e3180(float *self);                              // SRecurseInfoCompiled ctor (1110)
extern "C" void FASTCALL ext_4de420(float *dst, const float *src);               // mcpy (9 floats)
extern "C" void THISCALL ext_4db1b0(const u8 *geom, float *m, float *p);         // GetLocalMatPos (1115)
extern "C" void FASTCALL ext_4e2c60(const float *m, float *v);                   // TransformBox
extern "C" void FASTCALL ext_43e8e0(float *dst, const float *a, const float *b); // dst = a + b
extern "C" void FASTCALL ext_43e920(float *dst, const float *a, const float *b); // dst = a - b

static inline u8 *sysObj() { return G(u8 *, 0x70039c); }

// Query record q (SRecurseInfoCompiled + callback fields; GUESS names from the stores, offsets exact):
// +0 ctor 1.0f, +4 item callback 0x4ec660, +0x5c strip table base (value of collision+0x190), +0x60 out end,
// +0x64 out limit, +0x68 start, +0x6c out count, +0x70 local matrix (9 floats), +0x94 local point (3 floats),
// +0xa0 half extents (3 floats, from p3), +0xac current geom, +0xb0 helper object (this, slot 0x88).
// CheckCube (+0x14..+0x28) writes the query box and the walk's +0xc/+0x10 bases.
//
// 0x4ed5b0 GetStripsInsideBox(unsigned *out, char *strips, unsigned count, const float *p1, const float *p2,
// const float *p3, unsigned start, eGlobalTreeType type) [medium], thiscall (this in ECX), ret 0x20, returns al.
// 1. GetGeomsInBox(a, b, type, p1, p2, p3, start, 1, 1, 1) through [[sysobj+0x1aa3]+0x1c] slot 0x38 -> count.
// 2. For each geom a[i]: room = [geom+0x6c]; skip null or a disabled room (word room+dirOff+2 non-zero); octree handle
//    = room+dirOff+0x28, rebased on the octree node base when bit 0 is set; skip null.
//    The geom's local matrix and point from p1 and p2 (GetLocalMatPos), the half extents p3 through TransformBox,
//    the box is point -/+ half, and octree slot 0x1c (CheckCube) collects strip entries into strips[end..limit).
// 3. out = the count written; al = whether 0xe4 bytes of the window remain (unsigned).
static u8 THISCALL getStripsInsideBox(u8 *self, u32 *out, u8 *strips, u32 count, const float *p1, const float *p2,
                                      const float *p3, u32 start, u32 type) {
  u8 q[0xb4];
  for (u32 i = 0; i < sizeof q; i++)
    q[i] = 0;
  ext_4e3180((float *)q);
  *(u32 *)(q + 4) = 0x4ec660;
  *(u32 *)(q + 0x5c) = *(u32 *)(self + 0x190);
  *(u8 **)(q + 0x60) = strips;
  *(u8 **)(q + 0x64) = strips + count;
  *(u32 *)(q + 0x68) = start;
  *(u32 *)(q + 0x6c) = 0;
  *(u8 **)(q + 0xb0) = self;
  for (int k = 0; k < 3; k++)
    *(float *)(q + 0xa0 + 4 * k) = p3[k];

  u8 *ds = *(u8 **)(sysObj() + 0x1aa3);
  u8 *coll = *(u8 **)(ds + 0x1c);
  u8 *A[0x800], *B[0x800];
  u32 n = vcall<u32>(coll, 0x38, A, B, type, p1, p2, p3, start, 1u, 1u, 1u);
  u32 dirOff = *(u32 *)(ds + 0x20);
  u8 *octBase = *(u8 **)(*(u8 **)(sysObj() + 0x9b) + 0xaec);

  if (n) {
    for (u32 i = 0; i < n; i++) {
      u8 *geom = A[i];
      u8 *room = *(u8 **)(geom + 0x6c);
      if (!room)
        continue;
      if (*(u16 *)(room + dirOff + 2))
        continue;
      u32 h = *(u32 *)(room + dirOff + 0x28);
      if (h & 1)
        h = (h & 0xfffffffeu) + (u32)octBase;
      if (!h)
        continue;
      u8 *oct = (u8 *)h;
      *(u8 **)(q + 0xac) = geom;
      float *m = (float *)(q + 0x70);
      float *pt = (float *)(q + 0x94);
      for (int k = 0; k < 3; k++)
        pt[k] = p2[k];
      ext_4de420(m, p1);
      ext_4db1b0(geom, m, pt);
      float v[3];
      for (int k = 0; k < 3; k++)
        v[k] = *(float *)(q + 0xa0 + 4 * k);
      ext_4e2c60(m, v);
      float mx[3], mn[3];
      ext_43e8e0(mx, pt, v);
      ext_43e920(mn, pt, v);
      vcall<void>(oct, 0x1c, q, mn, mx);
    }
  }
  u32 written;
  u8 *end;
  if (n) {
    written = *(u32 *)(q + 0x6c);
    end = *(u8 **)(q + 0x60);
  } else {
    written = 0;
    end = strips;
  }
  *out = written;
  return (u8)((u32)(*(u8 **)(q + 0x64) - end) >= 0xe4);
}
PCREG(4ed5b0, getStripsInsideBox);
