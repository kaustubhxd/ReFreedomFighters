#include "ff.h"
// batch2745.cpp - unclaimed-27 batch 47 (residue 6). CareTaker function, 93 bytes. GUESS name.
// 0x5bc620: thiscall, two stack arguments (the first, [ebp+8], is unused; the second, [ebp+0xc], is passed as this to
// 0x4e5e60), ret 8.
extern "C" u32 THISCALL ext_4e5e60(u8 *self);

static void THISCALL funcCareTaker5bc620(u8 *self, u32 unused, u8 *arg) {
  (void)unused;
  *(u32 *)(self + 0x56) = ext_4e5e60(arg);
  *(u32 *)(self + 0x52) = ext_4e5e60(arg);
  u8 *g9 = (u8 *)(unsigned long)*(u32 *)(G(u32, 0x70039c) + 0x9b);
  typedef u8 *(THISCALL *F138)(u8 *);
  u8 *res1 = (*(F138 **)g9)[0x138 / 4](g9);
  u8 *g9b = (u8 *)(unsigned long)*(u32 *)(G(u32, 0x70039c) + 0x9b);
  u32 *vt1 = *(u32 **)res1;
  typedef u32(THISCALL * F4c)(u8 *, u32, u32);
  u32 r = (*(F4c **)g9b)[0x4c / 4](g9b, *(u32 *)(self + 0x44), 0x10);
  typedef void(THISCALL * F60)(u8 *, u32, u32);
  ((F60)vt1[0x60 / 4])(res1, 0x6b2cd8, r);
}
PCREG(5bc620, funcCareTaker5bc620);
