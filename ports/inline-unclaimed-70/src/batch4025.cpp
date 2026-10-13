// batch4025.cpp - area 70 (slice 4/5), batch 4025: 0x4d2c90 (name GUESS). Calls slot 0xb0 of this with (a1, a2). If the
// result p is null it returns 0; otherwise n = [p+8] bytes are copied from p + [p] + 0xc to dst with memmove (IAT thunk
// 0x634d22, cdecl, three arguments; stubbed by address in the spec), and it returns n.
#include "ff.h"

extern "C" void *ext_634d22(void *dst, const void *src, u32 n);   // exe: thunk to memmove (cdecl), stubbed by address

// 0x4d2c90 (name GUESS): thiscall (ECX = this), three stack arguments (dst at [ebp+8], a1 at [ebp+0xc], a2 at [ebp+0x10]),
// ret 0xc.
static u32 THISCALL copyFromSlotB0(u8 *self, u8 *dst, u32 a1, u32 a2) {
  u8 *p = (u8 *)vcall<void *>(self, 0xb0, a1, a2);
  if (p == 0) return 0;
  u32 n = *(u32 *)(p + 8);
  u8 *src = p + *(u32 *)p + 0xc;
  ext_634d22(dst, src, n);
  return n;
}
PCREG(4d2c90, copyFromSlotB0);
