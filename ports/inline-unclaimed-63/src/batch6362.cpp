// batch6362.cpp - unclaimed-63 batch 62: 0x51be20 (GUESS FUN_51be20), thiscall, two stack arguments a and b, ret 8, returns eax.
//   If (u16)a == [this+0x207]: this->vtbl[+0x394](b) (thiscall, one argument, callee pops 4); return 0.
//   Otherwise: if (u16)a == [this+0x5d7]: [this+0x485] = b[+0x28], [this+0x489] = b[+0x2c], [this+0x48d] = b[+0x30].
//   Then tail-jump to 0x5122f0(a, b) (thiscall, two arguments, ret 8; ZMoveOnSpline::ClassCommand, other area's code, stubbed):
//   the port returns its eax.
#include "ff.h"

extern "C" u32 THISCALL ext_5122f0(void *self, u32 a, u32 b);   // thiscall, two arguments, ret 8, stubbed

typedef void(THISCALL * one_fn)(void *, u32);

// 0x51be20 (GUESS FUN_51be20).
static u32 THISCALL unnamed51be20(u8 *self, u32 a, u32 b) {
  if ((u16)a == *(u16 *)(self + 0x207)) {
    ((one_fn)(*(u32 *)(*(u32 *)self + 0x394)))((void *)self, b);
    return 0;
  }
  if ((u16)a == *(u16 *)(self + 0x5d7)) {
    *(u32 *)(self + 0x485) = *(u32 *)(b + 0x28);
    *(u32 *)(self + 0x489) = *(u32 *)(b + 0x2c);
    *(u32 *)(self + 0x48d) = *(u32 *)(b + 0x30);
  }
  return ext_5122f0((void *)self, a, b);
}
PCREG(51be20, unnamed51be20);
