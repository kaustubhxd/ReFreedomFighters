// batch210055.cpp - Sonnet-w3a: 0x4d7610 (copy or inflate a stored blob into a caller buffer)
#include "ff.h"

static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

extern "C" u32 ext_634d22(u32 dst, u32 src, u32 n);
extern "C" int STDCALL ext_62f9d0(u32 *z, int wbits, u32 ver, int size);
extern "C" int STDCALL ext_62f5d0(u32 *z, int flush);
extern "C" int STDCALL ext_62f980(u32 *z);

static u32 THISCALL fn4d7610(u8 *self, u32 a, int b) {
  u32 base = ld32(self + 1);
  if (ld32(self + 0x11) == 1) {  // @4d7610_a
    int n = b;
    if (n > (int)ld32(self + 9)) n = (int)ld32(self + 9);  // @4d7610_b
    ext_634d22(a, base + 9, (u32)n);  // @4d7610_c
    return 1;
  }
  u32 z[14];
  z[0] = base + 9;
  z[1] = ld32(self + 5);  // @4d7610_d
  z[8] = 0;  // @4d7610_z
  z[3] = a;
  z[4] = (u32)b;
  z[9] = 0;  // @4d7610_y
  if (ext_62f9d0(z, -15, 0x69688c, 0x38)) {  // @4d7610_e
    u8 *r = (u8 *)vcall<u32, u32, u32>(G(u8 *, 0x700390), 0x20, 0x696924, 0x626);  // @4d7610_f
    typedef u32 (*F)(u8 *, u32);
    (*(F *)(*(u8 **)r + 0x2c))(r, 0x696b98);  // @4d7610_g
    return 0;
  }
  int rc = ext_62f5d0(z, 4);  // @4d7610_h
  ext_62f980(z);
  if (rc == 1 || (rc == -5 && z[4] == 0)) return 1;  // @4d7610_i
  return 0;
}
PCREG(4d7610, fn4d7610);
