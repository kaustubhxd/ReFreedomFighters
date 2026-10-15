// batch32085.cpp - cascade h2 (Sonnet): eight tier C wrappers (fifth batch); two are naked ports because a slot call leaves its stack arguments for the next callee.
#include "ff.h"

extern "C" u32 THISCALL ext_5003d0(u8 *self, u32 a);   // thiscall ret 4
extern "C" void THISCALL ext_45f3a0(u8 *self);         // thiscall, plain ret
extern "C" u32 THISCALL ext_52b9d0(u8 *self);          // thiscall, plain ret
extern "C" u32 THISCALL ext_4e5e60(u8 *self);          // thiscall, plain ret
extern "C" u32 THISCALL ext_4f2f60(u8 *self, u32 a);   // thiscall ret 4
extern "C" u32 THISCALL ext_43ec00(u8 *self, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);   // thiscall ret 0x18

// 0x4f2cc0, thiscall(a) ret 4: r = slot 0x4c of the engine table with a; tail jump to slot 0x40 of the object embedded at this+0x1a7 (its vtable pointer is the
// unaligned dword at that address) with r.
static u32 THISCALL fn4f2cc0(u8 *self, u32 a) {
  u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 r = vcall<u32>(tbl, 0x4c, a);
  return vcall<u32>(self + 0x1a7, 0x40, r);
}
PCREG(4f2cc0, fn4f2cc0);

// 0x51eb50, thiscall(a) ret 4: r = 0x5003d0([a+4], 0); returns slot 0x398 of [this+0x18] with [r].
static u32 THISCALL fn51eb50(u8 *self, u8 *a) {
  u32 r = ext_5003d0(*(u8 **)(a + 4), 0);
  return vcall<u32>(*(void **)(self + 0x18), 0x398, *(u32 *)r);
}
PCREG(51eb50, fn51eb50);

// 0x52b3f0, thiscall no args: 0x45f3a0(this); word [this+0x91] = slot 0x114 of the engine table with (0x6a0f84, 0, 0x6a0f54, 0x2292); tail jump to 0x52b9d0(this).
static u32 THISCALL fn52b3f0(u8 *self) {
  ext_45f3a0(self);
  u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 v = vcall<u32>(tbl, 0x114, 0x6a0f84u, 0u, 0x6a0f54u, 0x2292u);
  self[0x91] = v;
  self[0x92] = v >> 8;
  return ext_52b9d0(self);
}
PCREG(52b3f0, fn52b3f0);

// 0x5c3c30, thiscall(a, b) ret 8, returns eax of the last slot: v = 0x4e5e60(b); [this+0x49] = v (unaligned); byte [this+0x48] = 0; slot 0xbc of [this+0x44] with 1.
static u32 THISCALL fn5c3c30(u8 *self, u32 a, u8 *b) {
  u32 v = ext_4e5e60(b);
  self[0x49] = v; self[0x4a] = v >> 8; self[0x4b] = v >> 16; self[0x4c] = v >> 24;
  self[0x48] = 0;
  return vcall<u32>(*(void **)(self + 0x44), 0xbc, 1u);
}
PCREG(5c3c30, fn5c3c30);

// 0x5f0d80, fastcall-style (ecx = this, edx = a): t = slot 0x58 of the engine table with a; r = slot 0x2c4 of t with this (the slot leaves its argument on the
// stack); 0x4f2f60(r) (ret 4) consumes that argument.
extern "C" __attribute__((naked)) void f32085_5f0d80() {
  asm volatile("mov 0x70039c, %eax\n\t"
               "push %esi\n\t"
               "mov %ecx, %esi\n\t"
               "push %edx\n\t"
               "mov 0x9b(%eax), %ecx\n\t"
               "mov (%ecx), %eax\n\t"
               "call *0x58(%eax)\n\t"
               "push %esi\n\t"
               "mov %eax, %ecx\n\t"
               "mov (%eax), %edx\n\t"
               "call *0x2c4(%edx)\n\t"
               "mov %eax, %ecx\n\t"
               "call ext_4f2f60\n\t"
               "pop %esi\n\t"
               "ret\n\t");
}
PCREG(5f0d80, f32085_5f0d80);

// 0x467230, thiscall(a) ret 4: e = [this+8]; r = slot 0x20 of this with (e, e+0x24, a, 0, 0, 0) (the slot leaves the six arguments on the stack);
// 0x43ec00(r) (ret 0x18) consumes them.
extern "C" __attribute__((naked)) void f32085_467230() {
  asm volatile("push %ebp\n\t"
               "mov %esp, %ebp\n\t"
               "mov 8(%ecx), %edx\n\t"
               "push $0\n\t"
               "push $0\n\t"
               "push $0\n\t"
               "push 8(%ebp)\n\t"
               "lea 0x24(%edx), %eax\n\t"
               "push %eax\n\t"
               "mov (%ecx), %eax\n\t"
               "push %edx\n\t"
               "call *0x20(%eax)\n\t"
               "mov %eax, %ecx\n\t"
               "call ext_43ec00\n\t"
               "pop %ebp\n\t"
               "ret $4\n\t");
}
PCREG(467230, f32085_467230);

// 0x475a80, thiscall(a) ret 4: slot 0x10 of this != 0 -> returns slot 8 of this with (a, 0); else 0.
static u32 THISCALL fn475a80(void *self, u32 a) {
  if (!vcall<u32>(self, 0x10)) return 0;
  return vcall<u32>(self, 8, a, 0u);
}
PCREG(475a80, fn475a80);

// 0x47fc10, thiscall no args: o = [this+4]; o != 0 and slot 0x10 of o returns false (al == 0) -> tail jump to slot 0x14 of this; else returns that slot's eax.
// (o == 0 leaves eax undefined in the exe: not modelled, the spec never exercises it.)
static u32 THISCALL fn47fc10(u8 *self) {
  void *o = *(void **)(self + 4);
  if (!o) return 0;
  u32 r = vcall<u32>(o, 0x10);
  if ((u8)r) return r;
  return vcall<u32>(self, 0x14);
}
PCREG(47fc10, fn47fc10);
