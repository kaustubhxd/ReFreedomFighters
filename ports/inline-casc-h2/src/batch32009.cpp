// batch32009.cpp - h2 batch 32009: tier B frame setup + stdcall functions
#include "ff.h"

extern "C" void ext_4c0b00(u32 param);

// 0x4c1ed0, stdcall(arg1, arg2) ret 8: frame setup, push arg2, call 0x4c0b00, pop ebp, ret 8
static void STDCALL fn4c1ed0(u32 arg1, u32 arg2) {
  (void)arg1;
  ext_4c0b00(arg2);
}
PCREG(4c1ed0, fn4c1ed0);
