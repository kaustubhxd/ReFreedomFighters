// batch2611.cpp - wider batch 2611. 0x5cabb0 (GUESS destructor body), thiscall, no args, plain ret, SEH frame (plain C++: the frame pushes ESI then the cookie
// slot and never ECX, so the epilogue's `pop ecx` takes the cookie slot and `pop esi` restores ESI). Sets vtable 0x6b4be8; slot 0x1a8 of the engine
// object (arg: the pointer at +0x5a8); when that pointer is non-null its slot 0 is called with 1 (deleting dtor); then the base destructor body 0x4f6b20.
#include "ff.h"

extern "C" void THISCALL ext_4f6b20(u8 *self);
typedef void(THISCALL *v1_t)(void *, u32);

static void THISCALL guessDtor5cabb0(u8 *self) {
  u32 m = *(u32 *)(self + 0x5a8);
  *(u32 *)self = 0x6b4be8;
  void *sys = *(void **)0x70039c;
  (*(v1_t **)sys)[0x1a8 / 4](sys, m);
  void *o = *(void **)(self + 0x5a8);
  if (o) (*(v1_t **)o)[0](o, 1);
  ext_4f6b20(self);
}
PCREG(5cabb0, guessDtor5cabb0);
