// batch813.cpp - standing assignment, residue 19 (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

extern "C" u32 __attribute__((cdecl)) ext_634273(u32 a, u32 b);   // hooked (GUESS)
extern "C" u32 THISCALL ext_4e5e60(u8 *self);   // hooked; no stack words, ecx = self (GUESS)
typedef u8 *(THISCALL *VOneRet)(u8 *, u32);   // vt[0xc]: thiscall one word, returns a pointer
typedef void(THISCALL *VOneVoid)(u8 *, u32);  // vt slot with one word, no return used
typedef u32(__attribute__((stdcall)) *Fn1)(u32);  // vt[0x8c]: one word, callee cleans (ret 4)

// 0x5eaaf0, thiscall() with no return value: passes each of the first [this+0x48] words with 0x15 to 0x634273.
static void THISCALL callEach_5eaaf0(u8 *self) {
  u32 n = *(u32 *)(self + 0x48);
  for (u32 i = 0; i < n; i++) {
    ext_634273(*(u32 *)(self + 4 + 4 * i), 0x15u);
  }
}
PCREG(5eaaf0, callEach_5eaaf0);

// 0x57a1b0, thiscall(a) ret 4: three calls to 0x4e5e60 with ecx = a; results stored at this+0x48, +0x4c, +0x50.
static void THISCALL threeVals_57a1b0(u8 *self, u32 a) {
  *(u32 *)(self + 0x48) = ext_4e5e60((u8 *)a);
  *(u32 *)(self + 0x4c) = ext_4e5e60((u8 *)a);
  *(u32 *)(self + 0x50) = ext_4e5e60((u8 *)a);
}
PCREG(57a1b0, threeVals_57a1b0);

// 0x60ce70, thiscall() returning 1: vt[0x2b0](this); r = vt[0x8c](object at this+0x1377); clears a global and a byte.
static u8 THISCALL resetAndCall_60ce70(u8 *self) {
  u32 vt = *(u32 *)self;
  typedef void(THISCALL *VNoArg)(u8 *);
  ((VNoArg)(*(u32 *)(vt + 0x2b0)))(self);
  u8 *obj = *(u8 **)(self + 0x1377);
  Fn1 g = (Fn1)(*(u32 *)(*(u32 *)obj + 0x8c));
  g((u32)obj);
  *(volatile u32 *)0x724a00u = 0u;
  *(u8 *)(self + 0x13ec) = 0;
  return 1;
}
PCREG(60ce70, resetAndCall_60ce70);

// 0x657970, thiscall(a, b) ret 8: r = vt[0xc](this, a); r2 = vt[0xc](this, [r+0x3c]); word [r] = b; word [r2+0xe] = 3*b.
static void THISCALL twoVtStore_657970(u8 *self, u32 a, u32 b) {
  VOneRet f = (VOneRet)(*(u32 *)(*(u32 *)self + 0xc));
  u8 *r = f(self, a);
  VOneRet g = (VOneRet)(*(u32 *)(*(u32 *)self + 0xc));
  u8 *r2 = g(self, *(u32 *)(r + 0x3c));
  *(u16 *)r = (u16)b;
  *(u16 *)(r2 + 0xe) = (u16)(b * 3u);
}
PCREG(657970, twoVtStore_657970);
