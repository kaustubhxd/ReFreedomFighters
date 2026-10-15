// batch1610.cpp - ZIKLNKOBJ::PlaySoundFootStep (soundtimers thread, 2026-10-11).
#include "st.h"

static inline u8 *sys() { return *(u8 *volatile *)0x70039c; }
typedef u32(THISCALL *AddSound3dFn)(void *grp, float *mat, float *pos, u32 sound, u32, u32, u32);
typedef void(FASTCALL *MCpyFn)(float *dst, const float *src);            // 0x4de420 mcpy: 3x3 matrix copy
typedef void(FASTCALL *VAddScalarFn)(float *v, const float *a, float s);  // 0x451890: v += a * s (x87)
extern "C" char ext_43ec00[], ext_4de420[], ext_451890[];

// 0x4670b0 ZIKLNKOBJ::PlaySoundFootStep(bool right) [high]. Needs the sound DLL and a footwear id (+0x14f).
// Position: with real foot positions (+0x146) the foot bone (vtable +0x3b8 right / +0x3b4 left, result passed to
// +0x390), else the object's root; then moved 10 units along matrix row 0. Sound: DLL +0x58(ground material,
// footwear) with the material from +0x14b, else +0x147; if none, the "Default" material (DLL +0x5c("Default")).
// Started with AddSound3d(mat, pos, sound, 4, database +0x4c(this), 0) when +0x144 is set, else (.., 0xc, 0, 0).
// The flags are not touched afterwards, so footsteps keep AddSound3d's flag 4 (graph-tested).
u32 THISCALL ZIKLNKOBJ_PlaySoundFootStep(void *self, u32 right) {
  if (!AT(void *, sys(), 0x1a9f)) return 0;
  if (!AT(u32, self, 0x14f)) return 0;
  float mat[9], pos[3];
  if (AT(u8, self, 0x146)) {
    void *x = (u8)right ? vcall<void *>(self, 0x3b8, mat, pos) : vcall<void *>(self, 0x3b4, mat, pos);
    vcall<void>(self, 0x390, x);
  } else {
    ((MCpyFn)(void *)ext_4de420)(mat, AT(float *, self, 8));
    u8 *m = AT(u8 *, self, 8);
    pos[0] = AT(float, m, 0x24);
    pos[1] = AT(float, m, 0x28);
    pos[2] = AT(float, m, 0x2c);
  }
  ((VAddScalarFn)(void *)ext_451890)(pos, mat, 10.0f);
  u32 ground = AT(u32, self, 0x14b);
  if (!ground) ground = AT(u32, self, 0x147);
  u32 s = vcall<u32>(AT(void *, sys(), 0x1a9f), 0x58, ground, AT(u32, self, 0x14f));
  if (!s) {
    u32 def = vcall<u32>(AT(void *, sys(), 0x1a9f), 0x5c, (const char *)0x686078);  // "Default"
    s = vcall<u32>(AT(void *, sys(), 0x1a9f), 0x58, def, AT(u32, self, 0x14f));
    if (!s) return 0;
  }
  u32 a4, a5;
  if (AT(u8, self, 0x144)) {
    a5 = vcall<u32>(AT(void *, sys(), 0x9b), 0x4c, self);
    a4 = 4;
  } else {
    a5 = 0;
    a4 = 0xc;
  }
  void *grp = vcall<void *>(self, 0x20);
  return ((AddSound3dFn)(void *)ext_43ec00)(grp, mat, pos, s, a4, a5, 0);
}
PCREG(4670b0, ZIKLNKOBJ_PlaySoundFootStep);
