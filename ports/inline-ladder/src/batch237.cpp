// batch237.cpp - ZLNKWHANDS::ZLNKWHANDS(ZGEOMCLASSINFO*, const char*, ZBaseGeom*) (inline-ladder thread, 2026-10-11).
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))
#define U16(p, off) (*(u16 *)((u8 *)(p) + (off)))

extern "C" void THISCALL ext_468030(void *self, u32 ci, u32 name, u32 parent);   // ZCTRLIKLNKOBJ::ZCTRLIKLNKOBJ (base)
extern "C" void THISCALL ext_465650(void *target);                               // ZTARGET::ZTARGET

static const char *const kFileH = (const char *)0x68961c;   // "..\..\code\engine\geomsextend\zlnkwhands.cpp"

// Register a render-manager message: database slot 0x114 (msg, 0, file, line); the low word is the id.
static inline u16 regMsg(const char *msg, u32 line) {
  u32 db = U32(G(u32, 0x70039c), 0x9b);
  return (u16)vcall<u32>((void *)db, 0x114, msg, 0u, kFileH, line);
}

// 0x471b50 ZLNKWHANDS constructor [GC 80187f54, high], thiscall, ret 0xc, returns this. Base ZCTRLIKLNKOBJ constructor,
// vtable 0x6890a4, two ZTARGETs (+0x26a, +0x2eb), a third ZTARGET (+0x353) and the defaults below. Then the message ids:
// the hand inventory messages (+0x34d left, +0x3b5 right), and the global ids 0x6ff9a0 (PUSHBUTTON), 0x6ff9a4 (DROPITEM),
// 0x6ff9a8 (USEITEM), 0x6ff9ac (PICKUPITEM), 0x6ff9b0 (CANPICKUPITEM), 0x6ff9b4 (ENTERITEMRANGE), 0x6ff9b8 (LEAVEITEMRANGE),
// 0x6ff9bc (RELOADWEAPON), 0x6ff99c (CALCMATS), plus +0x165 ActivateObject. Line numbers are the source lines in the
// message registration (0x13, 0x15, 0xbe..0xc9 in zlnkwhands.cpp).
// Defaults (floats as hex in the exe): +0x345 = -4.0 (0xc0800000); +0x3ea..+0x40a = 1.0, 4.0 at +0x3fe, 10.0 at +0x402,
// 15.0 at +0x406 (0x40800000, 0x41200000, 0x41700000); +0x1e2 = 1.0. GUESS: the +0x3ea..+0x40e block is per-hand pose
// scales; the constants come from the exe, their meaning is not known.
static void *THISCALL handsCtor(u8 *self, u32 ci, u32 name, u32 parent) {
  ext_468030(self, ci, name, parent);
  U32(self, 0) = 0x6890a4;
  ext_465650(self + 0x26a);
  ext_465650(self + 0x2eb);
  U32(self, 0x2e7) = 0x689080;
  U32(self, 0x341) = 0;
  U32(self, 0x345) = 0;
  U32(self, 0x349) = 0;
  U16(self, 0x34d) = regMsg((const char *)0x68964c, 0x13);   // MSG_INVERTORYSETACTIVELEFT
  U32(self, 0x33d) = 0x11;
  U32(self, 0x338) = 0;
  self[0x33c] = 0;
  ext_465650(self + 0x353);
  U32(self, 0x34f) = 0x689080;
  U32(self, 0x3a9) = 0;
  U32(self, 0x3ad) = 0;
  U32(self, 0x3b1) = 0;
  U16(self, 0x3b5) = regMsg((const char *)0x689668, 0x15);   // MSG_INVERTORYSETACTIVERIGHT
  U32(self, 0x3a5) = 0x15;
  U32(self, 0x3a0) = 0;
  self[0x3a4] = 0;
  U32(self, 0x341) = 0;
  U32(self, 0x345) = 0xc0800000u;
  U32(self, 0x349) = 0;
  U32(self, 0x3ea) = 0x3f800000u;
  U32(self, 0x3ee) = 0x3f800000u;
  U32(self, 0x3f2) = 0x3f800000u;
  U32(self, 0x3f6) = 0x3f800000u;
  U32(self, 0x3fa) = 0x3f800000u;
  U32(self, 0x3fe) = 0x40800000u;
  U32(self, 0x402) = 0x41200000u;
  U32(self, 0x406) = 0x41700000u;
  U32(self, 0x40a) = 0x3f800000u;
  U32(self, 0x40e) = 0x3f800000u;
  self[0x3bb] = 0;
  self[0x3e8] = 0;
  U32(self, 0x3b7) = 0;
  U32(self, 0x2e3) = 0;
  U32(self, 0x1e2) = 0x3f800000u;
  U32(self, 0x1e6) = 0;
  for (u32 off = 0x3bc; off <= 0x3e0; off += 4)
    U32(self, off) = 0;
  G(u16, 0x6ff9a0) = regMsg((const char *)0x6896c4, 0xbe);   // MSG_PUSHBUTTON
  G(u16, 0x6ff9a4) = regMsg((const char *)0x6896d4, 0xbf);   // MSG_DROPITEM
  G(u16, 0x6ff9a8) = regMsg((const char *)0x6896e4, 0xc0);   // MSG_USEITEM
  G(u16, 0x6ff9ac) = regMsg((const char *)0x6896f0, 0xc1);   // MSG_PICKUPITEM
  G(u16, 0x6ff9b0) = regMsg((const char *)0x689700, 0xc2);   // MSG_CANPICKUPITEM
  G(u16, 0x6ff9b4) = regMsg((const char *)0x689714, 0xc3);   // MSG_ENTERITEMRANGE
  G(u16, 0x6ff9b8) = regMsg((const char *)0x689728, 0xc4);   // MSG_LEAVEITEMRANGE
  U16(self, 0x165) = regMsg((const char *)0x68973c, 0xc5);   // ActivateObject
  G(u16, 0x6ff9bc) = regMsg((const char *)0x68974c, 0xc6);   // MSG_RELOADWEAPON
  G(u16, 0x6ff99c) = regMsg((const char *)0x689760, 0xc9);   // MSG_CALCMATS
  return self;
}
PCREG(471b50, handsCtor);
