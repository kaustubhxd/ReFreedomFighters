#include "ff.h"

extern "C" void ext_634273(u32 ptr, u32 size);
typedef void (THISCALL *allocator_fn)(void *, u32, u32, u32, u32);
typedef void (*flush_fn)();

static u8 *THISCALL fn424e70(u8 *self, u32 flags) {
  u32 id = G(u32, self + 0x24);
  if (!id) id = 0xffffu;
  u32 size = (G(u32, self + 8) << 8) + 0xau;
  ((allocator_fn)G(u32, 0x6761d4))(self, id, G(u32, self + 4), size, 0u);
  G(u32, 0x700390) = 0;
  ((flush_fn)G(u32, 0x6762ac))();
  G(u32, 0x6fd930) = 0;
  G(u32, self) = 0x679754u;
  if (flags & 1) ext_634273((u32)self, 0x2cu);
  return self;
}

PCREG(424e70, fn424e70);
