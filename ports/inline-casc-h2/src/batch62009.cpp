#include "ff.h"

// 0x655c00, stdcall(index) ret 4: scale index by 40 and query the system
// collection, then its returned object, passing the scaled index.
static u32 STDCALL fn655c00(u32 index) {
  u32 scaled = index * 40u;
  if (!scaled) return 0;
  u8 *sys = G(u8 *, 0x70039c);
  u8 *collection = *(u8 **)(sys + 0x190f);
  u8 *item = vcall<u8 *>(collection, 0x20);
  return vcall<u32>(item, 0x14, scaled);
}

PCREG(655c00, fn655c00);
