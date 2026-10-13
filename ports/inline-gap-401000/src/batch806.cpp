// batch806.cpp - core gameplay batch 806 (docs/20-unclaimed-65.md, batch 806): 0x5dbeb0 (assembly), 0x469200 and 0x479030 (C).
#include "ff.h"

typedef u32(THISCALL *F1)(u8 *self, u32 a);
static u32 vc1(u8 *o, u32 s, u32 a) { return ((F1)(*(const u32 *)(*(const u32 *)o + s)))(o, a); }

extern "C" void fn5dbeb0(void);
extern "C" u32 THISCALL ext_4e6330(u8 *self, u32 a);   // thiscall, one argument (exe code; the pushed value is its argument)

asm(
    ".text\n"
    ".globl fn5dbeb0\n"
    "fn5dbeb0:\n"
    "  pushl %ebp\n"
    "  movl %esp, %ebp\n"
    "  pushl 0x48(%ecx)\n"
    "  movl 8(%ebp), %ecx\n"
    "  call ext_4e6330\n"
    "  popl %ebp\n"
    "  ret $4\n");

static void __attribute__((cdecl)) fn469200(void) {
  u8 *o = *(u8 **)(G(u8 *, 0x70039c) + 0x1907);
  if (o != nullptr) vc1(o, 0x14, 0x68875c);
}

static void THISCALL fn479030(u8 *self) {
  *(u32 *)(self + 0x74f) = vc1(self, 0x21c, 0x68adf8);
}

PCREG(5dbeb0, fn5dbeb0);
PCREG(469200, fn469200);
PCREG(479030, fn479030);
