// batch1017.cpp - unclaimed-10, batch 13 (docs/20-unclaimed-10.md): ZFFSimpleTrain2::CopyData(ZEventBase*) (0x5b8550),
// thiscall, one argument (the source), ret 4. Copies a fixed set of fields from the source into this, then the 36-byte block
// at +0xb7 (the base-class part) with 0x4de420, a plain copy routine (ecx = destination, edx = source, no stack use, ret).
// The copy routine is inlined here as nine dword copies: the same bytes as its two 16-byte moves and one dword.
#include "ff.h"

// 0x5b8550, ZFFSimpleTrain2::CopyData(ZEventBase*) (high)
static void THISCALL simpleTrain2CopyData(u8 *self, u8 *src) {
  *(u32 *)(self + 0x48) = *(u32 *)(src + 0x48);
  *(u32 *)(self + 0x50) = *(u32 *)(src + 0x50);
  *(u32 *)(self + 0x54) = *(u32 *)(src + 0x54);
  *(u32 *)(self + 0x58) = *(u32 *)(src + 0x58);
  *(u32 *)(self + 0x5c) = *(u32 *)(src + 0x5c);
  *(u32 *)(self + 0x7e) = *(u32 *)(src + 0x7e);
  *(u32 *)(self + 0x82) = *(u32 *)(src + 0x82);
  *(u32 *)(self + 0x86) = *(u32 *)(src + 0x86);
  *(u32 *)(self + 0xae) = *(u32 *)(src + 0xae);
  self[0xb2] = src[0xb2];
  *(u32 *)(self + 0xb3) = *(u32 *)(src + 0xb3);
  *(u16 *)(self + 0xdb) = *(u16 *)(src + 0xdb);
  self[0xdd] = src[0xdd];
  *(u32 *)(self + 0xde) = *(u32 *)(src + 0xde);
  *(u32 *)(self + 0xe2) = *(u32 *)(src + 0xe2);
  *(u32 *)(self + 0xe6) = *(u32 *)(src + 0xe6);
  *(u32 *)(self + 0xea) = *(u32 *)(src + 0xea);
  *(u32 *)(self + 0xee) = *(u32 *)(src + 0xee);
  *(u32 *)(self + 0xf2) = *(u32 *)(src + 0xf2);
  *(u32 *)(self + 0x8a) = *(u32 *)(src + 0x8a);
  *(u32 *)(self + 0x8e) = *(u32 *)(src + 0x8e);
  *(u32 *)(self + 0x92) = *(u32 *)(src + 0x92);
  *(u32 *)(self + 0x96) = *(u32 *)(src + 0x96);
  *(u32 *)(self + 0x9a) = *(u32 *)(src + 0x9a);
  *(u32 *)(self + 0x9e) = *(u32 *)(src + 0x9e);
  *(u32 *)(self + 0xa2) = *(u32 *)(src + 0xa2);
  *(u32 *)(self + 0xa6) = *(u32 *)(src + 0xa6);
  *(u32 *)(self + 0xaa) = *(u32 *)(src + 0xaa);
  // 0x4de420 (inlined): 36 bytes from src+0xb7 to self+0xb7.
  for (u32 i = 0; i < 0x24; i += 4) *(u32 *)(self + 0xb7 + i) = *(u32 *)(src + 0xb7 + i);
}
PCREG(5b8550, simpleTrain2CopyData);
