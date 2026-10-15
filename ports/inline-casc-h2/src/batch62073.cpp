#include "ff.h"

static u32 __attribute__((cdecl)) fn62c790(u8 *record, u32 value) {
  typedef u32 (*callback)(u32, u32);
  callback call = (callback)G(u32, record + 0x170);
  u32 code = call(G(u32, record + 0x174), value);
  if (code & 0xffff0000u) return 0;
  u32 page = code >> 8;
  u32 group = (code >> 5) & 7;
  u32 bit = code & 31;
  u32 base = G(u8, 0x6bfc20 + page);
  u32 mask = G(u32, 0x6bf720 + 4 * (group + base * 8));
  return mask & (1u << bit);
}

PCREG(62c790, fn62c790);
