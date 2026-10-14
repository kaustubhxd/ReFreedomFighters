// batch5840.cpp - residue 9, 0x5e4790 (ZFFHeroMovementStand::GetAnims(), gc name map), thiscall, no args, plain ret.
// Embedded objects P1 = this+0x10d, Q = this+0x13d, R = this+0x16d, W = this+0x155 (their vtable slot +8 takes three args). this vtable slots +0x58 (a key,
// returns a value) and +0x54 (one arg). Float constants: 1.0f (0x3f800000) and 0.1f (0x3dcccccd).
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef u32(THISCALL *SlotA)(u8 *self, u32 a);
typedef void(THISCALL *Slot3)(u8 *self, u32 a, u32 b, u32 c);

// 0x5e4790, thiscall, no args (ZFFHeroMovementStand::GetAnims)
static void THISCALL unnamed5e4790(u8 *self) {
  *(u32 *)(self + 0x1d) = ((SlotA)VT(self)[0x58 / 4])(self, 0x68d1ac);
  *(u32 *)(self + 0x35) = ((SlotA)VT(self)[0x58 / 4])(self, 0x68acf8);
  *(u32 *)(self + 0x4d) = ((SlotA)VT(self)[0x58 / 4])(self, 0x68d1cc);
  *(u32 *)(self + 0x65) = ((SlotA)VT(self)[0x58 / 4])(self, 0x68d1e0);
  u8 *P1 = self + 0x10d;
  ((Slot3)VT(P1)[0x8 / 4])(P1, (u32)(unsigned long)(self + 0x35), 0, 0x3f800000u);
  ((Slot3)VT(P1)[0x8 / 4])(P1, (u32)(unsigned long)(self + 0x4d), 0, 0x3dcccccdu);
  ((Slot3)VT(P1)[0x8 / 4])(P1, (u32)(unsigned long)(self + 0x65), 0, 0x3dcccccdu);
  *(u32 *)(self + 0xc5) = ((SlotA)VT(self)[0x58 / 4])(self, 0x6b7a38);
  u8 *Q = self + 0x13d;
  ((Slot3)VT(Q)[0x8 / 4])(Q, (u32)(unsigned long)(self + 0xc5), 0, 0x3f800000u);
  *(u32 *)(self + 0xf5) = ((SlotA)VT(self)[0x58 / 4])(self, 0x6b7a44);
  ((SlotA)VT(self)[0x54 / 4])(self, (u32)(unsigned long)(self + 0xf5));
  u8 *R = self + 0x16d;
  ((Slot3)VT(R)[0x8 / 4])(R, (u32)(unsigned long)(self + 0xf5), 0, 0x3f800000u);
  ((SlotA)VT(self)[0x54 / 4])(self, (u32)(unsigned long)(self + 0x35));
  ((SlotA)VT(self)[0x54 / 4])(self, (u32)(unsigned long)(self + 0x4d));
  ((SlotA)VT(self)[0x54 / 4])(self, (u32)(unsigned long)(self + 0x65));
  ((SlotA)VT(self)[0x54 / 4])(self, (u32)(unsigned long)(self + 0x1d));
  *(u32 *)(self + 0xdd) = ((SlotA)VT(self)[0x58 / 4])(self, 0x6b7a50);
  ((SlotA)VT(self)[0x54 / 4])(self, (u32)(unsigned long)(self + 0xdd));
  u8 *W = self + 0x155;
  ((Slot3)VT(W)[0x8 / 4])(W, (u32)(unsigned long)(self + 0xdd), 0, 0x3f800000u);
}
PCREG(5e4790, unnamed5e4790);
