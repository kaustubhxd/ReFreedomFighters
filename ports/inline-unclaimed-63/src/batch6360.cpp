// batch6360.cpp - unclaimed-63 batch 60: 0x577e20 ZObjectives::OnKeyPress(unsigned int) (core list name), thiscall, one stack argument
//   key, ret 4. If key == 0x102 or 0x103: o = this->vtbl[+0x84]() (thiscall); o->vtbl[+0x300]() (thiscall, no arguments); return al = 0.
//   Otherwise the original stores key over its argument and tail-jumps to 0x574250 (thiscall, one argument, ret 4; other area's code,
//   stubbed): the port calls it with the key and lets its own ret 4 pop the incoming argument.
#include "ff.h"

extern "C" void THISCALL ext_574250(void *self, u32 key);   // thiscall, one argument, ret 4, stubbed

typedef u32(THISCALL * q0_fn)(void *);

// 0x577e20.
static void THISCALL unnamed577e20(u8 *self, u32 key) {
  if (key == 0x102u || key == 0x103u) {
    u32 o = ((q0_fn)(*(u32 *)(*(u32 *)self + 0x84)))((void *)self);
    ((q0_fn)(*(u32 *)(*(u32 *)o + 0x300)))((void *)o);
    return;
  }
  ext_574250((void *)self, key);
}
PCREG(577e20, unnamed577e20);
