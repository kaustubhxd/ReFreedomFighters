// batch34058.cpp - cascade tier E, batch 34058: 0x496690 (release the nodes named by a stream), 0x4b70f0 (one-shot lookup of a table value and a word), 0x4c8560 (toggle a flag and apply it to
// flagged entries).
#include "ff.h"

extern "C" void THISCALL ext_4d9430(void *node);            // thiscall, plain ret
extern "C" void ext_4d9590(void *node);                     // cdecl
extern "C" void THISCALL ext_4daa20(void *node, u32 flag);  // thiscall ret 4

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x496690, thiscall(s) ret 4: s->slot0xc(5); base = [[this+0x14]+4]; ids read with s->slot0x18(&id, 4) until -1; for each: node = base + id*0x70; unless bit 0x4000000 of [node+0x3c]:
// 0x4d9430(node) and 0x4d9590(node).
static void THISCALL fn496690(u8 *self, u8 *s) {
  vcall<void>(s, 0xc, 5u);
  u8 *base = *(u8 **)(*(u8 **)(self + 0x14) + 4);
  u32 id;
  vcall<void>(s, 0x18, (u32)&id, 4u);
  while (id != 0xffffffffu) {
    u8 *node = base + id * 0x70;
    if (!(*(u32 *)(node + 0x3c) & 0x4000000)) {
      ext_4d9430(node);
      ext_4d9590(node);
    }
    vcall<void>(s, 0x18, (u32)&id, 4u);
  }
}
PCREG(496690, fn496690);

// 0x4b70f0, thiscall, no args: nothing unless byte [this+0x183]; then t = engine table slot 0x138(); tmp = 0; t->slot0x88(0x68c070, &tmp); [this+0x78] = engine table slot 0x58(tmp);
// v = engine table slot 0x114(0x692668, 0, 0x691edc, 0xdd7); word [this+0x76] = (u16)v; when [this+0x78]: it->slot0x130(it, v, 0); byte [this+0x183] = 0.
static void THISCALL fn4b70f0(u8 *self) {
  if (self[0x183] == 0) return;
  u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *t = vcall<u8 *>(tbl, 0x138);
  u32 tmp = 0;
  vcall<void>(t, 0x88, 0x68c070u, (u32)&tmp);
  tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  *(u32 *)(self + 0x78) = vcall<u32>(tbl, 0x58, tmp);
  tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 v = vcall<u32>(tbl, 0x114, 0x692668u, 0u, 0x691edcu, 0xdd7u);
  self[0x76] = v;
  self[0x77] = v >> 8;
  u8 *it = *(u8 **)(self + 0x78);
  if (it) vcall<void>(it, 0x130, (u32)it, v, 0u);
  self[0x183] = 0;
}
PCREG(4b70f0, fn4b70f0);

// 0x4c8560, thiscall, no args: [this+0x52] = ([this+0x52] == 0); walks the engine table's list ([[table]+0xadc], first node at +8, next through slot 0x50(&node)): for each node whose record
// ([[node+0x54]+0xc] dword +0x23, 0x200002 when [node+0x54] is null) has bit 0x400000: 0x4daa20(node, [this+0x52]); finally [table+0xbae] = [this+0x52].
static void THISCALL fn4c8560(u8 *self) {
  self[0x52] = self[0x52] == 0;
  u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *list = *(u8 **)(tbl + 0xadc);
  u32 node = *(u32 *)(list + 8);
  if (node) {
    do {
      u8 *p = *(u8 **)(node + 0x54);
      u32 f = p ? rd32u(*(u8 **)(p + 0xc) + 0x23) : 0x200002;
      if (f & 0x400000) ext_4daa20((void *)node, self[0x52]);
      tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
      list = *(u8 **)(tbl + 0xadc);
      vcall<void>(list, 0x50, (u32)&node);
    } while (node);
  }
  tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  tbl[0xbae] = self[0x52];
}
PCREG(4c8560, fn4c8560);
