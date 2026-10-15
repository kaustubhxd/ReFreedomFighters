// batch1314.cpp - inventory thread (inline-inventory, 2026-10-11): ZItemSpawn::SpawnItem (0x471680).
// Object: +0x44 the owner item, +0x52 the spawned item's reference id, +0x5a the spawned item object.
#include "ff.h"

extern "C" u32 THISCALL ext_46abf0(u8 *game, u8 *item);              // game-side spawn registration
static inline u8 *refTable() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }
static inline u8 isA(u8 *g, u32 type) { return (u8)vcall<u32>(g, 0x1e0, type); }

static void THISCALL itemSpawnSpawnItem(u8 *self) {
  if (*(u32 *)(self + 0x52)) return;
  u8 *owner = *(u8 **)(self + 0x44);
  if (!isA(owner, 0x1007d1)) return;
  u8 *tmpl = vcall<u8 *>(owner, 0x2e8);
  if (!tmpl) return;
  // the new item: template slot 0x2c4 (ref+0xadc, 'MEIT' flag) returns it
  u8 *nw = vcall<u8 *>(tmpl, 0x2c4, *(u32 *)(refTable() + 0xadc), 0x4954454du);
  *(u8 **)(self + 0x5a) = nw;
  if (!nw) return;
  if (isA(nw, 0x1007d2)) {
    u8 *s = *(u8 **)(self + 0x5a);
    u32 v = vcall<u32>(s, 0x364);
    vcall<u32>(s, 0x360, v);
  } else if (isA(nw, 0x1007d8)) {
    u32 v = vcall<u32>(*(u8 **)(self + 0x44), 0x320);
    vcall<u32>(*(u8 **)(self + 0x5a), 0x324, v);
  }
  *(u32 *)(self + 0x52) = vcall<u32>(refTable(), 0x4c, *(u8 **)(self + 0x5a));
  u8 *n2 = *(u8 **)(self + 0x5a);
  u32 id = vcall<u32>(refTable(), 0x4c, *(u8 **)(self + 0x44));
  vcall<u32>(n2, 0x2f0, id, 0u, 1u);
  vcall<u32>(*(u8 **)(self + 0x5a), 0x300, 1u);
  u32 a34[4] = {0, 0, 0, 0};
  u32 a10[4] = {0, 0, 0, 0};
  vcall<u32>(*(u8 **)(self + 0x44), 0x80, a34, a10);
  vcall<u32>(*(u8 **)(self + 0x5a), 0x7c, a34, a10);
  vcall<u32>(self, 0x68, 0x10u, 0u);
  ext_46abf0(G(u8 *, 0x7003b8), *(u8 **)(self + 0x5a));
}
PCREG(471680, itemSpawnSpawnItem);
