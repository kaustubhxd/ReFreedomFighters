// batch4122.cpp - unclaimed-41 batch 22 (slice 13): 0x4ac9d0 (GUESS FUN_4ac9d0; 123 instructions). Thiscall (ecx = T), one stack
// argument X (ret 4), returns eax. The /GS cookie check is not reproduced.
#include "ff.h"

extern "C" void THISCALL ext_4ad770(u8 *self, u32 a1);   // one stack argument, callee pops (checksum stub, GUESS)

typedef u32(THISCALL * f0_t)(u8 *);
typedef u32(THISCALL * f1_t)(u8 *, u32);
typedef u32(THISCALL * f2_t)(u8 *, u32, u32);
typedef u32(THISCALL * f3_t)(u8 *, u32, u32, u32);

// vtable slot at vt + off, where vt = *(o)
static u32 vslot(u8 *o, u32 off) {
  return *(u32 *)(*(u8 **)o + off);
}

// 0x4ac9d0: T = ecx, X = arg1 (0x8(%ebp)). m8 is the local -0x8.
static u32 THISCALL fn4ac9d0(u8 *T, u8 *X) {
  u32 m8 = ((f1_t)vslot(X, 0x100))(X, 0x689770u);
  if (m8 == 0) {
    m8 = ((f2_t)vslot(X, 0x10c))(X, 0x690994u, 0u);   // pushes ebx (zero here) and then the constant
    if (m8 == 0)
      return 0;
    ((f3_t)vslot((u8 *)m8, 0x5c))((u8 *)m8, 1u, 0u, 0u);
  }

  u8 *M = T + 0x11a;   // a sub-object of T; its vtable is the dword at M
  if (((f0_t)vslot(M, 0x14))(M) == 0)
    return m8;

  for (;;) {
    u32 L14;   // local -0x14; the slot at +0x4c or +0x44 writes it before it is read
    ((f1_t)vslot(M, 0x4c))(M, (u32)&L14);
    u32 edi = ((f1_t)vslot(M, 0x5c))(M, (u32)&L14);
    if (L14 != 0) {
      for (;;) {
        u8 *o = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
        u8 *c = (u8 *)((f1_t)vslot(o, 0x58))(o, edi);   // the call's result (eax) is the next object, ecx = c
        u32 bo = (c != 0) ? ((f1_t)vslot(c, 0x1e0))(c, 0x1007d1u) : 0u;
        if (c != 0 && (bo & 0xff) != 0)
          break;
        ((f1_t)vslot(M, 0x44))(M, (u32)&L14);
        edi = ((f1_t)vslot(M, 0x5c))(M, (u32)&L14);
        if (L14 == 0)
          break;
      }
    }

    if (edi != 0) {
      ext_4ad770(T, edi);
      u8 *o2 = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
      edi = ((f1_t)vslot(o2, 0x58))(o2, edi);
      u8 *o3 = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
      u8 *ebxv = *(u8 **)(u8 *)edi;   // ebx = edi's vtable, read before the call below
      u32 s = ((f3_t)vslot(o3, 0x4c))(o3, (u32)X, 0u, 1u);
      u32 fn2f0 = *(u32 *)(ebxv + 0x2f0);
      ((f1_t)fn2f0)((u8 *)edi, s);
    }

    if (((f0_t)vslot(M, 0x14))(M) == 0)
      break;
  }
  return m8;
}
PCREG(4ac9d0, fn4ac9d0);
