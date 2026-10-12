// batch1604.cpp - unclaimed-16 batch 4 (docs/20-unclaimed-16.md): ZFFActor::SetHero, GetProjectilesInMagazine and
// GetItemTemplate. Names are from the GC name map (high confidence). Each reads the render-manager object through the
// global at 0x70039c (its dword at +0x9b). The callees that are virtual are left to the harness (logging vtables);
// ZActor::SetHero (0x47bdf0) is called as original code.
#include "ff.h"

extern "C" void THISCALL ext_47bdf0(u8 *self, u32 a1); // ZActor::SetHero, original code (verified in unclaimed-01)

typedef u32(THISCALL *FnR0)(void *);
typedef u32(THISCALL *FnR1)(void *, u32);
typedef u8(THISCALL *FnB1)(void *, u32);

// *(*(u32*)0x70039c + 0x9b): the object the three functions call through.
static void *renderMgrSub() {
  u32 rm = *(u32 *)0x70039c;
  return (void *)(u32)*(u32 *)(rm + 0x9b);
}

// 0x5a2d60, ZFFActor::SetHero(unsigned int) (high): calls ZActor::SetHero(arg) (original code at 0x47bdf0); then
// stores the result of slot 0x58 of the render-manager sub-object (called with arg) at this+0x92e.
static void THISCALL ffActorSetHero(u8 *self, u32 a1) {
  ext_47bdf0(self, a1);
  void *q = renderMgrSub();
  u32 *vt = *(u32 **)q;
  u32 v = ((FnR1)vt[0x58 / 4])(q, a1);
  *(u32 *)(self + 0x92e) = v;
}
PCREG(5a2d60, ffActorSetHero);

// 0x59ff70, ZFFActor::GetProjectilesInMagazine(int) (high): slot = dword at this+0x78a if the argument is 0, else
// dword at this+0x78e. obj = slot 0x58 of the render-manager sub-object (called with slot). If obj is 0 returns -1;
// otherwise returns slot 0x35c of obj (no arguments).
static u32 THISCALL ffActorGetProjectilesInMagazine(u8 *self, u32 a1) {
  u32 slot = (a1 == 0) ? *(u32 *)(self + 0x78a) : *(u32 *)(self + 0x78e);
  void *q = renderMgrSub();
  u32 *qvt = *(u32 **)q;
  u32 obj = ((FnR1)qvt[0x58 / 4])(q, slot);
  if (obj == 0)
    return 0xffffffffu;
  u8 *o = (u8 *)obj;
  u32 *ovt = *(u32 **)o;
  return ((FnR0)ovt[0x35c / 4])(o);
}
PCREG(59ff70, ffActorGetProjectilesInMagazine);

// 0x59fe20, ZFFActor::GetItemTemplate(unsigned int) (high): does not use this. obj = slot 0x58 of the render-manager
// sub-object (called with the argument). If obj is 0 returns 0. Otherwise, if slot 0x1e0 of obj (called with
// 0x1007d3) returns a nonzero low byte, returns obj; else returns 0.
static u32 THISCALL ffActorGetItemTemplate(u8 *self, u32 a1) {
  (void)self;
  void *q = renderMgrSub();
  u32 *qvt = *(u32 **)q;
  u32 obj = ((FnR1)qvt[0x58 / 4])(q, a1);
  if (obj == 0)
    return 0;
  u8 *o = (u8 *)obj;
  u32 *ovt = *(u32 **)o;
  u8 ok = ((FnB1)ovt[0x1e0 / 4])(o, 0x1007d3);
  return ok ? obj : 0;
}
PCREG(59fe20, ffActorGetItemTemplate);
