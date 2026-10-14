// batch3008.cpp - unclaimed-30: batch 8 (docs/20-unclaimed-30.md, claim 1). CMAINCAMERACONTROL::Save(ZSaveGame*) [map 0x4fd890;
// thiscall, ret 4, returns true]. Clears bit 0x40 of the dword at +4, then saves through the save object: dwords (+0x48, +0x6a,
// +0x6e, +0x78, +0x144, +0x148, +0x14e, +0x152, +0x156; slots 0x3c / 0x44), bytes (+0x4c, +0x4d, +0x68; slot 0x60), 16 bytes at
// +0x4e (slot 0x10), a float (+0x5e; slot 0x4c), words (+0x7c, +0x7e, +0x80, +0x82; slot 0x40), and the pointer this+0x98 (slot 0x6c).
#include "ff.h"

static u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static u16 rd16u(const u8 *p) { u16 v; __builtin_memcpy(&v, p, 2); return v; }

static bool THISCALL cameraSave(u8 *self, u8 *save) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  vcall<void>(save, 0x3c, rd32u(self + 0x48));
  vcall<void>(save, 0x60, (u32)self[0x4c]);
  vcall<void>(save, 0x60, (u32)self[0x4d]);
  vcall<void>(save, 0x10, (const void *)(self + 0x4e), (u32)0x10);
  vcall<void>(save, 0x4c, *(const float *)(self + 0x5e));
  vcall<void>(save, 0x60, (u32)self[0x68]);
  vcall<void>(save, 0x44, rd32u(self + 0x6a));
  vcall<void>(save, 0x3c, rd32u(self + 0x6e));
  vcall<void>(save, 0x3c, rd32u(self + 0x78));
  vcall<void>(save, 0x40, (u32)rd16u(self + 0x7c));
  vcall<void>(save, 0x40, (u32)rd16u(self + 0x7e));
  vcall<void>(save, 0x40, (u32)rd16u(self + 0x80));
  vcall<void>(save, 0x40, (u32)rd16u(self + 0x82));
  vcall<void>(save, 0x6c, (const void *)(self + 0x98));
  vcall<void>(save, 0x3c, rd32u(self + 0x144));
  vcall<void>(save, 0x44, rd32u(self + 0x148));
  vcall<void>(save, 0x3c, rd32u(self + 0x14e));
  vcall<void>(save, 0x44, rd32u(self + 0x152));
  vcall<void>(save, 0x3c, rd32u(self + 0x156));
  return true;
}
PCREG(4fd890, cameraSave);
