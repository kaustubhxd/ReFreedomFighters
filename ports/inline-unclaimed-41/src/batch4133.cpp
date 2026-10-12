// batch4133.cpp - unclaimed-41 batch 33 (core-todo residue-19): 0x4edcb0 ZCollisionBase::LoadInternColiTree(char*) (thiscall, one stack
// argument buf, ret 4; returns buf + size, where size is the first dword of buf). The octree constructor 0x4e3d60 is the stub from the
// batch 30 spec pattern (GUESS).
#include "ff.h"

extern "C" void THISCALL ext_4e3d60(u8 *self, u8 *s);   // octree constructor, one stack argument, callee pops (checksum stub, GUESS)

static u8 *THISCALL fn4edcb0(u8 *ecxUnused, u8 *buf) {
  (void)ecxUnused;
  u32 size = *(u32 *)buf;
  *(u32 *)(buf + 4) = 0x67d138u;
  ext_4e3d60(buf + 4, buf + 0x20);
  return buf + size;
}
PCREG(4edcb0, fn4edcb0);
