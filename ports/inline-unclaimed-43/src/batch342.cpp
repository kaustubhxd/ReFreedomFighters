// batch342.cpp - 0x41edd0 (gap band). Forwarder: ecx = dword [this+0x31], then jmp 0x4d0580 (exe getter: eax = dword [ecx+0x213]).
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" u32 THISCALL ext_4d0580(u8 *self);   // getter: dword at +0x213 (no stack arguments)

static u32 THISCALL forwardGet213(u8 *self) {
  return ext_4d0580((u8 *)(unsigned long)U32(self, 0x31));
}
PCREG(41edd0, forwardGet213);
