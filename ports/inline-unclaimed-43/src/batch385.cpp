// batch385.cpp - 0x410340 (gap band). cdecl, one argument p (struct pointer). Table-driven CRC-style pass: crc starts at 0;
// for each byte of buf0 (length p[4]) crc = (crc << 8) ^ T[byte ^ (crc >> 24)], then the same over buf1 (length p[0xc]).
// The four bytes of the result go to buf0 at +0x16..+0x19, low byte first. Table T is the exe dword table at 0x6f242c.
// The four zero stores happen before the loop, so the loop reads the buffer after them (matching the exe order).
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

static u32 crcStep(u32 crc, u8 b) {
  return (crc << 8) ^ G(u32, 0x6f242c + 4 * (u32)(b ^ (crc >> 24)));
}

static void crcFields(u8 *p) {
  u8 *b0 = *(u8 **)p;
  b0[0x16] = 0;
  b0[0x17] = 0;
  b0[0x18] = 0;
  b0[0x19] = 0;
  u32 crc = 0;
  s32 n1 = (s32)U32(p, 0x4);
  for (s32 i = 0; i < n1; i++) crc = crcStep(crc, b0[i]);
  u8 *b1 = *(u8 **)(p + 0x8);
  s32 n2 = (s32)U32(p, 0xc);
  for (s32 j = 0; j < n2; j++) crc = crcStep(crc, b1[j]);
  b0[0x16] = (u8)(crc & 0xff);
  b0[0x17] = (u8)((crc >> 8) & 0xff);
  b0[0x18] = (u8)((crc >> 16) & 0xff);
  b0[0x19] = (u8)(crc >> 24);
}
PCREG(410340, crcFields);
