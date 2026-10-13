// f16b028.cpp - fresh slice 16, batch 28 (2026-10-12).
// 0x6210c0 (cdecl parser, elem) expat setElementTypePrefix: for each ':' in the name *elem: copy the name up to it into the
//           temp pool at +0x1a8 (poolGrow 0x6206e0 when ptr == end; 0 -> return 0), add '\0'; prefix = lookup 0x61fd60(
//           +0x194 prefixes, pool start, 8) (0 -> return 0); prefix name is the pool string -> keep it (start = ptr), else
//           discard it (ptr = start); elem[1] = prefix. Keeps scanning after a ':' as the exe does. Returns 1.
// 0x638b80 (thiscall src, img): s = this slot 0x38(img); converter T (0x60 bytes): masks {0xff, 0xff00, 0xff0000,
//           0xff000000} at +0 and src masks +0x14..+0x20 at +0x30, prepared by 0x4d06a0(&T; &T) and 0x4d06a0(&T; &T+0x30)
//           (both run as exe code); rows of 8-bit indices from
//           s+0x10 + src[4] * s[4] + src[0] (row step s[4]) map through the palette [this+0x2d] with 0x639df0(&T; colour,
//           alpha byte src+0x28) (exe code) into src+0x2c (16-bit when src+0x24 == 16, else 32-bit; row step src+0x10).
//           Width src+8, height src+0xc. Ret 8. Cookie not reproduced.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_6206e0[], ext_61fd60[], ext_4d06a0[], ext_639df0[];

typedef int (*Grow)(void *);

extern "C" int f16_6210c0(u8 *ctx, u8 **elem) {
  u8 *b = elem[0];
  if (!*b) return 1;
  u8 ch = *b;
  for (;;) {
    if (ch == ':') {
      for (u8 *p = elem[0]; p != b; p++) {
        if (AT(u32, ctx, 0x1b4) == AT(u32, ctx, 0x1b0) && !((Grow)(void *)ext_6206e0)(ctx + 0x1a8)) return 0;
        *AT(u8 *, ctx, 0x1b4) = *p;
        AT(u32, ctx, 0x1b4)++;
      }
      if (AT(u32, ctx, 0x1b4) == AT(u32, ctx, 0x1b0) && !((Grow)(void *)ext_6206e0)(ctx + 0x1a8)) return 0;
      *AT(u8 *, ctx, 0x1b4) = 0;
      AT(u32, ctx, 0x1b4)++;
      u32 *r = ((u32 * (*)(void *, u32, u32))(void *)ext_61fd60)(ctx + 0x194, AT(u32, ctx, 0x1b8), 8);
      if (!r) return 0;
      if (*r == AT(u32, ctx, 0x1b8))
        AT(u32, ctx, 0x1b8) = AT(u32, ctx, 0x1b4);
      else
        AT(u32, ctx, 0x1b4) = AT(u32, ctx, 0x1b8);
      elem[1] = (u8 *)r;
    }
    ch = *++b;
    if (!ch) return 1;
  }
}

typedef void(THISCALL *Prep)(void *, const void *);
typedef u32(THISCALL *Conv)(void *, u32, u32);

extern "C" void THISCALL f16_638b80(u8 *self, u8 *src, u32 img) {
  u8 *s = vcall<u8 *>(self, 0x38, img);
  volatile u32 T[0x60 / 4];  // two 0x30-byte channel layouts: destination masks at +0, source masks at +0x30
  T[0] = 0xff;
  T[1] = 0xff00;
  T[2] = 0xff0000;
  T[3] = 0xff000000u;
  ((Prep)(void *)ext_4d06a0)((void *)T, (void *)T);
  T[12] = AT(u32, src, 0x14);
  T[13] = AT(u32, src, 0x18);
  T[14] = AT(u32, src, 0x1c);
  T[15] = AT(u32, src, 0x20);
  ((Prep)(void *)ext_4d06a0)((void *)T, (void *)(T + 12));
  u8 *row = (u8 *)(AT(u32, src, 4) * AT(u32, s, 4) + AT(u32, s, 0x10) + AT(u32, src, 0));
  u8 *dst = AT(u8 *, src, 0x2c);
  for (int y = 0; y < AT(int, src, 0xc); y++) {
    for (int x = 0; x < AT(int, src, 8); x++) {
      u32 c = ((Conv)(void *)ext_639df0)((void *)T, AT(u32 *, self, 0x2d)[row[x]], AT(u8, src, 0x28));
      if (AT(u32, src, 0x24) == 16)
        ((u16 *)dst)[x] = (u16)c;
      else
        ((u32 *)dst)[x] = c;
    }
    dst += AT(u32, src, 0x10);
    row += AT(u32, s, 4);
  }
}

PCREG(6210c0, f16_6210c0);
PCREG(638b80, f16_638b80);
