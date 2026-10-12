// batch393.cpp - 0x489160 (core, thiscall, no arguments). Calls 0x488bc0 (exe, thiscall, no arguments; hooked by address in
// the spec, GUESS: body not ported), then vtable slot 0x58 with 0x68d410; stores the returned dword at this+0x391; then
// vtable slot 0x54 with the address this+0x391 as its one argument.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" void THISCALL ext_488bc0(void *self);   // callee by address (hooked in the spec)

static void THISCALL initFieldAt391(u8 *self) {
  ext_488bc0(self);
  u32 r = vcall<u32>((void *)self, 0x58, 0x68d410u);
  U32(self, 0x391) = r;
  vcall<void>((void *)self, 0x54, (u32)(unsigned long)(self + 0x391));
}
PCREG(489160, initFieldAt391);
