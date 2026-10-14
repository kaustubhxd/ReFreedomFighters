// batch37042.cpp - cascade s6 batch 37042: 0x4d79d0.
#include "ff.h"

extern "C" s32 STDCALL ext_62f120(u32 *z, u32 level, u32 ver, u32 size);   // deflateInit_, ret 0x10
extern "C" s32 STDCALL ext_62ebc0(u32 *z, u32 flush);                       // deflate, ret 8
extern "C" s32 STDCALL ext_62ee40(u32 *z);                                  // deflateEnd, ret 4
typedef u32(THISCALL *v3_t)(void *, u32, u32, u32);
typedef void(*cdl_t)(void *, ...);
#define F32(o) (*(u32 *)(self + (o)))

static void logErr(u32 msg) {
  void *L = *(void **)0x700390;
  (*(cdl_t **)L)[0x34 / 4](L, msg);
}

// 0x4d79d0, thiscall(hdr, data) ret 8: writes one entry's data to the stream at this+0x15 (handle this+0x11, slot 0x18 = write(buf, n, h)). hdr: +6 method (0 stored, 8
// deflate, anything else logs 0x6968f4), +0x10 compressed size accumulator, +0x14 source length. Stored: one write of hdr+0x14 bytes (short write logs 0x696858) and +0x10
// = +0x14. Deflate: z_stream on the stack, deflateInit_ (level this+0x1d, failure logs 0x696894) then deflate(Z_FINISH) in 16 KB blocks (the 2-byte zlib header dropped from the
// first one), each block written through the stream (a short write ends the stream and logs 0x6968c4), until deflate returns 1. Every error sets this+0x6e.
static void THISCALL fn4d79d0(u8 *self, u8 *hdr, u32 *data) {
  u32 z[14];
  u8 buf[0x4000];
  u32 skip = 2;
  u32 method = *(u16 *)(hdr + 6);
  if (method == 0) {
    void *S = *(void **)(self + 0x15);
    s32 n = (s32)(*(v3_t **)S)[0x18 / 4](S, (u32)data, *(u32 *)(hdr + 0x14), F32(0x11));
    if (n < (s32)*(u32 *)(hdr + 0x14)) {
      logErr(0x696858);
      *(u8 *)(self + 0x6e) = 1;
    }
    *(u32 *)(hdr + 0x10) = *(u32 *)(hdr + 0x14);
    return;
  }
  if (method != 8) {
    logErr(0x6968f4);
    *(u8 *)(self + 0x6e) = 1;
    return;
  }
  z[1] = *(u32 *)(hdr + 0x14);
  z[9] = 0;
  z[8] = 0;
  z[0] = (u32)data;
  if (ext_62f120(z, F32(0x1d), 0x69688c, 0x38)) {
    logErr(0x696894);
    *(u8 *)(self + 0x6e) = 1;
    return;
  }
  for (;;) {
    z[4] = 0x4000;
    z[3] = (u32)buf;
    s32 r = ext_62ebc0(z, 4);
    u32 n = 0x4000 - z[4] - skip;
    *(u32 *)(hdr + 0x10) += n;
    void *S = *(void **)(self + 0x15);
    u32 w = (*(v3_t **)S)[0x18 / 4](S, (u32)(buf + skip), n, F32(0x11));
    if (w != n) {
      ext_62ee40(z);
      logErr(0x6968c4);
      *(u8 *)(self + 0x6e) = 1;
    }
    skip = 0;
    if (r == 1) break;
  }
  ext_62ee40(z);
}
PCREG(4d79d0, fn4d79d0);
