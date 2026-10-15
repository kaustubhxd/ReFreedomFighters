// batch827.cpp - animation layer thread, batch 827: ZIKLNKOBJ forwarders to its current link action (+0x1ce).
#include "ff.h"

#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

// The current link action object lives at +0x1ce; these functions forward to its virtuals (no arguments).
static inline void *action(u8 *self) { return FP(self, 0x1ce); }

// ZIKLNKOBJ::CallBackLnkActionTarget() [medium, GC-mapped]: action vt +0xc.
static void THISCALL CallBackLnkActionTarget(u8 *self) { vcall<void>(action(self), 0xc); }
PCREG(465a70, CallBackLnkActionTarget);

// ZIKLNKOBJ::RemoveCurrentLnkAction() [medium]: action vt +0x10.
static void THISCALL RemoveCurrentLnkAction(u8 *self) { vcall<void>(action(self), 0x10); }
PCREG(4675d0, RemoveCurrentLnkAction);

// ZIKLNKOBJ::UpdateCurrentLnkAction() [medium]: action vt +8.
static void THISCALL UpdateCurrentLnkAction(u8 *self) { vcall<void>(action(self), 8); }
PCREG(467cf0, UpdateCurrentLnkAction);

// ZIKLNKOBJ::CurrentLnkActionId() const [medium]: 0 when the action has no sub-object (+4); otherwise the sub-object's
// vt +4 (its id).
static u32 THISCALL CurrentLnkActionId(u8 *self) {
  void *x = FP(action(self), 4);
  if (!x) return 0;
  return vcall<u32>(x, 4);
}
PCREG(466400, CurrentLnkActionId);

// ZIKLNKOBJ::DisplayGround(bool on) [high, GC-mapped]: forwards to its own vt +0x2a8(0, on).
static void THISCALL DisplayGround(u8 *self, u32 on) { vcall<void>(self, 0x2a8, 0u, on); }
PCREG(466480, DisplayGround);
