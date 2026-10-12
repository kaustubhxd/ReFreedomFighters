// batch2304.cpp - unclaimed-23 batch 4 (docs/20-unclaimed-23.md): ZVehicleIf::addMethodDefinitions(OpaqueMethodList_t&) at
// 0x51aba0. Name from the GC name map (high). The method list has a flag byte at +0xc. While the flag is set, four blocks run
// in order; each adds a function address (0x51aaf0, 0x51aaa0, 0x51ab70, 0x51ab40) to a table at 0x701738 with the count
// at 0x701730 (up to 50 entries). Once the count is 50 or more, each block calls this->vtbl[+0x44](0x69f3b8) and then the
// hook at 0x7003b0 (an int3 fault if null). The list flag is then cleared and 0x519ea0 is called with this in ECX and the
// list as its one stack argument. Callee pops 4 (ret 4).
#include "ff.h"

extern "C" void THISCALL ext_519ea0(void *self, u8 *list);   // original code, stubbed by the spec

// 0x51aba0 (high).
static void THISCALL vehicleIfAddMethodDefinitions(u8 *self, u8 *list) {
  static const u32 kFns[4] = {0x51aaf0, 0x51aaa0, 0x51ab70, 0x51ab40};
  typedef void(THISCALL * call1_fn)(void *, u32);
  if (list[0xc]) {
    for (u32 k = 0; k < 4; k++) {
      if (!list[0xc])
        break;
      u32 count = G(u32, 0x701730);
      if (count < 50) {
        G(u32, 0x701738 + count * 4) = kFns[k];
        G(u32, 0x701730) = count + 1;
      } else {
        ((call1_fn)(*(u32 *)(*(u32 *)self + 0x44)))(self, 0x69f3b8);
        typedef void (*hook_fn)(void);
        u32 hook = G(u32, 0x7003b0);
        if (!hook)
          __builtin_trap();
        ((hook_fn)hook)();
      }
    }
  }
  list[0xc] = 0;
  ext_519ea0(self, list);
}
PCREG(51aba0, vehicleIfAddMethodDefinitions);
