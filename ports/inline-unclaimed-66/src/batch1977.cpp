// batch1977.cpp - slice-5 batch 110 (GUESS name): 0x662dd0
// THISCALL(this, v), ret 4: calls 0x4e0830 (FASTCALL ECX=v, EDX=this+4, returns float on ST0),
// compares with 0x67a284, if greater copies 3 dwords from v to this+4 and calls 0x662cf0(this).
#include "ff.h"

extern "C" float FASTCALL ext_4e0830(void *v, void *this_plus_4);  // FASTCALL, returns float
extern "C" void THISCALL ext_662cf0(u8 *self);  // THISCALL, no arguments (stub by address)

// 0x662dd0, GUESS FUN_00662dd0 (batch 110).
static void THISCALL gapFn662dd0(u8 *self, void *v) {
  float result = ext_4e0830(v, (char *)self + 4);
  if (result > *(float *)0x67a284) {
    // Copy 3 dwords from v to this+4, this+8, this+0xc
    *(u32 *)((char *)self + 4) = *(u32 *)v;
    *(u32 *)((char *)self + 8) = *(u32 *)((char *)v + 4);
    *(u32 *)((char *)self + 0xc) = *(u32 *)((char *)v + 8);
    ext_662cf0(self);
  }
}
PCREG(662dd0, gapFn662dd0);
