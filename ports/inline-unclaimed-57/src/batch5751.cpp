// batch5751.cpp - unclaimed-57, band batch 51 (name GUESS): 0x5d5790, thiscall, no args (the non-deleting destructor shape). vtable 0x6b5610 at
// this+0; sub = dword this+0x19; if sub: sub->vt[0](1) (thiscall, one argument; stubbed); delete(dword this+0x29, 1) (cdecl; hooked and logged);
// then tail-jump to 0x43de70(this) (thiscall, no args; original code). Written as a call followed by return: the callee takes no stack
// arguments, so the caller's stack is the same as after a tail jump.
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef void(THISCALL *Slot1)(u8 *self, u32 a);

extern "C" void ext_634273(u8 *p, u32 size);       // operator delete (cdecl), hooked and logged in the spec
extern "C" void THISCALL ext_43de70(u8 *self);    // base dtor, original code (no arguments)

static void THISCALL unnamed5d5790(u8 *self) {
  u8 *sub = *(u8 **)(self + 0x19);
  *(u32 *)self = 0x6b5610;
  if (sub != 0) ((Slot1)VT(sub)[0])(sub, 1);
  ext_634273((u8 *)(unsigned long)*(u32 *)(self + 0x29), 1);
  ext_43de70(self);
}
PCREG(5d5790, unnamed5d5790);
