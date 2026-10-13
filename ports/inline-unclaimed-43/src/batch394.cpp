// batch394.cpp - 0x55ec30 (core: ZFFActorIf::opaqueCall, stdcall, one argument obj, ret 4). idx = word obj+0x10.
// If idx < count (global 0x713f10): call table[idx] (global table 0x713f18) with obj as its one stdcall argument.
// Otherwise word obj+0x10 = idx - count, and tail-jump to 0x5095f0 (ZActorIf::opaqueCall; hooked by address in the spec,
// GUESS: body not ported) with obj as its argument.
#include "ff.h"

typedef void(STDCALL *OpaqueFn)(void *obj);

extern "C" void STDCALL ext_5095f0(void *obj);   // tail target by address (hooked in the spec)

static void STDCALL opaqueCallByIndex(u8 *obj) {
  u32 idx = *(u16 *)(obj + 0x10);
  u32 count = G(u32, 0x713f10);
  if (idx < count) {
    OpaqueFn f = (OpaqueFn)(unsigned long)G(u32, 0x713f18 + 4 * idx);
    f(obj);
    return;
  }
  *(u16 *)(obj + 0x10) = (u16)(idx - count);
  ext_5095f0(obj);
}
PCREG(55ec30, opaqueCallByIndex);
