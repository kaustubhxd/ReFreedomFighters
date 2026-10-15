// batch5844.cpp - 0x590cd0 (FUN_00590cd0, SEH allocate + construct with two arguments): thiscall, no args, returns eax.
// o = operator new(0x54c) (0x41e290, cdecl, hooked); if o == 0: return 0; else ctor 0x5e0e10(o, this, 3) (thiscall, ret 8, exe code, hooked in the spec) and return its eax.
// The exe frame (SEH record, cookie, ESI saved and restored) is the naked wrapper; `this` reaches the C body through a global set in the wrapper.
#include "ff.h"

extern "C" void *ext_41e290(u32 size);                              // operator new (cdecl), original code (hooked in the spec)
extern "C" u32 THISCALL ext_5e0e10(u8 *self, u32 a, u32 b);      // constructor (ret 8), original code (hooked in the spec)

extern "C" __attribute__((used)) u8 *g_self_5844 = 0;

extern "C" __attribute__((used)) u32 f5844_body_590cd0() {
  u8 *self = g_self_5844;
  u8 *o = (u8 *)ext_41e290(0x54c);
  if (o == 0) return 0;
  return ext_5e0e10(o, (u32)(unsigned long)self, 3);
}

// The exe frame for this function: push -1, handler 0x66b8e2, previous fs:[0], ECX, ESI, cookie; ESI = this; the epilogue restores fs:[0], pops ECX and ESI.
extern "C" __attribute__((naked)) void f5844_seh_590cd0() {
  asm volatile("push %ebp\n\t"
               "mov %esp, %ebp\n\t"
               "push $-1\n\t"
               "push $0x66b8e2\n\t"
               "mov %fs:0, %eax\n\t"
               "push %eax\n\t"
               "push %ecx\n\t"
               "push %esi\n\t"
               "mov 0x6f5630, %eax\n\t"
               "xor %ebp, %eax\n\t"
               "push %eax\n\t"
               "lea -0xc(%ebp), %eax\n\t"
               "mov %eax, %fs:0\n\t"
               "mov %ecx, %esi\n\t"
               "mov %ecx, g_self_5844\n\t"
               "call f5844_body_590cd0\n\t"
               "mov -0xc(%ebp), %ecx\n\t"
               "mov %ecx, %fs:0\n\t"
               "pop %ecx\n\t"
               "pop %esi\n\t"
               "mov %ebp, %esp\n\t"
               "pop %ebp\n\t"
               "ret\n\t");
}
PCREG(590cd0, f5844_seh_590cd0);
