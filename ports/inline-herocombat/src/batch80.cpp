// batch80.cpp - two small ones, inline session batch 80: ZShotActivate::Init (0x4c8df0) and ZFFSimpleTrain2::Command
// (0x5b8530). Stop (0x5b9250) is exe code.
#include "ff.h"

extern "C" void THISCALL ext_5b9250(u8 *self);  // ZFFSimpleTrain2::Stop()

// 0x4c8df0 ZShotActivate::Init(), thiscall, ret 0: the flag at +0x58 is cleared.
static void THISCALL saInit(u8 *self) { *(u8 *)(self + 0x58) = 0; }
PCREG(4c8df0, saInit);

// 0x5b8530 ZFFSimpleTrain2::Command(unsigned short cmd, void *data), thiscall, ret 8: when cmd (the low word) equals
// the word at +0xdb, Stop(). Returns 0.
static u32 THISCALL trainCommand(u8 *self, u32 cmd, void *) {
  if ((u16)cmd == *(u16 *)(self + 0xdb))
    ext_5b9250(self);
  return 0;
}
PCREG(5b8530, trainCommand);
