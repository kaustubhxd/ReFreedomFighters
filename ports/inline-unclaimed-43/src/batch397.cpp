// batch397.cpp - 0x5095f0 (core: ZActorIf::opaqueCall, stdcall, one argument obj, ret 4). idx = word obj+0x10.
// If idx < count (global 0x701048): call table[idx] (global table 0x701050) with obj as its one stdcall argument.
// Otherwise word obj+0x10 = idx - count, and tail-jump to 0x5060b0 (hooked by address in the spec, GUESS: body not ported)
// with obj as its argument.
#include "ff.h"

typedef void(STDCALL *ActorOpaqueFn)(void *obj);

extern "C" void STDCALL ext_5060b0(void *obj);   // tail target by address (hooked in the spec)

static void STDCALL actorOpaqueCallByIndex(u8 *obj) {
  u32 idx = *(u16 *)(obj + 0x10);
  u32 count = G(u32, 0x701048);
  if (idx < count) {
    ActorOpaqueFn f = (ActorOpaqueFn)(unsigned long)G(u32, 0x701050 + 4 * idx);
    f(obj);
    return;
  }
  *(u16 *)(obj + 0x10) = (u16)(idx - count);
  ext_5060b0(obj);
}
PCREG(5095f0, actorOpaqueCallByIndex);
