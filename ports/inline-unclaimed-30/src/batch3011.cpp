// batch3011.cpp - unclaimed-30: batch 11 (docs/20-unclaimed-30.md, claim 1). ZGEOM::RemoveEventFromList(ZEventBase *ev) [map
// 0x45f7d0; thiscall, ret 4]. Gated by 0x4da3a0 (exe code, as in DeactivateEvents). Walks the list at this+0x10 -> +8 with begin
// (+0x4c) and next (+0x5c). Each element comes from the allocator's slot 0xcc; when it is ev, and its flag byte +0x14 has bit 8 and
// its dword +0x1c is non-zero, the dword at (this+0x10)->+0x10 is cleared; the element is then removed (list slot +0x44). At the end
// the list's slot +0x14 is asked; when it is zero, this's slot 0x140 is called.
#include "ff.h"

extern "C" u8 THISCALL ext_4da3a0(u8 *self);   // gate (exe code)

static u8 *rdp(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return (u8 *)v; }
static u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }

static void THISCALL geomRemoveEventFromList(u8 *self, u8 *ev) {
  if (!ext_4da3a0(rdp(self + 8))) return;
  u8 *holder = rdp(self + 0x10);
  u8 *ilist = rdp(holder + 8);
  if (ilist) {
    u32 it[3];
    vcall<void>(ilist, 0x4c, it);
    u32 cur = vcall<u32>(ilist, 0x5c, it);
    if (it[0]) {
      do {
        u32 res = vcall<u32>(G(u8 *, 0x70038c), 0xcc, cur);
        if (res == (u32)ev) {
          u8 *h = rdp(self + 0x10);
          if ((*(u8 *)(res + 0x14) & 8) && rd32u((u8 *)res + 0x1c)) {
            if (h) {
              u8 *h2 = rdp(h + 0x10);
              if (h2) wr32u(h2, 0);
            }
          }
          vcall<void>(rdp(rdp(self + 0x10) + 8), 0x44, it);
        }
        cur = vcall<u32>(rdp(rdp(self + 0x10) + 8), 0x5c, it);
      } while (it[0] != 0);
    }
  }
  u32 r = vcall<u32>(rdp(rdp(self + 0x10) + 8), 0x14);
  if (!r) vcall<void>(self, 0x140);
}
PCREG(45f7d0, geomRemoveEventFromList);
