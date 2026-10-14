// batch34051.cpp - cascade tier E, batch 34051: 0x566850 (feed every id of a list to a sink), 0x56ad00 (hide six objects, then show one), 0x56c780 (broadcast a flag to five members).
#include "ff.h"

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x566850, thiscall, no args: l = [[this+0x180]+0x18] (return when null): it = {}; l->slot0x4c(&it); id = l->slot0x5c(&it); while it[0]: [this+0x44]->slot0x12c(id, word [this+0x186], id);
// id = [[this+0x180]+0x18]->slot0x5c(&it).
static void THISCALL fn566850(u8 *self) {
  u32 it[3];
  u8 *owner = *(u8 **)(self + 0x180);
  u8 *l = *(u8 **)(owner + 0x18);
  if (!l) return;
  vcall<void>(l, 0x4c, (u32)it);
  u32 id = vcall<u32>(*(u8 **)(*(u8 **)(self + 0x180) + 0x18), 0x5c, (u32)it);
  if (it[0] == 0) return;
  do {
    vcall<void>(*(u8 **)(self + 0x44), 0x12c, id, (u32)(self[0x186] | self[0x187] << 8), id);
    id = vcall<u32>(*(u8 **)(*(u8 **)(self + 0x180) + 0x18), 0x5c, (u32)it);
  } while (it[0] != 0);
}
PCREG(566850, fn566850);

// 0x56ad00, thiscall(k) ret 4: for the six ids at +0x180 + 4*i: the object from engine table slot 0x58 gets slot 0xbc(1) when found; then, for k < 6, the object of id k gets slot 0xbc(0) (a tail call in the original).
static void THISCALL fn56ad00(u8 *self, u32 k) {
  for (u32 i = 0; i < 6; i++) {
    u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u8 *o = vcall<u8 *>(tbl, 0x58, *(u32 *)(self + 0x180 + i * 4));
    if (o) vcall<void>(o, 0xbc, 1u);
  }
  if (k >= 6) return;
  u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *o = vcall<u8 *>(tbl, 0x58, *(u32 *)(self + 0x180 + k * 4));
  if (!o) return;
  vcall<void>(o, 0xbc, 0u);
}
PCREG(56ad00, fn56ad00);

// 0x56c780, thiscall(f) ret 4: slot 0xbc(f) of the members at the unaligned +0xcb6, +0xcc6, +0xcba, +0xcca (each when non-null), then slot 0xbc((f & 0xff) == 0) of the member at +0xcce (a tail call).
static void THISCALL fn56c780(u8 *self, u32 f) {
  u8 *m;
  m = (u8 *)rd32u(self + 0xcb6);
  if (m) vcall<void>(m, 0xbc, f);
  m = (u8 *)rd32u(self + 0xcc6);
  if (m) vcall<void>(m, 0xbc, f);
  m = (u8 *)rd32u(self + 0xcba);
  if (m) vcall<void>(m, 0xbc, f);
  m = (u8 *)rd32u(self + 0xcca);
  if (m) vcall<void>(m, 0xbc, f);
  m = (u8 *)rd32u(self + 0xcce);
  if (m) vcall<void>(m, 0xbc, (u32)((f & 0xff) == 0));
}
PCREG(56c780, fn56c780);
