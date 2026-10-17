// batch240011.cpp - Sonnet-w4a: MSVC SEH4 prolog/epilog helpers (naked copies) and the __ehvec_ctor/dtor loops built on them.
#include "ff.h"

extern "C" void THISCALL ext_634aae(u32 fn);   // import thunk (control-flow-guard check): ecx = target, no stack args

// registration record of an SEH4 frame: [ebp-0x10] next, [ebp-0xc] handler, [ebp-8] scope table ^ cookie, [ebp-4] try level
struct Eh4 {
  Eh4 *next;
  u32 handler;
  u32 xtable;
  s32 level;
};
static inline void eh4_enter(volatile Eh4 *r, u32 table) {
  r->next = (Eh4 *)seh_head();
  r->handler = 0x633665;
  r->xtable = table ^ G(u32, 0x6f5630);
  r->level = -2;
  seh_set_head((volatile SehRecord *)r);
}
static inline void eh4_leave(volatile Eh4 *r) { seh_set_head((volatile SehRecord *)r->next); }
static inline void callfn(u32 fn, u32 self) { ((u32(THISCALL *)(u32))fn)(self); }

// 0x634ac0 (_SEH_prolog4): builds the frame from [esp]=ret, [esp+4]=scope table, [esp+8]=locals size; naked copy
extern "C" __attribute__((naked, used)) void fn_634ac0() {
  asm volatile(
      "pushl $0x633665\n"
      "pushl %fs:0\n"
      "movl 0x10(%esp), %eax\n"
      "movl %ebp, 0x10(%esp)\n"
      "leal 0x10(%esp), %ebp\n"
      "subl %eax, %esp\n"
      "pushl %ebx\n"
      "pushl %esi\n"
      "pushl %edi\n"
      "movl 0x6f5630, %eax\n"
      "xorl %eax, -4(%ebp)\n"
      "xorl %ebp, %eax\n"
      "pushl %eax\n"
      "movl %esp, -0x18(%ebp)\n"
      "pushl -8(%ebp)\n"
      "movl -4(%ebp), %eax\n"
      "movl $0xfffffffe, -4(%ebp)\n"
      "movl %eax, -8(%ebp)\n"
      "leal -0x10(%ebp), %eax\n"
      "movl %eax, %fs:0\n"
      "ret\n");
}
PCREG(634ac0, fn_634ac0);

// 0x634b06 (_SEH_epilog4): restores fs:[0] from the frame and returns to the caller's caller; naked copy
extern "C" __attribute__((naked, used)) void fn_634b06() {
  asm volatile(
      "movl -0x10(%ebp), %ecx\n"
      "movl %ecx, %fs:0\n"
      "popl %ecx\n"
      "popl %edi\n"
      "popl %edi\n"
      "popl %esi\n"
      "popl %ebx\n"
      "movl %ebp, %esp\n"
      "popl %ebp\n"
      "pushl %ecx\n"
      "ret\n");
}
PCREG(634b06, fn_634b06);

// 0x634206: stdcall(p, size, count, fn) ret 0x10: __ehvec cleanup: count times: p -= size; fn(p) (thiscall), guarded
static void STDCALL fn_634206(u32 p, u32 size, u32 count, u32 fn) {
  volatile Eh4 reg;
  eh4_enter(&reg, 0x6dcd88);
  reg.level = 0;
  u32 edi = p;
  for (u32 esi = 0; esi != count; esi++) {
    edi -= size;
    ext_634aae(fn);
    callfn(fn, edi);
  }
  reg.level = -2;
  eh4_leave(&reg);
}
PCREG(634206, fn_634206);

// 0x634123: stdcall(p, size, count, fn, unused) ret 0x14: __ehvec_ctor loop: count times: fn(p); p += size
static void STDCALL fn_634123(u32 p, u32 size, u32 count, u32 fn, u32 unused) {
  (void)unused;
  volatile Eh4 reg;
  eh4_enter(&reg, 0x6dcd48);
  reg.level = 0;
  for (u32 ebx = 0; ebx != count; ebx++) {
    ext_634aae(fn);
    callfn(fn, p);
    p += size;
  }
  reg.level = -2;
  eh4_leave(&reg);
}
PCREG(634123, fn_634123);

// 0x63418c: stdcall(p, size, count, fn) ret 0x10: __ehvec_dtor loop: from the end: count times: p -= size; fn(p)
static void STDCALL fn_63418c(u32 p, u32 size, u32 count, u32 fn) {
  volatile Eh4 reg;
  eh4_enter(&reg, 0x6dcd68);
  u32 esi = p + size * count;
  reg.level = 0;
  u32 edi = count;
  for (;;) {
    u32 e = edi;
    edi--;
    if (e == 0) break;
    esi -= size;
    ext_634aae(fn);
    callfn(fn, esi);
  }
  reg.level = -2;
  eh4_leave(&reg);
}
PCREG(63418c, fn_63418c);

// 0x634178 / 0x6341f6: unwind funclets, al = "completed" flag; when 0 they call 0x634206(p, size, count=ebx/edi, fn) from the
// parent frame (naked copies: they read ebp/ebx/esi/edi of the parent)
extern "C" __attribute__((naked, used)) void fn_634178() {
  asm volatile(
      "testb %al, %al\n"
      "jne 1f\n"
      "pushl 0x18(%ebp)\n"
      "pushl %ebx\n"
      "pushl 0xc(%ebp)\n"
      "pushl 8(%ebp)\n"
      "call ext_634206\n"
      "1: ret\n");
}
PCREG(634178, fn_634178);
extern "C" __attribute__((naked, used)) void fn_6341f6() {
  asm volatile(
      "testb %al, %al\n"
      "jne 1f\n"
      "pushl 0x14(%ebp)\n"
      "pushl %edi\n"
      "pushl %ebx\n"
      "pushl %esi\n"
      "call ext_634206\n"
      "1: ret\n");
}
PCREG(6341f6, fn_6341f6);
