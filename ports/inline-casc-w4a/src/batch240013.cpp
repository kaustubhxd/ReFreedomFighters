// batch240013.cpp - Sonnet-w4a: small DEBUG/TOOLS rows (thunk, fatal assert, SEH wrapper).
#include "ff.h"

extern "C" u32 STDCALL ext_41ca80(u32 a, u32 b, u32 c, u32 d);

struct Eh4 {
  Eh4 *next;
  u32 handler;
  u32 xtable;
  s32 level;
};

// 0x660ce0: thiscall tail thunk: o = this[0x18]; o ? jump to o's vtable slot 0x14 (this = o, the stack arguments pass through) : 0
extern "C" __attribute__((naked, used)) void fn_660ce0() {
  asm volatile(
      "movl 0x18(%ecx), %ecx\n"
      "testl %ecx, %ecx\n"
      "jne 1f\n"
      "xorl %eax, %eax\n"
      "ret\n"
      "1: movl (%ecx), %eax\n"
      "jmp *0x14(%eax)\n");
}
PCREG(660ce0, fn_660ce0);

// 0x5f17d0: stdcall(unused) ret 4: assert failure path: o = logger->slot 0x20("..", 0x2b9); o->vtable slot 0x2c(o, msg, file)
// (cdecl), then calls the assert hook [0x7003b0] (int3 when it is null) and returns its eax
static u32 STDCALL fn_5f17d0(u32 unused) {
  (void)unused;
  u8 *g = G(u8 *, 0x700390);
  u8 *o = vcall<u8 *>(g, 0x20, 0x6b8738u, 0x2b9u);
  typedef u32(__attribute__((cdecl)) * f_t)(u8 *, u32, u32);
  (*(f_t *)(*(u8 **)o + 0x2c))(o, 0x69c6b0, 0x6b88c8);
  typedef u32 (*hook_t)();
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __builtin_trap();
  return h();
}
PCREG(5f17d0, fn_5f17d0);

// 0x41c9c0: stdcall(a, b, c, d) ret 0x10: calls 0x41ca80(a, b, c, d); under a debugger (import [0x67606c] non-zero) without the
// SEH4 frame (table 0x6d4598), otherwise inside it with try level 0
static u32 STDCALL fn_41c9c0(u32 a, u32 b, u32 c, u32 d) {
  volatile Eh4 reg;
  reg.next = (Eh4 *)seh_head();
  reg.handler = 0x633665;
  reg.xtable = 0x6d4598 ^ G(u32, 0x6f5630);
  reg.level = -2;
  seh_set_head((volatile SehRecord *)&reg);
  u32 r;
  if ((*(u32(__stdcall **)())0x67606c)() == 0) {
    reg.level = 0;
    r = ext_41ca80(a, b, c, d);
    reg.level = -2;
  } else {
    r = ext_41ca80(a, b, c, d);
  }
  seh_set_head((volatile SehRecord *)reg.next);
  return r;
}
PCREG(41c9c0, fn_41c9c0);
