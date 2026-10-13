// batch1408.cpp - unclaimed-14 batch 8 (slice 13): ZHeliIf::opaqueCall(OpaqueCallParameters_t&).
#include "ff.h"

// 0x51a7d0, the tail-jump target (original code, not lifted; the same one batch 7 uses). Stdcall, pops its argument.
extern "C" void STDCALL ext_51a7d0(u8 *x);

// 0x51f250, ZHeliIf::opaqueCall(OpaqueCallParameters_t&) (medium, GUESS class): the same dispatch as ZVehicleIf::opaqueCall
// with its own table: idx = word at X+0x10; if idx < count at 0x7018d8, calls entry 0x7018e0[idx] (stdcall, pops X) and
// returns ret 4; otherwise stores idx-count back and tail-jumps to 0x51a7d0 (pops X). The port ends with `ret 4` (STDCALL).
static void STDCALL heliIfOpaqueCall(u8 *x) {
  u32 idx = *(u16 *)(x + 0x10);
  u32 count = G(u32, 0x7018d8);
  if (idx < count) {
    typedef void(STDCALL * entry_fn)(u8 *);
    entry_fn f = (entry_fn)G(u32, 0x7018e0 + idx * 4);
    f(x);
    return;
  }
  *(u16 *)(x + 0x10) = (u16)(idx - count);
  ext_51a7d0(x);
}
PCREG(51f250, heliIfOpaqueCall);
