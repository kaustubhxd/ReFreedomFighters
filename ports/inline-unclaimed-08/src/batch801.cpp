// batch801.cpp - unclaimed-08: three small CORE functions (docs/20-unclaimed-08.md). Thiscall, names are from the GC
// name map (naming only; the bodies are from the PC bytes).
#include "ff.h"

// 0x4fb8b0, CCHECKOBJINOBJ::Init() (high): clears the byte at this+0x48, then calls vtable +0x4c of the object at
// ZSysInterface+0x9b with the dword at this+0x44 as its one argument, and stores the returned eax at this+0x49.
static void THISCALL checkObjInObjInit(u8 *self) {
  u32 arg = *(u32 *)(self + 0x44);
  self[0x48] = 0;
  u8 *sys = *(u8 **)0x70039c;
  u8 *child = *(u8 **)(sys + 0x9b);
  *(u32 *)(self + 0x49) = vcall<u32>(child, 0x4c, arg);
}
PCREG(4fb8b0, checkObjInObjInit);

// 0x4fc140, CMAINCAMERACONTROL::End() (high): if ZSysInterface+0x1907 is set, calls its vtable +0x14 with the
// string address 0x67d9e8 as the one argument. `this` is not read.
static void THISCALL mainCameraControlEnd(u8 *self) {
  (void)self;
  u8 *sys = *(u8 **)0x70039c;
  u8 *obj = *(u8 **)(sys + 0x1907);
  if (obj) vcall<void>(obj, 0x14, (u32)0x67d9e8);
}
PCREG(4fc140, mainCameraControlEnd);

// 0x47aa80, ZActor::OnViewEnter() (high): the counter at this+0x640 goes up by one. Only the first entry (old value
// 0) calls vtable +0xbc of this with the old counter, and only if the object at this+8 has no 0x800 bit in its
// dword at +0x3c.
static void THISCALL actorOnViewEnter(u8 *self) {
  u32 n = *(u32 *)(self + 0x640);
  *(u32 *)(self + 0x640) = n + 1;
  if (n == 0) {
    u8 *owner = *(u8 **)(self + 8);
    if (!(*(u32 *)(owner + 0x3c) & 0x800)) vcall<void>(self, 0xbc, n);
  }
}
PCREG(47aa80, actorOnViewEnter);

// 0x592d20, ZFFHERO::Load3() (high): stores GetGameOSD(byte(this+0x684) - 1) at this+0x852. The call is inlined:
// 0x589c20 (ZFFGameData::GetGameOSD, verified in docs/20-soundtimers.md) reads the signed byte argument and returns
// the dword at game data +0x2c2d + 4*index. The global 0x7003b8 is the game data object (ecx for the call).
static void THISCALL heroLoad3(u8 *self) {
  u8 arg = (u8)(self[0x684] - 1);
  u8 *gamedata = *(u8 **)0x7003b8;
  s32 idx = (s8)arg;
  *(u32 *)(self + 0x852) = *(u32 *)(gamedata + 0x2c2d + 4 * idx);
}
PCREG(592d20, heroLoad3);
