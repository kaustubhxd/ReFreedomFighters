// batch1403.cpp - unclaimed-14 batch 3 (docs/20-unclaimed-14.md): ZRelayMessage::CopyData and CMAINCAMERACONTROL::End.
#include "ff.h"

// 0x4b85f0, ZRelayMessage::CopyData(ZEventBase*) (high): stdcall-like one stack argument, thiscall with this in ecx.
// Copies the word at +0x48, the word at +0x4a and the dword at +0x4c from the argument to this (16-bit moves for the
// words, so the other bytes of this are untouched).
static void THISCALL relayMessageCopyData(u8 *self, u32 src) {
  u8 *s = (u8 *)src;
  *(u16 *)(self + 0x48) = *(u16 *)(s + 0x48);
  *(u16 *)(self + 0x4a) = *(u16 *)(s + 0x4a);
  *(u32 *)(self + 0x4c) = *(u32 *)(s + 0x4c);
}
PCREG(4b85f0, relayMessageCopyData);

// 0x4fc140, CMAINCAMERACONTROL::End() (high): reads the global at 0x70039c, takes the pointer at its +0x1907, and if
// that is nonzero calls vtable slot +0x14 of it with the constant 0x67d9e8 as its one argument (thiscall). No return value.
static void THISCALL cameraControlEnd(u8 *self) {
  (void)self;
  u8 *glob = G(u8 *, 0x70039c);
  u8 *obj = *(u8 **)(glob + 0x1907);
  if (obj) {
    typedef void(THISCALL * slot_fn)(u8 *, u32);
    slot_fn f = *(slot_fn *)(*(u32 *)obj + 0x14);
    f(obj, 0x67d9e8u);
  }
}
PCREG(4fc140, cameraControlEnd);
