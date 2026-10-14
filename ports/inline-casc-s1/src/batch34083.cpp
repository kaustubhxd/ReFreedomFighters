// batch34083.cpp - escalation batch 34083: event filters 0x62cc00 / 0x62d790 / 0x62d1b0, bit gather 0x530890, case-insensitive compare 0x62c5b0, MMX add 0x65a5d0.
#include "ff.h"

// 0x62cc00, cdecl(a, id): id 0xf returns 0; 0x15 sets [a] = 0x62cb80 and returns 0; 0x18 sets [a] = 0x62cd30 and returns 0; else when [a+0xc] is zero and id is 0x1c returns 0x34; else [a] = 0x51f230, returns -1.
static s32 fn62cc00(u32 *a, u32 id) {
  if (id == 0xf) return 0;
  if (id == 0x15) { a[0] = 0x62cb80; return 0; }
  if (id == 0x18) { a[0] = 0x62cd30; return 0; }
  if (a[3] == 0 && id == 0x1c) return 0x34;
  a[0] = 0x51f230;
  return -1;
}
PCREG(62cc00, fn62cc00);

// 0x62d790, cdecl(a, id): id 0xf returns 0; 0x12 sets [a] = 0x62d840 and returns 8; 0x16 sets [a] = 0x62d7f0 and returns 0; else when [a+0xc] is zero and id is 0x1c returns 0x34; else [a] = 0x51f230, returns -1.
static s32 fn62d790(u32 *a, u32 id) {
  if (id == 0xf) return 0;
  if (id == 0x12) { a[0] = 0x62d840; return 8; }
  if (id == 0x16) { a[0] = 0x62d7f0; return 0; }
  if (a[3] == 0 && id == 0x1c) return 0x34;
  a[0] = 0x51f230;
  return -1;
}
PCREG(62d790, fn62d790);

// 0x62d1b0, cdecl(a, id): id 0xf returns 0; 0x11 sets [a] = 0x62e120 and returns 7; 0x19 sets [a] = 0x62dc60 and returns 6; else when [a+0xc] is zero and id is 0x1c returns 0x34; else [a] = 0x51f230, returns -1.
static s32 fn62d1b0(u32 *a, u32 id) {
  if (id == 0xf) return 0;
  if (id == 0x11) { a[0] = 0x62e120; return 7; }
  if (id == 0x19) { a[0] = 0x62dc60; return 6; }
  if (a[3] == 0 && id == 0x1c) return 0x34;
  a[0] = 0x51f230;
  return -1;
}
PCREG(62d1b0, fn62d1b0);

// 0x530890, stdcall(bitmap, b, c) ret 0xc: bit i (0 <= i < c) of the result is bit number b + 64*i of the bitmap (signed index arithmetic); 0 when c <= 0.
static u32 STDCALL fn530890(u32 *bitmap, s32 b, s32 c) {
  u32 r = 0;
  s32 i = c - 1;
  if (i < 0) return 0;
  for (; i >= 0; i--) {
    s32 e = i * 64 + b;
    u32 bit = (u32)bitmap[e >> 5] & (1u << (e & 0x1f));
    r = (r << 1) | (bit ? 1 : 0);
  }
  return r;
}
PCREG(530890, fn530890);

// 0x62c5b0, cdecl(s1, s2), returns 1 when equal ignoring ASCII case, else 0 (stops at the terminator).
static u32 fn62c5b0(u8 *s1, u8 *s2) {
  for (;;) {
    u8 a = *s1++;
    u8 d = *s2++;
    if ((u8)(a - 0x61) <= 0x19) a += 0xe0;
    if ((u8)(d - 0x61) <= 0x19) d += 0xe0;
    if (a != d) return 0;
    if (a == 0) return 1;
  }
}
PCREG(62c5b0, fn62c5b0);

// 0x65a5d0, register ABI (ecx = dst, edx = src qword) plus one stack dword n, ret 4: for ((n + 3) >> 2) blocks of 32 bytes at dst: adds the four 16-bit lanes of *src (paddw) to each of the four qwords.
static void FASTCALL fn65a5d0(u16 *dst, u16 *src, u32 n) {
  u32 count = (n + 3) >> 2;
  u16 s0 = src[0], s1 = src[1], s2 = src[2], s3 = src[3];
  do {
    for (int j = 0; j < 4; j++) {
      dst[j * 4 + 0] += s0;
      dst[j * 4 + 1] += s1;
      dst[j * 4 + 2] += s2;
      dst[j * 4 + 3] += s3;
    }
    dst += 16;
    count--;
  } while (count != 0);
}
PCREG(65a5d0, fn65a5d0);
