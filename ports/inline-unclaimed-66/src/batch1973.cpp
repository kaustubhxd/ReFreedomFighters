// batch1973.cpp - slice-5 batches 104 and 105 (GUESS names). Callees are GUESS stubs by address or vtable slots.
//   0x427d90: STDCALL, one argument x, ret 4. Calls the import pointer at 0x676068 (STDCALL, seven arguments: x, 0x80000000, 1, 0, 3,
//             0x8000080, 0; the callee cleans); returns 0 if the result is -1, else the result.
//   0x43e810: THISCALL(this, a, b, c, d), ret 0x10. If [this+0x18] & 2: vtable +0x74 of this with (a, b); copy the three dwords at c to
//             [this+0x1c], [+0x20], [+0x24]; [this+0x3c] = d; 0x4690b0(ECX = [this+8]) (GUESS stub, no arguments).
#include "vcall_cc.h"

extern "C" void THISCALL ext_4690b0(u8 *self);  // THISCALL, no arguments (stub by address)

typedef u32(STDCALL *fn7_t)(u32, u32, u32, u32, u32, u32, u32);

// 0x427d90, GUESS FUN_00427d90 (batch 104).
static u32 STDCALL gapFn427d90(u32 x) {
  u32 r = ((fn7_t)*(u32 *)0x676068)(x, 0x80000000u, 1u, 0u, 3u, 0x8000080u, 0u);
  return r == 0xffffffffu ? 0u : r;
}
PCREG(427d90, gapFn427d90);

// 0x43e810, GUESS FUN_0043e810 (batch 105).
static void THISCALL gapFn43e810(u8 *self, u32 a, u32 b, u32 c, u32 d) {
  if (*(u8 *)(self + 0x18) & 2) {
    vcall<void>(self, 0x74, a, b);
    u8 *cp = (u8 *)c;
    *(u32 *)(self + 0x1c) = *(u32 *)cp;
    *(u32 *)(self + 0x20) = *(u32 *)(cp + 4);
    *(u32 *)(self + 0x24) = *(u32 *)(cp + 8);
    *(u32 *)(self + 0x3c) = d;
    ext_4690b0(*(u8 **)(self + 8));
  }
}
PCREG(43e810, gapFn43e810);
