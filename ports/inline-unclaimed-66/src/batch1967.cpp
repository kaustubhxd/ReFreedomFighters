// batch1967.cpp - unclaimed-66 batches 85 and 86 (gap band, GUESS names). STDCALL, one argument x, ret 4; eax returned.
//   p = 0x5003d0(ECX = [x+4], 0) (GUESS stub by address); r = vtable +0x58 of the ZSysInterface child with *p; if r == 0: return 0.
//   Else the exe tail-jumps to 0x4dbe30 with ECX = [r+8] and the flag as its one argument (0x4dbe30 is a GUESS stub by address); the port
//   returns its eax. 0x50f670 uses flag 1; 0x50f770 uses flag 0.
#include "vcall_cc.h"

extern "C" u8 *THISCALL ext_5003d0(void *holder, u32 index);  // ret 4 (one argument), hooked in the spec
extern "C" u32 THISCALL ext_4dbe30(u8 *self, u32 flag);        // THISCALL, one argument, ret 4 (hooked in the spec)

static u32 wrapper_4dbe(u32 x, u32 flag) {
  u8 *xo = (u8 *)x;
  u8 *p = ext_5003d0(*(u8 **)(xo + 4), 0);
  u8 *sys = *(u8 **)0x70039c;
  u8 *child = *(u8 **)(sys + 0x9b);
  u8 *r = (u8 *)vcall<u32>(child, 0x58, *(u32 *)p);
  if (!r) return 0;
  return ext_4dbe30(*(u8 **)(r + 8), flag);
}

// 0x50f670, GUESS FUN_0050f670 (batch 85).
static u32 STDCALL gapFn50f670(u32 x) { return wrapper_4dbe(x, 1); }
PCREG(50f670, gapFn50f670);

// 0x50f770, GUESS FUN_0050f770 (batch 86).
static u32 STDCALL gapFn50f770(u32 x) { return wrapper_4dbe(x, 0); }
PCREG(50f770, gapFn50f770);
