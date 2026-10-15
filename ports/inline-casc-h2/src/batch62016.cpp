#include "ff.h"

// 0x655bc0: scale an index by 68; zero returns immediately, otherwise query
// the engine's indexed record object.
static u32 STDCALL fn655bc0(u32 index) {
  u32 scaled = index * 68u;
  if (!scaled) return 0;
  u8 *system = (u8 *)g_pSysInterface;
  u8 *collection = *(u8 **)(system + 0x190f);
  u8 *records = vcall<u8 *>(collection, 0x20);
  return vcall<u32>(records, 0x14, scaled);
}

PCREG(655bc0, fn655bc0);
