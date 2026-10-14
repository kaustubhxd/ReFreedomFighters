// batch34091.cpp - escalation batch 34091: wrappers 0x4c31b0, 0x628e70, 0x451a00 (asm), 0x55ffb0, 0x626d70, 0x51e910.
#include "ff.h"

extern "C" void thunk451a00(void);
asm(
    ".text\n"
    ".globl thunk451a00\n"
    "thunk451a00:\n"          // p = [this+0x3c]; [this] = 0x6813c0; when p is set ext_634273(p, 0x7c) (cdecl); tail jump to 0x43de70 with ecx = this
    "  push %esi\n"
    "  mov %ecx, %esi\n"
    "  mov 0x3c(%esi), %eax\n"
    "  movl $0x6813c0, (%esi)\n"
    "  test %eax, %eax\n"
    "  je 1f\n"
    "  push $0x7c\n"
    "  push %eax\n"
    "  call ext_634273\n"
    "  add $8, %esp\n"
    "1:\n"
    "  mov %esi, %ecx\n"
    "  pop %esi\n"
    "  jmp ext_43de70\n");
PCREG(451a00, thunk451a00);

extern "C" void THISCALL ext_4c3740(void *self, u32 a);                 // thiscall ret 4
extern "C" u32 ext_628c80(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);    // cdecl
extern "C" u32 *THISCALL ext_5003d0(void *m, u32 i);                    // thiscall ret 4
extern "C" u8 *ext_626b00(u32 a, u32 b, u32 c, u32 d);                  // cdecl

// 0x4c31b0, thiscall(a, b) ret 8, returns 0: when the low word of a is 0x401: ext_4c3740([this+0x4c], [[this+0x44]+8]).
static u32 THISCALL fn4c31b0(u8 *self, u32 a, u32 b) {
  (void)b;
  if ((u16)a == 0x401) {
    u8 *x = *(u8 **)(self + 0x44);
    ext_4c3740(*(u8 **)(self + 0x4c), *(u32 *)(x + 8));
  }
  return 0;
}
PCREG(4c31b0, fn4c31b0);

// 0x628e70, cdecl(a, b, c, d): ext_628c80(0x6f4424, a, 1, b, c, d), returns its result.
static u32 fn628e70(u32 a, u32 b, u32 c, u32 d) {
  return ext_628c80(0x6f4424, a, 1, b, c, d);
}
PCREG(628e70, fn628e70);

// 0x55ffb0, stdcall(a) ret 4: cell = ext_5003d0([a+4], 0); flag = (*cell != 0); o = unaligned dword [[0x7003b8]+0x2c21]; byte [o+0x5c] = flag; returns o.
static u32 STDCALL fn55ffb0(u8 *a) {
  u32 *cell = ext_5003d0(*(u8 **)(a + 4), 0);
  u8 flag = *cell != 0;
  u8 *g = G(u8 *, 0x7003b8);
  u8 *o = (u8 *)(g[0x2c21] | g[0x2c22] << 8 | g[0x2c23] << 16 | (u32)g[0x2c24] << 24);
  o[0x5c] = flag;
  return (u32)o;
}
PCREG(55ffb0, fn55ffb0);

// 0x626d70, cdecl(a, b, c, d): r = ext_626b00(a, b, c, d); byte [r+0x86] = 0x17 when r is non-null; returns r.
static u8 *fn626d70(u32 a, u32 b, u32 c, u32 d) {
  u8 *r = ext_626b00(a, b, c, d);
  if (r) r[0x86] = 0x17;
  return r;
}
PCREG(626d70, fn626d70);

// 0x51e910, thiscall(a) ret 4: cell = ext_5003d0([a+4], 0); v = *cell; unaligned dword [[this+0x18]+0x272] = v; returns v.
static u32 THISCALL fn51e910(u8 *self, u8 *a) {
  u32 v = *ext_5003d0(*(u8 **)(a + 4), 0);
  u8 *t = *(u8 **)(self + 0x18);
  t[0x272] = v; t[0x273] = v >> 8; t[0x274] = v >> 16; t[0x275] = v >> 24;
  return v;
}
PCREG(51e910, fn51e910);
