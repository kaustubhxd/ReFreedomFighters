#include "ff.h"
// batch970.cpp - unclaimed-80 gap band (docs/20-unclaimed-80.md): 0x42ab26 (high). Cdecl, four parameters, returns eax.
// e = ext_42acaf(a0, a1, a2, a3) (exe code, returns the constant 0x6ff948, run for real); return ext_634d88([e], [e+4]).
extern "C" u8 *ext_42acaf(u32 a0, u32 a1, u32 a2, u32 a3);
extern "C" u32 ext_634d88(u32 x, u32 y);

static u32 zg42ab26(u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 *e = ext_42acaf(a0, a1, a2, a3);
  return ext_634d88(*(u32 *)e, *(u32 *)(e + 4));
}
PCREG(42ab26, zg42ab26);
