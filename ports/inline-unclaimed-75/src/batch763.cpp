// batch763.cpp - residue 17 big entries (docs/20-unclaimed-78b.md), built in the area 75 folder.
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(u8 *self, u32 w);   // original accessor, one stack word, ret 4

typedef u32(THISCALL *VTwoArg)(u8 *, u32, u32);   // vt[0x20]: two stack words (0x69c8e0, 0x104)
typedef void(THISCALL *VTwoW)(u8 *, u32, u32);           // vt[0x6d8]: this, then (1, byte)
typedef void(__attribute__((cdecl)) *Hook)(void);

// 0x5590d0, thiscall(arg) ret 4 (GUESS name). p = 5003d0(ecx = [arg+4], 0). If p[4] is neither 0 nor 1: lg = [0x700390],
// o = lg->vt[0x20](lg), then the vt[0x2c] call with ecx = the vtable of o and words (o, 0x69c6b0, 0x69c938); then the hook at
// 0x7003b0 when it is set. Finally [this+0x1c]->vt[0x6d8](obj, 1, p[0]). Name GUESS.
static void THISCALL logThenDispatch_5590d0(u8 *self, u8 *arg) {
  u8 *p = ext_5003d0(*(u8 **)(arg + 4), 0u);
  u8 dl = p[4];
  if (dl != 0 && dl != 1) {
    u8 *lg = *(u8 **)0x700390u;
    VTwoArg f20 = (VTwoArg)(*(u32 *)(*(u32 *)lg + 0x20));
    u8 *o = (u8 *)f20(lg, 0x69c8e0u, 0x104u);
    // vt[0x2c]: ecx = the vtable value, three stack words, and the CALLER cleans them (add esp, 12). C cannot set ecx for
    // a caller-cleaned call, so this site uses inline asm.
    u32 vt_o = *(u32 *)o;
    u32 fn2c = *(u32 *)(vt_o + 0x2c);
    u32 a0 = (u32)o;
    asm volatile("pushl $0x69c938\n\tpushl $0x69c6b0\n\tpushl %%edx\n\tcall *%%eax\n\taddl $12, %%esp"
                 : "+a"(fn2c), "+c"(vt_o), "+d"(a0)
                 :
                 : "memory", "cc");
    Hook h = (Hook)(*(u32 *)0x7003b0u);
    if (h) h();
  }
  u8 *obj = *(u8 **)(self + 0x1c);
  VTwoW f6d8 = (VTwoW)(*(u32 *)(*(u32 *)obj + 0x6d8));
  f6d8(obj, 1u, (u32)p[0]);
}
PCREG(5590d0, logThenDispatch_5590d0);
