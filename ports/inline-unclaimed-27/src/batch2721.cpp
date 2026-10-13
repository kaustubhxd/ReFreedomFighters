#include "ff.h"
// batch2721.cpp - unclaimed-27 batch 21 (gap band; docs/20-unclaimed-27.md). Name unknown (GUESS).
// 0x4e5e60 is thiscall, no stack arguments, returns eax. 0x58a660 is thiscall (this = the global at 0x7003b8), two stack
// arguments, callee cleans (ret 8).
extern "C" u32 THISCALL ext_4e5e60(u8 *self);
extern "C" void THISCALL ext_58a660(u8 *self, u32 a1, u8 *b);

// 0x59a6e0 (GUESS): thiscall, one argument, ret 4. Stores 0x4e5e60(arg) at this+0x85 and 0x4e5e60(arg) at this+0x22db, then calls
// 0x58a660 with the global at 0x7003b8 as this, the low byte of the second result, and this.
static void THISCALL funcStoreTwoAndNotify(u8 *self, u8 *arg) {
  u32 a = ext_4e5e60(arg);
  *(u32 *)(self + 0x85) = a;
  u32 b = ext_4e5e60(arg);
  *(u32 *)(self + 0x22db) = b;
  u8 *g = (u8 *)(unsigned long)G(u32, 0x7003b8);
  ext_58a660(g, (u32)(u8)b, self);
}
PCREG(59a6e0, funcStoreTwoAndNotify);
