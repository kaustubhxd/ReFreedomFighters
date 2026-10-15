// batch817.cpp - animation layer thread, batch 817: frame time, local IK bone, bone-chain FK, the global IK hook.
#include "ff.h"

#define F8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define F16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define F32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FF(p, o) (*(float *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

static double crtFmod(double a, double b) {
  double r;
  __asm__ volatile("fldl %1\n\tfldl %2\n\tcall *0x676358\n\tfstpl %0" : "=m"(r) : "m"(a), "m"(b) : "eax", "ecx", "edx", "memory", "cc");
  return r;
}

// ZAnimFilePack::GetFrameTime(bone anim, bool loop, float t) [medium, GameCube reference]: fmod(t, frames) when looping,
// else min(frames, t) (no clamp at 0 here, unlike the sampler). x87 float return.
static float THISCALL GetFrameTime(void *, u8 *ba, u8 loop, float t) {
  u32 n = F16(ba, 8);
  volatile float r;
  if (loop) r = (float)crtFmod((double)t, (double)(s32)n);
  else {
    float fn = (float)(s32)n;
    r = fn < t ? fn : t;
  }
  return r;
}
PCREG(4e59b0, GetFrameTime);

extern "C" void FASTCALL ext_4de440(float *out, const float *a, const float *b);   // mmmul
extern "C" void FASTCALL ext_43e920(float *d, const float *a, const float *b);     // PSVECSubtract d = a - b
extern "C" void FASTCALL ext_441a60(float *v, const float *m);                     // vmtmul
extern "C" void FASTCALL ext_4de4f0(float *m, const float *b);                     // (matrix by transposed matrix)
extern "C" void FASTCALL ext_4de1d0(float *q, const float *m);                     // mattoquat
extern "C" void FASTCALL ext_4df1e0(float *m, const float *q);                     // quattomat
extern "C" void FASTCALL ext_4de420(float *d, const float *s);                     // mcpy
extern "C" void FASTCALL ext_4de480(float *mat, const float *m);                   // mat = mat * m
extern "C" void FASTCALL ext_4419f0(float *v, const float *m);                     // vmmul
extern "C" void FASTCALL ext_441940(float *dst, const float *src);                 // PSVECAdd

// ZBoneModifyBase::SetLocalIKBone(ZBoneQuat* q, const ZBone* bones, const float* mats, const SBoneDefinition* defs,
// unsigned i, const float* target, const float* pos) const [high, GameCube reference]. thiscall (this unused) ret 0x1c.
// Turns a world-space bone transform (mats[i] * target, position pos) into the bone's local quaternion and
// position relative to its parent (defs[i] +0xc; ZBone and SBoneDefinition are 0x30 bytes, matrices 9 floats).
static void THISCALL SetLocalIKBone(void *, u8 *q, u8 *bones, float *mats, u8 *defs, u32 i, float *target, float *pos) {
  u8 *pb = bones + F32(defs + i * 0x30, 0xc) * 0x30;
  u8 *qi = q + i * 0x30;
  float M[9];
  ext_4de440(M, mats + i * 9, target);
  ext_43e920((float *)(qi + 0x24), pos, (float *)(pb + 0x24));
  ext_441a60((float *)(qi + 0x24), (float *)pb);
  ext_4de4f0(M, (float *)pb);
  ext_4de1d0((float *)qi, M);
}
PCREG(647430, SetLocalIKBone);

// ZBoneModifyBase::SolveBoneChain(ZBone* bones, int i, const ZBoneQuat* q, const SBoneDefinition* defs) const
// [medium, GameCube reference]. thiscall ret 0x10. Forward kinematics for one chain: local matrices for bone i and each
// parent up to (not including) the root, the root copied from q[0] as a matrix, then from the root down each bone
// becomes parent * local (rotation and position).
static void THISCALL SolveBoneChain(void *, u8 *bones, u32 i, u8 *q, u8 *defs) {
  u8 *stk[97];
  u32 n = 0;
  do {
    u8 *out = bones + i * 0x30, *src = q + i * 0x30;
    ext_4df1e0((float *)out, (float *)src);
    F32(out, 0x24) = F32(src, 0x24);
    F32(out, 0x28) = F32(src, 0x28);
    F32(out, 0x2c) = F32(src, 0x2c);
    stk[n++] = out;
    i = F32(defs + i * 0x30, 0xc);
  } while (i != 0);
  stk[n] = bones;
  ext_4de420((float *)bones, (float *)q);
  F32(bones, 0x24) = F32(q, 0x24);
  F32(bones, 0x28) = F32(q, 0x28);
  F32(bones, 0x2c) = F32(q, 0x2c);
  while (n) {
    u8 *par = stk[n];
    n--;
    u8 *ch = stk[n];
    ext_4de480((float *)ch, (float *)par);
    ext_4419f0((float *)(ch + 0x24), (float *)par);
    ext_441940((float *)(ch + 0x24), (float *)(par + 0x24));
  }
}
PCREG(6474f0, SolveBoneChain);

// ZBoneModifyBase::UpdateGlobalIK(ZBone* bones, unsigned geomId, ZLNKOBJ* obj) [medium, GameCube reference].
// With a ragdoll (+0x291): the ragdoll writes the bones (0x6421a0). Otherwise, when byte +4 is set, obj->vt[0x49c]()
// (single-row head look, see GetBonesFrames) is true, obj->vt[0x2fc]() is false and the object's name (vt 0x2e0) is
// not "Hitman2": bones 0xe and 0x12 of the file-bone map (vt 0xc8 of the definitions) are raised by [0x680a70] on
// their +0x2c (z) coordinate. A leftover from Hitman 2 (the name check is literal).
extern "C" void THISCALL ext_6421a0(void *rd, void *bones);
static void THISCALL UpdateGlobalIK(u8 *self, u8 *bones, u32 gid, void *obj) {
  void *rd = FP(self, 0x291);
  if (!rd) {
    if (F8(self, 0x295)) return;
    if (!F8(self, 4)) return;
    if (!vcall<bool>(obj, 0x49c)) return;
    if (vcall<bool>(obj, 0x2fc)) return;
    typedef int(__attribute__((cdecl)) * cmp_t)(const char *, const char *);
    if ((*(cmp_t *)0x676414)(vcall<const char *>(obj, 0x2e0), (const char *)0x6c29c8) == 0) return;
    u8 *m = vcall<u8 *>(FP(FP(G(void *, 0x70039c), 0x1aa3), 0x18), 0xc8, gid);
    u32 a = m[0xe], b = m[0x12];
    FF(bones + a * 0x30, 0x2c) = FF(bones + a * 0x30, 0x2c) + G(float, 0x680a70);
    FF(bones + b * 0x30, 0x2c) = FF(bones + b * 0x30, 0x2c) + G(float, 0x680a70);
    return;
  }
  ext_6421a0(rd, bones);
}
PCREG(647790, UpdateGlobalIK);
