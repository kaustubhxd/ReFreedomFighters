// batch37104.cpp - cascade s6 batch 37104: 0x4dbbe0.
#include "ff.h"

extern "C" void THISCALL ext_4dc630(u8 *self, u32 flags, u32 inv);   // ret 8
extern "C" void THISCALL ext_4dc9c0(u8 *self, u32 v);                // ret 4

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

static inline void rd(u8 *s, u32 dst, u32 n) { vcall<void>(s, 0x18, dst, n); }

// 0x4dbbe0, thiscall(stream) ret 4, returns bool: loads this object from a stream (slot 0x18 = read(dst, size)). Reads a byte block at +0x59 and the flags dword (bit 30
// dropped); flag 0x100000 adds the raw blocks +0 (0x24), +0x24 / +0x30 / +0x40 (0xc each), +0x4c and +0x6c (4 each); flag 0x40000 reads a 16-bit index (notifying the table's
// sub-object for the old id at +0x5c first) and, unless it is 0xffff, hands the 0x70-byte entry's field +0x54 to 0x4dc9c0. A bound object at +0x54 must accept the stream (slot
// 0x14, otherwise the load fails); finally 0x4dc630 gets the flags with bit 24 set and their complement.
static u8 THISCALL fn4dbbe0(u8 *self, u8 *s) {
  u32 flags;
  rd(s, (u32)(self + 0x59), 1);
  rd(s, (u32)&flags, 4);
  flags &= 0xbfffffffu;
  if (flags & 0x100000) {
    rd(s, (u32)self, 0x24);
    rd(s, (u32)(self + 0x24), 0xc);
    rd(s, (u32)(self + 0x30), 0xc);
    rd(s, (u32)(self + 0x40), 0xc);
    rd(s, (u32)(self + 0x4c), 4);
    rd(s, (u32)(self + 0x6c), 4);
  }
  if (flags & 0x40000) {
    u16 id = *(u16 *)(self + 0x5c);
    u8 *sub = *(u8 **)(*(u8 **)(*(u8 **)0x70039c + 0x9b) + 8);
    if (id) vcall<void>(sub, 0x5c, (u32)id);
    u16 v;
    rd(s, (u32)&v, 2);
    if (v != 0xffff) {
      u8 *sub2 = *(u8 **)(*(u8 **)(*(u8 **)0x70039c + 0x9b) + 8);
      u8 *base = (u8 *)vcall<u32>(sub2, 0x4c);
      ext_4dc9c0(self, D32(base + v * 0x70, 0x54));
    }
  }
  u8 *bound = *(u8 **)(self + 0x54);
  if (bound) {
    if (!(u8)vcall<u32>(bound, 0x14, (u32)s)) return 0;
  }
  flags |= 0x1000000;
  ext_4dc630(self, flags, ~flags);
  return 1;
}
PCREG(4dbbe0, fn4dbbe0);
