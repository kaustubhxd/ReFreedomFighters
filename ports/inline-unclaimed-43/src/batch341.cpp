// batch341.cpp - 0x420e90 (gap band). Returns dword [this+0x1b37] in eax. No arguments.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

static u32 THISCALL dwordAt1b37(u8 *self) {
  return U32(self, 0x1b37);
}
PCREG(420e90, dwordAt1b37);
