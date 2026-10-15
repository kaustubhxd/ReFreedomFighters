#include "ff.h"

extern "C" u32 THISCALL ext_4e5e60(u8 *parser);

// 0x5b95f0: parse two values and resolve each through the engine table.
static void THISCALL fn5b95f0(u8 *self, u32 ignored, u8 *parser) {
  u32 first = ext_4e5e60(parser);
  u32 second = ext_4e5e60(parser);
  *(u32 *)(self + 0x48) = first;
  *(u32 *)(self + 0x4c) = second;
  u8 *table = *(u8 **)((u8 *)g_pSysInterface + 0x9b);
  *(u32 *)(self + 0x50) = vcall<u32>(table, 0x58, first);
  *(u32 *)(self + 0x54) = vcall<u32>(table, 0x58, second);
}

PCREG(5b95f0, fn5b95f0);
