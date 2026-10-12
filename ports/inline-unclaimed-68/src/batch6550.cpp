// batch6550.cpp - unclaimed-68 batch 55 (claim 56, residue row). Name is a GUESS (ZInputActions::GetActionID from the residue file).
#include "ff.h"

typedef u32(THISCALL *VNoArgRet)(u8 *self);

// 0x438c20: thiscall, no arguments; tail jump to the vtable slot +0x58 with this in ecx (the callee's result is returned in EAX).
static u32 THISCALL inputActionsGetActionID(u8 *self) {
  return ((VNoArgRet)*(u32 *)(*(u8 **)self + 0x58))(self);
}
PCREG(438c20, inputActionsGetActionID);
