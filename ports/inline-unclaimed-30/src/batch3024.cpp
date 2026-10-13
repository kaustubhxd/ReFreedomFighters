// batch3024.cpp - unclaimed-30 claim 2 (residue 10): ZRepositionCharacter::CopyData(ZEventBase *src) [map 0x5c40e0; thiscall, ret 4].
// Copies the dwords at +0x4c and +0x50 from src. If src's list (+0x48) is not null, every element found by its begin (+0x4c) and next (+0x5c)
// is added to this's list (+0x48, slot +4).
#include "ff.h"

static u8 *rdp(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return (u8 *)v; }
static u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }

static void THISCALL repositionCopyData(u8 *self, u8 *src) {
  wr32u(self + 0x4c, rd32u(src + 0x4c));
  wr32u(self + 0x50, rd32u(src + 0x50));
  u8 *sl = rdp(src + 0x48);
  if (sl) {
    u32 it[3];
    vcall<void>(sl, 0x4c, it);
    u32 cur = vcall<u32>(sl, 0x5c, it);
    while (it[0] != 0) {
      vcall<void>(rdp(self + 0x48), 0x4, cur);
      cur = vcall<u32>(rdp(src + 0x48), 0x5c, it);
    }
  }
}
PCREG(5c40e0, repositionCopyData);
