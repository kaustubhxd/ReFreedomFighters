// u69_49.cpp - area 69, group 49 (slice 8). Block copy, no callees. The original unrolls it: a 0x74-dword loop at each of five ranges, plus single dword moves at the range joins; together they cover offsets 8 .. 0x95c.
#include "ff.h"

// 0x56ed00, thiscall one stack arg (src, ret 4), returns this. Copies the dword at src+4, then every dword from src+8 up to src+0x960 (exclusive), into self at the same offsets. src and self must not overlap.
static u8 *THISCALL copyBlock56ed00(u8 *self, u8 *src) {
  *(u32 *)(self + 4) = *(u32 *)(src + 4);
  for (u32 off = 8; off < 0x960; off += 4)
    *(u32 *)(self + off) = *(u32 *)(src + off);
  return self;
}
PCREG(56ed00, copyBlock56ed00);
