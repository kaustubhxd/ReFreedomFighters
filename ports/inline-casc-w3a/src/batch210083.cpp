// batch210083.cpp - Sonnet-w3a: 0x4618c0 (report a message with the text cut at '#', through the handler objects; /GS)
#include "ff.h"

extern "C" void FASTCALL ext_633654(u32 cookie);

typedef u8 *(*StrChr)(u8 *s, int c);
typedef u32 (*F5)(u8 *, u32, u32, u32, u8 *);

static u32 THISCALL fn4618c0(u8 *self, const u8 *str, u32 unused) {
  u8 buf[0x3e8];
  (void)unused;
  u32 i = 0;
  do { buf[i] = str[i]; } while (str[i++]);  // @4618c0_a
  u8 *p = G(StrChr, 0x676254)(buf, 0x23);  // @4618c0_b
  if (p) *p = 0;  // @4618c0_c
  u8 *r = (u8 *)vcall<u32, u32, u32>(G(u8 *, 0x700390), 0x20, 0x685834, 0x236);  // @4618c0_d
  u8 *o = (u8 *)vcall<u32>(self, 0x20);  // @4618c0_e
  u32 a = *(u32 *)(o + 4);
  u32 b = *(u32 *)(self + 4);
  u32 ea = a ? a : 0x67c8e8;  // @4618c0_f
  u32 eb = b ? b : 0x67c8e8;  // @4618c0_g
  (*(F5 *)(*(u8 **)r + 0x2c))(r, 0x6858b0, eb, ea, buf);  // @4618c0_h
  ext_633654(0);
  return 0;
}
PCREG(4618c0, fn4618c0);
