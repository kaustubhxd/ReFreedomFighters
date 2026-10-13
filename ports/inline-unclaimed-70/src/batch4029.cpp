// batch4029.cpp - area 70 (slice 4/5), batch 4029: 0x562390 (name GUESS). Caches a value in [this+0xf8]: if it is zero,
// takes the index edi = 1 (or [[this+0x90]+0x684] when [this+0x90] is set), passes the string-table entry arr[edi-1] and an
// out-pointer to slot 0x88 of the object from render-manager slot 0x138, then stores slot 0x58 of the render manager (arg:
// the out value) into [this+0xf8]. The security cookie check (0x633654) is omitted: it has no effect when the cookie is intact.
#include "ff.h"

// 0x562390 (name GUESS): thiscall (ECX = this), no arguments, plain ret.
static void THISCALL cacheVal562390(u8 *self) {
  if (*(u32 *)(self + 0xf8) != 0) return;
  u32 edi = 1;
  u8 *m = *(u8 **)(self + 0x90);
  if (m) edi = *(u32 *)(m + 0x684);
  u32 arr[4] = {0x6a6700u, 0x6a6710u, 0x6a6720u, 0x6a6730u};
  u8 *sys = G(u8 *, 0x70039c);
  void *rm = *(void **)(sys + 0x9b);
  void *x = vcall<void *>(rm, 0x138);
  u32 v = 0;
  vcall<void>(x, 0x88, arr[edi - 1], &v);
  sys = G(u8 *, 0x70039c);
  rm = *(void **)(sys + 0x9b);
  *(u32 *)(self + 0xf8) = vcall<u32>(rm, 0x58, v);
}
PCREG(562390, cacheVal562390);
