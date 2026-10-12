// batch2477.cpp - decomp area 24, batch 2477.
#include "ff.h"

extern "C" void THISCALL ext_43de70(void *self);                 // base destructor (recorder)
extern "C" void ext_4690b0(void *self, u32 state);               // ZRenderGC::SetState (cdecl)
extern "C" void ext_45c510(void *p);                             // ZGEOM::operator delete (cdecl)
extern "C" u32 THISCALL ext_448a30(void *self, void *db);        // ZLIGHT::CopyDataBlock(DBLK*)
extern "C" u32 THISCALL ext_4e1b30(void *db);                    // DBLK::NextBlock()
extern "C" u32 THISCALL ext_4e12e0(void *db, u32 *out, u32 count);  // DBLK::Get(unsigned int*, int)

static void releaseByFlag(u8 *self, u32 flag, u32 state) {
  if (flag & 1u) {
    if (flag & 4u)
      ext_4690b0(self, state);
    else
      ext_45c510(self);
  }
}

// 0x44cad0 ~ZBoneParticle, thiscall, ret 4, eax = this.
static u8 *THISCALL boneParticleDtor(u8 *self, u32 flag) {
  *(u32 *)self = 0x6801a4u;
  ext_43de70(self);
  releaseByFlag(self, flag, 0x24u);
  return self;
}
PCREG(44cad0, boneParticleDtor);

// 0x44cb60 ~ZMotionBlur, thiscall, ret 4, eax = this.
static u8 *THISCALL motionBlurDtor(u8 *self, u32 flag) {
  *(u32 *)self = 0x6807f8u;
  ext_43de70(self);
  releaseByFlag(self, flag, 0x4b0u);
  return self;
}
PCREG(44cb60, motionBlurDtor);

// 0x4489c0 ZGateLightOmni::CopyDataBlock(DBLK*), thiscall, ret 4.
static void THISCALL gateLightOmniCopyDataBlock(u8 *self, void *db) {
  ext_448a30(self, db);
  ext_4e1b30(db);
  ext_4e12e0(db, (u32 *)(self + 0x1c), 1u);
  ext_4e12e0(db, (u32 *)(self + 0x20), 1u);
  ext_4e1b30(db);
}
PCREG(4489c0, gateLightOmniCopyDataBlock);
