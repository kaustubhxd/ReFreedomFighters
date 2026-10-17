// batch915.cpp - vehicles thread, batch 915: ZTank driving (UpdateDir, UpdatePosDir, SplineUpdate) and helpers.
#include "ff.h"

extern "C" void FASTCALL ext_43e920(float *d, const float *a, const float *b);      // d = a - b
extern "C" void THISCALL ext_4e0d00(float *v, float k);                             // vscalar
extern "C" float THISCALL ext_44c840(float *v);                                     // vnorm in place
extern "C" void THISCALL ext_460af0(void *shape, float *pos, float *vel, float t);  // GetSplinePosVelocity
extern "C" float FASTCALL ext_4e0030(const float *a, const float *b);               // vangle
extern "C" void FASTCALL ext_4de040(float *mat, const float *dir, const float *up);  // createmat
extern "C" void FASTCALL ext_4de420(float *d, const float *s);                      // mcpy
extern "C" void THISCALL ext_521600(void *tank, const float *d);                    // ZTank::SetNextDir (913)
extern "C" void THISCALL ext_527d10(void *uc, float *mat, float *pos, const float *spl, const float *dir, float a,
                                    float b, float c);  // CUnderCarriageTank::FrameUpdate
extern "C" void THISCALL ext_520450(void *tank, const float *m0, const float *p0, float *m, float *p);
// ZTank::CheckPlayerCollision
extern "C" void THISCALL ext_515c70(void *v);    // ZVehicle::SplineUpdate
extern "C" void THISCALL ext_522520(void *t);    // ZTank::UpdateTurretDir (914)
extern "C" void THISCALL ext_521db0(void *t);    // ZTank::UpdateMachineGun (914)
extern "C" void THISCALL ext_521ab0(void *t);    // ZTank::UpdateCannon (914)
extern "C" void THISCALL ext_522250(void *t);    // ZTank::UpdateSound
extern "C" void THISCALL ext_523330(void *p, float *d);  // CMoveAlongPath::GetDir

static inline u8 *sysp() { return *(u8 **)0x70039c; }

// 0x515930 ZVehicle::DriveFwdToSplineVal / DriveBkwToSplineVal (one body): slot 0x2f8(val, flag).
static void THISCALL vehDriveToSplineVal(u8 *s, float v, u32 b) { vcall<void>(s, 0x2f8, v, b); }
PCREG(515930, vehDriveToSplineVal);

// 0x521930 (ZTank, unnamed: start driving backward): drive to spline value +0x2f8 (flag byte +0x2fc), direction
// sign +0x2f0 = -1, state +0x2f4 = 4, turning flag +0x216 cleared.
static void THISCALL tankStartBackward(u8 *s) {
  vehDriveToSplineVal(s, *(float *)(s + 0x2f8), s[0x2fc]);
  *(u32 *)(s + 0x2f0) = 0xbf800000;
  *(u32 *)(s + 0x2f4) = 4;
  *(u32 *)(s + 0x216) = 0;
}
PCREG(521930, tankStartBackward);

// 0x5233a0 CMoveAlongPath::GetDirToSplineVal(float[3]&, float t), pops 8: (1, 0, 0) without a shape (+0x4b);
// otherwise the spline velocity at the current value +4, to world (shape slot 0x88), negated when
// clamp(t, 0, 1) - current < 0, normalised.
static void THISCALL pathGetDirToSplineVal(u8 *p, float *out, float t) {
  float sign = 1.0f;
  float c = 0.0f > t ? 0.0f : _mm_cvtss_f32(_mm_min_ss(_mm_set_ss(1.0f), _mm_set_ss(t)));
  if (0.0f > c - *(float *)(p + 4))
    sign = -1.0f;
  *(u32 *)out = 0x3f800000;
  *(u32 *)(out + 1) = 0;
  *(u32 *)(out + 2) = 0;
  u8 *sh = *(u8 **)(p + 0x4b);
  if (!sh)
    return;
  float pos[3];
  ext_460af0(sh + 0x1c, pos, out, *(float *)(p + 4));
  vcall<void>(*(void **)(p + 0x4b), 0x88, out);
  ext_4e0d00(out, sign);
  ext_44c840(out);
}
PCREG(5233a0, pathGetDirToSplineVal);

// 0x521bd0 ZTank::UpdateDir(): the hull direction +0x2d8 follows the turner +0x2695 (slot 8). Unless turning in
// place (+0x216 == 1), while the path speed is over 10 and the tank moved more than 0.02 horizontally since the last
// frame, the next direction becomes the movement direction (times the drive sign +0x2f0, SetNextDir), and over speed
// 50 the hull takes it at once. When the turner is done (slot 0xc) it restarts from the hull direction toward the
// normalised next direction; a finished in-place turn sends the tank its own command word +0x270b. The hull
// direction is flattened and normalised.
static void THISCALL tankUpdateDir(u8 *s) {
  u8 *tn = s + 0x2695;
  float *dir = (float *)(s + 0x2d8);
  vcall<void>(tn, 8, dir);
  if (*(u32 *)(s + 0x216) != 1 && *(float *)(*(u8 **)(s + 0x5c) + 0x24) > 10.0f) {
    float v[3];
    ext_43e920(v, (float *)(s + 0x60), (float *)(s + 0x90));
    float l2 = _mm_cvtss_f32(_mm_add_ss(_mm_add_ss(_mm_mul_ss(_mm_set_ss(v[0]), _mm_set_ss(v[0])), _mm_set_ss(0.0f)),
                                        _mm_mul_ss(_mm_set_ss(v[2]), _mm_set_ss(v[2]))));
    v[1] = 0;
    float len = (float)crt::sqrt((double)l2);
    if (len > 0.019999999552965164f) {
      ext_4e0d00(v, *(float *)(s + 0x2f0));
      ext_521600(s, v);
      if (*(float *)(*(u8 **)(s + 0x5c) + 0x24) > 50.0f) {
        ((u32 *)dir)[0] = *(u32 *)(s + 0x2e4);
        ((u32 *)dir)[1] = *(u32 *)(s + 0x2e8);
        ((u32 *)dir)[2] = *(u32 *)(s + 0x2ec);
      }
    }
  }
  if (vcall<u8>(tn, 0xc)) {
    *(u32 *)(s + 0x2e8) = 0;
    ext_44c840((float *)(s + 0x2e4));
    vcall<void>(tn, 4, dir, s + 0x2e4);
    if (*(u32 *)(s + 0x216) == 1)
      vcall<void>(s, 0x130, s, (u32) * (u16 *)(s + 0x270b), 0);
  }
  *(u32 *)(s + 0x2dc) = 0;
  if (dir[0] == 0.0f && dir[1] == 0.0f && dir[2] == 0.0f)
    return;
  long double x = dir[0], y = dir[1], z = dir[2];
  long double inv = 1.0L / fsqrt_x87((x * x + y * y) + z * z);
  dir[0] = (float)(dir[0] * inv);
  dir[1] = (float)(dir[1] * inv);
  dir[2] = (float)(dir[2] * inv);
}
PCREG(521bd0, tankUpdateDir);

// 0x521f90 ZTank::UpdatePosDir(): UpdateDir (slot 0x370); with a body geom (+0x123) whose group has flag 0x1000 the
// undercarriage (+0x2fd) computes the new matrix and position from the spline point, the hull direction, the
// path speed (+0x24), path +0x28 and the drive sign; with a body without the flag the matrix comes from the
// direction and the position is the spline point. No body: "WARNING: Tank has no BODY, Tank wil not move."
// (tank.cpp line 0x21f) and the matrix/position stay unset. Then CheckPlayerCollision, SetRootTM, old
// position/matrix (+0x90/+0x9c) saved and the new ones stored (+0x6c/+0x60). State +0x2f4 = 1 (about to drive
// forward): debug "F m_vDir[NXT] : %v"; once the hull is within 1 degree of the path direction toward +0x2f8 the
// tank drives (sign +1, state 2). State 3 (about to reverse): debug "B m_vDir[NXT] : %v"; once more than 179
// degrees off it starts driving backward (0x521930).
typedef void *(THISCALL *dbgAt)(void *, const char *, u32);
typedef void (*dbgPrint)(void *, const char *);
typedef void (*dbgText)(void *, u32, u32, const char *, const void *);
static void THISCALL tankUpdatePosDir(u8 *s) {
  vcall<void>(s, 0x370);
  float S[3], M[9], P[3];
  u8 *p = *(u8 **)(s + 0x5c);
  S[0] = *(float *)(p + 8);
  S[1] = *(float *)(p + 0xc);
  S[2] = *(float *)(p + 0x10);
  u32 body = *(u32 *)(s + 0x123);
  if (body) {
    u8 *g = vcall<u8 *>(*(void **)(sysp() + 0x9b), 0x58, body);
    if (*(u32 *)(*(u8 **)(g + 8) + 0x3c) & 0x1000) {
      u8 *pp = *(u8 **)(s + 0x5c);
      ext_527d10(s + 0x2fd, M, P, S, (float *)(s + 0x2d8), *(float *)(pp + 0x24), *(float *)(pp + 0x28),
                 *(float *)(s + 0x2f0));
    } else {
      ext_4de040(M, (float *)(s + 0x2d8), 0);
      P[0] = S[0];
      P[1] = S[1];
      P[2] = S[2];
    }
  } else {
    void *dbg = *(void **)0x700390;
    void *o = (*(dbgAt *)(*(u8 **)dbg + 0x20))(dbg, (const char *)0x6a04a8, 0x21f);
    (*(dbgPrint *)(*(u8 **)o + 0x30))(o, (const char *)0x6a0614);
  }
  ext_520450(s, (float *)(s + 0x6c), (float *)(s + 0x60), M, P);
  vcall<void>(s, 0x7c, M, P);
  *(u32 *)(s + 0x90) = *(u32 *)(s + 0x60);
  *(u32 *)(s + 0x94) = *(u32 *)(s + 0x64);
  *(u32 *)(s + 0x98) = *(u32 *)(s + 0x68);
  ext_4de420((float *)(s + 0x9c), (float *)(s + 0x6c));
  ext_4de420((float *)(s + 0x6c), M);
  *(float *)(s + 0x60) = P[0];
  *(float *)(s + 0x64) = P[1];
  *(float *)(s + 0x68) = P[2];
  u32 st = *(u32 *)(s + 0x2f4);
  if (st != 1 && st != 3)
    return;
  void *o = vcall<void *>(sysp(), 0x190);
  (*(dbgText *)(*(u8 **)o + 0x184))(o, 10, 0xb, (const char *)(st == 1 ? 0x6a0644 : 0x6a0658), s + 0x2e4);
  float t[3];
  pathGetDirToSplineVal(*(u8 **)(s + 0x5c), t, *(float *)(s + 0x2f8));
  t[1] = 0;
  volatile float a = ext_4e0030((float *)(s + 0x2d8), t);
  if (st == 1) {
    if (0.01745329238474369f > a) {
      vehDriveToSplineVal(s, *(float *)(s + 0x2f8), s[0x2fc]);
      *(u32 *)(s + 0x2f0) = 0x3f800000;
      *(u32 *)(s + 0x2f4) = 2;
      *(u32 *)(s + 0x216) = 0;
    }
  } else if (a > 3.1241393089294434f) {
    tankStartBackward(s);
  }
}
PCREG(521f90, tankUpdatePosDir);

// 0x521830 ZTank::SplineUpdate(): ZVehicle::SplineUpdate; a stationary tank (+0x133) with a body re-seats on its
// undercarriage at its current matrix/position (GetRootTM, then FrameUpdate with zero speed); a moving one runs
// UpdatePosDir (slot 0x36c). Unless the weapons are off (+0x215): UpdateTurretDir, UpdateMachineGun, UpdateCannon,
// UpdateSound; otherwise the turret loops stop. Finally the path direction is fetched (unused).
static void THISCALL tankSplineUpdate(u8 *s) {
  ext_515c70(s);
  if (s[0x133]) {
    if (*(u32 *)(s + 0x123)) {
      vcall<void>(s, 0x80, s + 0x6c, s + 0x60);
      ext_527d10(s + 0x2fd, (float *)(s + 0x6c), (float *)(s + 0x60), (float *)(s + 0x60), (float *)(s + 0x6c),
                 0.0f, 0.0f, 0.0f);
    }
  } else {
    vcall<void>(s, 0x36c);
  }
  if (!s[0x215]) {
    ext_522520(s);
    ext_521db0(s);
    ext_521ab0(s);
    ext_522250(s);
  } else {
    if (*(u32 *)(s + 0x26fa))
      vcall<void>(s, 0x2ec, *(u32 *)(s + 0x26fa));
    *(u32 *)(s + 0x26fa) = 0;
    if (*(u32 *)(s + 0x26ea))
      vcall<void>(s, 0x2ec, *(u32 *)(s + 0x26ea));
    *(u32 *)(s + 0x26ea) = 0;
  }
  float d[3];
  ext_523330(*(void **)(s + 0x5c), d);
}
PCREG(521830, tankSplineUpdate);
