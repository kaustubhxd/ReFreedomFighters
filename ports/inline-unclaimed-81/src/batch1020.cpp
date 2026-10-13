// batch1020.cpp - area 81, batch 1020: CImpactResponse::Command(cmd, arg), 0x5dc230, thiscall, two stack arguments, ret 8. Returns 0 on every path (the
// exe clears eax). No SEH frame or cookie check. Stand-ins (GUESS): 0x41e290 (cdecl allocator, one argument; returns a fixed buffer), the function
// pointer at Q+8 (thiscall, no arguments), and the render manager's slot 0x114 (five arguments, returns a word in ax).
#include "ff.h"

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

extern "C" void *__attribute__((cdecl)) ext_41e290(u32 n);   // GUESS allocator (stood in)

typedef u32(__attribute__((thiscall)) * thiscall0_fn)(void *);

// 0x5dc230 CImpactResponse::Command(cmd, arg).
static u32 THISCALL impactResponseCommand(u8 *self, u32 cmdArg, u32 arg) {
  if ((u16)cmdArg != *(u16 *)0x714388)
    return 0;
  u32 P = D(self, 0x44);
  u32 l1c = 0x6b6b74u;
  u32 val = 0;
  u8 *Q = *(u8 **)0x70038c;
  if (P != 0) {
    if (vcall<u32>(Q, 0x20, P) == 0) {
      u32 f8 = D(Q, 8);
      if (f8 != 0 && !(D(Q, 0xc) > P) && !(P >= D(Q, 0x10))) {
        val = ((thiscall0_fn)f8)((void *)P);
      } else {
        if (D((u8 *)P, -4) == 0)
          vcall<void>(Q, 0xac, P);
        val = D((u8 *)P, -4);
      }
    }
  }
  // Copy the name at this+0x4c into a fresh buffer (strdup through the allocator).
  u8 *S = (u8 *)D(self, 0x4c);
  u32 len = 0;
  while (S[len])
    ++len;
  u8 *B = (u8 *)ext_41e290(len + 1);
  for (u32 i = 0; i <= len; ++i)
    B[i] = S[i];
  Q = *(u8 **)0x70038c;
  u32 R1 = vcall<u32>(Q, 0xcc, D(arg, 8));
  u32 R2 = vcall<u32>((void *)R1, 0x350);
  if (R2 != 0) {
    if (vcall<u32>(Q, 0x20, R2) == 0) {
      u32 f8 = D(Q, 8);
      if (f8 != 0 && !(D(Q, 0xc) > R2) && !(R2 >= D(Q, 0x10))) {
        val = ((thiscall0_fn)f8)((void *)R2);
      } else {
        if (D((u8 *)R2, -4) == 0)
          vcall<void>(Q, 0xac, R2);
        val = D((u8 *)R2, -4);
      }
    } else {
      val = 0;
    }
  }
  (void)val;
  u8 *W = (u8 *)D(self, 0x48);
  if (W == 0)
    return 0;
  u32 l0c = 0;
  vcall<void>(W, 0x4c, (u32)&l0c);   // one stack argument; the exe's push of ebx is its save of ebx, kept on the stack for the exit pop
  u32 R = vcall<u32>(W, 0x5c, (u32)&l0c);
  while (l0c != 0) {
    u8 *rm = (u8 *)D(*(u8 **)0x70039c, 0x9b);
    u16 ax = (u16)vcall<u32>(rm, 0x114, 0x694c6cu, 0u, 0x6b6b3cu, 0x5du, (u32)&l1c);
    vcall<void>((void *)P, 0x12c, R, (u32)ax);
    R = vcall<u32>(W, 0x5c, (u32)&l0c);
  }
  return 0;
}
PCREG(5dc230, impactResponseCommand);
