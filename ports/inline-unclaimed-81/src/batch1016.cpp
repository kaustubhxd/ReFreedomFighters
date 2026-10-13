// batch1016.cpp - area 81, batch 1016: CInventory::GetItemFromItemTemplate(t, flag), 0x4ac640, thiscall, two stack arguments, ret 8. SEH frame and cookie
// check not reproduced. Stand-ins (GUESS): 0x4cc1d0 (thiscall, returns a value), 0x4cbec0 (thiscall on a local object), the global cdecl name compare at
// 0x676414 (two arguments: name2, name1; zero means equal). The inline object at this+0x11a is walked with slots 0x4c, 0x5c and 0x44. Print paths
// (render manager slot 0x58 returns null, or the element's slot 0x2e8 returns null) call the channel's slot 0x2c (cdecl: channel, format, value).
#include "ff.h"

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

extern "C" u32 THISCALL ext_4cc1d0(void *self);    // GUESS (stood in)
extern "C" void THISCALL ext_4cbec0(void *self);   // GUESS (stood in)

typedef void(__attribute__((cdecl)) * print_fn)(u32, u32, u32);

// 0x4ac640 CInventory::GetItemFromItemTemplate(t, flag).
static u32 THISCALL inventoryGetItemFromTemplate(u8 *self, u32 tArg, u32 flagArg) {
  u8 *T = (u8 *)tArg;
  u8 *inner = self + 0x11a;
  u32 l11c = 0;
  vcall<void>(inner, 0x4c, (u32)&l11c);
  u8 *E = (u8 *)vcall<u32>(inner, 0x5c, (u32)&l11c);
  if (l11c == 0)
    return 0;
  for (;;) {
    u32 R = vcall<u32>((void *)D(*(u8 **)0x70039c, 0x9b), 0x58, (u32)E);
    if (!R) {
      u8 *chan = (u8 *)vcall<u32>((void *)*(u32 *)0x700390, 0x20, 0x6909a4u, 0x214u);
      u8 l90[8] = {0, 0, 0, 0, 0, 0, 0, 0};
      u8 *M = (u8 *)D(self, 0x44);
      u32 Q = vcall<u32>(M, 0x1d8, (u32)l90, 1u);
      u32 V = ext_4cc1d0((void *)Q);
      print_fn fn = (print_fn)D(*(u8 **)chan, 0x2c);
      fn((u32)chan, 0x690b00u, V);
      ext_4cbec0(l90);
      vcall<void>(inner, 0x44, (u32)&l11c);
    } else {
      u32 X = vcall<u32>((void *)R, 0x2e8);
      if (!X) {
        u8 *chan = (u8 *)vcall<u32>((void *)*(u32 *)0x700390, 0x20, 0x6909a4u, 0x21bu);
        u8 l110[8] = {0, 0, 0, 0, 0, 0, 0, 0};
        u32 Q2 = vcall<u32>((void *)R, 0x1d8, (u32)l110, 1u);
        u32 V2 = ext_4cc1d0((void *)Q2);
        print_fn fn = (print_fn)D(*(u8 **)chan, 0x2c);
        fn((u32)chan, 0x690b48u, V2);
        ext_4cbec0(l110);
        vcall<void>(inner, 0x44, (u32)&l11c);
      } else {
        if (X == (u32)T)
          return (u32)E;
        if ((u8)flagArg) {
          u32 n1 = D(T, 4) ? D(T, 4) : 0x67c8e8u;
          u32 n2 = D(X, 4) ? D(X, 4) : 0x67c8e8u;
          u32 cmp = ((u32(*)(u32, u32))(*(u32 *)0x676414))(n2, n1);
          if (cmp == 0)
            return (u32)E;
        }
      }
    }
    E = (u8 *)vcall<u32>(inner, 0x5c, (u32)&l11c);
    if (l11c == 0)
      break;
  }
  return 0;
}
PCREG(4ac640, inventoryGetItemFromTemplate);
