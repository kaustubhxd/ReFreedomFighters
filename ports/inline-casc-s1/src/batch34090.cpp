// batch34090.cpp - escalation batch 34090: 0x5d3640 (asm), 0x497390, 0x4d3ad0, 0x5273b0, 0x602240.
#include "ff.h"

extern "C" void thunk5d3640(void);
asm(
    ".text\n"
    ".globl thunk5d3640\n"
    "thunk5d3640:\n"          // ext_5d3520(this); when byte [this+0x54] is set tail jump to 0x5d3780 with ecx = this
    "  push %esi\n"
    "  mov %ecx, %esi\n"
    "  call ext_5d3520\n"
    "  cmpb $0, 0x54(%esi)\n"
    "  je 1f\n"
    "  mov %esi, %ecx\n"
    "  pop %esi\n"
    "  jmp ext_5d3780\n"
    "1:\n"
    "  pop %esi\n"
    "  ret\n");
PCREG(5d3640, thunk5d3640);

extern "C" u32 THISCALL ext_497320(void *self, u32 a);                           // thiscall ret 4
extern "C" u32 THISCALL ext_4d2700(void *self, u32 a, u32 b, u32 c, u32 *d, u32 e);   // thiscall ret 0x14
extern "C" void THISCALL ext_526ef0(void *self);                                  // thiscall, plain ret
extern "C" void ext_634273(void *p, u32 n);                                       // cdecl free

// 0x497390, thiscall(a) ret 4: a null returns 0; else ext_497320(this, [a+8]) and its result.
static u32 THISCALL fn497390(u8 *self, u8 *a) {
  if (!a) return 0;
  return ext_497320(self, *(u32 *)(a + 8));
}
PCREG(497390, fn497390);

// 0x4d3ad0, thiscall(a, b, c) ret 0xc: ext_4d2700(this, a, 4, c, &b, 0), where &b is the address of the parameter slot (the callee may rewrite it); returns its result.
static u32 THISCALL fn4d3ad0(u8 *self, u32 a, u32 b, u32 c) {
  u32 bb = b;
  return ext_4d2700(self, a, 4, c, &bb, 0);
}
PCREG(4d3ad0, fn4d3ad0);

// 0x5273b0, thiscall, plain ret, returns this: [this] = 0x6a0ae8; ext_526ef0(this+0x28); [this+0x1c] = 0x39000000; [this+0x20] = 0; [this+0x24] = 0x39000000.
static u32 THISCALL fn5273b0(u8 *self) {
  *(u32 *)self = 0x6a0ae8;
  ext_526ef0(self + 0x28);
  *(u32 *)(self + 0x1c) = 0x39000000;
  *(u32 *)(self + 0x20) = 0;
  *(u32 *)(self + 0x24) = 0x39000000;
  return (u32)self;
}
PCREG(5273b0, fn5273b0);

// 0x602240, thiscall, plain ret: [this] = 0x6b8508; when byte [this+0x14] is zero and [this+4] is set: ext_634273([this+4], 1).
static void THISCALL fn602240(u8 *self) {
  u8 flag = self[0x14];
  *(u32 *)self = 0x6b8508;
  if (flag == 0) {
    u8 *p = *(u8 **)(self + 4);
    if (p) ext_634273(p, 1);
  }
}
PCREG(602240, fn602240);
