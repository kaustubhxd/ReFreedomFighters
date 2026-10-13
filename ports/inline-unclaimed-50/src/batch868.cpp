// batch868.cpp - area 50 (residue-9 file, smallest rows first): three small setters (vtable functions, thiscall).
//  0x47bed0 ZActor::SetMoveSet(const ZActor::SMoveSet*) [7 instr]: stores the pointer at this + 0x49a + 4*(*p), where *p is a dword index.
//  0x5a2c50 ZFFActor::SetCloseCombatEnable(bool) [10 instr]: bit 0 of the dword at this+0x7a6 is set when the argument byte is
//    non-zero and cleared otherwise.
//  0x47bd90 ZActor::SetEndDir(const float*) [25 instr]: with a non-null vector, copies three floats to this+0x69a, clears the
//    dword at +0x69e, calls 0x44c840 (exe; a float result that is dropped) on the copy at +0x69a (ecx still points there), and sets
//    the byte at +0x699 to 1; with null, +0x699 = 0.
#include "ff.h"

#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))

extern "C" float THISCALL ext_44c840(void *self);   // exe; returns a float that the caller drops

// 0x47bed0 ZActor::SetMoveSet.
static void THISCALL SetMoveSet47bed0(u8 *self, u32 *p) {
  U32(self, 0x49a + U32(p, 0) * 4) = (u32)p;
}
PCREG(47bed0, SetMoveSet47bed0);

// 0x5a2c50 ZFFActor::SetCloseCombatEnable.
static void THISCALL SetCloseCombat5a2c50(u8 *self, u8 on) {
  if (on) U32(self, 0x7a6) = U32(self, 0x7a6) | 1u;
  else U32(self, 0x7a6) = U32(self, 0x7a6) & 0xfffffffeu;
}
PCREG(5a2c50, SetCloseCombat5a2c50);

// 0x47bd90 ZActor::SetEndDir.
static void THISCALL SetEndDir47bd90(u8 *self, float *v) {
  if (v == 0) {
    U8(self, 0x699) = 0;
    return;
  }
  U32(self, 0x69a) = U32(v, 0);
  U32(self, 0x69e) = U32(v, 4);
  U32(self, 0x6a2) = U32(v, 8);
  U32(self, 0x69e) = 0;
  ext_44c840(self + 0x69a);                // the exe's ecx is still esi+0x69a here (the copy's address)
  U8(self, 0x699) = 1;
}
PCREG(47bd90, SetEndDir47bd90);
