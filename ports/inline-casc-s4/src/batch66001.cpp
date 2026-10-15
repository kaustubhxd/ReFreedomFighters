// batch66001.cpp - cascade s4 batch 66001: 0x5e93f0 (tier F row; redone by Sonnet, the earlier Haiku asm port looped forever on some inputs).
#include "ff.h"

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

// Erase entry idx of the table (count at base[0], 8-byte (key, value) entries from base + 4): later entries move down one place, then the count is decremented.
static void erase_entry(u8 *base, u32 idx) {
  u32 cnt = rd(base);
  if (idx < cnt - 1) {
    u32 i = idx;
    do {
      u8 *e = base + 4 + i * 8;
      wr(e, rd(e + 8));
      i++;
      wr(e + 4, rd(e + 12));
    } while (i < rd(base) - 1);
  }
  wr(base, rd(base) - 1);
}

// 0x5e93f0, thiscall(value, flag) ret 8 (this = t; table at t + 0x48): p = first entry; table empty -> return. flag (byte) != 0: entries whose key is 0 are erased (the scan continues at the entry after the erased one's old position, not at the shifted-in entry; erasing the last one ends the call).
// flag == 0: the first entry whose key equals value is erased and the call ends.
static void THISCALL fn5e93f0(u8 *t, u32 value, u32 flag) {
  u8 *base = t + 0x48;
  u8 *p = t + 0x4c;
  if (p == base + rd(base) * 8 + 4) return;
  for (;;) {
    if ((u8)flag) {
      if (rd(p) == 0) {
        u8 *old_end = base + 4 + rd(base) * 8;
        u32 idx = (u32)(p - base - 4) >> 3;
        p += 8;
        erase_entry(base, idx);
        if (p == old_end) return;
      } else {
        p += 8;
      }
    } else {
      if (rd(p) == value) {
        erase_entry(base, (u32)(p - base - 4) >> 3);
        return;
      }
      p += 8;
    }
    if (p == base + rd(base) * 8 + 4) return;
  }
}
PCREG(5e93f0, fn5e93f0);
