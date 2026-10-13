// batch2506.cpp - decomp area 24, batch 2506. 0x601d30 (GUESS RunTimeTypeLibrary lookup + dispatch), stdcall(a, b, c), ret 0xc.
// 0x602d30 (singleton getter, cdecl, no argument; the caller's push before it is not used by it, that push is the argument
// of the next call) -> ECX; 0x602ff0 (thiscall, one argument b, ret 4) returns an entry or null; when non-null, call slot 0
// of the object at entry+0x1c with (b, c) (thiscall, callee pops 8). Returns that result, or 0.
#include "ff.h"

extern "C" void *ext_602d30();                                         // returns [0x724694] (the library), cdecl
extern "C" u8 *THISCALL ext_602ff0(void *self, u32 key);              // lookup, thiscall, ret 4

static u32 STDCALL rttiLookup(u32 a, u32 b, u32 c) {
  (void)a;
  u8 *e = ext_602ff0(ext_602d30(), b);
  if (!e) return 0;
  void *o = *(void **)(e + 0x1c);
  typedef u32(THISCALL * fn)(void *, u32, u32);
  return (*(fn **)o)[0](o, b, c);
}
PCREG(601d30, rttiLookup);
