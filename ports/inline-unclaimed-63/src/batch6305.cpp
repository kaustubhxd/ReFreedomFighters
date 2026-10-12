// batch6305.cpp - unclaimed-63 batch 5 (docs/20-unclaimed-63.md): three scalar-deleting destructors with the same shape.
//   0x49f720 CAction::~CAction()           (GC name, medium)  constant 0x10a
//   0x5db760 ZFireDamageBox::~ZFireDamageBox() (GC name, medium)  constant 0x8c
//   0x5dd060 ZFFMortar::~ZFFMortar()       (GC name, medium)  constant 0x7e
// Body: this+0x44 = 0; this+0x30 = 0; this->vptr = 0x686874; call the render-manager object's vtbl+0x34 with this;
// if (flags & 1): if (flags & 4) == 0, call the hook at 0x7003b0 (cdecl, no arguments; the PC faults if it is null);
// otherwise call 0x4690b0(this, constant) (cdecl, caller cleans). Returns this (thiscall, ret 4).
// The PC's SEH frame (fs:[0] handler 0x66b0fc, the cookie at 0x6f5630) is NOT reproduced: it only matters if an exception
// is thrown inside the body, which these paths do not do. The stack cookie is not checked in these functions either.
#include "ff.h"

extern "C" void ext_4690b0(void *self, u32 k);   // cdecl, original code, stubbed by the spec

typedef void(THISCALL * call1_fn)(void *, u32);

static void dtorBody(u8 *self, u32 flags, u32 k) {
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)self = 0x686874;
  u32 rm = G(u32, 0x70039c);
  u32 o = *(u32 *)(rm + 0x9b);
  ((call1_fn)(*(u32 *)(*(u32 *)o + 0x34)))((void *)o, (u32)self);
  if ((u8)flags & 1) {
    if (((u8)flags & 4) == 0) {
      u32 hook = G(u32, 0x7003b0);
      if (!hook)
        __builtin_trap();
      ((void (*)(void))hook)();
    } else {
      ext_4690b0(self, k);
    }
  }
}

// 0x49f720, CAction::~CAction() (medium).
static void THISCALL actionDtor(u8 *self, u32 flags) { dtorBody(self, flags, 0x10a); }
PCREG(49f720, actionDtor);

// 0x5db760, ZFireDamageBox::~ZFireDamageBox() (medium).
static void THISCALL fireDamageBoxDtor(u8 *self, u32 flags) { dtorBody(self, flags, 0x8c); }
PCREG(5db760, fireDamageBoxDtor);

// 0x5dd060, ZFFMortar::~ZFFMortar() (medium).
static void THISCALL ffMortarDtor(u8 *self, u32 flags) { dtorBody(self, flags, 0x7e); }
PCREG(5dd060, ffMortarDtor);
