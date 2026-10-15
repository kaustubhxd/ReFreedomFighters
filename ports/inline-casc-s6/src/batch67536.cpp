// batch67536.cpp - cascade s6 batch 67536: 0x428010.
#include "ff.h"

// 0x428010, thiscall(key, src, total, chunk) ret 0x10, no return value: resolves a handle for `key` (slot 0x14) and writes `total` bytes from `src` through slot 0x38 (handle, src, count) followed
// by slot 0x1c (handle). When `chunk` is non-zero and below `total` the data goes in `total / chunk` blocks of `chunk` (the first with the first handle, the rest with a second handle from slot 0xc(key)),
// plus a remainder block; the last handle is committed with slot 0x1c.
static void THISCALL fn428010(u8 *self, u32 key, u32 src, int total, int chunk) {
  u32 h = vcall<u32>(self, 0x14, key);
  if (!h) return;
  if (chunk == 0 || total <= chunk) {
    vcall<void>(self, 0x38, h, src, (u32)total);
    vcall<void>(self, 0x1c, h);
    return;
  }
  u32 p = src;
  vcall<void>(self, 0x38, h, p, (u32)chunk);
  vcall<void>(self, 0x1c, h);
  int q = total / chunk;
  p += (u32)chunk;
  u32 h2 = vcall<u32>(self, 0xc, key);
  int cnt = q - 1;
  if (cnt != 0) {
    do {
      vcall<void>(self, 0x38, h2, p, (u32)chunk);
      p += (u32)chunk;
      cnt--;
    } while (cnt != 0);
  }
  int rem = total - q * chunk;
  if (rem != 0) vcall<void>(self, 0x38, h2, p, (u32)rem);
  vcall<void>(self, 0x1c, h2);
}
PCREG(428010, fn428010);
