// batch34116.cpp - cascade tier E, batch 34116: 0x4ae3e0 (introsort driver over 53-byte elements, register arguments).
#include "ff.h"

extern "C" u32 FASTCALL ext_4ade70(u8 *first, u8 *last, u32 a, u32 depth);   // ecx = first, edx = last, stack (a, depth), ret 8
extern "C" u32 FASTCALL ext_4add60(u8 *first, u8 *last);                    // ecx = first, edx = last, plain ret
extern "C" u32 FASTCALL ext_4ae220(u8 *first, u8 *last, u32 a);             // ecx = first, edx = last, stack a, ret 4

// 0x4ae3e0, register ABI (ecx = first, edx = last) plain ret: nothing when first == last. n = ((last - first) * 0x4d4873ed >> 36) with the sign fix (about (last - first) / 53; the exe loops forever for n < 1); k = floor(log2 n); ext_4ade70(first, last, 0, 2k);
// n <= 0x10: ext_4add60(first, last) and return; else ext_4add60(first, first + 0x350), ext_4ae220(first + 0x350, last, 0).
static u32 FASTCALL fn4ae3e0(u8 *first, u8 *last) {
  if (first == last) return 0;
  s32 diff = (s32)(last - first);
  s32 hi = (s32)(((long long)diff * (s32)0x4d4873ed) >> 32) >> 4;
  s32 n = hi + (s32)((u32)hi >> 31);
  u32 k = 0;
  s32 v = n;
  while (v != 1) {
    v >>= 1;
    k++;
  }
  ext_4ade70(first, last, 0, k * 2);
  if (n <= 0x10) return ext_4add60(first, last);
  ext_4add60(first, first + 0x350);
  return ext_4ae220(first + 0x350, last, 0);
}
PCREG(4ae3e0, fn4ae3e0);
