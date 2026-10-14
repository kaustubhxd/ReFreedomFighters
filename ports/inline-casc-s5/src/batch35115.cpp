// batch35115.cpp - cascade s5 batch 35115: 0x54eb80 (GUESS reset a tuning block to its defaults and register it with the owner).
#include "ff.h"

typedef s32(THISCALL *c7_t)(u32 ecx, u32, u32, u32, u32, u32, u32, u32);   // ECX plus seven stack args, callee pops 0x1c
typedef u8 *(THISCALL *r2_t)(void *, u32, u32);

// 0x54eb80, thiscall, no arguments. Nothing when [this+4] (the owner) is zero. Otherwise the dwords from +0x10 to +0x7c are set to their default constants, then the owner o = [this+4]: o's slot 0x10 is called with ECX = its vtable and
// stack args (o, 0x6bdf60, 0x80000001, 0, 0, this + 0x10, 0x70); a negative result logs line 0xba (fmt 0x6a421c) through the logger at 0x700390 (inline asm, caller-popped slot 0x2c).
static void THISCALL fn54eb80(u8 *self) {
  if (*(u32 *)(self + 4) == 0) return;
  *(u32 *)(self + 0x10) = 0x0;
  *(u32 *)(self + 0x14) = 0x40f00000;
  *(u32 *)(self + 0x18) = 0x3f800000;
  *(u32 *)(self + 0x1c) = 0xfffffc18;
  *(u32 *)(self + 0x20) = 0xffffff9c;
  *(u32 *)(self + 0x24) = 0x0;
  *(u32 *)(self + 0x28) = 0x3fbeb852;
  *(u32 *)(self + 0x2c) = 0x3f547ae1;
  *(u32 *)(self + 0x30) = 0x3f800000;
  *(u32 *)(self + 0x34) = 0xfffff5d6;
  *(u32 *)(self + 0x38) = 0x3be56042;
  *(u32 *)(self + 0x48) = 0xc8;
  *(u32 *)(self + 0x4c) = 0x3c343958;
  *(u32 *)(self + 0x5c) = 0x3e800000;
  *(u32 *)(self + 0x60) = 0x0;
  *(u32 *)(self + 0x64) = 0x3e800000;
  *(u32 *)(self + 0x68) = 0x0;
  *(u32 *)(self + 0x6c) = 0xc0a00000;
  *(u32 *)(self + 0x70) = 0x459c4000;
  *(u32 *)(self + 0x74) = 0x437a0000;
  *(u32 *)(self + 0x78) = 0x0;
  *(u32 *)(self + 0x7c) = 0x3f;
  *(u32 *)(self + 0x44) = 0x0;
  *(u32 *)(self + 0x40) = 0x0;
  *(u32 *)(self + 0x3c) = 0x0;
  *(u32 *)(self + 0x58) = 0x0;
  *(u32 *)(self + 0x54) = 0x0;
  *(u32 *)(self + 0x50) = 0x0;
  u8 *o = *(u8 **)(self + 4);
  u32 vt = *(u32 *)o;
  s32 r = ((c7_t)((u32 *)vt)[0x10 / 4])(vt, (u32)o, 0x6bdf60, 0x80000001, 0, 0, (u32)(self + 0x10), 0x70);
  if (r >= 0) return;
  u8 *lg = G(u8 *, 0x700390);
  u8 *l = (*(r2_t **)lg)[0x20 / 4](lg, 0x6a4168, 0xba);
  u32 vt2 = *(u32 *)l;
  u32 slot = ((u32 *)vt2)[0x2c / 4];
  asm volatile("push $0x6a421c\n\tpush %[r]\n\tcall *%[fn]\n\tadd $8, %%esp" : : "c"(vt2), [r] "r"(l), [fn] "r"(slot) : "eax", "edx", "memory", "cc");
}
PCREG(54eb80, fn54eb80);
