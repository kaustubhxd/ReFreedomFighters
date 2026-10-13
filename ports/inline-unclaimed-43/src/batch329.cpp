// batch329.cpp - 0x559f60 (area 71 leaf, residue 10). thiscall (this = ECX), one stack argument (arg), ret 4.
// Body: v = this->[0x1c] slot 0x6f8() (vcall, no arguments); elem = array element 0 of arg->[8] (exe 0x5003d0, index 0);
// then exe 0x5002f0 with ecx = elem and v as its one stack argument (the exe leaves v on the stack across the 0x5003d0 call).
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" u8 *THISCALL ext_5003d0(u8 *arr, u32 index);          // array element address (ret 4)
extern "C" void THISCALL ext_5002f0(u8 *elem, u32 v);            // exe callee: ecx = elem, one stack argument

static void THISCALL callAfterElem(u8 *self, u32 arg) {
  u8 *o = (u8 *)(unsigned long)U32(self, 0x1c);
  u32 v = vcall<u32>((void *)o, 0x6f8);
  u8 *elem = ext_5003d0((u8 *)(unsigned long)U32(arg, 8), 0);
  ext_5002f0(elem, v);
}
PCREG(559f60, callAfterElem);
