// batch34074.cpp - escalation batch 34074: 0x471a70 and 0x4e54a0.
#include "ff.h"

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x471a70, stdcall(a) ret 4, bool: a non-null and the unaligned dword at [a+0xc]+0x23 equals 0x1007d9.
static bool STDCALL fn471a70(u8 *a) {
  if (!a) return false;
  return rd32(*(u8 **)(a + 0xc) + 0x23) == 0x1007d9;
}
PCREG(471a70, fn471a70);

// 0x4e54a0, thiscall(a) ret 4: d = [a+0x48]; 0 when d is negative, else [this+0xc] + d.
static u32 THISCALL fn4e54a0(u8 *self, u8 *a) {
  s32 d = *(s32 *)(a + 0x48);
  if (d < 0) return 0;
  return *(u32 *)(self + 0xc) + (u32)d;
}
PCREG(4e54a0, fn4e54a0);
