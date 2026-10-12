// batch2483.cpp - decomp area 24, batch 2483.
#include "ff.h"

// 0x4a0e90 CAction::FrameUpdate(), thiscall, ret 0 (the name map gives a ZGEOM* parameter, but the code takes none).
static void THISCALL actionFrameUpdate(u8 *self) {
  *(u32 *)(self + 0x5a) |= 1;
}
PCREG(4a0e90, actionFrameUpdate);

// 0x5e7590 ZFFHeroMovementBaseMove::WantControl(const float*, const float*, const float*), thiscall, ret 0xc, AL = 1.
static u8 THISCALL heroWantControl(void *self, const float *a, const float *b, const float *c) {
  (void)self;
  (void)a;
  (void)b;
  (void)c;
  return 1;
}
PCREG(5e7590, heroWantControl);

// 0x5c4190 ZRepositionCharacter::End(), thiscall. Tail jump: the child at +0x48 gets slot 0xc, so the callee returns to our caller.
static void THISCALL repositionEnd(u8 *self) {
  vcall<void>(*(void **)(self + 0x48), 0xc);
}
PCREG(5c4190, repositionEnd);
