// batch45003.cpp - tier H slice 5 (t6, Sonnet): 0x4616c0 (/GS asm), 0x561f70, 0x49a560.
#include "ff.h"

extern "C" void ext_633654(void);
extern "C" void ext_43df70(void);
extern "C" void ext_4db7c0(void);
extern "C" void ext_4dce50(void);
extern "C" void ext_4dd060(void);
extern "C" void ext_634d7c(void);
extern "C" void THISCALL ext_4f9680(void *, u32);
extern "C" void THISCALL ext_563750(void *, u32, u32);

// 0x4616c0 thiscall() plain ret, this = esi, /GS with esp-xored cookie after `and esp,-8`: 0x43df70(this); P=this[8]; 0x4db7c0(P, &v) fills v[3];
// m = max(v[2], max(v[1], v[0])) (SSE operand order) stored in all three; len = (float)sqrt((double)(m*m*3 as m2+m2+m2)) + K(0x678858); 0x4dce50(this[8], len); 0x4dd060(this[8], &v); /GS check.
asm(
    ".text\n"
    ".globl thunk4616c0\n"
    "thunk4616c0:\n"
    "  pushl %ebp\n"
    "  movl %esp, %ebp\n"
    "  andl $-8, %esp\n"
    "  subl $0x14, %esp\n"
    "  movl 0x6f5630, %eax\n"
    "  xorl %esp, %eax\n"
    "  movl %eax, 0x10(%esp)\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  call ext_43df70\n"
    "  movl 8(%esi), %ecx\n"
    "  leal 8(%esp), %eax\n"
    "  pushl %eax\n"
    "  call ext_4db7c0\n"
    "  movss 0xc(%esp), %xmm0\n"
    "  maxss 8(%esp), %xmm0\n"
    "  movss 0x10(%esp), %xmm1\n"
    "  maxss %xmm0, %xmm1\n"
    "  movss %xmm1, 8(%esp)\n"
    "  movss %xmm1, 0xc(%esp)\n"
    "  movss %xmm1, 0x10(%esp)\n"
    "  mulss %xmm1, %xmm1\n"
    "  movaps %xmm1, %xmm0\n"
    "  addss %xmm1, %xmm0\n"
    "  addss %xmm1, %xmm0\n"
    "  cvtps2pd %xmm0, %xmm0\n"
    "  call ext_634d7c\n"
    "  cvtsd2ss %xmm0, %xmm0\n"
    "  pushl %ecx\n"
    "  movl 8(%esi), %ecx\n"
    "  addss 0x678858, %xmm0\n"
    "  movss %xmm0, (%esp)\n"
    "  call ext_4dce50\n"
    "  movl 8(%esi), %ecx\n"
    "  leal 8(%esp), %eax\n"
    "  pushl %eax\n"
    "  call ext_4dd060\n"
    "  movl 0x14(%esp), %ecx\n"
    "  popl %esi\n"
    "  xorl %esp, %ecx\n"
    "  call ext_633654\n"
    "  movl %ebp, %esp\n"
    "  popl %ebp\n"
    "  ret\n");
extern "C" void thunk4616c0(void);
PCREG(4616c0, thunk4616c0);

// 0x561f70 thiscall() plain ret: 0x4f9680(0x700e24, 2); st = this[0xdc]; when st is 3 or 5: this[0x64] = (float)(int)engine(0x70039c)[0x30] * K(0x6785e4);
// 0x563750(this, st, 0); this[0x85] = 1; slot 0xbc(0) of the objects this[0x4c] and this[0x50] when non-null; slot 0xd4(0) of this; this[0xdc] = (this[0xdc] == 5) ? 6 : 0.
static void THISCALL fn_561f70(u8 *self) {
  ext_4f9680((void *)0x700e24, 2);
  u32 st = *(u32 *)(self + 0xdc);
  if (st == 3 || st == 5) {
    u8 *eng = *(u8 **)0x70039c;
    *(float *)(self + 0x64) = (float)(s32) * (u32 *)(eng + 0x30) * *(float *)0x6785e4;
    ext_563750(self, st, 0);
    self[0x85] = 1;
    void *o = *(void **)(self + 0x4c);
    if (o) vcall<void>(o, 0xbc, 0);
    o = *(void **)(self + 0x50);
    if (o) vcall<void>(o, 0xbc, 0);
    vcall<void>(self, 0xd4, 0);
    *(u32 *)(self + 0xdc) = (*(u32 *)(self + 0xdc) == 5) ? 6 : 0;
  }
}
PCREG(561f70, fn_561f70);

// 0x49a560 thiscall(A) ret 4: A->slot 0xc(); this->slot 0x14(&n) gives a count; n times: this->slot 0x40(&a), this->slot 0x50(&f), A->slot 0x98(a, f, 0).
static void THISCALL fn_49a560(u8 *self, u8 *a) {
  u32 n;
  u32 v = 0;
  float f = 0;
  vcall<void>(a, 0xc);
  vcall<void>(self, 0x14, &n);
  if (n != 0) {
    u32 i = 0;
    do {
      vcall<void>(self, 0x40, &v);
      vcall<void>(self, 0x50, &f);
      vcall<void>(a, 0x98, v, f, (u32)0);
      i++;
    } while (i != n);
  }
}
PCREG(49a560, fn_49a560);
