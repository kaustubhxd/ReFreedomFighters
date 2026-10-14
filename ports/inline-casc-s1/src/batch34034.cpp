// batch34034.cpp - cascade tier E, batch 34034: 0x436450 (slot 0xc over three object arrays), 0x443ad0 (refresh and maybe release a member, then dispatch on
// two predicates), 0x4544d0 (once-only walk of an id list calling slot 0x22c on each resolved object).
#include "ff.h"

extern "C" void THISCALL ext_443c80(void *self, void *a);   // thiscall ret 4
extern "C" void THISCALL ext_443b40(void *self, void *a);   // thiscall ret 4

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static inline void wr32u(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x436450, thiscall, no args: slot 0xc() of the [this+0xc] objects at +4.., of the [this+0x1c] objects at +0x10.. and of the [this+0x60] objects at +0x20.. (unsigned counts).
static void THISCALL fn436450(u8 *self) {
  for (u32 i = 0; i < *(u32 *)(self + 0xc); i++) vcall<void>(*(u8 **)(self + 4 + i * 4), 0xc);
  for (u32 i = 0; i < *(u32 *)(self + 0x1c); i++) vcall<void>(*(u8 **)(self + 0x10 + i * 4), 0xc);
  for (u32 i = 0; i < *(u32 *)(self + 0x60); i++) vcall<void>(*(u8 **)(self + 0x20 + i * 4), 0xc);
}
PCREG(436450, fn436450);

// 0x443ad0, thiscall(a) ret 4: m = [this+0x77] (unaligned); m->slot0x3c(a); when m->slot0x14() is 0: delete [this+0x77] through its slot 0 (flag 1) when set and clear
// the field; then when a->slot0x308() 0x443c80(this, a); when a->slot0x30c() 0x443b40(this, a).
static void THISCALL fn443ad0(u8 *self, u8 *a) {
  vcall<void>((void *)rd32u(self + 0x77), 0x3c, (u32)a);
  u32 r = vcall<u32>((void *)rd32u(self + 0x77), 0x14);
  if (r == 0) {
    u8 *m = (u8 *)rd32u(self + 0x77);
    if (m) vcall<void>(m, 0, 1u);
    wr32u(self + 0x77, 0);
  }
  if (vcall<bool>(a, 0x308)) ext_443c80(self, a);
  if (vcall<bool>(a, 0x30c)) ext_443b40(self, a);
}
PCREG(443ad0, fn443ad0);

// 0x4544d0, thiscall, no args: nothing when byte [this+0x5a] is set; else set it; m = [this+0x52] (unaligned) (return when null): it = {}; m->slot0x4c(&it); id = m->slot0x5c(&it);
// while it[0]: obj = engine table slot 0x58(id); obj->slot0x22c() when non-null; id = [this+0x52]->slot0x5c(&it).
static void THISCALL fn4544d0(u8 *self) {
  u32 it[3];
  if (self[0x5a]) return;
  u8 *m = (u8 *)rd32u(self + 0x52);
  self[0x5a] = 1;
  if (!m) return;
  vcall<void>(m, 0x4c, (u32)it);
  u32 id = vcall<u32>((void *)rd32u(self + 0x52), 0x5c, (u32)it);
  if (it[0] == 0) return;
  do {
    u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u8 *obj = vcall<u8 *>(tbl, 0x58, id);
    if (obj) vcall<void>(obj, 0x22c);
    id = vcall<u32>((void *)rd32u(self + 0x52), 0x5c, (u32)it);
  } while (it[0] != 0);
}
PCREG(4544d0, fn4544d0);
