// batch408.cpp - 0x60db20 (residue 2 leaf). thiscall, no arguments: returns dword [this+0x13e7] in eax.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

static u32 THISCALL dwordAt13e7(u8 *self) {
  return U32(self, 0x13e7);
}
PCREG(60db20, dwordAt13e7);
