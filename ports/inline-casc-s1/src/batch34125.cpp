// batch34125.cpp - cascade tier E, batch 34125: 0x5368a0 (first non-zero result of a handler chain), 0x5b6ab0 (find the first accepted item), 0x5cd9c0 (look up an owner pointer).
#include "ff.h"

extern "C" u32 THISCALL ext_4db9a0(void *self, u32 flags);       // thiscall ret 4 (al)

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x5368a0, thiscall(a) ret 4: 0 when the unaligned dword b = [this+0x5302] is zero. Otherwise the first non-zero sum slot(a) + b for the slots 0x6c, 0x68, 0x64, 0x5c is returned; then slot 0x1d0(a) when non-zero; else slot 0x1cc(a).
static u32 THISCALL fn5368a0(u8 *self, u32 a) {
  u32 b = rd32(self + 0x5302);
  if (b == 0) return 0;
  u32 v = vcall<u32>(self, 0x6c, a) + rd32(self + 0x5302);
  if (v) return v;
  v = vcall<u32>(self, 0x68, a) + rd32(self + 0x5302);
  if (v) return v;
  v = vcall<u32>(self, 0x64, a) + rd32(self + 0x5302);
  if (v) return v;
  v = vcall<u32>(self, 0x5c, a) + rd32(self + 0x5302);
  if (v) return v;
  v = vcall<u32>(self, 0x1d0, a);
  if (v) return v;
  return vcall<u32>(self, 0x1cc, a);
}
PCREG(5368a0, fn5368a0);

// 0x5b6ab0, thiscall(list) ret 4: cur = [list+8]; while cur: when ext_4db9a0(cur, 0x2007f9) has a non-zero low byte, h = [[0x70039c]+0x9b]->slot0x50(cur) and, when [this+0x48]->slot0x2c(h) is non-zero, h is returned; otherwise
// list->slot0x50(&cur) (the callee writes the next item); returns 0 when the list is exhausted.
static u32 THISCALL fn5b6ab0(u8 *self, u8 *list) {
  u32 cur = *(u32 *)(list + 8);
  while (cur) {
    if ((u8)ext_4db9a0((void *)cur, 0x2007f9)) {
      u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
      u32 h = vcall<u32>(tbl, 0x50, cur);
      if (vcall<u32>(*(u8 **)(self + 0x48), 0x2c, h)) return h;
    }
    vcall<void>(list, 0x50, (u32)&cur);
  }
  return 0;
}
PCREG(5b6ab0, fn5b6ab0);

// 0x5cd9c0, thiscall(a, out) ret 8, returns 0: only when the low word of a equals the word at the unaligned +0xb59. g = [0x70038c]: g->slot0x20(this) non-zero: *out = 0. Else when g+8 holds a function (called with ecx = this)
// and g+0xc <= this < g+0x10: *out = f(); otherwise (slot 0xac(this) when [this-4] is 0) *out = [this-4].
static u32 THISCALL fn5cd9c0(u8 *self, u32 a, u32 *out) {
  if ((u16)a != (u16)(self[0xb59] | self[0xb5a] << 8)) return 0;
  u8 *g = G(u8 *, 0x70038c);
  if (vcall<u32>(g, 0x20, (u32)self)) {
    *out = 0;
    return 0;
  }
  g = G(u8 *, 0x70038c);
  u32 f = *(u32 *)(g + 8);
  if (f && !(*(u32 *)(g + 0xc) > (u32)self) && (u32)self < *(u32 *)(g + 0x10)) {
    typedef u32 (THISCALL *fp)(void *);
    *out = ((fp)f)(self);
    return 0;
  }
  if (*(u32 *)(self - 4) == 0) vcall<void>(g, 0xac, (u32)self);
  *out = *(u32 *)(self - 4);
  return 0;
}
PCREG(5cd9c0, fn5cd9c0);
