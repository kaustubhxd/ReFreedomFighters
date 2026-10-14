// batch35004.cpp - cascade s5 batch 35004: 0x511ad0 (GUESS construct, use and tear down five stack objects in one 0x2fc8-byte frame).
#include "ff.h"

extern "C" void ext_4690b0();                              // 1-byte function (plain ret)
extern "C" void THISCALL ext_514940(u8 *self, u32 a, u32 b, u32 c);   // ret 0xc
extern "C" void THISCALL ext_517050(u8 *self, u32 a, u32 b, u32 c);   // ret 0xc
extern "C" void THISCALL ext_51b790(u8 *self, u32 a, u32 b, u32 c);   // ret 0xc
extern "C" void THISCALL ext_51f3e0(u8 *self, u32 a, u32 b, u32 c);   // ret 0xc
extern "C" void THISCALL ext_520110(u8 *self, u32 a, u32 b, u32 c);   // ret 0xc
extern "C" void THISCALL ext_511950(u8 *self);
extern "C" void THISCALL ext_511a00(u8 *self);
extern "C" void THISCALL ext_512070(u8 *self);
extern "C" void THISCALL ext_51f4c0(u8 *self);

// 0x511ad0, no arguments, one 0x2fc8-byte frame (EBP = frame + 0x2fc8, frame offsets below are EBP-relative): five objects are constructed in turn
// (0x514940 at -0x2dc, 0x517050 at -0x1f10, 0x51b790 at -0x8b8, 0x51f3e0 at -0x1fd8, 0x520110 at -0x2fc8, each with three zero arguments), used
// (0x511950 at -0x1c38, 0x4690b0 at -0x40b, 0x51f4c0 at -0x1fd8, 0x511a00 at -0x2ccb) and destroyed with 0x512070 (not for the -0x1fd8 one, whose 0x51f4c0 ends in it).
static void fn511ad0() {
  u8 frame[0x2fc8];
  u8 *e = frame + 0x2fc8;
  ext_4690b0();
  ext_4690b0();
  ext_4690b0();
  ext_514940(e - 0x2dc, 0, 0, 0);
  ext_512070(e - 0x2dc);
  ext_517050(e - 0x1f10, 0, 0, 0);
  ext_511950(e - 0x1c38);
  ext_512070(e - 0x1f10);
  ext_4690b0();
  ext_4690b0();
  ext_4690b0();
  ext_51b790(e - 0x8b8, 0, 0, 0);
  ext_4690b0();
  ext_512070(e - 0x8b8);
  ext_51f3e0(e - 0x1fd8, 0, 0, 0);
  ext_51f4c0(e - 0x1fd8);
  ext_520110(e - 0x2fc8, 0, 0, 0);
  ext_511a00(e - 0x2ccb);
  ext_512070(e - 0x2fc8);
}
PCREG(511ad0, fn511ad0);
