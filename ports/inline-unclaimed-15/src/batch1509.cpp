#include "ff.h"
// batch1509.cpp - unclaimed-15 claim 9 (docs/20-unclaimed-15.md): CImpactResponse::~CImpactResponse() (0x5dc0e0), scalar
// deleting. Name from the GC name map (high). Thiscall, one argument (flags, bit 1 = delete), ret 4.
// Stubbed in the harness: the member's slot 0 (logged), the render sub-object's slot +0x34 (logged, one argument: this),
// the CRT delete 0x4690b0 (cdecl, (this, size)) and the global hook 0x7003b0 (always non-null in the spec).

typedef u32(THISCALL *Slot1)(u8 *self, u32 a1);

extern "C" void ext_4690b0(u8 *p, u32 size);   // CRT delete, cdecl, stubbed

// 0x5dc0e0, CImpactResponse::~CImpactResponse() (high).
static u32 THISCALL impactResponseDtor(u8 *self, u32 flags) {
  u8 *member = *(u8 **)(self + 0x48);
  *(u32 *)self = 0x6b6ab8;
  if (member)
    ((Slot1)*(u32 *)(*(u32 *)member + 0))(member, 1);
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)self = 0x686874;
  u8 *rm = *(u8 **)0x70039c;
  u8 *obj = *(u8 **)(rm + 0x9b);
  ((Slot1)*(u32 *)(*(u32 *)obj + 0x34))(obj, (u32)self);
  if (flags & 1) {
    if (flags & 4) {
      ext_4690b0(self, 0x80);
    } else {
      void (*hook)() = (void (*)())*(u32 *)0x7003b0;
      if (hook)
        hook();
    }
  }
  return (u32)self;
}
PCREG(5dc0e0, impactResponseDtor);
