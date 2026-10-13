// batch367.cpp - 0x410220 (gap band). cdecl(p): o = *p; returns (o[0x11] << 24) | (o[0x10] << 16) | (o[0xf] << 8) | o[0xe].
#include "ff.h"

static u32 packBytesE_to_11(u32 *p) {
  u8 *o = (u8 *)(unsigned long)p[0];
  return ((u32)o[0x11] << 24) | ((u32)o[0x10] << 16) | ((u32)o[0xf] << 8) | (u32)o[0xe];
}
PCREG(410220, packBytesE_to_11);
