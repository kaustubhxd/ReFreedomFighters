#include "ff.h"

extern "C" u32 THISCALL ext_5aa660(void *self, u32 p, u32 code, u32 a, u32 b);

// 0x574af0: thiscall(this, sel, p, flag(byte), a, b) ret 0x14: map sel (0..0x12) to a code, forward to 0x5aa660 on [this+0xf8]
u32 THISCALL fn_574af0(u8 *self, u32 sel, u32 p, u32 flag, u32 a, u32 b) {
  if (sel > 0x12) return sel;
  static const u8 map[19] = {0, 0, 0, 0, 1, 2, 2, 2, 2, 2, 3, 3, 3, 4, 5, 6, 7, 8, 9};
  u32 f = (u8)flag != 0;
  u32 code;
  switch (map[sel]) {
    case 0: code = f; break;
    case 1: code = 2; break;
    case 2: code = 6 + f; break;
    case 3: code = 4 + f; break;
    case 4: code = 3; break;
    case 5: code = 8; break;
    case 6: code = 0xa; break;
    case 7: code = 0xb; break;
    case 8: code = 9; break;
    default: code = 0xc; break;
  }
  return ext_5aa660(*(void **)(self + 0xf8), p, code, a, b);
}
PCREG(574af0, fn_574af0);

// 0x57f9b0: thiscall(this, u32 *bit, u8 *dst) ret 8: shifts *bit left until it hits the mask [this+0xa4],
// then copies a 0x29-byte block from this+0 / +0x29 / +0x52 to dst (bit 2, 4/8, 0x10)
u32 THISCALL fn_57f9b0(u8 *self, volatile u32 *bit, u8 *dst) {
  u32 v;
  do {
    *bit = *bit << 1;
    v = *bit;
  } while (!(*(u32 *)(self + 0xa4) & v));
  u32 i = v - 2;
  if (i > 0xe) return (u32)bit;
  static const u8 map[15] = {0, 3, 1, 3, 3, 3, 1, 3, 3, 3, 3, 3, 3, 3, 2};
  u32 off;
  switch (map[i]) {
    case 0: off = 0; break;
    case 1: off = 0x29; break;
    case 2: off = 0x52; break;
    default: return 3;
  }
  __builtin_memcpy(dst, self + off, 0x29);
  return self[off + 0x28];
}
PCREG(57f9b0, fn_57f9b0);
