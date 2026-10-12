// batch6202.cpp - unclaimed-62 claim 2 (core-todo residue 03): ZFFFlak::Load(ZLoadGame*) [map 0x5dccb0; thiscall, ret 4, returns true].
// Clears bit 0x40 of the dword at +4; reads an input into a local (exe 0x6352f0, thiscall, one argument); calls 0x5dcea0 (exe, thiscall, one
// argument, the local) on this; then the load object's slot 0x50 gets this+0x48 and this+0x4c, and its slot 0x40 gets this+0x58.
#include "ff.h"

extern "C" u32 THISCALL ext_6352f0(u8 *self, u32 *out);   // exe: input read (ret 4)
extern "C" void THISCALL ext_5dcea0(u8 *self, u32 *arg);  // exe helper (ret 4)

static u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }

static bool THISCALL zffFlakLoad(u8 *self, u8 *load) {
  u32 tmp = 0;
  wr32u(self + 4, rd32u(self + 4) & 0xffffffbfu);
  ext_6352f0(self, &tmp);
  ext_5dcea0(self, &tmp);
  vcall<void>(load, 0x50, (void *)(self + 0x48));
  vcall<void>(load, 0x50, (void *)(self + 0x4c));
  vcall<void>(load, 0x40, (void *)(self + 0x58));
  return true;
}
PCREG(5dccb0, zffFlakLoad);
