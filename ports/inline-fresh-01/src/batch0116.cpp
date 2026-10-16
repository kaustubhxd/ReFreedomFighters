// batch0116.cpp - fresh-01 batch 16 (docs/20-fresh-01.md).
#include "ff.h"

extern "C" void *ext_634d22(void *d, const void *s, u32 n);          // memcpy thunk
extern "C" s32 STDCALL ext_62f9d0(void *z, s32 bits, const char *ver, s32 size);  // inflateInit2_
extern "C" s32 STDCALL ext_62f5d0(void *z, s32 flush);               // inflate
extern "C" s32 STDCALL ext_62f980(void *z);                          // inflateEnd
extern "C" void THISCALL ext_563710(u8 *self, u32 button, const char *text);  // CBaseWindow::SetTextOnButton(ZBUTTON*)
extern "C" void FASTCALL ext_633654(u32 cookie);                     // __security_check_cookie

typedef void (*log1Fn)(void *, u32);
typedef s32 (*fmt6Fn)(void *, char *, u32, u32, u32, u32);

static u8 *render() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

// 0x4d7610, ZPackedDataChunk::unzip(void*, int): stored chunks (+0x11 == 1) copy min(size, +9) (signed) bytes from
// [+1]+9 and return 1. Else a zlib stream (next_in = [+1]+9, avail_in = +5, next_out/avail_out = the arguments,
// zalloc = zfree = 0) is opened with inflateInit2_(-15, "1.2.x" at 0x69688c, 0x38); failure logs
// 0x696924:0x626 and returns 0. Then inflate(Z_FINISH), inflateEnd; 1 on Z_STREAM_END, or Z_BUF_ERROR with the
// output full.
struct ZStream {
  u32 next_in, avail_in, total_in, next_out, avail_out, total_out, msg, state, zalloc, zfree, opaque, data_type, adler,
      reserved;
};
static u8 THISCALL packedChunkUnzip(u8 *self, void *dst, s32 size) {
  u32 src = *(u32 *)(self + 1);
  if (*(u32 *)(self + 0x11) == 1) {
    s32 n = size;
    if (n > *(s32 *)(self + 9)) n = *(s32 *)(self + 9);
    ext_634d22(dst, (void *)(src + 9), n);
    return 1;
  }
  ZStream z;
  z.next_in = src + 9;
  z.avail_in = *(u32 *)(self + 5);
  z.next_out = (u32)dst;
  z.avail_out = size;
  z.zalloc = 0;
  z.zfree = 0;
  if (ext_62f9d0(&z, -15, (const char *)0x69688c, 0x38)) {
    u8 *lg = vcall<u8 *>(G(u8 *, 0x700390), 0x20, 0x696924u, 0x626u);
    (*(log1Fn *)(*(u8 **)lg + 0x2c))(lg, 0x696b98);
    return 0;
  }
  s32 r = ext_62f5d0(&z, 4);
  ext_62f980(&z);
  if (r == 1) return 1;
  if (r == -5 && z.avail_out == 0) return 1;
  return 0;
}
PCREG(4d7610, packedChunkUnzip);

// 0x56d750, CMultiplayerKOTH::UpdateAmountButton(): s1 = text(0x6a6760, 0x6a8070), s2 = text(0x6a67e8, 0x6a8078);
// fmt slot 0x198 (cdecl: fmt, buf, 0x6a8084, s2, 3 * +0x1b6, s1); a negative result logs 0x6a8040:0xfc;
// SetTextOnButton(+0x180, buf). /GS cookie.
static void THISCALL kothUpdateAmountButton(u8 *self) {
  char buf[0x100];
  u8 *fmt = vcall<u8 *>(G(u8 *, 0x70039c), 0x190);
  u8 *loc = *(u8 **)(render() + 0xae4);
  u32 s1 = vcall<u32>(loc, 0, 0x6a6760u, 0x6a8070u);
  u32 n3 = *(u32 *)(self + 0x1b6) * 3;
  u32 s2 = vcall<u32>(loc, 0, 0x6a67e8u, 0x6a8078u);
  if ((*(fmt6Fn *)(*(u8 **)fmt + 0x198))(fmt, buf, 0x6a8084, s2, n3, s1) < 0) {
    u8 *lg = vcall<u8 *>(G(u8 *, 0x700390), 0x20, 0x6a8040u, 0xfcu);
    (*(log1Fn *)(*(u8 **)lg + 0x2c))(lg, 0x6a8090);
  }
  ext_563710(self, *(u32 *)(self + 0x180), buf);
  ext_633654(G(u32, 0x6f5630));
}
PCREG(56d750, kothUpdateAmountButton);

// 0x4def50, qmul(float*, const float*, const float*) (ecx = out, edx = a, stack b): quaternion product (x, y, z, w),
// single precision in the exe's operation order; out is written component by component (may alias a or b).
static void FASTCALL qmul4def50(float *o, const float *a, const float *b) {
  o[0] = ((a[3] * b[0] + a[0] * b[3]) + b[2] * a[1]) - b[1] * a[2];
  o[1] = ((a[3] * b[1] - b[2] * a[0]) + a[1] * b[3]) + a[2] * b[0];
  o[2] = ((a[3] * b[2] + b[1] * a[0]) - a[1] * b[0]) + a[2] * b[3];
  o[3] = ((a[3] * b[3] - a[0] * b[0]) - b[1] * a[1]) - b[2] * a[2];
}
PCREG(4def50, qmul4def50);
