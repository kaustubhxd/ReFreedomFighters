// batch213.cpp - unclaimed area 21 (docs/20-unclaimed-21.md), piece of the 0x5a76c0 group. A helper that copies a struct
// from its first argument into a sub-object, copies three dwords from its second argument, then sets a flag byte. Name GUESS.
#include "ff.h"

extern "C" void FASTCALL ext_4de420(u8 *dst, u8 *src);   // original struct copy 0x24 bytes src -> dst, fastcall (ecx, edx); runs as exe code

// 0x5ec5c0, thiscall(a, b) (ret 8): ext_4de420(ecx = this + 4, edx = a) copies 0x24 bytes from a to this+4;
// [this+0x28..0x30] = b[0..2]; [this+0x34] = 1 (byte). Name GUESS.
static void THISCALL copyVec3Flag_5ec5c0(u8 *self, u32 a, u32 *b) {
  ext_4de420(self + 4, (u8 *)a);
  *(u32 *)(self + 0x28) = b[0];
  *(u32 *)(self + 0x2c) = b[1];
  *(u32 *)(self + 0x30) = b[2];
  *(u8 *)(self + 0x34) = 1;
}
PCREG(5ec5c0, copyVec3Flag_5ec5c0);
