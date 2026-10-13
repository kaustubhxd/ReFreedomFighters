// batch1962.cpp - unclaimed-66 batches 76 to 78 (gap band, GUESS names). STDCALL, one argument x, ret 4; eax returned.
//   p = 0x5003d0(ECX = [x+4], 0) (a GUESS stub by address); r = vtable +0x58 of the ZSysInterface child with *p.
//   If r: the argument is rewritten to a flag and r's vtable slot is called with it (tail jump in the exe; the port returns eax).
//   If r == 0 (the logger error path): obj = vtable +0x20 of the logger [0x700390] with (0x69db34, K1); then the caller-cleaned call of
//   [vt+0x2c] with ECX = vt = [obj] and (obj, Kc); return its eax.
//   0x50f5b0: slot 0xbc, flag 1, K1 0x240, Kc 0x69dc38.   0x50f610: slot 0xc4, flag 1, K1 0x24a, Kc 0x69dc88.   0x50ff20: slot 0xbc, flag 0,
//   K1 0x254, Kc 0x69dce0.
#include "vcall_cc.h"

extern "C" u8 *THISCALL ext_5003d0(void *holder, u32 index);  // ret 4 (one argument), hooked in the spec

static u32 wrapper_r(u32 x, u32 slot, u32 flag, u32 k1, u32 kc) {
  u8 *xo = (u8 *)x;
  u8 *p = ext_5003d0(*(u8 **)(xo + 4), 0);
  u8 *sys = *(u8 **)0x70039c;
  u8 *child = *(u8 **)(sys + 0x9b);
  u8 *r = (u8 *)vcall<u32>(child, 0x58, *(u32 *)p);
  if (!r) {
    u8 *logger = *(u8 **)0x700390;
    u32 obj = vcall<u32>(logger, 0x20, (u32)0x69db34, k1);
    return call_cc2(*(u32 *)obj, 0x2c, obj, kc);
  }
  return vcall<u32>(r, slot, flag);
}

// 0x50f5b0, GUESS FUN_0050f5b0 (batch 76).
static u32 STDCALL gapFn50f5b0(u32 x) { return wrapper_r(x, 0xbc, 1, 0x240, 0x69dc38); }
PCREG(50f5b0, gapFn50f5b0);

// 0x50f610, GUESS FUN_0050f610 (batch 77).
static u32 STDCALL gapFn50f610(u32 x) { return wrapper_r(x, 0xc4, 1, 0x24a, 0x69dc88); }
PCREG(50f610, gapFn50f610);

// 0x50ff20, GUESS FUN_0050ff20 (batch 78).
static u32 STDCALL gapFn50ff20(u32 x) { return wrapper_r(x, 0xbc, 0, 0x254, 0x69dce0); }
PCREG(50ff20, gapFn50ff20);
