// batch866.cpp - area 50 (residue-9 candidate): 0x42b390 [72 instr, thiscall, two stack args (ret 8); no name in the map
// (GUESS "string assign from a C string: fill (begin, end, capacity), copy with memmove, terminate")]. The C string's length
// n is counted; the block for n+1 bytes comes from 0x6014a0 (stood in; not called when n+1 is not below 0xffffffff, or 0);
// begin/end/capacity are set, the old begin is the destination of memmove(dst, src, n), and a NUL is written at the end.
// The exe's SEH frame (fs:[0]) is not reproduced (fs:[0] writes not compared).
#include "ff.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))

extern "C" void *THISCALL ext_6014a0(void *self, u32 size);   // block allocator (stood in by the harness)

// 0x42b390 (name GUESS).
static void THISCALL Fn42b390(u8 *self, const char *s, u32 unused) {
  (void)unused;
  U32(self, 0) = 0;
  U32(self, 4) = 0;
  U32(self, 8) = 0;
  u32 n = 0;
  while (s[n] != 0) n++;
  u8 *end = (u8 *)s + n;
  u32 esi = n + 1;
  u8 *dst;
  if (esi <= 0xfffffffeu) {
    if (esi == 0) {
      dst = 0;
    } else {
      dst = (u8 *)ext_6014a0(self, esi);
    }
    U32(self, 0) = (u32)dst;
    U32(self, 4) = (u32)dst;
    U32(self, 8) = (u32)(dst + esi);
  }
  dst = (u8 *)U32(self, 0);
  typedef void *(*memmove_t)(void *, const void *, u32);
  (*(memmove_t *)0x676278)(dst, s, n);
  U32(self, 4) = (u32)(end + (dst - (u8 *)s));
  *(u8 *)U32(self, 4) = 0;
}
PCREG(42b390, Fn42b390);
