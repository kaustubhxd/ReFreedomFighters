#include "ff.h"

static inline u32 rd32u(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }
static u8 THISCALL fn4c4e50(u8 *self, u8 *source) {
  *(u32 *)(self + 4) &= ~0x40u;
  vcall<void>(source, 0x58, (u32)(self + 0x65));
  vcall<void>(source, 0x68, (u32)(self + 0x69));
  vcall<void>(source, 0x70, rd32u(self + 0x6a));
  return 1;
}

PCREG(4c4e50, fn4c4e50);
