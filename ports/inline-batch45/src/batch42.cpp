// batch42.cpp - walk-tree clean leaves, inline session batch 42 (Haiku, night): 0x439570, 0x5a7500, 0x5acac0, 0x589c20.
#include "ff.h"

// 0x439570, stdcall, one dword stack arg, ret 4 (the caller's ecx is not read). Global table at 0x6e48c0: 16-byte entries
// {ptr, size, ...}, ended by an entry whose first dword is zero. The segment size is entry 0's +4 for every step. The
// loop finds the first entry whose range (arg - ecx) is below the size; the result is dword ptr[3 * rem] of that entry,
// where rem = arg - ecx. If the table runs out, the result is 0. Only the first dword of the table is checked up front.
static u32 STDCALL lookupTable(u32 arg) {
  u32 cum = 0;
  u32 idx = 0;
  if (G(u32, 0x6e48c0u) == 0)
    return 0;
  u32 size = G(u32, 0x6e48c4u);
  for (;;) {
    u32 rem = arg - cum;
    if ((s32)rem < (s32)size) {
      u32 base = G(u32, 0x6e48c0u + idx * 16u);
      return G(u32, base + 4u * (3u * rem));
    }
    idx++;
    cum += size;
    if (G(u32, 0x6e48c0u + idx * 16u) == 0)
      return 0;
  }
}
PCREG(439570, lookupTable);

// 0x5a7500, thiscall, two float stack args, ret 8. Stores the first at this+0x358 and the second at this+0x35c.
static void THISCALL setTwoFloats358(u8 *self, float a, float b) {
  *(float *)(self + 0x358) = a;
  *(float *)(self + 0x35c) = b;
}
PCREG(5a7500, setTwoFloats358);

// 0x5acac0, thiscall, one byte stack arg (low byte read), ret 4. Stores it at this+8.
static void THISCALL setByte8(u8 *self, u32 arg) {
  *(u8 *)(self + 8) = (u8)(arg & 0xffu);
}
PCREG(5acac0, setByte8);

// 0x589c20, ZFFGameData::GetGameOSD(char), thiscall, one byte stack arg (sign-extended), ret 4. Returns the dword at
// this + 0x2c2d + 4 * c.
static u32 THISCALL getGameOSD(u8 *self, u32 arg) {
  s32 c = (s32)(s8)(arg & 0xffu);
  return *(u32 *)((u32)self + 0x2c2du + (u32)(c * 4));
}
PCREG(589c20, getGameOSD);
