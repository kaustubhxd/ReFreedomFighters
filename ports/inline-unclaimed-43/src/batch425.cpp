// batch425.cpp - residue 2 row 0x5553e0 (stdcall, one stack argument a, ret 4; no return value).
// G = dword [0x7003b8]; S = dword [G+0x2c15]; if S == 0 return. Else: X = dword [dword [0x70039c] + 0x9b];
// r = 0x59b3c0 with ECX = S (exe, thiscall no arguments; hooked by address in the spec, GUESS); w = slot 0x4c of X with (r)
// (thiscall, one stack argument); elem = array element 0 of dword [a+8] (exe 0x5003d0, index 0); then exe 0x5002f0 with
// ECX = elem and w as its one stack argument (the exe leaves w on the stack across the 0x5003d0 call, as in batch 329).
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" u32 THISCALL ext_59b3c0(void *self);                 // exe callee by address (hooked in the spec)
extern "C" u8 *THISCALL ext_5003d0(u8 *arr, u32 index);          // array element address (ret 4)
extern "C" void THISCALL ext_5002f0(u8 *elem, u32 v);            // exe callee: ecx = elem, one stack argument

static void STDCALL elemFromSelection(u8 *a) {
  u8 *g = (u8 *)(unsigned long)G(u32, 0x7003b8);
  u32 s = U32(g, 0x2c15);
  if (s == 0)
    return;
  u32 r = ext_59b3c0((void *)(unsigned long)s);
  u8 *x = (u8 *)(unsigned long)U32((u8 *)(unsigned long)G(u32, 0x70039c), 0x9b);
  u32 w = vcall<u32>((void *)x, 0x4c, r);
  u8 *elem = ext_5003d0((u8 *)(unsigned long)U32(a, 8), 0);
  ext_5002f0(elem, w);
}
PCREG(5553e0, elemFromSelection);
