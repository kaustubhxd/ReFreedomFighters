// batch340.cpp - 0x41ea90 (gap band). inc dword [this+0x49]; ret 0 (no arguments, no return value).
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

static void THISCALL incrementAt49(u8 *self) {
  U32(self, 0x49) += 1u;
}
PCREG(41ea90, incrementAt49);
