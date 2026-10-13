// batch1112.cpp - collision thread, batch 1112: ZCollisionBase::CalcColiLort (line against one dynamic geom).
#include "ff.h"

extern "C" void THISCALL ext_4db220(const u8 *geom, float *p, float *v);          // GetLocalPointVect (1108)
extern "C" void FASTCALL ext_43e920(float *dst, const float *a, const float *b);   // PSVECSubtract
extern "C" u8 FASTCALL ext_4e2800(float *t, float, float, float, float, float, float, float, float, float, float,
                                  float, float);                                  // LineVS_AABB
extern "C" u32 THISCALL ext_4daf80(u8 *geom);                                     // GetBoundTreeType (1108)
extern "C" u8 THISCALL ext_4db9a0(const u8 *geom, u32 cls);                       // ZBaseGeom::IsDerivedFrom
extern "C" void FASTCALL ext_443ef0(float *dst, const float *a, const float *v, float s);   // dst = a + v * s

static inline float fneg(float f) { return bitsf(fbits(f) ^ 0x80000000u); }

// 0x4eb410 ZCollisionBase::CalcColiLort(SExtendedImpactInfo *imp, ZBaseGeom *geom, eGlobalTreeType type,
// const float *from, const float *vec, unsigned mask, bool b) const [high], thiscall, ret 0x1c, al.
// The segment goes into the geom's frame and is tested against the geom's box (centre +0x30, half size +0x40;
// LineVS_AABB). It must hit at a t below the impact's current best (imp+0). Then, by the class id of the geom's
// bound object (+0x54; first class descriptor +0xc, id at +0x23; 0x200002 without one):
// - 0x100000 set (a group): every child (bound+0x50, linked by +0x60) with flags (+0x3c) clear of 0xc00 and a
//   non-zero low byte is tested recursively through this's slot 0x54; returns whether any hit;
// - otherwise the geom must share a flag with the mask and have the bound tree type `type`. Class 0x200006 casts
//   with bound slot 0x27c (imp, local start, local vector): a non-zero result goes to imp+0x3c, imp+4 = start +
//   vector * imp[0], imp+0x44 = the geom's room, imp+0x10 = the geom. Other classes cast through slot 0x64 of
//   [[0x70039c]+0x1aa3]+0x1c (imp, geom, start, vector, b, mask); a hit sets imp+0x10.
static u8 THISCALL calcColiLort(u8 *self, u8 *imp, u8 *geom, u32 type, const float *from, const float *vec, u32 mask,
                                u32 b) {
  float p[3], v[3], d[3], t;
  p[0] = from[0];
  p[1] = from[1];
  p[2] = from[2];
  v[0] = vec[0];
  v[1] = vec[1];
  v[2] = vec[2];
  ext_4db220(geom, p, v);
  ext_43e920(d, p, (const float *)(geom + 0x30));
  const float *h = (const float *)(geom + 0x40);
  float h0 = h[0], h1 = h[1], h2 = h[2];
  if (!ext_4e2800(&t, fneg(h0), fneg(h1), fneg(h2), h0, h1, h2, d[0], d[1], d[2], v[0], v[1], v[2]))
    return 0;
  if (!(*(float *)imp > t))
    return 0;
  u8 *bnd = *(u8 **)(geom + 0x54);
  u32 cls = bnd ? *(u32 *)(*(u8 **)(bnd + 0xc) + 0x23) : 0x200002u;
  if (cls & 0x100000) {
    u8 hit = 0;
    for (u8 *ch = *(u8 **)(bnd + 0x50); ch; ch = *(u8 **)(ch + 0x60)) {
      u32 f = *(u32 *)(ch + 0x3c);
      if ((f & 0xc00) || !(u8)f)
        continue;
      hit |= vcall<u8>(self, 0x54, imp, ch, type, from, vec, mask, b);
    }
    return hit;
  }
  if (!(*(u32 *)(geom + 0x3c) & mask))
    return 0;
  if (ext_4daf80(geom) != type)
    return 0;
  if (ext_4db9a0(geom, 0x200006)) {
    u32 r = vcall<u32>(*(u8 **)(geom + 0x54), 0x27c, imp, p, v);
    if (!r)
      return 0;
    float s = *(float *)imp;
    *(u32 *)(imp + 0x3c) = r;
    ext_443ef0((float *)(imp + 4), p, v, s);
    *(u32 *)(imp + 0x44) = *(u32 *)(geom + 0x6c);
    *(u8 **)(imp + 0x10) = geom;
    return 1;
  }
  u8 *o = *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x1aa3) + 0x1c);
  if (!vcall<u8>(o, 0x64, imp, geom, p, v, b, mask))
    return 0;
  *(u8 **)(imp + 0x10) = geom;
  return 1;
}
PCREG(4eb410, calcColiLort);

extern "C" float *THISCALL ext_4e3180(float *self);                                // SRecurseInfoCompiled ctor
extern "C" void FASTCALL ext_43e8e0(float *dst, const float *a, const float *b);   // dst = a + b (x87)
extern "C" u8 THISCALL ext_4e4520(u8 *qt, u8 *info, const float *from, const float *to);   // CQuadtree::CheckLinesegment
extern "C" void FASTCALL ext_43e960(float *v, const float *a);                     // v -= a (x87)
extern "C" void FASTCALL ext_4de040(float *m, const float *dir, const float *up);   // createmat
extern "C" void FASTCALL ext_441940(float *v, const float *a);                     // PSVECAdd

// 0x4eb680 ZCollisionBase::CalcDynamicLineCollision(SExtendedImpactInfo *imp, const ZTreeGroup *tree,
// eGlobalTreeType type, float *from, float *vec, bool b, int mask) const [high], thiscall, ret 0x1c, al.
// Skipped when bit 10 of [[tree+8]+0x3c] is set or the tree has no quadtree (slot 0x314). The quadtree segment walk
// (CheckLinesegment) collects candidate geoms through callback 0x4e32e0 into the list at this+0x1b1 (end this+0x21b1,
// count in the info record); each goes through this's slot 0x54 (CalcColiLort) with (imp, geom, type, from, vec,
// mask, b). If any hit and imp+0x3c (the primitive) is set: for a 0x200006-class geom the hit frame comes from
// bound slot 0x24c's object, slot 0xc (matrix, point, primitive, bound): point -= the hit point, createmat(matrix,
// point, null), and imp+0x14 = hit point, imp+0x20 = hit + matrix row 2, imp+0x2c = hit + row 2 + row 1; without
// that object the frame is the fixed (0,0,0), (1,0,0), (1,1,0).
static u8 THISCALL calcDynamicLineCollision(u8 *self, u8 *imp, u8 *tree, u32 type, float *from, float *vec, u32 b,
                                            u32 mask) {
  if ((*(u32 *)(*(u8 **)(tree + 8) + 0x3c) >> 10) & 1)
    return 0;
  u8 *qt = vcall<u8 *>(tree, 0x314);
  if (!qt)
    return 0;
  u8 info[0x6c];
  ext_4e3180((float *)info);
  u8 **list = (u8 **)(self + 0x1b1);
  *(u32 *)(info + 4) = 0x4e32e0;
  *(u8 **)(info + 0x60) = self + 0x21b1;
  *(u32 *)(info + 0x64) = 0;
  *(u8 ***)(info + 0x5c) = list;
  *(u32 *)(info + 0x68) = mask;
  float end[3];
  ext_43e8e0(end, from, vec);
  ext_4e4520(qt, info, from, end);
  u8 hit = 0;
  for (u32 i = 0; i != *(u32 *)(info + 0x64); i++)
    hit |= vcall<u8>(self, 0x54, imp, list[i], type, from, vec, mask, b);
  if (!hit || !*(u32 *)(imp + 0x3c))
    return hit;
  if (!ext_4db9a0(*(u8 **)(imp + 0x10), 0x200006))
    return hit;
  u8 *bnd = *(u8 **)(*(u8 **)(imp + 0x10) + 0x54);
  u8 *src = vcall<u8 *>(bnd, 0x24c);
  float *ip = (float *)(imp + 4);
  if (src) {
    float M[9], P[3];
    vcall<void>(src, 0xc, M, P, *(u32 *)(imp + 0x3c), bnd);
    ext_43e960(P, ip);
    ext_4de040(M, P, 0);
    *(u32 *)(imp + 0x14) = *(u32 *)(imp + 4);
    *(u32 *)(imp + 0x18) = *(u32 *)(imp + 8);
    *(u32 *)(imp + 0x1c) = *(u32 *)(imp + 0xc);
    ext_43e8e0((float *)(imp + 0x20), ip, M + 6);
    ext_43e8e0((float *)(imp + 0x2c), ip, M + 6);
    ext_441940((float *)(imp + 0x2c), M + 3);
  } else {
    *(u32 *)(imp + 0x14) = 0;
    *(u32 *)(imp + 0x18) = 0;
    *(u32 *)(imp + 0x1c) = 0;
    *(u32 *)(imp + 0x20) = 0x3f800000;
    *(u32 *)(imp + 0x24) = 0;
    *(u32 *)(imp + 0x28) = 0;
    *(u32 *)(imp + 0x2c) = 0x3f800000;
    *(u32 *)(imp + 0x30) = 0x3f800000;
    *(u32 *)(imp + 0x34) = 0;
  }
  return hit;
}
PCREG(4eb680, calcDynamicLineCollision);
