// u69_60.cpp - area 69, group 60 (slice 8). Computes a value from the dword at self+0x20 (a multiply-high and divide-style reduction) and passes it to the cdecl helper 0x41e290 (other area, GUESS stub in the spec).
#include "ff.h"

extern "C" u32 ext_41e290(u32 n);  // cdecl, one arg (the caller pops it)

// 0x498700, thiscall no args (ret). orig = dword at +0x20; hi = high dword of 0x24924925 * orig; stores orig at +0x28; sets +0x24 = 1;
// t = ((orig - hi) >> 1 + hi) >> 6; m = (dword at +0x61 - t) * 4 (64-bit); the argument is the low dword of m, or'ed with -1 when m overflows 32 bits;
// stores the helper's result at +0x5d.
static void THISCALL refresh498700(u8 *self) {
  u32 orig = *(u32 *)(self + 0x20);
  u32 hi = (u32)(((u64)0x24924925u * orig) >> 32);
  *(u32 *)(self + 0x28) = orig;
  u32 t = ((orig - hi) >> 1) + hi;
  *(u32 *)(self + 0x24) = 1;
  t >>= 6;
  u32 eax = *(u32 *)(self + 0x61) - t;
  u64 m = (u64)eax * 4;
  u32 ovf = (m >> 32) != 0 ? 0xffffffffu : 0u;
  *(u32 *)(self + 0x5d) = ext_41e290(ovf | (u32)m);
}
PCREG(498700, refresh498700);
