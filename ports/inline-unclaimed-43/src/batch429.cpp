// batch429.cpp - residue 2 row 0x608da0 (thiscall, no arguments; conditional vtable calls).
// If byte [0x724b34] != 0, return early. Otherwise: get obj = [this+0x1377];
// call slot 0x80 with (address [this+0x1416], obj); call slot 0x84 with
// (address [this+0x141a], [this+0x1377]); call slot 0x140 of [this] with ECX = this,
// no stack args. Store 0 at [0x724844]; store 1 at [this+0x1e]; return.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))
#define U8(p, off) (*(u8 *)((u8 *)(p) + (off)))

static void THISCALL conditionalVtableCalls(u8 *self) {
  if (U8((u8 *)0, 0x724b34) != 0) {
    return;
  }

  u32 obj = U32(self, 0x1377);
  vcall<void>((void *)(unsigned long)obj, 0x80, obj, (u32)(self + 0x1416));

  u32 obj2 = U32(self, 0x1377);
  vcall<void>((void *)(unsigned long)obj2, 0x84, obj2, (u32)(self + 0x141a));

  vcall<void>((void *)self, 0x140);

  *(u32 *)0x724844 = 0;
  U8(self, 0x1e) = 1;
}
PCREG(608da0, conditionalVtableCalls);
