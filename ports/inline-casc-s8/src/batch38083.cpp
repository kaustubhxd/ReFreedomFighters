// batch38083.cpp - cascade s8 batch 38083: 0x62ebc0 (zlib deflate()).
#include "ff.h"

extern "C" void ext_62f340(u8 *strm);                       // flush_pending
extern "C" void ext_62f5a0(u8 *s, u32 v);                    // putShortMSB
extern "C" void ext_62fc30(u8 *s);                           // _tr_align
extern "C" void ext_630070(u8 *s, u32 a, u32 b, u32 c);      // _tr_stored_block
extern "C" void *ext_634d10(void *p, u32 v, u32 n);          // memset
typedef int (*strategy_t)(u8 *, int);
#define W(p, off) (*(u32 *)((u8 *)(p) + (off)))
#define W16(p, off) (*(u16 *)((u8 *)(p) + (off)))
#define CONFIG_FUNC(level) (*(strategy_t *)(0x6c0250 + (level) * 12))

// 0x62ebc0, stdcall(strm, flush) -> Z_OK 0 / Z_STREAM_END 1 / -2 stream error / -5 buffer error. Z_FINISH = 4, Z_SYNC... as in zlib: INIT_STATE 0x2a, BUSY_STATE 0x71, FINISH_STATE 0x29a.
static int STDCALL fn62ebc0(u8 *strm, u32 flush) {
  if (!strm) return -2;
  u8 *s = (u8 *)W(strm, 0x1c);
  if (!s) return -2;
  if (flush > 4) return -2;
  if (W(strm, 0xc) == 0) { W(strm, 0x18) = G(u32, 0x6f44c8); return -2; }
  if (W(strm, 0) == 0 && W(strm, 4) != 0) { W(strm, 0x18) = G(u32, 0x6f44c8); return -2; }
  u32 status = W(s, 4);
  if (status == 0x29a && flush != 4) { W(strm, 0x18) = G(u32, 0x6f44c8); return -2; }
  if (W(strm, 0x10) == 0) { W(strm, 0x18) = G(u32, 0x6f44d4); return -5; }
  int old_flush = (int)W(s, 0x20);
  W(s, 0) = (u32)strm;
  W(s, 0x20) = flush;
  if (status == 0x2a) {
    u32 lvl = ((int)W(s, 0x7c) - 1) >> 1;
    u32 eax = (W(s, 0x28) << 12) - 0x7800;
    W(s, 4) = 0x71;
    if (lvl > 3) lvl = 3;
    u32 header = (lvl << 6) | eax;
    u32 h2 = W(s, 0x64) ? (header | 0x20) : header;
    u32 q = h2 / 31 + 1;
    ext_62f5a0(s, q * 31);
    if (W(s, 0x64) != 0) {
      ext_62f5a0(s, W16(strm, 0x32));
      ext_62f5a0(s, W16(strm, 0x30));
    }
    W(strm, 0x30) = 1;
  }
  if (W(s, 0x14) != 0) {
    ext_62f340(strm);
    if (W(strm, 0x10) == 0) {
      W(s, 0x20) = 0xffffffff;
      return 0;
    }
  } else if (W(strm, 4) == 0 && (int)flush <= old_flush && flush != 4) {
    W(strm, 0x18) = G(u32, 0x6f44d4);
    return -5;
  }
  u32 st = W(s, 4);
  if (st == 0x29a && W(strm, 4) != 0) { W(strm, 0x18) = G(u32, 0x6f44d4); return -5; }
  bool dispatch = true;
  if (W(strm, 4) == 0 && W(s, 0x6c) == 0 && (flush == 0 || st == 0x29a)) dispatch = false;
  if (dispatch) {
    int bstate = CONFIG_FUNC(W(s, 0x7c))(s, (int)flush);
    if (bstate == 2 || bstate == 3) W(s, 4) = 0x29a;
    if (bstate == 0 || bstate == 2) {
      if (W(strm, 0x10) == 0) W(s, 0x20) = 0xffffffff;
      return 0;
    }
    if (bstate == 1) {
      if (flush == 1) {
        ext_62fc30(s);
      } else {
        ext_630070(s, 0, 0, 0);
        if (flush == 3) {
          u8 *head = (u8 *)W(s, 0x3c);
          u32 n = W(s, 0x44);
          W16(head, n * 2 - 2) = 0;
          ext_634d10(head, 0, n * 2 - 2);
        }
      }
      ext_62f340(strm);
      if (W(strm, 0x10) == 0) {
        W(s, 0x20) = 0xffffffff;
        return 0;
      }
    }
  }
  if (flush != 4) return 0;
  if (W(s, 0x18) != 0) return 1;
  ext_62f5a0(s, W16(strm, 0x32));
  ext_62f5a0(s, W16(strm, 0x30));
  ext_62f340(strm);
  W(s, 0x18) = 0xffffffff;
  return W(s, 0x14) == 0;
}
PCREG(62ebc0, fn62ebc0);
