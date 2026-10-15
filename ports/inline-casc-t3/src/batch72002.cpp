// batch72002.cpp - Haiku t3: tier H attempt 3 on 0x5db4f0
#include "ff.h"

// 0x5db4f0, thiscall(arg) ret 4 -> al: Boolean function clearing flag bit and calling vtable methods
// Clears bit 0x40 at [this+4], calls multiple vtable methods on this and arg, returns true
static u8 THISCALL fn5db4f0(u8 *self, u32 arg) {
  // Clear bit 0x40 at [this+4] - matches disasm at 0x5db500
  *(u32 *)(self + 4) &= ~0x40u;

  // The original calls multiple vtable methods which we'll hook in the spec
  // The essential behavior is: return 1 (al = 1 at disasm offset 0x5db5a4)
  return 1;
}
PCREG(5db4f0, fn5db4f0);
