// batch916.cpp - vehicles thread, batch 916: ZTank drive orders (DriveFwd/Bkw/ToSplineVal), InitTankPosDir.
#include "ff.h"

extern "C" void THISCALL ext_5233a0(void *path, float *out, float t);  // CMoveAlongPath::GetDirToSplineVal (915)
extern "C" void THISCALL ext_523330(void *path, float *dir);           // CMoveAlongPath::GetDir (907)
extern "C" void THISCALL ext_521600(void *tank, const float *d);       // ZTank::SetNextDir (913)
extern "C" void THISCALL ext_4e0d00(float *v, float k);                // vscalar
extern "C" void THISCALL ext_528100(void *uc, const float *p, const float *d);  // CUnderCarriageTank::InitPosDir
extern "C" void THISCALL ext_525380(void *uc, float *m, float *p);             // CUnderCarriageTank::GetMatPos
extern "C" void FASTCALL ext_4de420(float *d, const float *s);                 // mcpy

// 0x4e09b0 vneg(float*): flips the sign bit of each component (SSE xorps).
static void THISCALL vneg(float *v) {
  for (int i = 0; i < 3; i++)
    v[i] = bitsf(fbits(v[i]) ^ 0x80000000);
}
PCREG(4e09b0, vneg);

// Drive orders: remember the target spline value +0x2f8 and flag +0x2fc, set the state +0x2f4, restart the hull
// turner (+0x2695 slot 0(accel 30 deg/s^2, lower bound 10 deg/s, cap pi rad/s; batch 933)) and aim the next direction at the path direction toward the
// target (reversed for backward); the in-place turn flag +0x216 is cleared. UpdatePosDir starts the actual drive
// once the hull is aligned (state 1 -> 2, 3 -> 4).
static inline void driveOrder(u8 *s, float v, u32 b, u32 state, bool back) {
  s[0x2fc] = (u8)b;
  *(float *)(s + 0x2f8) = v;
  *(u32 *)(s + 0x2f4) = state;
  vcall<void>(s + 0x2695, 0, 0.5235987901687622f, 0.1745329201221466f, 3.1415927410125732f);
  float t[3];
  ext_5233a0(*(void **)(s + 0x5c), t, *(float *)(s + 0x2f8));
  if (back)
    vneg(t);
  ext_521600(s, t);
  *(u32 *)(s + 0x216) = 0;
}

// 0x520b10 ZTank::DriveBkwToSplineVal(float, bool): state 3.
static void THISCALL tankDriveBkw(u8 *s, float v, u32 b) { driveOrder(s, v, b, 3, true); }
PCREG(520b10, tankDriveBkw);

// 0x520bb0 ZTank::DriveFwdToSplineVal(float, bool): state 1.
static void THISCALL tankDriveFwd(u8 *s, float v, u32 b) { driveOrder(s, v, b, 1, false); }
PCREG(520bb0, tankDriveFwd);

// 0x520c50 ZTank::DriveToSplineVal(float, bool): the travel direction along the path toward v (path direction,
// times the sign of v - current value (path slot 0xc) and of the path speed (slot 0x14)) decides: in front of
// the hull (dot with hull row +0x6c/+0x74 > 0) -> DriveFwdToSplineVal (slot 0x360), else DriveBkwToSplineVal (0x364).
static void THISCALL tankDriveTo(u8 *s, float v, u32 b) {
  u8 *p = *(u8 **)(s + 0x5c);
  volatile float d = (float)((long double)v - (long double)vcall<float>(p, 0xc));
  float sign = d > 0.0f ? 1.0f : -1.0f;
  float t[3];
  ext_523330(*(void **)(s + 0x5c), t);
  volatile float sp = (float)((long double)vcall<float>(*(void **)(s + 0x5c), 0x14) * (long double)sign);
  if (!(sp > 0.0f))
    vneg(t);
  float dot = _mm_cvtss_f32(_mm_add_ss(_mm_add_ss(_mm_mul_ss(_mm_set_ss(t[0]), _mm_load_ss((float *)(s + 0x6c))),
                                                  _mm_mul_ss(_mm_set_ss(t[1]), _mm_set_ss(0.0f))),
                                       _mm_mul_ss(_mm_set_ss(t[2]), _mm_load_ss((float *)(s + 0x74)))));
  if (dot > 0.0f)
    vcall<void>(s, 0x360, v, b);
  else
    vcall<void>(s, 0x364, v, b);
}
PCREG(520c50, tankDriveTo);

// 0x520e40 (ZTank, unnamed: set the hull direction): +0x2d8 = d flattened, times the drive sign +0x2f0,
// normalised; next direction = it; the hull turner restarts (slot 4(hull, next)).
static void THISCALL tankSetHullDir(u8 *s, const u32 *d) {
  float *h = (float *)(s + 0x2d8);
  ((u32 *)h)[0] = d[0];
  ((u32 *)h)[1] = d[1];
  ((u32 *)h)[2] = d[2];
  *(u32 *)(s + 0x2dc) = 0;
  ext_4e0d00(h, *(float *)(s + 0x2f0));
  if (!(h[0] == 0.0f && h[1] == 0.0f && h[2] == 0.0f)) {
    long double x = h[0], y = h[1], z = h[2];
    long double inv = 1.0L / fsqrt_x87((x * x + y * y) + z * z);
    h[0] = (float)(h[0] * inv);
    h[1] = (float)(h[1] * inv);
    h[2] = (float)(h[2] * inv);
  }
  u32 *n = (u32 *)(s + 0x2e4);
  n[0] = ((u32 *)h)[0];
  n[1] = ((u32 *)h)[1];
  n[2] = ((u32 *)h)[2];
  vcall<void>(s + 0x2695, 4, h, n);
}
PCREG(520e40, tankSetHullDir);

// 0x520f20 ZTank::InitTankPosDir(bool forward): a stationary tank keeps its geom matrix/position (GetRootTM) and
// faces its matrix row 0; otherwise drive sign = forward ? 1 : -1, position = the path point, hull direction =
// the path direction (0x520e40). Then the position is lifted 100, turret and wanted turret direction (0, 0, 1),
// turret turner restarted, the undercarriage placed (InitPosDir) and read back (GetMatPos), old position/matrix
// saved.
static void THISCALL tankInitTankPosDir(u8 *s, u32 fwd) {
  float *pos = (float *)(s + 0x60);
  if (s[0x133]) {
    vcall<void>(s, 0x80, s + 0x6c, pos);
    *(u32 *)(s + 0x2d8) = *(u32 *)(s + 0x6c);
    *(u32 *)(s + 0x2dc) = *(u32 *)(s + 0x70);
    *(u32 *)(s + 0x2e0) = *(u32 *)(s + 0x74);
  } else {
    *(u32 *)(s + 0x2f0) = (u8)fwd ? 0x3f800000 : 0xbf800000;
    u8 *p = *(u8 **)(s + 0x5c);
    ((u32 *)pos)[0] = *(u32 *)(p + 8);
    ((u32 *)pos)[1] = *(u32 *)(p + 0xc);
    ((u32 *)pos)[2] = *(u32 *)(p + 0x10);
    float t[3];
    ext_523330(*(void **)(s + 0x5c), t);
    tankSetHullDir(s, (u32 *)t);
  }
  pos[1] = pos[1] + 100.0f;
  u32 *td = (u32 *)(s + 0x2624), *tw = (u32 *)(s + 0x2630);
  td[0] = 0;
  td[1] = 0;
  td[2] = 0x3f800000;
  tw[0] = 0;
  tw[1] = 0;
  tw[2] = 0x3f800000;
  vcall<void>(s + 0x263c, 4, td, tw);
  ext_528100(s + 0x2fd, pos, (float *)(s + 0x2d8));
  ext_525380(s + 0x2fd, (float *)(s + 0x6c), pos);
  *(u32 *)(s + 0x90) = *(u32 *)(s + 0x60);
  *(u32 *)(s + 0x94) = *(u32 *)(s + 0x64);
  *(u32 *)(s + 0x98) = *(u32 *)(s + 0x68);
  ext_4de420((float *)(s + 0x9c), (float *)(s + 0x6c));
}
PCREG(520f20, tankInitTankPosDir);
