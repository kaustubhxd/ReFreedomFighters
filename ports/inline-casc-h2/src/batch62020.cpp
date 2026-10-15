#include "ff.h"

extern "C" u32 THISCALL ext_4e5e60(u8 *parser);

// 0x4b0a70: parse two values, store the second's presence flag, report the
// final status through the engine table, then clear the temporary dword.
static void THISCALL fn4b0a70(u8 *self, u8 *parser) {
  *(u32 *)(self + 0x48) = ext_4e5e60(parser);
  u32 second = ext_4e5e60(parser);
  self[0x50] = second != 0;
  u8 *table = *(u8 **)((u8 *)g_pSysInterface + 0x9b);
  u16 status = vcall<u16>(table, 0x114, 0x685f34u, 0, 0x691edcu, 0xa83u);
  *(u16 *)(self + 0x51) = status;
  *(u32 *)(self + 0x48) = 0;
}

PCREG(4b0a70, fn4b0a70);
