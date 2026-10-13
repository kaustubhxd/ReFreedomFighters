// batch333.cpp - 0x507ee0 (area 71 leaf, residue 10). thiscall (this = ECX), one stack argument (arg), ret 4.
// Body: elem = array element 0 of arg->[4] (exe 0x5003d0, index 0); this->[0x18] byte at +0x776 = (dword at elem != 0).
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" u8 *THISCALL ext_5003d0(u8 *arr, u32 index);   // array element address (ret 4)

static void THISCALL setFlagFromElem0(u8 *self, u8 *arg) {
  u8 *elem = ext_5003d0((u8 *)(unsigned long)U32(arg, 4), 0);
  u8 *o = (u8 *)(unsigned long)U32(self, 0x18);
  o[0x776] = (u8)(U32(elem, 0) != 0);
}
PCREG(507ee0, setFlagFromElem0);
