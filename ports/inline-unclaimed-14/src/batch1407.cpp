// batch1407.cpp - unclaimed-14 batch 7 (slice 13): ZVehicleIf::opaqueCall(OpaqueCallParameters_t&).
#include "ff.h"

// 0x51a7d0, the tail-jump target of this function (original code, not lifted). Stdcall: it pops its one argument (ret 4).
extern "C" void STDCALL ext_51a7d0(u8 *x);

// 0x51ad90, ZVehicleIf::opaqueCall(OpaqueCallParameters_t&) (medium, GUESS class): one stack argument X, ret 4 (stdcall).
// idx = the word at X+0x10. If idx < the count at 0x701730, calls table entry 0x701738[idx] with X as its one stack argument
// (stdcall; the entry pops X) and returns with ret 4. Otherwise stores idx-count back into the word at X+0x10 and
// tail-jumps to 0x51a7d0 with X (that callee pops X). The port makes the same calls and ends with `ret 4` (STDCALL), so the
// ESP after return matches the PC in both branches: the callee pops X in each, and the outer ret 4 pops the same 4 bytes.
static void STDCALL vehicleIfOpaqueCall(u8 *x) {
  u32 idx = *(u16 *)(x + 0x10);
  u32 count = G(u32, 0x701730);
  if (idx < count) {
    typedef void(STDCALL * entry_fn)(u8 *);
    entry_fn f = (entry_fn)G(u32, 0x701738 + idx * 4);
    f(x);
    return;
  }
  *(u16 *)(x + 0x10) = (u16)(idx - count);
  ext_51a7d0(x);
}
PCREG(51ad90, vehicleIfOpaqueCall);
