// batch35006.cpp - cascade s5 batch 35006: 0x4d1790 (GUESS serialize a record into a buffer cursor).
#include "ff.h"

extern "C" void ext_634d22(void *dst, const void *src, u32 n);   // cdecl memcpy
extern "C" void ext_634d10(void *dst, u32 v, u32 n);             // cdecl memset
typedef void(THISCALL *v1_t)(void *, void *);

// 0x4d1790, thiscall(cur) ret 4; cur points at the write cursor. Copies [this+0xc] (size [this+8]) to the cursor and advances it; every child in the list at
// +0x24 (next at +0x30) is asked to write itself (slot 0xc(cur)); then every item of the list at +0x18 (next at +8, data +0xc, size +0x10) is copied the same way;
// the cursor is padded with zero bytes to a multiple of 4 of the summed item sizes.
static void THISCALL fn4d1790(u8 *self, u32 *edi) {
  ext_634d22((void *)*edi, *(void **)(self + 0xc), *(u32 *)(self + 8));
  *edi += *(u32 *)(self + 8);
  for (u8 *c = *(u8 **)(self + 0x24); c; c = *(u8 **)(c + 0x30)) (*(v1_t **)c)[0xc / 4](c, edi);
  u32 total = 0;
  for (u8 *it = *(u8 **)(self + 0x18); it; it = *(u8 **)(it + 8)) {
    ext_634d22((void *)*edi, *(void **)(it + 0xc), *(u32 *)(it + 0x10));
    *edi += *(u32 *)(it + 0x10);
    total += *(u32 *)(it + 0x10);
  }
  u32 pad = ((total + 3) & 0xfffffffc) - total;
  if (pad) {
    ext_634d10((void *)*edi, 0, pad);
    *edi += pad;
  }
}
PCREG(4d1790, fn4d1790);
