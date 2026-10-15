// batch66051.cpp - cascade s4 batch 66051: 0x421ed0 (tier F row).
#include "ff.h"

extern "C" u32 THISCALL ext_4209f0(void *self, u8 *src, u8 *end);   // ret 8
extern "C" void *ext_634d22(void *d, const void *s, u32 n);         // cdecl memcpy thunk

// 0x421ed0, thiscall(out, limit, src, end) ret 0x10, returns the packed size or -1 (run output full) or 0 (literal output full): a run-length packer. For each position: a run of the same byte (at most 0x7fff - 1 long) longer than 3 is written as {u16 length, byte} (needs 3 bytes of room);
// then n = 0x4209f0(this, src, end) literal bytes are written as {u16 -n, bytes} (needs 2 + n bytes of room), until the source is used up.
static s32 THISCALL fn421ed0(void *self, u8 *out, u8 *limit, u8 *src, u8 *end) {
  u8 *o = out;
  if (src >= end) return 0;
  do {
    u8 b = *src;
    u8 *p = src + 1;
    if (p != end) {
      while (p < src + 0x7fff && *p == b) {
        p++;
        if (p == end) break;
      }
    }
    u32 run = (u32)(p - src);
    if (run > 3) {
      if (limit < o + 3) return -1;
      *(u16 *)o = (u16)run;
      o[2] = *src;
      o += 3;
      src += run;
    }
    u32 n = ext_4209f0(self, src, end);
    if (n) {
      if (limit < o + 2 + n) return 0;
      *(u16 *)o = (u16)(0 - n);
      o += 2;
      ext_634d22(o, src, n);
      o += n;
      src += n;
    }
  } while (end > src);
  return (s32)(o - out);
}
PCREG(421ed0, fn421ed0);
