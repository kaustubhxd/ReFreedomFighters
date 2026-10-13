// batch328.cpp - 0x5582a0 (area 71 leaf, residue 10). thiscall (this = ECX), one stack argument (arg), ret 4.
// Body: elem = array element 0 of arg->[4] (exe 0x5003d0 with ecx = arg->[4], index 0); value = *elem;
// this->[0x1c]->[0x949] = value.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" u8 *THISCALL ext_5003d0(u8 *arr, u32 index);   // array element address (ret 4)

static void THISCALL storeElem0Value(u8 *self, u8 *arg) {
  u8 *elem = ext_5003d0((u8 *)(unsigned long)U32(arg, 4), 0);
  u8 *o = (u8 *)(unsigned long)U32(self, 0x1c);
  U32(o, 0x949) = U32(elem, 0);
}
PCREG(5582a0, storeElem0Value);
