// batch8080.cpp - residue 6 batch 80 (GUESS name): FUN_005f2d60.
#include "ff.h"

extern "C" void __attribute__((cdecl)) ext_634d22(void *dst, const void *src, u32 n);
extern "C" void THISCALL ext_5f2c60(u8 *self, u32 a, u32 b);

// 0x5f2d60 (GUESS FUN_005f2d60): thiscall, ret 8, returns this. n = b - a, cap = [this+4] - [this] (unsigned).
static u8 *THISCALL guess5f2d60(u8 *self, u32 a, u32 b) {
  u32 n = b - a;
  u32 cap = *(u32 *)(self + 4) - *(u32 *)self;
  if (n <= cap) {
    ext_634d22((void *)*(u32 *)self, (const void *)a, n);
    u32 edi = *(u32 *)self + n;
    u32 ebx = *(u32 *)(self + 4);
    if (edi != ebx) {
      typedef void *(__attribute__((cdecl)) * memmove_t)(void *, const void *, u32);
      memmove_t mm = (memmove_t)*(u32 *)0x676278;
      mm((void *)edi, (const void *)ebx, 1u);
      *(u32 *)(self + 4) += edi - ebx;
    }
  } else {
    ext_634d22((void *)*(u32 *)self, (const void *)a, cap);
    u32 end = *(u32 *)(self + 4) - *(u32 *)self + a;
    ext_5f2c60(self, end, b);
  }
  return self;
}
PCREG(5f2d60, guess5f2d60);
