// batch843.cpp - gap band zlib inflate helper (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

extern "C" void __attribute__((cdecl)) ext_633170(u32 a, u8 *z);   // hooked (GUESS)

typedef void (__attribute__((cdecl)) *zfree_t)(u32 opaque, u32 ptr);
typedef u32 (STDCALL *cb3_t)(u32 a, u32 b, u32 c);

// 0x6321a0: cdecl(state, z) - zlib inflateReset-like teardown: frees the window for modes 4 and 5 (state[0xc]), runs 0x633170 for
// mode 6, resets the state counters, calls the checksum init stdcall callback state[0x38](0, 0, 0) when set (result to state[0x3c] and
// z[0x30]), then frees state[0x28], state[0x24] and the state itself through z[0x24](z[0x28], ptr); returns 0
static u32 __attribute__((cdecl)) stateEnd_6321a0(u8 *s, u8 *z) {
#define ZFREE(p) (*(zfree_t *)(z + 0x24))(*(u32 *)(z + 0x28), (u32)(p))
  u32 mode = *(u32 *)s;
  if (mode == 4 || mode == 5) ZFREE(*(u32 *)(s + 0xc));
  if (*(u32 *)s == 6) ext_633170(*(u32 *)(s + 4), z);
  u32 w = *(u32 *)(s + 0x28);
  *(u32 *)(s + 0x34) = w;
  *(u32 *)(s + 0x30) = w;
  cb3_t cb = *(cb3_t *)(s + 0x38);
  *(u32 *)s = 0;
  *(u32 *)(s + 0x1c) = 0;
  *(u32 *)(s + 0x20) = 0;
  if (cb) {
    u32 r = cb(0, 0, 0);
    *(u32 *)(s + 0x3c) = r;
    *(u32 *)(z + 0x30) = r;
  }
  ZFREE(*(u32 *)(s + 0x28));
  ZFREE(*(u32 *)(s + 0x24));
  ZFREE(s);
#undef ZFREE
  return 0;
}
PCREG(6321a0, stateEnd_6321a0);
