// batch37072.cpp - cascade s6 batch 37072.
#include "ff.h"

extern "C" void THISCALL ext_49c310(u8 *self, u32 idx, u32 *pos, u32 flag);   // ret 0xc

// 0x49ca30, thiscall(idx, p, size, split) ret 0x10: bookkeeping on a boundary-tag style block record p (two words: p[0] start tag, p[1] end tag; low 3 bits are flags, the rest
// is a 0x70-aligned address). With split == 0: if p[0] is not marked (bit 0 clear) the words from p are shifted down until a marked one is found (returns 4); otherwise p[0] is
// reset to 1 when the bin slot (+0x1d table, entry idx) lies at or after p, else the previous word is marked (returns 0). With split != 0: the block [lo, hi) is cut at size,
// tags are rewritten (a remainder under 0xe0 clears flag 2 and makes the result 2) and the freed 0x70-steps are reported one by one to 0x49c310. Returns the result code.
static u32 THISCALL fn49ca30(u8 *self, u32 idx, u32 *p, u32 size, u8 split) {
  u32 bins = *(u32 *)(self + 0x1d);
  u32 slot = bins + idx * 4;
  u32 ret = 0;
  if (!split) {
    if (*p & 1) {
      if (slot + 4 >= (u32)p) *p = 1;
      else p[-1] |= 1;
      return 0;
    }
    while (!(*p & 1)) {
      *p = p[1];
      p++;
    }
    return 4;
  }
  u32 v0 = p[0];
  u32 hi = p[1] & 0xfffffff8u;
  u32 lo = v0 & 0xfffffff8u;
  u32 d = size - lo;
  u32 rest = hi - size;
  u32 start, end;
  if (d >= rest) {
    u32 e = d - 0x70;
    start = size + 0x70;
    if (e < 0xe0) {
      v0 &= 0xfffffffdu;
      ret = 2;
      p[0] = v0;
    }
    if (e == 0) {
      end = 0;
    } else {
      p[1] = (p[1] & 7) | (size - 0x70);
      end = hi;
    }
  } else {
    end = size - 0x70;
    start = lo;
    if (rest - 0x70 < 0xe0) {
      v0 &= 0xfffffffdu;
      ret = 2;
      p[0] = v0;
    }
    p[0] = (p[0] & 7) | (size + 0x70);
  }
  if (start > end) return ret;
  do {
    u32 pos = start;
    ext_49c310(self, idx, &pos, 1);
    start += 0x70;
  } while (start <= end);
  return ret;
}
PCREG(49ca30, fn49ca30);
