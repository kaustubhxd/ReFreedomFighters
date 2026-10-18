// batch980.cpp - residue-05 (core todo), batch 980: ZItemContainer::InsertItem(unsigned int), 0x46f2d0, thiscall, ret 4, void.
// (SEH frame not reproduced.) X = render manager vslot 0x58(id); Y = this vslot 0x2e8(); when Y vslot 0x31c(X) is zero (path F):
// channel = dbg vslot 0x20(0x6887c4, 0xf30); Ga = this vslot 0x1d8(&ga, 1); Gb = X vslot 0x1d8(&gb, 1); the channel's cdecl
// slot 0x2c(channel, 0x688e34, [Gb], [Ga]) (0x4cc1d0 is mov eax,[ecx]; ret, so [Gb] and [Ga] are the first dwords); the
// two locals are destroyed. Otherwise (path T): R = rm vslot 0x4c(this, this, 1); X vslot 0x2f0(R); X vslot 0x300(1); channel
// (0xf37) cdecl slot 0x2c(channel, 0x688e64, [X+4] or default, [this+4] or default); Y2 = this vslot 0x2e8(); Z = Y2 vslot
// 0x25c(0x688e88, 0); when Z is set 0x4db2c0 (stood in) with ECX = Z+8 fills L1c, else the vector init 0x4de7a0 fills L40 and L1c
// is zeroed; X vslot 0x2d4(L40, L1c); [this+0x94] vslot 4(id); channel2 (0xf49) cdecl slot 0x2c(channel2, 0x688e9c, id).
#include "ff.h"

extern "C" void THISCALL ext_4cbec0(void *local);                   // local destructor (exe; free stood in)
extern "C" void THISCALL ext_4de7a0(void *self);                    // vector init (exe)
extern "C" void THISCALL ext_4db2c0(void *self, u32 a1, u32 a2);    // stood in by the checker

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x46f2d0 ZItemContainer::InsertItem(unsigned int).
static void THISCALL insertItem(u8 *t, u32 id) {
  u8 *rm = *(u8 **)(*(u8 **)0x70039c + 0x9b);
  u8 *x = (u8 *)vcall<u32>(rm, 0x58, id);
  u8 *y = (u8 *)vcall<u32>(t, 0x2e8);
  u32 al = vcall<u32>(y, 0x31c, (u32)x);
  u32 ga[0x30], gb[0x30];
  if (!(u8)al) {
    u8 *ch = (u8 *)vcall<u32>(*(void **)0x700390, 0x20, 0x6887c4u, 0xf30u);
    u8 *gao = (u8 *)vcall<u32>(t, 0x1d8, (u32)ga, 1u);
    u8 *gbo = (u8 *)vcall<u32>(x, 0x1d8, (u32)gb, 1u);
    u32 p1 = D(gao, 0);
    u32 p2 = D(gbo, 0);
    u32 fn = *(u32 *)(*(u32 *)ch + 0x2c);
    ((u32(*)(void *, u32, u32, u32))fn)(ch, 0x688e34u, p2, p1);
    ext_4cbec0(gb);
    ext_4cbec0(ga);
    return;
  }
  u8 *r = (u8 *)vcall<u32>(rm, 0x4c, (u32)t, (u32)t, 1u);
  vcall<void>(x, 0x2f0, (u32)r);
  vcall<void>(x, 0x300, 1u);
  u8 *ch = (u8 *)vcall<u32>(*(void **)0x700390, 0x20, 0x6887c4u, 0xf37u);
  u32 vthis = D(t, 4) != 0 ? D(t, 4) : 0x67c8e8u;
  u32 vx = D(x, 4) != 0 ? D(x, 4) : 0x67c8e8u;
  u32 fn = *(u32 *)(*(u32 *)ch + 0x2c);
  ((u32(*)(void *, u32, u32, u32))fn)(ch, 0x688e64u, vx, vthis);
  u8 *y2 = (u8 *)vcall<u32>(t, 0x2e8);
  u8 *z = (u8 *)vcall<u32>(y2, 0x25c, 0x688e88u, 0u);
  u32 l40[9];
  u32 l1c[3];
  if (z) {
    ext_4db2c0((void *)(z + 8), (u32)l40, (u32)l1c);
  } else {
    ext_4de7a0(l40);
    l1c[2] = 0;
    l1c[1] = 0;
    l1c[0] = 0;
  }
  vcall<void>(x, 0x2d4, (u32)l40, (u32)l1c);
  u8 *sub = (u8 *)D(t, 0x94);
  vcall<void>(sub, 4, id);
  u8 *ch2 = (u8 *)vcall<u32>(*(void **)0x700390, 0x20, 0x6887c4u, 0xf49u);
  u32 fn2 = *(u32 *)(*(u32 *)ch2 + 0x2c);
  ((u32(*)(void *, u32, u32))fn2)(ch2, 0x688e9cu, id);
}
PCREG(46f2d0, insertItem);
