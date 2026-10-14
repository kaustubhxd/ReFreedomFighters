// batch31062.cpp - sysobj tail thunk and small field/array functions.
#include "ff.h"

asm(
    ".text\n"
    ".globl thunk494000\nthunk494000:\n  movl 0x70039c, %eax\n  movl 0x1a9f(%eax), %ecx\n  testl %ecx, %ecx\n  jne 1f\n  xorl %eax, %eax\n  ret $4\n1:\n  movl (%ecx), %eax\n  jmp *0x128(%eax)\n");
extern "C" void thunk494000(void);
PCREG(494000, thunk494000);

// 0x5a5f40 thiscall: clear byte +0x35 of each of the 12 objects pointed to from this+0x440.., then zero [this+0x47c].
THISCALL void fn5a5f40(u8 *self) {
  u32 *p = (u32 *)(self + 0x440);
  for (int i = 0; i < 12; i++) ((u8 *)p[i])[0x35] = 0;
  *(u32 *)(self + 0x47c) = 0;
}
PCREG(5a5f40, fn5a5f40);

// 0x463fc0 thiscall: for each 0x18-byte entry of the array at this+0x1c (count at this+0x20) with (flags@+4 & 3)==0, zero dword +0x10.
THISCALL void fn463fc0(u8 *self) {
  u8 *e = *(u8 **)(self + 0x1c);
  u32 n = *(u32 *)(self + 0x20);
  for (u32 i = 0; i < n; i++, e += 0x18)
    if ((e[4] & 3) == 0) *(u32 *)(e + 0x10) = 0;
}
PCREG(463fc0, fn463fc0);

// 0x462d30 thiscall ret 4: entry idx of the 0x18-byte array at this+0x1c; if [+0x14] != 0 and (flags@+4 & 3), return [[+0x14]+0x14], else 0.
THISCALL u32 fn462d30(u8 *self, int idx) {
  u8 *e = *(u8 **)(self + 0x1c) + idx * 0x18;
  u8 *p = *(u8 **)(e + 0x14);
  if (p && (e[4] & 3)) return *(u32 *)(p + 0x14);
  return 0;
}
PCREG(462d30, fn462d30);

// 0x537310 thiscall ret 4: base=[this+0x5302]; returns base + arg->[4] when base, arg and arg->[4] are nonzero, else 0.
THISCALL u32 fn537310(u8 *self, u8 *arg) {
  u32 base = *(u32 *)(self + 0x5302);
  if (!base || !arg) return 0;
  u32 off = *(u32 *)(arg + 4);
  if (!off) return 0;
  return off + base;
}
PCREG(537310, fn537310);

// 0x4669c0 thiscall ret 4: if [this+0x25] == 0x7fffffff return false, else copy 3 dwords from this+0x25 to out, return true.
THISCALL u8 fn4669c0(u8 *self, u32 *out) {
  if (*(u32 *)(self + 0x25) == 0x7fffffff) return 0;
  out[0] = *(u32 *)(self + 0x25);
  out[1] = *(u32 *)(self + 0x29);
  out[2] = *(u32 *)(self + 0x2d);
  return 1;
}
PCREG(4669c0, fn4669c0);

// 0x6361e0 thiscall constructor: fixed initial fields, vtable 0x6c2114, returns this.
THISCALL u8 *fn6361e0(u8 *self) {
  *(u32 *)(self + 0x1c) = 0;
  *(u32 *)(self + 4) = 0x52474241;
  *(u32 *)(self + 8) = 0;
  *(u32 *)(self + 0xc) = 0;
  *(u32 *)(self + 0x10) = 0;
  *(u32 *)(self + 0x14) = 0;
  *(u32 *)(self + 0x18) = 0;
  self[0x28] = 0;
  *(u32 *)(self + 0x29) = 0;
  *(u32 *)self = 0x6c2114;
  return self;
}
PCREG(6361e0, fn6361e0);
