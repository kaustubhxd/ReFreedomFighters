// batch37027.cpp - cascade s6 batch 37027: 0x55f6b0.
#include "ff.h"

extern "C" void THISCALL ext_505a00(u8 *self, u8 *a);   // ret 4
typedef void(THISCALL *s1_t)(void *, u32);
typedef u32 (*hook_t)();
#define CNT G(u32, 0x7140c8)

static const u32 FNS[6] = {0x55f5e0, 0x55f6a0, 0x55ef10, 0x55ee30, 0x55f670, 0x55f640};

// 0x55f6b0, thiscall(a) ret 4: pushes the six callbacks of FNS (in this order) on the global stack at 0x7140d0
// (count at 0x7140c8, capacity 0x32) as long as a+0xc is still set; a full stack reports through slot 0x44 of this (string 0x6a5ea4) and the assert hook. Always ends by
// clearing a+0xc and running 0x505a00.
static void THISCALL fn55f6b0(u8 *self, u8 *a) {
  u32 cnt = CNT;
  for (int k = 0; k < 6; k++) {
    if (!a[0xc]) break;
    if (cnt < 0x32) {
      G(u32, 0x7140d0 + 4 * cnt) = FNS[k];
      cnt++;
      CNT = cnt;
    } else {
      (*(s1_t **)self)[0x44 / 4](self, 0x6a5ea4);
      hook_t h = G(hook_t, 0x7003b0);
      if (!h) __asm__ volatile("int3");
      h();
      cnt = CNT;
    }
  }
  a[0xc] = 0;
  ext_505a00(self, a);
}
PCREG(55f6b0, fn55f6b0);
