// batch1972.cpp - slice-5 batches 101 to 103 (GUESS names). Callees are GUESS stubs by address or vtable slots.
//   0x5f20d0: cdecl, no arguments; returns -1. obj = vtable +0x20 of the logger [0x700390] with (0x6b8738, 0x2be); caller-cleaned call of
//             [vt+0x2c] with ECX = vt = [obj] and (obj, 0x69c6b0, 0x6b88c8); then the function pointer [0x7003b0] is called (no arguments).
//   0x5f1810: THISCALL(this), no arguments; vtable +0x1a8 of the sys object with [[this+0xc]+0x94]; if q = [[this+0xc]+0x94]: vtable +0 of q
//             with 1; then tail-jump to 0x5fb5a0 with ECX = [[this+0xc]+4] (the port returns its eax; GUESS stub by address).
//   0x557ad0: THISCALL(this, x), ret 4. n = [0x713e2c]; if n < 0x35: [0x713e30 + 4n] = x, [0x713e2c] = n + 1; else vtable +0x44 of this with
//             0x6a57f0 (no arguments) and then the function pointer [0x7003b0] if set.
#include "vcall_cc.h"

extern "C" u32 THISCALL ext_5fb5a0(u8 *self);  // THISCALL, no arguments (stub by address)

// 0x5f20d0, GUESS FUN_005f20d0 (batch 101).
static u32 gapFn5f20d0(void) {
  u8 *logger = *(u8 **)0x700390;
  u32 obj = vcall<u32>(logger, 0x20, (u32)0x6b8738, (u32)0x2be);
  u32 vt = *(u32 *)obj;
  call_cc3(vt, 0x2c, obj, (u32)0x69c6b0, (u32)0x6b88c8);
  void (*fn)(void) = *(void (**)(void))0x7003b0;
  if (fn) fn();
  return 0xffffffffu;
}
PCREG(5f20d0, gapFn5f20d0);

// 0x5f1810, GUESS FUN_005f1810 (batch 102).
static u32 THISCALL gapFn5f1810(u8 *self) {
  u8 *c = *(u8 **)(self + 0xc);
  u8 *s = *(u8 **)0x70039c;
  vcall<void>(s, 0x1a8, *(u32 *)(c + 0x94));
  u8 *q = *(u8 **)(*(u8 **)(self + 0xc) + 0x94);
  if (q) vcall<void>(q, 0x0, (u32)1);
  u8 *target = *(u8 **)(*(u8 **)(self + 0xc) + 4);
  return ext_5fb5a0(target);
}
PCREG(5f1810, gapFn5f1810);

// 0x557ad0, GUESS FUN_00557ad0 (batch 103).
static void THISCALL gapFn557ad0(u8 *self, u32 x) {
  u32 n = *(u32 *)0x713e2c;
  if (n < 0x35) {
    *(u32 *)(0x713e30 + 4 * n) = x;
    *(u32 *)0x713e2c = n + 1;
    return;
  }
  vcall<void>(self, 0x44, (u32)0x6a57f0);
  void (*fn)(void) = *(void (**)(void))0x7003b0;
  if (fn) fn();
}
PCREG(557ad0, gapFn557ad0);
