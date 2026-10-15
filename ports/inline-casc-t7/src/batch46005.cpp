// batch46005.cpp - cascade t7 (Sonnet), tier G: 0x62e730 = zlib deflate_slow(s, flush) (cdecl). hash_head is a function-level variable that is only
// refreshed when an insert happens (so it can be stale when lookahead < 3), exactly as the exe keeps it in [ebp-4].
#include "ff.h"

extern "C" void ext_62f1e0(u8 *s);                              // fill_window
extern "C" u32 ext_62f430(u8 *s, u32 cur);                      // longest_match
extern "C" void ext_62fe10(u8 *s, u8 *buf, u32 len, u32 last);  // _tr_flush_block
extern "C" void *ext_634d22(void *d, const void *src, u32 n);   // memcpy

static inline u32 &W(u8 *p, u32 off) { return *(u32 *)(p + off); }
static inline u16 &H(u8 *p, u32 off) { return *(u16 *)(p + off); }

static inline void flushBlock(u8 *s, u32 last) {
  s32 bs = (s32)W(s, 0x54);
  u8 *buf = bs >= 0 ? (u8 *)W(s, 0x30) + bs : 0;
  ext_62fe10(s, buf, W(s, 0x64) - W(s, 0x54), last);
  W(s, 0x54) = W(s, 0x64);
  u8 *strm = *(u8 **)s;
  u8 *st = *(u8 **)(strm + 0x1c);
  u32 n = W(st, 0x14);
  if (n > W(strm, 0x10)) n = W(strm, 0x10);
  if (n) {
    ext_634d22(*(void **)(strm + 0xc), *(void **)(st + 0x10), n);
    W(strm, 0xc) += n;
    W(*(u8 **)(strm + 0x1c), 0x10) += n;
    W(strm, 0x14) += n;
    W(strm, 0x10) -= n;
    W(*(u8 **)(strm + 0x1c), 0x14) -= n;
    st = *(u8 **)(strm + 0x1c);
    if (W(st, 0x14) == 0) W(st, 0x10) = W(st, 8);
  }
}

static inline u32 insertString(u8 *s, u32 pos) {
  u32 h = ((W(s, 0x40) << (W(s, 0x50) & 31)) ^ (*(u8 *)(W(s, 0x30) + pos + 2))) & W(s, 0x4c);
  W(s, 0x40) = h;
  u32 head = H((u8 *)W(s, 0x3c), h * 2);
  H((u8 *)W(s, 0x38), (W(s, 0x2c) & pos) * 2) = (u16)head;
  H((u8 *)W(s, 0x3c), W(s, 0x40) * 2) = (u16)pos;
  return head;
}
static inline bool tallyLiteral(u8 *s, u8 c) {
  u32 ll = W(s, 0x1698);
  H((u8 *)W(s, 0x169c), ll * 2) = 0;
  *((u8 *)W(s, 0x1690) + W(s, 0x1698)) = c;
  W(s, 0x1698)++;
  (*(u16 *)(s + c * 4 + 0x8c))++;
  return W(s, 0x1698) == W(s, 0x1694) - 1;
}

static u32 fn62e730(u8 *s, u32 flush) {
  u32 hh = 0;
  for (;;) {
    if (W(s, 0x6c) < 0x106) {
      ext_62f1e0(s);
      if (W(s, 0x6c) < 0x106 && flush == 0) return 0;
      if (W(s, 0x6c) == 0) break;
    }
    if (W(s, 0x6c) >= 3) hh = insertString(s, W(s, 0x64));
    W(s, 0x70) = W(s, 0x58);
    W(s, 0x5c) = W(s, 0x68);
    W(s, 0x58) = 2;
    if (hh != 0 && W(s, 0x70) < W(s, 0x78) && W(s, 0x64) - hh <= W(s, 0x24) - 0x106) {
      if (W(s, 0x80) != 2) W(s, 0x58) = ext_62f430(s, hh);
      u32 ml = W(s, 0x58);
      if (ml <= 5) {
        if (W(s, 0x80) == 1 || (ml == 3 && W(s, 0x64) - W(s, 0x68) > 0x1000)) W(s, 0x58) = 2;
      }
    }
    u32 pl = W(s, 0x70);
    if (pl >= 3 && W(s, 0x58) <= pl) {
      u32 maxIns = W(s, 0x6c) + W(s, 0x64) - 3;
      u8 len = (u8)(pl - 3);
      u16 dist = (u16)(W(s, 0x64) - W(s, 0x5c) - 1);
      u32 ll = W(s, 0x1698);
      H((u8 *)W(s, 0x169c), ll * 2) = dist;
      u16 d = (u16)(dist + 0xffff);
      *((u8 *)W(s, 0x1690) + W(s, 0x1698)) = len;
      W(s, 0x1698)++;
      u32 lc = *(u8 *)(0x6c0738 + len);
      (*(u16 *)(s + lc * 4 + 0x490))++;
      u32 dc = d < 0x100 ? *(u8 *)(0x6c0838 + d) : *(u8 *)(0x6c0938 + (d >> 7));
      (*(u16 *)(s + dc * 4 + 0x980))++;
      u32 lim = W(s, 0x1694) - 1;
      u32 cur = W(s, 0x1698);
      W(s, 0x6c) += 1 - pl;
      W(s, 0x70) = pl - 2;
      do {
        W(s, 0x64)++;
        if (W(s, 0x64) <= maxIns) hh = insertString(s, W(s, 0x64));
        W(s, 0x70)--;
      } while (W(s, 0x70) != 0);
      W(s, 0x64)++;
      W(s, 0x60) = 0;
      W(s, 0x58) = 2;
      if (cur == lim) {
        flushBlock(s, 0);
        if (W(*(u8 **)s, 0x10) == 0) return 0;
      }
    } else if (W(s, 0x60) != 0) {
      u8 c = *(u8 *)(W(s, 0x30) + W(s, 0x64) - 1);
      if (tallyLiteral(s, c)) flushBlock(s, 0);
      W(s, 0x64)++;
      W(s, 0x6c)--;
      if (W(*(u8 **)s, 0x10) == 0) return 0;
    } else {
      W(s, 0x64)++;
      W(s, 0x6c)--;
      W(s, 0x60) = 1;
    }
  }
  if (W(s, 0x60) != 0) {
    u8 c = *(u8 *)(W(s, 0x30) + W(s, 0x64) - 1);
    tallyLiteral(s, c);
    W(s, 0x60) = 0;
  }
  flushBlock(s, flush == 4);
  if (W(*(u8 **)s, 0x10) == 0) return flush == 4 ? 2 : 0;
  return (flush == 4) * 2 + 1;
}
PCREG(62e730, fn62e730);
