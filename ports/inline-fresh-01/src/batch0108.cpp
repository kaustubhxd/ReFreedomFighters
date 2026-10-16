// batch0108.cpp - fresh-01 batch 8 (docs/20-fresh-01.md).
#include "ff.h"

extern "C" u32 *THISCALL ext_5003d0(u32 arr, u32 i);                    // array element pointer (checked)
extern "C" void THISCALL ext_604ca0(u8 *self);                          // one-time OpaqueString setup
extern "C" void *ext_41e290(u32 size);                                  // operator new
extern "C" void THISCALL ext_45faf0(u8 *self, u32 cmd, u32 data, u32 sender);   // ZGEOM::SendCommandRecursive
extern "C" void THISCALL ext_4dc630(u32 geom, u32 a, u32 b);            // ZBaseGeom::SetControl
extern "C" void THISCALL ext_4da1d0(u32 geom, u32 flag);                // ZBaseGeom::CalcCenSize(bool)
extern "C" void THISCALL ext_4dd060(u32 geom, float *v);                // ZBaseGeom set size
extern "C" void FASTCALL ext_633654(u32 cookie);                        // __security_check_cookie
extern "C" void THISCALL ext_59a9b0(void *vec, u32 n);                  // vector reserve
extern "C" void THISCALL ext_4ff9d0(void *vec);                         // vector destructor

static u8 *render() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

// 0x50dad0 (unnamed): g0 = render slot 0x58(*elem(arr, 0)), g1 = render slot 0x58(*elem(arr, 1)) with arr = p+4;
// when both exist and g0 is a 0x100001 (slot 0x1e0): g0 slot 0x288(g1, 0, 1). ECX is not used.
static void THISCALL link50dad0(u8 *self, u8 *p) {
  u32 *e = ext_5003d0(*(u32 *)(p + 4), 0);
  u8 *g0 = vcall<u8 *>(render(), 0x58, *e);
  e = ext_5003d0(*(u32 *)(p + 4), 1);
  u8 *g1 = vcall<u8 *>(render(), 0x58, *e);
  if (!g1 || !g0) return;
  if (!vcall<u8>(g0, 0x1e0, 0x100001u)) return;
  vcall<void>(g0, 0x288, g1, 0u, 1u);
}
PCREG(50dad0, link50dad0);

// 0x5c3f10 (unnamed destructor): vtable 0x6b3f5c; the owned object at +0x48 is deleted (slot 0 with 1) and cleared;
// +0x44 = +0x30 = 0; base vtable 0x686874; render slot 0x34(this).
static void THISCALL dtor5c3f10(u8 *self) {
  *(u32 *)self = 0x6b3f5c;
  u8 *o = *(u8 **)(self + 0x48);
  if (o) {
    vcall<void>(o, 0, 1u);
    *(u32 *)(self + 0x48) = 0;
  }
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)self = 0x686874;
  vcall<void>(render(), 0x34, self);
}
PCREG(5c3f10, dtor5c3f10);

// 0x49a5d0, ZLoadGame::GetPtrAndSkip (name map; the body reads a list): obj slot 0xc(); n = this slot 0x14(&n) (read
// into the argument's own slot); then n times: id = slot 0x40, a = slot 0x50, b = slot 0x50 (each read into a local)
// and obj slot 0x98(id, b, a). The loop compares with != after the first pass.
static void THISCALL loadReadList(u8 *self, u8 *obj) {
  vcall<void>(obj, 0xc);
  u32 n;
  vcall<void>(self, 0x14, &n);
  if (n == 0) return;
  u32 i = 0;
  do {
    u32 id, a, b;
    vcall<void>(self, 0x40, &id);
    vcall<void>(self, 0x50, &a);
    vcall<void>(self, 0x50, &b);
    vcall<void>(obj, 0x98, id, b, a);
    i++;
  } while (i != n);
}
PCREG(49a5d0, loadReadList);

// 0x604650, OpaqueString_t::OpaqueString_t(): +4 = 1, +8 = 0, vtable 0x6b9b7c, one-time setup 0x604ca0 while
// [0x724768] is 0, +0xc = new(0xc) with an empty string, word +0x10 = 0xc. Returns this.
static u8 *THISCALL opaqueStringCtor(u8 *self) {
  *(u32 *)(self + 4) = 1;
  *(u32 *)(self + 8) = 0;
  *(u32 *)self = 0x6b9b7c;
  if (G(u32, 0x724768) == 0) ext_604ca0(self);
  u8 *p = (u8 *)ext_41e290(0xc);
  *(u8 **)(self + 0xc) = p;
  p[0] = 0;
  *(u16 *)(self + 0x10) = 0xc;
  return self;
}
PCREG(604650, opaqueStringCtor);

// Iterates the id list at `lst` (slot 0x4c starts, slot 0x5c steps: returns the id and leaves the iterator's first
// dword nonzero while valid) and gives each existing render geom (render slot 0x58(id)) to fn.
template <class F>
static void forEachGeom(u8 *owner, u32 off, F fn) {
  u32 it[3];
  vcall<void>(*(u8 **)(owner + off), 0x4c, (u32 *)it);
  u32 id = vcall<u32>(*(u8 **)(owner + off), 0x5c, (u32 *)it);
  while (it[0]) {
    u8 *g = vcall<u8 *>(render(), 0x58, id);
    if (g) fn(g);
    id = vcall<u32>(*(u8 **)(owner + off), 0x5c, (u32 *)it);
  }
}

// 0x44a710, ZLIST::SendCommandRecursive(unsigned short, void*, ZGEOM*): ZGEOM::SendCommandRecursive, then the same
// command to every member (list at +0x18) through slot 0x138.
static void THISCALL listSendCommandRecursive(u8 *self, u32 cmd, u32 data, u32 sender) {
  ext_45faf0(self, cmd, data, sender);
  if (!*(u8 **)(self + 0x18)) return;
  forEachGeom(self, 0x18, [&](u8 *g) { vcall<void>(g, 0x138, cmd, data, sender); });
}
PCREG(44a710, listSendCommandRecursive);

// 0x449310, ZGateLightMaster::Enable(): slot 0x214 on every light in the list at +0x1c; SetControl(0, 0x2000) on the
// geom at +8; flags +0x18: clear bit 0, set bit 3.
static void THISCALL gateLightMasterEnable(u8 *self) {
  if (*(u8 **)(self + 0x1c)) forEachGeom(self, 0x1c, [](u8 *g) { vcall<void>(g, 0x214); });
  ext_4dc630(*(u32 *)(self + 8), 0, 0x2000);
  *(u32 *)(self + 0x18) = (*(u32 *)(self + 0x18) & 0xfffffffeu) | 8;
}
PCREG(449310, gateLightMasterEnable);

// 0x453090, ZGATE::CalcCenSize(): ZBaseGeom::CalcCenSize(true) on the geom at +8, then its size (+0x40..+0x48) with each
// component below 1/8192 (0.0001220703125 at 0x679540; NaN stays) replaced by 1/8192, passed to 0x4dd060.
static void THISCALL gateCalcCenSize(u8 *self) {
  ext_4da1d0(*(u32 *)(self + 8), 1);
  u8 *g = *(u8 **)(self + 8);
  const float lim = bitsf(0x39000000);
  float v[3] = {*(float *)(g + 0x40), *(float *)(g + 0x44), *(float *)(g + 0x48)};
  if (lim > v[0]) *(u32 *)&v[0] = 0x39000000;
  if (lim > v[1]) *(u32 *)&v[1] = 0x39000000;
  if (lim > v[2]) *(u32 *)&v[2] = 0x39000000;
  ext_4dd060(*(u32 *)(self + 8), v);
  ext_633654(G(u32, 0x6f5630));
}
PCREG(453090, gateCalcCenSize);

// 0x522c50 (unnamed): unless [0x701a78] is set: a local vector {0, 0, 0, owns = 1} reserves 50 (0x59a9b0), own slot
// 0x1c fills it, and it is destroyed (0x4ff9d0).
struct LocalVec {
  u32 a, b, c;
  u8 owns;
};
static void THISCALL fill522c50(u8 *self) {
  if (G(u32, 0x701a78)) return;
  LocalVec v;
  v.a = 0;
  v.b = 0;
  v.c = 0;
  v.owns = 1;
  ext_59a9b0(&v, 0x32);
  vcall<void>(self, 0x1c, &v);
  ext_4ff9d0(&v);
}
PCREG(522c50, fill522c50);
