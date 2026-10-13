// batch284.cpp - area 22 gameplay-core batch (docs/20-unclaimed-22.md, "Gameplay core, batch284"): ZBoneModifyBase::
// CalcShadowProjectPlane, the screen-space bounds of a character's shadow (ten bone boxes projected through the light's
// matrix). Name from the GameCube name map; behaviour from the PC bytes.
#include "ff.h"

extern "C" void FASTCALL ext_441970(float *out, const float *v, const float *m);  // vmmul (inline-collision)
extern "C" void FASTCALL ext_441940(float *v, const float *a);                    // PSVECAdd (inline-batch45)
extern "C" void FASTCALL ext_4de440(float *out, const float *a, const float *b);  // mmmul (GUESS: hooked)
extern "C" void FASTCALL ext_4e09e0(float *out, const float *v);                  // vneg (inline-batch45)
extern "C" void FASTCALL ext_4419f0(float *v, const float *m);                    // vmmul in place (inline-batch45)

// 0x645790 ZBoneModifyBase::CalcShadowProjectPlane(const ZLNKOBJ *obj, float *out, const float *P, const float *T)
// const (thiscall, ret 0x10, returns bool). The bone data object (rm+0x1aa3)+0x18 must know the shape [obj+8]+0x6c
// (vt 0xc0), else false. For the ten bones of the list {0x17, 6, 0xa, 5, 9, 2, 0x15, 0x11, 0x13, 0xf} mapped through
// its table (vt 0xc8) to a slot s: the bone matrix is this->vt 0x58(obj) + 48 s and its box (vt 0xc4) + 48 s (centre at
// +0, half size at +0x10). The box centre goes through the bone matrix and P plus T; the eight corners of the box
// (vneg for the low corner) go through mmmul(bone, P) plus that point; each corner with z above 0 (as an int compare of
// the float bits) projects to (x / z, y / z) and widens the bounds (start +-1e38; a NaN replaces the bound). out = min x
// (at most 0), max x (at least 0), min y, max y; true. Stack cookie not reproduced.
u8 THISCALL calcShadowProjectPlane_645790(u8 *self, u8 *obj, float *out, const float *P, const float *T) {
  u32 shape = *(u32 *)(*(u8 **)(obj + 8) + 0x6c);
  u8 *bd = *(u8 **)(*(u8 **)(*(u8 **)0x70039cu + 0x1aa3) + 0x18);
  if (!vcall<u32>(bd, 0xc0, shape)) return 0;
  static const u8 bones[10] = {0x17, 0x06, 0x0a, 0x05, 0x09, 0x02, 0x15, 0x11, 0x13, 0x0f};
  u8 *map = (u8 *)vcall<u32>(*(u8 **)(*(u8 **)(*(u8 **)0x70039cu + 0x1aa3) + 0x18), 0xc8, shape);
  u8 *boxes = (u8 *)vcall<u32>(*(u8 **)(*(u8 **)(*(u8 **)0x70039cu + 0x1aa3) + 0x18), 0xc4, shape);
  u8 *mats = (u8 *)vcall<u32>(self, 0x58, (u32)obj);
  float minx = *(float *)0x67cd44u, maxx = *(float *)0x67cd48u;
  float miny = minx, maxy = maxx;
  for (int b = 0; b < 10; b++) {
    u32 s = map[bones[b]];
    const float *bm = (const float *)(mats + s * 48);
    const float *box = (const float *)(boxes + s * 48);
    float tmp[3];
    ext_441970(tmp, box, bm);
    ext_441940(tmp, bm + 9);
    float ext[3] = {box[4], box[5], box[6]};
    float M[12], Tc[3];
    ext_4de440(M, bm, P);
    ext_441970(Tc, tmp, P);
    ext_441940(Tc, T);
    float c[8][3];
    ext_4e09e0(c[0], ext);
    float n0 = c[0][0], n1 = c[0][1], n2 = c[0][2], e0 = ext[0], e1 = ext[1], e2 = ext[2];
    c[1][0] = e0; c[1][1] = e1; c[1][2] = e2;
    c[2][0] = e0; c[2][1] = n1; c[2][2] = n2;
    c[3][0] = n0; c[3][1] = e1; c[3][2] = n2;
    c[4][0] = e0; c[4][1] = e1; c[4][2] = n2;
    c[5][0] = n0; c[5][1] = n1; c[5][2] = e2;
    c[6][0] = e0; c[6][1] = n1; c[6][2] = e2;
    c[7][0] = n0; c[7][1] = e1; c[7][2] = e2;
    for (int k = 0; k < 8; k++) {
      ext_4419f0(c[k], M);
      ext_441940(c[k], Tc);
    }
    for (int k = 0; k < 8; k++) {
      if (*(s32 *)&c[k][2] <= 0) continue;
      float inv = *(float *)0x678858u / c[k][2];
      float x = c[k][0] * inv, y = c[k][1] * inv;
      if (!(x > minx)) minx = x;
      if (!(maxx > x)) maxx = x;
      if (!(y > miny)) miny = y;
      if (!(maxy > y)) maxy = y;
    }
  }
  out[0] = 0.0f < minx ? 0.0f : minx;
  out[1] = 0.0f > maxx ? 0.0f : maxx;
  out[2] = 0.0f < miny ? 0.0f : miny;
  out[3] = 0.0f > maxy ? 0.0f : maxy;
  return 1;
}
PCREG(645790, calcShadowProjectPlane_645790);
