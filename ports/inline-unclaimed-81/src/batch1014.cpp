// batch1014.cpp - area 81, batch 1014: CInventory::Command(cmd, arg), 0x4abc30, thiscall, two stack arguments, ret 8. No SEH frame, no cookie.
// Command word (low 16 bits) compared with this+0x50, 0x52, 0x4c, 0x4e, 0x5e, 0x60, 0x66, 0x56, 0x54, 0x5c, 0x62 in that order. Stand-ins (GUESS):
// 0x4acf30 (thiscall, one argument), 0x4ad770 (thiscall, one argument), 0x4ad9a0 and 0x4ad4d0 (thiscall, no arguments). The loop on the inner object
// at this+0x11a sets the exe's esi to arg while it runs (the port keeps this and passes arg directly).
#include "ff.h"

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define W16(p, o) (*(u16 *)((u8 *)(p) + (o)))

extern "C" void THISCALL ext_4acf30(void *self, u32 a);   // GUESS (stood in)
extern "C" void THISCALL ext_4ad770(void *self, u32 a);   // GUESS (stood in)
extern "C" void THISCALL ext_4ad9a0(void *self);          // GUESS (stood in)
extern "C" void THISCALL ext_4ad4d0(void *self);          // GUESS (stood in)

// The tail every path but the 0x50/0x52 and early-out paths reaches: when this+0x64 matches cmd, 0x4ad4d0(this).
static void inventoryTail(u8 *self, u16 cmd) {
  if (cmd == W16(self, 0x64))
    ext_4ad4d0(self);
}

// 0x4abc30 CInventory::Command(cmd, arg).
static u32 THISCALL inventoryCommand(u8 *self, u32 cmdArg, u32 arg) {
  u16 cmd = (u16)cmdArg;
  if (cmd == W16(self, 0x50) || cmd == W16(self, 0x52)) {
    u32 r = vcall<u32>((void *)D(*(u8 **)0x70039c, 0x9b), 0x58, D(self, 0x6a));
    if (r)
      vcall<void>((void *)r, 0x128, cmdArg, arg, 0u);
    inventoryTail(self, cmd);
    return 0;
  }
  if (cmd == W16(self, 0x4c)) {
    D(self, 0x6a) = arg;
    inventoryTail(self, cmd);
    return 0;
  }
  if (cmd == W16(self, 0x4e)) {
    D(self, 0x6a) = 0;
    inventoryTail(self, cmd);
    return 0;
  }
  if (cmd == W16(self, 0x5e)) {
    u32 r = vcall<u32>((void *)D(*(u8 **)0x70039c, 0x9b), 0x58, arg);
    if (!r)
      return 0;
    ext_4acf30(self, arg);
    inventoryTail(self, cmd);
    return 0;
  }
  if (cmd == W16(self, 0x60)) {
    ext_4ad770(self, arg);
    inventoryTail(self, cmd);
    return 0;
  }
  if (cmd == W16(self, 0x66)) {
    if (arg == 0) {
      inventoryTail(self, cmd);
      return 0;
    }
    u8 *inner = self + 0x11a;
    u32 l14 = 0;
    vcall<void>(inner, 0x4c, (u32)&l14);
    u32 cur = vcall<u32>(inner, 0x5c, (u32)&l14);
    if (l14 == 0) {
      inventoryTail(self, cmd);
      return 0;
    }
    do {
      u32 s = vcall<u32>((void *)D(*(u8 **)0x70039c, 0x9b), 0x58, cur);
      if (s)
        vcall<void>((void *)arg, 0x4, cur);
      else
        vcall<void>(inner, 0x44, (u32)&l14);
      cur = vcall<u32>(inner, 0x5c, (u32)&l14);
    } while (l14 != 0);
    inventoryTail(self, cmd);
    return 0;
  }
  if (cmd == W16(self, 0x56)) {
    vcall<void>(self, 0x90);
    inventoryTail(self, cmd);
    return 0;
  }
  if (cmd == W16(self, 0x54)) {
    vcall<void>(self, 0x84, arg);
    inventoryTail(self, cmd);
    return 0;
  }
  if (cmd == W16(self, 0x5c)) {
    vcall<void>(self, 0x94);
    inventoryTail(self, cmd);
    return 0;
  }
  if (cmd == W16(self, 0x62))
    ext_4ad9a0(self);
  inventoryTail(self, cmd);
  return 0;
}
PCREG(4abc30, inventoryCommand);
