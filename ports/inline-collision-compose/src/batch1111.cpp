// batch1111.cpp - collision thread, batch 1111: ZCollisionBase::CalcLineCollision and its primitive callback.
#include "ff.h"

static inline u8 *sysObj() { return G(u8 *, 0x70039c); }

// 0x4cc1d0 MYSTR::c_str (guessed), thiscall: returns the char pointer at +0.
static const char *THISCALL mystrCStr(const u8 *self) { return *(const char *const *)self; }
PCREG(4cc1d0, mystrCStr);

// The line-check record ("SLineChk", name guessed) CalcLineCollision builds on its stack and hands to a primitive
// octree: +0 result word (seeded from the impact's first word), +4 callback (0x4ec610), +0x5c impact, +0x60 record
// base (ZCollisionBase+0x190), +0x64 start, +0x70 vector, +0x7c bool, +0x7d mask (unaligned).

// 0x4ec610 (no Ghidra function; the primitive callback CalcLineCollision installs), fastcall (object, chk), al.
// Casts through slot 0x60 of [[0x70039c]+0x1aa3]+0x1c with (impact, chk+0x60 + object[0], &start, &vector, bool,
// mask); on a hit chk+0 = the impact's first word.
static u8 FASTCALL primLineCallBack(const u8 *obj, u8 *chk) {
  u8 *o = *(u8 **)(*(u8 **)(sysObj() + 0x1aa3) + 0x1c);
  u32 rec = *(u32 *)(chk + 0x60) + *(const u32 *)obj;
  if (!vcall<u8>(o, 0x60, *(u8 **)(chk + 0x5c), rec, chk + 0x64, chk + 0x70, (u32)chk[0x7c], *(u32 *)(chk + 0x7d)))
    return 0;
  *(u32 *)chk = **(u32 **)(chk + 0x5c);
  return 1;
}
PCREG(4ec610, primLineCallBack);

extern "C" u32 *THISCALL ext_4e3170(u32 *self, const u32 *src);
extern "C" void FASTCALL ext_43e8e0(float *dst, const float *a, const float *b);   // dst = a + b (x87)
extern "C" u8 *THISCALL ext_4da2f0(const u8 *geom, u8 *out, u32 flag);             // ZBaseGeom::CalcTotalName
extern "C" const char *THISCALL ext_4cc1d0(const u8 *s);                           // MYSTR::c_str
extern "C" void THISCALL ext_4cbec0(u8 *s);                                        // MYSTR::~MYSTR
typedef void *(THISCALL *vcallLog)(void *self, const char *file, u32 line);
typedef void (*cdeclFmt)(void *self, const char *fmt, const char *s);

// 0x4ebcf0 ZCollisionBase::CalcLineCollision(SExtendedImpactInfo *imp, ZBaseGeom *geom, float *from, float *vec,
// bool b, unsigned mask) const [high], thiscall, ret 0x18, al. Looks up the geom's room record (slot 0xc of
// [[0x70039c]+0x1aa3]+0x18); a disabled record (word +2) or a roomless geom misses. With a primitive octree (record
// +0x28, a node handle) it fills a line-check record and casts with the octree's slot 0x18 (chk, from, from + vec);
// a hit stores the geom at imp+0x10. Without one it logs "NOTIFY: Geom %s has no prim octree!" through the error
// object [0x700390] (slot 0x20 file 0x6977c4 line 0x307, then cdecl slot 0x30 with format 0x697840 and the geom's
// full name) and misses. The exe wraps the name string in an SEH frame; the port has no exceptions.
static u8 THISCALL calcLineCollision(u8 *self, u8 *imp, u8 *geom, float *from, float *vec, u8 b, u32 mask) {
  u32 room = *(u32 *)(geom + 0x6c);
  if (!room)
    return 0;
  u8 *rd = vcall<u8 *>(*(u8 **)(*(u8 **)(sysObj() + 0x1aa3) + 0x18), 0xc, room);
  if (*(u16 *)(rd + 2))
    return 0;
  u32 h = *(u32 *)(rd + 0x28);
  if (h & 1)
    h = (h & 0xfffffffeu) + *(u32 *)(*(u8 **)(sysObj() + 0x9b) + 0xaec);
  u8 *prim = (u8 *)h;
  if (!prim) {
    void *eh = G(void *, 0x700390);
    void *lg = ((vcallLog)(*(void ***)eh)[0x20 / 4])(eh, (const char *)0x6977c4u, 0x307u);
    u8 name[0x40];
    u8 *s = ext_4da2f0(geom, name, 1);
    ((cdeclFmt)(*(void ***)lg)[0x30 / 4])(lg, (const char *)0x697840u, ext_4cc1d0(s));
    ext_4cbec0(name);
    return 0;
  }
  u8 chk[0x104];
  ext_4e3170((u32 *)chk, (const u32 *)imp);
  *(u32 *)(chk + 4) = 0x4ec610;
  *(u32 *)(chk + 0x60) = *(u32 *)(self + 0x190);
  chk[0x7c] = b;
  *(u32 *)(chk + 0x7d) = mask;
  *(u8 **)(chk + 0x5c) = imp;
  float *s0 = (float *)(chk + 0x64);
  float *v0 = (float *)(chk + 0x70);
  s0[0] = from[0];
  s0[1] = from[1];
  s0[2] = from[2];
  v0[0] = vec[0];
  v0[1] = vec[1];
  v0[2] = vec[2];
  float end[3];
  ext_43e8e0(end, from, vec);
  if (!vcall<u8>(prim, 0x18, chk, from, end))
    return 0;
  *(u8 **)(imp + 0x10) = geom;
  return 1;
}
PCREG(4ebcf0, calcLineCollision);

extern "C" void THISCALL ext_4db670(const u8 *geom, float *p);   // ZBaseGeom::GetRootPoint (batch 1100)

// 0x4eba90 ZCollisionBase::CalcLineColi_(SExtendedImpactInfo *imp, eGlobalTreeType type, float *from, float *vec,
// bool b, unsigned mask, bool statics, bool dynamics) const [medium], thiscall, ret 0x20, al.
// statics: three chained check records on the stack, each seeded with imp[0]:
//   R (rooms; callback CalcRoomLineCallBack): +0x5c from, +0x68 vec, +0x74 type, +0x78 -> G, +0x7c the record offset
//     [[this+0x19d]+0x14], +0x80 a 16-entry ring, +0xc0 ring count = 0, +0xc4 ring-full = 0;
//   G (geoms; callback CalcGeomLineCallBack): +0x5c from, +0x68 vec, +0x74 mask, +0x78 -> P;
//   P (primitives; callback 0x4ec610): +0x5c imp, +0x60 [this+0x190], +0x7c b, +0x7d mask.
//   The room octree [this+0x19d] slot 0x18 casts (R, from, from + vec); afterwards every bound object still in R's
//   ring gets slot 0x378(0, 1) (all 16 when the ring wrapped).
// dynamics: when the dynamic tree [[[0x70039c]+0x9b]+0xadc] says so (slot 0x30c), this's slot 0x58
//   (CalcDynamicLineCollision) runs with (imp, tree, type, from, vec, b, mask).
// Any hit: imp+4 = imp's local hit point taken to world space by its geom (imp+0x10, GetRootPoint); returns true.
static u8 THISCALL calcLineColi_(u8 *self, u8 *imp, u32 type, float *from, float *vec, u32 b, u32 mask, u32 statics,
                                 u32 dynamics) {
  u8 hit = 0;
  if ((u8)statics) {
    u8 R[0xc8], Gk[0x7c], P[0x84];
    ext_4e3170((u32 *)R, (const u32 *)imp);
    ext_4e3170((u32 *)Gk, (const u32 *)imp);
    ext_4e3170((u32 *)P, (const u32 *)imp);
    *(u8 **)(R + 0x78) = Gk;
    *(u32 *)(R + 0x74) = type;
    *(u32 *)(R + 4) = 0x4ebed0;
    *(u32 *)(R + 0x7c) = *(u32 *)(*(u8 **)(self + 0x19d) + 0x14);
    R[0xc4] = 0;
    *(u8 **)(Gk + 0x78) = P;
    *(u32 *)(P + 0x60) = *(u32 *)(self + 0x190);
    *(u32 *)(Gk + 0x74) = mask;
    *(u32 *)(P + 0x7d) = mask;
    *(u32 *)(R + 0xc0) = 0;
    float f0 = from[0], f1 = from[1], f2 = from[2], v0 = vec[0], v1 = vec[1], v2 = vec[2];
    float *rf = (float *)(R + 0x5c), *gf = (float *)(Gk + 0x5c);
    rf[0] = f0, rf[1] = f1, rf[2] = f2, rf[3] = v0, rf[4] = v1, rf[5] = v2;
    *(u32 *)(Gk + 4) = 0x4eb8a0;
    gf[0] = f0, gf[1] = f1, gf[2] = f2, gf[3] = v0, gf[4] = v1, gf[5] = v2;
    *(u32 *)(P + 4) = 0x4ec610;
    *(u8 **)(P + 0x5c) = imp;
    P[0x7c] = (u8)b;
    float end[3];
    ext_43e8e0(end, from, vec);
    hit = vcall<u8>(*(u8 **)(self + 0x19d), 0x18, R, from, end);
    u32 n = R[0xc4] ? 0x10 : *(u32 *)(R + 0xc0);
    for (u32 i = 0; i != n; i++)
      vcall<void>(((u8 **)(R + 0x80))[i], 0x378, 0u, 1u);
  }
  if ((u8)dynamics) {
    u8 *tree = *(u8 **)(*(u8 **)(sysObj() + 0x9b) + 0xadc);
    if (vcall<u8>(tree, 0x30c))
      hit |= vcall<u8>(self, 0x58, imp, *(u8 **)(*(u8 **)(sysObj() + 0x9b) + 0xadc), type, from, vec, b, mask);
  }
  if (!hit)
    return 0;
  ext_4db670(*(u8 **)(imp + 0x10), (float *)(imp + 4));
  return 1;
}
PCREG(4eba90, calcLineColi_);

extern "C" u8 THISCALL ext_4eba90(u8 *self, u8 *imp, u32 type, float *from, float *vec, u32 b, u32 mask, u32 st,
                                  u32 dy);

// 0x4eba80 ZCollisionBase::CalcLineColi [medium]: tail jump to CalcLineColi_ (0x4eba90) with the same 8 args.
static u8 THISCALL calcLineColi(u8 *self, u8 *imp, u32 type, float *from, float *vec, u32 b, u32 mask, u32 st, u32 dy) {
  return ext_4eba90(self, imp, type, from, vec, b, mask, st, dy);
}
PCREG(4eba80, calcLineColi);
