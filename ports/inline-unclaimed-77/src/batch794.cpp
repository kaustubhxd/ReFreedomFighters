// batch794.cpp - unclaimed-77 claims 27 to 29 (docs/20-unclaimed-77.md). Callees are stubbed in the harness (GUESS).
#include "ff.h"

extern "C" void THISCALL ext_57cdc0(void *self);            // thiscall, no arguments, plain ret (stub)
extern "C" void THISCALL ext_57ece0(void *self, u32 a);     // thiscall, one argument, ret 4 (stub)
extern "C" void THISCALL ext_5edea0(void *self);            // thiscall, no arguments, plain ret (stub)
extern "C" void ext_634273(void *p, u32 n);                 // CRT delete, cdecl (stub)

// 0x57d880, GUESS FUN_57d880: 0x57cdc0(this), then 0x57ece0(this, 0).
static void THISCALL guessFun57d880(u8 *self) {
  ext_57cdc0(self);
  ext_57ece0(self, 0u);
}
PCREG(57d880, guessFun57d880);

// 0x656680, GUESS FUN_656680 (one argument): p = slot 0xc of this with the argument; [p+0x2c] when the word at p+2 is zero, else 0.
static u32 THISCALL guessFun656680(u8 *self, u32 a) {
  void **vt = *(void ***)self;
  u8 *p = (u8 *)((void *(THISCALL *)(void *, u32))(*(void **)((u8 *)vt + 0xc)))(self, a);
  if (*(u16 *)(p + 2) == 0) {
    return *(u32 *)(p + 0x2c);
  }
  return 0;
}
PCREG(656680, guessFun656680);

// 0x5edf40, GUESS FUN_5edf40 (one argument): 0x5edea0(this); CRT delete (this, 0x84) when bit 0 of the argument is set; returns this.
static u8 *THISCALL guessFun5edf40(u8 *self, u32 flags) {
  ext_5edea0(self);
  if ((u8)flags & 1) {
    ext_634273(self, 0x84u);
  }
  return self;
}
PCREG(5edf40, guessFun5edf40);
