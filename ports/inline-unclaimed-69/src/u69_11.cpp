// u69_11.cpp - area 69, group 11 (unclaimed-69 thread).
#include "ff.h"

// 0x41e710, ZSysMem::CreateRef(void* p) (GC map medium). thiscall, one stack arg (ret 4); returns p. The result of slot 0xd0
// (called with p) is stored at p-4. When the dword at p-8 is negative (signed), p-0x10 gets the XOR of the words at p-8, p-0xc,
// p-0x14, p-0x18, p-0x1c and p-0x20, or 1 when that XOR is zero.
static u8 *THISCALL sysMemCreateRef(u8 *self, u8 *p) {
  u32 result = vcall<u32>(self, 0xd0, (void *)p);
  *(u32 *)(p - 4) = result;
  if ((s32)*(u32 *)(p - 8) < 0) {
    u32 x = *(u32 *)(p - 8) ^ *(u32 *)(p - 0xc) ^ *(u32 *)(p - 0x14) ^ *(u32 *)(p - 0x18) ^ *(u32 *)(p - 0x1c) ^
            *(u32 *)(p - 0x20);
    *(u32 *)(p - 0x10) = (x == 0) ? 1u : x;
  }
  return p;
}
PCREG(41e710, sysMemCreateRef);
