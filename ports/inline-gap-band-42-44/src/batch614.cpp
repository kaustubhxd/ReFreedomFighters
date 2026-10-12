// batch614.cpp - band 0x421000-0x441000, batch 614: three byte stores and one LCG.
//   0x42cc20 ZSysInterface::FollowRealtime(bool) (thiscall, ret 4): byte [this+0x1b5c] = low byte of the argument.
//   0x4335d0 (thiscall, ret 4): byte [this+0x100] = low byte of the argument (no name in the map).
//   0x43d950 (named ZHapticsBase::GetEffectID(const char *) in the map, but the body only stores): byte [this+0x90] = low byte
//     of the argument, returns nothing (the name in the map is not what the code does).
//   0x42ee50 ZSysInterface::Rand(char *, int) (thiscall, ret 8): x = dword [this+0x1b49] * 0x10dcd + 1, stored back;
//     returns (x >> 8) & 0x7fff with an arithmetic shift. Both arguments are ignored.
#include "ff.h"

static void THISCALL followRealtime(u8 *self, u32 a) {
  *(u8 *)(self + 0x1b5c) = (u8)a;
}
PCREG(42cc20, followRealtime);

static void THISCALL setByte100(u8 *self, u32 a) {
  *(u8 *)(self + 0x100) = (u8)a;
}
PCREG(4335d0, setByte100);

static void THISCALL setByte90(u8 *self, u32 a) {
  *(u8 *)(self + 0x90) = (u8)a;
}
PCREG(43d950, setByte90);

static u32 THISCALL randNext(u8 *self, u32 a, u32 b) {
  (void)a;
  (void)b;
  u32 x = *(u32 *)(self + 0x1b49) * 0x10dcdu + 1u;
  *(u32 *)(self + 0x1b49) = x;
  return ((u32)((s32)x >> 8)) & 0x7fffu;
}
PCREG(42ee50, randNext);
