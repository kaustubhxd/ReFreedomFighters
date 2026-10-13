// batch1018.cpp - area 81, batch 1018: ZProjectile::CheckHit(t), 0x4b9340, thiscall, one float argument, ret 4. Asm-style port.
// The exe's epilogue is odd: on the main path it pushes edi then ecx (overwritten with -t), and its exits pop edi and esi from those slots, so it
// returns with esi = the caller's edi and edi = bits(-t) (movss [esp], xmm1 writes 0x80000000 xor'd t). The naked wrapper below saves the caller's
// esi and edi, runs the C core (cdecl, float in st0), and on the main path sets esi = caller's edi and edi = bits(t) ^ 0x80000000; on the early path
// (0 >= t) it restores both. Stand-ins (GUESS): 0x443ef0 (thiscall on the vector, one argument), 0x4dc630 (thiscall, two arguments), 0x43e920
// (fastcall, one stack argument). The SEH-less exe has no cookie check here.
#include "ff.h"

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

extern "C" void THISCALL ext_443ef0(void *self, u32 a);          // GUESS (stood in)
extern "C" void THISCALL ext_4dc630(void *self, u32 a, u32 b);   // GUESS (stood in)
extern "C" void __attribute__((fastcall)) ext_43e920(void *ecx, void *edx, void *a2);  // GUESS (stood in)

extern "C" volatile u32 checkHitMain = 0;

// The C core: returns the value in st0 and sets checkHitMain on the main path.
extern "C" float checkHitCore(u8 *self, float t) {
  checkHitMain = 0;
  if (0.0f >= t)
    return 0.0f;
  checkHitMain = 1;
  u8 *M = (u8 *)D(self, 0x44);
  u8 *Z = (u8 *)D(M, 8);
  float l10[3] = {*(float *)(Z + 0x24), *(float *)(Z + 0x28), *(float *)(Z + 0x2c)};
  float l1c[3];
  ext_443ef0(l1c, (u32)(Z + 0x18));
  vcall<void>((void *)vcall<u32>(M, 0x20), 0x84, (u32)l10);
  vcall<void>((void *)vcall<u32>(M, 0x20), 0x84, (u32)l1c);
  u8 *rm = (u8 *)D(*(u8 **)0x70039c, 0x9b);
  u8 *r = (u8 *)vcall<u32>(rm, 0x58, D(self, 0x65));
  u32 edi = 0;
  u8 *Y = 0;
  if (r) {
    Y = (u8 *)D(r, 8);
    edi = D(Y, 0x3c) & 6;
    ext_4dc630(Y, 0u, 6u);
  }
  u8 *P = (u8 *)D(self, 0x8d);
  *(float *)(P + 0) = l10[0];
  *(float *)(P + 4) = l10[1];
  *(float *)(P + 8) = l10[2];
  ext_43e920(P + 0xc, l1c, l10);
  *(float *)(P + 0x34) = 1.0f;
  *(u8 *)(P + 0x6c) = 1;
  u8 *R2 = (u8 *)D(rm, 0xadc);
  u8 al = (u8)vcall<u32>(R2, 0x2e0, (u32)P, 0u, 6u, 0xffffffffu, 1u, 1u);
  if (r)
    ext_4dc630(Y, edi, 0u);
  D(self, 0x65) = 0;
  if (al)
    return *(float *)(P + 0x34) * t;
  return t;
}

// The wrapper (thiscall: ecx = this, one stack float argument). Keeps the exe's register state at return.
__asm__(
    ".globl checkHitWrapper\n"
    "checkHitWrapper:\n"
    "  pushl %esi\n"
    "  pushl %edi\n"
    "  pushl 12(%esp)\n"
    "  pushl %ecx\n"
    "  call checkHitCore\n"
    "  addl $8, %esp\n"
    "  cmpl $0, checkHitMain\n"
    "  je 1f\n"
    "  movl (%esp), %esi\n"
    "  movl 12(%esp), %edi\n"
    "  xorl $0x80000000, %edi\n"
    "  addl $8, %esp\n"
    "  ret $4\n"
    "1:\n"
    "  popl %edi\n"
    "  popl %esi\n"
    "  ret $4\n");
extern "C" void checkHitWrapper();
PCREG(4b9340, checkHitWrapper);
