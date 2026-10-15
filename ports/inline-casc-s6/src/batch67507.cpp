// batch67507.cpp - cascade s6 batch 67507: 0x61bd20.
#include "ff.h"

typedef void *(*memmove_t)(void *, const void *, u32);          // IAT 0x676278, cdecl
typedef void *(*alloc_t)(u32);                                  // cdecl, stored at +0xc
typedef void (*free_t)(void *);                                 // cdecl, stored at +0x14
extern "C" void *__attribute__((cdecl)) ext_634d22(void *dst, const void *src, u32 n);   // memcpy thunk

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x61bd20, cdecl(buf, n), returns the write pointer: growable byte buffer {+8 base, +0xc alloc, +0x14 free, +0x18 read pointer, +0x1c write pointer, +0x20 end, +0x114 failure flag}.
// Returns the write pointer at once when n bytes fit before the end. Otherwise, when compacting (moving the data back by up to all but 0x400 of the already-consumed bytes) makes it
// fit, the data is moved with memmove; else the buffer is reallocated (size = max(end - read, 0x400) doubled until it holds the data plus the kept 0x400 bytes of history; the failure flag is set
// and 0 returned when the allocator fails), the data copied, the old block freed and the pointers rebased.
static u32 fn61bd20(u8 *s, s32 n) {
  u32 end = D32(s, 0x20), cur = D32(s, 0x1c);
  if (n <= (s32)(end - cur)) return cur;
  u32 start = D32(s, 0x18);
  u32 used = cur - start;
  s32 ebx = (s32)(start - D32(s, 8));
  s32 keep = ebx > 0x400 ? 0x400 : ebx;
  s32 need = (s32)used + n + keep;
  if (need <= (s32)(end - D32(s, 8))) {
    if (keep >= ebx) return D32(s, 0x1c);
    u32 shift = (u32)(ebx - keep);
    u8 *base = *(u8 **)(s + 8);
    (*(memmove_t *)0x676278)(base, base + shift, used + keep);
    D32(s, 0x1c) -= shift;
    D32(s, 0x18) -= shift;
    return D32(s, 0x1c);
  }
  s32 sz = (s32)(end - start);
  if (sz == 0) sz = 0x400;
  do {
    sz += sz;
  } while (sz < need);
  u8 *nb = (u8 *)(*(alloc_t *)(s + 0xc))((u32)sz);
  if (!nb) {
    D32(s, 0x114) = 1;
    return 0;
  }
  D32(s, 0x20) = (u32)nb + sz;
  if (start) {
    s32 hist = (s32)(start - D32(s, 8));
    if (hist > 0x400) hist = 0x400;
    u32 len = (D32(s, 0x1c) - start) + hist;
    ext_634d22(nb, (u8 *)(start - hist), len);
    (*(free_t *)(s + 0x14))(*(void **)(s + 8));
    D32(s, 8) = (u32)nb;
    D32(s, 0x1c) += (u32)hist - start + (u32)nb;
    D32(s, 0x18) = (u32)nb + (u32)hist;
    return D32(s, 0x1c);
  }
  D32(s, 0x1c) += (u32)nb;
  D32(s, 0x18) = (u32)nb;
  D32(s, 8) = (u32)nb;
  return D32(s, 0x1c);
}
PCREG(61bd20, fn61bd20);
