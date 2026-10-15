#include "ff.h"

typedef u32 (*lookup_t)(u32 *, u32, u32, u32, u32);

// 0x4f6580, thiscall(a,b) ret 8: form the rotated/xored key, query the
// import at 0x676448, then return the matched record's second dword.
static u32 THISCALL fn4f6580(u8 *self, u32 a, u32 b) {
  u32 key = (a << 16) | (a >> 16);
  key ^= b;
  u8 *table = *(u8 **)(self + 0x97);
  lookup_t lookup = G(lookup_t, 0x676448);
  u32 *entry = (u32 *)lookup(&key, *(u32 *)(self + 0x9f), *(u32 *)(table + 0x10), 8, 0x4f9510);
  return entry ? entry[1] : 0;
}

PCREG(4f6580, fn4f6580);
