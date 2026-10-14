// u69_96.cpp - area 69, residue-8 (batch 96).
// 0x665240 (plain ret, frame-based): `push [ebp-0x10]; push [ebp-0x14]; call 0x4690b0; add esp,8; ret` (cdecl callee, caller pops 8).
//   Naked asm, so the frame reads and the stack match. 0x4690b0 is a GUESS hook in the spec.
// 0x656d80 (thiscall, two stack args, ret 8): `r = self->vt[0xc](a); r->+0x18 = b;` (callee pops its one argument, GUESS fake vtable in the spec).
#include "ff.h"

extern "C" void ext_4690b0(u32 a, u32 b);   // cdecl, two args (GUESS hook)
extern "C" void fwd665240(void);
__asm__(
    ".text\n"
    ".globl fwd665240\n"
    "fwd665240:\n"
    "  movl -0x10(%ebp), %eax\n"
    "  pushl %eax\n"
    "  movl -0x14(%ebp), %eax\n"
    "  pushl %eax\n"
    "  call ext_4690b0\n"
    "  addl $8, %esp\n"
    "  ret\n");
PCREG(665240, fwd665240);

static void THISCALL store656d80(u8 *self, u32 a, u32 b) {
  u32 vt = *(u32 *)self;
  u8 *r = (u8 *)((u32(THISCALL *)(void *, u32))*(u32 *)(vt + 0xc))(self, a);
  *(u32 *)(r + 0x18) = b;
}
PCREG(656d80, store656d80);
