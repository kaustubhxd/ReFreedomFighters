// batch33.cpp - walk-tree lift, inline session batch 33 (Haiku, night): CalcNewSpeed.
#include "ff.h"

typedef void(THISCALL *vcallGetSpeeds)(void *self, float *out);
extern "C" void THISCALL ext_4e0d80(float *v, float s);     // vsetlen, original code (lifted in batch 31)
extern "C" u8 *THISCALL ext_5e3dd0(u8 *self, u32 status);   // GetAnimFromStatus, original code (lifted in batch 32)

// 0x5e17b0, thiscall, four stack args (two unused, then outA and outB), ret 0x10. The flag word fl is [[this+4]+0x417].
// If the byte at this+0x371 is zero, the object at this+0x36d gets a virtual call through slot 0x5c4 (ZPlayer::GetMoveSpeeds)
// with a float triple; the triple is then reloaded (zeros if the call was skipped). outA and outB are zeroed. Speed s is the
// float at the object's +0x80f when the byte at this+0x372 is zero, else 0. If fl has bit 0x20, s is negated and stored at
// outB+4; with only bit 0x40, s is stored at outB+4 without negation. The triple goes to outA. The anim pointer from
// GetAnimFromStatus(fl) goes to this+0x21; s becomes 1.0 or the float at anim+4 and vsetlen(outA, s) runs. Name
// ZFFHeroMovementBaseMove::CalcNewSpeed. The stack-cookie epilogue is the CRT's own check and is not part of the port.
static void THISCALL calcNewSpeed(u8 *self, u32 unusedA, u32 unusedB, float *outA, float *outB) {
  (void)unusedA;
  (void)unusedB;
  float xyz[3] = {0.0f, 0.0f, 0.0f};
  u32 fl = *(u32 *)(*(u8 **)(self + 4) + 0x417);
  if (self[0x371] == 0) {
    void *obj = *(void **)(self + 0x36d);
    void **vt = *(void ***)obj;
    ((vcallGetSpeeds)vt[0x5c4 / 4])(obj, xyz);
  }
  outA[0] = 0.0f;
  outA[1] = 0.0f;
  outA[2] = 0.0f;
  outB[0] = 0.0f;
  outB[1] = 0.0f;
  outB[2] = 0.0f;
  float s = 0.0f;
  if (self[0x372] == 0) {
    void *obj = *(void **)(self + 0x36d);
    s = *(float *)((u8 *)obj + 0x80f);
  }
  *(u32 *)(self + 0x21) = 0;
  if (fl & 0x20) {
    s = -s;
    outB[1] = s;
  } else if (fl & 0x40) {
    outB[1] = s;
  }
  outA[0] = xyz[0];
  outA[1] = xyz[1];
  outA[2] = xyz[2];
  u8 *anim = ext_5e3dd0(self, fl);
  *(u8 **)(self + 0x21) = anim;
  float ss = G(float, 0x678858);
  if (anim != 0)
    ss = *(float *)(anim + 4);
  ext_4e0d80(outA, ss);
}
PCREG(5e17b0, calcNewSpeed);
