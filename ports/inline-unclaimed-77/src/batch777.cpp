// batch777.cpp - unclaimed-77 claim 7 (docs/20-unclaimed-77.md): two constant-returning leaves. Thiscall, no arguments, no callees.
#include "ff.h"

// 0x614f00, ZDrawArray<ZPrimInstDrawEntryGC, ZPrimInstDrawEntry, ZArrayBlock> entries count (medium): returns the constant 0x91.
static u32 THISCALL drawArrayPrimInstCount(u8 *self) {
  (void)self;
  return 0x91;
}
PCREG(614f00, drawArrayPrimInstCount);

// 0x64b140, ZDrawArray<ZGateViewEntry, ZGateViewEntry, ZArrayBlock> entries count (medium): returns the constant 0x34.
static u32 THISCALL drawArrayGateViewCount(u8 *self) {
  (void)self;
  return 0x34;
}
PCREG(64b140, drawArrayGateViewCount);
