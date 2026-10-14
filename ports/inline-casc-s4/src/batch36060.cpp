// batch36060.cpp - cascade s4 batch 36060: 0x61cd60 (tier F row).
#include "ff.h"

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

typedef u8 *(*alloc_t)(u32);
typedef u8 *(*realloc_t)(u8 *, u32);

// 0x61cd60, cdecl(s, e, a, b, c, al) returns eax: s: count s[0xc] (signed), capacity s[0x10], table s[0x14] of 12-byte entries {e, (u8)a at +4, c at +8}, s[8] default.
// (c != 0 or b != 0): search the table for e (found -> return 1); not found and b != 0, s[8] == 0 and e[9] == 0 -> s[8] = e. Append (also when c == 0 and b == 0): full (count == capacity): capacity 0 -> 8 and al[0xc](0x60), else capacity *= 2 and al[0x10](table, capacity * 12);
// a null table -> return 0. entry = {e, (u8)a, c}; a == 0 -> e[8] = 1; count++; return 1.
static u32 fn61cd60(u8 *s, u8 *e, u32 a, u32 b, u32 c, u8 *al) {
  if (c != 0 || b != 0) {
    s32 n = (s32)rd(s + 0xc);
    if (n > 0) {
      u8 *p = *(u8 **)(s + 0x14);
      s32 i = 0;
      do {
        if (rd(p) == (u32)e) return 1;
        i++;
        p += 12;
      } while (i < n);
    }
    if (b != 0 && rd(s + 8) == 0 && e[9] == 0) wr(s + 8, (u32)e);
  }
  u32 cap = rd(s + 0x10);
  if (rd(s + 0xc) == cap) {
    u8 *ptr;
    if (cap == 0) {
      wr(s + 0x10, 8);
      ptr = (*(alloc_t *)(al + 0xc))(0x60);
    } else {
      cap += cap;
      wr(s + 0x10, cap);
      ptr = (*(realloc_t *)(al + 0x10))(*(u8 **)(s + 0x14), cap * 12);
    }
    wr(s + 0x14, (u32)ptr);
    if (!ptr) return 0;
  }
  u32 idx = rd(s + 0xc);
  u8 *ent = *(u8 **)(s + 0x14) + idx * 12;
  wr(ent, (u32)e);
  wr(ent + 8, c);
  ent[4] = (u8)a;
  if (a == 0) e[8] = 1;
  wr(s + 0xc, rd(s + 0xc) + 1);
  return 1;
}
PCREG(61cd60, fn61cd60);
