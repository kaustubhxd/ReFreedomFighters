// batch239.cpp - ZFFHERO small getters (inline-ladder thread, 2026-10-11).
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

// 0x591f30 ZFFHERO::GetMoveSpeeds(float *out) const [GC 80084f24, high], thiscall, ret 4: out = the three dwords at
// +0x65d, +0x661, +0x665 (the hero's move speed triple, packed offsets).
static void THISCALL heroGetMoveSpeeds(u8 *self, u32 *out) {
  out[0] = U32(self, 0x65d);
  out[1] = U32(self, 0x661);
  out[2] = U32(self, 0x665);
}
PCREG(591f30, heroGetMoveSpeeds);

// 0x483f00 ZFFHERO::GetCrouch() const [GC 80084ef8, low], thiscall, no args, returns AL = bit 10 of the input word +0x417.
static u32 THISCALL heroGetCrouch(u8 *self) { return (U32(self, 0x417) >> 10) & 1; }
PCREG(483f00, heroGetCrouch);
