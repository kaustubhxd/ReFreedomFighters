// batch816.cpp - unclaimed-08 batch 16: ZBoneModifyBase::UnfixParticle(int) (low name; PC body from the bytes).
// Residue 7 (core-todo). Thiscall, one stack argument, ret 4. Original: loads the pointer at this+0x291; when it is
// non-null, tail-jumps to 0x645100, which stores zero to dword (pointer + 4*index + 0x3f) and returns (the callee pops the
// argument). Nothing happens when the pointer is null.
#include "ff.h"

// 0x6475f0, ZBoneModifyBase::UnfixParticle(int).
static void THISCALL boneUnfixParticle(u8 *self, s32 index) {
  u8 *particle = *(u8 **)(self + 0x291);
  if (particle) *(u32 *)(particle + 4 * (u32)index + 0x3f) = 0;
}
PCREG(6475f0, boneUnfixParticle);
