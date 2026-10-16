// batch904.cpp - vehicles thread, batch 904: LoadRotationAxisAngle, roll/tilt from the dampers
// (CUnderCarriageCar/Tank::CalcRollAndTilt) and CUnderCarriageCar/Tank::InitPosDir.
#include "ff.h"

extern "C" void FASTCALL ext_4de040(float *mat, const float *dir, const float *up);  // createmat
extern "C" void FASTCALL ext_4de480(float *mat, const float *m2);                   // mat = mat * m2 (via vmmul)
extern "C" void THISCALL ext_5254c0(void *uc);  // CUnderCarriageCar::InitGlobalDamperPositions (batch 903)
extern "C" void THISCALL ext_526df0(void *uc);  // CUnderCarriageCar::UpdateYPos (batch 902)
extern "C" void THISCALL ext_526cf0(void *uc);  // CUnderCarriageCar::UpdateWheelsYPos (batch 902)
extern "C" void THISCALL ext_5255d0(void *uc);  // CUnderCarriageCar::InitMinMaxForWheels (batch 903)
extern "C" void THISCALL ext_527f80(void *uc);  // tank versions of the same four
extern "C" void THISCALL ext_529760(void *uc);
extern "C" void THISCALL ext_529660(void *uc);
extern "C" void THISCALL ext_528090(void *uc);

static const u32 ABS64[4] __attribute__((aligned(16))) = {0xffffffff, 0x7fffffff, 0xffffffff, 0x7fffffff};
static inline double fabs64(double d) {
  return _mm_cvtsd_f64(_mm_and_pd(_mm_set_sd(d), _mm_load_pd((const double *)ABS64)));
}
static inline float mn(float a, float b) { return _mm_cvtss_f32(_mm_min_ss(_mm_set_ss(a), _mm_set_ss(b))); }

// 0x4ddcb0 LoadRotationAxisAngle(float[3][3]&, const float* axis, float angle), fastcall + 1 stack arg.
// Rodrigues' rotation with c = cos, s = sin (CRT, in double, rounded to float), t = 1 - c; the element order and
// the products are kept exactly as the exe computes them.
static void FASTCALL loadRotationAxisAngle(float *m, const float *ax, float a) {
  float c = (float)crt::cos((double)a);
  float s = (float)crt::sin((double)a);
  float x = ax[0], y = ax[1], z = ax[2];
  float yy = y * y, xx = x * x, zz = z * z;
  float ys = y * s, xs = x * s, zs = z * s;
  float t = 1.0f - c;
  float yxt = (y * x) * t, zxt = (z * x) * t, zyt = (z * y) * t;
  m[6] = (1.0f - xx) * c + xx;
  m[7] = yxt + zs;
  m[3] = yxt - zs;
  m[8] = zxt - ys;
  m[0] = zxt + ys;
  m[4] = (1.0f - yy) * c + yy;
  m[2] = (1.0f - zz) * c + zz;
  m[5] = zyt + xs;
  m[1] = zyt - xs;
}
PCREG(4ddcb0, loadRotationAxisAngle);

// Height difference of two dampers (+0x55 current value), subtracted on the x87 stack.
static inline long double ydiff(u8 *a, u8 *b) { return (long double)*(float *)(a + 0x55) - *(float *)(b + 0x55); }

// Moves `cur` toward `target` by `step`, snapping to it within 2^-13 (0x679540).
static inline void approach(float *cur, float target, float step) {
  float v = *cur;
  if (v > target) {
    v = v - step;
    *cur = v;
    if (target + 0.0001220703125f > v)
      *cur = target;
  } else if (target > v) {
    v = v + step;
    *cur = v;
    if (v > target - 0.0001220703125f)
      *cur = target;
  }
}

// CalcRollAndTilt: roll = the largest left/right height difference over the wheel pairs of both axles (dampers in
// pairs, stride 0xde inside a pair, 0x1bc between pairs), tilt = the larger of the left and right rear-minus-front
// differences. Target angles atan(roll / track width) -> +0x3c and atan(tilt / wheelbase) -> +0x34, clamped to
// +-lim; the shown angles +0x38 (roll) and +0x30 (tilt) move toward them at 60 degrees/s (1.0471976 * frame time,
// engine +0x48).
static inline void calcRollAndTilt(u8 *s, u32 n1, u32 d1, u32 n2, u32 d2, u32 w, u32 l, float lim) {
  float roll = 0;
  for (s32 i = 0; i < *(s32 *)(s + n1); i += 2) {
    u8 *d = s + d1 + (i / 2) * 0x1bc;
    long double v = ydiff(d + 0xde, d);
    if (fabs64((double)v) > fabs64((double)roll))
      roll = (float)ydiff(d + 0xde, d);
  }
  for (s32 i = 0; i < *(s32 *)(s + n2); i += 2) {
    u8 *d = s + d2 + (i / 2) * 0x1bc;
    long double v = ydiff(d + 0xde, d);
    if (fabs64((double)v) > fabs64((double)roll))
      roll = (float)ydiff(d + 0xde, d);
  }
  float tilt = (float)ydiff(s + d2, s + d1);
  long double v = ydiff(s + d2 + 0xde, s + d1 + 0xde);
  if (fabs64((double)v) > fabs64((double)tilt))
    tilt = (float)ydiff(s + d2 + 0xde, s + d1 + 0xde);
  *(float *)(s + 0x3c) = (float)crt::atan((double)(roll / *(float *)(s + w)));
  float tr = (float)crt::atan((double)(tilt / *(float *)(s + l)));
  *(float *)(s + 0x34) = tr;
  float r = *(float *)(s + 0x3c);
  float r1 = -lim > r ? -lim : mn(lim, r);
  *(float *)(s + 0x3c) = r1;
  float t = *(float *)(s + 0x34);
  float t1 = -lim > t ? -lim : mn(lim, t);
  *(float *)(s + 0x34) = t1;
  u8 *sys = *(u8 **)0x70039c;
  approach((float *)(s + 0x38), r1, *(float *)(sys + 0x48) * 1.0471975803375244f);
  approach((float *)(s + 0x30), *(float *)(s + 0x34), *(float *)(sys + 0x48) * 1.0471975803375244f);
}

// 0x524b00 CUnderCarriageCar::CalcRollAndTilt(): front dampers +0xbd (count +0x8c), rear +0x435 (+0x90), track
// +0xa8, wheelbase +0xac, limit 45 degrees (0x69f1a0/0x69f1a8).
static void THISCALL ucCarCalcRollAndTilt(u8 *s) { calcRollAndTilt(s, 0x8c, 0xbd, 0x90, 0x435, 0xa8, 0xac, 0.7853981852531433f); }
PCREG(524b00, ucCarCalcRollAndTilt);

// 0x527710 CUnderCarriageTank::CalcRollAndTilt(): dampers +0x95 (+0x8d) and +0x785 (+0x91), +0x21b9 / +0x21bd,
// limit 30 degrees (0x6a0bc8/0x6a0bd0).
static void THISCALL ucTankCalcRollAndTilt(u8 *s) {
  calcRollAndTilt(s, 0x8d, 0x95, 0x91, 0x785, 0x21b9, 0x21bd, 0.5235987901687622f);
}
PCREG(527710, ucTankCalcRollAndTilt);

// InitPosDir(pos, dir): position +0, direction +0x4c flattened (y = 0) and copied to +0x58; body matrix +0xc from
// the direction; the group (slot 0x7c(mat, pos)) is placed; dampers dropped to the ground, body height and the
// target roll/tilt computed; then the matrix is rebuilt and turned by the shown roll (+0x38, about matrix row 0) and
// tilt (+0x30, about row 2), the group placed again, the wheels follow, travel limits set, the group placed a third
// time; +0x48 = engine time (+0x40) / 1024 and the impact timer (+0x84 car / +0x85 tank) = time + 0x1c00.
typedef void (*ucFn)(void *);
static inline void initPosDir(u8 *s, const u32 *p, const u32 *d, u32 grp, u32 tmr, void(THISCALL *dampers)(void *),
                              void(THISCALL *ypos)(void *), void(THISCALL *rt)(u8 *), void(THISCALL *wheels)(void *),
                              void(THISCALL *minmax)(void *)) {
  float *mat = (float *)(s + 0xc);
  ((u32 *)s)[0] = p[0];
  ((u32 *)s)[1] = p[1];
  ((u32 *)s)[2] = p[2];
  *(u32 *)(s + 0x4c) = d[0];
  *(u32 *)(s + 0x50) = d[1];
  *(u32 *)(s + 0x54) = d[2];
  *(u32 *)(s + 0x50) = 0;
  *(u32 *)(s + 0x58) = *(u32 *)(s + 0x4c);
  *(u32 *)(s + 0x5c) = *(u32 *)(s + 0x50);
  *(u32 *)(s + 0x60) = *(u32 *)(s + 0x54);
  ext_4de040(mat, (float *)(s + 0x4c), 0);
  vcall<void>(*(void **)(s + grp), 0x7c, mat, s);
  dampers(s);
  ypos(s);
  rt(s);
  float roll = *(float *)(s + 0x38), tilt = *(float *)(s + 0x30);
  *(u32 *)(s + 0x50) = 0;
  ext_4de040(mat, (float *)(s + 0x4c), 0);
  float r1[9], r2[9];
  loadRotationAxisAngle(r1, mat, roll);
  loadRotationAxisAngle(r2, mat + 6, tilt);
  ext_4de480(mat, r1);
  ext_4de480(mat, r2);
  vcall<void>(*(void **)(s + grp), 0x7c, mat, s);
  wheels(s);
  minmax(s);
  vcall<void>(*(void **)(s + grp), 0x7c, mat, s);
  u8 *sys = *(u8 **)0x70039c;
  *(float *)(s + 0x48) = (float)*(s32 *)(sys + 0x40) * 0.0009765625f;
  *(u32 *)(s + tmr) = *(u32 *)(*(u8 **)0x70039c + 0x40) + 0x1c00;
}

// 0x525640 CUnderCarriageCar::InitPosDir(const float*, const float*): group +0x88, timer +0x84.
static void THISCALL ucCarInitPosDir(u8 *s, const u32 *p, const u32 *d) {
  initPosDir(s, p, d, 0x88, 0x84, ext_5254c0, ext_526df0, ucCarCalcRollAndTilt, ext_526cf0, ext_5255d0);
}
PCREG(525640, ucCarInitPosDir);

// 0x528100 CUnderCarriageTank::InitPosDir: group +0x89, timer +0x85.
static void THISCALL ucTankInitPosDir(u8 *s, const u32 *p, const u32 *d) {
  initPosDir(s, p, d, 0x89, 0x85, ext_527f80, ext_529760, ucTankCalcRollAndTilt, ext_529660, ext_528090);
}
PCREG(528100, ucTankInitPosDir);
