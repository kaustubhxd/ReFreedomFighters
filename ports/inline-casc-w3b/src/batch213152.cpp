#include "ff.h"

extern "C" int ext_6331d0(void *s, void *z, int r);
extern "C" int ext_6332d0(u32 bl, u32 bd, void *tl, void *td, void *s, void *z);

struct Huft {
  u8 exop;
  u8 bits;
  u16 pad;
  u32 base;
};
// zlib 1.1.4 structures (offsets as used by the exe): z: next_in 0, avail_in 4, total_in 8, msg 0x18. s (inflate_blocks_state): codes 4, bitk 0x1c, bitb 0x20, window 0x28,
// end 0x2c, read 0x30, write 0x34. c (inflate_codes_state): mode 0, len 4, sub 8 / 0xc (tree + need | lit | get + dist), lbits 0x10, dbits 0x11, ltree 0x14, dtree 0x18.
struct Codes {
  u32 mode;
  u32 len;
  u32 sub0;
  u32 sub1;
  u8 lbits;
  u8 dbits;
  u16 pad;
  Huft *ltree;
  Huft *dtree;
};
enum { START, LEN, LENEXT, DIST, DISTEXT, COPY, LIT, WASH, END, BADCODE };

static inline u32 mask(u32 j) { return *(u32 *)(0x6f55e8 + 4 * j); }

// 0x632aa0: cdecl inflate_codes(s, z, r) -> int (zlib 1.1.4 infcodes.c): decodes literal / length / distance codes through the Huffman tables in c, copying into the window.
extern "C" int fn_632aa0(u8 *s, u8 *z, int r) {
  Codes *c = *(Codes **)(s + 4);
  u8 *p = *(u8 **)z;
  u32 n = *(u32 *)(z + 4);
  u32 b = *(u32 *)(s + 0x20);
  u32 k = *(u32 *)(s + 0x1c);
  u8 *q = *(u8 **)(s + 0x34);
  u8 *window = *(u8 **)(s + 0x28);
  u8 *end = *(u8 **)(s + 0x2c);
  u32 m;
  Huft *t;
  u32 e, j;
  u8 *f;
#define RD() (*(u8 **)(s + 0x30))
#define COMPUTE_M() m = (q < RD()) ? (u32)(RD() - q - 1) : (u32)(end - q)
#define LOAD() do { p = *(u8 **)z; n = *(u32 *)(z + 4); b = *(u32 *)(s + 0x20); k = *(u32 *)(s + 0x1c); q = *(u8 **)(s + 0x34); COMPUTE_M(); } while (0)
#define UPDATE() do { *(u32 *)(s + 0x20) = b; *(u32 *)(s + 0x1c) = k; *(u32 *)(z + 4) = n; *(u32 *)(z + 8) += (u32)(p - *(u8 **)z); *(u8 **)z = p; *(u8 **)(s + 0x34) = q; } while (0)
#define LEAVE() do { UPDATE(); return ext_6331d0(s, z, r); } while (0)
#define FLUSH() do { UPDATE(); r = ext_6331d0(s, z, r); LOAD(); } while (0)
#define NEEDBYTE() if (n) r = 0; else LEAVE()
#define NEEDBITS(jj) while (k < (jj)) { NEEDBYTE(); n--; b |= (u32)(*p++) << k; k += 8; }
#define DUMPBITS(jj) { b >>= (jj); k -= (jj); }
#define WRAP() if (q == end && RD() != window) { q = window; COMPUTE_M(); }
#define NEEDOUT() if (m == 0) { WRAP(); if (m == 0) { FLUSH(); WRAP(); if (m == 0) LEAVE(); } } r = 0
  COMPUTE_M();
  for (;;) {
    switch (c->mode) {
      case START:
        if (m >= 258 && n >= 10) {
          UPDATE();
          r = ext_6332d0(c->lbits, c->dbits, c->ltree, c->dtree, s, z);
          LOAD();
          if (r != 0) {
            c->mode = r == 1 ? WASH : BADCODE;
            break;
          }
        }
        c->sub1 = c->lbits;
        c->sub0 = (u32)c->ltree;
        c->mode = LEN;
      // fallthrough
      case LEN:
        j = c->sub1;
        NEEDBITS(j);
        t = (Huft *)c->sub0 + (b & mask(j));
        DUMPBITS(t->bits);
        e = t->exop;
        if (e == 0) {
          c->sub0 = t->base;
          c->mode = LIT;
          break;
        }
        if (e & 16) {
          c->sub0 = e & 15;
          c->len = t->base;
          c->mode = LENEXT;
          break;
        }
        if ((e & 64) == 0) {
          c->sub1 = e;
          c->sub0 = (u32)(t + t->base);
          break;
        }
        if (e & 32) {
          c->mode = WASH;
          break;
        }
        c->mode = BADCODE;
        *(u32 *)(z + 0x18) = 0x6c15b8;
        r = -3;
        LEAVE();
      case LENEXT:
        j = c->sub0;
        NEEDBITS(j);
        c->len += b & mask(j);
        DUMPBITS(j);
        c->sub1 = c->dbits;
        c->sub0 = (u32)c->dtree;
        c->mode = DIST;
      // fallthrough
      case DIST:
        j = c->sub1;
        NEEDBITS(j);
        t = (Huft *)c->sub0 + (b & mask(j));
        DUMPBITS(t->bits);
        e = t->exop;
        if (e & 16) {
          c->sub0 = e & 15;
          c->sub1 = t->base;
          c->mode = DISTEXT;
          break;
        }
        if ((e & 64) == 0) {
          c->sub1 = e;
          c->sub0 = (u32)(t + t->base);
          break;
        }
        c->mode = BADCODE;
        *(u32 *)(z + 0x18) = 0x6c15d4;
        r = -3;
        LEAVE();
      case DISTEXT:
        j = c->sub0;
        NEEDBITS(j);
        c->sub1 += b & mask(j);
        DUMPBITS(j);
        c->mode = COPY;
      // fallthrough
      case COPY:
        if ((u32)(q - window) < c->sub1)
          f = q + (end - window) - c->sub1;
        else
          f = q - c->sub1;
        while (c->len) {
          NEEDOUT();
          *q++ = *f++;
          m--;
          if (f == end) f = window;
          c->len--;
        }
        c->mode = START;
        break;
      case LIT:
        NEEDOUT();
        *q++ = (u8)c->sub0;
        m--;
        c->mode = START;
        break;
      case WASH:
        if (k > 7) {
          k -= 8;
          n++;
          p--;
        }
        FLUSH();
        if (RD() != q) LEAVE();
        c->mode = END;
      // fallthrough
      case END:
        r = 1;
        LEAVE();
      case BADCODE:
        r = -3;
        LEAVE();
      default:
        r = -2;
        LEAVE();
    }
  }
}
PCREG(632aa0, fn_632aa0);
