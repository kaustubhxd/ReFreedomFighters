// batch810.cpp - standing assignment, residue 19 (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

extern "C" u32 THISCALL ext_43de70(u8 *self, u32 arg);   // original thiscall ret 4 (claimed elsewhere; called as is)

// 0x658ff0, thiscall(f) ret 4: stores (short)(int)f at this+0xa. cvttss2si semantics for the conversion.
static void THISCALL storeFloatWord_658ff0(u8 *self, float f) {
  s32 v;
  asm volatile("cvttss2si %1, %0" : "=r"(v) : "x"(f));
  *(u16 *)(self + 0xa) = (u16)v;
}
PCREG(658ff0, storeFloatWord_658ff0);

// 0x454ab0, thiscall(arg) ret 4: sets the vtable and tail-jumps into 0x43de70 with the same arguments.
static u32 THISCALL setVtableThen_454ab0(u8 *self, u32 arg) {
  *(u32 *)self = 0x6823a4u;
  return ext_43de70(self, arg);
}
PCREG(454ab0, setVtableThen_454ab0);
