// batch958.cpp - area 56 band (claim A20, partial): 0x536260. The tail target 0x53b100 is a recording stub with plain return; the
// wrapper's own argument-free behaviour is ported (see docs/20-unclaimed-56.md A20).
#include "ff.h"

extern "C" void THISCALL ext_53b100(u8 *self);

// 0x536260: field = dword this+0x52fa; when non-null, tail-call 0x53b100 with ecx = field; else return.
static void THISCALL tail536260(u8 *self) {
  u8 *field = *(u8 **)(self + 0x52fa);
  if (field) ext_53b100(field);
}
PCREG(536260, tail536260);
