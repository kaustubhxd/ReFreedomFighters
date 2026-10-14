// u69_31.cpp - area 69, group 31 (slice 8). No callees.
#include "ff.h"

// 0x5ac600, thiscall with four stack args (ret 0x10). Stores the args as unaligned dwords at self+9, self+0xd, self+0x11 and self+0x15.
static void THISCALL setFourAt9(u8 *self, u32 a, u32 b, u32 c, u32 d) {
  *(u32 *)(self + 9) = a;
  *(u32 *)(self + 0xd) = b;
  *(u32 *)(self + 0x11) = c;
  *(u32 *)(self + 0x15) = d;
}
PCREG(5ac600, setFourAt9);

// 0x4273c0, stdcall with two args (ret 8). Returns a | b with the low byte replaced by 1 when a | b is zero, else 0 (or, then sete al). The GC name ZSysFileGC::MaxNumSlots() does not match the body.
static u32 STDCALL orIsZero4273c0(u32 a, u32 b) {
  u32 t = a | b;
  return (t & ~0xffu) | (t == 0);
}
PCREG(4273c0, orIsZero4273c0);

// 0x6564c0, stdcall with two args (ret 8). It loads its first arg into ecx, so it is not thiscall. Copies dword src+0x10 to dst+0x10, dword src+0x14 to dst+0x14 and byte src+0xc to dst+0xc.
static void STDCALL copyLight6564c0(u8 *dst, u8 *src) {
  *(u32 *)(dst + 0x10) = *(u32 *)(src + 0x10);
  *(u32 *)(dst + 0x14) = *(u32 *)(src + 0x14);
  dst[0xc] = src[0xc];
}
PCREG(6564c0, copyLight6564c0);
