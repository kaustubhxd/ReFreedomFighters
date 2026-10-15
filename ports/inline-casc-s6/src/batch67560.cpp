// batch67560.cpp - cascade s6 batch 67560: 0x5c21e0.
#include "ff.h"

extern "C" void THISCALL ext_5c2120(u8 *self, u32 mode);   // ret 4
extern "C" void STDCALL ext_610100(u32 flag);              // ret 4

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define SYS (*(u8 **)0x70039c)
typedef u32 (THISCALL *tab6_t)(u8 *, u32, u32, u32, u32, u32, u32);

// 0x5c21e0, thiscall(mode) ret 4, return value unused: switches the current mode this[0x48] (previous kept in +0x4c). With the direct flag (+0x111) 0x5c2120 does the switch, otherwise the old and new
// mode objects (this[0x10d] slot 0x25c on the entry at [+0xe4][mode - [+0xe8]]) are hidden / shown (slot 0xbc(1) / 0xbc(0)) and the new one is given a word from the table's slot 0x114 via its slot
// 0x128. With +0x50 set the colour +0x6c is set (white for mode 7, blue (0x3333ff) when mode matches 3 / 0 depending on sys[0x1b5d], else red) with 0x610100(1 / 0), and if the config byte at
// [[0x7003b8]+0x2c15]+0x103f is set +0x88 becomes 9 (10 for mode 7).
static void THISCALL fn5c21e0(u8 *self, u32 mode) {
  if (D32(self, 0x111)) {
    ext_5c2120(self, mode);
  } else {
    u8 *a = *(u8 **)(self + 0x10d);
    u32 idx = D32(self, 0x48) - D32(self, 0xe8);
    u8 *o1 = vcall<u8 *>(a, 0x25c, D32(*(u8 **)(self + 0xe4), idx * 4), 0u);
    if (o1) vcall<void>(o1, 0xbc, 1u);
    a = *(u8 **)(self + 0x10d);
    u32 idx2 = mode - D32(self, 0xe8);
    u8 *o2 = vcall<u8 *>(a, 0x25c, D32(*(u8 **)(self + 0xe4), idx2 * 4), 0u);
    if (o2) {
      vcall<void>(o2, 0xbc, 0u);
      u8 *tab = *(u8 **)(SYS + 0x9b);
      u32 r = (*(tab6_t *)(*(u8 **)tab + 0x114))(tab, 0x682e18u, 0, 0x6b3a74u, 0x1e6u, 0, 0);
      vcall<void>(o2, 0x128, r & 0xffff);
    }
  }
  u32 prev = D32(self, 0x48);
  u32 f = D32(self, 0x50);
  D32(self, 0x4c) = prev;
  D32(self, 0x48) = mode;
  if (f) {
    u32 edx = D32(SYS, 0x1b5d);
    if (mode == 7) {
      D32(self, 0x6c) = 0xffffff;
    } else {
      u32 want = edx == 1 ? 3 : 0;
      if (mode == want) {
        ext_610100(1);
        D32(self, 0x6c) = 0x3333ff;
      } else {
        ext_610100(0);
        D32(self, 0x6c) = 0xff3333;
      }
    }
    u8 *cfg = *(u8 **)(*(u8 **)0x7003b8 + 0x2c15);
    if (cfg[0x103f]) D32(self, 0x88) = (mode == 7) + 9;
  }
}
PCREG(5c21e0, fn5c21e0);
