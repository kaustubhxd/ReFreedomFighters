#include "ff.h"
// batch968.cpp - unclaimed-80 gap band (docs/20-unclaimed-80.md): 0x42aae8 (high). Cdecl, four parameters (a0..a3), returns eax.
// e = ext_42acb5(a0, -1, a1, a2, a3) (cdecl, claimed elsewhere, hooked by address in the spec, returns a pointer); return ext_634da0([e], [e+4]).
extern "C" u8 *ext_42acb5(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);
extern "C" u32 ext_634da0(u32 x, u32 y);

static u32 zg42aae8(u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 *e = ext_42acb5(a0, 0xffffffff, a1, a2, a3);
  return ext_634da0(*(u32 *)e, *(u32 *)(e + 4));
}
PCREG(42aae8, zg42aae8);
