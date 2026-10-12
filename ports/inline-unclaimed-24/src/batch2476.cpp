// batch2476.cpp - decomp area 24, batch 2476: two destructors (base, then SetState or delete by the flag).
#include "ff.h"

extern "C" void THISCALL ext_4553d0(void *self);    // ZParticleTemplate base destructor (recorder)
extern "C" void THISCALL ext_45a5a0(void *self);    // ZPICOBJ base destructor (recorder)
extern "C" void ext_4690b0(void *self, u32 state);  // ZRenderGC::SetState (cdecl)
extern "C" void ext_45c510(void *p);                // ZGEOM::operator delete (cdecl)

static void releaseByFlag(u8 *self, u32 flag, u32 state) {
  if (flag & 1u) {
    if (flag & 4u)
      ext_4690b0(self, state);
    else
      ext_45c510(self);
  }
}

// 0x455580 ZParticleTemplate::~ZParticleTemplate, thiscall, ret 4, eax = this.
static u8 *THISCALL particleTemplateDtor(u8 *self, u32 flag) {
  ext_4553d0(self);
  releaseByFlag(self, flag, 0xf1u);
  return self;
}
PCREG(455580, particleTemplateDtor);

// 0x45a640 ZPICOBJ::~ZPICOBJ, thiscall, ret 4, eax = this.
static u8 *THISCALL picObjDtor(u8 *self, u32 flag) {
  ext_45a5a0(self);
  releaseByFlag(self, flag, 0x37u);
  return self;
}
PCREG(45a640, picObjDtor);
