// batch412.cpp - 0x4b16a0 (residue 2; thiscall with one unused stack argument, ret 4, returns true in al). Clears bit 6 of dword [this+4]; if the
// function pointer at global 0x7003b0 is set, calls it with ECX = this (no arguments; the spec stores a logging stub there);
// then calls vtable slot 0x84 of this with one argument 0.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

typedef void(THISCALL *NotifyFn)(void *self);

static u8 THISCALL clearFlagAndNotify(u8 *self, u32 unused) {
  (void)unused;
  U32(self, 0x4) &= 0xffffffbfu;
  u32 fn = G(u32, 0x7003b0);
  if (fn != 0)
    ((NotifyFn)(unsigned long)fn)(self);
  vcall<void>((void *)self, 0x84, 0u);
  return 1;
}
PCREG(4b16a0, clearFlagAndNotify);
