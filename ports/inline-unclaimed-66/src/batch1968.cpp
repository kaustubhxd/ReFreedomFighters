// batch1968.cpp - slice-5 batches 87 to 91 (GUESS names). Callees are GUESS stubs by address in the specs.
//   0x63dad0: cdecl, no arguments; returns 0x30.
//   0x651850: THISCALL(this), no arguments; 0x64f270(ECX = this) (stub); [this] = 0x6c3974; [this+0x1c] = 0; returns this.
//   0x54add0: THISCALL(this), one argument flags, ret 4; 0x54acc0(ECX = this) (stub); if flags & 1: 0x634273(this, 0x63f8) (cdecl, the CRT free);
//             returns this.
//   0x60fe50: cdecl, no arguments; if [0x724950] != [0x724954]: edx = [0x724954]; [0x724950] = edx; o = [0x724a00];
//             call [vt+0xc8] with ECX = vt = [o] and (o, 0x22, edx) (THISCALL: callee cleans).
//   0x64ff50: THISCALL(this), one argument a, ret 4 (returns al = 1); o = [this+0xbd]; vtable +0x64 of o (no arguments);
//             vtable +0x7c of a with [this+0x8c].
#include "ff.h"

extern "C" void THISCALL ext_64f270(u8 *self);      // THISCALL, no arguments (stub by address)
extern "C" void THISCALL ext_54acc0(u8 *self);      // THISCALL, no arguments (stub by address)
extern "C" void ext_634273(void *p, u32 size);      // cdecl (the CRT free), two arguments (stub by address)

// 0x63dad0, GUESS FUN_0063dad0 (batch 87).
static u32 gapConst63dad0(void) { return 0x30; }
PCREG(63dad0, gapConst63dad0);

// 0x651850, GUESS FUN_00651850 (batch 88).
static u8 *THISCALL gapInit651850(u8 *self) {
  ext_64f270(self);
  *(u32 *)self = 0x6c3974;
  *(u32 *)(self + 0x1c) = 0;
  return self;
}
PCREG(651850, gapInit651850);

// 0x54add0, GUESS FUN_0054add0 (batch 89).
static u8 *THISCALL gapDtor54add0(u8 *self, u32 flags) {
  ext_54acc0(self);
  if (flags & 1) ext_634273(self, 0x63f8);
  return self;
}
PCREG(54add0, gapDtor54add0);

// 0x60fe50, GUESS FUN_0060fe50 (batch 90).
static void gapGuard60fe50(void) {
  u32 edx = *(u32 *)0x724954;
  if (*(u32 *)0x724950 == edx) return;
  u8 *o = *(u8 **)0x724a00;
  *(u32 *)0x724950 = edx;
  u32 vt = *(u32 *)o;
  ((void(THISCALL *)(void *, u32, u32, u32))(*(u32 *)(vt + 0xc8)))((void *)vt, (u32)o, 0x22u, edx);
}
PCREG(60fe50, gapGuard60fe50);

// 0x64ff50, GUESS FUN_0064ff50 (batch 91).
static u8 THISCALL gapFn64ff50(u8 *self, u32 a) {
  u8 *o = *(u8 **)(self + 0xbd);
  vcall<void>(o, 0x64);
  vcall<void>((u8 *)a, 0x7c, *(u32 *)(self + 0x8c));
  return 1;
}
PCREG(64ff50, gapFn64ff50);
