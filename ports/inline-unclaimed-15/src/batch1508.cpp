#include "ff.h"
// batch1508.cpp - unclaimed-15 claim 8 (docs/20-unclaimed-15.md): CActionController::~CActionController (0x49f7e0) and
// CTargetObtained::~CTargetObtained (0x5c52a0). Both are scalar deleting destructors with the same body. Names from the GC
// name map (medium). The exe's SEH frame (fs:[0]) is stack state and is not ported.
// Stubbed in the harness: the CRT delete 0x4690b0 (cdecl, (this, size)) and the global hook at 0x7003b0 (called with no
// arguments when bit 1 is set and bit 4 is clear).

typedef u32(THISCALL *Slot1)(u8 *self, u32 a1);

extern "C" void ext_4690b0(u8 *p, u32 size);   // CRT delete, cdecl, stubbed

static void dtorCommon(u8 *self, u32 flags, u32 deleteSize) {
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)self = 0x686874;
  u8 *rm = *(u8 **)0x70039c;
  u8 *obj = *(u8 **)(rm + 0x9b);
  ((Slot1)*(u32 *)(*(u32 *)obj + 0x34))(obj, (u32)self);   // push esi; slot +0x34 takes one argument
  if (flags & 1) {
    if (flags & 4) {
      ext_4690b0(self, deleteSize);
    } else {
      void (*hook)() = (void (*)())*(u32 *)0x7003b0;
      if (hook)
        hook();
    }
  }
}

// 0x49f7e0, CActionController::~CActionController() (medium), delete size 0x8b4.
static u32 THISCALL actionControllerDtor(u8 *self, u32 flags) {
  dtorCommon(self, flags, 0x8b4);
  return (u32)self;
}
PCREG(49f7e0, actionControllerDtor);

// 0x5c52a0, CTargetObtained::~CTargetObtained() (medium), delete size 0x153.
static u32 THISCALL targetObtainedDtor(u8 *self, u32 flags) {
  dtorCommon(self, flags, 0x153);
  return (u32)self;
}
PCREG(5c52a0, targetObtainedDtor);
