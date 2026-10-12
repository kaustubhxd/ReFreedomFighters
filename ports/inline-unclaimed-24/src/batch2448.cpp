// batch2448.cpp - decomp area 24, batch 2448 (gap band).
#include "ff.h"

extern "C" void THISCALL ext_43de40(void *self, u32 a0, u32 a1, u32 a2);  // ZSTDOBJ base constructor, ret 12
extern "C" void ext_634d22(void *dst, const void *src, u32 n);            // cdecl copy (recorder)

// 0x45ae10 (GUESS), thiscall, ret 12, eax = this: base constructor, then vtable 0x684068.
static u8 *THISCALL stdObjDerivedCtor45ae10(u8 *self, u32 a0, u32 a1, u32 a2) {
  ext_43de40(self, a0, a1, a2);
  *(u32 *)self = 0x684068u;
  return self;
}
PCREG(45ae10, stdObjDerivedCtor45ae10);

// 0x445180 (GUESS), thiscall, ret 4: the bytes of the argument are rearranged and stored at +0xa0.
static void THISCALL byteShuffleStore(u8 *self, u32 v) {
  u32 edx = (v >> 16) & 0xffu;
  u32 eax = (v & 0xffu) << 16;
  u32 ecx = v & 0xff00ff00u;
  *(u32 *)(self + 0xa0) = edx | eax | ecx;
}
PCREG(445180, byteShuffleStore);

// 0x45c080 ZBloodSplatters::NotifyMarkUV(unsigned int, const float*, unsigned int), thiscall, ret 12.
static void THISCALL bloodSplattersNotifyMarkUV(u8 *self, u32 idx, const void *ptr, u32 count) {
  u8 *dst = self + 0x508 + idx * 0x300u;
  ext_634d22(dst, ptr, count * 0x18u);
}
PCREG(45c080, bloodSplattersNotifyMarkUV);

// 0x45c0b0 ZBloodStains::NotifyMarkUV, thiscall, ret 12.
static void THISCALL bloodStainsNotifyMarkUV(u8 *self, u32 idx, const void *ptr, u32 count) {
  u8 *dst = self + 0x3fc + idx * 0x300u;
  ext_634d22(dst, ptr, count * 0x18u);
}
PCREG(45c0b0, bloodStainsNotifyMarkUV);
