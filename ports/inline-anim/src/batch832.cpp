// batch832.cpp - animation layer thread, batch 832: ZIKLNKOBJ IK bone queries. Each forwards to the bone modifier
// (ZIKLNKOBJ +0x6c), vt +0x10, which takes four stack arguments: the outputs, the bone id and the owner object (pushed
// by these functions as the last argument; the exe passes the object pointer through).
#include "ff.h"

#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

// ZIKLNKOBJ::GetIKBoneMat(int bone, float* out) const [high, GC-mapped]. A 16-byte scratch buffer is passed as the
// second argument (the exe leaves it uninitialised; the callee writes it).
static void THISCALL GetIKBoneMat(u8 *self, s32 bone, float *out) {
  float tmp[4];
  vcall<void>(FP(self, 0x6c), 0x10, out, tmp, bone, self);
}
PCREG(466830, GetIKBoneMat);

// ZIKLNKOBJ::GetIKBoneMatPos(int bone, float* mat, float* pos) const [high, GC-mapped].
static void THISCALL GetIKBoneMatPos(u8 *self, s32 bone, float *mat, float *pos) {
  vcall<void>(FP(self, 0x6c), 0x10, mat, pos, bone, self);
}
PCREG(466870, GetIKBoneMatPos);

// ZIKLNKOBJ::GetIKBonePos(int bone, float* pos) const [high, GC-mapped]: a 40-byte scratch buffer is passed first.
static void THISCALL GetIKBonePos(u8 *self, s32 bone, float *pos) {
  float tmp[10];
  vcall<void>(FP(self, 0x6c), 0x10, tmp, pos, bone, self);
}
PCREG(466890, GetIKBonePos);
