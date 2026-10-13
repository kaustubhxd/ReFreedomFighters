// batch1136.cpp - collision thread, batch 1136 (gap-list row, name GUESS): 0x4ae2b0, an insertion step into a sorted array of
// 0x35-byte records. Records before the insertion point whose first float is greater than the key's first float move up one
// slot (0x35 bytes each); then the key record is stored: 16 bytes k, 16 bytes v2, 16 bytes v3, a dword i4 and a byte b1.
// Thiscall (ECX = insertion point); 56 bytes of stack arguments; ret 0x38.
#include "ff.h"

struct V16 {
  u32 w[4];
};

static void THISCALL insert4ae2b0(u8 *p, V16 k, V16 v2, V16 v3, u32 i4, u32 b1) {
  u8 *dst = p;
  u8 *src = p - 0x35;
  float key = *(float *)&k.w[0];
  if (*(float *)src > key) {
    do {
      __builtin_memcpy(dst, src, 0x35);
      dst = src;
      src = src - 0x35;
    } while (*(float *)src > key);
  }
  __builtin_memcpy(dst, &k, 16);
  __builtin_memcpy(dst + 0x10, &v2, 16);
  __builtin_memcpy(dst + 0x20, &v3, 16);
  *(u32 *)(dst + 0x30) = i4;
  dst[0x34] = (u8)b1;
}
PCREG(4ae2b0, insert4ae2b0);
