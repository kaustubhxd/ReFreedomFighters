#include "ff.h"
// batch7906.cpp - unclaimed-79 batch 6 (docs/20-unclaimed-79.md). Name from the residue list (no GC conflict).
// Helpers 0x4e7c40, 0x4e78c0 (not lifted here) and RegisterMessages 0x4a5c20 (original code) are called through their addresses.

extern "C" void THISCALL ext_4e7c40(u8 *self48, u32 a);
extern "C" void THISCALL ext_4e78c0(u8 *self48, u8 *ld);
extern "C" void ext_4a5c20(void);

// 0x4a5ae0, ZMatPosAnim::Load(ZLoadGame*) (residue list). Thiscall, one stack argument (ret 4).
static u8 THISCALL matPosAnimLoad(u8 *self, u8 *ld) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  vcall<void, u8 *>(ld, 0x6c, self + 0x5f);
  vcall<void, u8 *>(ld, 0x74, self + 0x6b);
  vcall<void, u8 *>(ld, 0x68, self + 0x8f);
  vcall<void, u8 *>(ld, 0x68, self + 0x90);
  vcall<void, u8 *>(ld, 0x68, self + 0x91);
  vcall<void, u8 *>(ld, 0x44, self + 0x5d);
  vcall<void, u8 *>(ld, 0x74, self + 0x93);
  vcall<void, u8 *>(ld, 0x58, self + 0xb7);
  vcall<void, u8 *>(ld, 0x50, self + 0xbb);
  vcall<void, u8 *>(ld, 0x68, self + 0x92);
  vcall<void, u8 *>(ld, 0x50, self + 0xc0);
  vcall<void, u8 *>(ld, 0x68, self + 0xc4);
  vcall<void, u8 *>(ld, 0x68, self + 0xc5);
  vcall<void, u8 *>(ld, 0x68, self + 0xc6);
  vcall<void, u8 *>(ld, 0x50, self + 0xc7);
  vcall<void, u8 *>(ld, 0x68, self + 0xcb);
  vcall<void, u8 *>(ld, 0x48, self + 0xcc);
  vcall<void, u8 *>(ld, 0x48, self + 0xd0);
  vcall<void, u8 *>(ld, 0x68, self + 0xbf);
  u32 r = vcall<u32, u32>(*(u8 **)(self + 0x44), 0x4c, 0x4b455953u);
  ext_4e7c40(self + 0x48, r);
  ext_4e78c0(self + 0x48, ld);
  ext_4a5c20();
  return 1;
}
PCREG(4a5ae0, matPosAnimLoad);
