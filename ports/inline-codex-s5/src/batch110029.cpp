#include "ff.h"
// ---------------------------------------------------------------- 0x481570 ZPlayer::CalcBonesFromMotion(4 x const float*) [high]
// thiscall, ret 0x10. The animation controller at +0x455 picks the anim for this frame's motion and returns a blend
// weight; the player switches to it and updates the blend.
static void THISCALL playerCalcBonesFromMotion(u8 *self, const float *a0, const float *a1, const float *a2,
                                               const float *a3) {
  u8 *link = *(u8 **)(self + 0x6c);
  *(u32 *)(link + 0x65) = 0;
  *(u32 *)(link + 0x251) = 0;
  if (!vcall<u8>(self, 0x324, 0u) || (vcall<u8>(self, 0x320, 0u) & 0x20)) {
    u32 anim = 0;
    float w = vcall<float>(*(u8 **)(self + 0x455), 0x24, &anim, a0, a1, a2, a3);
    if (*(float *)(self + 0x612) > w && anim) {
      vcall<void>(self, 0x268, anim, *(u32 *)((u8 *)anim + 0x7c));
    }
    *(float *)(self + 0x612) = w;
    if (!anim) {
      anim = *(u32 *)(self + 0x424);
      if (!anim)
        goto done;
    }
    if (*(u32 *)(self + 0x417) & 0x40000)
      goto done;
    if (*(u32 *)(self + 0x424) != anim) {
      if (*(u32 *)(self + 0x424))
        *(float *)(self + 0x428) = (float)*(s32 *)(G(u8 *, 0x70039c) + 0x40) * 0.0009765625f;  // [0x6785e4]
      else
        *(u32 *)(self + 0x428) = 0xc47a0000u;  // -1000.0
      *(u32 *)(self + 0x424) = anim;
    }
    {
      void **vt = *(void ***)self;
      float g = vcall<float>(*(u8 **)(self + 0x455), 0x30, anim);  // ZMovementBase::BlendInSpeed(const AnimHeader*)
      // ZLNKOBJ::SetBoneFrameBlend(AnimHeader*, float, float, bool, unsigned int) [high]
      ((void(THISCALL *)(u8 *, u32, float, float, u32, u32))vt[0x244 / 4])(self, anim, w, g, 0, 0);
    }
    if (!vcall<u8>(*(u8 **)(self + 0x455), 0x28))
      vcall<void>(self, 0x5f8, w);
  }
done:
  vcall<void>(self, 0x3e0);
}
PCREG(481570, playerCalcBonesFromMotion);

