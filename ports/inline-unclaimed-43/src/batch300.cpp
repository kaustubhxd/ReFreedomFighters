// batch300.cpp - ZLNKOBJ::GetDefaultBones(ZBone *out) const (area 43, residue 2, 2026-10-12). GameCube reference (name map, high).
// 0x4630e0, thiscall (this = ECX, out on the stack), ret 4. Frame is EBP-relative in the exe.
// Callees (all original exe code, register arguments only, no stack arguments):
//   0x4de7a0 mreset(float *mat) (identity), 0x4df1e0 quattomat(mat, quat), 0x4de480 (mat, parent) matrix product,
//   0x4419f0 vmmul(vec, mat), 0x441940 PSVECAdd(dst, src).
// Vtable slots of this (thiscall): 0x2b4(2) returns the bone index n, 0x2cc returns r1 (parent table, 0x30 stride,
// parent index at +0xc), 0x2c8 returns r2 (offset table, 0x30 stride, translation at +0x24).
// Object fields: +0x1c skeleton (0x18-byte records; signed bytes at +0x20..+0x23 are the quaternion, +8..+0xa the
// root offset of bone n), +0x20 bone count.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" void FASTCALL ext_4de7a0(float *mat);                        // mreset (ecx = mat)
extern "C" void FASTCALL ext_4df1e0(float *mat, const float *quat);     // quattomat (ecx = mat, edx = quat)
extern "C" void FASTCALL ext_4de480(float *mat, const float *parent);   // matrix product (ecx = mat, edx = parent)
extern "C" void FASTCALL ext_4419f0(float *vec, const float *mat);      // vmmul (ecx = vec, edx = mat)
extern "C" void FASTCALL ext_441940(float *dst, const float *src);      // PSVECAdd (ecx = dst, edx = src)

static void THISCALL boneGetDefaultBones(u8 *self, u8 *out) {
  ext_4de7a0((float *)out);
  float *t0 = (float *)(out + 0x24);
  t0[0] = 0.0f;
  t0[1] = 0.0f;
  t0[2] = 0.0f;

  u32 n = vcall<u32>(self, 0x2b4, 2u);
  u8 *skel = (u8 *)U32(self, 0x1c);
  float *tn = (float *)(out + 0x30 * n + 0x24);
  tn[0] = 2.0f * (float)(s8)skel[8];
  tn[1] = 2.0f * (float)(s8)skel[9];
  tn[2] = 2.0f * (float)(s8)skel[0xa];

  u8 *r1 = vcall<u8 *>(self, 0x2cc);
  u8 *r2 = vcall<u8 *>(self, 0x2c8);

  if (U32(self, 0x20) == 1)
    return;

  u8 *rec = skel;
  u32 i = 1;
  do {
    float q[4];
    for (int k = 0; k < 4; k++)
      q[k] = (float)(s8)rec[0x20 + k] / 112.0f;
    float *mat = (float *)(out + 0x30 * i);
    ext_4df1e0(mat, q);

    u32 parent = U32(r1, 0xc + 0x30 * i);
    float *pm = (float *)(out + 0x30 * parent);
    ext_4de480(mat, pm);

    if (i != 1) {
      float *vec = (float *)(out + 0x24 + 0x30 * i);
      float *src = (float *)(r2 + 0x24 + 0x30 * i);
      vec[0] = src[0];
      vec[1] = src[1];
      vec[2] = src[2];
      ext_4419f0(vec, pm);
      ext_441940(vec, (float *)((u8 *)pm + 0x24));
    }
    rec += 0x18;
    i++;
  } while (i != U32(self, 0x20));
}
PCREG(4630e0, boneGetDefaultBones);
