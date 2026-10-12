// batch1605.cpp - unclaimed-16 batch 5 (docs/20-unclaimed-16.md): ZActor::Hide(bool) and ZFFActor::GetAimAnim().
// Names are from the GC name map (Hide medium, GetAimAnim high). The thunk at 0x45f070 and the tail target 0x473e50
// are original code called through ext_ symbols; in the spec both are patched to recording stubs, so the port and
// the exe reach the same stub. Virtual callees are logging vtables (not verified here).
#include "ff.h"

extern "C" void THISCALL ext_45f070(u8 *self, u32 a1);  // thunk to 0x4db860, original code (stubbed in the spec)
extern "C" u32 THISCALL ext_473e50(u8 *self);           // tail target of GetAimAnim, original code (stubbed)

typedef u32(THISCALL *FnR0)(void *);
typedef void(THISCALL *FnV0)(void *);

// 0x478ff0, ZActor::Hide(bool) (medium): if the low byte of the argument is nonzero, calls 0x45f070 with (1) and
// returns. Otherwise calls 0x45f070 with (0), and if the dword at this+0x640 is nonzero calls slot 0x58c of this.
static void THISCALL actorHide(u8 *self, u32 a1) {
  u8 flag = (u8)a1;
  if (flag) {
    ext_45f070(self, 1);
    return;
  }
  ext_45f070(self, 0);
  if (*(u32 *)(self + 0x640) != 0) {
    u32 *vt = *(u32 **)self;
    ((FnV0)vt[0x58c / 4])(self);
  }
}
PCREG(478ff0, actorHide);

// 0x59fc60, ZFFActor::GetAimAnim() const (high). Returns 0 if dword this+0x90f is nonzero or dword this+0x64c is 0xa.
// If dword this+0x91c is nonzero, returns dword this+0x918. Otherwise: if slot 0x50c of this is nonzero, Z =
// slot 0x300 of (slot 0x350 of (slot 0x50c of this)); Z 0 returns 0. Then W = slot 0x3f0 of this; W 0x13 or 0x12
// returns 0; otherwise tail-calls 0x473e50 with this.
static u32 THISCALL ffActorGetAimAnim(u8 *self) {
  if (*(u32 *)(self + 0x90f) != 0)
    return 0;
  if (*(u32 *)(self + 0x64c) == 0xa)
    return 0;
  if (*(u32 *)(self + 0x91c) != 0)
    return *(u32 *)(self + 0x918);
  u32 *vt = *(u32 **)self;
  if (((FnR0)vt[0x50c / 4])(self) != 0) {
    u8 *x = (u8 *)(u32)((FnR0)vt[0x50c / 4])(self);
    u32 *xvt = *(u32 **)x;
    u8 *y = (u8 *)(u32)((FnR0)xvt[0x350 / 4])(x);
    u32 *yvt = *(u32 **)y;
    u32 z = ((FnR0)yvt[0x300 / 4])(y);
    if (z == 0)
      return 0;
  }
  u32 w = ((FnR0)vt[0x3f0 / 4])(self);
  if (w == 0x13 || w == 0x12)
    return 0;
  return ext_473e50(self);
}
PCREG(59fc60, ffActorGetAimAnim);
