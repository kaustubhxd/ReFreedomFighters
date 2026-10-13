// batch314.cpp - 0x5ebde0 (area 43, 2026-10-12). thiscall (this = ECX), one stack argument (index), ret 4.
// Body: arr = dword at this+0x62 (unaligned); element = arr[index] (dword); return the word at element+0x24, zero-extended.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

static u32 THISCALL indexedWordAt24(u8 *self, u32 index) {
  u8 *arr = (u8 *)(unsigned long)U32(self, 0x62);
  u8 *elem = (u8 *)(unsigned long)U32(arr, index * 4);
  return *(u16 *)(elem + 0x24);
}
PCREG(5ebde0, indexedWordAt24);
