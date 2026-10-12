// batch2437.cpp - decomp area 24, batch 2437 (slice 11 leaves).
#include "ff.h"

// 0x41f0b0 ZSysMemGC::GetNrAllocs(node*), thiscall, ret 4: pushes the node onto the list at +0x2c.
static void THISCALL sysMemGCGetNrAllocs(u8 *self, u8 *node) {
  *(u32 *)(node + 4) = *(u32 *)(self + 0x2c);
  *(u8 **)(self + 0x2c) = node;
}
PCREG(41f0b0, sysMemGCGetNrAllocs);

// 0x4d5130 IOFSMemoryAccess_t::nativeFdValid(ImpNativeFd_t*), thiscall, ret 4, eax.
static u32 THISCALL nativeFdValid(u8 *self, u8 *fd) {
  return (fd == self + 4) ? 1u : 0u;
}
PCREG(4d5130, nativeFdValid);

// 0x5f33f0 ZScriptDll::setOpaqueCallPrice(int), thiscall, ret 4.
static void THISCALL scriptDllSetOpaqueCallPrice(u8 *self, s32 v) {
  u8 *o2 = *(u8 **)(self + 0xc);
  u8 *o3 = *(u8 **)(o2 + 4);
  *(s32 *)(o3 + 0x34) = v;
}
PCREG(5f33f0, scriptDllSetOpaqueCallPrice);

// 0x425af0 ZSysComGC::SetFileAndLine(char*, int), thiscall, ret 8, eax = this.
static u8 *THISCALL sysComGCSetFileAndLine(u8 *self, char *file, s32 line) {
  *(char **)(self + 0x18) = file;
  *(s32 *)(self + 0x1c) = line;
  return self;
}
PCREG(425af0, sysComGCSetFileAndLine);

// 0x4930f0 (GUESS owner), thiscall, plain ret.
static void THISCALL flagClearAndReset(u8 *self) {
  if (self[0xbc2] != 0) {
    self[0xbc2] = 0;
    u8 *o = *(u8 **)(self + 8);
    if (o)
      *(u32 *)(o + 0x24) = 0;
  }
}
PCREG(4930f0, flagClearAndReset);

// 0x410470 (GUESS), cdecl, eax = 0: zeroes seven dwords at a non-null pointer.
static u32 cdeclZeroSeven(u32 *p) {
  if (p) {
    for (u32 i = 0; i < 7; ++i)
      p[i] = 0;
  }
  return 0;
}
PCREG(410470, cdeclZeroSeven);
