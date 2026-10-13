// f16b014.cpp - fresh slice 16, batch 14 (2026-10-12).
// 0x633e05 ___scrt_is_nonwritable_in_current_image(p) (CRT, cdecl): image 0x400000 has MZ, PE and optional magic 0x10b ->
//           s = find_pe_section 0x633cbc(0x400000, p - 0x400000); true when s and s+0x24 (characteristics) >= 0 (not
//           writable). SEH4 frame not reproduced.
// 0x616580 constructor (a, ge, ctx): +4 = a, vtable 0x6bdc58, +8..+0x10 = 0; 0x659330(this+8; u16 [[ge+0x10]+8]+0xe,
//           [ctx+0xb9a8]) (ret 8); [[ge+0xc]+0x38]+0x3c |= 0x1000000. Returns this. Ret 0xc. SEH not reproduced.
// 0x629a40 (expat, cdecl enc, ptr, end, next): two-byte little-endian chars; type = hi == 0 ? enc[0x4c + lo] :
//           0x62c640(hi, lo). The first char must have type 0x18 or 0x19; following chars: 0x12 -> *next = after it, 10;
//           0x18/0x19 continue; anything else -> *next = that char, 0. End reached -> -1.
// 0x448000 (fastcall a, b; c, d): p = d ? 0x45c4f0(0x20, d) : 0x45c4b0(0x20) (cdecl); p -> 0x447580(p; c, a, b) (ret 0xc),
//           its result; else 0. Ret 8. SEH not reproduced.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_633cbc[], ext_659330[], ext_62c640[], ext_45c4f0[], ext_45c4b0[], ext_447580[];

extern "C" bool f16_633e05(u32 p) {
  if (G(u16, 0x400000) != 0x5a4d) return false;
  u32 pe = G(u32, 0x40003c);
  if (G(u32, pe + 0x400000) != 0x4550) return false;
  if (G(u16, pe + 0x400018) != 0x10b) return false;
  u8 *s = ((u8 * (*)(u32, u32))(void *)ext_633cbc)(0x400000, p - 0x400000);
  if (!s) return false;
  return AT(s32, s, 0x24) >= 0;
}

extern "C" void *THISCALL f16_616580(u32 *self, u32 a, u8 *ge, u8 *ctx) {
  self[1] = a;
  self[0] = 0x6bdc58u;
  self[2] = 0;
  self[3] = 0;
  self[4] = 0;
  u32 k = AT(u16, AT(u8 *, AT(u8 *, ge, 0x10), 8), 0xe);
  ((void(THISCALL *)(void *, u32, u32))(void *)ext_659330)(self + 2, k, AT(u32, ctx, 0xb9a8));
  AT(u32, AT(u8 *, AT(u8 *, ge, 0xc), 0x38), 0x3c) |= 0x1000000u;
  return self;
}

static inline u32 type629(u8 *enc, const u8 *c) {
  u8 hi = c[1], lo = c[0];
  if (hi == 0) return enc[0x4c + lo];
  return ((u32(*)(u32, u32))(void *)ext_62c640)(hi, lo);
}

extern "C" s32 f16_629a40(u8 *enc, const u8 *p, const u8 *end, const u8 **next) {
  if (p == end) return -1;
  u32 t = type629(enc, p);
  if (t - 0x18 > 1) {
    *next = p;
    return 0;
  }
  for (p += 2; p != end; p += 2) {
    t = type629(enc, p);
    if (t == 0x12) {
      *next = p + 2;
      return 10;
    }
    if (t - 0x18 > 1) {
      *next = p;
      return 0;
    }
  }
  return -1;
}

extern "C" u32 FASTCALL f16_448000(u32 a, u32 b, u32 c, u32 d) {
  void *p = d ? ((void *(*)(u32, u32))(void *)ext_45c4f0)(0x20, d) : ((void *(*)(u32))(void *)ext_45c4b0)(0x20);
  if (!p) return 0;
  return ((u32(THISCALL *)(void *, u32, u32, u32))(void *)ext_447580)(p, c, a, b);
}

PCREG(633e05, f16_633e05);
PCREG(616580, f16_616580);
PCREG(629a40, f16_629a40);
PCREG(448000, f16_448000);
