// batch1033.cpp - area 81, batch 1033: 0x44ae20, thiscall(this; a1 as one stack argument), ret 4, returns a float in st0. Cookie check not present. The
// table comes from the render manager's helper object (sys+0x1aa3 -> +0x18): slot 0x100 gives a pointer whose dword is the count, slot 0xfc gives the base,
// elements are 0x24 bytes. The argument is compared with each element address; the result is index / (count - 1). If the count is zero or the argument is
// not found, the debug channel gets a message (slot 0x20 then cdecl slot 0x2c) and the result is 0.0. No stand-ins besides the object slots.
#include "ff.h"

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

typedef void(__attribute__((cdecl)) * print_fn)(u32, u32);

// 0x44ae20 (thiscall: this; a1).
static float THISCALL indexFraction(u8 *self, u32 a1) {
  u8 *sys = *(u8 **)0x70039c;
  u8 *rm2 = (u8 *)D(sys, 0x1aa3);
  u8 *Mo = (u8 *)D(rm2, 0x18);
  u32 edx = D((u8 *)D(self, 8), 0x6c);
  u32 cnt = D((u8 *)vcall<u32>(Mo, 0x100, edx), 0);
  u32 edx2 = D((u8 *)D(self, 8), 0x6c);
  u8 *base = (u8 *)vcall<u32>(Mo, 0xfc, edx2);
  u32 idx = 0;
  u8 *p = base;
  bool found = false;
  if (cnt != 0) {
    for (;;) {
      if (a1 == (u32)(u64)p) {
        found = true;
        break;
      }
      ++idx;
      p += 0x24;
      if (idx == cnt)
        break;
    }
  }
  if (found) {
    float num = (float)(int)idx;
    float den = (float)(int)(cnt - 1);
    return num / den;
  }
  u8 *chan = (u8 *)vcall<u32>((void *)*(u32 *)0x700390, 0x20, 0x67fa88u, 0x8au);
  print_fn fn = (print_fn)D(*(u8 **)chan, 0x2c);
  fn((u32)chan, 0x67fab0u);
  return 0.0f;
}
PCREG(44ae20, indexFraction);
