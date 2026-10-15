#include "ff.h"
// batch1516.cpp - unclaimed-15 claim 16 (docs/20-unclaimed-15.md): ZActor::Load2() (0x4790e0). Name from the GC name map
// (high). Thiscall, no arguments, ret 0. Stubbed in the harness: 0x474710 (thiscall, no args). The render manager's
// slots +0x134 and +0x138 (return X and Y), X's slot +0x90 (writes a byte through its pointer argument), and Y's slot +0x88
// (writes a dword through its pointer argument) are code stubs. This actor's slots +0x654 and +0x580 are logged.

extern "C" void THISCALL ext_474710(u8 *self);   // stubbed in the harness

typedef u32(THISCALL *Slot0)(u8 *self);
typedef u32(THISCALL *Slot1)(u8 *self, u32 a1);
typedef u32(THISCALL *Slot2)(u8 *self, u32 a1, u32 a2);

static u8 *renderSub(u32 index) {
  u8 *rm = *(u8 **)0x70039c;
  u8 *obj = *(u8 **)(rm + 0x9b);
  return (u8 *)((Slot0)*(u32 *)(*(u32 *)obj + index))(obj);
}

// 0x4790e0, ZActor::Load2() (high).
static void THISCALL actorLoad2(u8 *self) {
  ext_474710(self);
  if (self[0x5d2])
    ((Slot1)*(u32 *)(*(u32 *)self + 0x654))(self, 1);
  u8 *x = renderSub(0x134);
  u8 flag = 0;
  ((Slot2)*(u32 *)(*(u32 *)x + 0x90))(x, 0x68a9d4, (u32)&flag);
  if (flag) {
    ((Slot1)*(u32 *)(*(u32 *)self + 0x580))(self, 0);
    return;
  }
  u8 *y = renderSub(0x138);
  u32 v = 0;
  ((Slot2)*(u32 *)(*(u32 *)y + 0x88))(y, 0x681320, (u32)&v);
  ((Slot1)*(u32 *)(*(u32 *)self + 0x580))(self, v);
}
PCREG(4790e0, actorLoad2);
