// batch4143.cpp - unclaimed-41 batch 43 (core-todo residue-19): 0x4e6d70 ZRunParamAnim::Create(CHUNKFILE*, bool, float) (thiscall, three
// stack arguments cf, b, f; ret 0xc; returns al = 1). When 0.0 > f the error hook 0x7003b0 is called (a zero hook traps in the exe). The
// byte b is stored at this+0xbc and f at this+0xb8; then this.vt[0x8](cf) (the callee pops it; the port passes one argument).
#include "ff.h"

typedef u32(THISCALL * f1_t)(u8 *, u32);

static u32 vslot(u8 *o, u32 off) {
  return *(u32 *)(*(u8 **)o + off);
}

static u8 THISCALL fn4e6d70(u8 *self, u8 *cf, u32 b, float f) {
  if (0.0f > f) {
    void (*hook)(void) = (void (*)(void))G(u32, 0x7003b0);
    hook();
  }
  *(u8 *)(self + 0xbc) = (u8)b;
  *(float *)(self + 0xb8) = f;
  ((f1_t)vslot(self, 0x8))(self, (u32)cf);
  return 1;
}
PCREG(4e6d70, fn4e6d70);
