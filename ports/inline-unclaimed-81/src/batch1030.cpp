// batch1030.cpp - area 81, batch 1030: 0x5121e0, thiscall (this), no arguments, plain ret. Cookie check not reproduced (no SEH frame). Stand-ins (GUESS):
// 0x4e7930 (thiscall on this+0x144 with four stack arguments; returns a float in st0), 0x4de420 and 0x4de480 and 0x441940 (fastcall; vector copies in
// the harness), the print through the debug channel's slot 0x2c (cdecl, two arguments). this's slot 0x130 (three arguments) is a counting stub.
#include "ff.h"

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

extern "C" float THISCALL ext_4e7930(void *self, u32 tick, u32 p58, u32 p10, float m1);  // GUESS (stood in; float in st0)
extern "C" void __attribute__((fastcall)) ext_4de420(void *ecx, void *edx);              // GUESS (stood in)
extern "C" void __attribute__((fastcall)) ext_4de480(void *ecx, void *edx);              // GUESS (stood in)
extern "C" void __attribute__((fastcall)) ext_441940(void *ecx, void *edx);              // GUESS (stood in)

typedef void(__attribute__((cdecl)) * print_fn)(u32, u32);

// 0x5121e0 (thiscall, this in ecx).
static void THISCALL vecUpdateAndPrint(u8 *self) {
  if (D(self, 0x159) == 0)
    return;
  float V10[3], V34[3], V58[3];
  u8 *sys = *(u8 **)0x70039c;
  u32 tick = D(sys, 0x40);
  float F = ext_4e7930(self + 0x144, tick, (u32)V58, (u32)V10, -1.0f);
  ext_4de420(V34, self + 0x169);
  ext_4de480(V34, V58);
  ext_441940(V10, self + 0x15d);
  vcall<void>((void *)D(self, 0x159), 0x74, (u32)V34, (u32)V10);
  if (0.0f > F) {
    u32 w = (u32)*(u16 *)(self + 0x20d);
    D(self, 0x159) = 0;
    vcall<void>(self, 0x130, (u32)self, w, 0u);
    u8 *chan = (u8 *)vcall<u32>((void *)*(u32 *)0x700390, 0x20, 0x69e4bcu, 0x35au);
    print_fn fn = (print_fn)D(*(u8 **)chan, 0x2c);
    fn((u32)chan, 0x69e624u);
  }
}
PCREG(5121e0, vecUpdateAndPrint);
