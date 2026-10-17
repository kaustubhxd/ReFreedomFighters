#include "ff.h"

extern "C" int ext_631850(void *blocks, void *z, int r);
extern "C" void ext_6322e0(void *blocks, void *z, void *check);

// zlib 1.1.x z_stream offsets used: next_in 0, avail_in 4, total_in 8, msg 0x18, state 0x1c, adler 0x30. inflate_state:
enum { METHOD, FLAG, DICT4, DICT3, DICT2, DICT1, DICT0, BLOCKS, CHECK4, CHECK3, CHECK2, CHECK1, DONE, BAD };
struct IState {
  u32 mode;     // 0
  u32 sub0;     // 4 method / check.was / marker
  u32 sub1;     // 8 check.need
  u32 nowrap;   // 0xc
  u32 wbits;    // 0x10
  void *blocks; // 0x14
};

// 0x62f5d0: stdcall(z, f) ret 8 -> zlib inflate() (state machine over z->state->mode, 1.1.x layout): header method/window check, FLAG check (% 31), optional dictionary id
// (returns Z_NEED_DICT), blocks via 0x631850(blocks, z, r) (cdecl), adler check on the trailer; f == Z_FINISH (4) turns "no input" into Z_BUF_ERROR (-5).
extern "C" int STDCALL fn_62f5d0(u8 *zr, int f) {
  if (!zr) return -2;
  IState *st = *(IState **)(zr + 0x1c);
  if (!st) return -2;
  if (!*(u8 **)zr) return -2;
  int fr = f == 4 ? -5 : 0;
  int r = -5;
  u8 **next_in = (u8 **)zr;
  u32 *avail_in = (u32 *)(zr + 4);
  u32 *total_in = (u32 *)(zr + 8);
  const char **msg = (const char **)(zr + 0x18);
  u32 *adler = (u32 *)(zr + 0x30);
#define NEEDBYTE if (*avail_in == 0) return r; r = fr
#define NEXTBYTE ((*avail_in)--, (*total_in)++, *(*next_in)++)
  for (;;) {
    switch (st->mode) {
      case METHOD: {
        NEEDBYTE;
        u32 m = NEXTBYTE;
        st->sub0 = m;
        if ((m & 0xf) != 8) {
          st->mode = BAD;
          *msg = (const char *)0x6c02c0;
          st->sub0 = 5;
          break;
        }
        if ((st->sub0 >> 4) + 8 > st->wbits) {
          st->mode = BAD;
          *msg = (const char *)0x6c02dc;
          st->sub0 = 5;
          break;
        }
        st->mode = FLAG;
      }
      // fallthrough
      case FLAG: {
        NEEDBYTE;
        u32 b = NEXTBYTE;
        if (((st->sub0 << 8) + b) % 31) {
          st->mode = BAD;
          *msg = (const char *)0x6c02f0;
          st->sub0 = 5;
          break;
        }
        if (!(b & 0x20)) {
          st->mode = BLOCKS;
          break;
        }
        st->mode = DICT4;
      }
      // fallthrough
      case DICT4:
        NEEDBYTE;
        st->sub1 = (u32)NEXTBYTE << 24;
        st->mode = DICT3;
      // fallthrough
      case DICT3:
        NEEDBYTE;
        st->sub1 += (u32)NEXTBYTE << 16;
        st->mode = DICT2;
      // fallthrough
      case DICT2:
        NEEDBYTE;
        st->sub1 += (u32)NEXTBYTE << 8;
        st->mode = DICT1;
      // fallthrough
      case DICT1:
        if (*avail_in == 0) return r;
        st->sub1 += NEXTBYTE;
        *adler = st->sub1;
        st->mode = DICT0;
        return 2;
      case DICT0:
        st->mode = BAD;
        *msg = (const char *)0x6c0308;
        st->sub0 = 0;
        return -2;
      case BLOCKS:
        r = ext_631850(st->blocks, zr, r);
        if (r == -3) {
          st->mode = BAD;
          st->sub0 = 0;
          break;
        }
        if (r == 0) r = fr;
        if (r != 1) return r;
        r = fr;
        ext_6322e0(st->blocks, zr, &st->sub0);
        if (st->nowrap) {
          st->mode = DONE;
          break;
        }
        st->mode = CHECK4;
      // fallthrough
      case CHECK4:
        NEEDBYTE;
        st->sub1 = (u32)NEXTBYTE << 24;
        st->mode = CHECK3;
      // fallthrough
      case CHECK3:
        NEEDBYTE;
        st->sub1 += (u32)NEXTBYTE << 16;
        st->mode = CHECK2;
      // fallthrough
      case CHECK2:
        NEEDBYTE;
        st->sub1 += (u32)NEXTBYTE << 8;
        st->mode = CHECK1;
      // fallthrough
      case CHECK1:
        NEEDBYTE;
        st->sub1 += NEXTBYTE;
        if (st->sub0 != st->sub1) {
          st->mode = BAD;
          *msg = (const char *)0x6c0318;
          st->sub0 = 5;
          break;
        }
        st->mode = DONE;
        return 1;
      case DONE:
        return 1;
      case BAD:
        return -3;
      default:
        return -2;
    }
  }
}
PCREG(62f5d0, fn_62f5d0);
