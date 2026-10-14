// batch304.cpp - mounted gun tree, batch 304: CMachinegunControlGroup::Command, the nest's message handler.
// The constructor stores the registered ids of 13 messages in u16 globals 4 bytes apart from 0x714350:
//   0x714350 GetItemWeapon   0x714354 AimWeaponAt   0x714358 AimWeaponRef  0x71435c CanAimWeaponRef
//   0x714360 SetOwner        0x714364 GetOwner      0x714368 GetCenter     0x71436c LockTarget
//   0x714370 GetTaken        0x714374 MakeReservation 0x714378 ScriptEvent 0x71437c GetReservedBy
//   0x714380 RenewMachinegun
// This names the fields: +0x70 gun (item weapon) ref, +0x74 base ("center") ref, +0x80 aim target ref,
// +0x88 reserved-by ref, +0x8c reservation expiry (seconds).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u8 *(THISCALL *vcallPU)(void *self, u32 a);
typedef void(THISCALL *vcallVUUU)(void *self, u32 a, u32 b, u32 c);
typedef void *(THISCALL *logOpen)(void *self, const char *file, u32 line);
typedef void (*logPrintf)(void *pr, const char *fmt, ...);

extern "C" u8 THISCALL ext_5c82a0(void *self, const float *p);       // AimWeaponAt (batch 302)
extern "C" u8 THISCALL ext_5c8470(void *self, u32 ref);              // AimWeaponRef (batch 302)
extern "C" u8 THISCALL ext_5c87f0(void *self, u32 *ref);             // CanAimWeaponRef (batch 301)
extern "C" void THISCALL ext_5c9330(void *self, u8 *user);           // setUser (batch 303)
extern "C" u32 THISCALL ext_5c94f0(void *self);                      // getUserRef (batch 300)
extern "C" void THISCALL ext_5c90b0(void *self, u32 ref);            // LockTargetSetup (batch 300)
extern "C" void THISCALL ext_5c9130(void *self, u32 ref, float secs);// Reserve (batch 300)

static inline u8 *byRef(u32 ref) {
  u8 *m = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  return ((vcallPU)VT(m, 0x58))(m, ref);
}

// 0x5c8a80 CMachinegunControlGroup::Command(unsigned short msg, void *data), GC map [high]; thiscall, ret 8, returns 0.
// The ids are compared in the order below (first match wins).
static u32 THISCALL command(u8 *self, u16 msg, void *data) {
  if (msg == G(u16, 0x714350)) {   // GetItemWeapon
    *(u32 *)data = *(u32 *)(self + 0x70);
  } else if (msg == G(u16, 0x714368)) {   // GetCenter
    *(u32 *)data = *(u32 *)(self + 0x74);
  } else if (msg == G(u16, 0x714354)) {   // AimWeaponAt
    ext_5c82a0(self, (const float *)data);
  } else if (msg == G(u16, 0x714358)) {   // AimWeaponRef
    ext_5c8470(self, (u32)data);
  } else if (msg == G(u16, 0x71435c)) {   // CanAimWeaponRef
    ext_5c87f0(self, (u32 *)data);
  } else if (msg == G(u16, 0x714360)) {   // SetOwner: the gun's user becomes the object `data` refers to
    u8 *gun = byRef(*(u32 *)(self + 0x70));
    ext_5c9330(self, byRef((u32)data));
    u8 *g = *(u8 **)(self + 0x44);
    ((vcallVUUU)VT(g, 0x288))(g, (u32)gun, 0, 1);
    if (data == nullptr)
      *(u32 *)(self + 0x80) = 0;
  } else if (msg == G(u16, 0x714364)) {   // GetOwner
    *(u32 *)data = ext_5c94f0(self);
  } else if (msg == G(u16, 0x71436c)) {   // LockTarget
    ext_5c90b0(self, (u32)data);
  } else if (msg == G(u16, 0x714370)) {   // GetTaken: reserved or in use
    *(u32 *)data = (*(u32 *)(self + 0x88) != 0 || ext_5c94f0(self) != 0) ? 1 : 0;
  } else if (msg == G(u16, 0x71437c)) {   // GetReservedBy
    *(u32 *)data = *(u32 *)(self + 0x88);
  } else if (msg == G(u16, 0x714374)) {   // MakeReservation(ref) for 2 seconds; refused (logged) if someone else holds it
    u32 by = *(u32 *)(self + 0x88);
    if (by != 0 && by != (u32)data) {
      void *lg = G(void *, 0x700390);
      void *pr = ((logOpen)VT(lg, 0x20))(lg, (const char *)0x6b49b8, 0x11e);
      ((logPrintf)VT(pr, 0x2c))(pr, (const char *)0x6b4a48);
      return 0;
    }
    ext_5c9130(self, (u32)data, 2.0f);
  }
  return 0;
}
PCREG(5c8a80, command);
