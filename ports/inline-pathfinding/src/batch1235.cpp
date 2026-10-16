// batch1235.cpp - pathfinding tree: door blockers and the path user profile [map 0x4875d0 GetUser, 0x4875e0
// CDoorBlocker::isOpen, 0x487490 CDoorBlocker::Activate, 0x487550 CPathUserProfile::CanOpenDoor, 0x560360 CanPassPerson].
// The profile holds a word at +4, a dword at +6 (GetUser), and two flags at +0xa / +0xb. The door's +4 dword is its
// geometry key. The message table (engine +0x9b) answers slot 0x4c (one value) and slot 0x114 (five words, returns a
// word); the user object (the profile's slot 8) takes the door state through its slot 0x130.
#include "pf.h"

static u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static u16 rd16u(const u8 *p) { u16 v; __builtin_memcpy(&v, p, 2); return v; }

// 0x4875d0 CPathUserProfile::GetUser() const: the dword at +6 (unaligned). thiscall, no arguments.
static u32 THISCALL profileGetUser(u8 *self) { return rd32u(self + 6); }
PCREG(4875d0, profileGetUser);

// 0x4875e0 CDoorBlocker::isOpen(const CPathUserProfile *p): no profile means open; otherwise the profile's slot 0
// (CanOpenDoor) with the door's +4 dword. thiscall, ret 4, returns al.
static u8 THISCALL doorIsOpen(u8 *door, u8 *profile) {
  if (!profile) return 1;
  return vcall<u8>(profile, 0, rd32u(door + 4));
}
PCREG(4875e0, doorIsOpen);

// 0x487490 CDoorBlocker::Activate(const CPathUserProfile *p): the user is p's slot 8 object. With p's +0xa flag set the
// message table reports (0x68cf28, 0x60) and the user's slot 0x130 gets the door's +4 dword and the result. The message
// table then reports the user (slot 0x4c) with the string 0x68cf34 (+0xb set) or 0x68cf40 (clear), and the user's slot
// 0x130 gets the door's +4 dword and that result. thiscall, ret 4.
static void THISCALL doorActivate(u8 *door, u8 *profile) {
  u8 *user = vcall<u8 *>(profile, 8);
  if (profile[0xa]) {
    u8 *msg = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u32 r0 = vcall<u32>(msg, 0x114, (u32)0x68cf28, (u32)0, (u32)0x68cee8, (u32)0x60, (u32)0);
    vcall<void>(user, 0x130, rd32u(door + 4), (u32)(u16)r0);
  }
  u8 *msg = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 v = vcall<u32>(msg, 0x4c, user);
  u32 r;
  if (profile[0xb]) {
    r = vcall<u32>(msg, 0x114, (u32)0x68cf34, (u32)0, (u32)0x68cee8, (u32)0x67, v);
  } else {
    r = vcall<u32>(msg, 0x114, (u32)0x68cf40, (u32)0, (u32)0x68cee8, (u32)0x69, v);
  }
  vcall<void>(user, 0x130, rd32u(door + 4), (u32)(u16)r);
}
PCREG(487490, doorActivate);

// 0x487550 CPathUserProfile::CanOpenDoor(ZGEOM *g): the message table's slot 0x4c gives a value from the profile's +6
// dword; the geometry's slot 0x128 gets the profile's +4 word, a pointer to that value, and 0 (it may write the value).
// The answer is whether the value is non-zero afterwards. thiscall, ret 4, returns al.
static u8 THISCALL profileCanOpenDoor(u8 *self, u8 *geom) {
  u8 *msg = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 v = vcall<u32>(msg, 0x4c, rd32u(self + 6));
  vcall<void>(geom, 0x128, (u32)rd16u(self + 4), &v, (u32)0);
  return v != 0;
}
PCREG(487550, profileCanOpenDoor);

// 0x560360 CPathUserProfile::CanPassPerson(ZLNKOBJ*) const: never passes (xor al,al). thiscall, ret 4.
static u8 THISCALL profileCanPassPerson(u8 *self, u8 *obj) {
  (void)self;
  (void)obj;
  return 0;
}
PCREG(560360, profileCanPassPerson);
