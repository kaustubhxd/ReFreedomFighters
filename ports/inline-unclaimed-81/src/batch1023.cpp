// batch1023.cpp - area 81, batch 1023: ZShotActivate::Command(cmd, arg), 0x4c8860, GROUP 1 of a grown file. Thiscall, two stack arguments, ret 8.
// Group 1 covers the dispatch skeleton only: the command word is compared with the globals 0x700370 (group 2: the large branch) and 0x70036c (group 2:
// the branch that needs this+0x58 clear); both are trapped here, so the harness must not drive them. Other commands: when the word equals 0x700378 the
// argument is stored at this+0x59; the result is always 0 (the exe clears eax). The SEH frame and the cookie check are not reproduced.
#include "ff.h"

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x4c8860 ZShotActivate::Command(cmd, arg), group 1.
static u32 THISCALL shotActivateCommand(u8 *self, u32 cmdArg, u32 arg) {
  u16 cmd = (u16)cmdArg;
  if (cmd == *(u16 *)0x700370)
    __builtin_trap();   // group 2
  if (cmd == *(u16 *)0x70036c) {
    if (self[0x58] == 0)
      __builtin_trap(); // group 2
  }
  if (cmd == *(u16 *)0x700378)
    D(self, 0x59) = arg;
  return 0;
}
PCREG(4c8860, shotActivateCommand);
