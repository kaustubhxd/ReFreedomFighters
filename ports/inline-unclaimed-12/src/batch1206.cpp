// batch1206.cpp - unclaimed-12: batch 6 (docs/20-unclaimed-12.md, claim 6, in slice). Thiscall; the callee pops the stack arg.
// Names are from the GC name map (high confidence for both).
#include "ff.h"

// 0x4e5e60, DBREAD::operator unsigned int(); 0x4e5e40, DBREAD::operator unsigned short() (original code here).
extern "C" u32 THISCALL ext_4e5e60(u8 *dbread);
extern "C" u32 THISCALL ext_4e5e40(u8 *dbread);

// a ZLoadGame read: the vtable slot +0x40 takes one stack argument, the destination pointer (the object is in ecx)
typedef u32(THISCALL *LoadFieldFn)(u8 *load, void *dst);

static void loadField(u8 *load, void *dst) {
  const u32 vtbl = *(const u32 *)load;
  LoadFieldFn read = (LoadFieldFn)(*(const u32 *)(vtbl + 0x40));
  read(load, dst);
}

// 0x4b83f0, CTelePortList::Load(ZLoadGame*) (high): clears bit 0x40 of the dword at +4, then reads fields into +0x4c, +0x50
// and +0x48 through the load object's vtable slot +0x40. Returns true (al = 1).
static bool THISCALL teleportListLoad(u8 *self, u8 *load) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  loadField(load, self + 0x4c);
  loadField(load, self + 0x50);
  loadField(load, self + 0x48);
  return true;
}
PCREG(4b83f0, teleportListLoad);

// 0x4fb830, CCHECKOBJINOBJ::CopyEventDataBlock(DBREAD&) (high): dwords from three DBREAD dword reads go to +0x51, +0x59 and
// +0x55 (in that order); two DBREAD word reads go to +0x4d and +0x4f.
static void THISCALL checkObjInObjCopyEventDataBlock(u8 *self, u8 *dbread) {
  *(u32 *)(self + 0x51) = ext_4e5e60(dbread);
  *(u32 *)(self + 0x59) = ext_4e5e60(dbread);
  *(u32 *)(self + 0x55) = ext_4e5e60(dbread);
  *(u16 *)(self + 0x4d) = (u16)ext_4e5e40(dbread);
  *(u16 *)(self + 0x4f) = (u16)ext_4e5e40(dbread);
}
PCREG(4fb830, checkObjInObjCopyEventDataBlock);
