// batch1027.cpp - unclaimed-10, batch 23 (residue-10 list): ZParamAnim::CopyEventDataBlock(DBREAD&) (0x4a24a0), thiscall, one
// argument (the DBREAD), ret 4. Sets defaults (+0x51 = 0, +0x55 = -1.0, word +0x11c = 0x100, dword +0x11e = 25.0, byte +0x48 = 1).
// If the DBREAD's first dword is 0 it stops. Otherwise, with b = the byte at the buffer pointer: reader A (0x4e5e60) gives
// byte +0x11d; if (b != 0xff and (b & 0x3f) == 2) byte +0x11c = 0, else byte +0x11c = that same result and +0x11d is set again
// from reader A. Then float +0x11e = reader B (0x4e5e80), byte +0x48 = reader A != 0; if (b != 0xff and (b & 0x3f) == 0x0a) word
// +0x11a = reader C (0x4e5e40); if (b != 0xff and (b & 0x3f) == 2): +0x51 = reader B, v2 = reader B, +0x51 = +0x51 / K,
// +0x55 = v2 / K, where K is the float at 0x685270. Readers A, B, C are unverified and run as hooked original calls (ext_).
#include "ff.h"

#define G(T, addr) (*(T *)(addr))

extern "C" u32 THISCALL ext_4e5e60(u8 *dbread);   // reader A, hooked in the spec
extern "C" float THISCALL ext_4e5e80(u8 *dbread); // reader B (float in st0), hooked in the spec
extern "C" u32 THISCALL ext_4e5e40(u8 *dbread);   // reader C, hooked in the spec

// 0x4a24a0, ZParamAnim::CopyEventDataBlock(DBREAD&) (vtable, high)
static void THISCALL paramAnimCopyEventDataBlock(u8 *self, u8 *dbread) {
  *(u32 *)(self + 0x51) = 0;
  *(u32 *)(self + 0x55) = 0xbf800000u;
  *(u16 *)(self + 0x11c) = 0x100;
  *(u32 *)(self + 0x11e) = 0x41c80000u;
  self[0x48] = 1;
  if (*(u32 *)dbread == 0) return;
  u8 *buf = *(u8 **)dbread;
  u8 cl = ext_4e5e60(dbread) != 0;
  self[0x11d] = cl;
  u8 b = buf[0];
  if (b != 0xff && (b & 0x3f) == 2) {
    self[0x11c] = 0;
  } else {
    self[0x11c] = cl;
    self[0x11d] = ext_4e5e60(dbread) != 0;
  }
  *(float *)(self + 0x11e) = ext_4e5e80(dbread);
  self[0x48] = ext_4e5e60(dbread) != 0;
  b = buf[0];
  if (b != 0xff && (b & 0x3f) == 0xa) *(u16 *)(self + 0x11a) = (u16)ext_4e5e40(dbread);
  b = buf[0];
  if (b != 0xff && (b & 0x3f) == 2) {
    *(float *)(self + 0x51) = ext_4e5e80(dbread);
    float v2 = ext_4e5e80(dbread);
    *(float *)(self + 0x51) = *(float *)(self + 0x51) / G(float, 0x685270);
    *(float *)(self + 0x55) = v2 / G(float, 0x685270);
  }
}
PCREG(4a24a0, paramAnimCopyEventDataBlock);
