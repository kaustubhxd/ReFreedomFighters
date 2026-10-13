#include "ff.h"
// batch3509.cpp - area 35 claim 9 (docs/20-unclaimed-35.md): four leaves in slice 14. 0x5852e0 is a tail jump to vtable slot
// +0x84 (no arguments); the slot is a logged stub in the harness. The others are leaves; 0x428820 is a GUESS name.

typedef u32(THISCALL *Slot0)(u8 *self);

// 0x5852e0, CWaves::FrameUpdate() (low): tail-jumps to vtable slot +0x84 of this.
static u32 THISCALL wavesFrameUpdate(u8 *self) {
  return ((Slot0)*(u32 *)(*(u32 *)self + 0x84))(self);
}
PCREG(5852e0, wavesFrameUpdate);

// 0x4f1860, ZActionMapZWINDOWSKEYS_3::GetActionDefinitions() (low): returns the dword at the global 0x6e7e1c.
static u32 THISCALL actionMapGetActionDefinitions(u8 *self) {
  (void)self;
  return *(u32 *)0x6e7e1c;
}
PCREG(4f1860, actionMapGetActionDefinitions);

// 0x607ce0, ZPrimControlBase::GetSizeOfLightSpot() const (low): returns 0x38.
static u32 THISCALL primControlGetSizeOfLightSpot(u8 *self) {
  (void)self;
  return 0x38u;
}
PCREG(607ce0, primControlGetSizeOfLightSpot);

// 0x428820, GUESS FUN_428820: sets the byte at this + 0x75 to 1 and returns true.
static u8 THISCALL guessSetFlag75(u8 *self) {
  self[0x75] = 1;
  return 1;
}
PCREG(428820, guessSetFlag75);
