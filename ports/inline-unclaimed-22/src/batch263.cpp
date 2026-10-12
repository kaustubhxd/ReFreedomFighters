// batch263.cpp - area 22 gameplay-core batch (docs/20-unclaimed-22.md, "Gameplay core, batch263"): spline vehicle level
// data and the fire controller (burning objects) constructor. Names from the GameCube name map; behaviour from the PC bytes.
#include "ff.h"

extern "C" void THISCALL ext_43f900(u8 *self, u8 *d);          // ZGROUP::CopyDataBlock (hooked, GUESS stub)
extern "C" void THISCALL ext_4e12e0(u8 *d, u32 *dst, u32 n);   // DBLK::Get(unsigned*, int) (hooked, GUESS stub)
extern "C" u32 THISCALL ext_4e1600(u8 *d);                     // DBLK::GetType (hooked, GUESS stub; al)
extern "C" void THISCALL ext_4e14a0(u8 *d, u8 *dst, u32 n);    // DBLK::Get(bool*, int) (hooked, GUESS stub)
extern "C" void THISCALL ext_4e1b30(u8 *d);                    // DBLK::NextBlock (hooked, GUESS stub)
extern "C" void THISCALL ext_469870(u8 *self);                 // base constructor (verified in inline-mountedgun; runs as exe code)

#define DB (*(u8 **)(*(u8 **)0x70039cu + 0x9b))

// 0x512850 ZMoveOnSpline::CopyDataBlock(DBLK *d) ret 4: the group's CopyDataBlock, three words (+0xce, +0xd6, +0x12f);
// two optional geom references (type 8: an id turned into a geom with db vt[0x58], else 0) into +0x134 and +0x138; an
// optional bool (type 3) into +0x133; then NextBlock.
static void THISCALL copyDataBlock_512850(u8 *self, u8 *d) {
  ext_43f900(self, d);
  ext_4e12e0(d, (u32 *)(self + 0xce), 1);
  ext_4e12e0(d, (u32 *)(self + 0xd6), 1);
  ext_4e12e0(d, (u32 *)(self + 0x12f), 1);
  u32 id;
  if ((u8)ext_4e1600(d) == 8) {
    ext_4e12e0(d, &id, 1);
    *(u32 *)(self + 0x134) = vcall<u32>(DB, 0x58, id);
  } else {
    *(u32 *)(self + 0x134) = 0;
  }
  if ((u8)ext_4e1600(d) == 8) {
    ext_4e12e0(d, &id, 1);
    *(u32 *)(self + 0x138) = vcall<u32>(DB, 0x58, id);
  } else {
    *(u32 *)(self + 0x138) = 0;
  }
  if ((u8)ext_4e1600(d) == 3) ext_4e14a0(d, self + 0x133, 1);
  ext_4e1b30(d);
}
PCREG(512850, copyDataBlock_512850);

// 0x581410 CFireController::CFireController() (no args), returns this: base constructor 0x469870; flag 0x20 at +4;
// +0x44, +0x4c, +0x750, +0xa58 = 0; vtable 0x6ab5c8; registers itself at [0x7003b8]+0x2c51; +0xa54 = &this[+0x754]
// (the table at 0x754 indexed by +0x750); messages "DangerBox" and "DamageInfo" are registered (db vt[0x114], Explode.cpp
// lines 0x4aa and 0x4ab) into the words at 0x714270 and 0x714274; +0xa5c = ([render manager +0x1a9f])->vt[0x68]
// ("*Molotov_Stand") when that object exists, else 0; +0xa60 = 0.
static u8 *THISCALL fireControllerCtor_581410(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x6ab5c8u;
  *(u32 *)(self + 0x4c) = 0;
  *(u32 *)(self + 0x750) = 0;
  *(u32 *)(self + 0xa58) = 0;
  *(u8 **)(*(u8 **)0x7003b8u + 0x2c51) = self;
  *(u8 **)(self + 0xa54) = self + 4 * (*(u32 *)(self + 0x750) + 0x1d5);
  *(u16 *)0x714270u = (u16)vcall<u32>(DB, 0x114, 0x6a567cu, 0u, 0x6ab6d4u, 0x4aau);
  *(u16 *)0x714274u = (u16)vcall<u32>(DB, 0x114, 0x69eaacu, 0u, 0x6ab6d4u, 0x4abu);
  *(u32 *)(self + 0xa5c) = 0;
  u8 *m = *(u8 **)(*(u8 **)0x70039cu + 0x1a9f);
  if (m) *(u32 *)(self + 0xa5c) = vcall<u32>(m, 0x68, 0x6ab74cu);
  *(u32 *)(self + 0xa60) = 0;
  return self;
}
PCREG(581410, fireControllerCtor_581410);
#undef DB
