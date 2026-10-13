// batch1004.cpp - area 81 (residue 0), batch 1004: CRigidBody::Command(cmd, arg), 0x53e6c0, thiscall, two stack arguments, ret 8. No SEH frame.
// Compares the 16-bit cmd with the words at this+0x5c, 0x5e, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x60 in that order (the 0x4c and 0x54 branches are the
// same block). Helpers stood in: 0x634e90 (thiscall, one argument 0x10, GUESS), 0x53f0e0, 0x53eeb0, 0x53efd0 (thiscall, one argument arg, GUESS),
// 0x53f770 (thiscall, no arguments, GUESS), and the vslot 0x84 of this (one argument arg).
#include "ff.h"

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define W(p, o) (*(u16 *)((u8 *)(p) + (o)))

extern "C" void THISCALL ext_634e90(void *self, u32 n);     // GUESS (stood in)
extern "C" void THISCALL ext_53f0e0(void *self, u32 arg);   // GUESS (stood in)
extern "C" void THISCALL ext_53eeb0(void *self, u32 arg);   // GUESS (stood in)
extern "C" void THISCALL ext_53efd0(void *self, u32 arg);   // GUESS (stood in)
extern "C" void THISCALL ext_53f770(void *self);            // GUESS (stood in)

// The 0x4c and 0x54 branch: the value at this+0x141 goes to +0x13d; the 0x10 ms counter is set up with 0x634e90.
static void THISCALL commandSetup(u8 *self) {
  u32 v = D(self, 0x141);
  *(u8 *)(self + 0x10f) = 1;
  D(self, 0xf7) = 0x3e8;
  D(self, 0xfb) = 0x45480000u;
  D(self, 0xff) = 0x43c80000u;
  D(self, 0x13d) = v;
  ext_634e90(self, 0x10);
}

// 0x53e6c0 CRigidBody::Command(cmd, arg).
static u32 THISCALL rigidBodyCommand(u8 *self, u32 cmdArg, u32 arg) {
  u16 cmd = (u16)cmdArg;
  if (cmd == W(self, 0x5c))
    *(u8 *)(self + 0x110) = 1;
  if (cmd == W(self, 0x5e))
    *(u8 *)(self + 0x156) = 1;
  if (cmd == W(self, 0x4c))
    commandSetup(self);
  if (cmd == W(self, 0x4e))
    ext_53f0e0(self, arg);
  if (cmd == W(self, 0x50))
    ext_53eeb0(self, arg);
  if (cmd == W(self, 0x52))
    ext_53efd0(self, arg);
  if (cmd == W(self, 0x54))
    commandSetup(self);
  if (cmd == W(self, 0x56)) {
    D(self, 0x111) = D(arg, 0);
    D(self, 0x115) = D(arg, 4);
    D(self, 0x119) = D(arg, 8);
    ext_53f770(self);
  }
  if (cmd == W(self, 0x58))
    vcall<void>(self, 0x84, arg);
  if (cmd == W(self, 0x5a)) {
    D(self, 0x139) = D(arg, 0);
    D(self, 0x141) = D(arg, 4);
    D(self, 0x13d) = D(arg, 4);
  }
  if (cmd == W(self, 0x60))
    D(self, 0x145) = D(arg, 0);
  return 0;
}
PCREG(53e6c0, rigidBodyCommand);
