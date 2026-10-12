// batch271.cpp - area 22 gameplay-core batch (docs/20-unclaimed-22.md, "Gameplay core, batch271"): the ZMoveOnSpline
// constructor (spline movers: trains, tanks, helicopters and other scripted vehicles). Name from the GameCube name map
// (high); behaviour from the PC bytes.
#include "ff.h"

extern "C" void THISCALL ext_43e990(u8 *self, u32 info, u32 name, u32 parent);  // base geom constructor (GUESS: hooked)
extern "C" u8 *__attribute__((cdecl)) ext_41e290(u32 size);                    // operator new (unclaimed-64)
extern "C" u8 *THISCALL ext_522e80(u8 *p);                                      // 0x67-byte helper ctor (inline-batch45)
extern "C" u8 *THISCALL ext_4ccba0(u8 *p);                                      // REFTAB32 ctor (GUESS: hooked)
extern "C" u8 *THISCALL ext_4ccbe0(u8 *p, u32 n, u32 grow);                     // table ctor (inline-batch45)

// {message name, field} in registration order; lines 0x2e + index in movespline.cpp (0x69e4bc).
static const u32 kMosMsgs[10][2] = {
    {0x68a994u, 0x1fd}, {0x69e4f0u, 0x203}, {0x69e500u, 0x205}, {0x692ae4u, 0x207}, {0x690640u, 0x209},
    {0x690650u, 0x20b}, {0x69e514u, 0x20d}, {0x682e18u, 0x20f}, {0x69c848u, 0x211}, {0x69c85cu, 0x213}};

// 0x511cd0 ZMoveOnSpline::ZMoveOnSpline(ZGEOMCLASSINFO *, const char *, ZBaseGeom *) ret 0xc, returns this. Base geom
// constructor 0x43e990; vtable 0x69e15c; clears the spline state, speed 1000 (+0xc8), flags; registers ten messages (engine
// db vt 0x114, lines 0x2e..0x37) into words +0x1fd..+0x213; allocates the 0x67-byte helper (+0x5c), a REFTAB32 (+0x127)
// and two tables (+0x12b (0x20, 4), +0x1ed (8, 0)), each null when the allocation fails; adds itself to the global mover
// list at [0x7003b8] (+0x41c count, +0x420 entries).
u8 *THISCALL mosCtor_511cd0(u8 *self, u32 info, u32 name, u32 parent) {
  ext_43e990(self, info, name, parent);
  *(u32 *)self = 0x69e15cu;
  *(u32 *)(self + 0xda) = 0;
  *(u32 *)(self + 0x144) = 0;
  *(u32 *)(self + 0xce) = 0;
  *(u32 *)(self + 0xd2) = 0;
  *(u32 *)(self + 0xd6) = 0;
  self[0x11e] = 1;
  *(u32 *)(self + 0x11f) = 0;
  *(u32 *)(self + 0xc8) = 0x447a0000u;  // 1000.0f
  *(u16 *)(self + 0xcc) = 0x101;
  *(u32 *)(self + 0xc4) = 1;
  for (u32 i = 0; i < 10; i++)
    *(u16 *)(self + kMosMsgs[i][1]) =
        (u16)vcall<u32>(*(u8 **)(*(u8 **)0x70039cu + 0x9b), 0x114, kMosMsgs[i][0], 0u, 0x69e4bcu, 0x2eu + i);
  *(u32 *)(self + 0x12f) = 0;
  *(u32 *)(self + 0x123) = 0;
  *(u32 *)(self + 0x1d1) = 0;
  *(u32 *)(self + 0x1dd) = 0;
  *(u32 *)(self + 0x1e1) = 0;
  *(u32 *)(self + 0x1e5) = 0;
  *(u32 *)(self + 0x1e9) = 0;
  *(u32 *)(self + 0x1c1) = 0;
  *(u32 *)(self + 0x1c5) = 0;
  *(u32 *)(self + 0x1c9) = 0xbf800000u;  // -1.0f
  *(u32 *)(self + 0x159) = 0;
  self[0x133] = 0;
  u8 *p = ext_41e290(0x67);
  *(u8 **)(self + 0x5c) = p ? ext_522e80(p) : 0;
  p = ext_41e290(0xac);
  *(u8 **)(self + 0x127) = p ? ext_4ccba0(p) : 0;
  p = ext_41e290(0x1c);
  *(u8 **)(self + 0x12b) = p ? ext_4ccbe0(p, 0x20, 4) : 0;
  *(u32 *)(self + 0x134) = 0;
  *(u32 *)(self + 0x138) = 0;
  u8 *lst = *(u8 **)0x7003b8u;
  *(u8 **)(lst + 0x420 + *(u32 *)(lst + 0x41c) * 4) = self;
  *(u32 *)(lst + 0x41c) += 1;
  p = ext_41e290(0x1c);
  *(u8 **)(self + 0x1ed) = p ? ext_4ccbe0(p, 8, 0) : 0;
  self[0x215] = 0;
  return self;
}
PCREG(511cd0, mosCtor_511cd0);
