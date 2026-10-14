// batch34011.cpp - cascade escalation batch 34011: an indexed store and a flag-gated tail jump (assembly: the early exit pops its argument,
// the jump leaves the entry stack untouched).
#include "ff.h"

extern "C" void thunk593fd0(void);

asm(
    ".text\n"
    ".globl thunk593fd0\n"
    "thunk593fd0:\n"          // thiscall(a) ret 4: bit 0x400 of dword [this+0x417] set -> return 0; else tail-jump to 0x4670b0
    "  testl $0x400, 0x417(%ecx)\n"
    "  je 1f\n"
    "  xorl %eax, %eax\n"
    "  ret $4\n"
    "1:\n"
    "  jmp ext_4670b0\n");
PCREG(593fd0, thunk593fd0);

// 0x5398d0, thiscall(idx, v) ret 8: unaligned dword at this + idx*9 + 0x515e = v.
static void THISCALL fn5398d0(u8 *self, u32 idx, u32 v) {
  u8 *p = self + idx * 9 + 0x515e;
  p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24;
}
PCREG(5398d0, fn5398d0);
