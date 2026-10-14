// batch32073.cpp - cascade h2 (): 0x57c910 (copy-assign: base copy + tail fields), 0x45b3a0 (init with memset).
#include "ff.h"

extern "C" void THISCALL ext_4cbee0(u8 *self, u8 *src);            // thiscall ret 4
extern "C" void THISCALL ext_43de40(u8 *self, u32 a, u32 b, u32 c); // thiscall ret 0xc
extern "C" void ext_634d10(void *p, u32 v, u32 n);                 // memset-style, cdecl

static inline void cp4(u8 *d, const u8 *s, u32 off) {
  for (int i = 0; i < 4; i++) d[off + i] = s[off + i];
}

// 0x57c910, thiscall(src) ret 4, returns this: 0x4cbee0(this, src), then copy [0x80..0xa0) dwords, byte 0xa0, dword 0xa1 (unaligned), bytes 0xa5 and 0xa6,
// unaligned dwords 0xa7, 0xab, 0xaf.
static u8 *THISCALL fn57c910(u8 *self, u8 *src) {
  ext_4cbee0(self, src);
  for (u32 o = 0x80; o < 0xa0; o += 4) *(u32 *)(self + o) = *(u32 *)(src + o);
  self[0xa0] = src[0xa0];
  cp4(self, src, 0xa1);
  self[0xa5] = src[0xa5];
  self[0xa6] = src[0xa6];
  cp4(self, src, 0xa7);
  cp4(self, src, 0xab);
  cp4(self, src, 0xaf);
  return self;
}
PCREG(57c910, fn57c910);

// 0x45b3a0, thiscall(a, b, c) ret 0xc, returns this: 0x43de40(this, a, b, c); constants; memset(this+0x8d8, 0, 0x80); interior pointers.
static u8 *THISCALL fn45b3a0(u8 *self, u32 a, u32 b, u32 c) {
  ext_43de40(self, a, b, c);
  *(u32 *)(self + 0x28) = 0x41000000;
  *(u32 *)(self + 0x2c) = 0x41200000;
  *(u32 *)(self + 0x38) = 0;
  *(u32 *)(self + 0x3c) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)(self + 0x34) = 0;
  *(u32 *)(self + 0x24) = 0;
  *(u32 *)self = 0x684580;
  ext_634d10(self + 0x8d8, 0, 0x80);
  *(u8 **)(self + 0x254) = self + 0x8d8;
  *(u8 **)(self + 0x40) = self + 0x258;
  *(u32 *)(self + 0x44) = 0xffffffff;
  *(u8 **)(self + 0x248) = self + 0x458;
  *(u8 **)(self + 0x24c) = self + 0x4d8;
  *(u8 **)(self + 0x250) = self + 0x6d8;
  *(u32 *)(self + 0x1c) = 0x80;
  *(u32 *)(self + 0x20) = 0x20;
  *(u32 *)(self + 0x18) = 0x60;
  return self;
}
PCREG(45b3a0, fn45b3a0);
