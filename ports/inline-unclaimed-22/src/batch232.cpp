// batch232.cpp - unclaimed area 22 (docs/20-unclaimed-22.md), slice floor(addr/16) mod 20 == 1. Leaves from the full list
// (not in residue 01). Field reads and tests, one tail call through a vtable slot, one increment, and two x87 float loads.
// Names GUESS.
#include "ff.h"

// 0x46eed0: mov eax, [ecx + 0x5c]; ret.
static u32 THISCALL getField5c_46eed0(u8 *self) { return *(u32 *)(self + 0x5c); }
PCREG(46eed0, getField5c_46eed0);

// 0x5a8350: mov eax, [ecx + 0x300]; ret.
static u32 THISCALL getField300_5a8350(u8 *self) { return *(u32 *)(self + 0x300); }
PCREG(5a8350, getField300_5a8350);

// 0x483f10: mov eax, [ecx + 0x417]; and eax, 1; ret.
static u32 THISCALL getBit417_483f10(u8 *self) { return *(u32 *)(self + 0x417) & 1u; }
PCREG(483f10, getBit417_483f10);

// 0x5139d0: mov ecx, [ecx + 0x5c]; mov eax, [ecx]; jmp [eax + 0x10]. Tail call, no arguments, returns the callee's eax.
static u32 THISCALL vtTail10_5139d0(u8 *self) {
  u8 *obj = *(u8 **)(self + 0x5c);
  return vcall<u32>(obj, 0x10);
}
PCREG(5139d0, vtTail10_5139d0);

// 0x5ab050: cmp [ecx + 0x300], 0x10000000; je skip; inc dword [ecx + 0x8b3]; skip: ret.
static void THISCALL bumpIfNot_5ab050(u8 *self) {
  if (*(u32 *)(self + 0x300) != 0x10000000u) *(u32 *)(self + 0x8b3) += 1;
}
PCREG(5ab050, bumpIfNot_5ab050);

// 0x5abcd0: mov al, [ecx + 8]; ret. Only al is defined by the original (the harness compares al for this one).
static u8 THISCALL byte8_5abcd0(u8 *self) { return self[8]; }
PCREG(5abcd0, byte8_5abcd0);

// 0x468210: fld dword [ecx + 0x1da]; ret. The float is returned in ST0.
static float THISCALL floatAt1da_468210(u8 *self) { return *(float *)(self + 0x1da); }
PCREG(468210, floatAt1da_468210);

// 0x483a10: fld dword [ecx + 0x451]; ret. The float is returned in ST0.
static float THISCALL floatAt451_483a10(u8 *self) { return *(float *)(self + 0x451); }
PCREG(483a10, floatAt451_483a10);
