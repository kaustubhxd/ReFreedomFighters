// batch6335.cpp - unclaimed-63 gap-band batch 35: 0x4d25f0 (C-set; no GC name), thiscall, five stack arguments (a1, a2, a3, a4, a5), ret 0x14.
//   vtbl[+0xa0](a1, 0) (thiscall virtual, callee pops 8; result unused). size = (a2 + 0x13 + a4) & ~3.
//   Y = pool allocator 0x4cd9b0 at this+0x40b4 (thiscall, size and 1; callee pops 8; it is the exe's original code, stubbed by the spec).
//   B = [this+0x4004]; B[Y] = size; p = B + Y + 4; 0x634d22(p + 0xc, a1, a2) and 0x634d22(p + 0xc + a2, a5, a4) (cdecl, caller cleans).
//   p[0] = a2, p[1] = a3, p[2] = a4. Then vtbl[+4] of the object at this+0x4008 with the argument p (thiscall, callee pops 4).
#include "ff.h"

extern "C" u32 THISCALL ext_4cd9b0(void *pool, u32 size, u32 one);   // pool allocator, original code, stubbed by the spec
extern "C" void ext_634d22(u32 dst, u32 src, u32 n);                 // cdecl import thunk, stubbed by the spec

typedef u32(THISCALL * virt_a0_fn)(void *, u32, u32);
typedef void(THISCALL * virt4_fn)(void *, u8 *);

// 0x4d25f0 (C-set).
static void THISCALL unnamed4d25f0(u8 *self, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
  u32 vt = *(u32 *)self;
  ((virt_a0_fn)(*(u32 *)(vt + 0xa0)))((void *)self, a1, 0u);
  u32 size = (a2 + 0x13u + a4) & 0xfffffffcu;
  u32 y = ext_4cd9b0((void *)(self + 0x40b4), size, 1u);
  u8 *b = *(u8 **)(self + 0x4004);
  *(u32 *)(b + y) = size;
  u8 *p = b + y + 4;
  ext_634d22((u32)(p + 0xc), a1, a2);
  ext_634d22((u32)(p + 0xc + a2), a5, a4);
  ((u32 *)p)[0] = a2;
  ((u32 *)p)[1] = a3;
  ((u32 *)p)[2] = a4;
  u8 *o = self + 0x4008;
  ((virt4_fn)(*(u32 *)(*(u32 *)o + 4)))((void *)o, p);
}
PCREG(4d25f0, unnamed4d25f0);
