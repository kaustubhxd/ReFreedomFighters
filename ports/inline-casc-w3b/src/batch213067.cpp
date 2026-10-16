#include "ff.h"

extern "C" u32 ext_62c640(u32 a, u32 b);

static inline void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }

// 0x6246e0: little-endian twin of 0x621ce0 (the pair is [char, lead]: lead = second byte, char = first byte; same state machine, verified apart from byte order):
//  cdecl(base, p, max, out) -> count: token scanner over big-endian character pairs (the first pair at p is skipped), recording up to max entries of
// 16 bytes at out: [0] start of a name, [4] start of a value (after its opening quote pair), [8] the closing quote position, [0xc] byte flag. The class of a pair is
// base[0x4c + second] when the first byte is 0, else 0x62c640(first, second); jump table 0x621f10 over class - 3 (byte map 0x621f38): classes 5, 22, 24, 29 (width 2),
// 6 (width 3), 7 (width 4) start a name when the state is 0 (state 1 afterwards), 21 and 9 / 10 move state 1 to 0 (and in state 2 clear the flag of the open record,
// class 21 only for a [0, 0x20] pair), 3 clears the flag, 12 / 13 open (state 2, kind 12 / 13) and close (same kind, count + 1) a value, 11 and 17 return the
// count unless in state 2; everything else skips one pair. There is no end of input check.
extern "C" s32 fn_6246e0(u8 *base, u8 *p, s32 max, u8 *out) {
  static const u8 map[27] = {0, 9, 1, 2, 3, 9, 4, 4, 5, 6, 7, 9, 9, 9, 5, 9, 9, 9, 8, 1, 9, 1, 9, 9, 9, 9, 1};
  u8 *cur = p + 2;
  u32 state = 1;
  u32 kind = 0;
  s32 count = 0;
  u8 *rec = out;
  for (;;) {
    u32 b0 = cur[1], b1 = cur[0];
    u32 cls = b0 ? ext_62c640(b0, b1) : base[0x4c + b1];
    u32 idx = cls - 3;
    if (idx > 0x1a) { cur += 2; continue; }
    switch (map[idx]) {
      case 0:
        if (count < max) rec[0xc] = 0;
        cur += 2;
        break;
      case 1:
        if (state) { cur += 2; break; }
        if (count < max) { wr32u(rec, (u32)cur); rec[0xc] = 1; }
        cur += 2;
        state = 1;
        break;
      case 2:
        if (state == 0) {
          if (count < max) { wr32u(rec, (u32)cur); rec[0xc] = 1; }
          state = 1;
        }
        cur += 3;
        break;
      case 3:
        if (state == 0) {
          if (count < max) { wr32u(rec, (u32)cur); rec[0xc] = 1; }
          state = 1;
        }
        cur += 4;
        break;
      case 4:
        if (state == 1) { state = 0; cur += 2; break; }
        if (state == 2 && count < max) { cur += 2; rec[0xc] = 0; break; }
        cur += 2;
        break;
      case 5:
        if (state != 2) return count;
        cur += 2;
        break;
      case 6:
      case 7: {
        u32 k = map[idx] == 6 ? 0xc : 0xd;
        if (state != 2) {
          if (count < max) wr32u(rec + 4, (u32)(cur + 2));
          state = 2;
          kind = k;
          cur += 2;
          break;
        }
        if (kind != k) { cur += 2; break; }
        state = 0;
        if (count < max) wr32u(rec + 8, (u32)cur);
        rec += 0x10;
        count++;
        cur += 2;
        break;
      }
      case 8:
        if (state == 1) { state = 0; cur += 2; break; }
        if (state != 2) { cur += 2; break; }
        if (count >= max) { cur += 2; break; }
        if (rec[0xc] == 0) { cur += 2; break; }
        if ((u32)cur != *(u32 *)(rec + 4) && b0 == 0 && (s8)b1 == 0x20) {
          u32 b2 = cur[3];
          u32 c2;
          if (b2 == 0) {
            u32 b3 = cur[2];
            if (b3 == 0x20) goto clear;
            c2 = base[0x4c + b3];
          } else {
            c2 = ext_62c640(b2, cur[2]);
          }
          if (c2 != kind) { cur += 2; break; }
        }
      clear:
        cur += 2;
        rec[0xc] = 0;
        break;
      default:
        cur += 2;
        break;
    }
  }
}
PCREG(6246e0, fn_6246e0);
