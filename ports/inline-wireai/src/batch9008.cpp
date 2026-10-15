// batch9008.cpp - wire-ai thread (2026-10-13): CRagdoll2::HandleCalcMatsMsg 0x6421a0 (GameCube reference HandleCalcMatsMsg__9CRagdoll2FP5ZBone,
// name medium), the ragdoll's pose read-out: the particles -> the bone frames the body is drawn with. Called by ZBoneModifyBase::Update
// 0x647610 when a ragdoll ends and by ZBoneModifyBase::UpdateGlobalIK 0x647790 every frame.
#include "ff.h"

extern "C" void FASTCALL ext_43e8e0(float *d, const float *a, const float *b);   // d = a + b
extern "C" void THISCALL ext_4e0d00(float *v, float s);                          // v *= s
extern "C" void FASTCALL ext_43e920(float *d, const float *a, const float *b);   // d = a - b
extern "C" void FASTCALL ext_446ee0(float *d, const float *a, const float *b);   // vcross
extern "C" void FASTCALL ext_4de420(float *dst, const float *src);               // mcpy (9 floats)
extern "C" void FASTCALL ext_4de480(float *mat, const float *m);                 // mat = mat * m
extern "C" void FASTCALL ext_4de440(float *out, const float *a, const float *b); // mmmul
extern "C" void FASTCALL ext_441970(float *out, const float *v, const float *m); // vmmul
extern "C" void FASTCALL ext_441940(float *dst, const float *src);               // dst += src
extern "C" void FASTCALL ext_4e0d40(float *out, const float *a, float s);        // out = a * s
extern "C" void FASTCALL ext_451890(float *dst, const float *v, float s);        // dst += v * s
extern "C" void FASTCALL ext_4de4b0(float *dst, const float *a, const float *m); // mmtmul
extern "C" void THISCALL ext_4de7a0(float *m);                                   // mreset

// The inlined vnorm: when any component is != 0 (a NaN counts), v *= 1 / sqrt(x*x + y*y + z*z), on the x87.
static inline void vnorm9008(float *v) {
  if (v[0] != 0.0f || v[1] != 0.0f || v[2] != 0.0f) {
    long double x = v[0], y = v[1], z = v[2];
    long double l = fsqrt_x87(x * x + y * y + z * z);
    long double inv = 1.0L / l;
    v[0] = (float)((long double)v[0] * inv);
    v[1] = (float)((long double)v[1] * inv);
    v[2] = (float)((long double)v[2] * inv);
  }
}

static inline float dot9008(const float *a, const float *b) { return (a[0] * b[0] + a[1] * b[1]) + a[2] * b[2]; }

// The render system's skeleton tables for the body's model: slot 0xc0 the bind rotations (9 floats per bone), slot 0xc4 the bone
// records (0x30 each, parent index at +0xc).
static inline void *skel9008() { return *(void **)(*(u8 **)(G(u8 *, 0x70039c) + 0x1aa3) + 0x18); }
static inline u32 model9008(u8 *self) { return *(u32 *)(*(u8 **)(*(u8 **)(self + 0x36) + 8) + 0x6c); }

// Inlined SetLinkMatPosByIx(ix at self+off, mat, pos): bone = bind rotation * mat at pos; the link (+0x36) slot 0x94(bone, bone pos);
// done[ix] = 1.
static void setLink9008(u8 *self, u32 off, const float *mat, const float *pos, u8 *bones, u8 *done) {
  s32 ix = *(s32 *)(self + off);
  float *rot = vcall<float *>(skel9008(), 0xc0, model9008(self));
  float *dst = (float *)(bones + ix * 0x30);
  dst[9] = pos[0];
  dst[10] = pos[1];
  dst[11] = pos[2];
  ext_4de420(dst, rot + ix * 9);
  ext_4de480(dst, mat);
  vcall<void>(*(void **)(self + 0x36), 0x94, dst, dst + 9);
  done[*(s32 *)(self + off)] = 1;
}

// Inlined LinkMats(ix): bone = its bind frame (+0x32) in its parent's frame; no parent (-1) leaves it.
static void linkTo9008(u8 *self, s32 ix, u8 *bones) {
  u8 *recs = vcall<u8 *>(skel9008(), 0xc4, model9008(self));
  s32 parent = *(s32 *)(recs + ix * 0x30 + 0xc);
  if (parent == -1) return;
  float *b = (float *)(bones + ix * 0x30);
  float *bind = (float *)(*(u8 **)(self + 0x32) + ix * 0x30);
  float *p = (float *)(bones + parent * 0x30);
  ext_4de440(b, bind, p);
  ext_441970(b + 9, bind + 9, p);
  ext_441940(b + 9, p + 9);
}

static void linkIx9008(u8 *self, u32 off, u8 *bones, u8 *done) {
  s32 ix = *(s32 *)(self + off);
  if (ix == -1) return;
  linkTo9008(self, ix, bones);
  done[*(s32 *)(self + off)] = 1;
}

// A limb segment: row 0 = unit(a - b); row 2 = r2 * c + r1 * s with c = +-(row 0 . r1), s = +-sqrt(max(0, 1 - c*c)) (CRT sqrt);
// row 1 = unit(row 0 x row 2); row 2 = row 1 x row 0.
static void limb9008(float *M, const float *a, const float *b, const float *r1, const float *r2, bool negDot, bool negSq) {
  ext_43e920(M, a, b);
  vnorm9008(M);
  float c = dot9008(M, r1);
  if (negDot) c = -c;
  ext_4e0d40(M + 6, r2, c);
  float x = 1.0f - c * c;
  float m = (0.0f > x) ? 0.0f : x;
  double s = crt::sqrt((double)m);
  if (negSq) s = -s;
  ext_451890(M + 6, r1, (float)s);
  ext_446ee0(M + 3, M, M + 6);
  vnorm9008(M + 3);
  ext_446ee0(M + 6, M + 3, M);
}

// A hip: d = unit(a - b), axis = unit(root row 0 x d), c = d . root row 0 (clamped to <= 1 for the second hip), the rotation about the
// axis by acos(c) (the exe's row order), W = mmtmul(root, R).
static void hip9008(float *W, const float *root, const float *a, const float *b, bool clamp) {
  float r0[3] = {root[0], root[1], root[2]};
  float d[3], ax[3], R[9];
  ext_43e920(d, a, b);
  vnorm9008(d);
  ext_446ee0(ax, r0, d);
  vnorm9008(ax);
  float c = (d[1] * r0[1] + d[0] * r0[0]) + d[2] * r0[2];
  if (clamp) c = (1.0f < c) ? 1.0f : c;
  float x = 1.0f - c * c;
  float m = (0.0f > x) ? 0.0f : x;
  float s = (float)crt::sqrt((double)m);
  float t = 1.0f - c;
  float X = ax[0], Y = ax[1], Z = ax[2];
  float yx = Y * X * t, zx = Z * X * t, zy = Z * Y * t;
  R[6] = X * X * t + c;
  R[7] = yx - Z * s;
  R[3] = yx + Z * s;
  R[8] = zx + Y * s;
  R[0] = zx - Y * s;
  R[4] = Y * Y * t + c;
  R[2] = Z * Z * t + c;
  float xs = X * s;
  R[5] = zy - xs;
  R[1] = zy + xs;
  ext_4de4b0(W, root, R);
}

#define P9008(off) ((float *)(rec + (off)))   // particle k's position: rec + k * 0x34 + 0xc

// 0x6421a0 CRagdoll2::HandleCalcMatsMsg(ZBone *bones), thiscall, ret 4. Particles at [[self+0x17f]+0xf]; bone indices at +0x183 ...
// (CRagdoll2::InitIndices); bones are 0x30 records (rotation, position at +0x24); a 0x60-byte done table.
static void THISCALL handleCalcMats(u8 *self, u8 *bones) {
  u8 done[0x60];
  for (int k = 0; k < 0x60; k++) done[k] = 0;
  u8 *rec = *(u8 **)(*(u8 **)(self + 0x17f) + 0xf);
  float mid1[3], mid2[3], u[3], v[3], w[3], junk[3];
  float root[9], spine[9], spine2[9];
  // root (bone +0x183): between the hips (particles 8, 9) facing the chest (mid of 5, 6)
  ext_43e8e0(mid1, P9008(0x110), P9008(0x144));
  ext_4e0d00(mid1, 0.5f);
  ext_43e8e0(mid2, P9008(0x1ac), P9008(0x1e0));
  ext_4e0d00(mid2, 0.5f);
  ext_43e920(u, mid1, mid2);
  vnorm9008(u);
  ext_43e920(v, P9008(0x1ac), P9008(0x1e0));
  vnorm9008(v);
  ext_446ee0(w, v, u);
  ext_446ee0(junk, v, u);
  vnorm9008(w);
  ext_446ee0(v, u, w);
  for (int k = 0; k < 3; k++) { root[k] = u[k]; root[3 + k] = v[k]; root[6 + k] = w[k]; }
  setLink9008(self, 0x183, root, mid2, bones, done);
  // spine (bone +0x187): from the chest to particle 1, across particles 5 -> 6
  ext_43e920(u, P9008(0x40), mid1);
  vnorm9008(u);
  ext_43e920(v, P9008(0x110), P9008(0x144));
  vnorm9008(v);
  ext_446ee0(w, v, u);
  vnorm9008(w);
  ext_446ee0(v, u, w);
  for (int k = 0; k < 3; k++) { spine[k] = u[k]; spine[3 + k] = v[k]; spine[6 + k] = w[k]; }
  setLink9008(self, 0x187, spine, mid1, bones, done);
  ext_4de420(spine2, spine);
  linkIx9008(self, 0x18b, bones, done);
  linkIx9008(self, 0x18f, bones, done);
  linkIx9008(self, 0x193, bones, done);
  linkIx9008(self, 0x197, bones, done);
  linkIx9008(self, 0x1a7, bones, done);
  // the arms: 3 -> 7 -> 11 and 2 -> 4 -> 10
  float a1[9], a2[9], a3[9], a4[9];
  limb9008(a1, P9008(0x178), P9008(0xa8), spine2 + 3, spine2 + 6, true, false);
  setLink9008(self, 0x19b, a1, P9008(0xa8), bones, done);
  limb9008(a2, P9008(0x248), P9008(0x178), a1, a1 + 3, false, true);
  setLink9008(self, 0x19f, a2, P9008(0x178), bones, done);
  limb9008(a3, P9008(0xdc), P9008(0x74), spine2 + 3, spine2 + 6, false, true);
  setLink9008(self, 0x1ab, a3, P9008(0x74), bones, done);
  limb9008(a4, P9008(0x214), P9008(0xdc), a3, a3 + 3, true, true);
  setLink9008(self, 0x1af, a4, P9008(0xdc), bones, done);
  // the legs: 9 -> 13 -> 15 and 8 -> 12 -> 14, the hips against the root turned half round (rows 0 and 1 negated)
  ext_4e0d00(root, -1.0f);
  ext_4e0d00(root + 3, -1.0f);
  float h1[9], l1[9], h2[9], l2[9];
  hip9008(h1, root, P9008(0x2b0), P9008(0x1e0), false);
  setLink9008(self, 0x1b7, h1, P9008(0x1e0), bones, done);
  limb9008(l1, P9008(0x318), P9008(0x2b0), h1, h1 + 6, false, false);
  setLink9008(self, 0x1bb, l1, P9008(0x2b0), bones, done);
  hip9008(h2, root, P9008(0x27c), P9008(0x1ac), true);
  setLink9008(self, 0x1c7, h2, P9008(0x1ac), bones, done);
  limb9008(l2, P9008(0x2e4), P9008(0x27c), h2, h2 + 6, false, false);
  setLink9008(self, 0x1cb, l2, P9008(0x27c), bones, done);
  // bone 0 = identity at 0; every bone not set yet follows its parent
  vcall<u8 *>(skel9008(), 0xc4, model9008(self));
  ext_4de7a0((float *)bones);
  ((u32 *)bones)[9] = 0;
  ((u32 *)bones)[10] = 0;
  ((u32 *)bones)[11] = 0;
  for (s32 i = 0; i < *(s32 *)(self + 0x26); i++) {
    if (done[i]) continue;
    linkTo9008(self, i, bones);
    done[i] = 1;
  }
}
PCREG(6421a0, handleCalcMats);
