// batch1971.cpp - slice-5 batches 98 to 100 (GUESS names). Callees are GUESS stubs by address or vtable slots.
//   0x626dd0: cdecl, eleven arguments (caller cleans). 0x628810(0x628b40, a0..a10) (cdecl, eleven arguments; stub by address).
//   0x495ed0: THISCALL(this, a, b, c), ret 0xc. r = vtable +0x158 of the ZSysInterface child with b; then vtable +4 of this with
//             (a, r, c, 0) (THISCALL, callee cleans).
//   0x658f10: THISCALL(this, x), ret 4. o = [this+0x10]; if o: o = [o+0xc]; if x: tbl = [o+0x3c]; obj = [[sys]+0x1aa3]; vtable +0x80 of obj
//             with [tbl + 4*x + 4] (one argument).
#include "ff.h"

extern "C" void ext_628810(u32 fn, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8, u32 a9, u32 a10);  // cdecl (stub)

// 0x626dd0, GUESS FUN_00626dd0 (batch 98).
void gapWrap626dd0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8, u32 a9, u32 a10) {
  ext_628810(0x628b40, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
}
PCREG(626dd0, gapWrap626dd0);

// 0x495ed0, GUESS FUN_00495ed0 (batch 99).
static void THISCALL gapFn495ed0(u8 *self, u32 a, u32 b, u32 c) {
  u8 *s = *(u8 **)0x70039c;
  u8 *child = *(u8 **)(s + 0x9b);
  u32 r = vcall<u32>(child, 0x158, b);
  vcall<void>(self, 0x4, a, r, c, (u32)0);
}
PCREG(495ed0, gapFn495ed0);

// 0x658f10, GUESS FUN_00658f10 (batch 100).
static void THISCALL gapFn658f10(u8 *self, u32 x) {
  u8 *o = *(u8 **)(self + 0x10);
  if (!o) return;
  o = *(u8 **)(o + 0xc);
  if (x) {
    u8 *tbl = *(u8 **)(o + 0x3c);
    u8 *s = *(u8 **)0x70039c;
    u8 *obj = *(u8 **)(s + 0x1aa3);
    u32 arg = *(u32 *)(tbl + x * 4 + 4);
    vcall<void>(obj, 0x80, arg);
  }
}
PCREG(658f10, gapFn658f10);
