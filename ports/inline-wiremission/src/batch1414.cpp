// batch1414.cpp - missions thread, batch 1414: ZFFCareTaker_C01A construction and destruction.
// The MSVC SEH frame (fs:[0] push/pop around the body) is left out: it only matters while a C++ exception unwinds,
// and the TEB is restored to the same value on return.
#include "missions.h"

extern "C" void THISCALL ext_469870(u8 *ev);   // ZEventBase::ZEventBase()
extern "C" u8 *ext_41e290(u32 size);           // operator new (cdecl)
extern "C" u8 *THISCALL ext_4d8330(u8 *dv, const char *group, const char *desc, void *var);   // debug variable ctor
#define CARETAKER_C01A_CPP 0x6b290cu

static inline u8 *sysi() { return G(u8 *, 0x70039c); }
static inline u8 *mgr() { return *(u8 **)(sysi() + 0x9b); }
static inline u16 msgId(const char *name, u32 line) {
  return vcall<u16, const char *, u32, const char *, u32>(mgr(), 0x114, name, 0, (const char *)CARETAKER_C01A_CPP, line);
}

// 0x5b9880 ZFFCareTaker_C01A::ZFFCareTaker_C01A(): ZEventBase base, vtable 0x6b2864, fields cleared (+0x64/+0x65
// start as 1), a debug variable "tutorial" / "jump to tutorial (0-12)" bound to +0x48 registered with the engine
// (sys slot 0x1a4; kept at +0x80), and the message ids CompletedAct, StartAct, SelectedItem, PlaySynchronizedAnim,
// Activate, msgCloseToStairs, msgDownStairs cached at +0x72..+0x7e.
static u8 *THISCALL c01aCtor(u8 *ct) {
  ext_469870(ct);
  *(u32 *)(ct + 4) |= 0x20;
  *(u32 *)(ct + 0x44) = 0;
  *(u32 *)ct = 0x6b2864;
  *(u32 *)(ct + 0xb4) = 0;
  *(u32 *)(ct + 0xb9) = 0;
  *(u32 *)(ct + 0x48) = 0;
  *(u32 *)(ct + 0x60) = 0;
  ct[0xbd] = 0;
  *(u16 *)(ct + 0x64) = 0x101;
  *(u32 *)(ct + 0x5c) = 0;
  u8 *dv = ext_41e290(0x108);
  dv = dv ? ext_4d8330(dv, (const char *)0x6b2900, (const char *)0x6b28e8, ct + 0x48) : 0;
  *(u8 **)(ct + 0x80) = dv;
  vcall<void, u8 *>(sysi(), 0x1a4, dv);
  *(u16 *)(ct + 0x72) = msgId((const char *)0x6b2944, 0x31);   // CompletedAct
  *(u16 *)(ct + 0x74) = msgId((const char *)0x6a5628, 0x32);   // StartAct
  *(u16 *)(ct + 0x76) = msgId((const char *)0x6a5634, 0x33);   // SelectedItem
  *(u16 *)(ct + 0x78) = msgId((const char *)0x6a56dc, 0x34);   // PlaySynchronizedAnim
  *(u16 *)(ct + 0x7a) = msgId((const char *)0x682e18, 0x35);   // Activate
  *(u16 *)(ct + 0x7c) = msgId((const char *)0x6b2954, 0x36);   // msgCloseToStairs
  *(u16 *)(ct + 0x7e) = msgId((const char *)0x6b2968, 0x37);   // msgDownStairs
  return ct;
}
PCREG(5b9880, c01aCtor);

// 0x5b9a60 ZFFCareTaker_C01A::~ZFFCareTaker_C01A() body (no GameCube name; the deleting destructor calls it):
// unregisters and deletes the debug variable, clears +0x44/+0x30, ZEventBase vtable 0x686874, and unregisters the
// event (manager slot 0x34).
extern "C" void THISCALL m_5b9a60(u8 *ct) {
  *(u32 *)ct = 0x6b2864;
  vcall<void, u32>(sysi(), 0x1a8, *(u32 *)(ct + 0x80));
  u8 *dv = *(u8 **)(ct + 0x80);
  if (dv)
    vcall<void, u32>(dv, 0, 1);
  *(u32 *)(ct + 0x44) = 0;
  *(u32 *)(ct + 0x30) = 0;
  *(u32 *)ct = 0x686874;
  vcall<void, u8 *>(mgr(), 0x34, ct);
}
PCREG(5b9a60, m_5b9a60);

// 0x5b9af0 ZFFCareTaker_C01A deleting destructor (flags): the body, then with flag 1 the memory goes back: flag 4
// through the no-op sized delete (0xca bytes), otherwise through the engine's free hook [0x7003b0] (int3 if unset).
static u8 *THISCALL c01aDtor(u8 *ct, u32 flags) {
  m_5b9a60(ct);
  return deletingDtor(ct, flags, 0xca);
}
PCREG(5b9af0, c01aDtor);

extern "C" const char *THISCALL ext_4cc1d0(void *s);   // MYSTR -> const char*
extern "C" void THISCALL ext_4cbec0(void *s);          // MYSTR::~MYSTR()

// 0x5b9c00 ZFFCareTaker_C01A::BeamActor(ZActor*, ZGEOM*): moves the actor to the geom's matrix and position (actor
// slots 0x370(mat, pos) and 0x5dc(pos, mat)), then logs "BeamActor  actor[%s], room[%s]" with the names (slot 0x1d8
// returns a MYSTR) of the actor and of the room it is in now (actor slot 0x660 -> manager slot 0x58).
static void THISCALL c01aBeamActor(u8 *ct, u8 *actor, u8 *geom) {
  (void)ct;
  float mat[9], pos[3];
  vcall<void, float *, float *>(geom, 0x80, mat, pos);
  vcall<void, float *, float *>(actor, 0x370, mat, pos);
  vcall<void, float *, float *>(actor, 0x5dc, pos, mat);
  u32 r = vcall<u32>(actor, 0x660);
  u8 *room = vcall<u8 *, u32>(mgr(), 0x58, r);
  void *pr = logOpenAt((const char *)CARETAKER_C01A_CPP, 0xf5);
  u8 roomName[0x80], actorName[0x80];
  void *s1 = vcall<void *, u8 *, u32>(room, 0x1d8, roomName, 1);
  void *s2 = vcall<void *, u8 *, u32>(actor, 0x1d8, actorName, 1);
  const char *c1 = ext_4cc1d0(s1);
  const char *c2 = ext_4cc1d0(s2);
  ((logPrintf)(*(void ***)pr)[0x2c / 4])(pr, (const char *)0x6b2994, c2, c1);
  ext_4cbec0(actorName);
  ext_4cbec0(roomName);
}
PCREG(5b9c00, c01aBeamActor);
