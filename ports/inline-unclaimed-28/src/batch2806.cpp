#include "ff.h"
// batch2806.cpp - unclaimed-28 batch 6 (docs/20-unclaimed-28.md). Name from the GC name map (naming only).
// Helpers 0x4a02e0, 0x4a01c0, 0x4a03b0 and 0x4a0d00 run as original code here (stubbed by the harness); the strcmp-like
// import at 0x676414 (cdecl, two arguments) is called through its slot.

extern "C" void THISCALL ext_4a02e0(u8 *self, void *a);
extern "C" void THISCALL ext_4a01c0(u8 *self, void *a);
extern "C" void THISCALL ext_4a03b0(u8 *self, void *a, u32 b);
extern "C" u8 *THISCALL ext_4a0d00(u8 *self);

// 0x49fdb0, CAction::Command(unsigned short, void*) (high). Dispatch on the word command. Every path returns 0.
//  - command == word 0x7002ac: if this+0x102 and arg are both nonzero, stores this+0x102 through arg.
//  - command == word 0x7002d4: calls this's slot +0x58.
//  - command == word at this+0x5f sets bit 0 of dword +0x5a; else command == word at this+0x61 clears it.
//  - if the byte at this+0x63 is zero, calls this's slot +0x0c. If the byte at this+0x5e is zero, stops.
//  - 0x7002b4: helper 0x4a02e0(this, arg). 0x7002b0: helper 0x4a01c0(this, arg). 0x7002b8: helper 0x4a03b0(this, arg, 1).
//    0x7002bc: helper 0x4a03b0(this, arg, 0). 0x7002d8: calls the function pointer at 0x7003b0 with no arguments.
//  - 0x7002dc with a nonzero arg: walks the list from helper 0x4a0d00(this): for each element, if the import at 0x676414
//    (cdecl strcmp-like, arguments (arg, element+0x7a)) returns 0, calls the element's slot +0xac.
static u32 THISCALL actionCommand(u8 *self, u32 cmdArg, void *arg) {
  u16 cmd = (u16)cmdArg;
  if (cmd == G(u16, 0x7002ac)) {
    u32 v = *(u32 *)(self + 0x102);
    if (v != 0 && arg != 0)
      *(u32 *)arg = v;
    return 0;
  }
  if (cmd == G(u16, 0x7002d4)) {
    vcall<void>(self, 0x58);
    return 0;
  }
  if (cmd == *(u16 *)(self + 0x5f))
    *(u32 *)(self + 0x5a) |= 1u;
  else if (cmd == *(u16 *)(self + 0x61))
    *(u32 *)(self + 0x5a) &= 0xfffffffeu;
  if (self[0x63] == 0)
    vcall<void>(self, 0xc);
  if (self[0x5e] == 0)
    return 0;
  if (cmd == G(u16, 0x7002b4)) {
    ext_4a02e0(self, arg);
    return 0;
  }
  if (cmd == G(u16, 0x7002b0)) {
    ext_4a01c0(self, arg);
    return 0;
  }
  if (cmd == G(u16, 0x7002b8)) {
    ext_4a03b0(self, arg, 1u);
    return 0;
  }
  if (cmd == G(u16, 0x7002bc)) {
    ext_4a03b0(self, arg, 0u);
    return 0;
  }
  if (cmd == G(u16, 0x7002d8)) {
    ((void (*)())G(u32, 0x7003b0))();
    return 0;
  }
  if (cmd == G(u16, 0x7002dc) && arg != 0) {
    u8 *list = ext_4a0d00(self);
    if (*(u32 *)list == 0)
      return 0;
    u8 **edi = (u8 **)(list + 4);
    u32 i = 0;
    do {
      u8 *el = edi[i];
      u32 r = ((u32(__attribute__((cdecl)) *)(void *, u32))G(u32, 0x676414))(arg, *(u32 *)(el + 0x7a));
      if (r == 0)
        vcall<void>(el, 0xac);
      ++i;
    } while (i < *(u32 *)list);
    return 0;
  }
  return 0;
}
PCREG(49fdb0, actionCommand);
