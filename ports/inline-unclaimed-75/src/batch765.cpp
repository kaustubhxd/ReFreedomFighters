// batch765.cpp - residue 17 big entries (docs/20-unclaimed-78b.md), built in the area 75 folder.
#include "ff.h"

// 0x5fa4d0, stdcall(arg) ret 4 (GUESS name). The original calls 0x5fa630 (a getter that returns [0x724270]), then pushes
// arg, 0x6b918c, and the object, and calls vt[0x0c] of the object with ecx = the vtable value. That callee is caller-cleaned
// (add esp, 12). The port reads the global directly (the getter is only mov eax, [0x724270]; ret), then uses inline asm for
// the caller-cleaned call with ecx set. Name GUESS.
static void STDCALL vtCallArg_5fa4d0(u32 arg) {
  u8 *o = *(u8 **)0x724270u;
  u32 vt_o = *(u32 *)o;
  u32 fn = *(u32 *)(vt_o + 0x0c);
  u32 a0 = (u32)o;
  asm volatile("pushl %[arg]\n\tpushl $0x6b918c\n\tpushl %%edx\n\tcall *%%eax\n\taddl $12, %%esp"
               : "+a"(fn), "+c"(vt_o), "+d"(a0)
               : [arg] "r"(arg)
               : "memory", "cc");
}
PCREG(5fa4d0, vtCallArg_5fa4d0);
