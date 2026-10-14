// batch958.cpp - 0x557c20 (no name in the map), read in full (2026-10-12). Thiscall (ECX = this), one arg (a), ret 4, void.
// Accessor 0x5003d0 (stood in) on ECX = [a+4] with indices 0..3 gives dwords d0..d3. x = 0x59dae0 (stood in; thiscall on ECX = [this+0x1c],
// five stack words, ret 0x14) with (d0, d1, d2, 1, d3). Then the setter 0x5002f0 (stood in; ret 4) on ECX = acc([a+8], 0) with x.
#include "ff.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" void *THISCALL ext_5003d0(void *self, u32 idx);                          // stood in (one arg, returns a pointer)
extern "C" u32 THISCALL ext_59dae0(void *self, u32 a, u32 b, u32 c, u32 k, u32 d);  // stood in (ret 0x14)
extern "C" void THISCALL ext_5002f0(void *item, u32 value);                         // typed setter (ret 4)

// 0x557c20 (no name in the map).
static void THISCALL Apply557c20(u8 *self, u8 *a) {
  u32 d0 = U32(ext_5003d0(FP(a, 4), 0u), 0);
  u32 d1 = U32(ext_5003d0(FP(a, 4), 1u), 0);
  u32 d2 = U32(ext_5003d0(FP(a, 4), 2u), 0);
  u32 d3 = U32(ext_5003d0(FP(a, 4), 3u), 0);
  u32 x = ext_59dae0(FP(self, 0x1c), d0, d1, d2, 1u, d3);
  ext_5002f0(ext_5003d0(FP(a, 8), 0u), x);
}
PCREG(557c20, Apply557c20);
