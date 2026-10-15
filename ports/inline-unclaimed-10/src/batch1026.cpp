// batch1026.cpp - unclaimed-10, batch 22 (residue-10 list): ZDamageBox2::~ZDamageBox2() (0x5db6a0), scalar deleting destructor,
// thiscall, one argument (flags), ret 4. this+0x44 = 0; this+0x30 = 0; vtable 0x686874; the engine object (global 0x70039c,
// field +0x9b) gets slot +0x34 with this; then, if bit 0 is set: bit 2 selects sized free 0x4690b0 (this, 0x9f); otherwise the
// assert hook (global 0x7003b0) is called. Unverified callees: the engine slot (stubbed), 0x4690b0 (original code, its delete
// logged by the spec) and the assert hook (a logging stub in the spec).
#include "ff.h"

#define VT(o) (*(void ***)(o))
#define G(T, addr) (*(T *)(addr))

typedef void(THISCALL *SlotEng)(u8 *self, u8 *a);  // engine->vt[+0x34](this)

extern "C" void ext_4690b0(u8 *p, u32 size);  // sized free, cdecl, original code

// 0x5db6a0, ZDamageBox2::~ZDamageBox2() (dtor, high)
static u8 *THISCALL damageBox2Dtor(u8 *self, u32 flags) {
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)self = 0x686874;
  u8 *engine = G(u8 *, 0x70039c);
  u8 *obj = *(u8 **)(engine + 0x9b);
  ((SlotEng)VT(obj)[0x34 / 4])(obj, self);
  if (flags & 1) {
    if (flags & 4) {
      ext_4690b0(self, 0x9f);
    } else {
      u32 hook = G(u32, 0x7003b0);
      if (hook) ((void (*)())hook)();
    }
  }
  return self;
}
PCREG(5db6a0, damageBox2Dtor);
