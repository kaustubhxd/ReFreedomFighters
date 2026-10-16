// batch972.cpp - residue-04 (core todo), batch 972: ZActorIf::SetHoldWeaponUBAnim(OpaqueCallParameters_t&), 0x508100, thiscall, ret 4.
// n = *(int *)0x5003d0(p->[4], 0) (helper, thiscall, stood in). When n > 0 the exe tail-jumps: [this+0x18] vslot 0x69c with
// (render manager +0x44 + n) and returns its EAX. Otherwise it prints through the debug object (0x700390, vslot 0x20(0x69cff0,
// 0xfe) gives the channel), with the value of [this+0x18] vslot 0x20() +4 (or 0x67c8e8 when zero) into the channel's vslot 0x2c,
// a cdecl call with three stack arguments (channel, 0x69d078, value; the caller cleans up), and returns its EAX.
#include "ff.h"

extern "C" u32 THISCALL ext_5003d0(void *self, u32 a);   // stood in by the checker

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x508100 ZActorIf::SetHoldWeaponUBAnim(OpaqueCallParameters_t&).
static u32 THISCALL setHoldWeaponUBAnim(u8 *t, u8 *p) {
  int n = *(int *)ext_5003d0((void *)D(p, 4), 0);
  u8 *e = (u8 *)D(t, 0x18);
  if (n > 0) {
    u8 *rm = *(u8 **)(*(u8 **)0x70039c + 0x9b);
    u32 nv = D(rm, 0x44) + (u32)n;
    return vcall<u32>(e, 0x69c, nv);
  }
  u8 *ch = (u8 *)vcall<u32>(*(void **)0x700390, 0x20, 0x69cff0u, 0xfeu);
  u8 *x = (u8 *)vcall<u32>(e, 0x20);
  u32 v = D(x, 4) != 0 ? D(x, 4) : 0x67c8e8u;
  u32 fn = *(u32 *)(*(u32 *)ch + 0x2c);
  return ((u32(*)(void *, u32, u32))fn)(ch, 0x69d078u, v);
}
PCREG(508100, setHoldWeaponUBAnim);
