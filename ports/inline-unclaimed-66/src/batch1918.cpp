// batch1918.cpp - unclaimed-66 batch 18: the base constructor 0x561020 (about 60 instructions, three calls). Thiscall, no
// arguments. Original order: 0x469870(this) (exe code, no arguments); +4 |= 0x20; +0x44 = 0; [this] = 0x6a62c0; +0xd8, +0xfc,
// +0x54 = 0; word +0x84 = 0; byte +0x88 = 0; +0x58, +0x5c = 0; byte +0x100 = 0; word +0x74 = the engine db's +0x114(0x6a64e0, 0,
// 0x6a64b4, 0x21); word +0x76 = the same slot (0x6a64f0, 0, 0x6a64b4, 0x22); +0x48, +0x4c, +0x50 = 0; +0x6c = 0x409fffff,
// +0x68 = 0x40c7ffff, +0x70 = 0x40a00000; word +0x86 = 0x100; word +0x89 = 0; +0x90, +0xf8, +0xf4 = 0.
// The engine db is *(*(0x70039c) + 0x9b). Not static: batch 1913 (0x57bd90) calls it.
#include "ff.h"

extern "C" void THISCALL ext_469870(void *);

void THISCALL baseCtor561020(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x6a62c0;
  *(u32 *)(self + 0xd8) = 0;
  *(u32 *)(self + 0xfc) = 0;
  *(u32 *)(self + 0x54) = 0;
  *(u16 *)(self + 0x84) = 0;
  self[0x88] = 0;
  *(u32 *)(self + 0x58) = 0;
  *(u32 *)(self + 0x5c) = 0;
  self[0x100] = 0;
  u8 *sys = *(u8 **)0x70039c;
  u8 *db = *(u8 **)(sys + 0x9b);
  *(u16 *)(self + 0x74) = (u16)vcall<u32>(db, 0x114, (u32)0x6a64e0, (u32)0, (u32)0x6a64b4, (u32)0x21);
  sys = *(u8 **)0x70039c;
  db = *(u8 **)(sys + 0x9b);
  *(u16 *)(self + 0x76) = (u16)vcall<u32>(db, 0x114, (u32)0x6a64f0, (u32)0, (u32)0x6a64b4, (u32)0x22);
  *(u32 *)(self + 0x48) = 0;
  *(u32 *)(self + 0x4c) = 0;
  *(u32 *)(self + 0x50) = 0;
  *(u32 *)(self + 0x6c) = 0x409fffff;
  *(u32 *)(self + 0x68) = 0x40c7ffff;
  *(u32 *)(self + 0x70) = 0x40a00000;
  *(u16 *)(self + 0x86) = 0x100;
  *(u16 *)(self + 0x89) = 0;
  *(u32 *)(self + 0x90) = 0;
  *(u32 *)(self + 0xf8) = 0;
  *(u32 *)(self + 0xf4) = 0;
}
PCREG(561020, baseCtor561020);
