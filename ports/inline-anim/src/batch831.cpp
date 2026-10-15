// batch831.cpp - animation layer thread, batch 831: ZLNKOBJ / ZIKLNKOBJ push and pop of the object state.
// The state flags word is at +0x136 (0x20000 = IK on); a saved copy is at +0x159. The pushed state is the clip pair
// at +0x5c/+0x60 with the saved pair at +0x72/+0x76 (moved on pop; PopState reads the pushed values from +0x7a/+0x7e).
#include "ff.h"

#define F32(p, o) (*(u32 *)((u8 *)(p) + (o)))

extern "C" void THISCALL ext_4639f0(void *self);     // ZLNKOBJ::PushState (base; not ported here)
extern "C" void THISCALL ext_463940(void *self);     // ZLNKOBJ::PopState (base; ported below as PopState)

// ZLNKOBJ::PopState() [high, GC-mapped]. Calls vt +0x2f8(0) and vt +0x330(), then restores the saved clip pair (+0x7a
// -> +0x64, +0x7e -> +0x68) and moves the pending pair (+0x72/+0x76) into the current pair (+0x5c/+0x60), clearing the
// pending pair.
static void THISCALL ZLNKOBJ_PopState(u8 *self) {
  vcall<void>(self, 0x2f8, 0u);
  F32(self, 0x5c) = 0;
  F32(self, 0x60) = 0;
  vcall<void>(self, 0x330);
  F32(self, 0x64) = F32(self, 0x7a);
  F32(self, 0x68) = F32(self, 0x7e);
  F32(self, 0x5c) = F32(self, 0x72);
  F32(self, 0x60) = F32(self, 0x76);
  F32(self, 0x72) = 0;
  F32(self, 0x76) = 0;
}
PCREG(463940, ZLNKOBJ_PopState);

// ZIKLNKOBJ::PushState() [medium]: saves the flags word into +0x159, clears the IK flag (0x20000), then the base push.
static void THISCALL ZIKLNKOBJ_PushState(u8 *self) {
  u32 f = F32(self, 0x136);
  F32(self, 0x159) = f;
  F32(self, 0x136) = f & 0xfffdffffu;
  ext_4639f0(self);
}
PCREG(4673d0, ZIKLNKOBJ_PushState);

// ZIKLNKOBJ::PopState() [medium]: the IK flag saved at +0x159 decides which pop virtual runs (0x360 when set, else
// 0x364); then the base pop (tail call).
static void THISCALL ZIKLNKOBJ_PopState(u8 *self) {
  if (F32(self, 0x159) & 0x20000u) vcall<void>(self, 0x360);
  else vcall<void>(self, 0x364);
  ext_463940(self);
}
PCREG(467390, ZIKLNKOBJ_PopState);
