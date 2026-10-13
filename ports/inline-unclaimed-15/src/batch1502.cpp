#include "ff.h"
// batch1502.cpp - unclaimed-15 claim 2 (docs/20-unclaimed-15.md): ZInputActions name-lookup wrappers.
// Each wrapper first calls vtable slot +0x58 (a lookup, one argument, returns an action pointer or 0) and then calls
// another virtual slot on the same object. Names from the GC name map (naming only). All thiscall.

typedef u32(THISCALL *Slot1)(u8 *self, u32 a1);
typedef u32(THISCALL *Slot2)(u8 *self, u32 a1, u32 a2);

static u32 slot1(u8 *self, u32 index, u32 a1) {
  u32 vt = *(u32 *)self;
  return ((Slot1)*(u32 *)(vt + index))(self, a1);
}

static u32 slot2(u8 *self, u32 index, u32 a1, u32 a2) {
  u32 vt = *(u32 *)self;
  return ((Slot2)*(u32 *)(vt + index))(self, a1, a2);
}

// 0x438360, ZInputActions::DisableActions(const char*) (GUESS: the map name says no arguments, the code takes one).
// If the lookup returns an action, clears the byte at +0xc of it. No return value.
static void THISCALL inputActionsDisableActions(u8 *self, u32 a1) {
  u32 r = slot1(self, 0x58, a1);
  if (r)
    *(u8 *)(r + 0xc) = 0;
}
PCREG(438360, inputActionsDisableActions);

// 0x437fe0, ZInputActions::CheckAction(const char*, void*) (high): lookup, then slot +0x2c with (result, 0).
// The second argument is not read; the wrapper pushes a literal 0.
static u32 THISCALL inputActionsCheckAction(u8 *self, u32 a1, u32 a2) {
  (void)a2;
  u32 r = slot1(self, 0x58, a1);
  return slot2(self, 0x2c, r, 0);
}
PCREG(437fe0, inputActionsCheckAction);

// 0x438f30, ZInputActions::GetActionValue(const char*) (high): lookup, then slot +0xa0 with the result.
static u32 THISCALL inputActionsGetActionValue(u8 *self, u32 a1) {
  u32 r = slot1(self, 0x58, a1);
  return slot1(self, 0xa0, r);
}
PCREG(438f30, inputActionsGetActionValue);

// 0x438880, ZInputActions::ForceSetAction(const char*, bool) (medium): lookup, then slot +0x4c with (result, bool).
// The slot's return value is left in eax.
static u32 THISCALL inputActionsForceSetAction(u8 *self, u32 a1, u32 a2) {
  u32 r = slot1(self, 0x58, a1);
  return slot2(self, 0x4c, r, a2);
}
PCREG(438880, inputActionsForceSetAction);

// 0x4380a0, ZInputActions::CheckActionCheat(unsigned int, void*) (high): if the render manager's byte at +0x9b9 is
// clear, returns 0 (the exe leaves eax as the manager pointer with its low byte cleared, `xor al, al`). Otherwise
// tail-jumps to slot +0x2c with (the id, 0): the second argument is overwritten with 0 before the jump.
static u32 THISCALL inputActionsCheckActionCheat(u8 *self, u32 a1, u32 a2) {
  (void)a2;
  u32 rm = *(u32 *)0x70039c;
  if (!*(u8 *)(rm + 0x9b9))
    return rm & 0xffffff00u;
  return slot2(self, 0x2c, a1, 0);
}
PCREG(4380a0, inputActionsCheckActionCheat);
