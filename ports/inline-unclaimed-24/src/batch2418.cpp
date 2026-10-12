// batch2418.cpp - decomp area 24, batch 2418: two tail-jump forwarders that keep the caller's stack argument.
#include "ff.h"

extern "C" u32 THISCALL ext_4d0ee0(void *self, u32 flag);  // reads and clears the byte at +0x821b, ret 4
extern "C" u32 THISCALL ext_497450(void *self, u32 id);    // ZGeomBuffer::GeomRefToPtr(unsigned int), ret 4

// 0x41fa30 ZSysMemGC::GetReadOutBlock() const, thiscall, ret 4 (the argument belongs to the jump target).
static u32 THISCALL sysMemGCReadOutBlock(u8 *self, u32 flag) {
  return ext_4d0ee0(*(void **)(self + 0x31), flag);
}
PCREG(41fa30, sysMemGCReadOutBlock);

// 0x48ffb0 (GUESS owner), thiscall, ret 4.
static u32 THISCALL geomBufferForward(u8 *self, u32 id) {
  return ext_497450(*(void **)(self + 8), id);
}
PCREG(48ffb0, geomBufferForward);
