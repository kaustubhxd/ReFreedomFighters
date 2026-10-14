// u69_62.cpp - area 69, group 62 (slice 8). A block copy (CMultiplayerStat::CopyData). No callees.
#include "ff.h"

// 0x56dcc0, CMultiplayerStat::CopyData(ZEventBase*) (GC map high). thiscall one stack arg (src, ret 4). Copies the 33 dwords at src+0x180..0x200 into
// self at the same offsets, then the dwords at +0x205, +0x209 and +0x20d.
static void THISCALL copyMultiplayerStat56dcc0(u8 *self, u8 *src) {
  for (u32 off = 0x180; off <= 0x200; off += 4)
    *(u32 *)(self + off) = *(u32 *)(src + off);
  *(u32 *)(self + 0x205) = *(u32 *)(src + 0x205);
  *(u32 *)(self + 0x209) = *(u32 *)(src + 0x209);
  *(u32 *)(self + 0x20d) = *(u32 *)(src + 0x20d);
}
PCREG(56dcc0, copyMultiplayerStat56dcc0);
