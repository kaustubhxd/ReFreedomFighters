// batch401.cpp - 0x41f1d0 (gap band, parked row; thiscall, no arguments). ecx = dword [this+0x45]; ecx = dword
// [this + ecx*4 + 0x31]; then tail-jump to 0x4d1100 (ZMallocSimple::CheckAllFreed, thiscall with no arguments; exe, hooked by
// address in the spec, GUESS: its body is not ported). The result is the target's al.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" u8 THISCALL ext_4d1100(void *self);   // CheckAllFreed by address (hooked in the spec)

static u8 THISCALL forwardCheckAllFreed(u8 *self) {
  u32 idx = U32(self, 0x45);
  u32 obj = U32(self, 0x31 + 4 * idx);
  return ext_4d1100((void *)(unsigned long)obj);
}
PCREG(41f1d0, forwardCheckAllFreed);
