// batch424.cpp - unclaimed-42 batch 4 (claim 4, residue 1). Names from the GC name map (naming only, never committed).
// The SEH frame of the original (fs:[0] chain) is not observable in the port and is left out.
#include "ff.h"

// Sub-object destructor (thiscall, no arguments), original code.
extern "C" void THISCALL ext_4ccf60(u8 *self);
// Sized delete wrapper (cdecl pointer, size), original code; the harness hooks and logs it.
extern "C" void __attribute__((cdecl)) ext_4690b0(void *p, u32 size);

typedef void (*VoidFn)(void);

// Engine virtual slot +0x34 on the object at [0x70039c]+0x9b: (this) with one stack argument, callee pops 4.
typedef void(THISCALL *VEngine34)(u8 *self, u8 *arg);

// 0x5c24d0, ZFenceGate::~ZFenceGate() scalar deleting destructor (medium): writes the vtable word 0x6b3c58, runs three
// sub-object destructors (this+0x1ae, +0x100, +0x54), clears this+0x44 and this+0x30, writes the final vtable word 0x686874,
// makes the engine call (slot +0x34 with this), then: if bit 1 of the argument is clear, returns; if bit 2 is set,
// sized delete with size 0x25c; otherwise calls the function pointer at 0x7003b0 (no arguments) when it is not null.
// Returns this in EAX, ret 4. (In the original, a null pointer at 0x7003b0 reaches an int3 trap; the port does not model it.)
static u8 *THISCALL fenceGateDtor(u8 *self, u32 flags) {
  *(u32 *)self = 0x6b3c58;
  ext_4ccf60(self + 0x1ae);
  ext_4ccf60(self + 0x100);
  ext_4ccf60(self + 0x54);
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)self = 0x686874;

  u8 *eng = G(u8 *, 0x70039c);
  u8 *en = *(u8 **)(eng + 0x9b);
  ((VEngine34)*(u32 *)(*(u8 **)en + 0x34))(en, self);

  u8 f = (u8)flags;
  if (f & 1) {
    if (f & 4) {
      ext_4690b0(self, 0x25c);
    } else {
      VoidFn hook = G(VoidFn, 0x7003b0);
      if (hook) hook();
    }
  }
  return self;
}
PCREG(5c24d0, fenceGateDtor);
