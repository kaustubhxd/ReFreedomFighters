// batch201.cpp - unclaimed area 20 (docs/20-unclaimed-20.md), slice floor(addr/16) mod 20 == 19. Plain leaves with no
// calls: a masked flag update, a two-dword reset, a 3-dword copy with a flag, and an empty stub.
#include "ff.h"

// 0x441870, thiscall(set, clear): [this+0x30] = ([this+0x30] & ~clear) | set. Name GUESS (flag setter).
static void THISCALL setMaskedFlags_441870(u8 *self, u32 set, u32 clear) {
  *(u32 *)(self + 0x30) = (*(u32 *)(self + 0x30) & ~clear) | set;
}
PCREG(441870, setMaskedFlags_441870);

// 0x4cf170, stdcall(p): p[0] = 0, p[1] = -1. Name GUESS (two-field reset).
static void STDCALL resetPair_4cf170(u32 *p) {
  p[1] = 0xffffffffu;
  p[0] = 0;
}
PCREG(4cf170, resetPair_4cf170);

// 0x4dcd70, thiscall(src): copy three dwords from src to [this+0x24..0x2c], then set bit 0x100000 in [this+0x3c].
// Name GUESS (copy of a 3-vector into the object).
static void THISCALL copyVec3Flag_4dcd70(u8 *self, u32 *src) {
  *(u32 *)(self + 0x24) = src[0];
  *(u32 *)(self + 0x28) = src[1];
  *(u32 *)(self + 0x2c) = src[2];
  *(u32 *)(self + 0x3c) |= 0x100000u;
}
PCREG(4dcd70, copyVec3Flag_4dcd70);


// 0x65f530, stdcall with 24 bytes of arguments (ret 0x18), empty body. Name GUESS (no-op hook).
static void STDCALL noop6_65f530(u32, u32, u32, u32, u32, u32) {}
PCREG(65f530, noop6_65f530);
