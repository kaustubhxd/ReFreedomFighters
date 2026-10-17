#include "ff.h"

extern "C" void FASTCALL ext_633654(u32 cookie);

struct Huft {
  u8 exop;
  u8 bits;
  u16 pad;  // uninitialised in the original (copied along with exop / bits)
  u32 base;
};

// 0x632360: cdecl huft_build(b, n, s, d, e, t, m, hp, hn, v) -> zlib 1.1.x inflate_trees.c: builds the Huffman decoding table for n code lengths b[] (symbols >= s use the
// base / extra tables d / e; 0x5a0 = MANY entries in hp, *hn counts them). Returns 0, -3 (over-subscribed), -4 (table full), -5 (incomplete); /GS: cookie call before every return.
static int body_632360(u32 *b, u32 n, u32 s, const u32 *d, const u32 *e, Huft **t, u32 *m, Huft *hp, u32 *hn, u32 *v) {
  u32 a, c[16], f, i, j, z;
  int g, h, k, l, w, y;
  u32 *p, *xp;
  Huft *q, *u[15];
  Huft r;
  u32 x[16];
  for (i = 0; i < 16; i++) c[i] = 0;
  p = b;
  i = n;
  do {
    c[*p]++;
    p++;
  } while (--i);
  if (c[0] == n) {
    *t = 0;
    *m = 0;
    return 0;
  }
  l = (int)*m;
  for (j = 1; j <= 15; j++)
    if (c[j]) break;
  k = (int)j;
  if ((u32)l < j) l = (int)j;
  for (i = 15; i; i--)
    if (c[i]) break;
  g = (int)i;
  if ((u32)l > i) l = (int)i;
  *m = (u32)l;
  for (y = 1 << j; j < i; j++, y <<= 1)
    if ((y -= (int)c[j]) < 0) return -3;
  if ((y -= (int)c[i]) < 0) return -3;
  c[i] += (u32)y;
  x[1] = j = 0;
  p = c + 1;
  xp = x + 2;
  while (--i) {
    j += *p++;
    *xp++ = j;
  }
  p = b;
  i = 0;
  do {
    if ((j = *p++) != 0) v[x[j]++] = i;
  } while (++i < n);
  n = x[g];
  x[0] = i = 0;
  p = v;
  h = -1;
  w = -l;
  u[0] = 0;
  q = 0;
  z = 0;
  for (; k <= g; k++) {
    a = c[k];
    while (a--) {
      while (k > w + l) {
        h++;
        w += l;
        z = (u32)(g - w);
        z = z > (u32)l ? (u32)l : z;
        if ((f = 1u << (j = (u32)(k - w))) > a + 1) {
          f -= a + 1;
          xp = c + k;
          if (j < z)
            while (++j < z) {
              if ((f <<= 1) <= *++xp) break;
              f -= *xp;
            }
        }
        z = 1u << j;
        if (*hn + z > 0x5a0) return -4;
        u[h] = q = hp + *hn;
        *hn += z;
        if (h) {
          x[h] = i;
          r.bits = (u8)l;
          r.exop = (u8)j;
          j = i >> (w - l);
          r.base = (u32)(q - u[h - 1]) - j;
          u[h - 1][j] = r;
        } else {
          *t = q;
        }
      }
      r.bits = (u8)(k - w);
      if (p >= v + n) {
        r.exop = 128 + 64;
      } else if (*p < s) {
        r.exop = (u8)(*p < 256 ? 0 : 32 + 64);
        r.base = *p++;
      } else {
        r.exop = (u8)(e[*p - s] + 16 + 64);
        r.base = d[*p++ - s];
      }
      f = 1u << (k - w);
      for (j = i >> w; j < z; j += f) q[j] = r;
      for (j = 1u << (k - 1); i & j; j >>= 1) i ^= j;
      i ^= j;
      while ((i & ((1u << w) - 1)) != x[h]) {
        h--;
        w -= l;
      }
    }
  }
  return y != 0 && g != 1 ? -5 : 0;
}
extern "C" int fn_632360(u32 *b, u32 n, u32 s, const u32 *d, const u32 *e, Huft **t, u32 *m, Huft *hp, u32 *hn, u32 *v) {
  int r = body_632360(b, n, s, d, e, t, m, hp, hn, v);
  ext_633654(G(u32, 0x6f5630));
  return r;
}
PCREG(632360, fn_632360);
