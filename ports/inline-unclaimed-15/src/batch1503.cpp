#include "ff.h"
// batch1503.cpp - unclaimed-15 claim 3 (docs/20-unclaimed-15.md): ZFFHeroMovementOpenGate::GetAnims (0x5e46a0) and
// ZInputActions::CheckAction(ZInputActionGroup*, void*) (0x437fa0). Names from the GC name map (naming only).
// The exe callees (0x5e3e90, 0x439670, 0x438150) are not ported; they run as original code.

extern "C" void THISCALL ext_5e3e90(u8 *self);       // hero movement base helper, original code
extern "C" u8 THISCALL ext_439670(u8 *self);         // bool check on the action's member, original code
extern "C" u32 THISCALL ext_438150(u8 *self);        // action update, original code (its eax is returned)

typedef u32(THISCALL *Slot1)(u8 *self, u32 a1);

// 0x5e46a0, ZFFHeroMovementOpenGate::GetAnims() (high): base helper, then two vtable lookups (slot +0x58) with string
// literals; their results go to +0x553 and +0x557. The word at +0x371 becomes 0x101. No return value.
static void THISCALL heroOpenGateGetAnims(u8 *self) {
  ext_5e3e90(self);
  u32 vt = *(u32 *)self;
  *(u32 *)(self + 0x553) = ((Slot1)*(u32 *)(vt + 0x58))(self, 0x6b7e74);
  vt = *(u32 *)self;
  *(u32 *)(self + 0x557) = ((Slot1)*(u32 *)(vt + 0x58))(self, 0x6b7e80);
  *(u16 *)(self + 0x371) = 0x101;
}
PCREG(5e46a0, heroOpenGateGetAnims);

// 0x437fa0, ZInputActions::CheckAction(ZInputActionGroup*, void*) (high): two stack arguments, no this (ret 8).
// The flag byte at +0xc of the group gates the check. Unless the first dword is 3, the bool from 0x439670 on the
// member at +8 is ANDed in. If the result is still set, 0x438150 runs on the group and its al is returned.
// Only AL is defined by the exe's return; the failure path leaves the upper eax bits from the last call.
static u8 STDCALL inputActionsCheckGroup(u8 *group, u32 a2) {
  (void)a2;
  u8 bl = group[0xc];
  if (bl && *(u32 *)group != 3)
    bl &= ext_439670(*(u8 **)(group + 8));
  if (!bl)
    return 0;
  return (u8)ext_438150(group);
}
PCREG(437fa0, inputActionsCheckGroup);
