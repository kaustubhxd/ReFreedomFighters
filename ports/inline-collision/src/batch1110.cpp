// batch1110.cpp - collision thread, batch 1110: the octree line-cast callbacks of ZCollisionBase and two forwarders.
#include "ff.h"

extern "C" void THISCALL ext_4db220(const u8 *geom, float *p, float *v);   // ZBaseGeom::GetLocalPointVect (1108)
extern "C" void FASTCALL ext_441940(float *v, const float *a);             // PSVECAdd: v += a
extern "C" u8 *FASTCALL ext_4ed370(u32 handle);

static inline u8 *sysObj() { return G(u8 *, 0x70039c); }
static inline u8 *renderMgr() { return *(u8 **)(sysObj() + 0x9b); }

// 0x4ed370 (unnamed; guessed ResolveNodeHandle), fastcall (handle in ECX), plain ret. A handle with bit 0 set is an
// offset into the octree node array ([[0x70039c]+0x9b]+0xaec) after clearing the bit; otherwise it is a pointer.
static u8 *FASTCALL resolveHandle(u32 h) {
  if (h & 1)
    return (u8 *)((h & 0xfffffffeu) + *(u32 *)(renderMgr() + 0xaec));
  return (u8 *)h;
}
PCREG(4ed370, resolveHandle);

// SOctreeChk (from these bodies): +0 result word, +0x5c segment start, +0x68 segment vector, +0x74 geom flag mask,
// +0x78 SExtendedImpactInfo*, +0x7c record offset (room walk), +0x80 ring of 16 bound objects, +0xc0 ring count,
// +0xc4 ring-full byte. SExtendedImpactInfo: +0 word, +0x5c hit record (+0 word, +0x10 geom), +0x64 local start,
// +0x70 local vector, +0x7c byte.

// 0x4eb8a0 CalcGeomLineCallBack(CObjectInfo *obj, SOctreeChk *chk) [high], fastcall, plain ret, al = hit.
// geom = render-manager slot 0x54 (obj[0]); skipped when null, flagged 0xc00, not in the mask, or roomless (+0x6c).
// rd = slot 0xc of [[0x70039c]+0x1aa3]+0x18 (room); skipped when the word rd+2 is set. The segment goes into the
// geom's local frame. With a primitive octree (handle rd+0x28 resolved non-null) the local segment is stored in the
// impact (+0x64, +0x70) and cast with the octree's slot 0x18 (impact, start, end). Without one, geoms flagged
// 0x400000 are cast through slot 0x5c of [[0x70039c]+0x1aa3]+0x1c (record, room, start, vector, impact byte +0x7c,
// mask). On a hit the record's +0x10 = geom and chk+0 = a word of the impact (first path) or of the record (second).
static u8 FASTCALL calcGeomLineCallBack(u8 *obj, u8 *chk) {
  u8 *geom = vcall<u8 *>(renderMgr(), 0x54, *(u32 *)obj);
  if (!geom)
    return 0;
  u32 f = *(u32 *)(geom + 0x3c);
  if (f & 0xc00)
    return 0;
  if (!(*(u32 *)(chk + 0x74) & f))
    return 0;
  u32 room = *(u32 *)(geom + 0x6c);
  if (!room)
    return 0;
  u8 *x = *(u8 **)(sysObj() + 0x1aa3);
  u8 *rd = vcall<u8 *>(*(u8 **)(x + 0x18), 0xc, room);
  if (*(u16 *)(rd + 2))
    return 0;
  u8 *prim = ext_4ed370(*(u32 *)(rd + 0x28));
  float p[3], v[3];
  p[0] = *(float *)(chk + 0x5c);
  p[1] = *(float *)(chk + 0x60);
  p[2] = *(float *)(chk + 0x64);
  v[0] = *(float *)(chk + 0x68);
  v[1] = *(float *)(chk + 0x6c);
  v[2] = *(float *)(chk + 0x70);
  ext_4db220(geom, p, v);
  if (prim) {
    u8 *imp = *(u8 **)(chk + 0x78);
    *(float *)(imp + 0x64) = p[0];
    *(float *)(imp + 0x68) = p[1];
    *(float *)(imp + 0x6c) = p[2];
    imp = *(u8 **)(chk + 0x78);
    *(float *)(imp + 0x70) = v[0];
    *(float *)(imp + 0x74) = v[1];
    *(float *)(imp + 0x78) = v[2];
    ext_441940(v, p);
    if (!vcall<u8>(prim, 0x18, *(u8 **)(chk + 0x78), p, v))
      return 0;
    *(u8 **)(*(u8 **)(*(u8 **)(chk + 0x78) + 0x5c) + 0x10) = geom;
    *(u32 *)chk = **(u32 **)(chk + 0x78);
    return 1;
  }
  if (!(*(u32 *)(geom + 0x3c) & 0x400000))
    return 0;
  u8 *imp = *(u8 **)(chk + 0x78);
  u8 *o = *(u8 **)(*(u8 **)(sysObj() + 0x1aa3) + 0x1c);
  if (!vcall<u8>(o, 0x5c, *(u8 **)(imp + 0x5c), room, p, v, (u32)imp[0x7c], *(u32 *)(chk + 0x74)))
    return 0;
  *(u8 **)(*(u8 **)(*(u8 **)(chk + 0x78) + 0x5c) + 0x10) = geom;
  *(u32 *)chk = **(u32 **)(*(u8 **)(chk + 0x78) + 0x5c);
  return 1;
}
PCREG(4eb8a0, calcGeomLineCallBack);

// 0x4ebed0 CalcRoomLineCallBack(CObjectInfo *obj, SOctreeChk *chk) [high], fastcall, plain ret, al = hit.
// rec = obj[0] + chk+0x7c; geom = render-manager slot 0x54 (rec+0x4c); skipped when null or flagged 0xc00, or when
// bit 0 of its bound object's (+0x54) slot 0x37c is set. The bound object goes into a 16-entry ring at chk+0x80
// (when the ring has wrapped, the entry it replaces gets slot 0x378(0, 1)); the new one gets slot 0x378(1, 0). Then
// prim = bound slot 0x340 (mask); the segment goes into the geom's frame and is cast with prim slot 0x18 (impact,
// start, end). On a hit chk+0 = the impact's first word.
static u8 FASTCALL calcRoomLineCallBack(u8 *obj, u8 *chk) {
  u8 *rec = *(u8 **)(chk + 0x7c) + *(u32 *)obj;
  u8 *geom = vcall<u8 *>(renderMgr(), 0x54, *(u32 *)(rec + 0x4c));
  if (!geom || (*(u32 *)(geom + 0x3c) & 0xc00))
    return 0;
  u8 *b = *(u8 **)(geom + 0x54);
  if (vcall<u8>(b, 0x37c) & 1)
    return 0;
  u32 n = *(u32 *)(chk + 0xc0);
  if (n == 0x10)
    chk[0xc4] = 1;
  n &= 0xf;
  *(u32 *)(chk + 0xc0) = n;
  if (chk[0xc4])
    vcall<void>(*(u8 **)(chk + 0x80 + 4 * n), 0x378, 0u, 1u);
  ((u8 **)(chk + 0x80))[*(u32 *)(chk + 0xc0)] = b;
  *(u32 *)(chk + 0xc0) += 1;
  vcall<void>(b, 0x378, 1u, 0u);
  u8 *prim = vcall<u8 *>(b, 0x340, *(u32 *)(chk + 0x74));
  if (!prim)
    return 0;
  float p[3], v[3];
  p[0] = *(float *)(chk + 0x5c);
  p[1] = *(float *)(chk + 0x60);
  p[2] = *(float *)(chk + 0x64);
  v[0] = *(float *)(chk + 0x68);
  v[1] = *(float *)(chk + 0x6c);
  v[2] = *(float *)(chk + 0x70);
  ext_4db220(geom, p, v);
  ext_441940(v, p);
  if (!vcall<u8>(prim, 0x18, *(u8 **)(chk + 0x78), p, v))
    return 0;
  *(u32 *)chk = **(u32 **)(chk + 0x78);
  return 1;
}
PCREG(4ebed0, calcRoomLineCallBack);

// 0x4ec6c0 ZCollisionBase::CheckLineColi [low]: tail jump to this object's vtable slot 0x30 (CalcLineColi), same args.
static u8 THISCALL checkLineColi(u8 *self, u8 *info, u32 type, float *a, float *b, u32 c, u32 d, u32 e, u32 f) {
  return vcall<u8>(self, 0x30, info, type, a, b, c, d, e, f);
}
PCREG(4ec6c0, checkLineColi);
