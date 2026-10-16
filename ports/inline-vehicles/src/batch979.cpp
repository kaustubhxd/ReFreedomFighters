// batch979.cpp - residue-05 (core todo), batch 979: ZItemStateProjectile::GetUseGeom(ZItem*), 0x468b10, thiscall, ret 4.
// (SEH frame not reproduced.) 0x4cc1d0 is mov eax,[ecx]; ret (ECX = the slot 0x1d8 object), so the printed value is its first dword. First vslot 0x1e0(0x1007d2): if it is zero (path A): debug channel (0x700390 vslot 0x20(0x6887c4,
// 0x1078)), g1 = vslot 0x1d8(&A, 1), g2 = vslot 0x2e8(), then the channel's cdecl slot 0x30(ch, 0x688fa4, g2, g2+4 or default);
// the local A is destroyed (0x4cbec0). Otherwise h = vslot 0x328(): when h is zero (path B) the same with 0x1080, &B and 0x688fcc.
// When h is set (path C): r = h vslot 0x334(); if r is non-zero return r; else the channel's cdecl slot 0x30(ch, 0x688ff0,
// h+4 or default). Returns 0 unless r. The pass-through 0x4cc1d0 is a bare ret and is not called (its pushed argument stays on the
// stack in the exe; the four-argument cdecl print below takes it).
#include "ff.h"

extern "C" void THISCALL ext_4cbec0(void *local);   // local destructor (exe; frees through 0x634273, stood in)

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x468b10 ZItemStateProjectile::GetUseGeom(ZItem*): the item is the stack argument (ECX is not used by the exe).
static u32 THISCALL itemUseGeom(void *self, u8 *it) {
  (void)self;
  u32 A[0x40], B[0x40];
  if (!(u8)vcall<u32>(it, 0x1e0, 0x1007d2u)) {
    u8 *ch = (u8 *)vcall<u32>(*(void **)0x700390, 0x20, 0x6887c4u, 0x1078u);
    u8 *g1 = (u8 *)vcall<u32>(it, 0x1d8, (u32)A, 1u);
    u32 p1 = D(g1, 0);   // 0x4cc1d0 is mov eax,[ecx]; ret: EAX is the first dword of the object from slot 0x1d8
    u8 *g2 = (u8 *)vcall<u32>(it, 0x2e8);
    u32 v1 = D(g2, 4) != 0 ? D(g2, 4) : 0x67c8e8u;
    u32 fn = *(u32 *)(*(u32 *)ch + 0x30);
    ((u32(*)(void *, u32, u32, u32))fn)(ch, 0x688fa4u, p1, v1);
    ext_4cbec0(A);
    return 0;
  }
  u8 *h = (u8 *)vcall<u32>(it, 0x328);
  if (!h) {
    u8 *ch = (u8 *)vcall<u32>(*(void **)0x700390, 0x20, 0x6887c4u, 0x1080u);
    u8 *g1 = (u8 *)vcall<u32>(it, 0x1d8, (u32)B, 1u);
    u32 p2 = D(g1, 0);
    u8 *g2 = (u8 *)vcall<u32>(it, 0x2e8);
    u32 v2 = D(g2, 4) != 0 ? D(g2, 4) : 0x67c8e8u;
    u32 fn = *(u32 *)(*(u32 *)ch + 0x30);
    ((u32(*)(void *, u32, u32, u32))fn)(ch, 0x688fccu, p2, v2);
    ext_4cbec0(B);
    return 0;
  }
  u32 r = vcall<u32>(h, 0x334);
  if (r)
    return r;
  u8 *ch = (u8 *)vcall<u32>(*(void **)0x700390, 0x20, 0x6887c4u, 0x1087u);
  u32 v3 = D(h, 4) != 0 ? D(h, 4) : 0x67c8e8u;
  u32 fn = *(u32 *)(*(u32 *)ch + 0x30);
  ((u32(*)(void *, u32, u32))fn)(ch, 0x688ff0u, v3);
  return 0;
}
PCREG(468b10, itemUseGeom);
