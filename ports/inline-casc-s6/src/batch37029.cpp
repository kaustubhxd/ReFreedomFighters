// batch37029.cpp - cascade s6 batch 37029: 0x4d7f70.
#include "ff.h"

extern "C" u8 *ext_41e290(u32 n);                                              // alloc, cdecl
extern "C" void ext_634273(u8 *p, u32 n);                                      // free, cdecl
extern "C" void ext_634d22(u8 *dst, u8 *src, u32 n);                           // memcpy thunk, cdecl
extern "C" s32 STDCALL ext_62f120(u32 *z, u32 level, u32 ver, u32 size);      // deflateInit_, ret 0x10
extern "C" s32 STDCALL ext_62ebc0(u32 *z, u32 flush);                          // deflate, ret 8
extern "C" s32 STDCALL ext_62ee40(u32 *z);                                     // deflateEnd, ret 4
typedef u32 (*hook_t)();
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef void(*cdl_t)(void *, ...);
#define F8(o) (*(u8 *)(self + (o)))
#define F32(o) (*(u32 *)(self + (o)))

// 0x4d7f70, thiscall(src, len, extbuf, cap) ret 0x10, returns 1 (0 when deflateInit fails after logging error 0x5ee): zlib-compresses len bytes at src into a buffer
// {u32 len, u32 total, u8 stored, deflate data...}. this: +0 byte (0 = buffer owned), +1 buffer, +5 compressed size, +9 src length, +0xd level, +0x11 stored flag.
// A previously owned buffer is freed first; extbuf (when non-null) is used instead of allocating len+9 bytes. The two-byte zlib header is dropped; when the output
// would exceed len the source is stored raw (flag 1; the assert hook runs if len+9 > cap).
static u32 THISCALL fn4d7f70(u8 *self, u8 *src, u32 len, u8 *extbuf, u32 cap) {
  u32 z[14];
  u8 buf[0x4000];
  if (F32(1)) {
    if (F8(0) == 0) ext_634273((u8 *)F32(1), 1);
    F32(1) = 0;
    F32(5) = 0;
    F32(9) = 0;
    F32(0x11) = 0;
  }
  F32(0x11) = 0;
  u32 skip = 2;
  F32(9) = len;
  F32(5) = 0;
  u8 *out;
  if (extbuf) {
    F8(0) = 1;
    out = extbuf;
  } else {
    cap = len + 9;
    out = ext_41e290(len + 9);
    F8(0) = 0;
  }
  F32(1) = (u32)out;
  *(u32 *)out = len;
  u32 outpos = 9;
  z[8] = 0;
  z[9] = 0;
  z[0] = (u32)src;
  z[1] = len;
  if (ext_62f120(z, F32(0xd), 0x69688c, 0x38)) {
    u8 *lg = *(u8 **)0x700390;
    void *L = (void *)(*(v2_t **)lg)[0x20 / 4](lg, 0x696924, 0x5ee);
    (*(cdl_t **)L)[0x2c / 4](L, 0x696b98);
    return 0;
  }
  for (;;) {
    z[4] = 0x4000;
    z[3] = (u32)buf;
    s32 r = ext_62ebc0(z, 4);
    u32 n = 0x4000 - z[4] - skip;
    F32(5) += n;
    if ((s32)F32(5) > (s32)len) {
      if (len + 9 > cap) {
        hook_t h = G(hook_t, 0x7003b0);
        if (!h) __asm__ volatile("int3");
        h();
      }
      ext_634d22((u8 *)(F32(1) + 9), src, len);
      F32(5) = len;
      F32(0x11) = 1;
      break;
    }
    ext_634d22((u8 *)(F32(1) + outpos), buf + skip, n);
    outpos += n;
    skip = 0;
    if (r == 1) break;
  }
  ext_62ee40(z);
  F32(5) += 9;
  *(u32 *)(F32(1) + 4) = F32(5);
  *(u8 *)(F32(1) + 8) = F8(0x11);
  return 1;
}
PCREG(4d7f70, fn4d7f70);
