// batch35085.cpp - cascade s5 batch 35085: 0x61be80 (GUESS buffered stream write: copy n bytes in, or flush through the writer callback).
#include "ff.h"

extern "C" u8 *ext_61bd20(u8 *s, u32 n);                    // cdecl, two args: space for n bytes
extern "C" void ext_634d22(void *dst, const void *src, u32 n);   // cdecl memcpy
extern "C" u32 ext_61bf10(u8 *s, u32 n, u32 c);             // cdecl, three args
typedef s32 (*cb_t)(u8 *, u32, u32, u32);

// 0x61be80, cdecl(s, data, n, c), returns EAX. n != 0: p = 0x61bd20(s, n); memcpy(p, data, n); return 0x61bf10(s, n, c). n == 0: c == 0 gives 1; otherwise [s+0x28] = [s+0x1c], [s+0x120] = [s+0x18],
// r = [s+0x110](s, [s+0x18], [s+0x1c], 0) (cdecl callback), [s+0x114] = r; r == 0 gives 1; else [s+0x11c] = [s+0x118], [s+0x110] = 0x61f590 and 0.
static u32 fn61be80(u8 *s, u8 *data, u32 n, u32 c) {
  if (n != 0) {
    u8 *p = ext_61bd20(s, n);
    ext_634d22(p, data, n);
    return ext_61bf10(s, n, c);
  }
  if (c == 0) return 1;
  u32 a = *(u32 *)(s + 0x1c);
  u32 b = *(u32 *)(s + 0x18);
  *(u32 *)(s + 0x28) = a;
  *(u32 *)(s + 0x120) = b;
  s32 r = (*(cb_t *)(s + 0x110))(s, b, a, 0);
  *(u32 *)(s + 0x114) = (u32)r;
  if (r == 0) return 1;
  *(u32 *)(s + 0x11c) = *(u32 *)(s + 0x118);
  *(u32 *)(s + 0x110) = 0x61f590;
  return 0;
}
PCREG(61be80, fn61be80);
