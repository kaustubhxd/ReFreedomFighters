// batch847.cpp - gap band zlib-style state allocation (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

extern "C" void __attribute__((cdecl)) ext_6322e0(u8 *s, u8 *z, u32 zero);   // hooked (GUESS): state reset

typedef u8 *(__attribute__((cdecl)) *zalloc_t)(u32 opaque, u32 items, u32 size);
typedef void (__attribute__((cdecl)) *zfree_t)(u32 opaque, u8 *ptr);

// 0x632230: cdecl(z, cb, n) - allocates a 0x40-byte state s through z[0x20](z[0x28], 1, 0x40), then s[0x24] (8 x 0x5a0 bytes) and
// s[0x28] (n bytes), freeing what it got through z[0x24] and returning 0 on any failure; sets s[0x2c] = s[0x28] + n, s[0] = 0,
// s[0x38] = cb, runs 0x6322e0(s, z, 0) and returns s
static u8 *__attribute__((cdecl)) stateNew_632230(u8 *z, u32 cb, u32 n) {
#define ZALLOC(it, sz) (*(zalloc_t *)(z + 0x20))(*(u32 *)(z + 0x28), (it), (sz))
#define ZFREE(p) (*(zfree_t *)(z + 0x24))(*(u32 *)(z + 0x28), (p))
  u8 *s = ZALLOC(1, 0x40);
  if (!s) return 0;
  u8 *w = ZALLOC(8, 0x5a0);
  *(u8 **)(s + 0x24) = w;
  if (!w) {
    ZFREE(s);
    return 0;
  }
  u8 *buf = ZALLOC(1, n);
  *(u8 **)(s + 0x28) = buf;
  if (!buf) {
    ZFREE(*(u8 **)(s + 0x24));
    ZFREE(s);
    return 0;
  }
  *(u32 *)s = 0;
  *(u32 *)(s + 0x2c) = (u32)buf + n;
  *(u32 *)(s + 0x38) = cb;
  ext_6322e0(s, z, 0);
  return s;
#undef ZALLOC
#undef ZFREE
}
PCREG(632230, stateNew_632230);
