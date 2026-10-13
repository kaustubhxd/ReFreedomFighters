// batch1963.cpp - unclaimed-66 batches 79 and 80 (gap band, GUESS names). STDCALL, one argument x, ret 4; eax returned.
//   p = 0x5003d0(ECX = [x+4], 0) (a GUESS stub by address); r = vtable +0x58 of the ZSysInterface child with *p.
//   If r: return vtable slot (ECX = r, no arguments) of r: 0x50f6b0 uses +0x2c, 0x50f710 uses +0x28.
//   If r == 0: the logger error path: obj = vtable +0x20 of [0x700390] with (0x69db34, K1); caller-cleaned call of [vt+0x2c] with (obj, Kc).
//   0x50f6b0: K1 0x268, Kc 0x69dd90.   0x50f710: K1 0x272, Kc 0x69ddf0.
#include "vcall_cc.h"

extern "C" u8 *THISCALL ext_5003d0(void *holder, u32 index);  // ret 4 (one argument), hooked in the spec

static u32 wrapper_nz(u32 x, u32 slot, u32 k1, u32 kc) {
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
  return vcall<u32>(r, slot);
}

// 0x50f6b0, GUESS FUN_0050f6b0 (batch 79).
static u32 STDCALL gapFn50f6b0(u32 x) { return wrapper_nz(x, 0x2c, 0x268, 0x69dd90); }
PCREG(50f6b0, gapFn50f6b0);

// 0x50f710, GUESS FUN_0050f710 (batch 80).
static u32 STDCALL gapFn50f710(u32 x) { return wrapper_nz(x, 0x28, 0x272, 0x69ddf0); }
PCREG(50f710, gapFn50f710);
