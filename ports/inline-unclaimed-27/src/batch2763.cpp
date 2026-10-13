#include "ff.h"
// batch2763.cpp - unclaimed-27 batch 63 (residue 6). FUN_005bc4e0 (GUESS): constructor-like, thiscall, one stack argument (flags), ret 4,
// returns this. SEH frame (fs:[0] chain and the /GS-style cookie push) is not reproduced (tagged); it is restored before every return.
// this[0x44] = 0, this[0x30] = 0, this[0] = 0x686874; vslot +0x34 of the object at [[0x70039c] + 0x9b] is called with this.
// If flags bit 0 is clear: return this. Else if bit 2 is set: 0x4690b0(this, 0x61) (cdecl, caller cleans), return this.
// Else call the function pointer at 0x7003b0 (no arguments); if it is null the exe executes int3 (the spec never makes it null).
extern "C" void ext_4690b0(u8 *self, u32 n);

static u8 *THISCALL funcCtor5bc4e0(u8 *self, u32 flags) {
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)self = 0x686874;
  u8 *o = (u8 *)(unsigned long)*(u32 *)(G(u32, 0x70039c) + 0x9b);
  typedef void(THISCALL * F34)(u8 *, u8 *);
  (*(F34 **)o)[0x34 / 4](o, self);
  if (!(flags & 1)) return self;
  if (flags & 4) {
    ext_4690b0(self, 0x61);
    return self;
  }
  typedef void (*Hook)();
  Hook h = (Hook)(unsigned long)G(u32, 0x7003b0);
  if (!h) __builtin_trap();
  h();
  return self;
}
PCREG(5bc4e0, funcCtor5bc4e0);
