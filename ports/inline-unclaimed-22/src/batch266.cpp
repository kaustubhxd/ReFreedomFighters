// batch266.cpp - area 22 gameplay-core batch (docs/20-unclaimed-22.md, "Gameplay core, batch266"): the CAction constructor
// (base of every scripted action, including the hero's throw and close-combat actions). Name from the GameCube name map.
#include "ff.h"

extern "C" void THISCALL ext_469870(u8 *self);   // base constructor (verified in inline-mountedgun; runs as exe code)

// {message name, global word} in registration order; lines 0x331 + index in action.cpp (0x68f6b4).
static const u32 kActionMsgs[13][2] = {
    {0x68f7e8u, 0x7002acu}, {0x68f800u, 0x7002b0u}, {0x68f814u, 0x7002b4u}, {0x689714u, 0x7002c0u},
    {0x689728u, 0x7002c4u}, {0x68f828u, 0x7002c8u}, {0x68f838u, 0x7002ccu}, {0x68f84cu, 0x7002d0u},
    {0x68f860u, 0x7002d4u}, {0x68f870u, 0x7002b8u}, {0x68f880u, 0x7002bcu}, {0x68f890u, 0x7002d8u},
    {0x68f8a0u, 0x7002dcu}};

// 0x49f2d0 CAction::CAction() (no args), returns this: base constructor 0x469870; flag 0x20 at +4; +0x44 = 0; vtable
// 0x68f5e8; +0x6a, +0x76, +0x7a, +0x7e, +0x106, +0x102 = 0; registers the 13 action messages (engine db vt[0x114]) into
// their global words; word +0x4c = 0, +0x4e = +0x52 = 0, +0x48 = 1, +0x56 = 5.
static u8 *THISCALL actionCtor_49f2d0(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x68f5e8u;
  *(u32 *)(self + 0x6a) = 0;
  *(u32 *)(self + 0x76) = 0;
  *(u32 *)(self + 0x7a) = 0;
  *(u32 *)(self + 0x7e) = 0;
  *(u32 *)(self + 0x106) = 0;
  *(u32 *)(self + 0x102) = 0;
  for (u32 i = 0; i < 13; i++)
    *(u16 *)kActionMsgs[i][1] =
        (u16)vcall<u32>(*(u8 **)(*(u8 **)0x70039cu + 0x9b), 0x114, kActionMsgs[i][0], 0u, 0x68f6b4u, 0x331u + i);
  *(u16 *)(self + 0x4c) = 0;
  *(u32 *)(self + 0x4e) = 0;
  *(u32 *)(self + 0x52) = 0;
  *(u32 *)(self + 0x48) = 1;
  *(u32 *)(self + 0x56) = 5;
  return self;
}
PCREG(49f2d0, actionCtor_49f2d0);
