// batch230.cpp - unclaimed area 22 (docs/20-unclaimed-22.md), residue 01 (core-todo/residue-01.txt). Three short bodies:
// a vtable tail call with no arguments, and two forwarders that jump to a one-argument thiscall (ret 4) with their own
// stack argument left in place. Names GUESS.
#include "ff.h"

extern "C" u32 THISCALL ext_584b40(u8 *self, u8 *a);   // original, thiscall, one stack word, ret 4 (CopyEventDataBlock body)
extern "C" u32 THISCALL ext_5c56f0(u8 *self, u8 *a);   // original, thiscall, one stack word, ret 4 (CopyEventDataBlock body)

// 0x51cad0: mov eax, [ecx]; jmp [eax + 0x360]. Returns the callee's eax with ecx = this.
static u32 THISCALL vtTail360_51cad0(u8 *self) {
  return vcall<u32>(self, 0x360);
}
PCREG(51cad0, vtTail360_51cad0);

// 0x582790: push ebp; mov ebp, esp; pop ebp; jmp 0x584b40. The forwarder keeps the argument and the callee pops it.
static u32 THISCALL forwardCopy_582790(u8 *self, u8 *a) {
  return ext_584b40(self, a);
}
PCREG(582790, forwardCopy_582790);

// 0x5c5590: push ebp; mov ebp, esp; pop ebp; jmp 0x5c56f0.
static u32 THISCALL forwardCopy_5c5590(u8 *self, u8 *a) {
  return ext_5c56f0(self, a);
}
PCREG(5c5590, forwardCopy_5c5590);
