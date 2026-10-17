// batch0117.cpp - fresh-01 batch 17 (docs/20-fresh-01.md).
#include "ff.h"

extern "C" void THISCALL ext_659330(u8 *list, u32 n, u32 b);         // per-instance table setup (ret 8)
extern "C" void *ext_634d22(void *d, const void *s, u32 n);          // memcpy thunk
extern "C" void THISCALL ext_4db6c0(u8 *g, float *mat, float *pos);  // ZBaseGeom::GetRootTM
extern "C" void THISCALL ext_4db2a0(u8 *g, float *mat);              // ZBaseGeom::GetMat
extern "C" void THISCALL ext_4db500(u8 *g, float *pos);              // ZBaseGeom::GetPos
extern "C" void THISCALL ext_4db600(u8 *g, float *mat, float *pos);  // ZBaseGeom::GetRootMatPos
extern "C" u8 *THISCALL ext_4b48c0(u8 *self, u32 geom);              // CCutSequenceList::GetIKLnkObj
extern "C" void THISCALL ext_4dcf80(u8 *g, const float *mat, const float *pos);  // ZBaseGeom::SetRootTM
extern "C" void FASTCALL ext_633654(u32 cookie);                     // __security_check_cookie
extern "C" u32 *THISCALL ext_5003d0(u32 arr, u32 i);                 // array element pointer (checked)

typedef void (*handlerFn)();
typedef void (*log3Fn)(void *, u32, u32);

static u8 *render() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

// 0x616490 (unnamed constructor, SEH frame without cleanups): +4 = a, vtable 0x6bdcf4, +8..+0x10 = 0; p =
// [[b+0x10]+8], n = u16 p+0xe; 0x659330(this+8, n, [c+0xb9a8]); src = [[c+0xb9a4]+0x13fa], base =
// [[0x70039c]+0x1aa3]+0x20 (always read); when +0xc is set: src+0x30 is filled from src slot 4(0, 0) when empty,
// then n 36-byte records are copied from base + p+0x14 to src+0x30 + 36 * +0xc. Returns this.
static u8 *THISCALL ctor616490(u8 *self, u32 a, u8 *b, u8 *c) {
  *(u32 *)(self + 4) = a;
  *(u32 *)self = 0x6bdcf4;
  *(u32 *)(self + 8) = 0;
  *(u32 *)(self + 0xc) = 0;
  *(u32 *)(self + 0x10) = 0;
  u8 *p = *(u8 **)(*(u8 **)(b + 0x10) + 8);
  u32 n = *(u16 *)(p + 0xe);
  ext_659330(self + 8, n, *(u32 *)(c + 0xb9a8));
  u8 *src = *(u8 **)(*(u8 **)(c + 0xb9a4) + 0x13fa);
  u32 base = *(u32 *)(*(u8 **)(G(u8 *, 0x70039c) + 0x1aa3) + 0x20);
  if (*(u32 *)(self + 0xc)) {
    if (*(u32 *)(src + 0x30) == 0) *(u32 *)(src + 0x30) = vcall<u32>(src, 4, 0u, 0u);
    ext_634d22((void *)(*(u32 *)(src + 0x30) + *(u32 *)(self + 0xc) * 36), (void *)(*(u32 *)(p + 0x14) + base), n * 36);
  }
  return self;
}
PCREG(616490, ctor616490);

// 0x4b7f90, CCutSequenceList::SetObjectTM(unsigned int, unsigned int): reads the source transform of geom `b`
// (render slot 0x54): GetRootTM when +0x80 is 0, else GetMat/GetPos then GetRootMatPos of geom +0x80; then on geom
// `a` (when found): its IK link object (GetIKLnkObj(a+0x54)) slot 0x370(mat, pos), else SetRootTM(mat, pos). /GS.
static void THISCALL cutSetObjectTM(u8 *self, u32 a, u32 b) {
  float mat[9], pos[3];
  u8 *g = vcall<u8 *>(render(), 0x54, b);
  if (*(u32 *)(self + 0x80) == 0) {
    ext_4db6c0(g, mat, pos);
  } else {
    ext_4db2a0(g, mat);
    ext_4db500(g, pos);
    u8 *h = vcall<u8 *>(render(), 0x54, *(u32 *)(self + 0x80));
    ext_4db600(h, mat, pos);
  }
  u8 *t = vcall<u8 *>(render(), 0x54, a);
  if (t) {
    u8 *lnk = ext_4b48c0(self, *(u32 *)(t + 0x54));
    if (lnk) vcall<void>(lnk, 0x370, mat, pos);
    else ext_4dcf80(t, mat, pos);
  }
  ext_633654(G(u32, 0x6f5630));
}
PCREG(4b7f90, cutSetObjectTM);

// 0x50dd50 (script native, unnamed): element 0 of +4: type 3 -> its value, type 4 -> value slot 0x34(), else log
// 0x69c8e0:0x111 and the handler (int3 when unset), value 0; r = render slot 0x4c([[render]+0xadc] slot 0x25c(v, 0));
// result element 0 of +8: when its type is 0 or 1 it becomes type 1 = r, else log 0x69c8e0:0xc4 and the handler.
static void THISCALL native50dd50(u8 *self, u8 *p) {
  u32 *e = ext_5003d0(*(u32 *)(p + 4), 0);
  u8 ty = *((u8 *)e + 4);
  u32 v;
  if (ty == 3) {
    v = *e;
  } else if (ty == 4) {
    v = vcall<u32>(*(u8 **)e, 0x34);
  } else {
    u8 *lg = vcall<u8 *>(G(u8 *, 0x700390), 0x20, 0x69c8e0u, 0x111u);
    (*(log3Fn *)(*(u8 **)lg + 0x2c))(lg, 0x69c6b0, 0x69c9b0);
    handlerFn h = G(handlerFn, 0x7003b0);
    if (!h) __builtin_debugtrap();
    h();
    v = 0;
  }
  u32 x = vcall<u32>(*(u8 **)(render() + 0xadc), 0x25c, v, 0u);
  u32 r = vcall<u32>(render(), 0x4c, x);
  u32 *o = ext_5003d0(*(u32 *)(p + 8), 0);
  if (*((u8 *)o + 4) <= 1) {
    *o = r;
    *((u8 *)o + 4) = 1;
    return;
  }
  u8 *lg = vcall<u8 *>(G(u8 *, 0x700390), 0x20, 0x69c8e0u, 0xc4u);
  (*(log3Fn *)(*(u8 **)lg + 0x2c))(lg, 0x69c6b0, 0x69c938);
  handlerFn h = G(handlerFn, 0x7003b0);
  if (!h) __builtin_debugtrap();
  h();
}
PCREG(50dd50, native50dd50);
