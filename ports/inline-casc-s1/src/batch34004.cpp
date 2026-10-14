// batch34004.cpp - cascade escalation batch 34004: vtable forwarders / tail stubs in assembly (entry stack untouched at the jump)
// and a decrement-and-flag function.
#include "ff.h"

extern "C" void thunk63b690(void);
extern "C" void thunk46fd90(void);
extern "C" void thunk4bf4c0(void);
extern "C" void thunk4c1f70(void);

asm(
    ".text\n"
    ".globl thunk63b690\n"
    "thunk63b690:\n"          // this = [this+4]; slot 8
    "  movl 4(%ecx), %ecx\n"
    "  movl (%ecx), %eax\n"
    "  jmp *8(%eax)\n"
    ".globl thunk46fd90\n"
    "thunk46fd90:\n"          // empty frame (push/mov/pop ebp), then 0x46f9d0
    "  jmp ext_46f9d0\n"
    ".globl thunk4bf4c0\n"
    "thunk4bf4c0:\n"          // empty frame, then 0x4c1060
    "  jmp ext_4c1060\n"
    ".globl thunk4c1f70\n"
    "thunk4c1f70:\n"          // this = [engine+0x9b]; slot 0x2c
    "  movl 0x70039c, %eax\n"
    "  movl 0x9b(%eax), %ecx\n"
    "  movl (%ecx), %eax\n"
    "  jmp *0x2c(%eax)\n");
PCREG(63b690, thunk63b690);
PCREG(46fd90, thunk46fd90);
PCREG(4bf4c0, thunk4bf4c0);
PCREG(4c1f70, thunk4c1f70);

// 0x483400, thiscall: unaligned dword +0x602 -= 1; when it reaches zero, byte +0x5ff = 1.
static void THISCALL fn483400(u8 *self) {
  u32 v;
  u8 *p = self + 0x602;
  v = p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24;
  v -= 1;
  p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24;
  if (v == 0) self[0x5ff] = 1;
}
PCREG(483400, fn483400);
