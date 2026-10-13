// batch1211.cpp - fresh slice 12, batch 11. Names are FUN_ in the exe list (no map entry). Exe callees run as
// ext_<hex>; the harness hooks and logs them.
#include "ff.h"

extern "C" u32 THISCALL ext_565360(u8 *self, u8 *entry);   // ret 4
typedef s32(__attribute__((cdecl)) * stricmp_t)(const char *, const char *);
#define imp_stricmp G(stricmp_t, 0x676414)                     // api-ms-win-crt-string _stricmp (IAT)

// 0x4321c0: looks a name up in the engine's string table (engine+0x190b): groups of 16 bytes {base, ?, entries, ?},
// ended by a null entries pointer; entries are 12-byte records with the name first, ended by a null name. Returns
// group.base + index of the first case-insensitive match, else -1. ret 4.
static s32 THISCALL findName(u8 *, const char *key) {
  u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x190b);
  for (u32 g = 0; *(u8 **)(tbl + g * 16 + 8); g++) {
    u8 *e = *(u8 **)(tbl + g * 16 + 8);
    for (u32 i = 0; *(u32 *)(e + i * 12); i++) {
      if (!imp_stricmp(*(const char **)(e + i * 12), key)) return *(s32 *)(tbl + g * 16) + (s32)i;
    }
  }
  return -1;
}
PCREG(4321c0, findName);

// 0x4ca240: resets the state block: +0x48..+0x68 (nine dwords) = 0, copies (+0x44)->+8 ->+0x24/+0x28/+0x2c to
// +0xad/+0xb1/+0xb5, and clears +0xa9, +0xa5, +0xa1.
static void THISCALL resetState(u8 *self) {
  u8 *src = *(u8 **)(*(u8 **)(self + 0x44) + 8);
  for (u32 off = 0x48; off <= 0x68; off += 4) *(u32 *)(self + off) = 0;
  *(u32 *)(self + 0xad) = *(u32 *)(src + 0x24);
  *(u32 *)(self + 0xb1) = *(u32 *)(src + 0x28);
  *(u32 *)(self + 0xb5) = *(u32 *)(src + 0x2c);
  *(u32 *)(self + 0xa9) = 0;
  *(u32 *)(self + 0xa5) = 0;
  *(u32 *)(self + 0xa1) = 0;
}
PCREG(4ca240, resetState);

// 0x565100: selects entry idx (0x2a-byte records from +0x18c). A flagged entry (+0x1b5) sets +0xc86 = idx, +0xc82 =
// 0x20, +0xc9a = 9, +0x184 = 0x10; otherwise ids 0x15 / 0x16 first save +0xc82 in +0xc92, then +0xc82 = idx, +0xc9a =
// 0xa. Both tail-call 0x565360(entry). ret 4.
static u32 THISCALL selectEntry(u8 *self, u32 idx) {
  u32 o = idx * 0x2a;
  if (self[o + 0x1b5]) {
    *(u32 *)(self + 0xc86) = idx;
    *(u32 *)(self + 0xc82) = 0x20;
    *(u32 *)(self + 0xc9a) = 9;
    *(u32 *)(self + 0x184) = 0x10;
    return ext_565360(self, self + 0x18c + o);
  }
  if (idx == 0x15 || idx == 0x16) *(u32 *)(self + 0xc92) = *(u32 *)(self + 0xc82);
  *(u32 *)(self + 0xc82) = idx;
  *(u32 *)(self + 0xc9a) = 0xa;
  return ext_565360(self, self + 0x18c + o);
}
PCREG(565100, selectEntry);
