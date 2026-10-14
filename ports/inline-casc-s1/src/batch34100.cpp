// batch34100.cpp - escalation batch 34100: small wrappers 0x4bb9d0 / 0x5761b0 / 0x57f410 (asm), 0x612550, 0x566e40, 0x57c1c0.
#include "ff.h"

extern "C" void thunk4bb9d0(void);
extern "C" void thunk5761b0(void);
extern "C" void thunk57f410(void);
asm(
    ".text\n"
    ".globl thunk4bb9d0\n"
    "thunk4bb9d0:\n"          // [this+4] &= ~0x40; ext_4c24b0(this); al = 1; ret 4
    "  andl $0xffffffbf, 4(%ecx)\n"
    "  call ext_4c24b0\n"
    "  mov $1, %al\n"
    "  ret $4\n"
    ".globl thunk5761b0\n"
    "thunk5761b0:\n"          // ext_562260(this); tail jump to 0x5772c0 with ecx = this
    "  push %esi\n"
    "  mov %ecx, %esi\n"
    "  call ext_562260\n"
    "  mov %esi, %ecx\n"
    "  pop %esi\n"
    "  jmp ext_5772c0\n"
    ".globl thunk57f410\n"
    "thunk57f410:\n"          // ext_5626c0(this); tail jump to 0x57f420 with ecx = this
    "  push %esi\n"
    "  mov %ecx, %esi\n"
    "  call ext_5626c0\n"
    "  mov %esi, %ecx\n"
    "  pop %esi\n"
    "  jmp ext_57f420\n");
PCREG(4bb9d0, thunk4bb9d0);
PCREG(5761b0, thunk5761b0);
PCREG(57f410, thunk57f410);

extern "C" u32 STDCALL ext_634cf8(u32 p);              // import thunk, stdcall (callee pops its one argument)
extern "C" u32 THISCALL ext_566f10(void *self);        // thiscall, plain ret
extern "C" u32 THISCALL ext_561c40(void *self);        // thiscall, plain ret (al)

// 0x612550, thiscall plain: p = [this+4]; [this] = 0x6bd5d0; returns ext_634cf8(p).
static u32 THISCALL fn612550(u8 *self) {
  u32 p = *(u32 *)(self + 4);
  *(u32 *)self = 0x6bd5d0;
  return ext_634cf8(p);
}
PCREG(612550, fn612550);

// 0x566e40, thiscall plain: [this+0x198] = ext_566f10(this); returns it.
static u32 THISCALL fn566e40(u8 *self) {
  u32 v = ext_566f10(self);
  *(u32 *)(self + 0x198) = v;
  return v;
}
PCREG(566e40, fn566e40);

// 0x57c1c0, thiscall plain: v = ext_561c40(this); byte [this+0x184] = low byte of v; returns v.
static u32 THISCALL fn57c1c0(u8 *self) {
  u32 v = ext_561c40(self);
  self[0x184] = v;
  return v;
}
PCREG(57c1c0, fn57c1c0);
