// batch5750.cpp - unclaimed-57, band batch 50 (name GUESS): 0x5d82a0, thiscall, one stack arg (a1), ret 4. src = 0x634d2e(a1, 0, 0x6f6df8,
// 0x6fac3c, 0) (cdecl, five args; unverified, hooked in the spec: returns a record pointer). Copies: word this+0x48, +0x4a, +0x4c from src;
// dwords this+0x4e .. +0x4e+0x64 (25 dwords) from src (rep movsd); byte this+0xb2 = src byte +0xb2; dword this+0xb3 = src dword +0xb3 unless the
// two addresses are equal; dword this+0xb7 = src dword +0xb7 unless equal; byte this+0xbb = src byte +0xbb; dword this+0xbc = src dword +0xbc.
#include "ff.h"

extern "C" u8 *ext_634d2e(u32 a1, u32 b, u32 c, u32 d, u32 e);  // cdecl, five args, unverified (hooked in the spec)

static void THISCALL unnamed5d82a0(u8 *self, u32 a1) {
  u8 *src = ext_634d2e(a1, 0, 0x6f6df8, 0x6fac3c, 0);
  *(u16 *)(self + 0x48) = *(u16 *)(src + 0x48);
  *(u16 *)(self + 0x4a) = *(u16 *)(src + 0x4a);
  *(u16 *)(self + 0x4c) = *(u16 *)(src + 0x4c);
  for (u32 k = 0; k < 25; k++) *(u32 *)(self + 0x4e + 4 * k) = *(u32 *)(src + 0x4e + 4 * k);
  self[0xb2] = src[0xb2];
  if (self + 0xb3 != src + 0xb3) *(u32 *)(self + 0xb3) = *(u32 *)(src + 0xb3);
  if (self + 0xb7 != src + 0xb7) *(u32 *)(self + 0xb7) = *(u32 *)(src + 0xb7);
  self[0xbb] = src[0xbb];
  *(u32 *)(self + 0xbc) = *(u32 *)(src + 0xbc);
}
PCREG(5d82a0, unnamed5d82a0);
