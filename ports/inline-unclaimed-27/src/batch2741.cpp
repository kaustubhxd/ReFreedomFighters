#include "ff.h"
// batch2741.cpp - unclaimed-27 batch 43 (residue 12). Names unknown (GUESS). The assert hook at 0x7003b0 is non-null in the spec.

// 0x656140 (GUESS): stdcall, two arguments (dst, src), ret 8: *dst = *src.
static void STDCALL funcCopyDword(u32 dst, u32 src) {
  *(u32 *)(unsigned long)dst = *(u32 *)(unsigned long)src;
}
PCREG(656140, funcCopyDword);

// 0x64fc00 (GUESS): thiscall, one stack argument (out pointer), ret 4: out[0] = this+0x60, out[1] = this+0x64, out[2] = 0.
static void THISCALL funcCopyPair(u8 *self, u32 *out) {
  out[0] = *(u32 *)(self + 0x60);
  out[1] = *(u32 *)(self + 0x64);
  out[2] = 0;
}
PCREG(64fc00, funcCopyPair);

// 0x639b80 (GUESS): stdcall, four arguments (ignored), ret 0x10, returns 0. Calls the assert hook (cdecl, no args) when set.
static u32 STDCALL funcCallHookRet0(u32 a, u32 b, u32 c, u32 d) {
  (void)a; (void)b; (void)c; (void)d;
  void (*hook)(void) = (void (*)(void))(unsigned long)G(u32, 0x7003b0);
  if (hook) hook();
  return 0;
}
PCREG(639b80, funcCallHookRet0);
