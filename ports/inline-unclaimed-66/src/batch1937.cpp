// batch1937.cpp - unclaimed-66 batch 37 (gap band; GUESS name). Thiscall, no arguments. Original: [this] = 0x69e15c; CRT free([this+0x5c],
// 0x67) (0x634273, cdecl, hooked in the spec); for each object at [this+0x127], [this+0x12b], [this+0x1ed] that is non-null, its vtable slot 0
// is called with 1 (the callee pops it); then a tail jump to 0x43ea20 with ECX = this (the base destructor, exe code: a GUESS stub in the spec).
#include "ff.h"

extern "C" void ext_634273(void *ptr, u32 size);   // cdecl CRT free
extern "C" void THISCALL ext_43ea20(void *self);   // the base destructor (GUESS stub in the spec)

// 0x512070, GUESS FUN_00512070.
static void THISCALL baseDtorStep(u8 *self) {
  *(u32 *)self = 0x69e15c;
  ext_634273(*(void **)(self + 0x5c), 0x67);
  u8 *a = *(u8 **)(self + 0x127);
  if (a) vcall<void>(a, 0, (u32)1);
  u8 *b = *(u8 **)(self + 0x12b);
  if (b) vcall<void>(b, 0, (u32)1);
  u8 *c = *(u8 **)(self + 0x1ed);
  if (c) vcall<void>(c, 0, (u32)1);
  ext_43ea20(self);
}
PCREG(512070, baseDtorStep);
