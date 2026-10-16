// batch685.cpp - unclaimed-68 batch 5 (claim 5 with the forwarder in batch 4). Name: CSharedCom::SetVal (low confidence; the
// body is a forwarder, see docs/20-unclaimed-68.md).
#include "ff.h"

// 0x4d3cf0, CSharedCom::SetVal(const char*, const int*, int) (low): ret 0xc, three stack arguments; ecx is the object (this),
// which 0x4d24e0 uses as its own this. Calls 0x4d24e0 (stdcall, four
// arguments, ret 0x10, original code) with (name, 4, values, count * 4). The original pushes them in that order; ecx is not
// set here, so the callee sees the incoming ecx, as in the original.
static void THISCALL sharedComSetVal(u8 *self, const char *name, const int *values, u32 count) {
  u32 bytes = count << 2;
  asm volatile("pushl %[by]\n\tpushl %[vp]\n\tpushl $4\n\tpushl %[nm]\n\tmovl $0x4d24e0, %%eax\n\tcall *%%eax"
               :
               : "c"(self), [by] "r"(bytes), [vp] "r"(values), [nm] "r"(name)
               : "eax", "edx", "memory", "cc", "xmm0", "xmm1", "xmm2", "xmm3", "xmm4", "xmm5", "xmm6", "xmm7");
}
PCREG(4d3cf0, sharedComSetVal);
