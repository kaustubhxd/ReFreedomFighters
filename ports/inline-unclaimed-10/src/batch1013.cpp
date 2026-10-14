// batch1013.cpp - unclaimed-10, batch 9 (docs/20-unclaimed-10.md): ZFFHeroMovementStand::GetAnims() (0x5e4790), thiscall, no
// arguments (ret). A straight sequence of virtual calls, copied in the original order and with the original arguments:
//   on the object (this), slot +0x58 (one argument, returns a value stored in a field) x4 and then x3 more,
//   slot +0x54 (one argument) x6, all on this;
//   on the embedded sub-objects at this+0x10d, +0x13d, +0x16d, +0x155, slot +8 (three arguments: pointer, 0, float).
// Every callee is an UNVERIFIED virtual slot: the spec stubs each slot with a logging handler, so the calls, arguments and
// stores are checked and the callee bodies are not.
#include "ff.h"

typedef u32(THISCALL *Slot58)(u8 *self, u32 a);                 // this->vt[+0x58] (value returned)
typedef void(THISCALL *Slot54)(u8 *self, u32 a);                // this->vt[+0x54]
typedef void(THISCALL *Slot8)(u8 *self, u32 a, u32 b, float c); // sub->vt[+8] (pointer, 0, float)

#define VT(o) (*(void ***)(o))

// 0x5e4790, ZFFHeroMovementStand::GetAnims() (high)
static void THISCALL heroStandGetAnims(u8 *self) {
  u8 *T = self;
  *(u32 *)(T + 0x1d) = ((Slot58)VT(T)[0x58 / 4])(T, 0x68d1ac);
  *(u32 *)(T + 0x35) = ((Slot58)VT(T)[0x58 / 4])(T, 0x68acf8);
  *(u32 *)(T + 0x4d) = ((Slot58)VT(T)[0x58 / 4])(T, 0x68d1cc);
  *(u32 *)(T + 0x65) = ((Slot58)VT(T)[0x58 / 4])(T, 0x68d1e0);
  ((Slot8)VT(T + 0x10d)[0x8 / 4])(T + 0x10d, (u32)(unsigned long)(T + 0x35), 0, bitsf(0x3f800000));
  ((Slot8)VT(T + 0x10d)[0x8 / 4])(T + 0x10d, (u32)(unsigned long)(T + 0x4d), 0, bitsf(0x3dcccccd));
  ((Slot8)VT(T + 0x10d)[0x8 / 4])(T + 0x10d, (u32)(unsigned long)(T + 0x65), 0, bitsf(0x3dcccccd));
  *(u32 *)(T + 0xc5) = ((Slot58)VT(T)[0x58 / 4])(T, 0x6b7a38);
  ((Slot8)VT(T + 0x13d)[0x8 / 4])(T + 0x13d, (u32)(unsigned long)(T + 0xc5), 0, bitsf(0x3f800000));
  *(u32 *)(T + 0xf5) = ((Slot58)VT(T)[0x58 / 4])(T, 0x6b7a44);
  ((Slot54)VT(T)[0x54 / 4])(T, (u32)(unsigned long)(T + 0xf5));
  ((Slot8)VT(T + 0x16d)[0x8 / 4])(T + 0x16d, (u32)(unsigned long)(T + 0xf5), 0, bitsf(0x3f800000));
  ((Slot54)VT(T)[0x54 / 4])(T, (u32)(unsigned long)(T + 0x35));
  ((Slot54)VT(T)[0x54 / 4])(T, (u32)(unsigned long)(T + 0x4d));
  ((Slot54)VT(T)[0x54 / 4])(T, (u32)(unsigned long)(T + 0x65));
  ((Slot54)VT(T)[0x54 / 4])(T, (u32)(unsigned long)(T + 0x1d));
  *(u32 *)(T + 0xdd) = ((Slot58)VT(T)[0x58 / 4])(T, 0x6b7a50);
  ((Slot54)VT(T)[0x54 / 4])(T, (u32)(unsigned long)(T + 0xdd));
  ((Slot8)VT(T + 0x155)[0x8 / 4])(T + 0x155, (u32)(unsigned long)(T + 0xdd), 0, bitsf(0x3f800000));
}
PCREG(5e4790, heroStandGetAnims);
