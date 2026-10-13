// batch311.cpp - ZActor scalar deleting destructor, 0x4775e0 (core-todo residue-02; name-map candidate ZActor::~ZActor,
// demoted). thiscall (this = ECX), one stack argument (flags), ret 4, returns this.
// Body: base destructor 0x477480 (original exe code, ecx = this). If (flags & 1): if (flags & 4) sized delete
// 0x4690b0(this, 0x77f) (cdecl, 2 arguments), else delete 0x45c510(this) (cdecl, 1 argument). Return this.
// The deletes are hooked in the spec (as in unclaimed-42): the fake heap has no free.
#include "ff.h"

extern "C" void THISCALL ext_477480(u8 *self);            // base destructor (ecx = self, no stack arguments)
extern "C" void ext_45c510(void *p);                       // delete wrapper (cdecl, 1 argument)
extern "C" void ext_4690b0(void *p, unsigned long size);   // sized delete (cdecl, 2 arguments)

static u8 *THISCALL actorScalarDeletingDtor(u8 *self, u32 flags) {
  ext_477480(self);
  if ((flags & 1) == 0)
    return self;
  if (flags & 4)
    ext_4690b0(self, 0x77f);
  else
    ext_45c510(self);
  return self;
}
PCREG(4775e0, actorScalarDeletingDtor);
