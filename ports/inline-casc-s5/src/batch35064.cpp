// batch35064.cpp - cascade s5 batch 35064: 0x6578b0 (GUESS copy the first 12 bytes of up to `max` indexed 36-byte records into an output array).
#include "ff.h"

typedef u8 *(THISCALL *g1_t)(void *, u32);

// 0x6578b0, thiscall(a, out, max) ret 0xc, returns the count. rec = this slot 0xc(a); A = this slot 0xc([rec+0x14]); C = this slot 0xc([rec+0x3c]) (index list: word count at +2, words from +4).
// n = min(max, count) (unsigned); for i < n: the first 12 bytes of the 36-byte record A + 36 * C[4 + 2i] go to out + 12 * i. Returns n.
static u32 THISCALL fn6578b0(u8 *self, u32 a, u32 *out, u32 max) {
  u8 *rec = (*(g1_t **)self)[0xc / 4](self, a);
  u8 *A = (*(g1_t **)self)[0xc / 4](self, *(u32 *)(rec + 0x14));
  u8 *C = (*(g1_t **)self)[0xc / 4](self, *(u32 *)(rec + 0x3c));
  u32 cnt = *(u16 *)(C + 2);
  u32 n = max > cnt ? cnt : max;
  if (n == 0) return 0;
  const u16 *idx = (const u16 *)(C + 4);
  for (u32 i = 0; i < n; i++) {
    const u32 *ent = (const u32 *)(A + (u32)idx[i] * 36);
    out[i * 3] = ent[0];
    out[i * 3 + 1] = ent[1];
    out[i * 3 + 2] = ent[2];
  }
  return n;
}
PCREG(6578b0, fn6578b0);
