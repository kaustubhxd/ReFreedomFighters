#include "ff.h"
// batch2746.cpp - unclaimed-27 batch 48 (residue 6). CareTaker function, 108 bytes. GUESS name.
// 0x5bbfe0: thiscall, one stack argument (passed as this to 0x4e5e60), ret 4. Same tail as batch 47, plus a byte store.
extern "C" u32 THISCALL ext_4e5e60(u8 *self);

static void THISCALL funcCareTaker5bbfe0(u8 *self, u8 *arg) {
  *(u32 *)(self + 0x51) = ext_4e5e60(arg);
  *(u32 *)(self + 0x55) = ext_4e5e60(arg);
  *(u32 *)(self + 0x59) = ext_4e5e60(arg);
  u8 *g9 = (u8 *)(unsigned long)*(u32 *)(G(u32, 0x70039c) + 0x9b);
  typedef u8 *(THISCALL *F138)(u8 *);
  u8 *res1 = (*(F138 **)g9)[0x138 / 4](g9);
  u8 *g9b = (u8 *)(unsigned long)*(u32 *)(G(u32, 0x70039c) + 0x9b);
  u32 *vt1 = *(u32 **)res1;
  typedef u32(THISCALL * F4c)(u8 *, u32, u32);
  u32 r = (*(F4c **)g9b)[0x4c / 4](g9b, *(u32 *)(self + 0x44), 0x10);
  typedef void(THISCALL * F60)(u8 *, u32, u32);
  ((F60)vt1[0x60 / 4])(res1, 0x6b2cd8, r);
  *(u8 *)(self + 0x4c) = 0;
}
PCREG(5bbfe0, funcCareTaker5bbfe0);
