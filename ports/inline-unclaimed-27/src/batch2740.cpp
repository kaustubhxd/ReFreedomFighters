#include "ff.h"
// batch2740.cpp - unclaimed-27 batch 42 (standing slice-6 assignment; docs/20-unclaimed-27.md). Names from the GC name map where known.
extern "C" void STDCALL ext_6352f0(u32 p);              // hooked in the spec (stub, NOT verified); callee cleans one argument
extern "C" void THISCALL ext_4cb030(u8 *self, u32 p);  // hooked in the spec (stub, NOT verified); callee cleans one argument

// 0x64c4a0 (name unknown, GUESS): stdcall, one argument, ret 4. Returns the argument with the low 12 bits cleared.
static u32 STDCALL funcPageBase(u32 a) {
  return a & 0xfffff000u;
}
PCREG(64c4a0, funcPageBase);

// 0x64ede0 (GUESS): thiscall, one stack argument (out pointer), ret 4. out[0] = v ? v+0x10 : 0; out[1] = 0; out[2] = v, with v = this+0xc.
static void THISCALL funcRangeOut(u8 *self, u32 *out) {
  u32 v = *(u32 *)(self + 0xc);
  out[0] = 0;
  out[2] = v;
  out[1] = 0;
  if (v != 0) out[0] = v + 0x10;
}
PCREG(64ede0, funcRangeOut);

// 0x4cb0e0 (GUESS): thiscall, no arguments, void. Calls 0x6352f0(&v), then 0x4cb030(this, &v) with v = 0 at first.
static void THISCALL funcCallPair(u8 *self) {
  u32 v = 0;
  ext_6352f0((u32)(unsigned long)&v);
  ext_4cb030(self, (u32)(unsigned long)&v);
}
PCREG(4cb0e0, funcCallPair);
