// batch67562.cpp - cascade s6 batch 67562: 0x52d080.
#include "ff.h"

extern "C" void ext_634273(u8 *p, u32 n);   // free, cdecl

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x52d080, thiscall() plain ret (eax unused): destructor. Sets the vtable pointer this[0] = 0x6a1414 and frees every owned block that is set: +0x54 (0x16), +0x5a (0xc), +0x60 (4), +0x66 (0xa),
// +0x6c (4), +0x72 (4), +0x78 (0xa), +0x82 (1), +0x98 (0x15), +0x88 (0xc), +0x8c (4), +0x90 (0x18), +0x7c (1) with 0x634273(ptr, class).
static void THISCALL fn52d080(u8 *self) {
  D32(self, 0) = 0x6a1414u;
  static const u32 tab[][2] = {{0x54, 0x16}, {0x5a, 0xc}, {0x60, 4}, {0x66, 0xa}, {0x6c, 4}, {0x72, 4}, {0x78, 0xa},
                               {0x82, 1}, {0x98, 0x15}, {0x88, 0xc}, {0x8c, 4}, {0x90, 0x18}, {0x7c, 1}};
  for (const auto &e : tab) {
    u32 p = D32(self, e[0]);
    if (p) ext_634273((u8 *)p, e[1]);
  }
}
PCREG(52d080, fn52d080);
