// batch2509.cpp - decomp area 24, batch 2509. 0x575970 (GUESS UI object refresh), thiscall(a, b), ret 8.
// The "uncontrolled push ecx" is not observable: the pushed slot is addressed by `mov ecx, esp` and overwritten with 0 two
// instructions later, so the vcall at slot 0x350 receives (2, 0, [this+0x44]) and the register value never matters.
#include "ff.h"

extern "C" void THISCALL ext_574280(void *self, u32 a, u32 b);   // thiscall, 2 args, callee pops 8
extern "C" void THISCALL ext_5738c0(void *self, u32 v);          // thiscall, 1 arg, callee pops 4

static void THISCALL uiRefresh(u8 *self, u32 a, u32 b) {
  ext_574280(self, a, b);
  ext_5738c0(self, *(u32 *)(self + 0x1b8));
  void *o = *(void **)(self + 0x20e);
  typedef void(THISCALL * f1)(void *, u32);
  (*(f1 **)o)[0xbc / 4](o, 1);
  typedef void *(THISCALL * f0)(void *);
  void *t = (*(f0 **)self)[0x84 / 4](self);
  typedef void(THISCALL * f3)(void *, u32, u32, u32);
  (*(f3 **)t)[0x350 / 4](t, 2, 0, *(u32 *)(self + 0x44));
  if ((u8)b) *(u32 *)(self + 0x20a) = 0;
}
PCREG(575970, uiRefresh);
