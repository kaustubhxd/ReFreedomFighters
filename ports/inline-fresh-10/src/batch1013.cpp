// batch1013.cpp - fresh-10 batch 13: opaque type singleton, dynamic trees, scene value name, sewer info, room lights.
#include "ff.h"

#define F32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FL(p, o) (*(float *)((u8 *)(p) + (o)))
#define SCENE (*(u8 **)(*(u8 **)0x70039c + 0x9b))
extern "C" void THISCALL ext_4cbec0(void *);        // MYSTR::~MYSTR
extern "C" void THISCALL ext_4cbee0(void *, void *); // MYSTR::operator=
extern "C" void THISCALL ext_4cbe80(void *, u32);    // MYSTR::MYSTR(const char*)
extern "C" u8 *ext_41e290(u32);                      // new (cdecl)

// 0x50d8e0 GUESS (fastcall info, buf; SEH frame): the opaque type singleton [0x7012cc] is replaced: the old one gets
// slot4(0); o = new(0xc) OpaqueType_t(info, buf) with vtable 0x69d3b8. Unless [0x7012c8] is set, a temporary vector
// {0, 0, 0, flag 1} is reserved for 0x32 (0x59a9b0), filled by o.slot1c and freed (0x4ff9d0). Returns [0x7012cc].
extern "C" void THISCALL ext_5f9700(void *, u32, u32);
extern "C" void THISCALL ext_59a9b0(void *, u32);
extern "C" void THISCALL ext_4ff9d0(void *);
struct Vec16 { u32 a, b, c; u8 f; };   // 13 bytes used; the 3 padding bytes are left as they are (not compared)
static u8 *FASTCALL OpaqueSingleton(u32 info, u32 buf) {
  void *old = G(void *, 0x7012cc);
  if (old) {
    vcall<void>(old, 4, 0u);
    G(u32, 0x7012cc) = 0;
  }
  u8 *o = ext_41e290(0xc);
  if (o) {
    ext_5f9700(o, info, buf);
    F32(o, 0) = 0x69d3b8;
  }
  G(u8 *, 0x7012cc) = o;
  if (G(u32, 0x7012c8)) return o;
  Vec16 v = {0, 0, 0, 1};
  ext_59a9b0(&v, 0x32);
  vcall<void>(o, 0x1c, &v);
  ext_4ff9d0(&v);
  return G(u8 *, 0x7012cc);
}
PCREG(50d8e0, OpaqueSingleton);

// 0x442d20 ZTreeGroup::CreateDynamicTrees() (high; /GS, SEH frame): +0x71 = new(0x2d) CQuadtree(0x2800);
// size = GetOriginAndSize(origin) (ST0); quadtree 0x4e4fc0(origin), 0x4e4fe0(32000 / max(1000, size));
// slot2f0(+8); every tree of the list +0x7b (count word +2, pointers from +0x404) gets slot324().
extern "C" u8 *THISCALL ext_4e3e70(void *, u32);
extern "C" float THISCALL ext_443080(void *, float *);
extern "C" void THISCALL ext_4e4fc0(void *, float *);
extern "C" void THISCALL ext_4e4fe0(void *, float);
static void THISCALL CreateDynamicTrees(u8 *self) {
  u8 *q = ext_41e290(0x2d);
  *(u8 **)(self + 0x71) = q ? ext_4e3e70(q, 0x2800) : 0;
  float org[3];
  float sz = ext_443080(self, org);
  float c = G(float, 0x67d164);
  float s = c > sz ? c : sz;
  ext_4e4fc0(*(void **)(self + 0x71), org);
  ext_4e4fe0(*(void **)(self + 0x71), G(float, 0x67d168) / s);
  vcall<void>(self, 0x2f0, F32(self, 8));
  if (*(u8 **)(self + 0x7b))
    for (u32 i = 0; i != *(u16 *)(*(u8 **)(self + 0x7b) + 2); i++)
      vcall<void>(*(void **)(*(u8 **)(self + 0x7b) + 0x404 + 4 * i), 0x324);
}
PCREG(442d20, CreateDynamicTrees);

// 0x4c90a0 CRegisterSceneValName::Init(ZGEOM*, DBREAD&) (high; /GS, SEH frame): name = MYSTR(geom +0x44 -> +4); a
// string field in the block (type byte != 0xff, low 6 bits == 4) replaces it; o = scene.slot138();
// o.slot60(name, scene.slot4c(+0x44, 2)); slot58(); ~name.
extern "C" char *THISCALL ext_4e5ea0(void *);
static void THISCALL SceneValNameInit(u8 *self, void *, u8 **db) {
  u8 name[0x80];
  ext_4cbe80(name, F32(*(u8 **)(self + 0x44), 4));
  u8 t = **db;
  if (t != 0xff && (t & 0x3f) == 4) {
    u8 tmp[0x80];
    ext_4cbe80(tmp, (u32)ext_4e5ea0(db));
    ext_4cbee0(name, tmp);
    ext_4cbec0(tmp);
  }
  void *o = vcall<void *>(SCENE, 0x138);
  u32 x = vcall<u32>(SCENE, 0x4c, F32(self, 0x44), 2u);
  vcall<void>(o, 0x60, *(u32 *)name, x);
  vcall<void>(self, 0x58);
  ext_4cbec0(name);
}
PCREG(4c90a0, SceneValNameInit);

// 0x5b1760 ZSewerControl::SetSewerInfo(const char*, int, float*, float*) (medium): angle of the direction (atan(z/x)
// on +0x20/+0x18, quarter turns when x == 0, +pi when x < 0, +2pi when z < 0); every one of the 19 entries (+8, 0x12
// bytes: name, kind byte, position, angle byte) whose name matches gets kind, position and (int)(angle * 255 / 2pi).
static inline s32 Cvtt(float f) {
  s32 r;
  asm("cvttss2si %1, %0" : "=r"(r) : "x"(f));
  return r;
}
static void THISCALL SetSewerInfo(u8 *self, const char *name, u32 kind, u32 *pos, float *dir) {
  float x = dir[6], z = dir[8], a;
  if (x == 0.0f) {
    a = z > 0.0f ? G(float, 0x683770) : G(float, 0x6970d8);
  } else {
    a = (float)crt::atan((double)(z / x));
    if (0.0f > dir[6]) a += G(float, 0x67da18);
    else if (0.0f > dir[8]) a += G(float, 0x68aef8);
  }
  for (int i = 0; i < 19; i++) {
    u8 *e = self + 8 + 0x12 * i;
    const u8 *p = (const u8 *)name, *q = *(const u8 **)e;
    while (*p == *q && *p) p++, q++;
    if (*p != *q) continue;
    e[4] = (u8)kind;
    e[0x11] = (u8)Cvtt(a * G(float, 0x68af18) / G(float, 0x68aef8));
    *(u32 *)(e + 5) = pos[0];
    *(u32 *)(e + 9) = pos[1];
    *(u32 *)(e + 0xd) = pos[2];
  }
}
PCREG(5b1760, SetSewerInfo);

// 0x4449e0 ZROOM::GetDynamicLightsInRoom(ZBaseGeom**, ZBaseGeom**) (high): walk the dynamic table +0xa8 (slot4c begin,
// slot5c next; ends when the iterator's first word is 0) while out < end. A geom whose kind flags (+0x54 -> +0xc ->
// +0x23, 0x200002 without one) have 0x800000 is stored; one with 0x100000 whose object slot2a8() has 0x10000 stores
// its children (+8, then object.slot50(&child)) that have 0x800000. Returns the new end.
static inline u32 KindFlags(u8 *g) {
  u8 *r = *(u8 **)(g + 0x54);
  return r ? F32(*(u8 **)(r + 0xc), 0x23) : 0x200002;
}
static u8 **THISCALL GetDynamicLightsInRoom(u8 *self, u8 **out, u8 **end) {
  if (!*(void **)(self + 0xa8)) return out;
  u32 it[3];
  vcall<void>(*(void **)(self + 0xa8), 0x4c, it);
  u8 *g = vcall<u8 *>(*(void **)(self + 0xa8), 0x5c, it);
  while (it[0]) {
    if (end <= out) return out;
    u8 *r = *(u8 **)(g + 0x54);
    u32 f = r ? F32(*(u8 **)(r + 0xc), 0x23) : 0x200002;
    if (f & 0x800000) {
      if (out < end) *out++ = g;
    } else if ((f & 0x100000) && (vcall<u32>(r, 0x2a8) & 0x10000)) {
      for (u8 *c = *(u8 **)(r + 8); c;) {
        if ((KindFlags(c) & 0x800000) && out < end) *out++ = c;
        vcall<void>(r, 0x50, &c);
      }
    }
    g = vcall<u8 *>(*(void **)(self + 0xa8), 0x5c, it);
  }
  return out;
}
PCREG(4449e0, GetDynamicLightsInRoom);
