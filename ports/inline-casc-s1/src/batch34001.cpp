// batch34001.cpp - cascade escalation batch 34001: thiscall tail-jump stubs (assembly, so the entry stack is untouched at the jump),
// a one-byte clear and a truncating float read.
#include "ff.h"

extern "C" void thunk4f8e10(void);
extern "C" void thunk504870(void);
extern "C" void thunk51b020(void);

asm(
    ".text\n"
    ".globl thunk4f8e10\n"
    "thunk4f8e10:\n"          // this += 0x8f, then 0x4cc1d0
    "  addl $0x8f, %ecx\n"
    "  jmp ext_4cc1d0\n"
    ".globl thunk504870\n"
    "thunk504870:\n"          // vtable = 0x69cc88, then 0x500a10
    "  movl $0x69cc88, (%ecx)\n"
    "  jmp ext_500a10\n"
    ".globl thunk51b020\n"
    "thunk51b020:\n"          // vtable = 0x69f43c, then 0x51aa60
    "  movl $0x69f43c, (%ecx)\n"
    "  jmp ext_51aa60\n");
PCREG(4f8e10, thunk4f8e10);
PCREG(504870, thunk504870);
PCREG(51b020, thunk51b020);

// 0x473b40, thiscall: byte +0x3e8 = 0.
static void THISCALL fn473b40(u8 *self) { self[0x3e8] = 0; }
PCREG(473b40, fn473b40);

// 0x5333d0, thiscall: truncate the (unaligned) float at +0x87 to int (cvttss2si).
static s32 THISCALL fn5333d0(u8 *self) {
  u32 b = self[0x87] | self[0x88] << 8 | self[0x89] << 16 | (u32)self[0x8a] << 24;
  return _mm_cvttss_si32(_mm_set_ss(bitsf(b)));
}
PCREG(5333d0, fn5333d0);
