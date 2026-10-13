// batch1045.cpp - area 81, batch 1045: 0x663b40, stdcall (one argument p), ret 4. If p is non-null, calls its vtable slot 0x28 with ecx = p (no
// arguments). No SEH frame, no cookie check. No stand-ins; the slot is a GUESS stub in the spec.
#include "ff.h"

#define STDCALL __attribute__((stdcall))

// 0x663b40 (stdcall: p).
static void STDCALL callSlot28IfSet(u8 *p) {
  if (p)
    vcall<void>(p, 0x28);
}
PCREG(663b40, callSlot28IfSet);
