// batch774.cpp - unclaimed-77 claim 4 (docs/20-unclaimed-77.md): two pure leaves, thiscall, no callees (names medium).
#include "ff.h"

// 0x4d7700, FsZip_t::useSecondaryArchive() (medium): stores byte 1 at this+0x21.
static void THISCALL fsZipUseSecondaryArchive(u8 *self) {
  self[0x21] = 1;
}
PCREG(4d7700, fsZipUseSecondaryArchive);

// 0x60d980, ZRenderGC::GetTexCon() const (medium): returns the dword at this+0x11a7.
static u32 THISCALL renderGCGetTexCon(u8 *self) {
  return *(u32 *)(self + 0x11a7);
}
PCREG(60d980, renderGCGetTexCon);
