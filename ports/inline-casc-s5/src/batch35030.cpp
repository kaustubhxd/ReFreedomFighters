// batch35030.cpp - cascade s5 batch 35030: 0x5fd670 (GUESS string replace of the range [a, b) by the range [c, d)).
#include "ff.h"

extern "C" void ext_634d22(void *dst, const void *src, u32 n);                    // cdecl memcpy
extern "C" void THISCALL ext_430d10(u8 *self, u8 *pos, u8 *first, u8 *last);      // ret 0xc
typedef void(*memmove_t)(void *, const void *, u32);

// 0x5fd670, thiscall(a, b, c, d) ret 0x10, returns this. n = d - c, room = b - a (signed). room >= n: memcpy(a, c, n); p = a + n; when p != b the tail (this[4] - b + 1 bytes)
// is moved down with memmove (IAT 0x676278) and this[4] += p - b. Otherwise memcpy(a, c, room) and 0x430d10(this, b, c + room, d) inserts the rest.
static u8 *THISCALL fn5fd670(u8 *self, u8 *a, u8 *b, u8 *c, u8 *d) {
  s32 n = (s32)(d - c);
  s32 room = (s32)(b - a);
  if (room >= n) {
    ext_634d22(a, c, n);
    u8 *p = a + n;
    if (p != b) {
      u32 tail = *(u32 *)(self + 4) - (u32)b + 1;
      G(memmove_t, 0x676278)(p, b, tail);
      *(u32 *)(self + 4) += (u32)(p - b);
    }
    return self;
  }
  u8 *p = c + room;
  ext_634d22(a, c, (u32)(p - c));
  ext_430d10(self, b, p, d);
  return self;
}
PCREG(5fd670, fn5fd670);
