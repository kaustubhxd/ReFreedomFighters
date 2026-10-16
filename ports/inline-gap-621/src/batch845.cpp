// batch845.cpp - gap band zlib gen_codes (docs/20-unclaimed-gap-621.md). Names are GUESS. /GS cookie not modelled.
#include "ff.h"

// 0x630bb0: cdecl(tree, max_code, bl_count) - zlib trees.c gen_codes: tree entries are {Code u16, Len u16}; next_code[bits] is built
// from bl_count (u16[16]) and each tree[n] with a nonzero Len gets the bit-reversed next code of that length
static void __attribute__((cdecl)) genCodes_630bb0(u16 *tree, s32 max_code, const u16 *bl_count) {
  u16 next_code[16];
  u16 code = 0;
  next_code[0] = 0;
  for (int bits = 1; bits <= 15; bits++) {
    code = (u16)((code + bl_count[bits - 1]) << 1);
    next_code[bits] = code;
  }
  for (s32 n = 0; n <= max_code; n++) {
    u32 len = tree[n * 2 + 1];
    if (!len) continue;
    u32 c = next_code[len]++;
    u32 res = 0;
    do {
      res |= c & 1;
      c >>= 1;
      res <<= 1;
      len--;
    } while ((s32)len > 0);
    tree[n * 2] = (u16)(res >> 1);
  }
}
PCREG(630bb0, genCodes_630bb0);

typedef u32 (__attribute__((cdecl)) *qcb2_t)(u8 *obj, u32 a, u32 b, u32 tag);

// 0x62d840: cdecl(out, code, a, b, obj) - sibling of queryHandler 0x62ce70: code 0xf returns 0; code 0x1b sets *out = 0x62cf90 and returns
// 10; code 0x12 asks obj[0x1c](obj, a, b, 0x6c0208) then (.., 0x6c01f4): a nonzero answer sets *out to 0x62d940 / 0x62d8f0 and
// returns 0; otherwise out[3] == 0 and code == 0x1c returns 0x34, else *out = 0x51f230 and returns -1
static u32 __attribute__((cdecl)) queryHandler2_62d840(u32 *out, u32 code, u32 a, u32 b, u8 *obj) {
  if (code == 0xf) return 0;
  if (code == 0x12) {
    if ((*(qcb2_t *)(obj + 0x1c))(obj, a, b, 0x6c0208)) {
      *out = 0x62d940;
      return 0;
    }
    if ((*(qcb2_t *)(obj + 0x1c))(obj, a, b, 0x6c01f4)) {
      *out = 0x62d8f0;
      return 0;
    }
  } else if (code == 0x1b) {
    *out = 0x62cf90;
    return code - 0x11;
  }
  if (out[3] == 0 && code == 0x1c) return code + 0x18;
  *out = 0x51f230;
  return 0xffffffffu;
}
PCREG(62d840, queryHandler2_62d840);

extern "C" u32 THISCALL ext_658e00(u8 *a, u32 *buf, u32 max);   // hooked (GUESS): fills buf, returns the count, ret 8
typedef void (THISCALL *vcur_t)(u8 *self, u32 arg);

// 0x63faa0: thiscall(a) ret 4 - gets up to 8 entries from 0x658e00(a, buf, 8); for each entry whose [0x54] owner p has flags
// (p[0xc][0x23], 0x200002 when p is null) with bit 0x100000: walks cur = p[8], calling this->vt[0x50](cur) then p->vt[0x50](&cur)
// until cur is 0. /GS cookie not modelled (0x633654 hooked in the spec).
static void THISCALL walkOwners_63faa0(u8 *self, u8 *a) {
  u32 buf[8];
  u32 n = ext_658e00(a, buf, 8);
  for (u32 i = 0; i != n && n != 0; i++) {
    u8 *item = (u8 *)buf[i];
    u8 *p = *(u8 **)(item + 0x54);
    u32 flags = p ? *(u32 *)(*(u8 **)(p + 0xc) + 0x23) : 0x200002;
    if (flags & 0x100000) {
      u32 cur = *(u32 *)(p + 8);
      if (cur) {
        do {
          (*(vcur_t *)(*(u8 **)self + 0x50))(self, cur);
          (*(vcur_t *)(*(u8 **)p + 0x50))(p, (u32)&cur);
        } while (cur != 0);
      }
    }
  }
}
PCREG(63faa0, walkOwners_63faa0);
