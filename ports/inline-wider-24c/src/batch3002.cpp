// batch3002.cpp - unclaimed-30: batch 2 (docs/20-unclaimed-30.md, claim 1). ZGEOM::DeactivateEvents(bool) [map 0x45d9d0;
// thiscall, ret 4]. The gate 0x4da3a0 (exe code) must hold; the inner list (this+0x10 -> +8) is walked with its begin (+0x4c)
// and next (+0x5c); each element goes to the allocator's slot 0xcc: no result removes the element (list slot +0x44), a
// result is passed with the flag to this's slot 0x120.
#include "ff.h"

// 0x4da3a0 (exe): the gate; thiscall on the object at this+8 (ret 0), returns al.
extern "C" u8 THISCALL ext_4da3a0(u8 *self);

static u8 *rdp(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return (u8 *)v; }

static void THISCALL geomDeactivateEvents(u8 *self, u32 flag) {
  if (!ext_4da3a0(rdp(self + 8))) return;
  u8 *ilist = rdp(rdp(self + 0x10) + 8);
  if (!ilist) return;
  u32 it[3];
  vcall<void>(ilist, 0x4c, it);
  u32 cur = vcall<u32>(ilist, 0x5c, it);
  if (!it[0]) return;
  do {
    u8 *res = (u8 *)vcall<u32>(G(u8 *, 0x70038c), 0xcc, cur);
    if (!res) {
      vcall<void>(rdp(rdp(self + 0x10) + 8), 0x44, it);
    } else {
      vcall<void>(self, 0x120, res, flag);
    }
    cur = vcall<u32>(rdp(rdp(self + 0x10) + 8), 0x5c, it);
  } while (it[0] != 0);
}
PCREG(45d9d0, geomDeactivateEvents);
