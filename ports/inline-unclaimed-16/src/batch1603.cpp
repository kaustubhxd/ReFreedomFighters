// batch1603.cpp - unclaimed-16 batch 3 (docs/20-unclaimed-16.md): ZMatPosAnim::RunOffscreen, ZInputActions::
// GetActionMapStatus and ZActor::GetAnimOffset(const char*). Names are from the GC name map (GUESS where low); bodies
// are from the PC bytes. The virtual callees are left to the harness (logging vtables) and are not verified here.
#include "ff.h"

typedef void(THISCALL *FnV0)(void *);
typedef void(THISCALL *FnV1)(void *, u32);
typedef u32(THISCALL *FnR0)(void *);
typedef u32(THISCALL *FnR1)(void *, u32);

// 0x4a5da0, ZMatPosAnim::RunOffscreen(bool) (high): if the low byte of the argument is nonzero, calls slot 0x64 of
// the vtable with (16); then stores the low byte of the argument at this+0x92 in both cases.
static void THISCALL matPosAnimRunOffscreen(u8 *self, u32 a1) {
  u8 flag = (u8)a1;
  if (flag) {
    u32 *vt = *(u32 **)self;
    ((FnV1)vt[0x64 / 4])(self, 0x10);
  }
  self[0x92] = flag;
}
PCREG(4a5da0, matPosAnimRunOffscreen);

// 0x438260, ZInputActions::GetActionMapStatus(const char*) (medium): obj = slot 0x58 of this, called with the name.
// If the first dword of obj is 3, returns slot 0x30 of the object at obj-4 (no arguments). Otherwise, if that dword
// is 0, stores 0 at obj+0x42; then returns obj.
static u32 THISCALL inputGetActionMapStatus(u8 *self, u32 a1) {
  u32 *vt = *(u32 **)self;
  u8 *obj = (u8 *)(u32)((FnR1)vt[0x58 / 4])(self, a1);
  u32 first = *(u32 *)obj;
  if (first == 3) {
    u8 *inner = obj - 4;
    u32 *ivt = *(u32 **)inner;
    return ((FnR0)ivt[0x30 / 4])(inner);
  }
  if (first == 0)
    *(u32 *)(obj + 0x42) = 0;
  return (u32)obj;
}
PCREG(438260, inputGetActionMapStatus);

// 0x478b00, ZActor::GetAnimOffset(const char*) (high): p = slot 0x21c of this (called with the name). Returns 0 if p
// is 0; otherwise p minus the dword at (the dword at (the dword at 0x70039c) + 0x9b) + 0x44.
static u32 THISCALL actorGetAnimOffsetByName(u8 *self, u32 a1) {
  u32 *vt = *(u32 **)self;
  u32 p = ((FnR1)vt[0x21c / 4])(self, a1);
  if (p == 0)
    return p;
  u32 rm = *(u32 *)0x70039c;
  u32 q = *(u32 *)(rm + 0x9b);
  return p - *(u32 *)(q + 0x44);
}
PCREG(478b00, actorGetAnimOffsetByName);
