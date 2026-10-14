// batch34028.cpp - cascade tier E, batch 34028: 0x4bafe0 (feed every id of a list to this), 0x4c86d0 (toggle a flag and apply it to matching entries),
// 0x4d1b00 (replay a linked list into a sink from the n-th node).
#include "ff.h"

extern "C" void THISCALL ext_4daa20(void *node, u32 flag);   // thiscall ret 4

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x4bafe0, thiscall(a) ret 4: l = [a+0x18]; when set: it = {}; l->slot0x4c(&it); e = l->slot0x5c(&it); while it[0]: obj = engine table slot 0x58(e); this->slot0x94(obj);
// e = [a+0x18]->slot0x5c(&it).
static void THISCALL fn4bafe0(u8 *self, u8 *a) {
  u8 *l = *(u8 **)(a + 0x18);
  u32 it[3];
  if (!l) return;
  vcall<void>(l, 0x4c, (u32)it);
  u32 e = vcall<u32>(*(u8 **)(a + 0x18), 0x5c, (u32)it);
  if (it[0] == 0) return;
  do {
    u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u32 obj = vcall<u32>(tbl, 0x58, e);
    vcall<void>(self, 0x94, obj);
    e = vcall<u32>(*(u8 **)(a + 0x18), 0x5c, (u32)it);
  } while (it[0] != 0);
}
PCREG(4bafe0, fn4bafe0);

// 0x4c86d0, thiscall, no args: [this+0x53] = ([this+0x53] == 0); walk the list at [[engine table]+0xadc] (first node [list+8], next through slot 0x50(&node));
// for each node whose record [[node+0x54]+0xc] has the dword 0x200012 at +0x23: 0x4daa20(node, [this+0x53]); finally [[engine table]+0xbaf] = [this+0x53].
static void THISCALL fn4c86d0(u8 *self) {
  self[0x53] = self[0x53] == 0;
  u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *list = *(u8 **)(tbl + 0xadc);
  u32 node = *(u32 *)(list + 8);
  if (node) {
    do {
      u8 *p = *(u8 **)(node + 0x54);
      if (p) {
        u8 *q = *(u8 **)(p + 0xc);
        if (rd32u(q + 0x23) == 0x200012) ext_4daa20((void *)node, self[0x53]);
      }
      tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
      list = *(u8 **)(tbl + 0xadc);
      vcall<void>(list, 0x50, (u32)&node);
    } while (node);
  }
  tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  tbl[0xbaf] = self[0x53];
}
PCREG(4c86d0, fn4c86d0);

// 0x4d1b00, thiscall(sink, n) ret 8: node = [this+0x18]; for n > 0 step n times along [node+8] (a missing node logs through the object at 0x700390: slot 0x20(0x695fec, 0x1d9),
// then its slot 0x2c with (r, 0x696068), caller-popped, and returns); then for each node from there on: sink->slot0x1c([node+0xc], [node+0x10]).
static void THISCALL fn4d1b00(u8 *self, u8 *sink, s32 n) {
  u8 *node = *(u8 **)(self + 0x18);
  s32 i = 0;
  if (n > 0) {
    do {
      node = *(u8 **)(node + 8);
      if (!node) {
        u8 *lg = G(u8 *, 0x700390);
        u8 *r = vcall<u8 *>(lg, 0x20, 0x695fecu, 0x1d9u);
        u32 vt = *(u32 *)r;
        u32 slot = ((u32 *)vt)[0x2c / 4];
        asm volatile("push $0x696068\n\tpush %[r]\n\tcall *%[fn]\n\tadd $8, %%esp" : : "c"(vt), [r] "r"(r), [fn] "r"(slot) : "eax", "edx", "memory", "cc");
        return;
      }
      i++;
    } while (i < n);
  }
  while (node) {
    vcall<void>(sink, 0x1c, *(u32 *)(node + 0xc), *(u32 *)(node + 0x10));
    node = *(u8 **)(node + 8);
  }
}
PCREG(4d1b00, fn4d1b00);
