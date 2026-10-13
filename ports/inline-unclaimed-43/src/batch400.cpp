// batch400.cpp - 0x5c56c0 (core: CTargetObtained::Load, thiscall with one unused stack argument, ret 4, returns true in al).
// Clears bit 6 of dword [this+4]; calls 0x6352f0(&L) (exe, stdcall one argument; hooked by address in the spec, GUESS: a
// getter that stores a dword through its pointer); calls 0x5c56f0(&L) as a thiscall on this (exe; hooked by address in the
// spec, GUESS: its string-copy body is not ported). L is a local dword set to 0 before the first call.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" void STDCALL ext_6352f0(u32 *out);             // getter by address (hooked in the spec)
extern "C" void THISCALL ext_5c56f0(void *self, u32 *arg); // loader by address (hooked in the spec)

static u8 THISCALL targetObtainedLoad(u8 *self, u32 unused) {
  (void)unused;
  u32 local = 0;
  U32(self, 0x4) &= 0xffffffbfu;
  ext_6352f0(&local);
  ext_5c56f0(self, &local);
  return 1;
}
PCREG(5c56c0, targetObtainedLoad);
