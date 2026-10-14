// batch848.cpp - area 50 (residue-10 list): CFireController::DrawActorsOnFire() [0x582aa0, 226 instr].
// Per entry of the array at this+0x50 (stride 0x1c, count at this+0x4c): the entry's key is looked up in the engine's
// manager (vt +0x58), the object's vt +0x80 gives a matrix and an offset, the entry's position (+8) is moved towards the
// offset and scaled by 1/dt, and two positions are sent to the fire object (vt +0x218). While the fire timer this+0xa60
// is below zero, explosion data is emitted (engine vt +0x1c4 calls). Finally the timer is clamped back above zero.
// The exe's stack cookie (fs-less __security_check_cookie at 0x633654) is not reproduced: the port has no check path.
#include "ff.h"

extern "C" void THISCALL ext_456b70(void *tmpl, u32 *ctlA, u32 *ctlB);   // ZParticleTemplate::GetController (not ported here)
extern "C" void THISCALL ext_4daf90(u8 *self, float *vec);                 // ZBaseGeom::GetCen (not ported here)
extern "C" FASTCALL void ext_43e8e0(float *d, const float *a, const float *b);   // d = a + b
extern "C" FASTCALL void ext_43e920(float *d, const float *a, const float *b);   // d = a - b
extern "C" THISCALL void ext_4e0d00(float *v, float s);                          // v *= s
extern "C" FASTCALL void ext_4419f0(float *v, const float *m);                   // v = v * M
extern "C" FASTCALL void ext_441940(float *v, const float *a);                   // v += a

static void THISCALL DrawActorsOnFire(u8 *self) {
  u8 *eng = G(u8 *, 0x70039c);
  u8 *mgr = *(u8 **)(eng + 0x9b);
  u8 *obj = vcall<u8 *>(mgr, 0x58, *(u32 *)(self + 0x48));
  if (!obj) return;
  u32 ctlA = 0, ctlB = 0;
  ext_456b70(obj, &ctlA, &ctlB);
  u8 *ctl = vcall<u8 *>(mgr, 0x58, ctlA);

  float *timer = (float *)(self + 0xa60);
  *timer -= *(float *)(eng + 0x48);
  float s88 = (float)*(s32 *)(eng + 0x40) * 0.0009765625f;   // clock ticks (1024/s) as seconds

  u8 *base = self + 0x50;
  for (u8 *e = base; e != base + 0x1c * *(u32 *)(self + 0x4c); e += 0x1c) {
    u8 *o = vcall<u8 *>(mgr, 0x58, *(u32 *)e);
    float v70[12], v10[3], v40[3], v9c[3], va8[3], v34[3], v28[3], v1c[3];
    vcall<void>(o, 0x80, v70, v10);
    ext_4daf90(*(u8 **)(o + 8), v40);
    ext_43e8e0(v9c, v10, v40);
    va8[0] = *(float *)(e + 8);
    va8[1] = *(float *)(e + 0xc);
    va8[2] = *(float *)(e + 0x10);
    ext_43e920(v34, v9c, va8);
    ext_4e0d00(v34, 1.0f / *(float *)(eng + 0x48));
    *(float *)(e + 8) = v9c[0];
    *(float *)(e + 0xc) = v9c[1];
    *(float *)(e + 0x10) = v9c[2];

    u32 r1 = vcall<u32>(o, 0x2b4, 4u);
    vcall<void>(o, 0x398, r1, v28);
    ext_4419f0(v28, v70);
    ext_441940(v28, v10);
    u32 r2 = vcall<u32>(o, 0x2b4, 0x14u);
    vcall<void>(o, 0x398, r2, v1c);
    ext_4419f0(v1c, v70);
    ext_441940(v1c, v10);

    float u = *timer;
    while (0.0f > u) {
      float v = u + s88;
      // three samples of the engine's logger slot, each scaled by 20
      float b4[3];
      b4[0] = vcall<float>(eng, 0x1c4, (u32)0x6ab6d4, 0x619) * 20.0f;
      b4[1] = vcall<float>(eng, 0x1c4, (u32)0x6ab6d4, 0x619) * 20.0f;
      b4[2] = vcall<float>(eng, 0x1c4, (u32)0x6ab6d4, 0x619) * 20.0f;
      s32 cnt = (s32)((v + u) * 1024.0f);
      for (int i = 0; i < 2; i++) {
        float *pos = i == 0 ? v28 : v1c;
        float v4c[3];
        ext_43e8e0(v4c, b4, pos);
        vcall<void>(ctl, 0x218, ctlB, v4c, v34, cnt);
      }
      u += 0.02666667f;
    }
  }

  if (0.0f > *timer) {
    do {
      *timer += 0.013333334f;
    } while (0.0f > *timer);
  }
}
PCREG(582aa0, DrawActorsOnFire);
