// batch637.cpp - band 0x421000-0x441000, batch 637: one function.
//   0x424590 (thiscall, two args ret 8, returns edx:eax): calls exe 0x4248e0, stores result;
//     calls vtable[0x1fc] with stack args; returns two dwords (result pair from locals).
#include "ff.h"

typedef u32(*ext_4248e0_t)();
typedef u32(THISCALL *vslot_1fc_t)(void *self, u32 arg1, void *local_addr, u32 val1, u32 val2, u32 arg2);

static u64 THISCALL func_424590(u8 *self, u32 arg1, u32 arg2) {
  u32 local_lo, local_hi;

  // Call exe function 0x4248e0 (no args)
  ext_4248e0_t ext_fn = (ext_4248e0_t)G(void *, 0x4248e0);
  local_lo = ext_fn();

  // Call vtable slot 0x1fc with various args
  void **vtable = *(void ***)self;
  void *local_addr = &local_lo;
  local_hi = ((vslot_1fc_t)vtable[0x1fc / 4])(self, arg1, local_addr, 0x8, 0x10, arg2);

  // Return edx:eax (local_hi:local_lo)
  return ((u64)local_hi << 32) | local_lo;
}
PCREG(424590, func_424590);
