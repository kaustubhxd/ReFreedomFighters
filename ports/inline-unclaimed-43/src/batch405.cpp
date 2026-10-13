// batch405.cpp - 0x41eab0 (gap band, parked row). thiscall with one stack argument (forwarded unchanged; the target's only
// return form is ret 4). ecx = dword [this+0x31]; tail-jumps to 0x4d0100 (exe, thiscall, one argument; hooked by address in
// the spec, GUESS: its 1137-byte body is not ported). The result is the target's eax.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" u32 THISCALL ext_4d0100(void *self, u32 arg);   // target by address (hooked in the spec)

static u32 THISCALL forwardTo4d0100(u8 *self, u32 arg) {
  return ext_4d0100((void *)(unsigned long)U32(self, 0x31), arg);
}
PCREG(41eab0, forwardTo4d0100);
