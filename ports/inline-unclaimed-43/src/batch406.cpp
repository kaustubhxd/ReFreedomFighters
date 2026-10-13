// batch406.cpp - gap band parked rows 0x41f180 (forwarder) and its target 0x4d0f10 (exe, real code; not hooked).
// 0x4d0f10: thiscall, one stack argument v (ret 4): returns the old dword at this+0x821c and stores v there.
// 0x41f180: thiscall with the same stack argument; ecx = dword [this+0x31]; tail-jumps to 0x4d0f10 (returns its eax).
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" u32 THISCALL ext_4d0f10(void *self, u32 v);   // setter that returns the old value (exe code)

static u32 THISCALL swapAt821c(u8 *self, u32 v) {
  u32 old = U32(self, 0x821c);
  U32(self, 0x821c) = v;
  return old;
}

static u32 THISCALL forwardTo4d0f10(u8 *self, u32 v) {
  return ext_4d0f10((void *)(unsigned long)U32(self, 0x31), v);
}

PCREG(4d0f10, swapAt821c);
PCREG(41f180, forwardTo4d0f10);
