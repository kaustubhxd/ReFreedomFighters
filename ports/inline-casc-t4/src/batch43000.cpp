// batch43000.cpp - t4 (Sonnet) batch 43000: tier H float/SSE functions
#include "ff.h"

extern "C" void ext_634dc4();                                  // x87 CRT fmod: st1 = x, st0 = y on entry, result in st0
extern "C" u32 *THISCALL ext_5003d0(u8 *self, u32 idx);        // thiscall ret 4: element pointer (8 byte stride)

// 0x4e59b0, stdcall(obj, flag, float x) ret 0xc, float in st0: n = word [obj+8]; byte flag != 0: (float)fmod((double)x, (double)n);
// otherwise minss: (float)n < x ? (float)n : x
static float STDCALL fn4e59b0(u8 *obj, u32 flag, float x) {
  s32 n = *(u16 *)(obj + 8);
  if ((u8)flag) {
    double xd = (double)x, nd = (double)n;
    float r;
    __asm__ volatile("fldl %1\n\tfldl %2\n\tcall ext_634dc4\n\tfstps %0" : "=m"(r) : "m"(xd), "m"(nd) : "eax", "ecx", "edx", "memory", "cc", "st", "st(1)", "st(2)", "st(3)");
    return r;
  }
  float nf = (float)n;
  return nf < x ? nf : x;
}
PCREG(4e59b0, fn4e59b0);

// 0x51aaf0, thiscall(a) ret 4: p1 = a[4]->0x5003d0(1), p0 = a[4]->0x5003d0(0); this[0x18]->slot 0x360(float *p0, (*p1 != 0))
static void THISCALL fn51aaf0(u8 *self, u8 *a) {
  u8 *tbl = *(u8 **)(a + 4);
  u32 *p1 = ext_5003d0(tbl, 1);
  u32 *p0 = ext_5003d0(tbl, 0);
  u32 flag = (*p1 != 0);
  float x = *(float *)p0;
  vcall<void>(*(u8 **)(self + 0x18), 0x360, x, flag);
}
PCREG(51aaf0, fn51aaf0);

// 0x5f4e60, thiscall(float *p) ret 4: byte [this+4] == 2: *(float*)this *= *p; otherwise logs through [0x700390] (slot 0x20, then slot 0x2c on
// the vtable pointer as `this`) and calls the assert hook at 0x7003b0 (int3 when null)
asm(
    ".text\n"
    ".globl thunk5f4e60\n"
    "thunk5f4e60:\n"
    "  pushl %ebp\n"
    "  movl %esp, %ebp\n"
    "  movzbl 4(%ecx), %eax\n"
    "  subl $2, %eax\n"
    "  je 8f\n"
    "  movl 0x700390, %ecx\n"
    "  pushl $0xa6\n"
    "  pushl $0x69c8e0\n"
    "  movl (%ecx), %eax\n"
    "  call *0x20(%eax)\n"
    "  pushl $0x69c938\n"
    "  pushl $0x69c6b0\n"
    "  pushl %eax\n"
    "  movl (%eax), %ecx\n"
    "  call *0x2c(%ecx)\n"
    "  movl 0x7003b0, %eax\n"
    "  addl $0xc, %esp\n"
    "  testl %eax, %eax\n"
    "  je 7f\n"
    "  call *%eax\n"
    "  popl %ebp\n"
    "  ret $4\n"
    "7:\n"
    "  int3\n"
    "8:\n"
    "  movl 8(%ebp), %eax\n"
    "  movss (%eax), %xmm0\n"
    "  mulss (%ecx), %xmm0\n"
    "  movss %xmm0, (%ecx)\n"
    "  popl %ebp\n"
    "  ret $4\n");
extern "C" void thunk5f4e60(void);
PCREG(5f4e60, thunk5f4e60);
