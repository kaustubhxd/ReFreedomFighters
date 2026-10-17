// batch990.cpp - residue-11 (core todo), batch 990: ZFFActor::HolsterWeapon(int), 0x5a00b0, thiscall, ret 4 (SEH frame not reproduced).
// e = [this+0x78e] when hand != 0, else [this+0x78a]. e == 0: the debug channel (0x700390 vslot 0x20(0x6ae6a0, 0x371)) prints through a cdecl
// slot 0x2c(channel, 0x6ae9ac, [res]) where res = vslot 0x1d8(&a, 1) on this (0x4cc1d0 is mov eax,[ecx]; ret), then a is destroyed (0x4cbec0).
// Then: vslot 0x6b4(e) (flag); when set: vslot 0x4b4(0, 0, 0, 0, -1) on this (the exe pushes a dummy zero and a 16-byte block {0,0,0,-1})
// and vslot 0x6d4(e) on this.
#include "ff.h"

extern "C" void THISCALL ext_4cbec0(void *local);   // local destructor (exe; free stood in)

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x5a00b0 ZFFActor::HolsterWeapon(int).
static void THISCALL holsterWeapon(u8 *t, u32 hand) {
  u32 e = hand != 0 ? D(t, 0x78e) : D(t, 0x78a);
  if (e == 0) {
    u8 *ch = (u8 *)vcall<u32>(*(void **)0x700390, 0x20, 0x6ae6a0u, 0x371u);
    u32 a[0x40];
    u8 *res = (u8 *)vcall<u32>(t, 0x1d8, (u32)a, 1u);
    u32 p = D(res, 0);
    u32 fn = *(u32 *)(*(u32 *)ch + 0x2c);
    ((u32(*)(void *, u32, u32))fn)(ch, 0x6ae9acu, p);
    ext_4cbec0(a);
  }
  u32 r = vcall<u32>(t, 0x6b4, e);
  if ((u8)r) {
    vcall<void>(t, 0x4b4, 0u, 0u, 0u, 0u, 0xffffffffu);
    vcall<void>(t, 0x6d4, e);
  }
}
PCREG(5a00b0, holsterWeapon);
