// batch38014.cpp - cascade s8 batch 38014: 0x405240 (build a binary decode tree and a lookup table from code lengths).
#include "ff.h"

extern "C" void *ext_634d58(u32 size);              // malloc, cdecl
extern "C" void *ext_634df4(u32 n, u32 size);       // calloc, cdecl
extern "C" void ext_634d52(void *p);                // free, cdecl
extern "C" s32 *ext_4050f0(s32 *lens, s32 count);   // returns the code of every symbol (cdecl)
extern "C" s32 ext_405090(s32 count);               // cdecl

// 0x405240, cdecl(cfg) -> table or 0. cfg: +4 symbol count n, +8 pointer to a struct (+4 count, +8 lengths array). Builds a two-way tree in two calloc'ed arrays (0 / 1 child
// per node, n*2 entries each: B for a 0 bit, C for a 1 bit; leaves hold -symbol), walking each code LSB first, then a 1<<k entry lookup table (k = max(ext_405090(n) - 4, 5)) of
// (node or leaf, bits used) pairs. Returns the 0x18-byte table object: +0 values, +4 bit counts, +8 k, +0xc / +0x10 the two arrays, +0x14 n*2.
static s32 *fn405240(u8 *cfg) {
  u8 *L = *(u8 **)(cfg + 8);
  s32 *ebx = (s32 *)ext_634d58(0x18);
  s32 ebp = 0;
  s32 *B = (s32 *)ext_634df4(*(s32 *)(cfg + 4) * 2, 4);
  ebx[3] = (s32)B;
  s32 *C = (s32 *)ext_634df4(*(s32 *)(cfg + 4) * 2, 4);
  ebx[4] = (s32)C;
  s32 *D = ext_4050f0(*(s32 **)(L + 8), *(s32 *)(L + 4));
  if (!D) return 0;
  ebx[5] = *(s32 *)(cfg + 4) * 2;
  s32 n = *(s32 *)(cfg + 4);
  if (n > 0) {
    s32 F = 0;
    for (s32 i = 0; i < *(s32 *)(cfg + 4); i++, F--) {
      s32 len = (*(s32 **)(L + 8))[i];
      if (len > 0) {
        s32 edx = 0, j = 0;
        s32 *arr;
        if (len - 1 > 0) {
          do {
            arr = ((D[i] >> j) & 1) ? C : B;
            if (arr[edx] == 0) {
              ebp++;
              arr[edx] = ebp;
            }
            edx = arr[edx];
            j++;
          } while (j < (*(s32 **)(L + 8))[i] - 1);
        }
        arr = ((D[i] >> j) & 1) ? C : B;
        arr[edx] = F;
      }
    }
  }
  ext_634d52(D);
  s32 k = ext_405090(*(s32 *)(cfg + 4)) - 4;
  ebx[2] = k;
  if (k < 5) ebx[2] = 5;
  s32 cnt = 1 << ebx[2];
  u32 sz = (u32)cnt * 4;
  ebx[0] = (s32)ext_634d58(sz);
  ebx[1] = (s32)ext_634d58(sz);
  for (s32 edx = 0; edx < cnt; edx++) {
    s32 esi = ebx[2], eax = 0, ecx = 0;
    if (esi > 0) {
      do {
        if (!(eax > 0 || ecx == 0)) break;
        s32 *arr = (edx & (1 << ecx)) ? C : B;
        eax = arr[eax];
        ecx++;
      } while (ecx < esi);
    }
    ((s32 *)ebx[0])[edx] = eax;
    ((s32 *)ebx[1])[edx] = ecx;
  }
  return ebx;
}
PCREG(405240, fn405240);
