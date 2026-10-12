// batch6300.cpp - unclaimed-68 batch 29 (claim 29, gap band). Name from the GC name map.
#include "ff.h"

// Slot +0x210 of the sub-object (thiscall, one argument; the callee cleans it).
typedef void(THISCALL *VSub210)(u8 *self, u32 arg);

// 0x4bbc20, ZDefaultAcusticEnv::Init2() (name map): thiscall, void. The sub-object at this+0x44, when not null, gets slot +0x210 (1).
static void THISCALL acousticEnvInit2(u8 *self) {
  u8 *s = *(u8 **)(self + 0x44);
  if (s) ((VSub210)*(u32 *)(*(u8 **)s + 0x210))(s, 1);
}
PCREG(4bbc20, acousticEnvInit2);
