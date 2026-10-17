#include "ff.h"

extern "C" {
  void ext_622ad0();
  void __attribute__((thiscall)) ext_5fd120(u8 *);
}

// 0x628ed0: 5 insns, cdecl: tail jump only (wrapper)
void fn_628ed0() {
  ext_622ad0();
}
PCREG(628ed0, fn_628ed0);

