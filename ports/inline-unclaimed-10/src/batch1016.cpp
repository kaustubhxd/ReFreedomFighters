// batch1016.cpp - unclaimed-10, batch 12 (docs/20-unclaimed-10.md): ZRepositionCharacter::~ZRepositionCharacter() (0x5c3f90),
// thiscall, one argument (flags, ret 4). Order: vtable 0x6b3f5c; if the child at +0x48 is set, its slot 0 is called with 1;
// +0x48, +0x44, +0x30 cleared; vtable 0x686874; the engine object (global 0x70039c, field +0x9b) gets slot +0x34 with this;
// then, if bit 0 is set: bit 2 selects a sized free 0x4690b0 (this, 0x54); otherwise the global hook at 0x7003b0 is called
// when it is not null. The child call, the engine slot, 0x4690b0 and the delete are unverified callees: they run as stubs
// (child, engine) or as original code (0x4690b0; its delete 0x634273 is logged only by the spec).
#include "ff.h"

#define VT(o) (*(void ***)(o))
#define G(T, addr) (*(T *)(addr))

typedef void(THISCALL *Slot0)(u8 *self, u32 a);   // child->vt[0](1)
typedef void(THISCALL *Slot34)(u8 *self, u8 *a);  // engine->vt[+0x34](this)

extern "C" void ext_4690b0(u8 *p, u32 size);  // sized free, cdecl, original code

// 0x5c3f90, ZRepositionCharacter::~ZRepositionCharacter() (high)
static u8 *THISCALL repositionCharacterDtor(u8 *self, u32 flags) {
  u8 *child = *(u8 **)(self + 0x48);
  *(u32 *)self = 0x6b3f5c;
  if (child) ((Slot0)VT(child)[0])(child, 1);
  *(u32 *)(self + 0x48) = 0;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)self = 0x686874;
  u8 *engine = G(u8 *, 0x70039c);
  u8 *obj = *(u8 **)(engine + 0x9b);
  ((Slot34)VT(obj)[0x34 / 4])(obj, self);
  if (flags & 1) {
    if (flags & 4) {
      ext_4690b0(self, 0x54);
    } else {
      u32 hook = G(u32, 0x7003b0);
      if (hook) ((void (*)())hook)();
    }
  }
  return self;
}
PCREG(5c3f90, repositionCharacterDtor);
