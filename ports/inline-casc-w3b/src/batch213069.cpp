#include "ff.h"

static inline void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }

// 0x626640: cdecl(base, p, max, out) -> count: single-byte sibling of 0x621ce0 (token scanner recording up to max 16-byte entries at out: [0] name start, [4] value start,
// [8] value end, [0xc] byte flag); the first byte at p is skipped, the class of a byte is base[0x4c + byte], jump table 0x626808 over class - 3 (byte map 0x626834): classes
// 22, 24, 29 (width 1), 5 (2), 6 (3), 7 (4) start a name when the state is 0 (state 1 afterwards), 21 and 9 / 10 move state 1 to 0 (and in state 2 clear the flag of the open
// record; class 21 only for a space not followed by a space and a class equal to the open kind), 3 clears the flag, 12 / 13 open (state 2, kind 12 / 13) and close
// (same kind, count + 1) a value, 11 and 17 return the count unless in state 2; everything else skips one byte. There is no end of input check.
extern "C" s32 fn_626640(u8 *base, u8 *p, s32 max, u8 *out) {
  static const u8 map[27] = {0, 10, 1, 2, 3, 10, 4, 4, 5, 6, 7, 10, 10, 10, 5, 10, 10, 10, 8, 9, 10, 9, 10, 10, 10, 10, 9};
  u8 *cur = p + 1;
  u32 state = 1;
  u32 kind = 0;
  s32 count = 0;
  u8 *rec = out;
  for (;;) {
    u32 ch = cur[0];
    u32 idx = (u32)base[0x4c + ch] - 3;
    if (idx > 0x1a) { cur += 1; continue; }
    u32 m = map[idx];
    switch (m) {
      case 0:
        if (count < max) { rec[0xc] = 0; }
        cur += 1;
        break;
      case 1:
      case 2:
      case 3:
        if (state == 0) {
          if (count < max) { wr32u(rec, (u32)cur); rec[0xc] = 1; }
          state = 1;
        }
        cur += m + 1;
        break;
      case 9:
        if (state) { cur += 1; break; }
        if (count < max) { wr32u(rec, (u32)cur); rec[0xc] = 1; }
        cur += 1;
        state = 1;
        break;
      case 4:
        if (state == 1) { state = 0; cur += 1; break; }
        if (state == 2 && count < max) { cur += 1; rec[0xc] = 0; break; }
        cur += 1;
        break;
      case 5:
        if (state != 2) return count;
        cur += 1;
        break;
      case 6:
      case 7: {
        u32 k = m == 6 ? 0xc : 0xd;
        if (state != 2) {
          if (count < max) wr32u(rec + 4, (u32)(cur + 1));
          state = 2;
          kind = k;
          cur += 1;
          break;
        }
        if (kind != k) { cur += 1; break; }
        state = 0;
        if (count < max) wr32u(rec + 8, (u32)cur);
        rec += 0x10;
        count++;
        cur += 1;
        break;
      }
      case 8:
        if (state == 1) { state = 0; cur += 1; break; }
        if (state != 2) { cur += 1; break; }
        if (count >= max) { cur += 1; break; }
        if (rec[0xc] == 0) { cur += 1; break; }
        if ((u32)cur != *(u32 *)(rec + 4) && ch == 0x20) {
          u32 n = cur[1];
          if (n != 0x20 && base[0x4c + n] != kind) { cur += 1; break; }
        }
        cur += 1;
        rec[0xc] = 0;
        break;
      default:
        cur += 1;
        break;
    }
  }
}
PCREG(626640, fn_626640);
