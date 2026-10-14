// batch38074.cpp - cascade s8 batch 38074: 0x62e190 (zlib deflate_stored: copy input to stored blocks, flushing the pending output into the stream).
#include "ff.h"

extern "C" void ext_62f1e0(u8 *s);                              // fill_window
extern "C" void ext_62fe10(u8 *s, u8 *buf, u32 len, u32 last);  // _tr_flush_block-like (stored block emit)
extern "C" void *ext_634d22(void *dst, const void *src, u32 n); // memcpy
#define W(p, off) (*(u32 *)((u8 *)(p) + (off)))

// the inlined flush_pending(strm): copies min(pending, avail_out) bytes
static void flush_pending(u8 *strm) {
  u8 *st = (u8 *)W(strm, 0x1c);
  u32 len = W(st, 0x14);
  if (len > W(strm, 0x10)) len = W(strm, 0x10);
  if (len == 0) return;
  ext_634d22((void *)W(strm, 0xc), (void *)W(st, 0x10), len);
  W(strm, 0xc) += len;
  W(st, 0x10) += len;
  W(strm, 0x14) += len;
  W(strm, 0x10) -= len;
  W(st, 0x14) -= len;
  if (W(st, 0x14) == 0) W(st, 0x10) = W(st, 8);
}
static void flush_block_only(u8 *s, u32 last) {
  int bs = (int)W(s, 0x54);
  u8 *buf = bs >= 0 ? (u8 *)(W(s, 0x30) + bs) : 0;
  ext_62fe10(s, buf, W(s, 0x64) - W(s, 0x54), last);
  u8 *strm = (u8 *)W(s, 0);
  W(s, 0x54) = W(s, 0x64);
  flush_pending(strm);
}

// 0x62e190, cdecl(s, flush) -> 0 need more, 1 block done, 2 finish started, 3 finish done.
static u32 fn62e190(u8 *s, u32 flush) {
  u32 max_block = 0xffff;
  u32 t = W(s, 0xc) - 5;
  if (t < max_block) max_block = t;
  for (;;) {
    u32 la = W(s, 0x6c);
    if (la <= 1) {
      ext_62f1e0(s);
      la = W(s, 0x6c);
      if (la == 0) {
        if (flush == 0) return 0;
        flush_block_only(s, flush == 4);
        u8 *strm = (u8 *)W(s, 0);
        if (W(strm, 0x10) == 0) return flush == 4 ? 2 : 0;
        return (flush == 4) * 2 + 1;
      }
    }
    W(s, 0x64) += la;
    u32 ss = W(s, 0x64);
    W(s, 0x6c) = 0;
    u32 max_start = W(s, 0x54) + max_block;
    if (ss == 0 || ss >= max_start) {
      W(s, 0x6c) = ss - max_start;
      W(s, 0x64) = max_start;
      flush_block_only(s, 0);
      if (W(*(u8 **)s, 0x10) == 0) return 0;
    }
    if (W(s, 0x64) - W(s, 0x54) >= W(s, 0x24) - 0x106) {
      flush_block_only(s, 0);
      if (W(*(u8 **)s, 0x10) == 0) return 0;
    }
  }
}
PCREG(62e190, fn62e190);
