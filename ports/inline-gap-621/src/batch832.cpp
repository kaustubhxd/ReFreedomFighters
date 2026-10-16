// batch832.cpp - gap band small functions (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

// 0x634340 (__allmul): stdcall(u64 a, u64 b) ret 0x10 - 64-bit product in edx:eax
static u64 STDCALL allmul_634340(u32 alo, u32 ahi, u32 blo, u32 bhi) {
  u64 a = ((u64)ahi << 32) | alo, b = ((u64)bhi << 32) | blo;
  return a * b;
}
PCREG(634340, allmul_634340);

// 0x6387a0: stdcall(2 unused words) ret 8 - calls the global callback at 0x7003b0 (int3 when unset), returns 0
typedef void (*cbfn_t)();
static u32 STDCALL callbackRet0_6387a0(u32, u32) {
  cbfn_t cb = G(cbfn_t, 0x7003b0);
  if (!cb) __builtin_trap();
  cb();
  return 0;
}
PCREG(6387a0, callbackRet0_6387a0);
