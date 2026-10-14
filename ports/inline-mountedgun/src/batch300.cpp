// batch300.cpp - mounted gun tree, batch 300: leaf methods of CMachinegunControlGroup (MachinegunControlGroup.cpp).
// Engine object 0x70039c: +0x40 is the game clock in 1/1024 s ticks (inferred from the 1024 scale below);
// +0x9b is the object manager (slot 0x58: reference -> object, slot 0x4c: object -> reference; batch 55 names it
// the render manager). Object slot 0x1e0 is IsA(class id). Class id 0x200006 is unnamed here.
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u8 *(THISCALL *vcallPU)(void *self, u32 a);
typedef u32(THISCALL *vcallU0)(void *self);
typedef u32(THISCALL *vcallUU)(void *self, u32 a);
typedef u8(THISCALL *vcallBU)(void *self, u32 a);

static inline u8 *objMgr() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

// 0x5c9130 CMachinegunControlGroup::Reserve(unsigned int ref, float secs) (namemap said LockTargetSetup [low]; Command
// in batch 304 shows it is the MakeReservation worker). +0x88 = ref (reserved by); +0x8c = the clock time (seconds) at
// which the reservation ends: (clock - (int)(secs * -1024)) / 1024.
static void THISCALL lockTargetSetup(u8 *self, u32 ref, float secs) {
  float t = secs * -1024.0f;   // 0x67862c
  *(u32 *)(self + 0x88) = ref;
  u32 ticks = *(u32 *)(G(u8 *, 0x70039c) + 0x40) - (u32)(s32)t;   // cvttss2si: out of range gives 0x80000000
  *(float *)(self + 0x8c) = (float)(s32)ticks * 0.0009765625f;   // 0x6785e4
}
PCREG(5c9130, lockTargetSetup);

// The object behind ref is a class-0x200006 object whose +0x54 pointer is set and that pointer's +4 is 0
// (inferred: a free gunner seat / actor with no current controller).
static bool isFreeOwner(u8 *o) {
  if (!o || !((vcallBU)VT(o, 0x1e0))(o, 0x200006))
    return false;
  u8 *p = *(u8 **)(o + 0x54);
  return p && *(u32 *)(p + 4) == 0;
}

// 0x5c94a0 (no GC match), thiscall, ret 4, result in al: isFreeOwner(objMgr()->slot58(ref)). `this` is not used.
static u8 THISCALL refIsFreeOwner(u8 *self, u32 ref) {
  (void)self;
  u8 *m = objMgr();
  u8 *o = ((vcallPU)VT(m, 0x58))(m, ref);
  return isFreeOwner(o);
}
PCREG(5c94a0, refIsFreeOwner);

// 0x5c90b0 CMachinegunControlGroup::LockTargetSetup(unsigned int ref) (namemap said WeaponOwner [low]; it is the
// LockTarget message worker, batch 304): +0x80 = aim target ref,
// +0x84 = 1.0f when the ref's object is a free owner (isFreeOwner), else 0.0f. thiscall, ret 4.
static void THISCALL setOwnerRef(u8 *self, u32 ref) {
  u8 *m = objMgr();
  u8 *o = ((vcallPU)VT(m, 0x58))(m, ref);
  bool ok = isFreeOwner(o);
  *(u32 *)(self + 0x80) = ref;
  *(u32 *)(self + 0x84) = ok ? 0x3f800000u : 0u;
}
PCREG(5c90b0, setOwnerRef);

// 0x5c94f0 (no GC match; the GetOwner message worker, batch 304), thiscall, no args: the gun user's reference,
// objMgr()->slot4c(objMgr()->slot58(+0x70)->slot2f4()).
// The +0x70 field holds a reference (inferred: the machine gun weapon); slot 0x2f4 of that object returns an
// object whose reference is returned. The manager's vtable is read before slot 0x2f4 runs, as in the original.
static u32 THISCALL weaponSubRef(u8 *self) {
  u8 *m = objMgr();
  u8 *w = ((vcallPU)VT(m, 0x58))(m, *(u32 *)(self + 0x70));
  void **mvt = *(void ***)objMgr();
  u32 sub = ((vcallU0)VT(w, 0x2f4))(w);
  return ((vcallUU)mvt[0x4c / 4])(objMgr(), sub);
}
PCREG(5c94f0, weaponSubRef);
