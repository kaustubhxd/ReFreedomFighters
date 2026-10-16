// batch5845.cpp - 0x5c3f90 (FUN_005c3f90, ZRepositionCharacter-like scalar deleting destructor, SEH frame), thiscall, one stack argument (flags), ret 4, returns this.
// m = this+0x48: if m: m->vt[0](1); this+0x48 = 0. this+0x44 = 0; this+0x30 = 0; this->vtable = 0x686874. sub = (engine+0x9b): sub->vt[+0x34](this).
// if flags & 1: if flags & 4: 0x4690b0(this, 0x54) (cdecl sized free, hooked); else: call the assert hook 0x7003b0 (must be non-null; int3 otherwise).
// The exe frame (handler 0x66b0fc, cookie, ESI saved and restored) is a naked wrapper; this and flags reach the C body through globals.
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef u32(THISCALL *SlotA)(u8 *self, u32 a);
typedef u32(THISCALL *SlotN)(u8 *self);

extern "C" void ext_4690b0(u8 *p, u32 size);  // sized free (cdecl), original code (hooked in the spec)

extern "C" __attribute__((used)) u8 *g_self_5845 = 0;
extern "C" __attribute__((used)) u32 g_flags_5845 = 0;

extern "C" __attribute__((used)) u32 f5845_body_5c3f90() {
  u8 *self = g_self_5845;
  u32 flags = g_flags_5845;
  *(u32 *)self = 0x6b3f5c;
  u8 *m = *(u8 **)(self + 0x48);
  if (m) {
    ((SlotA)VT(m)[0 / 4])(m, 1);
    *(u32 *)(self + 0x48) = 0;
  }
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)self = 0x686874;
  u8 *sub = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  ((SlotA)VT(sub)[0x34 / 4])(sub, (u32)(unsigned long)self);
  if (flags & 1) {
    if (flags & 4) {
      ext_4690b0(self, 0x54);
    } else {
      u32 h = G(u32, 0x7003b0);
      if (h) ((void (*)(void))h)();
      else __builtin_trap();
    }
  }
  return (u32)(unsigned long)self;
}

// The exe frame: push -1, handler 0x66b0fc, previous fs:[0], ESI, cookie; ESI = this; the epilogue restores fs:[0], pops the cookie slot (ECX) and ESI, ret 4.
extern "C" __attribute__((naked)) void f5845_seh_5c3f90() {
  asm volatile("push %ebp\n\t"
               "mov %esp, %ebp\n\t"
               "push $-1\n\t"
               "push $0x66b0fc\n\t"
               "mov %fs:0, %eax\n\t"
               "push %eax\n\t"
               "push %esi\n\t"
               "mov 0x6f5630, %eax\n\t"
               "xor %ebp, %eax\n\t"
               "push %eax\n\t"
               "lea -0xc(%ebp), %eax\n\t"
               "mov %eax, %fs:0\n\t"
               "mov %ecx, %esi\n\t"
               "mov %ecx, g_self_5845\n\t"
               "mov 8(%ebp), %eax\n\t"
               "mov %eax, g_flags_5845\n\t"
               "call f5845_body_5c3f90\n\t"
               "mov -0xc(%ebp), %ecx\n\t"
               "mov %ecx, %fs:0\n\t"
               "pop %ecx\n\t"
               "pop %esi\n\t"
               "mov %ebp, %esp\n\t"
               "pop %ebp\n\t"
               "ret $4\n\t");
}
PCREG(5c3f90, f5845_seh_5c3f90);
