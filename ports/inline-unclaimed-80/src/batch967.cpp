#include "ff.h"
// batch967.cpp - unclaimed-80 gap band (docs/20-unclaimed-80.md): 0x42ac38 and 0x42ac08 (high). Both cdecl.
// 0x42ac38(p0..p4): return ext_42ac08(p0, p1, p2, p3, 0, p4) (eax passes through; the caller pops the five parameters).
// 0x42ac08(a0..a5): e = ext_42acaf(a0..a5) (cdecl, returns a pointer; exe code run for real); r = ext_634d9a([e], [e+4]) (cdecl, IAT thunk,
// hooked by address in the spec); return r < 0 ? 0xffffffff : r. The caller pops the six parameters with the two pushed for 634d9a.

extern "C" u32 ext_42ac08(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5);
extern "C" u8 *ext_42acaf(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5);
extern "C" u32 ext_634d9a(u32 x, u32 y);

static u32 zg42ac38(u32 p0, u32 p1, u32 p2, u32 p3, u32 p4) {
  return ext_42ac08(p0, p1, p2, p3, 0, p4);
}
PCREG(42ac38, zg42ac38);

static u32 zg42ac08(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
  u8 *e = ext_42acaf(a0, a1, a2, a3, a4, a5);
  u32 r = ext_634d9a(*(u32 *)e, *(u32 *)(e + 4));
  if ((s32)r < 0) return 0xffffffff;
  return r;
}
PCREG(42ac08, zg42ac08);
