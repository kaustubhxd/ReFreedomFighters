// batch240008.cpp - Sonnet-w4a: CRT atexit-style registration through an encoded pointer.
#include "ff.h"

extern "C" u32 THISCALL ext_634aae(u32 self, u32 a, u32 b, u32 c);   // import thunk, ecx = this, 3 stack args, callee pops
extern "C" void ext_6345fd();
extern "C" void ext_6345b0();

// 0x634609: cdecl(a): [0x7257f4] == 0: f = ror(cookie ^ [0x7257f8], cookie & 31); thunk 634aae(f; 0x7257f0, 0x7257d8, a);
// returns f() != 0; else 6345fd(), r = import [0x6760b8]([0x7257f4], a, 0), 6345b0(), returns r == 0
static u32 fn_634609(u32 a) {
  u32 v = G(u32, 0x7257f4);
  if (v == 0) {
    u32 c = G(u32, 0x6f5630);
    u32 x = c ^ G(u32, 0x7257f8);
    u32 n = c & 0x1f;
    u32 f = n ? (x >> n) | (x << (32 - n)) : x;
    ext_634aae(f, 0x7257f0, 0x7257d8, a);
    return ((u32(*)())f)() != 0;
  }
  ext_6345fd();
  u32 r = (*(u32(__stdcall **)(u32, u32, u32))0x6760b8)(G(u32, 0x7257f4), a, 0);
  ext_6345b0();
  return r == 0;
}
PCREG(634609, fn_634609);
