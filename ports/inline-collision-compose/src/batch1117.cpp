// batch1117.cpp - collision thread, batch 1117: room lists of ZCollisionBase (point and oriented-box queries).
#include "ff.h"

static inline u8 *sysObj() { return G(u8 *, 0x70039c); }
static inline u8 *renderMgr() { return *(u8 **)(sysObj() + 0x9b); }
static inline u8 *roomDir() { return *(u8 **)(*(u8 **)(sysObj() + 0x1aa3) + 0x18); }

extern "C" void FASTCALL ext_459fc0(float *out, const float *v, const float *m);   // vmtmul 3-arg (batch 1115)
extern "C" void FASTCALL ext_43e920(float *dst, const float *a, const float *b);   // PSVECSubtract: dst = a - b
extern "C" void FASTCALL ext_43e8e0(float *dst, const float *a, const float *b);   // dst = a + b (x87)
extern "C" void FASTCALL ext_441a60(float *v, const float *m);                     // vmtmul in place (batch 1100)
extern "C" void FASTCALL ext_4de4b0(float *dst, const float *a, const float *m);
extern "C" u8 FASTCALL ext_4df330(const float *m0, const float *p0, const float *h0, const float *m1, const float *p1,
                                  const float *h1);                                // rectBoxColi
extern "C" float *THISCALL ext_4e3180(float *self);                               // SRecurseInfoCompiled ctor
extern "C" void FASTCALL ext_4de420(float *dst, const float *src);                 // mcpy
extern "C" void FASTCALL ext_4e2c60(const float *m, float *v);                     // TransformBox

// 0x4de4b0 (unnamed; guessed mmtmul(dst, a, m)), fastcall (dst ECX, a EDX, m stack), ret 4: each row of a (2, 1, 0)
// times transpose(m) into dst.
static void FASTCALL mmtmul(float *dst, const float *a, const float *m) {
  ext_459fc0(dst + 6, a + 6, m);
  ext_459fc0(dst + 3, a + 3, m);
  ext_459fc0(dst, a, m);
}
PCREG(4de4b0, mmtmul);

// Room query record ("room info", an SRecurseInfoCompiled used by GetRoomsLst): +4 callback, +0x5c record base
// (octree+0x14), +0x60 out begin, +0x64 out end, +0x68 count, +0x6c query matrix (box query), +0x90 query point /
// box centre, +0x9c box half size, +0xa8 the half size through TransformBox.
// Room record (base + object[0]): +0 axis-aligned flag, +4 rotation, +0x28 centre, +0x34 a second point, +0x40 half
// size, +0x4c room key (render manager slot 0x58 -> ZROOM), +0x50 geom key (render manager slot 0x54).

static inline bool fabsGt(float a, float b) {
  return bitsf64(f64bits((double)a) & 0x7fffffffffffffffull) > (double)b;
}

// Appends room to the record's out list when there is space: slot 0x378(1, 0) marks it, then list[count++] = room.
static inline u8 appendRoom(u8 *info, u8 *room) {
  if (!(*(u32 *)(info + 0x64) > *(u32 *)(info + 0x60) + *(u32 *)(info + 0x68) * 4))
    return 0;
  vcall<void>(room, 0x378, 1u, 0u);
  ((u8 **)*(u8 **)(info + 0x60))[*(u32 *)(info + 0x68)] = room;
  *(u32 *)(info + 0x68) += 1;
  return 1;
}

// 0x4eda00 (no Ghidra function; the point-in-room callback of GetRoomsLst), fastcall (object, info), al.
// Skips rooms whose slot 0x37c has bit 0. The point (info+0x90) minus the record centre, rotated into the room
// unless the record is axis-aligned, must be within the half size on every axis (|d| compared in double). A record
// with a geom key also needs the room directory's slot 0x1c (geom room, local point, 0) to agree. Then appends.
static u8 FASTCALL pointRoomCallBack(const u8 *obj, u8 *info) {
  u8 *rec = *(u8 **)(info + 0x5c) + *(const u32 *)obj;
  u8 *room = vcall<u8 *>(renderMgr(), 0x58, *(u32 *)(rec + 0x4c));
  if (vcall<u8>(room, 0x37c) & 1)
    return 0;
  float d[3];
  ext_43e920(d, (const float *)(info + 0x90), (const float *)(rec + 0x28));
  if (*(u32 *)rec == 0)
    ext_441a60(d, (const float *)(rec + 4));
  const float *h = (const float *)(rec + 0x40);
  if (fabsGt(d[0], h[0]) || fabsGt(d[1], h[1]) || fabsGt(d[2], h[2]))
    return 0;
  u32 gk = *(u32 *)(rec + 0x50);
  if (gk) {
    u8 *geom = vcall<u8 *>(renderMgr(), 0x54, gk);
    if (geom) {
      float l[3];
      ext_43e920(l, (const float *)(info + 0x90), (const float *)(rec + 0x34));
      ext_441a60(l, (const float *)(rec + 4));
      if (!vcall<u8>(roomDir(), 0x1c, *(u32 *)(geom + 0x6c), l, 0u))
        return 0;
    }
  }
  return appendRoom(info, room);
}
PCREG(4eda00, pointRoomCallBack);

// 0x4ed840 (no Ghidra function; the box-in-room callback of GetRoomsLst), fastcall (object, info), al. Like 0x4eda00
// for an oriented box: axis-aligned records compare |centre - record centre| with the transformed half size plus the
// record's half size; rotated records use rectBoxColi. A geom record asks the room directory's slot 0x20 (geom room,
// box matrix in the record frame, local centre, half size).
static u8 FASTCALL boxRoomCallBack(const u8 *obj, u8 *info) {
  u8 *rec = *(u8 **)(info + 0x5c) + *(const u32 *)obj;
  u8 *room = vcall<u8 *>(renderMgr(), 0x58, *(u32 *)(rec + 0x4c));
  if (vcall<u8>(room, 0x37c) & 1)
    return 0;
  if (*(u32 *)rec) {
    float d[3], e[3];
    ext_43e920(d, (const float *)(info + 0x90), (const float *)(rec + 0x28));
    ext_43e8e0(e, (const float *)(info + 0xa8), (const float *)(rec + 0x40));
    if (fabsGt(d[0], e[0]) || fabsGt(d[1], e[1]) || fabsGt(d[2], e[2]))
      return 0;
  } else if (!ext_4df330((const float *)(info + 0x6c), (const float *)(info + 0x90), (const float *)(info + 0x9c),
                         (const float *)(rec + 4), (const float *)(rec + 0x28), (const float *)(rec + 0x40))) {
    return 0;
  }
  u32 gk = *(u32 *)(rec + 0x50);
  if (gk) {
    u8 *geom = vcall<u8 *>(renderMgr(), 0x54, gk);
    if (geom) {
      float l[3], m[9];
      ext_43e920(l, (const float *)(info + 0x90), (const float *)(rec + 0x28));
      ext_441a60(l, (const float *)(rec + 4));
      ext_4de4b0(m, (const float *)(info + 0x6c), (const float *)(rec + 4));
      if (!vcall<u8>(roomDir(), 0x20, *(u32 *)(geom + 0x6c), m, l, (const float *)(info + 0x9c)))
        return 0;
    }
  }
  return appendRoom(info, room);
}
PCREG(4ed840, boxRoomCallBack);

// 0x4ed4f0 ZCollisionBase::GetRoomsLst(ZROOM **begin, ZROOM **end, ZOctreeCompiled *oct, const float *p) const
// [medium], thiscall, ret 0x10. Fills a room record (callback 0x4eda00) and asks the octree (slot 0x24, record, p);
// then every room it listed gets slot 0x378(0, 1) (the marks are only for the duration of the query).
static u32 THISCALL getRoomsLstPoint(u8 *self, u8 **begin, u8 **end, u8 *oct, const float *p) {
  (void)self;
  u8 info[0xb4];
  ext_4e3180((float *)info);
  *(u32 *)(info + 0x5c) = *(u32 *)(oct + 0x14);
  *(u8 ***)(info + 0x60) = begin;
  *(u8 ***)(info + 0x64) = end;
  *(u32 *)(info + 0x68) = 0;
  *(u32 *)(info + 4) = 0x4eda00;
  float *q = (float *)(info + 0x90);
  q[0] = p[0];
  q[1] = p[1];
  q[2] = p[2];
  vcall<void>(oct, 0x24, info, p);
  for (u32 i = 0; i != *(u32 *)(info + 0x68); i++)
    vcall<void>(begin[i], 0x378, 0u, 1u);
  return *(u32 *)(info + 0x68);
}
PCREG(4ed4f0, getRoomsLstPoint);

// 0x4ed390 ZCollisionBase::GetRoomsLst(ZROOM **begin, ZROOM **end, ZOctreeCompiled *oct, const float *mat,
// const float *pos, const float *half) const [medium], thiscall, ret 0x18. The oriented-box version (callback
// 0x4ed840): the record holds the matrix, centre, half size and its TransformBox image; the octree's slot 0x1c is
// asked with the world AABB (pos - t, pos + t). Then the marks are released as above.
static u32 THISCALL getRoomsLstBox(u8 *self, u8 **begin, u8 **end, u8 *oct, const float *mat, const float *pos,
                                   const float *half) {
  (void)self;
  u8 info[0xb4];
  ext_4e3180((float *)info);
  *(u8 ***)(info + 0x64) = end;
  *(u32 *)(info + 0x68) = 0;
  *(u32 *)(info + 4) = 0x4ed840;
  *(u32 *)(info + 0x5c) = *(u32 *)(oct + 0x14);
  *(u8 ***)(info + 0x60) = begin;
  ext_4de420((float *)(info + 0x6c), mat);
  float *q = (float *)(info + 0x90);
  q[0] = pos[0];
  q[1] = pos[1];
  q[2] = pos[2];
  float t[3];
  t[0] = q[3] = half[0];
  t[1] = q[4] = half[1];
  t[2] = q[5] = half[2];
  ext_4e2c60(mat, t);
  q[6] = t[0];
  q[7] = t[1];
  q[8] = t[2];
  float lo[3], hi[3];
  ext_43e920(lo, pos, t);
  ext_43e8e0(hi, pos, t);
  vcall<void>(oct, 0x1c, info, lo, hi);
  for (u32 i = 0; i != *(u32 *)(info + 0x68); i++)
    vcall<void>(begin[i], 0x378, 0u, 1u);
  return *(u32 *)(info + 0x68);
}
PCREG(4ed390, getRoomsLstBox);

// 0x4ed340 ZCollisionBase::GetInsideRoomsLst(begin, end, mat, pos, half) [medium] and 0x4ecb00 GetColiRoomsLst
// [medium], thiscall, ret 0x14: this's slot 0x14 (the box GetRoomsLst) with the octree at +0x1a1 (inside) or
// +0x19d (collision rooms).
static u32 THISCALL getInsideRoomsLst(u8 *self, u8 **b, u8 **e, const float *m, const float *p, const float *h) {
  return vcall<u32>(self, 0x14, b, e, *(u8 **)(self + 0x1a1), m, p, h);
}
PCREG(4ed340, getInsideRoomsLst);
static u32 THISCALL getColiRoomsLst(u8 *self, u8 **b, u8 **e, const float *m, const float *p, const float *h) {
  return vcall<u32>(self, 0x14, b, e, *(u8 **)(self + 0x19d), m, p, h);
}
PCREG(4ecb00, getColiRoomsLst);
