// batch32072.cpp - cascade h2 (): 0x65f4d0 (create a record and copy a 9-dword block + vector), 0x4d4f70 (copy out of a record payload).
#include "ff.h"

extern "C" u8 *THISCALL ext_64b2f0(u8 *self, u32 a, u32 c, u32 d);   // thiscall ret 0xc
extern "C" void FASTCALL ext_4de420(void *dst, const void *src);      // 36-byte copy (verified)
extern "C" u8 *STDCALL ext_4d4de0(u32 a);                             // stdcall ret 4
extern "C" void ext_634d22(void *dst, const void *src, u32 n);        // memcpy-style, cdecl

// 0x65f4d0, thiscall(a, p, blk, vec, c, d) ret 0x18: *p == 0 -> 0; r = 0x64b2f0([this+0xc], a, c, d); r == 0 -> 0;
// copy 9 dwords blk -> [r+0xc]; [r+0x1c] = p; 3 dwords vec -> [[r+0xc]+0x24]; return r.
static u8 *THISCALL fn65f4d0(u8 *self, u32 a, u32 *p, void *blk, u32 *vec, u32 c, u32 d) {
  if (*p == 0) return 0;
  u8 *r = ext_64b2f0(*(u8 **)(self + 0xc), a, c, d);
  if (!r) return 0;
  ext_4de420(*(u8 **)(r + 0xc), blk);
  *(u32 **)(r + 0x1c) = p;
  u8 *e = *(u8 **)(r + 0xc);
  *(u32 *)(e + 0x24) = vec[0];
  *(u32 *)(e + 0x28) = vec[1];
  *(u32 *)(e + 0x2c) = vec[2];
  return r;
}
PCREG(65f4d0, fn65f4d0);

// 0x4d4f70, stdcall(a, dst, n, off) ret 0x10, returns n: x = 0x4d4de0(a), none -> -1; flags = [x+4]; payload record q =
// (flags < 0) ? ((flags & 0x40000000) ? x + ([x+0x10]+5)*4 : x + 0x10) : null; skip = ([q+4] & 0xc0000000) != 0 ? [q+8] : 8;
// memcpy(dst, x-relative q + skip + off, n).
static int STDCALL fn4d4f70(u32 a, void *dst, u32 n, u32 off) {
  u8 *x = ext_4d4de0(a);
  if (!x) return -1;
  int flags = *(int *)(x + 4);
  u8 *q;
  if (flags < 0) {
    if (flags & 0x40000000) q = x + (*(u32 *)(x + 0x10) + 5) * 4;
    else q = x + 0x10;
  } else {
    q = 0;
  }
  u32 k = *(u32 *)(q + 4) & 0xc0000000;
  u32 skip = 8;
  if (k == 0x40000000 || k == 0x80000000 || k == 0xc0000000) skip = *(u32 *)(q + 8);
  ext_634d22(dst, q + skip + off, n);
  return n;
}
PCREG(4d4f70, fn4d4f70);
