// batch810.cpp - core gameplay batch 810 (docs/20-unclaimed-65.md, batch 810): 0x5c74a0, a stdcall with one argument (ret 4) that returns a
// bool in al. The argument is read from [ebp+8] (ecx is not used). Its virtual calls are all through the object at +8 of the argument,
// the render sub-object at [0x70039c]+0x9b, and the objects that slot 0x58 returns. The local at ebp-0xc is passed by address to slots
// 0x4c and 0x5c and tested after each call.
#include "ff.h"

typedef u32(THISCALL *F0)(u8 *self);
typedef u32(THISCALL *F1)(u8 *self, u32 a);

static u32 vc0(u8 *o, u32 s) { return ((F0)(*(const u32 *)(*(const u32 *)o + s)))(o); }
static u32 vc1(u8 *o, u32 s, u32 a) { return ((F1)(*(const u32 *)(*(const u32 *)o + s)))(o, a); }

static u8 STDCALL fn5c74a0(u8 *s) {
  if (s == 0) return 0;
  if (vc0(*(u8 **)(s + 8), 0x14) == 0) return 1;
  if (*(u8 **)(s + 8) == 0) return 0;

  u32 L = 0;
  vc1(*(u8 **)(s + 8), 0x4c, (u32)&L);
  u32 edi = vc1(*(u8 **)(s + 8), 0x5c, (u32)&L);
  if (L == 0) return 0;

  for (;;) {
    u8 *x = (u8 *)vc1(*(u8 **)(G(u8 *, 0x70039c) + 0x9b), 0x58, edi);
    const u32 al1 = vc1(x, 0x1e0, 0x2007f9) & 0xff;
    if (al1 != 0) {
      u8 *y = (u8 *)vc1(*(u8 **)(G(u8 *, 0x70039c) + 0x9b), 0x58, edi);
      if ((vc0(y, 0x438) & 0xff) == 0) return 1;
    }
    edi = vc1(*(u8 **)(s + 8), 0x5c, (u32)&L);
    if (L == 0) break;
  }
  return 0;
}

PCREG(5c74a0, fn5c74a0);
