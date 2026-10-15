// batch684.cpp - unclaimed-68 batch 4 (claim 4). Names from the GC name map (naming only, never committed).
// The forwarders call exe code with stack arguments; the calls are written in inline asm with the original's push order,
// so the compiler adds no cleanup of its own around them.
#include "ff.h"

// 0x514430, ZMoveOnSpline::SetPath(unsigned int, float) (high): thiscall, ret 8. Forwards (index, float) to the object at
// this+0x5c through 0x523cc0 (thiscall with two stack arguments, ret 8, original code). The float goes below the index, as
// in the original (its push slot is overwritten with the float bits).
static void THISCALL moveOnSplineSetPath(u8 *self, u32 index, float f) {
  u8 *target = *(u8 **)(self + 0x5c);
  u32 fb = fbits(f);
  asm volatile("pushl %[fb]\n\tpushl %[ix]\n\tmovl $0x523cc0, %%eax\n\tcall *%%eax"
               :
               : "c"(target), [fb] "r"(fb), [ix] "r"(index)
               : "eax", "edx", "memory", "cc", "xmm0", "xmm1", "xmm2", "xmm3", "xmm4", "xmm5", "xmm6", "xmm7");
}
PCREG(514430, moveOnSplineSetPath);
