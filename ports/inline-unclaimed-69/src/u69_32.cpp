// u69_32.cpp - area 69, group 32 (slice 8). No callees.
#include "ff.h"

// 0x548ec0, CShatter::CopyData(ZEventBase*) (GC map high). thiscall, one stack arg (ret 4). Copies four dwords at src+0x4c..0x58 to self+0x4c..0x58.
static void THISCALL copyCShatterFields(u8 *self, u8 *src) {
  for (u32 i = 0; i < 4; ++i)
    *(u32 *)(self + 0x4c + 4 * i) = *(u32 *)(src + 0x4c + 4 * i);
}
PCREG(548ec0, copyCShatterFields);

static void copy16(u8 *dst, const u8 *src) {
  for (u32 i = 0; i < 4; ++i)
    *(u32 *)(dst + 4 * i) = *(u32 *)(src + 4 * i);
}

// 0x5a83c0, ZOnScreenDisplay::GetStats() (GC map high), thiscall, one stack arg (the output pointer, ret 4). Copies 16 bytes from self+0x8af to out and 16 bytes from self+0x8bf to out+0x10.
static void THISCALL copyStatsOut5a83c0(u8 *self, u8 *out) {
  copy16(out, self + 0x8af);
  copy16(out + 0x10, self + 0x8bf);
}
PCREG(5a83c0, copyStatsOut5a83c0);
