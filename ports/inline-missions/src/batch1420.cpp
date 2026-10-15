// batch1420.cpp - missions thread, batch 1420: ZFFCareTaker_C03B (the second bridge director: the fuel tank that
// blows up sets the mission variable SETMISSIONVAR on the level controller).
//
// Layout: +0x44 event sender, +0x48 message id ("FuelTankExploded" registered in the constructor; the id is compared with
// the incoming message). GUESS: the handle found under "LevelController" is an object whose slot 0x128(msgId) is the
// "send message" call; that object is not the ZFFLevelController vtable (its slot 0x128 is out of range).
#include "missions.h"

extern "C" void THISCALL ext_469870(u8 *ev);   // ZEventBase::ZEventBase()
#define CARETAKER_C03B_CPP 0x6b2e8cu

static inline u8 *sysi() { return G(u8 *, 0x70039c); }
static inline u8 *mgr() { return *(u8 **)(sysi() + 0x9b); }
static inline u16 msgId(const char *name, u32 line) {
  return vcall<u16, const char *, u32, const char *, u32>(mgr(), 0x114, name, 0, (const char *)CARETAKER_C03B_CPP, line);
}

// 0x5bc1d0 ZFFCareTaker_C03B::ZFFCareTaker_C03B(): event base, vtable 0x6b2e08, message id "FuelTankExploded" at +0x48.
static u8 *THISCALL c03bCtor(u8 *ct) {
  if (!ct)
    return 0;
  ext_469870(ct);
  *(u32 *)(ct + 4) |= 0x20;
  *(u32 *)(ct + 0x44) = 0;
  *(u32 *)ct = 0x6b2e08;
  *(u16 *)(ct + 0x48) = msgId((const char *)0x6b2ec4, 0x13);
  return ct;
}
PCREG(5bc1d0, c03bCtor);

// 0x5bc2f0 ZFFCareTaker_C03B deleting destructor: the ZEventBase part (sender cleared, vtable 0x686874, manager slot
// 0x34 unregisters). Object size 0x4a (the sized free of the flag-4 path).
static u8 *THISCALL c03bDtor(u8 *ct, u32 flags) {
  *(u32 *)(ct + 0x44) = 0;
  *(u32 *)(ct + 0x30) = 0;
  *(u32 *)ct = 0x686874;
  vcall<void, u8 *>(mgr(), 0x34, ct);
  return deletingDtor(ct, flags, 0x4a);
}
PCREG(5bc2f0, c03bDtor);

// 0x5bc3e0 ZFFCareTaker_C03B::Command(unsigned short msg, void *data). On its own message: logs "MESSAGE RECEIVED:
// FuelTankExploded" (line 0x1b), looks up "LevelController", and when found sends SETMISSIONVAR (registered as the
// message id) to the controller's object with slot 0x128. Returns 0.
static u32 THISCALL c03bCommand(u8 *ct, u32 msg, u32 data) {
  (void)data;
  if ((u16)msg != *(u16 *)(ct + 0x48))
    return 0;
  LOGF(CARETAKER_C03B_CPP, 0x1b, (const char *)0x6b2ed8);
  u8 *reg = vcall<u8 *>(mgr(), 0x138);
  u32 h = 0;
  vcall<u32, const char *, u32 *>(reg, 0x88, (const char *)0x6a5c48, &h);   // LevelController
  u8 *obj = vcall<u8 *, u32>(mgr(), 0x58, h);
  if (obj) {
    // The original pushes six words for this register call (the constructor's call pushes four). GUESS: the two
    // extras are a second name ("C03BS_Helipad") and a zero; the callee pops all six.
    typedef u16(THISCALL * reg6)(void *self, const char *name, u32 zero, const char *file, u32 line, const char *extra, u32 zero2);
    u16 mid = ((reg6)(*(void ***)mgr())[0x114 / 4])(mgr(), (const char *)0x6a5c58, 0, (const char *)CARETAKER_C03B_CPP, 0x20,
                                                    (const char *)0x6b0520, 0);   // SETMISSIONVAR
    u16 id = mid;
    vcall<void, u32>(obj, 0x128, (u32)id);
  }
  return 0;
}
PCREG(5bc3e0, c03bCommand);
