// batch813.cpp - unclaimed-08 batch 13 (slice floor(addr/16) mod 20 = 7): two small functions.
#include "ff.h"

// 0x488430, ZMovementGuide::ClassInit2() (medium name). Thiscall, no arguments, ret. The engine's object at
// ZSysInterface+0x9b+0xadc: vtable +0x25c with the string 0x68d404 and 0 (two arguments, callee pops); the result is
// stored at this+0x375.
static void THISCALL movementGuideClassInit2(u8 *self) {
  u8 *sys = *(u8 **)0x70039c;
  u8 *db = *(u8 **)(sys + 0x9b);
  u8 *ref = *(u8 **)(db + 0xadc);
  *(u32 *)(self + 0x375) = vcall<u32>(ref, 0x25c, (u32)0x68d404, (u32)0);
}
PCREG(488430, movementGuideClassInit2);

// 0x5dd470, ZFFMortar::PlayAnimation(ZIKLNKOBJ*, char*) (high). Stdcall (ret 8): the first argument is the object.
// Its vtable +0x21c with the name returns r; then vtable +0x228 with (r, 1, 0, -1.0f, 1.0f) (callee pops 0x14).
static void STDCALL mortarPlayAnimation(u8 *self, const char *name) {
  u32 r = vcall<u32>(self, 0x21c, (u32)name);
  vcall<void>(self, 0x228, r, (u32)1, (u32)0, -1.0f, 1.0f);
}
PCREG(5dd470, mortarPlayAnimation);
