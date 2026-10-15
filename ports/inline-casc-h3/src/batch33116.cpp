// batch33116.cpp - h3 (Sonnet) batch 33116: tier H float/SSE functions
#include "ff.h"

static inline u32 R32(u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

// 0x4a4f10: thiscall(s) ret 4, returns true: [this+4] &= ~0x40; s->slot 0x40(u16 [0x48]); slot 0x60(byte [0x5f], [0x60], [0x61], [0x62]); slot 0x54([0x56]); slot 0x4c([0x5a]); slot 0x60(byte [0x63]); slot 0x4c([0x4a]); slot 0x60(byte [0x64])
static u8 THISCALL fn4a4f10(u8 *self, u8 *s) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  vcall<u32>(s, 0x40, (u32)*(u16 *)(self + 0x48));
  vcall<u32>(s, 0x60, (u32)self[0x5f]);
  vcall<u32>(s, 0x60, (u32)self[0x60]);
  vcall<u32>(s, 0x60, (u32)self[0x61]);
  vcall<u32>(s, 0x60, (u32)self[0x62]);
  vcall<u32>(s, 0x54, R32(self + 0x56));
  vcall<u32>(s, 0x4c, R32(self + 0x5a));
  vcall<u32>(s, 0x60, (u32)self[0x63]);
  vcall<u32>(s, 0x4c, R32(self + 0x4a));
  vcall<u32>(s, 0x60, (u32)self[0x64]);
  return 1;
}
PCREG(4a4f10, fn4a4f10);

// 0x4b7890: thiscall(s) ret 4, returns true: [this+4] &= ~0x40; s->slot 0x44([0x48]); slot 0x54([0x50]); slot 0x4c([0x58], [0x5c]); slot 0x44([0x68], [0x6c]); slot 0x3c([0x8d]); slot 0x4c([0x60]); slot 0x44([0x64], [0x70], [0x74]); slot 0x3c([0x7c])
static u8 THISCALL fn4b7890(u8 *self, u8 *s) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  vcall<u32>(s, 0x44, R32(self + 0x48));
  vcall<u32>(s, 0x54, R32(self + 0x50));
  vcall<u32>(s, 0x4c, R32(self + 0x58));
  vcall<u32>(s, 0x4c, R32(self + 0x5c));
  vcall<u32>(s, 0x44, R32(self + 0x68));
  vcall<u32>(s, 0x44, R32(self + 0x6c));
  vcall<u32>(s, 0x3c, R32(self + 0x8d));
  vcall<u32>(s, 0x4c, R32(self + 0x60));
  vcall<u32>(s, 0x44, R32(self + 0x64));
  vcall<u32>(s, 0x44, R32(self + 0x70));
  vcall<u32>(s, 0x44, R32(self + 0x74));
  vcall<u32>(s, 0x3c, R32(self + 0x7c));
  return 1;
}
PCREG(4b7890, fn4b7890);

// 0x642050: thiscall no args: n=[this+0x21] (signed); n <= 0 -> 0; else the number of non-zero dwords among the first n of the array at [this+0x2d]
static u32 THISCALL fn642050(u8 *self) {
  s32 n = *(s32 *)(self + 0x21);
  if (n <= 0) return 0;
  u32 *arr = (u32 *)R32(self + 0x2d);
  u32 cnt = 0;
  for (s32 i = 0; i < n; i++)
    if (arr[i] != 0) cnt++;
  return cnt;
}
PCREG(642050, fn642050);
