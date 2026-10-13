#include "ff.h"
// batch3514.cpp - area 35 claim 14 (docs/20-unclaimed-35.md): six leaves in slice 14. Names: GC map for 0x41e320; GUESS elsewhere.
// Stubbed in the harness: 0x480980 and 0x561020 (thiscall, no args, logged); the vtable slots these leaves call (logged).

typedef u32(THISCALL *Slot0)(u8 *self);
typedef u32(THISCALL *Slot4)(u8 *self, u32 a0, u32 a1, u32 a2, u32 a3);

extern "C" void THISCALL ext_480980(u8 *self);
extern "C" void THISCALL ext_561020(u8 *self);

// 0x563d20, GUESS FUN_563d20: decrements *p (second argument); if the result is below a1 (signed), stores a3 - 1 there.
static void THISCALL guessCounter(u8 *self, u32 a1, u32 *p, u32 a3) {
  (void)self;
  *p -= 1;
  if ((s32)*p < (s32)a1)
    *p = a3 - 1;
}
PCREG(563d20, guessCounter);

// 0x41e320, ZSysMem::RemoveRefController(...) (high): this+8 = a3, this+0xc = a1, this+0x10 = a2.
static void THISCALL sysMemRemoveRefController(u8 *self, u32 a1, u32 a2, u32 a3) {
  *(u32 *)(self + 8) = a3;
  *(u32 *)(self + 0xc) = a1;
  *(u32 *)(self + 0x10) = a2;
}
PCREG(41e320, sysMemRemoveRefController);

// 0x462f20, GUESS FUN_462f20: calls vtable slot +0xc of the object at this + 0x6c with the three arguments.
static void THISCALL guessForward3(u8 *self, u32 a1, u32 a2, u32 a3) {
  // The exe pushes this (ecx) before the three arguments, so the slot takes four (ret 0x10) with this as the last one.
  u8 *o = *(u8 **)(self + 0x6c);
  ((Slot4)*(u32 *)(*(u32 *)o + 0xc))(o, a1, a2, a3, (u32)self);
}
PCREG(462f20, guessForward3);

// 0x4cdd20, GUESS FUN_4cdd20: this+0x14, minus the result of the object at this+0x24's slot +0x14 when that object is present.
static u32 THISCALL guessDifference(u8 *self) {
  u8 *p = *(u8 **)(self + 0x24);
  if (!p)
    return *(u32 *)(self + 0x14);
  u32 v = ((Slot0)*(u32 *)(*(u32 *)p + 0x14))(p);
  return *(u32 *)(self + 0x14) - v;
}
PCREG(4cdd20, guessDifference);

// 0x480a20, GUESS FUN_480a20: calls 0x480980 on this, sets the vtable to 0x68b61c, returns this.
static u8 *THISCALL guessCtorA(u8 *self) {
  ext_480980(self);
  *(u32 *)self = 0x68b61c;
  return self;
}
PCREG(480a20, guessCtorA);

// 0x57c460, GUESS FUN_57c460: calls 0x561020 on this, sets the vtable to 0x6aa7b4, returns this.
static u8 *THISCALL guessCtorB(u8 *self) {
  ext_561020(self);
  *(u32 *)self = 0x6aa7b4;
  return self;
}
PCREG(57c460, guessCtorB);
