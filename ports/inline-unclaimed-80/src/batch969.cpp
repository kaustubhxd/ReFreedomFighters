#include "ff.h"
// batch969.cpp - unclaimed-80 gap band (docs/20-unclaimed-80.md): 0x42ab81 (high). Cdecl, four parameters, returns eax.
// e = ext_42acb5(a0, a1, a2, a3) (cdecl, claimed elsewhere, hooked by address in the spec); return ext_634d8e([e], [e+4]).
extern "C" u8 *ext_42acb5(u32 a0, u32 a1, u32 a2, u32 a3);
extern "C" u32 ext_634d8e(u32 x, u32 y);

static u32 zg42ab81(u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 *e = ext_42acb5(a0, a1, a2, a3);
  return ext_634d8e(*(u32 *)e, *(u32 *)(e + 4));
}
PCREG(42ab81, zg42ab81);
