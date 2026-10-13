// batch1212.cpp - fresh slice 12, batch 12: three more SEH-frame functions. 0x4af440 and 0x5c2440 pop the cookie slot
// into ECX and restore ESI, so plain C++ matches them; 0x4b2b40 has the batch 1210 epilogue (ESI = cookie ^ EBP) and
// gets a naked frame like those.
#include "ff.h"

extern "C" void THISCALL ext_469870(u8 *self);   // base constructor, ret 0
extern "C" void THISCALL ext_4ccba0(u8 *self);   // member constructor, ret 0
extern "C" void THISCALL ext_4ccf60(u8 *self);   // member destructor, ret 0

// 0x4af440: constructor. Base 0x469870, +4 |= 0x20, +0x44 = 0, vtable 0x690e10, word +0x5e = 0x100, then word +0x5c =
// engine(+0x9b) slot 0x114(0x690ec8, 0, 0x690e98, 0x11) (registers a type by name). Returns this.
static u8 *THISCALL ctor4af440(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x690e10;
  *(u16 *)(self + 0x5e) = 0x100;
  u8 *e = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  *(u16 *)(self + 0x5c) = (u16)vcall<u32>(e, 0x114, 0x690ec8u, 0u, 0x690e98u, 0x11u);
  return self;
}
PCREG(4af440, ctor4af440);

// 0x5c2440: destructor. Vtable 0x6b3c58, member destructors 0x4ccf60 on +0x1ae, +0x100, +0x54, then +0x44 = 0, +0x30 =
// 0, base vtable 0x686874, and engine(+0x9b) slot 0x34(this). Returns what that call returns (EAX passes through).
static u32 THISCALL dtor5c2440(u8 *self) {
  *(u32 *)self = 0x6b3c58;
  ext_4ccf60(self + 0x1ae);
  ext_4ccf60(self + 0x100);
  ext_4ccf60(self + 0x54);
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)self = 0x686874;
  u8 *e = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  return vcall<u32>(e, 0x34, self);
}
PCREG(5c2440, dtor5c2440);

// 0x4b2b40: allocate + construct (batch 1210 family): o = engine(+0x9b)->+8 ->slot 0x44(); if o: base 0x469870,
// +4 |= 0x20, +0x44 = 0, vtable 0x691900, member ctor 0x4ccba0(o + 0x4a). Exe frame with handler 0x668a89.
extern "C" __attribute__((used)) u8 *f12_body_4b2b40() {
  u8 *a = *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x9b) + 8);
  u8 *o = vcall<u8 *>(a, 0x44);
  if (o) {
    ext_469870(o);
    *(u32 *)(o + 4) |= 0x20;
    *(u32 *)(o + 0x44) = 0;
    *(u32 *)o = 0x691900;
    ext_4ccba0(o + 0x4a);
  }
  return o;
}
extern "C" __attribute__((naked)) void f12_seh_4b2b40() {
  asm volatile("push %ebp\n\t"
               "mov %esp, %ebp\n\t"
               "push $-1\n\t"
               "push $0x668a89\n\t"
               "mov %fs:0, %eax\n\t"
               "push %eax\n\t"
               "sub $8, %esp\n\t"
               "push %esi\n\t"
               "mov 0x6f5630, %eax\n\t"
               "xor %ebp, %eax\n\t"
               "push %eax\n\t"
               "lea -0xc(%ebp), %eax\n\t"
               "mov %eax, %fs:0\n\t"
               "push %ecx\n\t"
               "call f12_body_4b2b40\n\t"
               "mov %eax, %esi\n\t"
               "mov %esi, -0x10(%ebp)\n\t"
               "mov %esi, -0x14(%ebp)\n\t"
               "movl $1, -4(%ebp)\n\t"
               "mov %esi, %eax\n\t"
               "mov -0xc(%ebp), %ecx\n\t"
               "mov %ecx, %fs:0\n\t"
               "pop %ecx\n\t"
               "pop %esi\n\t"
               "mov %ebp, %esp\n\t"
               "pop %ebp\n\t"
               "ret\n\t");
}
PCREG(4b2b40, f12_seh_4b2b40);
