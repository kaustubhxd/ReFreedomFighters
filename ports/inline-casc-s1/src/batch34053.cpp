// batch34053.cpp - cascade tier E, batch 34053: 0x5b8200 / 0x5b8270 (send a stored word to the objects of an id list through the global service), 0x5c1aa0 (toggle visibility of a
// listed set, then maybe notify).
#include "ff.h"

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// Shared walk for 0x5b8200 / 0x5b8270, thiscall, no args: l = [[this+0x54]+0x18] (return when null): it = {}; l->slot0x4c(&it); id = l->slot0x5c(&it); while it[0]: o = global(0x70038c)->slot0xcc(id);
// o->slot0x128(word [this+off], 0, 0); id = l->slot0x5c(&it).
static inline void send_word(u8 *self, u32 off) {
  u32 it[3];
  u8 *l = *(u8 **)(*(u8 **)(self + 0x54) + 0x18);
  if (!l) return;
  vcall<void>(l, 0x4c, (u32)it);
  u32 id = vcall<u32>(l, 0x5c, (u32)it);
  if (it[0] == 0) return;
  do {
    u8 *g = G(u8 *, 0x70038c);
    u8 *o = vcall<u8 *>(g, 0xcc, id);
    vcall<void>(o, 0x128, (u32)(self[off] | self[off + 1] << 8), 0u, 0u);
    id = vcall<u32>(l, 0x5c, (u32)it);
  } while (it[0] != 0);
}

// 0x5b8200: the word at +0x5a.
static void THISCALL fn5b8200(u8 *self) { send_word(self, 0x5a); }
PCREG(5b8200, fn5b8200);

// 0x5b8270: the word at +0x58.
static void THISCALL fn5b8270(u8 *self) { send_word(self, 0x58); }
PCREG(5b8270, fn5b8270);

// 0x5c1aa0, thiscall, no args: when the unaligned dword [this+0x111] is zero: for the zero-terminated id array at [this+0xe4], with a counter starting at [this+0xe8]: o = [this+0x10d] (unaligned
// object) slot 0x25c(id, 0); when found o->slot0xbc(counter != [this+0x48]) (0 when equal, 1 otherwise). Always finishes: when [engine+0x1b5d] is zero this->slot0x68(0x10, 0).
static void THISCALL fn5c1aa0(u8 *self) {
  if (rd32u(self + 0x111) == 0) {
    u32 *p = *(u32 **)(self + 0xe4);
    u32 idx = *(u32 *)(self + 0xe8);
    u32 id = *p;
    while (id) {
      u8 *owner = (u8 *)rd32u(self + 0x10d);
      u8 *o = vcall<u8 *>(owner, 0x25c, id, 0u);
      if (o) {
        if (idx == *(u32 *)(self + 0x48)) vcall<void>(o, 0xbc, 0u);
        else vcall<void>(o, 0xbc, 1u);
      }
      id = p[1];
      p += 1;
      idx += 1;
    }
  }
  u8 *eng = G(u8 *, 0x70039c);
  if (*(u32 *)(eng + 0x1b5d) == 0) vcall<void>(self, 0x68, 0x10u, 0u);
}
PCREG(5c1aa0, fn5c1aa0);
