// batch34129.cpp - cascade tier E, batch 34129: 0x5eee70 (set up a two-control dialog row).
#include "ff.h"

extern "C" void THISCALL ext_5eecd0(void *self);
extern "C" void THISCALL ext_5edc60(void *self, u32 a);
extern "C" void THISCALL ext_5edb00(void *self, u32 a);
extern "C" void THISCALL ext_5aba60(void *self, u32 a, u32 b, u32 c, u32 d);
extern "C" void THISCALL ext_5ac940(void *self, u32 a);
extern "C" void THISCALL ext_5ac5d0(void *self, u32 a);
extern "C" void THISCALL ext_5acac0(void *self, u32 a);

// 0x5eee70, thiscall(a, b, c, d) ret 0x10: runs 0x5eecd0, calls slot 0x14 of the objects at this+4 (a, 0, 0, 0x66, 0x40) and this+8 (b, 0, 0, 0, 0), then 0x5edc60(0x66) and 0x5edb00(0x40) on this+8,
// 0x5aba60(c, d, 0, 0), 0x5ac940(0x6b81a4), 0x5ac5d0(-1) on this+0xc, clears byte +0x35 of this+4 and this+8, finally 0x5acac0(0) on this+0xc.
static void THISCALL fn5eee70(u8 *self, u32 a, u32 b, u32 c, u32 d) {
  ext_5eecd0(self);
  u8 *o4 = *(u8 **)(self + 4);
  vcall<void>(o4, 0x14, a, 0u, 0u, 0x66u, 0x40u);
  u8 *o8 = *(u8 **)(self + 8);
  vcall<void>(o8, 0x14, b, 0u, 0u, 0u, 0u);
  ext_5edc60(*(u8 **)(self + 8), 0x66);
  ext_5edb00(*(u8 **)(self + 8), 0x40);
  ext_5aba60(*(u8 **)(self + 0xc), c, d, 0, 0);
  ext_5ac940(*(u8 **)(self + 0xc), 0x6b81a4);
  ext_5ac5d0(*(u8 **)(self + 0xc), (u32)-1);
  (*(u8 **)(self + 4))[0x35] = 0;
  (*(u8 **)(self + 8))[0x35] = 0;
  ext_5acac0(*(u8 **)(self + 0xc), 0);
}
PCREG(5eee70, fn5eee70);
