// batch343.cpp - 0x41f680 (gap band). Forwarder: ecx = dword [this+0x31], then jmp 0x4d0690 (exe: eax = ecx + 0x217).
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" u32 THISCALL ext_4d0690(u8 *self);   // address of +0x217 (no stack arguments)

static u32 THISCALL forwardAddr217(u8 *self) {
  return ext_4d0690((u8 *)(unsigned long)U32(self, 0x31));
}
PCREG(41f680, forwardAddr217);
