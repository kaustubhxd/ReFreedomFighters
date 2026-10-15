// batch927.cpp - vehicles thread, batch 927: CUnderCarriageCar physics step, DynamicsFrameUpdate and FrameUpdate.
#include "ff.h"

extern "C" void THISCALL ext_516070(void *d, float dt);  // CDamper physics step (919)
extern "C" void THISCALL ext_526df0(void *uc);           // CUnderCarriageCar::UpdateYPos (902)
extern "C" void THISCALL ext_524b00(void *uc);           // CUnderCarriageCar::CalcRollAndTilt (904)
extern "C" void THISCALL ext_524f50(void *uc);           // physics step (this batch, by address)
extern "C" void THISCALL ext_524ff0(void *uc);           // DynamicsFrameUpdate (this batch, by address)
extern "C" void THISCALL ext_526cf0(void *uc);           // UpdateWheelsYPos (902)
extern "C" void THISCALL ext_524de0(void *uc);           // CorrectReversedDampers
extern "C" void THISCALL ext_526470(void *uc);           // ground probe
extern "C" void THISCALL ext_526ac0(void *uc);           // weight transfer
extern "C" void THISCALL ext_526360(void *uc);           // dampers follow anchors
extern "C" void THISCALL ext_525f30(void *uc);           // wheels (steer, spin)
extern "C" void THISCALL ext_526880(void *uc);           // wheel dust
extern "C" void THISCALL ext_526c60(void *uc);           // exhaust
extern "C" void FASTCALL ext_4de040(float *mat, const float *dir, const float *up);  // createmat
extern "C" void FASTCALL ext_4ddcb0(float *m, const float *axis, float a);          // LoadRotationAxisAngle
extern "C" void FASTCALL ext_4de480(float *mat, const float *m2);                   // mat = mat * m2
extern "C" void FASTCALL ext_4de420(float *d, const float *s);                      // mcpy
extern "C" float FASTCALL ext_4e0030(const float *a, const float *b);               // vangle
extern "C" void FASTCALL ext_446ee0(float *d, const float *a, const float *b);      // vcross
#define F(p, o) (*(float *)((u8 *)(p) + (o)))
static inline float sadd(float a, float b) { asm("addss %1, %0" : "+x"(a) : "x"(b)); return a; }
static inline float smul(float a, float b) { asm("mulss %1, %0" : "+x"(a) : "x"(b)); return a; }
static inline u8 *sysp() { return *(u8 **)0x70039c; }

// 0x524f50 (CUnderCarriageCar, unnamed: one physics step): every damper of both axles steps by +0x9c; +0x80 = 1.0
// when any bottomed out (else 0).
static void THISCALL ucCarStep(u8 *s) {
  *(u32 *)(s + 0x80) = 0;
  for (s32 i = 0; i < *(s32 *)(s + 0x8c); i++) {
    ext_516070(s + 0xbd + i * 0xde, F(s, 0x9c));
    if (s[0xcd + i * 0xde])
      *(u32 *)(s + 0x80) = 0x3f800000;
  }
  for (s32 i = 0; i < *(s32 *)(s + 0x90); i++) {
    ext_516070(s + 0x435 + i * 0xde, F(s, 0x9c));
    if (s[0x445 + i * 0xde])
      *(u32 *)(s + 0x80) = 0x3f800000;
  }
}
PCREG(524f50, ucCarStep);

static inline void bodyMatrix(u8 *s) {
  float roll = F(s, 0x38), tilt = F(s, 0x30);
  float *mat = (float *)(s + 0xc);
  *(u32 *)(s + 0x50) = 0;
  ext_4de040(mat, (float *)(s + 0x4c), 0);
  float r1[9], r2[9];
  ext_4ddcb0(r1, mat, roll);
  ext_4ddcb0(r2, mat + 6, tilt);
  ext_4de480(mat, r1);
  ext_4de480(mat, r2);
}

// 0x524ff0 CUnderCarriageCar::DynamicsFrameUpdate(): like the tank's (5 ms steps, at most 10), but the car updates
// body height, roll/tilt and the body matrix after every step as well as once at the end.
static void THISCALL ucCarDynamics(u8 *s) {
  s32 now = *(s32 *)(sysp() + 0x40);
  F(s, 0x9c) = 0.004999999888241291f;
  s32 t = now - _mm_cvttss_si32(_mm_set_ss(smul(F(s, 0x48), 1024.0f)));
  float q = _mm_cvtss_f32(_mm_div_ss(_mm_set_ss(smul((float)t, 0.0009765625f)), _mm_set_ss(0.004999999888241291f)));
  s32 n = _mm_cvttss_si32(_mm_set_ss(q));
  if (n >= 10)
    n = 10;
  if (n > 0) {
    for (s32 i = 0; i < n; i++) {
      ucCarStep(s);
      ext_526df0(s);
      ext_524b00(s);
      bodyMatrix(s);
    }
    if (n >= 10)
      F(s, 0x48) = smul((float)*(s32 *)(sysp() + 0x40), 0.0009765625f);
    else
      F(s, 0x48) = sadd(smul((float)n, F(s, 0x9c)), F(s, 0x48));
  }
  ext_526df0(s);
  ext_524b00(s);
  bodyMatrix(s);
}
PCREG(524ff0, ucCarDynamics);

// 0x5251c0 CUnderCarriageCar::FrameUpdate(mat, pos, spline, dir, speed, accel, steer, sign), pops 32. As the tank's
// (batch 922) with the car's offsets: frozen flag +0xbc with impact timer +0x84 and group +0x88; +0x64 = spline y +
// 150; steering angle +0x7c; sub-steps 0x526470 (ground probe), 0x526ac0 (weight), 0x526360 (anchors), dynamics,
// wheel heights, 0x525f30 (wheels), 0x526880 (dust), 0x526c60 (exhaust), CorrectReversedDampers.
static void THISCALL ucCarFrameUpdate(u8 *s, float *mat, u32 *pos, const u32 *spl, const u32 *dir, float speed,
                                      float accel, float steer, float sign) {
  if (s[0xbc]) {
    if (*(s32 *)(sysp() + 0x40) >= *(s32 *)(s + 0x84)) {
      vcall<void>(*(void **)(s + 0x88), 0x80, mat, pos);
      return;
    }
    ext_524ff0(s);
    ext_526cf0(s);
    vcall<void>(*(void **)(s + 0x88), 0x7c, s + 0xc, s);
    ext_524de0(s);
    ext_4de420(mat, (float *)(s + 0xc));
    pos[0] = ((u32 *)s)[0];
    pos[1] = ((u32 *)s)[1];
    pos[2] = ((u32 *)s)[2];
    return;
  }
  ((u32 *)s)[0] = spl[0];
  ((u32 *)s)[1] = spl[1];
  ((u32 *)s)[2] = spl[2];
  F(s, 0x64) = sadd(((float *)spl)[1], 150.0f);
  u32 *nd = (u32 *)(s + 0x4c), *od = (u32 *)(s + 0x58);
  od[0] = nd[0];
  od[1] = nd[1];
  od[2] = nd[2];
  nd[0] = dir[0];
  nd[1] = dir[1];
  nd[2] = dir[2];
  *(u32 *)(s + 0x50) = 0;
  F(s, 0x68) = speed;
  F(s, 0x6c) = accel;
  F(s, 0x78) = steer;
  F(s, 0x7c) = sign;
  F(s, 0x70) = ext_4e0030((float *)od, (float *)nd);
  float c[3];
  ext_446ee0(c, (float *)od, (float *)nd);
  if (0.0f > c[1])
    F(s, 0x70) = bitsf(fbits(F(s, 0x70)) ^ 0x80000000);
  F(s, 0x74) = _mm_cvtss_f32(_mm_div_ss(_mm_set_ss(F(s, 0x70)), _mm_set_ss(F(sysp(), 0x48))));
  ext_526470(s);
  ext_526ac0(s);
  ext_526360(s);
  ext_524ff0(s);
  ext_526cf0(s);
  ext_525f30(s);
  ext_526880(s);
  ext_526c60(s);
  ext_524de0(s);
  ext_4de420(mat, (float *)(s + 0xc));
  pos[0] = ((u32 *)s)[0];
  pos[1] = ((u32 *)s)[1];
  pos[2] = ((u32 *)s)[2];
}
PCREG(5251c0, ucCarFrameUpdate);
