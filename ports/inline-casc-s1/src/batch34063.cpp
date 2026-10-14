// batch34063 - cascade tier E, batch 34063: 0x63d270 (create a slot node and register it twice), 0x64d560 (release a mapped entry and a side object), 0x434d90 (apply a lookup to every element of a list).
#include "ff.h"

extern "C" void THISCALL ext_64c8d0(void *node);   // thiscall, plain ret
typedef u32 (*hook_t)();

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x63d270, thiscall(a, b) ret 8, returns the node: this->slot0x60(); i = index of the first zero dword among the 32 at +0x6c (32 when none); node = this->slot0x7c(a, i, b); 0x64c8d0(node) when byte
// [this+5]; [this + 0x6c + 4*[node+0x10055]] = node (the index is an unaligned dword of the node); when [this+0xec] + 1 > 0x20 the assert hook (int3 when null); [this + 0xf0 + 4*[this+0xec]] = node;
// [this+0xec]++; returns node.
static u8 *THISCALL fn63d270(u8 *self, u32 a, u32 b) {
  vcall<void>(self, 0x60);
  u32 i = 0;
  u32 *e = (u32 *)(self + 0x6c);
  for (;;) {
    if (*e == 0) break;
    i++;
    e += 1;
    if (i == 0x20) break;
  }
  u8 *node = vcall<u8 *>(self, 0x7c, a, i, b);
  if (self[5]) ext_64c8d0(node);
  u32 idx = rd32u(node + 0x10055);
  *(u8 **)(self + idx * 4 + 0x6c) = node;
  u32 n = *(u32 *)(self + 0xec) + 1;
  if (n > 0x20) {
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
  u32 cnt = *(u32 *)(self + 0xec);
  *(u8 **)(self + cnt * 4 + 0xf0) = node;
  *(u32 *)(self + 0xec) += 1;
  return node;
}
PCREG(63d270, fn63d270);

// 0x64d560, thiscall(p) ret 4: edx = [p+8]; a = [edx+0x10]; when a and [a] == 0: ent = [a+8]; slot = (u16)[ent+6] & 0xfff; x = table[slot] (table at [this+0x10071]); when x: [edx+0x14] &= ~[this+0x10059],
// table[slot] = 0 and [this+0x10161]->slot0xc(x). Then, when y = [p+0xc]: [[this+0x1005d]+0x234]->slot0xc(y) and [p+0xc] = 0.
static void THISCALL fn64d560(u8 *self, u8 *p) {
  u8 *edx = *(u8 **)(p + 8);
  u8 *a = *(u8 **)(edx + 0x10);
  if (a && *(u32 *)a == 0) {
    u8 *ent = *(u8 **)(a + 8);
    u8 **table = (u8 **)rd32u(self + 0x10071);
    u32 slot = (ent[6] | ent[7] << 8) & 0xfff;
    u8 *x = table[slot];
    if (x) {
      u32 m = rd32u(self + 0x10059);
      *(u32 *)(edx + 0x14) &= ~m;
      slot = (ent[6] | ent[7] << 8) & 0xfff;
      table = (u8 **)rd32u(self + 0x10071);
      table[slot] = 0;
      u8 *o = (u8 *)rd32u(self + 0x10161);
      vcall<void>(o, 0xc, (u32)x);
    }
  }
  u8 *y = *(u8 **)(p + 0xc);
  if (y) {
    u8 *g = (u8 *)rd32u(self + 0x1005d);
    u8 *o2 = *(u8 **)(g + 0x234);
    vcall<void>(o2, 0xc, (u32)y);
    *(u32 *)(p + 0xc) = 0;
  }
}
PCREG(64d560, fn64d560);

// 0x434d90, thiscall(a) ret 4: m = [this+4] (return when null): it = {}; m->slot0x4c(&it); x = m->slot0x64(&it); while x: r = this->slot0x130(a); when r: [x]->slot0x54(r); x = m->slot0x64(&it).
static void THISCALL fn434d90(u8 *self, u32 a) {
  u32 it[3];
  u8 *m = *(u8 **)(self + 4);
  if (!m) return;
  vcall<void>(m, 0x4c, (u32)it);
  u8 *x = vcall<u8 *>(*(u8 **)(self + 4), 0x64, (u32)it);
  while (x) {
    u32 r = vcall<u32>(self, 0x130, a);
    if (r) vcall<void>(*(u8 **)x, 0x54, r);
    x = vcall<u8 *>(*(u8 **)(self + 4), 0x64, (u32)it);
  }
}
PCREG(434d90, fn434d90);
