// batch902.cpp - unclaimed-01 batch 2 (docs/20-unclaimed-01.md): ZActor::IsDead and ZActor::UpdateFacing.
#include "ff.h"

// Names from the GC name map (IsDead low confidence, GUESS); bodies from the PC bytes.

// 0x467d00, the tail-call target of UpdateFacing (original code, not lifted here). Thiscall, no stack arguments.
extern "C" u32 THISCALL ext_467d00(u8 *self);

// 0x479050, ZActor::IsDead() const (low): calls vtable slot +0x588 (thiscall, no arguments) and returns 1 when that
// call returns 0, otherwise 0 (PC: neg/sbb/inc on the result).
static u32 THISCALL actorIsDead(u8 *self) {
  typedef u32(THISCALL * slot_fn)(u8 *);
  slot_fn f = *(slot_fn *)(*(u32 *)self + 0x588);
  return f(self) == 0 ? 1u : 0u;
}
PCREG(479050, actorIsDead);

// 0x47cde0, ZActor::UpdateFacing() (high): if the byte at +0x726 is zero, tail-jumps to 0x467d00 with this in ecx;
// otherwise returns. The port makes the same call and returns (the tail jump has no stack effect for a thiscall
// callee with no arguments). eax on the early return is the caller's, so the spec does not compare it (ret=None).
static void THISCALL actorUpdateFacing(u8 *self) {
  if (self[0x726] == 0)
    ext_467d00(self);
}
PCREG(47cde0, actorUpdateFacing);
