// batch4023.cpp - area 70 (slice 4/5), batch 4023: 0x4a0150, move an entry to the front of an index list and drop one count
// (name GUESS). Exe callee 0x4a0e40 (thiscall, one argument, ret 4, returns the list position) is stubbed by address.
#include "ff.h"

extern "C" u32 THISCALL ext_4a0e40(void *self, u32 idx);   // exe: returns a position; stubbed by address in the spec

// 0x4a0150 (name GUESS): thiscall (ECX = this), one stack argument idx, ret 4. b = 0x4a0e40(idx). Layout: values at
// +4 + 4*k (k < 0x200), counts at +0x804 + 4*k. If counts[b] != idx, swap values[idx] and values[counts[b]]. Then, from
// s = b - 1 down while s > 0 and the count at s equals counts[b], decrement it and s; finally decrement counts[b].
static void THISCALL moveAndDrop(u8 *self, u32 idx) {
  u32 *vals = (u32 *)(self + 4);
  u32 *cnt = (u32 *)(self + 0x804);
  u32 b = ext_4a0e40(self, idx);
  u32 pos = cnt[b];
  if (pos != idx) {
    u32 t = vals[idx];
    vals[idx] = vals[pos];
    vals[pos] = t;
  }
  s32 s = (s32)b - 1;
  if (s > 0) {
    u32 *p = &cnt[s];
    for (;;) {
      u32 v = *p;
      if (v != cnt[b]) break;
      v--;
      s--;
      *p = v;
      p--;
      if (!(s > 0)) break;
    }
  }
  cnt[b]--;
}
PCREG(4a0150, moveAndDrop);
