// batch7474.cpp - area 73 batch 74 (tail-jump row, zero arguments): FUN_4f43d0.
#include "ff.h"

extern "C" void __attribute__((cdecl)) ext_634273(void *p, u32 size);
extern "C" void THISCALL ext_4ee440(u8 *self);

// 0x4f43d0 (GUESS FUN_4f43d0): vtable word 0x699664. A non-null pointer at this+0xac is deleted (size 1); the call then continues in
// 0x4ee440 on this (the call site pushes no arguments, so none here).
static void THISCALL guess4f43d0(u8 *self) {
  *(u32 *)self = 0x699664;
  void *p = *(void **)(self + 0xac);
  if (p)
    ext_634273(p, 1u);
  ext_4ee440(self);
}
PCREG(4f43d0, guess4f43d0);
