// batch37039.cpp - cascade s6 batch 37039: 0x402320.
#include "ff.h"

extern "C" void ext_401890(u8 *s);                              // cdecl
extern "C" void ext_410bc0(u8 *buf, u32 a, u32 b);              // cdecl
extern "C" s32 ext_410de0(u8 *buf, u32 n);                      // cdecl
extern "C" u8 *ext_401820(u8 *s, u32 bytes);                    // cdecl
typedef s32(*dec_t)(u8 *, u32);

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x402320, cdecl(s, b), returns -0x87 / -0x88 on read errors, else what the per-mode handler returns: Vorbis-style per-block setup. Resets the block (0x401890),
// opens its bit reader at s+4 on b's data, reads a mode id (error when its top bit is set) and a mode index from the setup tables reachable through s+0x40; records the
// block's window/previous info (+0x18 / +0x20 / +0x1c / +0x24 .. +0x3c, with b's 64-bit position minus 3), allocates the per-channel pointer array and one buffer per
// channel, then calls the decoder selected through the table at 0x6f1dd8 (slot 0x1c) with (s, setup entry).
static s32 fn402320(u8 *s, u8 *b) {
  u8 *t = *(u8 **)(s + 0x40);
  u8 *p = *(u8 **)(t + 4);
  u8 *q = *(u8 **)(t + 0x68);
  u8 *v = *(u8 **)(p + 0x1c);
  ext_401890(s);
  ext_410bc0(s + 4, D32(b, 0), D32(b, 4));
  if (ext_410de0(s + 4, 1) != 0) return (s32)0xffffff79;
  s32 idx = ext_410de0(s + 4, D32(q, 0x34));
  if (idx == -1) return (s32)0xffffff78;
  D32(s, 0x28) = (u32)idx;
  u8 *w = *(u8 **)(v + idx * 4 + 0x24);
  u32 e = D32(w, 0);
  D32(s, 0x1c) = e;
  if (e != 0) {
    D32(s, 0x18) = (u32)ext_410de0(s + 4, 1);
    s32 r2 = ext_410de0(s + 4, 1);
    D32(s, 0x20) = (u32)r2;
    if (r2 == -1) return (s32)0xffffff78;
  } else {
    D32(s, 0x18) = 0;
    D32(s, 0x20) = 0;
  }
  D32(s, 0x30) = D32(b, 0x10);
  D32(s, 0x34) = D32(b, 0x14);
  u32 lo = D32(b, 0x18), hi = D32(b, 0x1c);
  u32 lo2 = lo - 3;
  hi -= (lo < 3);
  D32(s, 0x38) = lo2;
  D32(s, 0x3c) = hi;
  D32(s, 0x2c) = D32(b, 0xc);
  D32(s, 0x24) = D32(v, D32(s, 0x1c) * 4);
  D32(s, 0) = (u32)ext_401820(s, D32(p, 4) * 4);
  for (s32 i = 0; (s32)D32(p, 4) > 0 && i < (s32)D32(p, 4); i++) {
    u8 *blk = ext_401820(s, D32(s, 0x24) * 4);
    ((u32 *)D32(s, 0))[i] = (u32)blk;
  }
  u32 k = D32(*(u8 **)(v + idx * 4 + 0x24), 0xc);
  u32 mt = D32(v, k * 4 + 0x124);
  u8 *mode = *(u8 **)(0x6f1dd8 + mt * 4);
  u32 arg = ((u32 *)D32(q, 0x38))[idx];
  return (*(dec_t *)(mode + 0x1c))(s, arg);
}
PCREG(402320, fn402320);
