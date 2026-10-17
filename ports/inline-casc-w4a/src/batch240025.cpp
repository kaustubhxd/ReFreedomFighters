// batch240025.cpp - Sonnet-w4a: 0x6332d0 zlib inflate_fast (inflate_blocks_state / z_stream layout of this exe).
#include "ff.h"

struct inflate_huft { u8 exop; u8 bits; u16 pad; u32 base; };

// 0x6332d0: cdecl(bl, bd, tl, td, s, z): fast inflate loop; s: +0x1c bitk, +0x20 bitb, +0x28 window, +0x2c end, +0x30 read, +0x34 write;
// z: +0 next_in, +4 avail_in, +8 total_in, +0x18 msg. Returns 0 (ok), 1 (stream end) or -3 (data error).
static s32 fn_6332d0(u32 bl, u32 bd, inflate_huft *tl, inflate_huft *td, u8 *s, u8 *z) {
  const u32 *mask = (const u32 *)0x6f55e8;   // inflate_mask
  inflate_huft *t;
  u32 e, b, k, n, m, ml, md, c, d;
  u8 *p, *q, *r;
  p = *(u8 **)(z + 0);
  n = *(u32 *)(z + 4);
  b = *(u32 *)(s + 0x20);
  k = *(u32 *)(s + 0x1c);
  q = *(u8 **)(s + 0x34);
  u8 *read = *(u8 **)(s + 0x30);
  u8 *window = *(u8 **)(s + 0x28);
  u8 *end = *(u8 **)(s + 0x2c);
  m = (u32)(q < read ? read - q - 1 : end - q);
  ml = mask[bl];
  md = mask[bd];
#define GRAB(j) { while (k < (j)) { n--; b |= ((u32)(*p++)) << k; k += 8; } }
#define DUMP(j) { b >>= (j); k -= (j); }
#define UNGRAB { c = *(u32 *)(z + 4) - n; c = (k >> 3) < c ? (k >> 3) : c; n += c; p -= c; k -= c << 3; }
#define UPDATE { *(u32 *)(s + 0x20) = b; *(u32 *)(s + 0x1c) = k; *(u32 *)(z + 4) = n; *(u32 *)(z + 8) += (u32)(p - *(u8 **)(z + 0)); *(u8 **)(z + 0) = p; *(u8 **)(s + 0x34) = q; }
  do {
    GRAB(20)
    if ((e = (t = tl + (b & ml))->exop) == 0) {
      DUMP(t->bits)
      *q++ = (u8)t->base;
      m--;
      continue;
    }
    for (;;) {
      DUMP(t->bits)
      if (e & 16) {
        e &= 15;
        c = t->base + (b & mask[e]);
        DUMP(e)
        GRAB(15)
        t = td + (b & md);
        e = t->exop;
        for (;;) {
          DUMP(t->bits)
          if (e & 16) {
            e &= 15;
            GRAB(e)
            d = t->base + (b & mask[e]);
            DUMP(e)
            m -= c;
            if ((u32)(q - window) >= d) {
              r = q - d;
              *q++ = *r++;
              c--;
              *q++ = *r++;
              c--;
            } else {
              e = d - (u32)(q - window);
              r = end - e;
              if (c > e) {
                c -= e;
                do { *q++ = *r++; } while (--e);
                r = window;
              }
            }
            do { *q++ = *r++; } while (--c);
            break;
          } else if ((e & 64) == 0) {
            t += t->base;
            e = (t += (b & mask[e]))->exop;
          } else {
            *(u32 *)(z + 0x18) = 0x6c15d4;
            UNGRAB
            UPDATE
            return -3;
          }
        }
        break;
      }
      if ((e & 64) == 0) {
        t += t->base;
        if ((e = (t += (b & mask[e]))->exop) == 0) {
          DUMP(t->bits)
          *q++ = (u8)t->base;
          m--;
          break;
        }
      } else if (e & 32) {
        UNGRAB
        UPDATE
        return 1;
      } else {
        *(u32 *)(z + 0x18) = 0x6c15b8;
        UNGRAB
        UPDATE
        return -3;
      }
    }
  } while (m >= 258 && n >= 10);
  UNGRAB
  UPDATE
  return 0;
}
PCREG(6332d0, fn_6332d0);
