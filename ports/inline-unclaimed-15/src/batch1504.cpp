#include "ff.h"
// batch1504.cpp - unclaimed-15 claim 4 (docs/20-unclaimed-15.md): ZFFFlak::Init2 (0x5dcc20) and
// CTimerEvent::Init(ZGEOM*, DBREAD&) (0x5c58e0). Names from the GC name map (naming only).
// The flak helper 0x5dc7a0 is stubbed (unverified); it is called as original code by its address.

typedef u32(THISCALL *Slot2)(u8 *self, u32 a1, u32 a2);

extern "C" u8 THISCALL ext_5dc7a0(u8 *self, u32 a1);   // flak check helper, stubbed in the harness
extern "C" u32 THISCALL ext_4e5e60(u8 *self);          // DBREAD::operator unsigned int, stubbed in the harness

// 0x5dcc20, ZFFFlak::Init2() (high): four checks on dwords +0x65, +0x69, +0x6d, +0x71; the first false one returns.
// If all pass, vtable slot +0x68 is called with (0x10, 0).
static void THISCALL flakInit2(u8 *self) {
  if (!ext_5dc7a0(self, *(u32 *)(self + 0x65)))
    return;
  if (!ext_5dc7a0(self, *(u32 *)(self + 0x69)))
    return;
  if (!ext_5dc7a0(self, *(u32 *)(self + 0x6d)))
    return;
  if (!ext_5dc7a0(self, *(u32 *)(self + 0x71)))
    return;
  u32 vt = *(u32 *)self;
  ((Slot2)*(u32 *)(vt + 0x68))(self, 0x10, 0);
}
PCREG(5dcc20, flakInit2);

// 0x5c58e0, CTimerEvent::Init(ZGEOM*, DBREAD&) (high): the value read from the DBREAD is stored at +0x48, or 1 when it
// is 0. +0x4c and +0x50 are cleared. The ZGEOM argument is not read. No return value.
static void THISCALL timerEventInit(u8 *self, u32 geom, u32 dbread) {
  (void)geom;
  u32 v = ext_4e5e60((u8 *)dbread);
  *(u32 *)(self + 0x50) = 0;
  *(u32 *)(self + 0x4c) = 0;
  *(u32 *)(self + 0x48) = v ? v : 1u;
}
PCREG(5c58e0, timerEventInit);
