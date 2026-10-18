// batch818.cpp - animation layer thread, batch 818: head aim IK (ZBoneModifyBase::UpdateLocalIK) and safe acos.
#include "ff.h"

#define F8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define F32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FF(p, o) (*(float *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

// 0x477620 SafeAcos(float) (no GC name; stdcall, x87 return): 0 above 1, pi below -1, else acos.
static float STDCALL SafeAcos(float x) {
  volatile float r;
  if (x > 1.0f) return 0.0f;
  if (-1.0f > x) return bitsf(0x40490fdb);
  r = (float)crt::acos((double)x);
  return r;
}
PCREG(477620, SafeAcos);

extern "C" float FASTCALL ext_44c840(float *v);                                    // vnorm (in place, ST0)
extern "C" void FASTCALL ext_441a60(float *v, const float *m);                     // vmtmul
extern "C" float STDCALL ext_477620(float x);                                      // SafeAcos (above)
extern "C" void FASTCALL ext_4e0d00(float *v, float s);                            // vscalar (in place)
extern "C" void FASTCALL ext_4df1e0(float *m, const float *q);                     // quattomat
extern "C" void FASTCALL ext_4dec90(float *m, const float *euler);                 // (rotate matrix by angles)
extern "C" void FASTCALL ext_4de1d0(float *q, const float *m);                     // mattoquat
extern "C" void THISCALL ext_6474f0(void *self, void *bones, u32 i, void *q, void *defs);   // SolveBoneChain
extern "C" void FASTCALL ext_4dfd10(float *d, const float *s);                     // tmat
extern "C" void FASTCALL ext_4de480(float *mat, const float *m);                   // mat = mat * m
extern "C" void FASTCALL ext_43e920(float *d, const float *a, const float *b);     // PSVECSubtract d = a - b
extern "C" void FASTCALL ext_4e0130(float *out, const float *a, const float *b, float t);   // vangpul
extern "C" void FASTCALL ext_446ee0(float *d, const float *a, const float *b);     // vcross
extern "C" float FASTCALL ext_44e630(float *d, const float *s);                    // vnorm(d, s)
extern "C" void FASTCALL ext_4e1f00(float *v, float *out, float a, float b, float c, float d);   // DVFitElip
extern "C" void FASTCALL ext_4419f0(float *v, const float *m);                     // vmmul
extern "C" void FASTCALL ext_4de520(float *out, const float *a, const float *b, float t);   // mpul
extern "C" void THISCALL ext_647430(void *self, void *q, void *bones, float *mats, void *defs, u32 i, float *t, float *p);

static inline void *defs() { return FP(FP(G(void *, 0x70039c), 0x1aa3), 0x18); }

// ZBoneModifyBase::UpdateLocalIK(ZBoneQuat* q, unsigned geomId, ZLNKOBJ* obj) [high, GC 80221b98]. thiscall ret 0xc.
// Head aim. Fields (PC): +4 byte "full body" (torso twist + elliptical head limits in head space), +0x22d head IK
// weight, +0x231 target (x, y, z), +0x23d / +0x24d copies of +0x22d / +0x251 (read by GetBonesFrames next frame),
// +0x241 smoothed look direction, +0x251 head-look weight. File-bone map (defs vt 0xc8) slots: 0xc torso, 0x16
// neck(?), 0x17 head. Steps:
//  1. head-look weight set and obj->vt[0x49c]() (single-row head-look): bone 1 rotation taken from defs vt 0xb8.
//  2. Copy the weights; weight 0 -> clear the smoothed direction and stop.
//  3. With +4 and head-look weight 0: twist the torso bone toward the target (yaw from acos of the
//     target direction in root space, scaled 0.15 or 0.35 by flag 0x400 of obj+0x417, times the weight).
//  4. Solve the head chain (SolveBoneChain into a local bone buffer), direction head -> target, normalised on the
//     x87, turned toward it from the smoothed direction at 4 pi rad/s (vangpul with frame time [0x70039c]+0x48),
//     kept in +0x241.
//  5. Limit the direction to an elliptical cone (DVFitElip 70/60/70/40 degrees; in neck space with +4, where the
//     weight also fades out as the neck's up-axis y drops below 0.4), build a look matrix (cross products with up),
//     blend it with the current head matrix by the weight (mpul) unless the weight is exactly 1, and write the head
//     bone back as a local quaternion (SetLocalIKBone). The head IK weight is then cleared.
// The exe's x87 normalise (fsqrt with the FPU's precision setting) is reproduced with long double.
static void THISCALL UpdateLocalIK(u8 *self, u8 *q, u32 gid, void *obj) {
  if (!(FF(self, 0x251) == 0.0f)) {
    if (vcall<bool>(obj, 0x49c)) {
      u8 *r3 = vcall<u8 *>(defs(), 0xb8, gid);
      F32(q, 0x30) = F32(r3, 0x1c);
      F32(q, 0x34) = F32(r3, 0x20);
      F32(q, 0x38) = F32(r3, 0x24);
      F32(q, 0x3c) = F32(r3, 0x28);
    }
  }
  float w = FF(self, 0x22d);
  F32(self, 0x24d) = F32(self, 0x251);
  FF(self, 0x23d) = w;
  if (w == 0.0f) {
    F32(self, 0x241) = 0;
    F32(self, 0x245) = 0;
    F32(self, 0x249) = 0;
    F32(self, 0x251) = 0;
    return;
  }
  u8 *map = vcall<u8 *>(defs(), 0xc8, gid);
  if (F8(self, 4) && FF(self, 0x251) == G(float, 0x6785d0)) {
    float V[3];
    V[0] = FF(self, 0x231);
    u32 ti = map[0xc];
    V[2] = FF(self, 0x239);
    V[1] = 0.0f;
    ext_44c840(V);
    ext_441a60(V, (float *)q);
    float a;
    if (F32(obj, 0x417) & 0x400) a = (float)((long double)ext_477620(-V[2]) * (long double)G(float, 0x67af1c));
    else a = (float)((long double)ext_477620(-V[2]) * (long double)G(float, 0x68d438));
    if (V[0] > 0.0f) a = -a;
    float y = V[1], ang;
    if (y > 1.0f) ang = 0.0f;
    else if (-1.0f > y) ang = bitsf(0x40490fdb);
    else ang = (float)crt::acos((double)y);
    float E[3];
    E[0] = -a;
    E[2] = 0.0f;
    E[1] = (ang - G(float, 0x683770)) * 0.0f;
    ext_4e0d00(E, FF(self, 0x22d));
    float M[9];
    u8 *tq = q + ti * 0x30;
    ext_4df1e0(M, (float *)tq);
    ext_4dec90(M, E);
    ext_4de1d0((float *)tq, M);
  }
  u8 *bdefs = vcall<u8 *>(obj, 0x2cc);
  float *mats = vcall<float *>(defs(), 0xc0, gid);
  u32 hb = map[0x17];
  u8 B[0x1200];
  ext_6474f0(self, B, hb, q, bdefs);
  float P[3] = {FF(B + hb * 0x30, 0x24), FF(B + hb * 0x30, 0x28), FF(B + hb * 0x30, 0x2c)};
  float M[12];   // M[0..8] matrix, followed directly by D (the exe's locals are adjacent)
  float *D = M + 9;
  float Mt[9];
  ext_4dfd10(M, (float *)(B + hb * 0x30));
  ext_4de480(M, mats + hb * 9);
  ext_4dfd10(Mt, M);
  ext_43e920(D, (float *)(self + 0x231), P);
  if (!(D[0] == 0.0f) || !(D[1] == 0.0f) || !(D[2] == 0.0f)) {
    long double one = 1.0f;
    long double len = fsqrt_x87(((long double)D[0] * D[0] + (long double)D[1] * D[1]) + (long double)D[2] * D[2]);
    long double inv = one / len;
    D[0] = (float)(D[0] * inv);
    D[1] = (float)(D[1] * inv);
    D[2] = (float)(D[2] * inv);
  }
  float *S = (float *)(self + 0x241);
  if (!(S[0] == 0.0f) || !(S[1] == 0.0f) || !(S[2] == 0.0f))
    ext_4e0130(D, S, D, FF(G(u8 *, 0x70039c), 0x48) * G(float, 0x6c2abc));
  float d2 = D[2];
  S[0] = D[0];
  S[1] = D[1];
  S[2] = d2;
  float z;
  if (F8(self, 4)) {
    u32 nb = map[0x16];
    float M2[9];
    ext_4dfd10(M2, (float *)(B + nb * 0x30));
    ext_4de480(M2, mats + nb * 9);
    ext_4dfd10(M, M2);
    if (G(float, 0x67c19c) > M[1]) {
      float x = M[1] - G(float, 0x67c194);
      float m = 0.0f > x ? 0.0f : x;
      FF(self, 0x22d) = m / G(float, 0x67c194) * FF(self, 0x22d);
    }
    M[3] = 0.0f;   // the middle row becomes "up" (0, 1, 0)
    M[4] = 1.0f;
    M[5] = 0.0f;
    ext_446ee0(M, M + 6, M + 3);
    ext_44e630(M + 6, M);
    ext_446ee0(M, M + 6, M + 3);
    ext_441a60(D, M);
    float v = -D[2];
    if (0.0f > v) v = -v;
    D[2] = v;
    ext_4e1f00(D, 0, bitsf(0x3f9c61ab), bitsf(0x3f860a92), bitsf(0x3f9c61ab), bitsf(0x3f32b8c3));
    D[2] = -D[2];
    ext_4419f0(D, M);
    z = D[2];
  } else {
    float v = -d2;
    if (0.0f > v) v = -v;
    D[2] = v;
    ext_4e1f00(D, 0, bitsf(0x3f9c61ab), bitsf(0x3f860a92), bitsf(0x3f9c61ab), bitsf(0x3f32b8c3));
    z = -D[2];
    D[2] = z;
  }
  float R[9];   // rows: U (built from up), side, look
  R[6] = D[0];
  R[7] = D[1];
  R[8] = z;
  R[0] = 0.0f;
  R[1] = 1.0f;
  R[2] = 0.0f;
  ext_446ee0(R + 3, R, R + 6);
  ext_44c840(R + 3);
  ext_446ee0(R, R + 6, R + 3);
  float *T;
  float Tb[9];
  if (FF(self, 0x22d) == 1.0f) T = R;
  else {
    ext_4de520(Tb, Mt, R, FF(self, 0x22d));
    T = Tb;
  }
  ext_647430(self, q, B, mats, bdefs, hb, T, P);
  F32(self, 0x22d) = 0;
  F32(self, 0x251) = 0;
}
PCREG(647870, UpdateLocalIK);
