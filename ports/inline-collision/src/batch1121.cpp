// batch1121.cpp - collision thread, batch 1121: ZCollisionBase::GetDynamicGeomsInBox (0x4ecb40).
#include "ff.h"

static inline u8 *sysObj() { return G(u8 *, 0x70039c); }

extern "C" float *THISCALL ext_4e3180(float *self);                    // SRecurseInfoCompiled ctor (batch 1110)
extern "C" void FASTCALL ext_4e2c60(const float *m, float *v);         // TransformBox (batch 1100 chain)
extern "C" void FASTCALL ext_43e920(float *dst, const float *a, const float *b);   // dst = a - b
extern "C" void FASTCALL ext_43e8e0(float *dst, const float *a, const float *b);   // dst = a + b
extern "C" void THISCALL ext_4e4420(u8 *tree, u8 *info, const float *mn, const float *mx);   // quadtree box query (1116)
extern "C" void THISCALL ext_4ec6d0(u8 *info);                         // clear marked geoms (1115)
extern "C" void THISCALL ext_4daf90(const u8 *geom, float *c);         // GetCen (1115)
extern "C" void FASTCALL ext_4de7a0(float *m);                         // mreset
extern "C" void THISCALL ext_4db600(const u8 *geom, float *m, float *p);   // GetRootMatPos (1115)
extern "C" u8 FASTCALL ext_4df330(const float *m0, const float *p0, const float *h0, const float *m1,
                                  const float *p1, const float *h1);    // rectBoxColi

// 0x4ecb40 ZCollisionBase::GetDynamicGeomsInBox(ZBaseGeom **a, ZBaseGeom **b, eGlobalTreeType type,
// const float *mat, const float *centre, const float *half, unsigned mask, bool filter) const [medium], thiscall,
// ret 0x20, returns the count of geoms written to a from its start.
// 1. The dynamic tree ([[[0x70039c]+0x9b]+0xadc], slot 0x314) gives the quadtree; none means 0.
// 2. The info record (see batch 1120) gets the collect callback 0x4edd40, out range a..b, mask, class type.
// 3. The half extents are transformed by mat (TransformBox); the query box is centre -/+ them. The quadtree's
//    CheckBox (0x4e4420) collects into the record; then the marked geoms are cleared (0x4ec6d0).
// 4. With filter and a non-empty result: each collected geom (kept in the array) has its centre and root matrix
//    taken, and is kept when rectBoxColi (mat, centre, half, the root-matrix frame, the geom's centre, its half) hits;
//    misses are replaced by the last entry.
static u32 THISCALL getDynamicGeomsInBox(u8 *self, u8 **a, u8 **b, u32 type, const float *mat, const float *centre,
                                         const float *half, u32 mask, u8 filter) {
  (void)self;
  u8 *tree = *(u8 **)(*(u8 **)(sysObj() + 0x9b) + 0xadc);
  u8 *dt = vcall<u8 *>(tree, 0x314);
  if (!dt)
    return 0;
  u8 info[0x1078];
  ext_4e3180((float *)info);
  *(u32 *)(info + 4) = 0x4edd40;
  *(u8 ***)(info + 0x5c) = a;
  *(u8 ***)(info + 0x60) = b;
  *(u32 *)(info + 0x64) = 0;
  *(u32 *)(info + 0x68) = mask;
  *(u32 *)(info + 0x6c) = type;
  *(u32 *)(info + 0x70) = 0;
  *(u32 *)(info + 0x1074) = 0;
  float t[3], mn[3], mx[3];
  t[0] = half[0];
  t[1] = half[1];
  t[2] = half[2];
  ext_4e2c60(mat, t);
  ext_43e920(mn, centre, t);
  ext_43e8e0(mx, centre, t);
  ext_4e4420(dt, info, mn, mx);
  ext_4ec6d0(info);
  u32 n = *(u32 *)(info + 0x64);
  if (filter && n) {
    u32 cnt = n;
    for (u32 k = 0; k < cnt;) {
      u8 *g = a[k];
      float c[3], m[9];
      ext_4daf90(g, c);
      ext_4de7a0(m);
      ext_4db600(g, m, c);
      if (ext_4df330(mat, centre, half, m, c, (const float *)(g + 0x40))) {
        k++;
      } else {
        a[k] = a[cnt - 1];
        cnt--;
      }
    }
    n = cnt;
  }
  return n;
}
PCREG(4ecb40, getDynamicGeomsInBox);
