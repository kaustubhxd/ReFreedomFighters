// batch775.cpp - unclaimed-77 claim 5 (docs/20-unclaimed-77.md): two leaves that return a global dword. Thiscall, no callees.
#include "ff.h"

// 0x4f1880, ZActionMapZWINDOWSKEYS_ALL::GetActionDefinitions() (medium): returns the dword at the global 0x6e80fc.
static u32 THISCALL actionMapWindowsKeysGetActionDefinitions(u8 *self) {
  (void)self;
  return G(u32, 0x6e80fc);
}
PCREG(4f1880, actionMapWindowsKeysGetActionDefinitions);

// 0x56c800, ZActionMapMenuAddOn::GetActionDefinitions() (medium): returns the dword at the global 0x6ec7b8.
static u32 THISCALL actionMapMenuAddOnGetActionDefinitions(u8 *self) {
  (void)self;
  return G(u32, 0x6ec7b8);
}
PCREG(56c800, actionMapMenuAddOnGetActionDefinitions);
