#include "ff.h"
// batch923.cpp - unclaimed-80 claim 3 (docs/20-unclaimed-80.md). ZFenceGate::ReadInput(DBREAD&) (0x5c2870, from the residue
// list, GC map name). DBREAD operators: 0x4e5ea0 (dword, no args), 0x4e5e60 (dword), 0x4e5ef0 (byte), 0x4e5e40 (word),
// 0x4e6330 (GetRefTab, one argument). Original code; the spec stubs them.

extern "C" u32 THISCALL ext_4e5ea0(u8 *dbread);
extern "C" u32 THISCALL ext_4e5e60(u8 *dbread);
extern "C" u8 THISCALL ext_4e5ef0(u8 *dbread);
extern "C" u32 THISCALL ext_4e5e40(u8 *dbread);
extern "C" void THISCALL ext_4e6330(u8 *dbread, u8 *out);

static void THISCALL fenceGateReadInput(u8 *self, u8 *dbread) {
  *(u32 *)(self + 0x48) = ext_4e5ea0(dbread);
  *(u32 *)(self + 0x4c) = ext_4e5e60(dbread);
  self[0x25a] = ext_4e5ef0(dbread);
  *(u32 *)(self + 0x50) = ext_4e5e60(dbread);
  ext_4e6330(dbread, self + 0x54);
  *(u16 *)(self + 0x1ac) = (u16)ext_4e5e40(dbread);
  u8 b = **(u8 **)dbread;
  if (b != 0xff && (b & 0x3f) == 9)
    ext_4e6330(dbread, self + 0x1ae);
  b = **(u8 **)dbread;
  if (b != 0xff && (b & 0x3f) == 9)
    ext_4e6330(dbread, self + 0x100);
}
PCREG(5c2870, fenceGateReadInput);
