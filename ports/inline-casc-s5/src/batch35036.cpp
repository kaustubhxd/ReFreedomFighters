// batch35036.cpp - cascade s5 batch 35036: 0x4d7540 (GUESS tear down a loaded resource: flush, free buffers, release owner and sub-object).
#include "ff.h"

extern "C" void THISCALL ext_4d7740(u8 *self);   // plain ret
extern "C" void THISCALL ext_4d7ba0(u8 *self);   // plain ret
extern "C" void ext_41e2c0(u32 p);               // cdecl, one argument
extern "C" void ext_634273(void *p, u32 n);      // CRT free-style, cdecl
typedef void(THISCALL *v1_t)(void *, u32);

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static inline void wr32u(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x4d7540, thiscall, no arguments, all fields unaligned. Nothing when [+0xd] is zero. Mode [+9] of 1 or 4: 0x4d7740(this) then 0x4d7ba0(this). Buffers [+0x4e] (with +0x4a, +0x46) and [+0x5a]
// (with +0x56, +0x52) are released with 0x41e2c0 and cleared. free([+0xd], 1), [+0xd] = 0, owner [+0x15] slot 4([+0x11]); byte +8 = 0, dword +9 = 0; [+0x6a] (when set) slot 0(1) and cleared;
// [+0x15] other than the static default 0x6e7b98 is freed (size 4) and reset to it.
static void THISCALL fn4d7540(u8 *self) {
  if (rd32u(self + 0xd) == 0) return;
  u32 m = rd32u(self + 9);
  if (m == 1 || m == 4) {
    ext_4d7740(self);
    ext_4d7ba0(self);
  }
  u32 a = rd32u(self + 0x4e);
  if (a) {
    ext_41e2c0(a);
    wr32u(self + 0x4e, 0);
    wr32u(self + 0x4a, 0);
    wr32u(self + 0x46, 0);
  }
  u32 b = rd32u(self + 0x5a);
  if (b) {
    ext_41e2c0(b);
    wr32u(self + 0x5a, 0);
    wr32u(self + 0x56, 0);
    wr32u(self + 0x52, 0);
  }
  ext_634273((void *)rd32u(self + 0xd), 1);
  u8 *owner = (u8 *)rd32u(self + 0x15);
  wr32u(self + 0xd, 0);
  (*(v1_t **)owner)[4 / 4](owner, rd32u(self + 0x11));
  u8 *c = (u8 *)rd32u(self + 0x6a);
  self[8] = 0;
  wr32u(self + 9, 0);
  if (c) {
    (*(v1_t **)c)[0](c, 1);
    wr32u(self + 0x6a, 0);
  }
  u32 p = rd32u(self + 0x15);
  if (p != 0x6e7b98) {
    ext_634273((void *)p, 4);
    wr32u(self + 0x15, 0x6e7b98);
  }
}
PCREG(4d7540, fn4d7540);
