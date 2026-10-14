// batch34092.cpp - escalation batch 34092: 0x55c770, 0x534d80 (asm), 0x48ab70 / 0x4e5050 / 0x534d00 (scalar deleting destructors), 0x51ab40.
#include "ff.h"

extern "C" void thunk534d80(void);
asm(
    ".text\n"
    ".globl thunk534d80\n"
    "thunk534d80:\n"          // this = [this+0x52fa]; null: ret 4; else tail jump to 0x53b1b0
    "  push %ebp\n  mov %esp, %ebp\n"
    "  mov 0x52fa(%ecx), %ecx\n"
    "  test %ecx, %ecx\n"
    "  je 1f\n"
    "  pop %ebp\n"
    "  jmp ext_53b1b0\n"
    "1:\n"
    "  pop %ebp\n"
    "  ret $4\n");
PCREG(534d80, thunk534d80);

extern "C" u32 *THISCALL ext_5003d0(void *m, u32 i);   // thiscall ret 4
extern "C" void THISCALL ext_48a880(void *self);       // thiscall, plain ret
extern "C" void THISCALL ext_534be0(void *self);       // thiscall, plain ret
extern "C" void ext_634273(void *p, u32 n);            // cdecl free

// 0x55c770, thiscall(a) ret 4: v = *ext_5003d0([a+4], 0); unaligned dword [[this+0x1c]+0x945] = v; returns v.
static u32 THISCALL fn55c770(u8 *self, u8 *a) {
  u32 v = *ext_5003d0(*(u8 **)(a + 4), 0);
  u8 *t = *(u8 **)(self + 0x1c);
  t[0x945] = v; t[0x946] = v >> 8; t[0x947] = v >> 16; t[0x948] = v >> 24;
  return v;
}
PCREG(55c770, fn55c770);

// 0x48ab70, thiscall(flags) ret 4, returns this: ext_48a880(this); when bit 0 of flags is set ext_634273(this, 0x5da5).
static u32 THISCALL fn48ab70(u8 *self, u32 flags) {
  ext_48a880(self);
  if (flags & 1) ext_634273(self, 0x5da5);
  return (u32)self;
}
PCREG(48ab70, fn48ab70);

// 0x534d00, thiscall(flags) ret 4, returns this: ext_534be0(this); when bit 0 of flags is set ext_634273(this, 0x5462).
static u32 THISCALL fn534d00(u8 *self, u32 flags) {
  ext_534be0(self);
  if (flags & 1) ext_634273(self, 0x5462);
  return (u32)self;
}
PCREG(534d00, fn534d00);

// 0x4e5050, thiscall(flags) ret 4, returns this: [this] = 0x697360; when bit 0 of flags is set ext_634273(this, 0x2c).
static u32 THISCALL fn4e5050(u8 *self, u32 flags) {
  *(u32 *)self = 0x697360;
  if (flags & 1) ext_634273(self, 0x2c);
  return (u32)self;
}
PCREG(4e5050, fn4e5050);

// 0x51ab40, thiscall(a) ret 4, returns [this+0x18]: byte [[this+0x18]+0x2c3] = (*ext_5003d0([a+4], 0) != 0).
static u32 THISCALL fn51ab40(u8 *self, u8 *a) {
  u32 *cell = ext_5003d0(*(u8 **)(a + 4), 0);
  u8 flag = *cell != 0;
  u8 *t = *(u8 **)(self + 0x18);
  t[0x2c3] = flag;
  return (u32)t;
}
PCREG(51ab40, fn51ab40);
