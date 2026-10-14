// batch37097.cpp - cascade s6 batch 37097: 0x4050f0.
#include "ff.h"

extern "C" u32 *__attribute__((cdecl)) ext_634d58(u32 bytes);   // malloc
extern "C" void __attribute__((cdecl)) ext_634d52(void *p);     // free

// 0x4050f0, cdecl(lens, n), returns an array of n codes or 0: Vorbis-style canonical Huffman codeword assignment. next[len] is the next free code of each length (0x21
// entries); every entry with a positive length takes next[len] (failing when it no longer fits in len bits, freeing the array), the tree of next[] values is advanced (carrying
// up while the code is even, then propagating the left shift to longer lengths) and finally each code is bit-reversed within its length (entries with no length become 0).
static u32 *fn4050f0(s32 *lens, s32 n) {
  u32 *mem = ext_634d58((u32)n * 4);
  s32 next[0x21];
  for (int i = 0; i < 0x21; i++) next[i] = 0;
  if (n <= 0) return mem;
  for (s32 i = 0; i < n; i++) {
    s32 len = lens[i];
    if (len <= 0) continue;
    s32 code = next[len];
    if (len < 0x20 && (code >> len) != 0) {
      ext_634d52(mem);
      return 0;
    }
    mem[i] = (u32)code;
    s32 d = len;
    for (;;) {
      s32 v = next[d];
      if (v & 1) {
        if (d == 1) next[1]++;
        else next[d] = next[d - 1] << 1;
        break;
      }
      next[d] = v + 1;
      d--;
      if (d <= 0) break;
    }
    s32 ecx = len + 1;
    s32 esi = code;
    while (ecx < 0x21) {
      s32 edx = next[ecx];
      if ((edx >> 1) != esi) break;
      esi = edx;
      next[ecx] = next[ecx - 1] << 1;
      ecx++;
    }
  }
  for (s32 i = 0; i < n; i++) {
    s32 len = lens[i];
    u32 r = 0;
    if (len > 0) {
      u32 code = mem[i];
      for (s32 k = 0; k < len; k++) r = (r << 1) | ((code >> k) & 1);
    }
    mem[i] = r;
  }
  return mem;
}
PCREG(4050f0, fn4050f0);
