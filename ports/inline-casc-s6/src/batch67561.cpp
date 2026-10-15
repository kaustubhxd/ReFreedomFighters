// batch67561.cpp - cascade s6 batch 67561: 0x4449e0.
#include "ff.h"

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

static inline u32 typeOf(u8 *n) {
  u8 *sub = *(u8 **)(n + 0x54);
  return sub ? D32(*(u8 **)(sub + 0xc), 0x23) : 0x200002u;
}

// 0x4449e0, thiscall(out, end) ret 8, returns the new write cursor: collects the visible children of this[0xa8]'s list into the pointer array [out, end) (unsigned bounds). Each node of the list
// (slots 0x4c / 0x5c with an iterator dword) is stored when its type word ([+0x54][+0xc][+0x23]) has bit 0x800000; nodes with bit 0x100000 whose sub-record's slot 0x2a8 reports flag 0x10000 are
// expanded: their children (+8, next via slot 0x50 with an iterator) are stored the same way. The scan stops when the array is full.
static u8 **THISCALL fn4449e0(u8 *self, u8 **out, u8 **end) {
  u8 *list = *(u8 **)(self + 0xa8);
  if (!list) return out;
  u32 it;
  vcall<void>(list, 0x4c, (u32)&it);
  u8 *cur = vcall<u8 *>(list, 0x5c, (u32)&it);
  if (it == 0) return out;
  u8 **esi = out;
  for (;;) {
    if (!(esi < end)) return esi;
    u8 *edi = *(u8 **)(cur + 0x54);
    u32 t = typeOf(cur);
    if (t & 0x800000) {
      if (esi < end) *esi++ = cur;
    } else if (t & 0x100000) {
      if (vcall<u32>(edi, 0x2a8) & 0x10000) {
        u8 *c = *(u8 **)(edi + 8);
        u32 v8 = (u32)c;
        while (c) {
          if ((typeOf(c) & 0x800000) && esi < end) *esi++ = c;
          vcall<void>(edi, 0x50, (u32)&v8);
          c = (u8 *)v8;
        }
      }
    }
    cur = vcall<u8 *>(*(u8 **)(self + 0xa8), 0x5c, (u32)&it);
    if (it == 0) return esi;
  }
}
PCREG(4449e0, fn4449e0);
