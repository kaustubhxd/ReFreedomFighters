// batch34105.cpp - escalation batch 34105: 0x4ea2b0, 0x532a80, 0x54c2a0 (asm), 0x55c7d0, 0x57a100, 0x5afed0, 0x5b7960.
#include "ff.h"

extern "C" void thunk54c2a0(void);
asm(
    ".text\n"
    ".globl thunk54c2a0\n"
    "thunk54c2a0:\n"          // ext_650dc0(this, a); this = [this+0x50]; null: ret 4; else tail jump through slot 0x20 with the argument slot untouched
    "  push %ebp\n  mov %esp, %ebp\n"
    "  push %esi\n"
    "  push 8(%ebp)\n"
    "  mov %ecx, %esi\n"
    "  call ext_650dc0\n"
    "  mov 0x50(%esi), %ecx\n"
    "  pop %esi\n"
    "  test %ecx, %ecx\n"
    "  je 1f\n"
    "  mov (%ecx), %eax\n"
    "  pop %ebp\n"
    "  jmp *0x20(%eax)\n"
    "1:\n"
    "  pop %ebp\n"
    "  ret $4\n");
PCREG(54c2a0, thunk54c2a0);

extern "C" u32 FASTCALL ext_441970(u32 a, u32 b, u8 *c);           // ecx = a, edx = b, stack c, ret 4
extern "C" u32 FASTCALL ext_441940(u32 a, u8 *b);                  // ecx = a, edx = b, plain ret
extern "C" u32 THISCALL ext_5329f0(void *self);                    // thiscall, plain ret
extern "C" void ext_634273(void *p, u32 n);                        // cdecl free
extern "C" u32 *THISCALL ext_5003d0(void *m, u32 i);               // thiscall ret 4
extern "C" u32 THISCALL ext_469870(void *self);                    // thiscall, plain ret
extern "C" u32 THISCALL ext_5afbb0(void *self, u32 a, u32 b);      // thiscall ret 8

// 0x4ea2b0, thiscall(a, b) ret 8: ext_441970(ecx = a, edx = b, this+0x18); then ext_441940(ecx = a, edx = this+0x3c); returns the second's eax.
static u32 THISCALL fn4ea2b0(u8 *self, u32 a, u32 b) {
  ext_441970(a, b, self + 0x18);
  return ext_441940(a, self + 0x3c);
}
PCREG(4ea2b0, fn4ea2b0);

// 0x532a80, thiscall(flags) ret 4, returns this: ext_5329f0(this); frees the object (size 0x548e) when bit 0 of flags is set.
static u32 THISCALL fn532a80(u8 *self, u32 flags) {
  ext_5329f0(self);
  if (flags & 1) ext_634273(self, 0x548e);
  return (u32)self;
}
PCREG(532a80, fn532a80);

// 0x55c7d0, thiscall(a) ret 4: v = *ext_5003d0([a+4], 0); dword [[[this+0x1c]+0x54]+8] = v; returns v.
static u32 THISCALL fn55c7d0(u8 *self, u8 *a) {
  u32 v = *ext_5003d0(*(u8 **)(a + 4), 0);
  *(u32 *)(*(u8 **)(*(u8 **)(self + 0x1c) + 0x54) + 8) = v;
  return v;
}
PCREG(55c7d0, fn55c7d0);

// 0x57a100 / 0x5b7960, thiscall plain, returns this: ext_469870(this); [this+4] |= 0x20; [this+0x44] = 0; [this] = 0x6a9b58 / 0x6b245c.
static u32 THISCALL fn57a100(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x6a9b58;
  return (u32)self;
}
PCREG(57a100, fn57a100);
static u32 THISCALL fn5b7960(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x6b245c;
  return (u32)self;
}
PCREG(5b7960, fn5b7960);

// 0x5afed0, thiscall(a, b) ret 8: v = ext_5afbb0(this+0x18, a, b); [this+0x14] = b; returns v.
static u32 THISCALL fn5afed0(u8 *self, u32 a, u32 b) {
  u32 v = ext_5afbb0(self + 0x18, a, b);
  *(u32 *)(self + 0x14) = b;
  return v;
}
PCREG(5afed0, fn5afed0);
