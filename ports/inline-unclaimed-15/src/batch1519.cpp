#include "ff.h"
// batch1519.cpp - unclaimed-15 claim 19 (docs/20-unclaimed-15.md): ZActor::Die() (0x478320). The name is a GUESS (residue
// file: FUN_478320). Thiscall, no arguments, ret 0. The exe pushes esi before the slot +0x628 call and pops it at the end (a
// save, not an argument); the call takes three arguments (2, 4, 0).
// Stubbed in the harness: 0x466ce0 (thiscall, no args) and 0x47aad0 (thiscall, two args). The rest are vtable calls.

typedef u32(THISCALL *Slot0)(u8 *self);
typedef u32(THISCALL *Slot1)(u8 *self, u32 a1);
typedef u32(THISCALL *Slot2)(u8 *self, u32 a1, u32 a2);
typedef u32(THISCALL *Slot3)(u8 *self, u32 a0, u32 a1, u32 a2);
typedef u32(THISCALL *Slot4)(u8 *self, u32 a0, u32 a1, u32 a2, u32 a3);
typedef u32(THISCALL *Slot3)(u8 *self, u32 a0, u32 a1, u32 a2);

extern "C" void THISCALL ext_466ce0(u8 *self);
extern "C" void THISCALL ext_47aad0(u8 *self, u32 a0, u32 a1);

// GUESS: ZActor::Die() (0x478320).
static void THISCALL actorDie(u8 *self) {
  u8 *vt = *(u8 **)self;
  if (!((Slot0)*(u32 *)(vt + 0x588))(self))
    return;
  ext_466ce0(self);
  ((Slot1)*(u32 *)(vt + 0x654))(self, 0);
  ((Slot1)*(u32 *)(vt + 0x584))(self, 0);
  u32 v = *(u32 *)(self + 0x6ce);
  if (v && *(u32 *)(self + 0x64c) == 0xa) {
    ext_47aad0((u8 *)0x6ff9c0, v, (u32)self);
    *(u32 *)(self + 0x6ce) = 0;
    *(u32 *)(self + 0x64c) = 0;
  }
  *(u32 *)(self + 0x650) = 0;
  vt = *(u8 **)self;
  ((Slot3)*(u32 *)(vt + 0x628))(self, 2, 4, 0);
  ((Slot1)*(u32 *)(vt + 0x62c))(self, 0);
  ((Slot0)*(u32 *)(vt + 0x3dc))(self);
  u8 *rm = *(u8 **)0x70039c;
  u8 *sub = *(u8 **)(rm + 0x9b);
  // RegisterZMsg (slot +0x114) takes four arguments (ret 0x10). The first value pushed (0) stays on the stack and is the
  // third argument of the next call, slot +0x130 (this, r16, 0; ret 0xc).
  u32 r = ((Slot4)*(u32 *)(*(u32 *)sub + 0x114))(sub, 0x68ae08, 0, 0x68a7c4, 0xdf9);
  ((Slot3)*(u32 *)(*(u32 *)self + 0x130))(self, (u32)self, (u16)r, 0);
}
PCREG(478320, actorDie);
