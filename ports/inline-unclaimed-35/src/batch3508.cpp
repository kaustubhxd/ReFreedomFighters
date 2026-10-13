#include "ff.h"
// batch3508.cpp - area 35 claim 8 (docs/20-unclaimed-35.md): six plain leaves in slice 14. Names: GC name map (naming only);
// FUN_ names are GUESS. No calls.

// 0x41eaa0, GUESS FUN_41eaa0: decrements the dword at this + 0x49.
static void THISCALL guessDecrement(u8 *self) {
  *(u32 *)(self + 0x49) -= 1;
}
PCREG(41eaa0, guessDecrement);

// 0x428fa0, GUESS FUN_428fa0: returns this + 0xd.
static u8 *THISCALL guessFieldAddr(u8 *self) {
  return self + 0xd;
}
PCREG(428fa0, guessFieldAddr);

// 0x4d8c20, CConsoleCommand::Name() const (low): returns this + 4.
static u8 *THISCALL consoleCommandName(u8 *self) {
  return self + 4;
}
PCREG(4d8c20, consoleCommandName);

// 0x5f2de0, SerialInfo_t::getCurrentOffset() (low): returns the dword at this + 8.
static u32 THISCALL serialInfoGetCurrentOffset(u8 *self) {
  return *(u32 *)(self + 8);
}
PCREG(5f2de0, serialInfoGetCurrentOffset);

// 0x449660, ZLIGHT::SetCanChangePosition() (low): ORs 0x10 into the dword at this + 0x18.
static void THISCALL zlightSetCanChangePosition(u8 *self) {
  *(u32 *)(self + 0x18) |= 0x10u;
}
PCREG(449660, zlightSetCanChangePosition);

// 0x45e920, ZGEOM::GetActionID(char*) (low): returns -1; one argument, ret 4.
static u32 THISCALL zgeomGetActionID(u8 *self, u32 name) {
  (void)self;
  (void)name;
  return 0xffffffffu;
}
PCREG(45e920, zgeomGetActionID);
