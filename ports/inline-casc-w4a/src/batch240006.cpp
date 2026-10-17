// batch240006.cpp - Sonnet-w4a: CRT onexit table initialisation.
#include "ff.h"

extern "C" u32 ext_634cb5();
extern "C" u32 ext_634e72(u32 p);       // import thunk, cdecl 1 arg (table init)
extern "C" u32 ext_634879(u32 code);    // fatal handler (does not return)

// 0x633d6e: cdecl(mode) mode 0 or 1 (else fatal 5): with the helper flag set and mode 0 initialises both onexit tables
// through the import (stops early when the first fails); otherwise fills 12 bytes at 0x725498 and 12 at 0x7254a4 with ~cookie
static u32 fn_633d6e(u32 mode) {
  if (mode != 0 && mode != 1) return ext_634879(5);
  if (ext_634cb5() && mode == 0) {
    u32 r = ext_634e72(0x725498);
    if (r != 0) return r & ~0xffu;
    u32 r2 = ext_634e72(0x7254a4);
    u32 nr = 0 - r2;
    return (nr & ~0xffu) | (r2 != 0 ? 0u : 1u);
  }
  u32 v = ~G(u32, 0x6f5630);
  for (int i = 0; i < 3; i++) {
    G(u32, 0x725498 + 4 * i) = v;
    G(u32, 0x7254a4 + 4 * i) = v;
  }
  return (v & ~0xffu) | 1;
}
PCREG(633d6e, fn_633d6e);
