// batch941.cpp - two label-D rows from the area-50 claim (2026-10-12), both read in full.
//  0x573d40 (no name in the map): thiscall (ECX = this), no args, plain ret. If the signed count at this+0x1fe is above 0, for each entry i
//    (the object pointer at this+0x190 + 4*i): slot +0xbc with 1, then slot +0x284 with 0x677b5a. Then this+0x202 = 0.
//  0x547760 (no name in the map): thiscall (ECX = this), two args (index a, source pointer src), ret 8. The destination is
//    this+0xf (a dword base) + 0x34*a + 0xc. It copies three dwords from src to the destination. The exe also calls 0x43e920 (a vector
//    subtract, src - dst, into a local that is never read); that dead result is not reproduced.
#include "ff.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x573d40 (no name in the map).
static void THISCALL Loop573d40(u8 *self) {
  s32 n = (s32)U32(self, 0x1fe);
  for (s32 i = 0; i < n; i++) {
    void *obj = *(void **)(self + 0x190 + 4 * i);
    vcall<void>(obj, 0xbc, 1u);
    vcall<void>(obj, 0x284, 0x677b5au);
  }
  U32(self, 0x202) = 0;
}
PCREG(573d40, Loop573d40);

// 0x547760 (no name in the map).
static void THISCALL Copy547760(u8 *self, u32 a, u32 *src) {
  u32 *dst = (u32 *)(U32(self, 0xf) + 0x34 * a + 0xc);
  dst[0] = src[0];
  dst[1] = src[1];
  dst[2] = src[2];
}
PCREG(547760, Copy547760);
